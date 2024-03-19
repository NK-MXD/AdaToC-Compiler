#ifndef __ADA2C_FUNCTION_H__
#define __ADA2C_FUNCTION_H__

#include "SymbolTable.h"
#include "Type.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

class CppUnit;

class Function {
private:
  SymbolEntry *sym_ptr;
  CppUnit *parent;

public:
  Function(CppUnit *unit, SymbolEntry *symbol);
  ~Function() ;
  void output() const;
  SymbolEntry *getSymPtr() { return sym_ptr; };
};

#endif