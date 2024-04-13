#ifndef __ADA2C_FUNCTION_H__
#define __ADA2C_FUNCTION_H__

#include "Operand.h"
#include "Statement.h"
#include "SymbolTable.h"
#include "Type.h"
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
  Function *prev = nullptr;

  // Some declared operands.
  std::vector<Operand *> declOps;
  // Some declarations.
  CppStmt *decls;

  // Some statements.
  std::vector<CppStmt*> stats;

public:
  Function(CppUnit *unit, SymbolEntry *symbol);
  ~Function();
  void addDeclOps(Operand *op) { declOps.push_back(op); }
  void setPrev(Function *func) { prev = func; }
  std::string getName() { return symPtr->dump(); }
  void output(int level) const;
  SymbolEntry *getSymPtr() { return symPtr; };
  bool haveDeclOp() const { return !declOps.empty(); }
  void insertStmts(CppStmt* stmt) { stats.push_back(stmt); }
};

#endif