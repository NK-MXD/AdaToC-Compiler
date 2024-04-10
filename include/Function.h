#ifndef __ADA2C_FUNCTION_H__
#define __ADA2C_FUNCTION_H__

#include "SymbolTable.h"
#include "Type.h"
#include "Operand.h"
#include "Statement.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

class CppUnit;

// Ada Procedure and Ada Function => Cpp Class
class Function {
private:
  // Name of Procedure or Function
  SymbolEntry *symPtr;
  CppUnit *parent;
  
  // Some declared operands.
  std::vector<Operand*> declOps;
  // Some declarations.
  CppStmt* decls;

  // Some statements.
  CppStmt* stats;

public:
  Function(CppUnit *unit, SymbolEntry *symbol);
  ~Function() ;
  void addDeclOps(Operand* op) {
    declOps.push_back(op);
  }
  void output(int level) const;
  SymbolEntry *getSymPtr() { return symPtr; };
  bool haveDeclOp() const{
    return !declOps.empty();
  }
};

#endif