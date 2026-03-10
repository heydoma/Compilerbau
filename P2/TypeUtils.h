#include "Absyn.H"
#include <string>
#ifndef TYPE_UTILS
#define TYPE_UTILS

namespace TypeUtils {
  bool isTypeInt(Type* t);
  bool isTypeDouble(Type* t);
  bool isTypeBool(Type* t);
  bool isTypeVoid(Type* t);
  bool isTypeStruct(Type* t);
  std::string toString(Type* t);
  Type* inferArithType(Type* t1, Type* t2);
  bool isLValue(Exp* e);
  bool isNumeric(Type* t1);
};
#endif
