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

Function::Function(Function *func, SymbolEntry *symbol) {
  func->addSubFunc(this);
  prev = func;
  symPtr = symbol;
}

Function::~Function() {
  if (parent)
    parent->removeFunc(this);
}

std::string Function::getDeclStr(int level) const {
  std::string declStr;
  // 1. process operand declarations
  for (auto op : declOps) {
    char temp[100];
    sprintf(temp, "%*cstatic %s %s;\n", level, ' ', op->typeName().c_str(),
            op->getName().c_str());
    declStr += std::string(temp);
  }
  // 2. process other declarations
  for (auto decl : decls) {
    declStr += decl->output(level);
  }
  // 3. process procedure defination
  for (auto &func : subFuncs) {
    std::string temp = func->output(level);
    declStr += temp;
  }
  return declStr;
}

std::string Function::getParamStr() const {
  std::string paramStr;
  std::vector<Type *> paramType;
  std::vector<SymbolEntry *> paramIds;
  if (symPtr->getType()->isProcedure()) {
    ProcedureType *type = dynamic_cast<ProcedureType *>(symPtr->getType());
    paramType = type->getParamType();
    paramIds = type->getParamIds();
  }
  if (symPtr->getType()->isFunction()) {
    FunctionType *type = dynamic_cast<FunctionType *>(symPtr->getType());
    paramType = type->getParamType();
    paramIds = type->getParamIds();
  }
  paramStr += "(";
  if (paramType.empty()) {
    paramStr += ")";
    return paramStr;
  }
  for (auto i = 0; i < paramType.size() - 1; i++) {
    paramStr += paramType[i]->toCppStr() + " " + paramIds[i]->dump() + ", ";
  }
  paramStr += paramType.back()->toCppStr() + " " + paramIds.back()->dump();
  paramStr += ")";
  return paramStr;
}

std::string Function::getStmtStr(int level) const {
  std::string stmtStr;
  return stats.front()->output(level);
}

std::string Function::output(int level) const {
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
  // 1. get decl string
  std::string declStr = getDeclStr(level + 4);
  // 2. get param string
  std::string paramStr = getParamStr();
  // 3. get stmt string
  std::string stmtStr = getStmtStr(level + 8);
  char resStr[MAX_OUTPUT_LENGTH];
  sprintf(resStr, R"deli(
%*cclass %s {
%*cprivate:
%s
%*cpublic:
%*c   static void main%s {
%s%*c   }
%*c};
)deli",
          level, ' ', symPtr->dump().c_str(), level, ' ', declStr.c_str(),
          level, ' ', level, ' ', paramStr.c_str(), stmtStr.c_str(), level, ' ',
          level, ' ');
  return std::string(resStr);
}