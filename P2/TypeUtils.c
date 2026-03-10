#include "TypeUtils.h"

bool TypeUtils::isNumeric(Type *t1) {
  return TypeUtils::isTypeInt(t1) || TypeUtils::isTypeDouble(t1);
}

bool TypeUtils::isTypeInt(Type *t) { return dynamic_cast<Type_int *>(t); }

bool TypeUtils::isTypeDouble(Type *t) { return dynamic_cast<Type_double *>(t); }

bool TypeUtils::isTypeBool(Type *t) { return dynamic_cast<Type_bool *>(t); }

bool TypeUtils::isTypeVoid(Type *t) { return dynamic_cast<Type_void *>(t); }

bool TypeUtils::isTypeStruct(Type *t) { return dynamic_cast<TypeId *>(t); }

bool TypeUtils::isLValue(Exp *e) {
  return dynamic_cast<EId *>(e) || dynamic_cast<EProj *>(e);
}

std::string TypeUtils::toString(Type *t) {
  if (isTypeInt(t))
    return "int";
  if (isTypeDouble(t))
    return "double";
  if (isTypeBool(t))
    return "bool";
  if (isTypeVoid(t))
    return "void";
  if (isTypeStruct(t))
    return "struct with id " + dynamic_cast<TypeId *>(t)->id_;
  return "unknown";
}

Type *TypeUtils::inferArithType(Type *t1, Type *t2) {
  if (isTypeInt(t1) && isTypeDouble(t2))
    return new Type_double();
  if (isTypeDouble(t1) && isTypeInt(t2))
    return new Type_double();
  if (isTypeInt(t1) && isTypeInt(t2))
    return new Type_int();
  if (isTypeDouble(t1) && isTypeDouble(t2))
    return new Type_double();
  throw "Arith. type mismatch: expected " + TypeUtils::toString(t1) + ", got " +
      TypeUtils::toString(t2);
}

