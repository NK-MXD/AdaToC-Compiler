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
  Operand(SymbolEntry *_se, Type *_type, bool _isConst)
      : se(_se), type(_type), isConst(_isConst) {}
  std::string dump() { return se->dump(); }
  Type* getType() {
    return type;
  }
  CppExpr *getInit() { return init; }
};

#endif