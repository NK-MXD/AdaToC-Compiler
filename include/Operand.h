#ifndef __ADA2C_OPERAND_H__
#define __ADA2C_OPERAND_H__

#include "SymbolTable.h"
#include "Type.h"

class CppExpr;

class Operand {
private:
  SymbolEntry *se;
  Type *type;
  // Init value of Operand
  CppExpr *init;

  // Constant or not;
  bool isConst;

public:
  Operand(SymbolEntry *_se, Type *_type, CppExpr *_init = nullptr)
      : se(_se), type(_type), init(_init) {}
  Operand(SymbolEntry *_se, Type *_type, bool _isConst,
          CppExpr *_init = nullptr)
      : se(_se), type(_type), isConst(_isConst), init(_init) {}
  std::string getName() { return se->dump(); }
  std::string typeName() { return type->toCppStr(); }
  Type *getType() { return type; }
  CppExpr *getCppExpr() { return init; }
  CppExpr *getInit() { return init; }
  bool getConst() { return isConst; }
};

#endif