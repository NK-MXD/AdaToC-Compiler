#include "Statement.h"
#include "Function.h"

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

CppStmt::CppStmt(Function *func) {
  if (func)
    func->insertStmts(this);
}

std::string CppId::output() const { return se->dump(); }

std::string CppConstant::output() const { return se->dump(); }

std::string CppFactor::output() const {
  std::string opMethod;
  switch (op) {
  case CppFactor::NOT:
    opMethod = "!";
    break;
  case CppFactor::ABS:
    opMethod = "";
  }
  return opMethod + cExpr->output();
}

std::string CppBinaryExpr::output() const {
  // For some operator, we can use them in Cpp directly.
  // But others we should define method to implement them.
  std::string opSignName;
  switch (sign) {
  case CppBinaryExpr::MUL:
    opSignName = " * ";
    break;
  case CppBinaryExpr::DIV:
    opSignName = " / ";
    break;
  case CppBinaryExpr::MOD:
    opSignName = " % ";
    break;
  case CppBinaryExpr::REM:
    opSignName = " rem ";
    break;
  case CppBinaryExpr::ADD:
    opSignName = " + ";
    break;
  case CppBinaryExpr::SUB:
    opSignName = " - ";
    break;
  case CppBinaryExpr::SINGLEAND:
    opSignName = " & ";
    break;
  case CppBinaryExpr::IN:
    opSignName = " in ";
    break;
  case CppBinaryExpr::NOTIN:
    opSignName = " not in ";
    break;
  case CppBinaryExpr::EQ:
    opSignName = " = ";
    break;
  case CppBinaryExpr::NE:
    opSignName = " != ";
    break;
  case CppBinaryExpr::LE:
    opSignName = " < ";
    break;
  case CppBinaryExpr::LTEQ:
    opSignName = " <= ";
    break;
  case CppBinaryExpr::GE:
    opSignName = " > ";
    break;
  case CppBinaryExpr::GTEQ:
    opSignName = " >= ";
    break;
  case CppBinaryExpr::ANDTHEN:
    opSignName = " and then ";
    break;
  case CppBinaryExpr::ORELSE:
    opSignName = " or else ";
    break;
  case CppBinaryExpr::AND:
    opSignName = " && ";
    break;
  case CppBinaryExpr::OR:
    opSignName = " || ";
    break;
  case CppBinaryExpr::XOR:
    opSignName = " xor ";
    break;
  default:
    break;
  }
  if (cExpr2 != nullptr) {
    return cExpr1->output() + opSignName + cExpr2->output();
  } else if(se) {
    return cExpr1->output() + opSignName + se->dump();
  } else {
    return opSignName + cExpr1->output();
  }
}

std::string CppDummyStmt::output(int level) const {
  char temp[80];
  sprintf(temp, "%*c;\n", level, ' ');
  return std::string(temp);
}

std::string CppAssignStmt::output(int level) const {
  char temp[200];
  sprintf(temp, "%*c%s = %s;\n", level, ' ', se->dump().c_str(),
          cExpr->output().c_str());
  return std::string(temp);
}

std::string CppCallStmt::output(int level) const {
  char temp[200];
  sprintf(temp, "%*c%s::main();\n", level, ' ', cId->output().c_str());
  return std::string(temp);
}

std::string CppCondClause::output(int level) const {
  std::string stmtStr = stmts->output(level + 4);
  char res[400];
  sprintf(res, R"deli(%*cif(%s) {
%s
%*c}
)deli",
          level, ' ', cond->output().c_str(), stmtStr.c_str(), level, ' ');
  CppCondClause *elseIf = dynamic_cast<CppCondClause *>(this->getNext());
  while (elseIf) {
    char temp[200];
    std::string elseIfStmtStr = elseIf->getStmts()->output(level + 4);
    sprintf(res, R"deli(%*celse if(%s) {
%s
%*c}
)deli",
            level, ' ', elseIf->getCond()->output().c_str(),
            elseIfStmtStr.c_str(), level, ' ');
    strcat(res, temp);
    elseIf = dynamic_cast<CppCondClause *>(elseIf->getNext());
  }
  return std::string(res);
}

std::string CppIfStmt::output(int level) const {
  char res[500];
  if (elsestmt) {
    std::string elseStr = elsestmt->output(level + 4);
    sprintf(res, R"deli(%s
%*celse {
%s
%*c}
)deli",
            clause->output(level).c_str(), level, ' ', elseStr.c_str(), level,
            ' ');
    return std::string(res);
  }
  return clause->output(level);
}