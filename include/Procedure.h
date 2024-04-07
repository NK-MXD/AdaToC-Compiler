#ifndef __ADA2C_PROCEDURE_H__
#define __ADA2C_PROCEDURE_H__

#include "SymbolTable.h"
#include "Type.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

extern FILE* yyout;

class CppUnit;

class Procedure {
private:
  SymbolEntry *sym_ptr;
  CppUnit *parent;

public:
  Procedure(CppUnit *unit, SymbolEntry *symbol);
  ~Procedure();
  void output() const;
  SymbolEntry *getSymPtr() { return sym_ptr; };
};

#endif