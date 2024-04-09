#include "Function.h"
#include "CppUnit.h"
#include "Type.h"
#include <list>

extern FILE *yyout;

Function::Function(CppUnit *unit, SymbolEntry *symbol) {
  unit->insertFunc(this);
  symPtr = symbol;
  parent = unit;
}

Function::~Function() { parent->removeFunc(this); }

void Function::output() const {
  // translate Procedure in ada grammar to Function in cpp grammar
  // eg.
  /*
    procedure main is
    begin
    ...
    end main;
  */
  /*
    class main {
    public:
      static void main() {
        ...
      }
    };
  */
  fprintf(yyout, "class %s\n", symPtr->dump().c_str());
  fprintf(yyout, "{\n");
  // 1. Process declared operands
  if (haveDeclOp()) {
    fprintf(yyout, "private:\n");
    for (int i = 0; i < declOps.size(); i++) {
      Operand *curOp = declOps[i];
      std::string opType;
      if (curOp->getType()->isInteger()) {
        opType = "int";
      }
      fprintf(yyout, "%s %s;\n", opType.c_str(), curOp->dump().c_str());
    }
    if (decls) {
      decls->output();
    }
  }
  // 2. Process statements
  fprintf(yyout, "public:\n");
  std::string retType;
  if (symPtr->getType()->isProcedure()) {
    retType = "void";
    fprintf(yyout, "static %s main", retType.c_str());
    ProcedureType *proType = dynamic_cast<ProcedureType *>(symPtr->getType());
    std::vector<Type *> paramType = proType->getParamType();
    std::vector<SymbolEntry *> paramIds = proType->getParamIds();
    if (paramType.empty()) {
      fprintf(yyout, "()\n");
    }
    fprintf(yyout, "{\n");
    // 3. Core statments translation
    if (stats) {
      stats->output();
    }
    fprintf(yyout, "}\n");
  }
  fprintf(yyout, "};\n");
}