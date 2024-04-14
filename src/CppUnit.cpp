#include "CppUnit.h"

extern FILE *yyout;

void CppUnit::output() const {
  AdaInteger::getInstance().output();
  for (auto &func : funcList) {
    std::string temp = func->output(0);
    fprintf(yyout, "%s", temp.c_str());
  }
  for (auto item : opList) {
    Function *func = item.first;
    std::vector<Operand *> *vec = item.second;
    for (auto op : *vec) {
      // Simple Operand Name
      std::string opName = func->getName() + "::" + op->getName();
      CppExpr *init = op->getCppExpr();
      if (init) {
        fprintf(yyout, "%s %s = %s;\n", op->typeName().c_str(), opName.c_str(),
                op->getCppExpr()->output().c_str());
      } else {
        fprintf(yyout, "%s %s = 0;\n", op->typeName().c_str(), opName.c_str());
      }
    }
  }
}