

#ifndef GENERATOR_HEADER
#define GENERATOR_HEADER

#include "Absyn.H"
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "map"


class Generator : public Visitor
{
private:
  llvm::Value* lastValue;
  std::string lastStruct;
  // Maps struct name to a vector of pairs of field name and type
  std::map<std::string, std::vector<std::pair<std::string, llvm::Type*>>> structFields;
  std::unique_ptr<llvm::LLVMContext> context;
  llvm::Value* getStructField(Exp* lhs, std::string fieldName);
  int getStructFieldIndex(std::string structName, std::string fieldName);
  llvm::GlobalVariable* getStructFieldIndices(Exp* lhs, std::vector<llvm::Value*>* indices, std::string fieldName);
  llvm::Value* isEqual(llvm::Value* lhs, llvm::Value* rhs);
  //TODO: Rename TheModule
  std::unique_ptr<llvm::Module> TheModule;
  std::unique_ptr<llvm::IRBuilder<>> builder;
  void visitProgram(Program *p);
  llvm::Type* convertType(Type *p);
  void visitDef(Def *p);
  void visitField(Field *p);
  void visitStm(Stm *p);
  void visitExp(Exp *p);
  void visitType(Type *p);
  void visitPDefs(PDefs *p);
  void visitDVar(DVar *p);
  void visitDFun(DFun *p);
  void visitDStruct(DStruct *p);
  void visitFDecl(FDecl *p);
  void visitSExp(SExp *p);
  void visitSReturn(SReturn *p);
  void visitSReturnV(SReturnV *p);
  void visitSWhile(SWhile *p);
  void visitSDoWhile(SDoWhile *p);
  void visitSFor(SFor *p);
  void visitSBlock(SBlock *p);
  void visitSIfElse(SIfElse *p);
  void visitETrue(ETrue *p);
  void visitEFalse(EFalse *p);
  void visitEInt(EInt *p);
  void visitEIdent(EIdent *p);
  void visitEApp(EApp *p);
  void visitEProj(EProj *p);
  void visitEPIncr(EPIncr *p);
  void visitEPDecr(EPDecr *p);
  void visitEIncr(EIncr *p);
  void visitEDecr(EDecr *p);
  void visitEUPlus(EUPlus *p);
  void visitEUMinus(EUMinus *p);
  void visitETimes(ETimes *p);
  void visitEDiv(EDiv *p);
  void visitEPlus(EPlus *p);
  void visitEMinus(EMinus *p);
  void visitETwc(ETwc *p);
  void visitELt(ELt *p);
  void visitEGt(EGt *p);
  void visitELtEq(ELtEq *p);
  void visitEGtEq(EGtEq *p);
  void visitEEq(EEq *p);
  void visitENEq(ENEq *p);
  void visitEAnd(EAnd *p);
  void visitEOr(EOr *p);
  void visitEAss(EAss *p);
  void visitECond(ECond *p);
  void visitType_bool(Type_bool *p);
  void visitType_int(Type_int *p);
  void visitType_void(Type_void *p);
  void visitTypeIdent(TypeIdent *p);
  void visitListDef(ListDef *p);
  void visitListField(ListField *p);
  void visitListStm(ListStm *p);

  void visitInteger(Integer x);
  void visitChar(Char x);
  void visitDouble(Double x);
  void visitString(String x);
  void visitIdent(Ident x);

public:
  void generate(Program *p);
};


#endif
