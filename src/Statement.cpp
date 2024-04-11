#include "Statement.h"

extern FILE *yyout;
int CppNode::counter = 0;

CppNode::CppNode() { seq = counter++; }

void CppNode::setNext(CppNode *node) {
  CppNode *n = this;
  while (n->getNext()) {
    n = n->getNext();
  }
  if (n == this) {
    this->next = node;
  } else {
    n->setNext(node);
  }
}

void CppId::output(int level) const {
  fprintf(yyout, "%s", se->dump().c_str());
}

void CppConstant::output(int level) const {
  fprintf(yyout, "%s", se->dump().c_str());
}

void CppFactor::output(int level) const {
  std::string opMethod;
  switch (op)
  {
  case CppFactor::NOT:
    opMethod = "!";
    break;
  case CppFactor::ABS:
    opMethod = "";
  }
  fprintf(yyout, "%*c%s", level, ' ', opMethod.c_str());
  cExpr->output(level + opMethod.size());
}

void CppBinaryExpr::output(int level) const {
  
}
