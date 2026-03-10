/*** Visitor Design Pattern TypeChecker. ***/

#include "TypeChecker.H"
#include "TypeUtils.h"
#include <iostream>
#include <vector>

// This is part of the environment as it requires lookup of structs
bool Env::isTypeException(Type *t) {
  if (dynamic_cast<Type_exception *>(t))
    return true;
  TypeId *s = dynamic_cast<TypeId *>(t);
  if (!s)
    return false;
  try {
    return dynamic_cast<Type_exception *>(structTable.at(s->id_).parent) ||
           isTypeException(structTable.at(s->id_).parent);
  } catch (std::out_of_range e) {
    return false;
  }
}

/**
 * Check if two types are equal. If they are not, check if they are compatible.
 * (e.g. expect double, got int)
 */
void Env::checkTypeCompatibility(Type *expected, Type *actual) {
  if (!(expected == actual ||
        (TypeUtils::isTypeInt(expected) && TypeUtils::isTypeInt(actual)) ||
        (TypeUtils::isTypeDouble(expected) &&
         TypeUtils::isTypeDouble(actual)) ||
        (TypeUtils::isTypeBool(expected) && TypeUtils::isTypeBool(actual)) ||
        (TypeUtils::isTypeVoid(expected) && TypeUtils::isTypeVoid(actual)) ||
        (isTypeException(expected) && isTypeException(actual)) ||
        (TypeUtils::isTypeDouble(expected) && TypeUtils::isTypeInt(actual)) ||
        (TypeUtils::isTypeStruct(expected) && TypeUtils::isTypeStruct(actual) &&
         dynamic_cast<TypeId *>(expected)->id_ ==
             dynamic_cast<TypeId *>(actual)->id_))) {
    throw "Type mismatch: expected " + TypeUtils::toString(expected) +
        ", got " + TypeUtils::toString(actual);
  }
}

void Env::extend(Def *d) { d->accept(this); }

void Env::extend(Arg *a) { a->accept(this); }

void Env::visitADecl(ADecl *a_decl) {
  if (alreadyDeclared(a_decl->id_)) {
    throw "Variable already declared";
  }
  if (TypeUtils::isTypeVoid(a_decl->type_)) {
    throw "Void variable type not allowed";
  }
  if (TypeUtils::isTypeStruct(a_decl->type_) &&
      structTable.find(dynamic_cast<TypeId *>(a_decl->type_)->id_) ==
          structTable.end()) {
    throw "No such type declared";
  }
  contextList.back()[a_decl->id_] = a_decl->type_;
}

void Env::visitDFun(DFun *d_fun) {
  if (functionTable.find(d_fun->id_) != functionTable.end()) {
    throw "Function already declared";
  }
  if (TypeUtils::isTypeStruct(d_fun->type_) &&
      structTable.find(dynamic_cast<TypeId *>(d_fun->type_)->id_) ==
          structTable.end()) {
    throw "No such type declared";
  }
  tempType = d_fun->type_;

  tempId = d_fun->id_;
  d_fun->listarg_->accept(this);
}

void Env::visitListArg(ListArg *l) {
  std::vector<Type *> res;
  std::map<Id, void *> argIds;
  for (ListArg::iterator i = l->begin(); i != l->end(); ++i) {
    // Cast Arg to ADecl (legal because there is no other possibility in the
    // grammar)
    ADecl *a = dynamic_cast<ADecl *>(*i);
    if (TypeUtils::isTypeVoid(a->type_)) {
      throw "Void argument type not allowed";
    }
    if (TypeUtils::isTypeStruct(a->type_) &&
        structTable.find(dynamic_cast<TypeId *>(a->type_)->id_) ==
            structTable.end()) {
      throw "No such type declared";
    }
    res.push_back(a->type_);
    if (argIds.find(a->id_) != argIds.end()) {
      throw "Argument already declared";
    }
    argIds[a->id_] = nullptr;
  }
  functionTable[tempId].argTypes = res;
  functionTable[tempId].returnType = tempType;
}

void Env::visitDStruct(DStruct *p) {
  if (structTable.find(p->id_) != structTable.end()) {
    throw "Struct already declared";
  }
  tempId = p->id_;
  p->listfield_->accept(this);
}

void Env::visitDStructDer(DStructDer *p) {
  if (structTable.find(p->id_) != structTable.end()) {
    throw "Struct already declared";
  }
  Type *base_class = p->type_;
  if (!isTypeException(base_class)) {
    if (!TypeUtils::isTypeStruct(base_class)) {
      throw "Parent struct must be a struct or exception";
    }
    if (structTable.find(dynamic_cast<TypeId *>(base_class)->id_) ==
        structTable.end()) {
      throw "Parent struct not declared";
    }
  }
  tempId = p->id_;
  structTable[tempId].parent = base_class;
  p->listfield_->accept(this);
}

void Env::visitFDecl(FDecl *f_decl) {
  if (structTable[tempId].members.find(f_decl->id_) !=
      structTable[tempId].members.end()) {
    throw "Struct member already declared";
  }
  if (structTable[tempId].parent != nullptr &&
      !dynamic_cast<Type_exception *>(structTable[tempId].parent) && // prevent segfault in following lookup
      lookupStructMember(structTable[tempId].parent, f_decl->id_) != nullptr) {
        throw "Struct member already declared in parent struct";
  }
  if (TypeUtils::isTypeVoid(f_decl->type_)) {
    throw "Void struct member type not allowed";
  }
  structTable[tempId].members[f_decl->id_] = f_decl->type_;
}

Type *Env::lookupStructMember(Type *t, Id id) {
  TypeId *s = dynamic_cast<TypeId *>(t);
  if (s && structTable.find(s->id_) != structTable.end()) {
    if (structTable[s->id_].members.find(id) !=
        structTable[s->id_].members.end()) {
      return structTable[s->id_].members[id];
    }
    if (structTable[s->id_].parent != nullptr) {
      // members defined in parent struct should be visible in child
      return lookupStructMember(structTable[s->id_].parent, id);
    }
  }
  return nullptr;
}

bool Env::alreadyDeclared(Id id) {
  return contextList.back().find(id) != contextList.back().end();
}

void Env::newBlock() { contextList.push_back(std::map<Id, Type *>()); }

void Env::popBlock() { contextList.pop_back(); }

Type *Env::lookupVar(Id id) {
  for (std::vector<std::map<Id, Type *>>::reverse_iterator i =
           contextList.rbegin();
       i != contextList.rend(); ++i) {
    if (i->find(id) != i->end())
      return i->find(id)->second;
  }
  throw "Variable not declared";
}

FuncSignature Env::lookupFun(Id id) {
  if (functionTable.find(id) != functionTable.end()) {
    return functionTable.find(id)->second;
  }
  throw "Function not declared";
}

bool TypeChecker::check(Program *p) {
  try {
    p->accept(this);
    return true;
  } catch (const char *msg) {
    printf("%s\n", msg);
    return false;
  } catch (const std::string msg) {
    std::cout << msg << std::endl;
    return false;
  }
}

void TypeChecker::visitDFun(DFun *d_fun) {
  d_fun->type_->accept(this);
  tempCurrentFunId = d_fun->id_;
  env.newBlock();
  d_fun->listarg_->accept(this);
  d_fun->liststm_->accept(this);
  env.popBlock();
}

void TypeChecker::visitSDecls(SDecls *s_decls) {
  tempTypeCheck = s_decls->type_;
  s_decls->type_->accept(this);
  s_decls->listidin_->accept(this);
}

void TypeChecker::visitSReturn(SReturn *s_return) {
  s_return->exp_->accept(this);
  Type *returnType = env.lookupFun(tempCurrentFunId).returnType;
  env.checkTypeCompatibility(returnType, tempTypeInfer);
}

void TypeChecker::visitSReturnV(SReturnV *s_return_v) {
  if (!TypeUtils::isTypeVoid(env.lookupFun(tempCurrentFunId).returnType)) {
    throw "Function does not return void";
  }
}

void TypeChecker::visitSWhile(SWhile *s_while) {
  s_while->exp_->accept(this);
  if (!TypeUtils::isTypeBool(tempTypeInfer)) {
    throw "While loop condition must be boolean";
  }
  s_while->stm_->accept(this);
}

void TypeChecker::visitSDoWhile(SDoWhile *s_do_while) {
  s_do_while->exp_->accept(this);
  if (!TypeUtils::isTypeBool(tempTypeInfer)) {
    throw "Do-While loop condition must be boolean";
  }
  s_do_while->stm_->accept(this);
}

void TypeChecker::visitSFor(SFor *s_for) {
  s_for->exp_1->accept(this);
  s_for->exp_2->accept(this);
  if (!TypeUtils::isTypeBool(tempTypeInfer)) {
    throw "For loop condition must be boolean";
  }
  s_for->exp_3->accept(this);
  s_for->stm_->accept(this);
}

void TypeChecker::visitSBlock(SBlock *s_block) {
  env.newBlock();
  s_block->liststm_->accept(this);
  env.popBlock();
}

void TypeChecker::visitSIfElse(SIfElse *s_if_else) {
  s_if_else->exp_->accept(this);
  if (!TypeUtils::isTypeBool(tempTypeInfer)) {
    throw "If condition must be boolean";
  }
  s_if_else->stm_1->accept(this);
  s_if_else->stm_2->accept(this);
}

void TypeChecker::visitSTry(STry *s_try) {
  s_try->stm_1->accept(this);
  s_try->type_->accept(this);
  if (!env.isTypeException(s_try->type_)) {
    throw "Variable in try block must be of type exception";
  }
  env.newBlock();
  // Exception is only visible in catch block
  ADecl *a = new ADecl(s_try->type_, s_try->id_);
  env.extend(a);
  s_try->stm_2->accept(this);
  env.popBlock();
}

void TypeChecker::visitIdNoInit(IdNoInit *id_no_init) {
  // Variables declared later in list should not be visible before
  ADecl *a = new ADecl(tempTypeCheck, id_no_init->id_);
  env.extend(a);
}

void TypeChecker::visitIdInit(IdInit *id_init) {
  id_init->exp_->accept(this);
  // Variables declared later in list should not be visible before
  ADecl *a = new ADecl(tempTypeCheck, id_init->id_);
  env.extend(a);
  env.checkTypeCompatibility(tempTypeCheck, tempTypeInfer);
}

void TypeChecker::visitETrue(ETrue *e_true) { tempTypeInfer = new Type_bool(); }

void TypeChecker::visitEFalse(EFalse *e_false) { tempTypeInfer = new Type_bool(); }

void TypeChecker::visitEInt(EInt *e_int) {
  tempTypeInfer = new Type_int();
  visitInteger(e_int->integer_);
}

void TypeChecker::visitEDouble(EDouble *e_double) {
  tempTypeInfer = new Type_double();
  visitDouble(e_double->double_);
}

void TypeChecker::visitEId(EId *e_id) {
  tempTypeInfer = env.lookupVar(e_id->id_);
}

void TypeChecker::visitEApp(EApp *e_app) {
  tempFunId = e_app->id_;
  e_app->listexp_->accept(this);
  tempTypeInfer = env.lookupFun(e_app->id_).returnType;
}

void TypeChecker::visitEProj(EProj *e_proj) {
  e_proj->exp_->accept(this);
  tempTypeInfer = env.lookupStructMember(tempTypeInfer, e_proj->id_);
  if (tempTypeInfer == nullptr) {
    throw "Struct member not found";
  }
}

void TypeChecker::visitEPIncr(EPIncr *ep_incr) {
  ep_incr->exp_->accept(this);
  Type *t1 = tempTypeInfer;
  if (!TypeUtils::isLValue(ep_incr->exp_)) {
    throw "expression is not an l-value";
  }
  if (!TypeUtils::isNumeric(t1)) {
    throw "Increment operator applied to non-numeric type.";
  }
}

void TypeChecker::visitEPDecr(EPDecr *ep_decr) {
  ep_decr->exp_->accept(this);
  Type *t1 = tempTypeInfer;
  if (!TypeUtils::isLValue(ep_decr->exp_)) {
    throw "expression is not an l-value";
  }
  if (!TypeUtils::isNumeric(t1)) {
    throw "Decrement operator applied to non-numeric type.";
  }
}

void TypeChecker::visitEIncr(EIncr *e_incr) {
  e_incr->exp_->accept(this);
  Type *t1 = tempTypeInfer;
  if (!TypeUtils::isLValue(e_incr->exp_)) {
    throw "expression is not an l-value";
  }
  if (!TypeUtils::isNumeric(t1)) {
    throw "Increment operator applied to non-numeric type.";
  }
}

void TypeChecker::visitEDecr(EDecr *e_decr) {
  e_decr->exp_->accept(this);
  Type *t1 = tempTypeInfer;
  if (!TypeUtils::isLValue(e_decr->exp_)) {
    throw "expression is not an l-value";
  }
  if (!TypeUtils::isNumeric(t1)) {
    throw "Decrement operator applied to non-numeric type.";
  }
}

void TypeChecker::visitEUPlus(EUPlus *eu_plus) {
  eu_plus->exp_->accept(this);
  Type *t1 = tempTypeInfer;
  if (!TypeUtils::isNumeric(t1)) {
    throw "Unary plus applied to non-numeric typer.";
  }
}

void TypeChecker::visitEUMinus(EUMinus *eu_minus) {
  eu_minus->exp_->accept(this);
  Type *t1 = tempTypeInfer;
  if (!TypeUtils::isNumeric(t1)) {
    throw "Unary minus applied to non-numeric typer.";
  }
}

void TypeChecker::visitETimes(ETimes *e_times) {
  e_times->exp_1->accept(this);
  Type *t1 = tempTypeInfer;
  e_times->exp_2->accept(this);
  Type *t2 = tempTypeInfer;
  tempTypeInfer = TypeUtils::inferArithType(t1, t2);
}

void TypeChecker::visitEDiv(EDiv *e_div) {
  e_div->exp_1->accept(this);
  Type *t1 = tempTypeInfer;
  e_div->exp_2->accept(this);
  Type *t2 = tempTypeInfer;
  tempTypeInfer = TypeUtils::inferArithType(t1, t2);
}

void TypeChecker::visitEPlus(EPlus *e_plus) {
  e_plus->exp_1->accept(this);
  Type *t1 = tempTypeInfer;
  e_plus->exp_2->accept(this);
  Type *t2 = tempTypeInfer;
  tempTypeInfer = TypeUtils::inferArithType(t1, t2);
}

void TypeChecker::visitEMinus(EMinus *e_minus) {
  e_minus->exp_1->accept(this);
  Type *t1 = tempTypeInfer;
  e_minus->exp_2->accept(this);
  Type *t2 = tempTypeInfer;
  tempTypeInfer = TypeUtils::inferArithType(t1, t2);
}

void TypeChecker::visitETwc(ETwc *e_twc) {
  e_twc->exp_1->accept(this);
  Type *t1 = tempTypeInfer;
  e_twc->exp_2->accept(this);
  Type *t2 = tempTypeInfer;
  TypeUtils::inferArithType(t1, t2);
  tempTypeInfer = new Type_int();
}

void TypeChecker::visitELt(ELt *e_lt) {
  e_lt->exp_1->accept(this);
  Type *t1 = tempTypeInfer;
  e_lt->exp_2->accept(this);
  Type *t2 = tempTypeInfer;
  TypeUtils::inferArithType(t1, t2);
  tempTypeInfer = new Type_bool();
}

void TypeChecker::visitEGt(EGt *e_gt) {
  e_gt->exp_1->accept(this);
  Type *t1 = tempTypeInfer;
  e_gt->exp_2->accept(this);
  Type *t2 = tempTypeInfer;
  TypeUtils::inferArithType(t1, t2);
  tempTypeInfer = new Type_bool();
}

void TypeChecker::visitELtEq(ELtEq *e_lt_eq) {
  e_lt_eq->exp_1->accept(this);
  Type *t1 = tempTypeInfer;
  e_lt_eq->exp_2->accept(this);
  Type *t2 = tempTypeInfer;
  TypeUtils::inferArithType(t1, t2);
  tempTypeInfer = new Type_bool();
}

void TypeChecker::visitEGtEq(EGtEq *e_gt_eq) {
  e_gt_eq->exp_1->accept(this);
  Type *t1 = tempTypeInfer;
  e_gt_eq->exp_2->accept(this);
  Type *t2 = tempTypeInfer;
  TypeUtils::inferArithType(t1, t2);
  tempTypeInfer = new Type_bool();
}

void TypeChecker::visitEEq(EEq *e_eq) {
  e_eq->exp_1->accept(this);
  e_eq->exp_2->accept(this);
  tempTypeInfer = new Type_bool();
}

void TypeChecker::visitENEq(ENEq *en_eq) {
  en_eq->exp_1->accept(this);
  en_eq->exp_2->accept(this);
  tempTypeInfer = new Type_bool();
}

void TypeChecker::visitEAnd(EAnd *e_and) {
  e_and->exp_1->accept(this);
  Type *t1 = tempTypeInfer;
  e_and->exp_2->accept(this);
  Type *t2 = tempTypeInfer;
  if (!TypeUtils::isTypeBool(t1) || !TypeUtils::isTypeBool(t2)) {
    throw "&& condition requires both operands to be of type bool";
  }
}

void TypeChecker::visitEOr(EOr *e_or) {
  e_or->exp_1->accept(this);
  Type *t1 = tempTypeInfer;
  e_or->exp_2->accept(this);
  Type *t2 = tempTypeInfer;
  if (!TypeUtils::isTypeBool(t1) || !TypeUtils::isTypeBool(t2)) {
    throw "|| condition requires both operands to be of type bool";
  }
}

void TypeChecker::visitEAss(EAss *e_ass) {
  e_ass->exp_1->accept(this);
  Type *t1 = tempTypeInfer;
  e_ass->exp_2->accept(this);
  Type *t2 = tempTypeInfer;
  env.checkTypeCompatibility(t1, t2);
  if (!TypeUtils::isLValue(e_ass->exp_1)) {
    throw "expression is not an l-value";
  }
  // In case of numeric assignments the type can change due to casting
  if (TypeUtils::isNumeric(t1)) {
    tempTypeInfer = TypeUtils::inferArithType(t1, t2);
  }
}

void TypeChecker::visitECond(ECond *e_cond) {
  e_cond->exp_1->accept(this);
  if (!TypeUtils::isTypeBool(tempTypeInfer)) {
    throw "ECond condition must be boolean";
  }
  e_cond->exp_2->accept(this);
  Type *t1 = tempTypeInfer;
  e_cond->exp_3->accept(this);
  Type *t2 = tempTypeInfer;
  env.checkTypeCompatibility(t1, t2);
}

void TypeChecker::visitEThrow(EThrow *e_throw) {
  e_throw->exp_->accept(this);
  if (!env.isTypeException(tempTypeInfer)) {
    throw "Operand has to be of type exception";
  }
}

// Is only called for function application
void TypeChecker::visitListExp(ListExp *list_exp) {
  std::vector<Type *> args = env.lookupFun(tempFunId).argTypes;

  // Check if the number of arguments is correct
  if (args.size() != list_exp->size()) {
    throw "Incorrect number of arguments";
  }
  for (ListExp::iterator i = list_exp->begin(); i != list_exp->end(); ++i) {
    (*i)->accept(this);
    env.checkTypeCompatibility(args[i - list_exp->begin()], tempTypeInfer);
  }
}

void TypeChecker::visitListDef(ListDef *list_def) {
  for (ListDef::iterator i = list_def->begin(); i != list_def->end(); ++i) {
    env.extend(*i);
  }

  for (ListDef::iterator i = list_def->begin(); i != list_def->end(); ++i) {
    (*i)->accept(this);
  }
}

void TypeChecker::visitListArg(ListArg *list_arg) {
  for (ListArg::iterator i = list_arg->begin(); i != list_arg->end(); ++i) {
    env.extend(*i);
    (*i)->accept(this);
  }
}
