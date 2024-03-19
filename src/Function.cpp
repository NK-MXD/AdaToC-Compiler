#include "Function.h"
#include "CppUnit.h"
#include "Type.h"
#include <list>

extern FILE *yyout;

Function::Function(CppUnit *unit, SymbolEntry *symbol) {
  unit->insertFunc(this);
  sym_ptr = symbol;
  parent = unit;
}

Function::~Function() { parent->removeFunc(this); }

void Function::output() const {
  // translate Function in ada grammar to cpp grammar
  // eg.
  /*

  */
  FunctionType *funcType = dynamic_cast<FunctionType *>(sym_ptr->getType());
  Type *retType = funcType->getRetType();
}