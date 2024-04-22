#include "Ast.h"
#include <cassert>

#define DEBUG_SWITCH_AST_LOG 0
#if DEBUG_SWITCH_AST_LOG
#define printAstLog(str) std::cerr << "[AST INFO]:" << str << "\n";
#else
#define printAstLog(str) //
#endif

extern FILE *yyout;
int Node::counter = 0;
CppBuilder *Node::builder = nullptr;
std::stack<LoopStmt *> loopIter;

Node::Node() { seq = counter++; }

void Node::setNext(Node *node) {
  Node *n = this;
  while (n->getNext()) {
    n = n->getNext();
  }
  if (n == this) {
    this->next = node;
  } else {
    n->setNext(node);
  }
}

void StmtNode::setNext(StmtNode *node) {
  StmtNode *n = this;
  while (n->getNext()) {
    n = n->getNext();
  }
  if (n == this) {
    this->next = node;
  } else {
    n->setNext(node);
  }
}

void OpSignNode::dump(int level) {
  std::string opSignName;
  switch (kind) {
  case OpSignNode::REVERSE:
    opSignName = "reverse";
    break;
  case OpSignNode::MUL:
    opSignName = "*";
    break;
  case OpSignNode::DIV:
    opSignName = "/";
    break;
  case OpSignNode::MOD:
    opSignName = "mod";
    break;
  case OpSignNode::REM:
    opSignName = "rem";
    break;
  case OpSignNode::ADD:
    opSignName = "+";
    break;
  case OpSignNode::SUB:
    opSignName = "-";
    break;
  case OpSignNode::SINGLEAND:
    opSignName = "&";
    break;
  case OpSignNode::IN:
    opSignName = "in";
    break;
  case OpSignNode::NOTIN:
    opSignName = "not in";
    break;
  case OpSignNode::EQ:
    opSignName = "=";
    break;
  case OpSignNode::NE:
    opSignName = "/=";
    break;
  case OpSignNode::LE:
    opSignName = "<";
    break;
  case OpSignNode::LTEQ:
    opSignName = "<=";
    break;
  case OpSignNode::GE:
    opSignName = ">";
    break;
  case OpSignNode::GTEQ:
    opSignName = ">=";
    break;
  case OpSignNode::ANDTHEN:
    opSignName = "and then";
    break;
  case OpSignNode::ORELSE:
    opSignName = "or else";
    break;
  case OpSignNode::AND:
    opSignName = "and";
    break;
  case OpSignNode::OR:
    opSignName = "or";
    break;
  case OpSignNode::XOR:
    opSignName = "xor";
    break;
  default:
    break;
  }
  fprintf(yyout, "%*cOpSign: %s\n", level, ' ', opSignName.c_str());
}

void OpSignNode::genCppCode(Node *parent) {}

void Id::dump(int level) {
  fprintf(yyout, "%*cId\n", level, ' ');
  if (name) {
    name->dump(level + 4);
    if (expr) {
      fprintf(yyout, "%*cName PAREN Value\n", level + 4, ' ');
      ExprNode *temp = expr;
      while (temp) {
        temp->dump(level + 8);
        temp = dynamic_cast<ExprNode *>(temp->getNext());
      }
    } else {
      fprintf(yyout, "%*cAttributeId: %s\n", level + 8, ' ', attr.c_str());
    }
  } else {
    std::string name, type;
    int scope;
    name = se->dump();
    type = se->getType()->dump();
    scope = dynamic_cast<IdentifierSymbolEntry *>(se)->getScope();
    fprintf(yyout, "%*cname: %s\tscope: %d\ttype: %s\n", level + 4, ' ',
            name.c_str(), scope, type.c_str());
  }
}

void Id::genCppCode(Node *parent) {
  if (name) {
    name->genCppCode(parent);
    CppId *id = dynamic_cast<CppId *>(name->getCppExpr());
    if (expr) {
      expr->genCppCode(parent);
      CppExpr *paramExpr = expr->getCppExpr();
      ExprNode *temp = dynamic_cast<ExprNode *>(expr->getNext());
      while (temp) {
        temp->genCppCode(parent);
        cExpr->setNext(temp->getCppExpr());
        temp = dynamic_cast<ExprNode *>(temp->getNext());
      }
      cExpr = new CppId(id, paramExpr);
    } else {
      cExpr = new CppId(id, attr);
    }
  } else {
    // for simple id
    cExpr = new CppId(se);
  }
}

void Constant::dump(int level) {
  printAstLog("Literal dump");
  std::string type, value;
  type = se->getType()->dump();
  value = se->dump();
  fprintf(yyout, "%*cLiteral\ttype: %s\tvalue: %s\n", level, ' ', type.c_str(),
          value.c_str());
}

void Constant::genCppCode(Node *parent) { cExpr = new CppConstant(se); }

void FactorExpr::dump(int level) {
  std::string opName;
  switch (op) {
  case FactorExpr::NOT:
    opName = "not";
    break;
  case FactorExpr::ABS:
    opName = "abs";
    break;
  default:
    break;
  }
  fprintf(yyout, "%*cFactorExpr\top: %s\n", level, ' ', opName.c_str());
  expr->dump(level + 4);
}

void FactorExpr::genCppCode(Node *parent) {
  expr->genCppCode(parent);
  cExpr = new CppFactor(expr->getCppExpr(), op);
}

void BinaryExpr::dump(int level) {
  fprintf(yyout, "%*cBinaryExpr\n", level, ' ');
  sign->dump(level + 4);
  expr1->dump(level + 8);
  if (isUnary) {
    return;
  } else if (isMember) {
    if (range)
      range->dump(level + 8);
    if (se)
      se->dump();
  } else {
    expr2->dump(level + 8);
  }
}

void BinaryExpr::genCppCode(Node *parent) {
  int cppOp;
  switch (sign->getKind()) {
  case OpSignNode::MUL:
    cppOp = CppBinaryExpr::MUL;
    break;
  case OpSignNode::DIV:
    cppOp = CppBinaryExpr::DIV;
    break;
  case OpSignNode::MOD:
    cppOp = CppBinaryExpr::MOD;
    break;
  case OpSignNode::REM:
    cppOp = CppBinaryExpr::REM;
    break;
  case OpSignNode::ADD:
    cppOp = CppBinaryExpr::ADD;
    break;
  case OpSignNode::SUB:
    cppOp = CppBinaryExpr::SUB;
    break;
  case OpSignNode::SINGLEAND:
    cppOp = CppBinaryExpr::SINGLEAND;
    break;
  case OpSignNode::IN:
    cppOp = CppBinaryExpr::IN;
    break;
  case OpSignNode::NOTIN:
    cppOp = CppBinaryExpr::NOTIN;
    break;
  case OpSignNode::EQ:
    cppOp = CppBinaryExpr::EQ;
    break;
  case OpSignNode::NE:
    cppOp = CppBinaryExpr::NE;
    break;
  case OpSignNode::LE:
    cppOp = CppBinaryExpr::LE;
    break;
  case OpSignNode::LTEQ:
    cppOp = CppBinaryExpr::LTEQ;
    break;
  case OpSignNode::GE:
    cppOp = CppBinaryExpr::GE;
    break;
  case OpSignNode::GTEQ:
    cppOp = CppBinaryExpr::GTEQ;
    break;
  case OpSignNode::ANDTHEN:
    cppOp = CppBinaryExpr::ANDTHEN;
    break;
  case OpSignNode::ORELSE:
    cppOp = CppBinaryExpr::ORELSE;
    break;
  case OpSignNode::AND:
    cppOp = CppBinaryExpr::AND;
    break;
  case OpSignNode::OR:
    cppOp = CppBinaryExpr::OR;
    break;
  case OpSignNode::XOR:
    cppOp = CppBinaryExpr::XOR;
    break;
  case OpSignNode::EXPON:
    cppOp = CppBinaryExpr::EXPON;
    break;
  default:
    break;
  }
  if (isUnary) {
    expr1->genCppCode(parent);
    cExpr = new CppBinaryExpr(expr1->getCppExpr(), cppOp);
  } else if (isMember) {
    if (range) {
      expr1->genCppCode(parent);
      range->genCppCode(parent);
      cExpr = new CppBinaryExpr(expr1->getCppExpr(),
                                dynamic_cast<CppRange *>(range->getCppStmt()),
                                cppOp);
    }
    if (se) {
      expr1->genCppCode(parent);
      cExpr = new CppBinaryExpr(expr1->getCppExpr(), se, cppOp);
    }
  } else {
    expr1->genCppCode(parent);
    expr2->genCppCode(parent);
    cExpr = new CppBinaryExpr(expr1->getCppExpr(), expr2->getCppExpr(), cppOp);
  }
}

void SeqNode::dump(int level) {
  stmt1->dump(level);
  stmt2->dump(level);
}

void SeqNode::genCppCode(Node *parent) {
  stmt1->genCppCode(parent);
  stmt2->genCppCode(parent);
}

void DefId::dump(int level) {
  std::string name, type;
  name = id->dump();
  type = id->getType()->dump();
  std::string isConst = "false";
  if(id->getConst()) {
    isConst = "true";
  }
  fprintf(yyout, "%*cDefId\tname: %s\ttype: %s\tisConst: %s\n", level, ' ', name.c_str(),
          type.c_str(), isConst.c_str());
  if (this->getNext())
    this->getNext()->dump(level);
}

void DefId::genCppCode(Node *parent) {}

void InitOptStmt::dump(int level) {
  fprintf(yyout, "%*cInitOptStmt\n", level, ' ');
  expr->dump(level + 4);
}

void InitOptStmt::genCppCode(Node *parent) { expr->genCppCode(parent); }

void ParamNode::dump(int level) {
  std::string name, type;
  name = se->dump();
  type = se->getType()->dump();
  fprintf(yyout, "%*cParam\tname: %s\ttype: %s\n", level, ' ', name.c_str(),
          type.c_str());
  if (init)
    init->dump(level + 4);
  if (this->getNext())
    this->getNext()->dump(level);
}

void ParamNode::genCppCode(Node *parent) {}

void ProcedureSpec::dump(int level) {
  printAstLog("ProcedureSpec dump");
  std::string name, type;
  name = se->dump();
  type = se->getType()->dump();
  fprintf(yyout, "%*cProcedure\tname: %s\ttype: %s\n", level, ' ', name.c_str(),
          type.c_str());
  if (params)
    params->dump(level + 4);
}

void ProcedureSpec::genCppCode(Node *parent) {}

void ProcedureDecl::dump(int level) {
  fprintf(yyout, "%*cProcedureDecl\n", level, ' ');
  spec->dump(level + 4);
}

void ProcedureDecl::genCppCode(Node *parent) {
  Function *curFunc = builder->getCurrFunc();
  cStmt = new CppFuncDecl(curFunc, getProcedureSymbol());
}

void ObjectDeclStmt::dump(int level) {
  printAstLog("ObjectDeclStmt dump");
  fprintf(yyout, "%*cObjectDeclStmt\n", level, ' ');
  id->dump(level + 4);
  if (init)
    init->dump(level + 4);
}

void ObjectDeclStmt::genCppCode(Node *parent) {
  if (dynamic_cast<ProcedureDef *>(parent)) {
    Function *func = builder->getCurrFunc();
    CppUnit *unit = builder->getUnit();
    // Init Var
    CppExpr *initExpr = nullptr;
    if (init) {
      init->genCppCode(parent);
      initExpr = init->getCppExpr();
    }
    // Declared objects
    DefId *temp = id;
    while (temp) {
      Operand *op =
          new Operand(temp->getSymbolEntry(), temp->getType(), initExpr);
      func->addDeclOps(op);
      unit->insertOp(func, op);
      temp = dynamic_cast<DefId *>(temp->getNext());
    }
  } else {
    // declarations in main function
    CppBlockStmt *block = dynamic_cast<CppBlockStmt *>(
        dynamic_cast<StmtNode *>(parent)->getCppStmt());
    CppExpr *initExpr = nullptr;
    if (init) {
      init->genCppCode(parent);
      initExpr = init->getCppExpr();
    }
    // Declared objects
    DefId *temp = id;
    while (temp) {
      Operand *op =
          new Operand(temp->getSymbolEntry(), temp->getType(), temp->getConst() ,initExpr);
      block->addOps(op);
      temp = dynamic_cast<DefId *>(temp->getNext());
    }
  }
}

void DeclStmt::dump(int level) {
  fprintf(yyout, "%*cDeclStmt\n", level, ' ');
  if (objectDecl)
    objectDecl->dump(level + 4);
  if (procedureDecl)
    procedureDecl->dump(level + 4);
}

void DeclStmt::genCppCode(Node *parent) {
  if (objectDecl) {
    objectDecl->genCppCode(parent);
    cStmt = objectDecl->getCppStmt();
  }
  if (procedureDecl) {
    procedureDecl->genCppCode(parent);
    cStmt = procedureDecl->getCppStmt();
  }
}

void DeclItemOrBodyStmt::dump(int level) {
  fprintf(yyout, "%*cDeclItemOrBodyStmt\n", level, ' ');
  if (decl)
    decl->dump(level + 4);
  if (prof)
    prof->dump(level + 4);
  if (this->getNext())
    this->getNext()->dump(level);
}

void DeclItemOrBodyStmt::genCppCode(Node *parent) {
  if (decl) {
    decl->genCppCode(parent);
    cStmt = decl->getCppStmt();
  }
  if (prof) {
    prof->genCppCode(parent);
  }
  if (this->getNext())
    this->getNext()->genCppCode(parent);
}

void NullStmt::dump(int level) { fprintf(yyout, "%*cNullStmt\n", level, ' '); }

void NullStmt::genCppCode(Node *parent) {
  if (dynamic_cast<ProcedureDef *>(parent)) {
    Function *curFunc = builder->getCurrFunc();
    cStmt = new CppDummyStmt(curFunc);
  } else {
    cStmt = new CppDummyStmt();
  }
}

void AssignStmt::dump(int level) {
  printAstLog("AssignStmt dump");
  std::string name, type;
  name = se->dump();
  type = se->getType()->dump();
  fprintf(yyout, "%*cAssignStmt\tname: %s\ttype: %s\n", level, ' ',
          name.c_str(), type.c_str());
  expr->dump(level + 4);
}

void AssignStmt::genCppCode(Node *parent) {
  expr->genCppCode(parent);
  if (dynamic_cast<ProcedureDef *>(parent)) {
    Function *func = builder->getCurrFunc();
    cStmt = new CppAssignStmt(func, se, expr->getCppExpr());
  } else {
    cStmt = new CppAssignStmt(nullptr, se, expr->getCppExpr());
  }
}

void ReturnStmt::dump(int level) {
  fprintf(yyout, "%*cReturnStmt\n", level, ' ');
  if (retValue)
    retValue->dump(level + 4);
  else
    fprintf(yyout, "%*cvoid\n", level + 4, ' ');
}

void ReturnStmt::genCppCode(Node *parent) {}

void CallStmt::dump(int level) {
  fprintf(yyout, "%*cCallStmt\n", level, ' ');
  id->dump(level + 4);
}

void CallStmt::genCppCode(Node *parent) {
  id->genCppCode(parent);
  CppId *cId = dynamic_cast<CppId *>(id->getCppExpr());
  if (dynamic_cast<ProcedureDef *>(parent)) {
    Function *curFunc = builder->getCurrFunc();
    cStmt = new CppCallStmt(curFunc, cId);
  } else {
    cStmt = new CppCallStmt(nullptr, cId);
  }
}

void Stmt::dump(int level) {
  fprintf(yyout, "%*cStmt\n", level, ' ');
  if (stmt)
    stmt->dump(level + 4);
  if (this->getNext())
    this->getNext()->dump(level);
}

void Stmt::genCppCode(Node *parent) {
  stmt->genCppCode(this);
  if (dynamic_cast<ProcedureDef *>(parent)) {
    Function *curFunc = builder->getCurrFunc();
    cStmt = new CppSeqStmt(curFunc, stmt->getCppStmt());
  } else {
    cStmt = new CppSeqStmt(nullptr, stmt->getCppStmt());
  }
  if (this->getNext()) {
    this->getNext()->genCppCode(this);
    cStmt->setNext(this->getNext()->getCppStmt());
  }
}

void ProcedureDef::dump(int level) {
  printAstLog("ProcedureDef dump");
  fprintf(yyout, "%*cProcedureDef\n", level, ' ');
  spec->dump(level + 4);
  if (items)
    items->dump(level + 4);
  if (stmts)
    stmts->dump(level + 4);
}

void ProcedureDef::genCppCode(Node *parent) {
  SymbolEntry *se = spec->getProcedureSymbol();
  CppUnit *unit = builder->getUnit();
  Function *curFunc;
  if (prev) {
    SymbolEntry *prevSe = prev->getProcedureSymbol();
    // Fix: subsubfunction can't get subfunction
    Function *prevFunc = unit->getFunction(prevSe);
    curFunc = new Function(prevFunc, se);
  } else {
    curFunc = new Function(unit, se);
  }
  builder->setCurrFunc(curFunc);
  spec->genCppCode(this);
  if (items)
    items->genCppCode(this);
  if (stmts)
    stmts->genCppCode(this);
  builder->removeCurrFunc();
}

void CondClause::dump(int level) {
  fprintf(yyout, "%*cCondClause\n", level, ' ');
  cond->dump(level + 4);
  stmts->dump(level + 4);
  if (this->getNext())
    this->getNext()->dump(level);
}

void CondClause::genCppCode(Node *parent) {
  cond->genCppCode(parent);
  stmts->genCppCode(this);
  cStmt = new CppCondClause(nullptr, cond->getCppExpr(),
                            dynamic_cast<CppSeqStmt *>(stmts->getCppStmt()));
  if (this->getNext()) {
    this->getNext()->genCppCode(this);
    cStmt->setNext(this->getNext()->getCppStmt());
  }
}

void IfStmt::dump(int level) {
  fprintf(yyout, "%*cIfStmt\n", level, ' ');
  clause->dump(level + 4);
  if (elsestmt) {
    fprintf(yyout, "%*cElse\n", level + 4, ' ');
    elsestmt->dump(level + 8);
  }
}

void IfStmt::genCppCode(Node *parent) {
  clause->genCppCode(this);
  CppCondClause *cClause = dynamic_cast<CppCondClause *>(clause->getCppStmt());
  CppSeqStmt *cElseStmt = nullptr;
  if (elsestmt) {
    elsestmt->genCppCode(this);
    cElseStmt = dynamic_cast<CppSeqStmt *>(elsestmt->getCppStmt());
  }
  if (dynamic_cast<ProcedureDef *>(parent)) {
    Function *curFunc = builder->getCurrFunc();
    cStmt = new CppIfStmt(curFunc, cClause, cElseStmt);
  } else {
    cStmt = new CppIfStmt(nullptr, cClause, cElseStmt);
  }
}

void Range::dump(int level) {
  fprintf(yyout, "%*cRange\n", level, ' ');
  lowerbound->dump(level + 4);
  upperbound->dump(level + 4);
}

void Range::genCppCode(Node *parent) {
  lowerbound->genCppCode(parent);
  upperbound->genCppCode(parent);
  cStmt = new CppRange(lowerbound->getCppExpr(), upperbound->getCppExpr());
}

void DiscreteRange::dump(int level) {
  if (se) {
    std::string name, type;
    name = se->dump();
    type = se->getType()->dump();
    fprintf(yyout, "%*cDiscreteRange\tname: %s\ttype: %s\n", level, ' ',
            name.c_str(), type.c_str());
    if (range)
      range->dump(level + 4);
  } else {
    fprintf(yyout, "%*cDiscreteRange\n", level, ' ');
    range->dump(level + 4);
  }
}

void DiscreteRange::genCppCode(Node *parent) {
  range->genCppCode(parent);
  cStmt = range->getCppStmt();
}

void Choice::dump(int level) {
  fprintf(yyout, "%*cChoice\n", level, ' ');
  if (expr)
    expr->dump(level + 4);
  if (discret)
    discret->dump(level + 4);
  if (others) {
    fprintf(yyout, "%*cothers\n", level + 4, ' ');
  }
  if (this->getNext()) {
    fprintf(yyout, "%*cOR\n", level, ' ');
    this->getNext()->dump(level);
  }
}

void Choice::genCppCode(Node *parent) {
  if (expr) {
    expr->genCppCode(parent);
    cStmt = new CppChoice(dynamic_cast<CppExpr *>(expr->getCppExpr()));
  }
  if (discret) {
    discret->genCppCode(parent);
    cStmt = new CppChoice(dynamic_cast<CppRange *>(discret->getCppStmt()));
  }
  if (others) {
    cStmt = new CppChoice(true);
  }
  if (this->getNext()) {
    this->getNext()->genCppCode(parent);
    cStmt->setNext(this->getNext()->getCppStmt());
  }
}

void Alternative::dump(int level) {
  fprintf(yyout, "%*cAlternative\n", level, ' ');
  choices->dump(level + 4);
  stmts->dump(level + 4);
  if (this->getNext())
    this->getNext()->dump(level);
}

void Alternative::genCppCode(Node *parent) {
  choices->genCppCode(parent);
  stmts->genCppCode(parent);
  cStmt = new CppAlternative(dynamic_cast<CppChoice *>(choices->getCppStmt()),
                             dynamic_cast<CppSeqStmt *>(stmts->getCppStmt()));
  if (this->getNext()) {
    this->getNext()->genCppCode(parent);
    cStmt->setNext(this->getNext()->getCppStmt());
  }
}

void CaseStmt::dump(int level) {
  fprintf(yyout, "%*cCaseStmt\n", level, ' ');
  expr->dump(level + 4);
  if (alter)
    alter->dump(level + 4);
}

void CaseStmt::genCppCode(Node *parent) {
  expr->genCppCode(parent);
  alter->genCppCode(parent);
  if (dynamic_cast<ProcedureDef *>(parent)) {
    Function *curFunc = builder->getCurrFunc();
    cStmt =
        new CppCaseStmt(curFunc, expr->getCppExpr(),
                        dynamic_cast<CppAlternative *>(alter->getCppStmt()));
  } else {
    cStmt =
        new CppCaseStmt(nullptr, expr->getCppExpr(),
                        dynamic_cast<CppAlternative *>(alter->getCppStmt()));
  }
}

void ExitStmt::dump(int level) {
  fprintf(yyout, "%*cExitStmt\n", level, ' ');
  if (cond)
    cond->dump(level + 4);
}

void ExitStmt::genCppCode(Node *parent) {
  if (cond) {
    cond->genCppCode(parent);
    cStmt = new CppExitStmt(cond->getCppExpr());
  } else {
    cStmt = new CppExitStmt();
  }
}

void BasicLoopStmt::dump(int level) {
  fprintf(yyout, "%*cBasicLoopStmt\n", level, ' ');
  stmts->dump(level + 4);
}

void BasicLoopStmt::genCppCode(Node *parent) {
  stmts->genCppCode(parent);
  cStmt = stmts->getCppStmt();
}

void IterPart::dump(int level) {
  std::string name;
  name = se->dump();
  fprintf(yyout, "%*cIterPart\tname: %s\n", level, ' ', name.c_str());
}

void IterPart::genCppCode(Node *parent) {}

void Iteration::dump(int level) {
  fprintf(yyout, "%*cIteration\n", level, ' ');
  if (cond) {
    cond->dump(level + 4);
  } else {
    iter->dump(level + 4);
    if (sign)
      sign->dump(level + 4);
    range->dump(level + 4);
  }
}

void Iteration::genCppCode(Node *parent) {
  if (iter) {
    iter->genCppCode(parent);
    range->genCppCode(parent);
    bool reverse = false;
    if (sign)
      reverse = true;
    cStmt = new CppIteration(iter->getSymbol(),
                             dynamic_cast<CppRange *>(range->getCppStmt()),
                             reverse);
  } else {
    cond->genCppCode(parent);
    cStmt = new CppIteration(cond->getCppExpr());
  }
}

void LabelOpt::dump(int level) {
  std::string name;
  name = se->dump();
  fprintf(yyout, "%*cIterPart\tname: %s\n", level, ' ', name.c_str());
}

void LabelOpt::genCppCode(Node *parent) {}

void LoopStmt::dump(int level) {
  fprintf(yyout, "%*cLoopStmt\n", level, ' ');
  if (label)
    label->dump(level + 4);
  if (iter)
    iter->dump(level + 4);
  loop->dump(level + 4);
}

void LoopStmt::genCppCode(Node *parent) {
  loopIter.push(this);
  CppIteration *cIter = nullptr;
  if (iter) {
    iter->genCppCode(this);
    cIter = dynamic_cast<CppIteration *>(iter->getCppStmt());
  }
  loop->genCppCode(this);

  if (dynamic_cast<ProcedureDef *>(parent)) {
    Function *curFunc = builder->getCurrFunc();
    cStmt = new CppLoopStmt(curFunc, cIter,
                            dynamic_cast<CppSeqStmt *>(loop->getCppStmt()));
  } else {
    cStmt = new CppLoopStmt(nullptr, cIter,
                            dynamic_cast<CppSeqStmt *>(loop->getCppStmt()));
  }
  loopIter.pop();
}

void Block::dump(int level) {
  fprintf(yyout, "%*cBlockStmt\n", level, ' ');
  if (label)
    label->dump(level + 4);
  decl->dump(level + 4);
  stmts->dump(level + 4);
}

void Block::genCppCode(Node *parent) {
  stmts->genCppCode(this);
  if (dynamic_cast<ProcedureDef *>(parent)) {
    Function *func = builder->getCurrFunc();
    cStmt =
        new CppBlockStmt(func, dynamic_cast<CppSeqStmt *>(stmts->getCppStmt()));
  } else {
    cStmt = new CppBlockStmt(nullptr,
                             dynamic_cast<CppSeqStmt *>(stmts->getCppStmt()));
  }
  decl->genCppCode(this);
}

void Ast::dump() {
  printAstLog("Program dump");
  fprintf(yyout, "program\n");
  if (root != nullptr)
    root->dump(4);
}

void Ast::genCppCode(CppUnit *unit) {
  CppBuilder *builder = new CppBuilder(unit);
  Node::setCppBuilder(builder);
  root->genCppCode(nullptr);
}