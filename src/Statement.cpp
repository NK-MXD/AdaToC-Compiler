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

void CppStmt::setNext(CppStmt *node) {
  CppStmt *n = this;
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
  if (func) {
    func->insertStmts(this);
  }
}

std::string CppId::output() const {
  if (name) {
    if (expr) {
      std::string paramStr;
      CppExpr *temp = expr;
      paramStr += temp->output();
      if (temp->getNext()) {
        paramStr += ", ";
        temp = dynamic_cast<CppExpr *>(temp->getNext());
      }
      char res[50];
      sprintf(res, "%s(%s)", name->output().c_str(), paramStr.c_str());
      return std::string(res);
    } else {
      char res[50];
      std::string className = name->output();
      if (name->output() == "Integer") {
        className = "AdaInteger";
      }
      sprintf(res, "%s::%s", className.c_str(), attr.c_str());
      return std::string(res);
    }
  } else {
    if (se->getType()->isProcedure()) {
      return se->dump() + "::main";
    } else {
      return se->dump();
    }
  }
}

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
    opSignName = "*";
    break;
  case CppBinaryExpr::DIV:
    opSignName = "/";
    break;
  case CppBinaryExpr::MOD:
    opSignName = "%";
    break;
  case CppBinaryExpr::REM:
    // Fix: add rules of it
    opSignName = "rem";
    break;
  case CppBinaryExpr::ADD:
    opSignName = "+";
    break;
  case CppBinaryExpr::SUB:
    opSignName = "-";
    break;
  case CppBinaryExpr::SINGLEAND:
    // HL: maybe string
    opSignName = "+";
    break;
    //   case CppBinaryExpr::IN:
    //     opSignName = "in";
    //     break;
    //   case CppBinaryExpr::NOTIN:
    //     opSignName = "not in";
    //     break;
  case CppBinaryExpr::EQ:
    opSignName = "==";
    break;
  case CppBinaryExpr::NE:
    opSignName = "!=";
    break;
  case CppBinaryExpr::LE:
    opSignName = "<";
    break;
  case CppBinaryExpr::LTEQ:
    opSignName = "<=";
    break;
  case CppBinaryExpr::GE:
    opSignName = ">";
    break;
  case CppBinaryExpr::GTEQ:
    opSignName = ">=";
    break;
  case CppBinaryExpr::ANDTHEN:
    // Fix: add rules of it
    opSignName = "and then";
    break;
  case CppBinaryExpr::ORELSE:
    // Fix: add rules of it
    opSignName = "or else";
    break;
  case CppBinaryExpr::AND:
    opSignName = "&&";
    break;
  case CppBinaryExpr::OR:
    opSignName = "||";
    break;
  case CppBinaryExpr::XOR:
    // Fix: add rules of it
    opSignName = "xor";
    break;
  default:
    break;
  }

  char temp[80];
  if (isUnary) {
    sprintf(temp, "%s%s", opSignName.c_str(), cExpr1->output().c_str());
    return std::string(temp);
  } else if (isMember) {
    if (se) {
      if (sign == CppBinaryExpr::IN) {
        // Fix: need to add rules
        /*
        ValidDigits : constant DigitSet := (1, 3, 5, 7, 9);
        if A in ValidDigits:
        */
      } else if (sign == CppBinaryExpr::NOTIN) {
        // Fix: need to add rules
      } else {
        sprintf(temp, "%s %s %s", cExpr1->output().c_str(), opSignName.c_str(),
                se->dump().c_str());
      }
    }
    if (cRange) {
      CppExpr *low = cRange->getLow();
      CppExpr *upper = cRange->getUpper();
      if (sign == CppBinaryExpr::IN) {
        sprintf(temp, "%s >= %s && %s <= %s", cExpr1->output().c_str(),
                low->output().c_str(), cExpr1->output().c_str(),
                upper->output().c_str());
      } else if (sign == CppBinaryExpr::NOTIN) {
        sprintf(temp, "%s < %s || %s > %s", cExpr1->output().c_str(),
                low->output().c_str(), cExpr1->output().c_str(),
                upper->output().c_str());
      } else {
        std::cerr << "[CPPBINARY OUTPUT ERROR] Not match sign of Range!\n";
        return std::string();
      }
    }
    return std::string(temp);
  } else {
    sprintf(temp, "%s %s %s", cExpr1->output().c_str(), opSignName.c_str(),
            cExpr2->output().c_str());
    return std::string(temp);
  }
}

std::string CppSeqStmt::output(int level) const {
  std::string res = stmt->output(level);
  if (this->getNext()) {
    res += this->getNext()->output(level);
  }
  return res;
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
  std::string paramStr;
  if (!cId->getParam()) {
    paramStr = "()";
  }
  sprintf(temp, "%*c%s%s;\n", level, ' ', cId->output().c_str(),
          paramStr.c_str());
  return std::string(temp);
}

std::string CppCondClause::output(int level) const {
  std::string stmtStr = stmts->output(level + 4);
  std::string resStr;
  char res[200];
  sprintf(res, R"deli(%*cif(%s) {
%s%*c}
)deli",
          level, ' ', cond->output().c_str(), stmtStr.c_str(), level, ' ');
  CppCondClause *elseIf = dynamic_cast<CppCondClause *>(this->getNext());
  resStr += std::string(res);
  while (elseIf) {
    char temp[200];
    std::string elseIfStmtStr = elseIf->getStmts()->output(level + 4);
    sprintf(temp, R"deli(%*celse if(%s) {
%s%*c}
)deli",
            level, ' ', elseIf->getCond()->output().c_str(),
            elseIfStmtStr.c_str(), level, ' ');
    elseIf = dynamic_cast<CppCondClause *>(elseIf->getNext());
    resStr += std::string(temp);
  }
  return resStr;
}

std::string CppIfStmt::output(int level) const {
  char res[2000];
  if (elsestmt) {
    std::string elseStr = elsestmt->output(level + 4);
    sprintf(res, R"deli(%s%*celse {
%s%*c}
)deli",
            clause->output(level).c_str(), level, ' ', elseStr.c_str(), level,
            ' ');
    return std::string(res);
  }
  return clause->output(level);
}

std::string CppIteration::output(int level) const {
  char res[200];
  if (cond) {
    sprintf(res, "while(%s)", cond->output().c_str());
  } else {
    if (isReverse) {
      sprintf(res, "for(int %s = %s; %s >= %s; %s--)", se->dump().c_str(),
              range->getUpper()->output().c_str(), se->dump().c_str(),
              range->getLow()->output().c_str(), se->dump().c_str());
    } else {
      sprintf(res, "for(int %s = %s; %s <= %s; %s++)", se->dump().c_str(),
              range->getLow()->output().c_str(), se->dump().c_str(),
              range->getUpper()->output().c_str(), se->dump().c_str());
    }
  }
  return std::string(res);
}

std::string CppLoopStmt::output(int level) const {
  char res[4000];
  if (cIter) {
    sprintf(res, R"deli(%*c%s {
%s%*c}
)deli",
            level, ' ', cIter->output(level).c_str(),
            loop->output(level + 4).c_str(), level, ' ');
  } else {
    sprintf(res, R"deli(%*cwhile(true) {
%s%*c}
)deli",
            level, ' ', loop->output(level + 4).c_str(), level, ' ');
  }
  return std::string(res);
}

std::string CppCaseStmt::output(int level) const {
  std::string resStr;
  std::string exprStr = cExpr->output();
  bool haveElse = false;
  CppSeqStmt *elseStmts;
  CppAlternative *temp = alter;
  bool firstCase = true;
  while (temp) {
    char tempIf[300];
    CppChoice *choices = temp->getChoices();
    CppSeqStmt *stmts = temp->getStmts();
    std::string condStr;
    bool isFirst = true;
    while (choices) {
      char tempCond[50];
      if (choices->getIsExpr()) {
        sprintf(tempCond, "%s == %s", exprStr.c_str(),
                choices->getExpr()->output().c_str());
      } else if (choices->getIsRange()) {
        sprintf(tempCond, "%s >= %s && %s <= %s", exprStr.c_str(),
                choices->getRange()->getLow()->output().c_str(),
                exprStr.c_str(),
                choices->getRange()->getUpper()->output().c_str());
      } else {
        haveElse = true;
        elseStmts = stmts;
        break;
      }
      if (isFirst) {
        condStr += std::string(tempCond);
        isFirst = false;
      } else {
        condStr += std::string(" || ") + std::string(tempCond);
      }
      choices = dynamic_cast<CppChoice *>(choices->getNext());
    }
    if (condStr.empty())
      break;
    if (firstCase) {
      sprintf(tempIf, R"deli(%*cif(%s) {
%s%*c}
)deli",
              level, ' ', condStr.c_str(), stmts->output(level + 4).c_str(),
              level, ' ');
      firstCase = false;
      resStr += std::string(tempIf);
    } else {
      sprintf(tempIf, R"deli(%*celse if(%s) {
%s%*c}
)deli",
              level, ' ', condStr.c_str(), stmts->output(level + 4).c_str(),
              level, ' ');
      resStr += std::string(tempIf);
    }
    temp = dynamic_cast<CppAlternative *>(temp->getNext());
  }

  if (haveElse) {
    char tempElse[300];
    sprintf(tempElse, R"deli(%*celse{
%s%*c}
)deli",
            level, ' ', elseStmts->output(level + 4).c_str(), level, ' ');
    resStr += std::string(tempElse);
  }
  return resStr;
}

std::string CppExitStmt::output(int level) const {
  char res[200];
  if (cCond) {
    sprintf(res, R"deli(%*cif(%s) {
%*cbreak;
%*c}
)deli",
            level, ' ', cCond->output().c_str(), level + 4, ' ', level, ' ');
  } else {
    sprintf(res, "%*cbreak;\n", level, ' ');
  }
  return std::string(res);
}

std::string CppBlockStmt::output(int level) const {
  std::string res;
  for (auto op : declvec) {
    char temp[200];
    CppExpr *init = op->getInit();
    std::string typeName = op->typeName();
    if (op->getConst()) {
      typeName = "const " + typeName;
    }
    if (init)
      sprintf(temp, "%*c%s %s = %s;\n", level, ' ', typeName.c_str(),
              op->getName().c_str(), init->output().c_str());
    else
      sprintf(temp, "%*c%s %s;\n", level, ' ', typeName.c_str(),
              op->getName().c_str());
    res += temp;
  }
  res += stmts->output(level);
  return res;
}

CppFuncDecl::CppFuncDecl(Function *_func, SymbolEntry *_se) : CppStmt(nullptr) {
  se = _se;
  _func->insertDecls(this);
}

std::string CppFuncDecl::output(int level) const {
  char res[50];
  sprintf(res, "%*cclass %s;", level, ' ', se->dump().c_str());
  return std::string(res);
}