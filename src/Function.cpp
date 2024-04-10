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

void Function::output(int level) const {
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
  fprintf(yyout, "%*cclass %s {\n", level, ' ', symPtr->dump().c_str());
  // 1. Process declared operands
  if (haveDeclOp()) {
    fprintf(yyout, "%*cprivate:\n", level, ' ');
    for (int i = 0; i < declOps.size(); i++) {
      Operand *curOp = declOps[i];
      std::string opType;
      if (curOp->getType()->isInteger()) {
        opType = "int";
      }
      fprintf(yyout, "%*c%s %s;\n", level + 2, ' ', opType.c_str(), curOp->dump().c_str());
    }
    if (decls) {
      decls->output();
    }
  }
  // 2. Process statements
  fprintf(yyout, "%*cpublic:\n", level, ' ');
  std::string retType;
  if (symPtr->getType()->isProcedure()) {
    retType = "void";
    fprintf(yyout, "%*cstatic %s main", level + 2, ' ', retType.c_str());
    ProcedureType *proType = dynamic_cast<ProcedureType *>(symPtr->getType());
    std::vector<Type *> paramType = proType->getParamType();
    std::vector<SymbolEntry *> paramIds = proType->getParamIds();
    if (paramType.empty()) {
      fprintf(yyout, "()\n");
    }
    fprintf(yyout, "%*c{\n", level + 2, ' ');
    // 3. Core statments translation
    if (stats) {
      stats->output();
    }
    fprintf(yyout, "%*c}\n", level + 2, ' ');
  }
  fprintf(yyout, "%*c};\n", level, ' ');
}