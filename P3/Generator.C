#include "Absyn.H"
#include "Generator.H"
#include <cstdio>
#include <string>

// All instructions have to be named because of bug
// https://discourse.llvm.org/t/bug-in-language-reference-0-versus-1-as-starting-index/30186

void Generator::visitProgram(Program *t) {} // abstract class
void Generator::visitDef(Def *t) {}         // abstract class
void Generator::visitField(Field *t) {}     // abstract class
void Generator::visitStm(Stm *t) {}         // abstract class
void Generator::visitExp(Exp *t) {}         // abstract class
void Generator::visitType(Type *t) {}       // abstract class

void Generator::generate(Program *p) {
  context = std::make_unique<llvm::LLVMContext>();
  TheModule = std::make_unique<llvm::Module>("main", *context);
  builder = std::make_unique<llvm::IRBuilder<>>(*context);
  p->accept(this);
  // Print IR to stdout
  TheModule->print(llvm::outs(), nullptr);
}

llvm::Type *Generator::convertType(Type *t) {
  if (dynamic_cast<Type_int *>(t)) {
    return llvm::Type::getInt32Ty(*context);
  } else if (dynamic_cast<Type_bool *>(t)) {
    return llvm::Type::getInt1Ty(*context);
  } else if (dynamic_cast<TypeIdent *>(t)) {
    llvm::StructType *structType =
        TheModule->getTypeByName(dynamic_cast<TypeIdent *>(t)->ident_);
    return structType;
  } else if (dynamic_cast<Type_void *>(t)) {
    return llvm::Type::getVoidTy(*context);
  }
  return nullptr;
}

int Generator::getStructFieldIndex(std::string structName,
                                   std::string fieldName) {
  int index = 0;
  for (auto field : structFields[structName]) {
    if (field.first == fieldName) {
      return index;
    }
    index++;
  }
  return -1;
}

llvm::GlobalVariable *
Generator::getStructFieldIndices(Exp *lhs, std::vector<llvm::Value *> *indices,
                                 std::string fieldName) {
  // Base Case
  if (EIdent *e_ident = dynamic_cast<EIdent *>(lhs)) {
    indices->push_back(llvm::ConstantInt::get(*context, llvm::APInt(32, 0)));
    lastStruct = TheModule->getNamedGlobal(e_ident->ident_)
                     ->getValueType()
                     ->getStructName();
    int index = getStructFieldIndex(lastStruct, fieldName);
    llvm::Type *fieldType = structFields[lastStruct][index].second;
    if (fieldType->isStructTy()) {
      lastStruct = fieldType->getStructName();
    }
    indices->push_back(
        llvm::ConstantInt::get(*context, llvm::APInt(32, index)));
    return TheModule->getNamedGlobal(e_ident->ident_);
  }
  // Recursive case
  EProj *e_proj = dynamic_cast<EProj *>(lhs);
  llvm::GlobalVariable *globalVariable =
      getStructFieldIndices(e_proj->exp_, indices, e_proj->ident_);
  int index = getStructFieldIndex(lastStruct, fieldName);
  llvm::Type *fieldType = structFields[lastStruct][index].second;
  if (fieldType->isStructTy()) {
    lastStruct = fieldType->getStructName();
  }
  indices->push_back(llvm::ConstantInt::get(*context, llvm::APInt(32, index)));
  return globalVariable;
}

llvm::Value *Generator::getStructField(Exp *lhs, std::string fieldName) {
  // TODO: Free memory
  std::vector<llvm::Value *> *indices = new std::vector<llvm::Value *>();

  // FIXME: Refactor getStructFieldIndices to use a 2nd global var to store the
  // name of the top-level struct
  llvm::GlobalVariable *globalVar =
      getStructFieldIndices(lhs, indices, fieldName);
  std::string structTypeName = globalVar->getValueType()->getStructName();
  llvm::Type *structType = globalVar->getValueType();
  return builder->CreateGEP(structType, globalVar, *indices, "gep");
}

void Generator::visitPDefs(PDefs *p_defs) {
  /* Code For PDefs Goes Here */

  if (p_defs->listdef_)
    p_defs->listdef_->accept(this);
}

void Generator::visitDVar(DVar *d_var) {
  // Add global variable to module for all types
  // Question: Is ExternalLinkage correct?
  if (TypeIdent *type_ident = dynamic_cast<TypeIdent *>(d_var->type_)) {
    llvm::StructType *structType = TheModule->getTypeByName(type_ident->ident_);
    lastValue = new llvm::GlobalVariable(
        *TheModule, structType, false, llvm::GlobalValue::ExternalLinkage,
        llvm::ConstantAggregateZero::get(structType), d_var->ident_);
  } else {
    lastValue = new llvm::GlobalVariable(
        *TheModule, convertType(d_var->type_), false,
        llvm::GlobalValue::ExternalLinkage,
        llvm::ConstantInt::get(convertType(d_var->type_), 0, true),
        d_var->ident_);
  }
}

void Generator::visitDFun(DFun *d_fun) {
  llvm::Type *functionReturnType = convertType(d_fun->type_);
  llvm::FunctionType *functionType =
      llvm::FunctionType::get(functionReturnType, false);
  llvm::Function *function =
      llvm::Function::Create(functionType, llvm::Function::ExternalLinkage,
                             d_fun->ident_, TheModule.get());
  llvm::BasicBlock *block =
      llvm::BasicBlock::Create(*context, "entry", function);
  builder->SetInsertPoint(block);
  if (d_fun->liststm_)
    d_fun->liststm_->accept(this);

  // Return void if function is void
  if (dynamic_cast<Type_void *>(d_fun->type_)) {
    builder->CreateRetVoid();
  } else {
    // Workaround: Create dummy return value if function is not void
    if (functionReturnType->isIntegerTy()) {
      builder->CreateRet(llvm::ConstantInt::get(functionReturnType, 0, true));
    } else if (functionReturnType->isStructTy()) {
      llvm::StructType *structType =
          llvm::cast<llvm::StructType>(functionReturnType);
      builder->CreateRet(llvm::ConstantAggregateZero::get(structType));
    }
  }
}

void Generator::visitDStruct(DStruct *d_struct) {
  lastStruct = d_struct->ident_;
  if (d_struct->listfield_)
    d_struct->listfield_->accept(this);
  std::vector<llvm::Type *> fields;
  for (auto field : structFields[d_struct->ident_]) {
    fields.push_back(field.second);
  }
  llvm::StructType::create(*context, fields, d_struct->ident_);
}

void Generator::visitFDecl(FDecl *f_decl) {
  // Store index of field in struct to be able to access it later
  llvm::Type *type = convertType(f_decl->type_);
  structFields[lastStruct].push_back(
      std::make_pair(f_decl->ident_, convertType(f_decl->type_)));
}

void Generator::visitSExp(SExp *s_exp) {
  /* Code For SExp Goes Here */

  if (s_exp->exp_)
    s_exp->exp_->accept(this);
}

void Generator::visitSReturn(SReturn *s_return) {
  if (s_return->exp_)
    s_return->exp_->accept(this);
  builder->CreateRet(lastValue);
}

void Generator::visitSReturnV(SReturnV *s_return_v) {
  builder->CreateRetVoid();
}

void Generator::visitSWhile(SWhile *s_while) {
  llvm::Function *function = builder->GetInsertBlock()->getParent();

  llvm::BasicBlock *condBB =
      llvm::BasicBlock::Create(*context, "while_cond", function);
  llvm::BasicBlock *bodyBB =
      llvm::BasicBlock::Create(*context, "while_body", function);
  llvm::BasicBlock *endBB =
      llvm::BasicBlock::Create(*context, "while_end", function);

  builder->CreateBr(condBB);
  builder->SetInsertPoint(condBB);

  if (s_while->exp_)
    s_while->exp_->accept(this);

  builder->CreateCondBr(lastValue, bodyBB, endBB);

  builder->SetInsertPoint(bodyBB);
  if (s_while->stm_)
    s_while->stm_->accept(this);

  builder->CreateBr(condBB);

  builder->SetInsertPoint(endBB);
}

void Generator::visitSDoWhile(SDoWhile *s_do_while) {
  llvm::Function *function = builder->GetInsertBlock()->getParent();
  llvm::BasicBlock *afterLoopBB =
      llvm::BasicBlock::Create(*context, "after-loop", function);
  llvm::BasicBlock *condBB =
      llvm::BasicBlock::Create(*context, "cond", function);
  llvm::BasicBlock *loopBB =
      llvm::BasicBlock::Create(*context, "loop-body", function);

  builder->CreateBr(loopBB);
  builder->SetInsertPoint(loopBB);
  if (s_do_while->stm_)
    s_do_while->stm_->accept(this);
  builder->CreateBr(condBB);

  builder->SetInsertPoint(condBB);
  if (s_do_while->exp_)
    s_do_while->exp_->accept(this);
  builder->CreateCondBr(lastValue, loopBB, afterLoopBB);
  builder->SetInsertPoint(afterLoopBB);
}

void Generator::visitSFor(SFor *s_for) {
  llvm::Function *function = builder->GetInsertBlock()->getParent();
  llvm::BasicBlock *afterLoopBB =
      llvm::BasicBlock::Create(*context, "after-loop", function);
  llvm::BasicBlock *condBB =
      llvm::BasicBlock::Create(*context, "cond", function);
  llvm::BasicBlock *loopBB =
      llvm::BasicBlock::Create(*context, "loop-body", function);
  llvm::BasicBlock *incBB =
      llvm::BasicBlock::Create(*context, "increment", function);

  if (s_for->exp_1)
    s_for->exp_1->accept(this);

  builder->CreateBr(condBB);
  builder->SetInsertPoint(condBB);
  if (s_for->exp_2)
    s_for->exp_2->accept(this);
  builder->CreateCondBr(lastValue, loopBB, afterLoopBB);

  builder->SetInsertPoint(loopBB);
  if (s_for->stm_)
    s_for->stm_->accept(this);
  builder->CreateBr(incBB);
  builder->SetInsertPoint(incBB);
  if (s_for->exp_3)
    s_for->exp_3->accept(this);
  builder->CreateBr(condBB);
  builder->SetInsertPoint(afterLoopBB);
}

void Generator::visitSBlock(SBlock *s_block) {
  /* Code For SBlock Goes Here */

  if (s_block->liststm_)
    s_block->liststm_->accept(this);
}

void Generator::visitSIfElse(SIfElse *s_if_else) {
  llvm::Function *function = builder->GetInsertBlock()->getParent();

  llvm::BasicBlock *thenBB =
      llvm::BasicBlock::Create(*context, "then", function);
  llvm::BasicBlock *elseBB =
      llvm::BasicBlock::Create(*context, "else", function);
  llvm::BasicBlock *endBB =
      llvm::BasicBlock::Create(*context, "if_end", function);

  if (s_if_else->exp_)
    s_if_else->exp_->accept(this);

  builder->CreateCondBr(lastValue, thenBB, elseBB);

  builder->SetInsertPoint(thenBB);
  if (s_if_else->stm_1)
    s_if_else->stm_1->accept(this);

  builder->CreateBr(elseBB);
  builder->SetInsertPoint(elseBB);
  if (s_if_else->stm_2)
    s_if_else->stm_2->accept(this);

  builder->CreateBr(endBB);
  builder->SetInsertPoint(endBB);
}

void Generator::visitETrue(ETrue *e_true) {
  lastValue = llvm::ConstantInt::get(*context, llvm::APInt(1, 1));
}

void Generator::visitEFalse(EFalse *e_false) {
  lastValue = llvm::ConstantInt::get(*context, llvm::APInt(1, 0));
}

void Generator::visitEInt(EInt *e_int) {
  lastValue =
      llvm::ConstantInt::get(*context, llvm::APInt(32, e_int->integer_));
}

void Generator::visitEIdent(EIdent *e_ident) {
  llvm::GlobalVariable *globalVariable =
      TheModule->getNamedGlobal(e_ident->ident_);
  lastValue = builder->CreateLoad(globalVariable->getValueType(),
                                  globalVariable, "loadedVar");
  lastStruct = e_ident->ident_;
}

void Generator::visitEApp(EApp *e_app) {
  llvm::Function *function = TheModule->getFunction(e_app->ident_);
  // Only store the last value if the function is not void
  if (function->getReturnType()->isVoidTy()) {
    builder->CreateCall(function, llvm::None);
  } else {
    lastValue = builder->CreateCall(function, llvm::None, "calltmp");
  }
}

void Generator::visitEProj(EProj *e_proj) {
  if (e_proj->exp_)
    e_proj->exp_->accept(this);
  lastStruct =
      llvm::dyn_cast<llvm::StructType>(lastValue->getType())->getName();
  lastValue = builder->CreateExtractValue(
      lastValue, getStructFieldIndex(lastStruct, e_proj->ident_),
      "extractedField");
  // FIXME: getPointerElementType is deprecated
  /* lastValue =
       builder->CreateLoad(structField->getType()->getPointerElementType(),
                           structField, "loadedVar"); */
}

// TODO: Move redundant code of unary operators to dedicated function like
// getVariable
void Generator::visitEPIncr(EPIncr *ep_incr) {
  if (ep_incr->exp_)
    ep_incr->exp_->accept(this);
  if (dynamic_cast<EIdent *>(ep_incr->exp_)) {
    llvm::GlobalVariable *globalVar = TheModule->getNamedGlobal(
        dynamic_cast<EIdent *>(ep_incr->exp_)->ident_);

    llvm::Value *value = builder->CreateAdd(
        lastValue, llvm::ConstantInt::get(*context, llvm::APInt(32, 1)),
        "addtmp");
    builder->CreateStore(value, globalVar);
  } else if (EProj *e_proj = dynamic_cast<EProj *>(ep_incr->exp_)) {
    llvm::Value *structField = getStructField(e_proj->exp_, e_proj->ident_);
    llvm::Value *value = builder->CreateAdd(
        lastValue, llvm::ConstantInt::get(*context, llvm::APInt(32, 1)),
        "addtmp");
    builder->CreateStore(value, structField);
  }
}

void Generator::visitEPDecr(EPDecr *ep_decr) {
  if (ep_decr->exp_)
    ep_decr->exp_->accept(this);
  if (dynamic_cast<EIdent *>(ep_decr->exp_)) {
    llvm::GlobalVariable *globalVar = TheModule->getNamedGlobal(
        dynamic_cast<EIdent *>(ep_decr->exp_)->ident_);

    llvm::Value *value = builder->CreateSub(
        lastValue, llvm::ConstantInt::get(*context, llvm::APInt(32, 1)),
        "subtmp");
    builder->CreateStore(value, globalVar);
  } else if (EProj *e_proj = dynamic_cast<EProj *>(ep_decr->exp_)) {
    llvm::Value *structField = getStructField(e_proj->exp_, e_proj->ident_);
    llvm::Value *value = builder->CreateSub(
        lastValue, llvm::ConstantInt::get(*context, llvm::APInt(32, 1)),
        "subtmp");
    builder->CreateStore(value, structField);
  }
}

void Generator::visitEIncr(EIncr *e_incr) {
  if (e_incr->exp_)
    e_incr->exp_->accept(this);

  if (dynamic_cast<EIdent *>(e_incr->exp_)) {
    llvm::GlobalVariable *globalVar =
        TheModule->getNamedGlobal(dynamic_cast<EIdent *>(e_incr->exp_)->ident_);

    lastValue = builder->CreateAdd(
        lastValue, llvm::ConstantInt::get(*context, llvm::APInt(32, 1)),
        "addtmp");
    builder->CreateStore(lastValue, globalVar);
  } else if (EProj *e_proj = dynamic_cast<EProj *>(e_incr->exp_)) {
    llvm::Value *structField = getStructField(e_proj->exp_, e_proj->ident_);
    lastValue = builder->CreateAdd(
        lastValue, llvm::ConstantInt::get(*context, llvm::APInt(32, 1)),
        "addtmp");
    builder->CreateStore(lastValue, structField);
  }
}

void Generator::visitEDecr(EDecr *e_decr) {
  if (e_decr->exp_)
    e_decr->exp_->accept(this);
  if (dynamic_cast<EIdent *>(e_decr->exp_)) {
    llvm::GlobalVariable *globalVar =
        TheModule->getNamedGlobal(dynamic_cast<EIdent *>(e_decr->exp_)->ident_);

    lastValue = builder->CreateSub(
        lastValue, llvm::ConstantInt::get(*context, llvm::APInt(32, 1)),
        "addtmp");
    builder->CreateStore(lastValue, globalVar);
  } else if (EProj *e_proj = dynamic_cast<EProj *>(e_decr->exp_)) {
    llvm::Value *structField = getStructField(e_proj->exp_, e_proj->ident_);
    lastValue = builder->CreateSub(
        lastValue, llvm::ConstantInt::get(*context, llvm::APInt(32, 1)),
        "addtmp");
    builder->CreateStore(lastValue, structField);
  }
}

void Generator::visitEUPlus(EUPlus *eu_plus) {
  if (eu_plus->exp_)
    eu_plus->exp_->accept(this);
  lastValue = builder->CreateSelect(
      builder->CreateICmpSGT(
          lastValue, llvm::ConstantInt::get(*context, llvm::APInt(32, 0)),
          "gttmp"),
      lastValue, builder->CreateNeg(lastValue, "negtmp"));
}

void Generator::visitEUMinus(EUMinus *eu_minus) {
  if (eu_minus->exp_)
    eu_minus->exp_->accept(this);
  // Multiply by -1
  lastValue = builder->CreateNeg(lastValue, "negtmp");
}

void Generator::visitETimes(ETimes *e_times) {
  if (e_times->exp_1)
    e_times->exp_1->accept(this);
  llvm::Value *left = lastValue;
  if (e_times->exp_2)
    e_times->exp_2->accept(this);
  llvm::Value *right = lastValue;
  lastValue = builder->CreateMul(left, right, "multmp");
}

void Generator::visitEDiv(EDiv *e_div) {

  if (e_div->exp_1)
    e_div->exp_1->accept(this);
  llvm::Value *left = lastValue;
  if (e_div->exp_2)
    e_div->exp_2->accept(this);
  llvm::Value *right = lastValue;
  lastValue = builder->CreateUDiv(left, right, "divtmp");
}

void Generator::visitEPlus(EPlus *e_plus) {
  if (e_plus->exp_1)
    e_plus->exp_1->accept(this);
  llvm::Value *left = lastValue;
  if (e_plus->exp_2)
    e_plus->exp_2->accept(this);
  llvm::Value *right = lastValue;
  lastValue = builder->CreateAdd(left, right, "addtmp");
}

void Generator::visitEMinus(EMinus *e_minus) {
  if (e_minus->exp_1)
    e_minus->exp_1->accept(this);
  llvm::Value *left = lastValue;
  if (e_minus->exp_2)
    e_minus->exp_2->accept(this);
  llvm::Value *right = lastValue;
  lastValue = builder->CreateSub(left, right, "subtmp");
}

void Generator::visitETwc(ETwc *e_twc) {
  if (e_twc->exp_1)
    e_twc->exp_1->accept(this);
  llvm::Value *left = lastValue;
  if (e_twc->exp_2)
    e_twc->exp_2->accept(this);
  llvm::Value *right = lastValue;
  llvm::Value *lt = builder->CreateICmpSLT(left, right, "isLessThan");
  llvm::Value *lt_32 =
      builder->CreateZExt(lt, builder->getInt32Ty(), "castTo32Bit");
  llvm::Value *gt = builder->CreateICmpSGT(left, right, "isGreaterThan");
  llvm::Value *gt_32 =
      builder->CreateZExt(gt, builder->getInt32Ty(), "castTo32Bit");
  llvm::Value *lhs =
      builder->CreateMul(llvm::ConstantInt::get(*context, llvm::APInt(32, -1)),
                         lt_32, "negateIfLessThan");
  lastValue = builder->CreateAdd(lhs, gt_32, "addIfGreaterThan");
}

void Generator::visitELt(ELt *e_lt) {
  if (e_lt->exp_1)
    e_lt->exp_1->accept(this);
  llvm::Value *left = lastValue;
  if (e_lt->exp_2)
    e_lt->exp_2->accept(this);
  llvm::Value *right = lastValue;
  lastValue = builder->CreateICmpSLT(left, right, "isLessThan");
}

void Generator::visitEGt(EGt *e_gt) {
  /* Code For EGt Goes Here */

  if (e_gt->exp_1)
    e_gt->exp_1->accept(this);

  llvm::Value *left = lastValue;
  if (e_gt->exp_2)
    e_gt->exp_2->accept(this);

  llvm::Value *right = lastValue;
  lastValue = builder->CreateICmpSGT(left, right, "isGreaterThan");
}

void Generator::visitELtEq(ELtEq *e_lt_eq) {
  if (e_lt_eq->exp_1)
    e_lt_eq->exp_1->accept(this);
  llvm::Value *left = lastValue;
  if (e_lt_eq->exp_2)
    e_lt_eq->exp_2->accept(this);
  llvm::Value *right = lastValue;
  lastValue = builder->CreateICmpSLE(left, right, "isLessThanEqual");
}

void Generator::visitEGtEq(EGtEq *e_gt_eq) {
  if (e_gt_eq->exp_1)
    e_gt_eq->exp_1->accept(this);
  llvm::Value *left = lastValue;
  if (e_gt_eq->exp_2)
    e_gt_eq->exp_2->accept(this);
  llvm::Value *right = lastValue;

  lastValue = builder->CreateICmpSGE(left, right, "isGreaterThanEqual");
}

llvm::Value *Generator::isEqual(llvm::Value *left, llvm::Value *right) {
  // Base Case: values are primitive
  if (left->getType()->isIntegerTy() && right->getType()->isIntegerTy()) {
    if (left->getType()->getIntegerBitWidth() !=
        right->getType()->getIntegerBitWidth()) {
      return llvm::ConstantInt::get(*context, llvm::APInt(1, 0));
    }
    return builder->CreateICmpEQ(left, right, "eqtmp");
  }
  // Recursive Case: values are structs
  llvm::StructType *structType = llvm::cast<llvm::StructType>(left->getType());
  llvm::Value *result = llvm::ConstantInt::get(*context, llvm::APInt(1, 1));
  for (int i = 0; i < structType->getNumElements(); i++) {
    llvm::Value *leftField = builder->CreateExtractValue(left, i);
    llvm::Value *rightField = builder->CreateExtractValue(right, i);
    result =
        builder->CreateAnd(result, isEqual(leftField, rightField), "andtmp");
  }
  return result;
}

void Generator::visitEEq(EEq *e_eq) {
  if (e_eq->exp_1)
    e_eq->exp_1->accept(this);
  llvm::Value *left = lastValue;
  if (e_eq->exp_2)
    e_eq->exp_2->accept(this);
  llvm::Value *right = lastValue;
  lastValue = isEqual(left, right);
}

void Generator::visitENEq(ENEq *en_eq) {
  if (en_eq->exp_1)
    en_eq->exp_1->accept(this);
  llvm::Value *left = lastValue;
  if (en_eq->exp_2)
    en_eq->exp_2->accept(this);
  llvm::Value *right = lastValue;

  llvm::Value *result = isEqual(left, right);
  lastValue = builder->CreateNot(result, "nottmp");
}

void Generator::visitEAnd(EAnd *e_and) {
  if (e_and->exp_1)
    e_and->exp_1->accept(this);
  llvm::Value *left = lastValue;
  if (e_and->exp_2)
    e_and->exp_2->accept(this);
  llvm::Value *right = lastValue;
  lastValue = builder->CreateAnd(left, right, "andtmp");
}

void Generator::visitEOr(EOr *e_or) {
  if (e_or->exp_1)
    e_or->exp_1->accept(this);
  llvm::Value *left = lastValue;
  if (e_or->exp_2)
    e_or->exp_2->accept(this);
  llvm::Value *right = lastValue;
  lastValue = builder->CreateOr(left, right, "ortmp");
}

void Generator::visitEAss(EAss *e_ass) {
  // Would cause the var to be loaded, not necessary for assignment
  /*
  if (e_ass->exp_1)
    e_ass->exp_1->accept(this);*/

  if (e_ass->exp_2)
    e_ass->exp_2->accept(this);

  // l-value is variable of primitive
  if (dynamic_cast<EIdent *>(e_ass->exp_1)) {
    llvm::GlobalVariable *globalVar =
        TheModule->getNamedGlobal(dynamic_cast<EIdent *>(e_ass->exp_1)->ident_);

    builder->CreateStore(lastValue, globalVar);
  } else if (EProj *e_proj = dynamic_cast<EProj *>(e_ass->exp_1)) {
    llvm::Value *structField = getStructField(e_proj->exp_, e_proj->ident_);
    builder->CreateStore(lastValue, structField);
  }
}

void Generator::visitECond(ECond *e_cond) {
  // Ternary operator
  if (e_cond->exp_1)
    e_cond->exp_1->accept(this);
  llvm::Value *condValue = lastValue;

  llvm::Function *function = builder->GetInsertBlock()->getParent();
  llvm::BasicBlock *thenBB =
      llvm::BasicBlock::Create(*context, "then", function);
  llvm::BasicBlock *elseBB = llvm::BasicBlock::Create(*context, "else");
  llvm::BasicBlock *mergeBB = llvm::BasicBlock::Create(*context, "ifcont");

  builder->CreateCondBr(condValue, thenBB, elseBB);

  builder->SetInsertPoint(thenBB);
  if (e_cond->exp_2)
    e_cond->exp_2->accept(this);
  llvm::Value *thenValue = lastValue;
  builder->CreateBr(mergeBB);
  thenBB = builder->GetInsertBlock();

  function->getBasicBlockList().push_back(elseBB);
  builder->SetInsertPoint(elseBB);
  if (e_cond->exp_3)
    e_cond->exp_3->accept(this);
  llvm::Value *elseValue = lastValue;
  builder->CreateBr(mergeBB);
  elseBB = builder->GetInsertBlock();

  function->getBasicBlockList().push_back(mergeBB);
  builder->SetInsertPoint(mergeBB);
  llvm::PHINode *PN = builder->CreatePHI(thenValue->getType(), 2, "iftmp");

  PN->addIncoming(thenValue, thenBB);
  PN->addIncoming(elseValue, elseBB);

  lastValue = PN;
}

void Generator::visitType_bool(Type_bool *type_bool) {
  /* Code For Type_bool Goes Here */
}

void Generator::visitType_int(Type_int *type_int) {
  /* Code For Type_int Goes Here */
}

void Generator::visitType_void(Type_void *type_void) {
  /* Code For Type_void Goes Here */
}

void Generator::visitTypeIdent(TypeIdent *type_ident) {
  /* Code For TypeIdent Goes Here */

  visitIdent(type_ident->ident_);
}

void Generator::visitListDef(ListDef *list_def) {
  for (ListDef::iterator i = list_def->begin(); i != list_def->end(); ++i) {
    (*i)->accept(this);
  }
}

void Generator::visitListField(ListField *list_field) {
  for (ListField::iterator i = list_field->begin(); i != list_field->end();
       ++i) {
    (*i)->accept(this);
  }
}

void Generator::visitListStm(ListStm *list_stm) {
  for (ListStm::iterator i = list_stm->begin(); i != list_stm->end(); ++i) {
    (*i)->accept(this);
  }
}

void Generator::visitInteger(Integer x) { /* Code for Integer Goes Here */
}

void Generator::visitChar(Char x) { /* Code for Char Goes Here */
}

void Generator::visitDouble(Double x) { /* Code for Double Goes Here */
}

void Generator::visitString(String x) { /* Code for String Goes Here */
}

void Generator::visitIdent(Ident x) { /* Code for Ident Goes Here */
}
