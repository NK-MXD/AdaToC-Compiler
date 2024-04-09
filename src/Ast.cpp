#include "Ast.h"
#include "CppBuilder.h"
#include "CppUnit.h"

#define DEBUG_SWITCH_AST_LOG 0
#if DEBUG_SWITCH_AST_LOG
#define printAstLog(str) std::cerr << "[AST INFO]:" << str << "\n";
#else
#define printAstLog(str) //
#endif

extern FILE *yyout;
int Node::counter = 0;
CppBuilder *Node::builder = nullptr;

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

void Ast::dump() {
  printAstLog("Program dump");
  fprintf(yyout, "program\n");
  if (root != nullptr)
    root->dump(4);
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

void OpSignNode::genCppCode() {}

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

void Id::genCppCode() {}

void Constant::dump(int level) {
  printAstLog("Literal dump");
  std::string type, value;
  type = se->getType()->dump();
  value = se->dump();
  fprintf(yyout, "%*cLiteral\ttype: %s\tvalue: %s\n", level, ' ', type.c_str(),
          value.c_str());
}

void Constant::genCppCode() {}

void FactorExpr::dump(int level) {
  std::string opName;
  switch (op) {
  case FactorExpr::NOT:
    opName = "not";
    break;
  case FactorExpr::ABS:
    opName = "abs";
    break;
  case FactorExpr::EXPON:
    opName = "expon";
    break;
  default:
    break;
  }
  fprintf(yyout, "%*cFactorExpr\top: %s\n", level, ' ', opName.c_str());
  expr->dump(level + 4);
}

void FactorExpr::genCppCode() {}

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

void BinaryExpr::genCppCode() {}

void SeqNode::dump(int level) {
  stmt1->dump(level);
  stmt2->dump(level);
}

void SeqNode::genCppCode() {
  stmt1->genCppCode();
  stmt2->genCppCode();
}

void DefId::dump(int level) {
  std::string name, type;
  name = id->dump();
  type = id->getType()->dump();
  fprintf(yyout, "%*cDefId\tname: %s\ttype: %s\n", level, ' ', name.c_str(),
          type.c_str());
  if (this->getNext())
    this->getNext()->dump(level);
}

void DefId::genCppCode() {}

void InitOptStmt::dump(int level) {
  fprintf(yyout, "%*cInitOptStmt\n", level, ' ');
  expr->dump(level + 4);
}

void InitOptStmt::genCppCode() {}

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

void ParamNode::genCppCode() {}

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

void ProcedureSpec::genCppCode() {}

void ProcedureDecl::dump(int level) {
  fprintf(yyout, "%*cProcedureDecl\n", level, ' ');
  spec->dump(level + 4);
}

void ProcedureDecl::genCppCode() {}

void ObjectDeclStmt::dump(int level) {
  printAstLog("ObjectDeclStmt dump");
  fprintf(yyout, "%*cObjectDeclStmt\n", level, ' ');
  id->dump(level + 4);
  if (init)
    init->dump(level + 4);
}

void ObjectDeclStmt::genCppCode() {
  Function *func = builder->getCurrFunc();
  // Init Var

  // Declared objects
  DefId *temp = id;
  while (temp) {
    Operand *op = new Operand(temp->getSymbolEntry(), temp->getType());
    func->addDeclOps(op);
    temp = dynamic_cast<DefId *>(temp->getNext());
  }
}

void DeclStmt::dump(int level) {
  fprintf(yyout, "%*cDeclStmt\n", level, ' ');
  if (objectDecl)
    objectDecl->dump(level + 4);
  if (procedureDecl)
    procedureDecl->dump(level + 4);
}

void DeclStmt::genCppCode() {
  if (objectDecl)
    objectDecl->genCppCode();
  if (procedureDecl)
    procedureDecl->genCppCode();
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

void DeclItemOrBodyStmt::genCppCode() {
  if (decl)
    decl->genCppCode();
  if (prof)
    prof->genCppCode();
  if (this->getNext())
    this->getNext()->genCppCode();
}

void NullStmt::dump(int level) { fprintf(yyout, "%*cNullStmt\n", level, ' '); }

void NullStmt::genCppCode() {}

void AssignStmt::dump(int level) {
  printAstLog("AssignStmt dump");
  std::string name, type;
  name = se->dump();
  type = se->getType()->dump();
  fprintf(yyout, "%*cAssignStmt\tname: %s\ttype: %s\n", level, ' ',
          name.c_str(), type.c_str());
  expr->dump(level + 4);
}

void AssignStmt::genCppCode() {}

void ReturnStmt::dump(int level) {
  fprintf(yyout, "%*cReturnStmt\n", level, ' ');
  if (retValue)
    retValue->dump(level + 4);
  else
    fprintf(yyout, "%*cvoid\n", level + 4, ' ');
}

void ReturnStmt::genCppCode() {}

void CallStmt::dump(int level) {
  fprintf(yyout, "%*cCallStmt\n", level, ' ');
  id->dump(level + 4);
}

void CallStmt::genCppCode() {}

void Stmt::dump(int level) {
  fprintf(yyout, "%*cStmt\n", level, ' ');
  if (stmt)
    stmt->dump(level + 4);
  if (stmt->getNext())
    stmt->getNext()->dump(level + 4);
}

void Stmt::genCppCode() {}

void ProcedureDef::dump(int level) {
  printAstLog("ProcedureDef dump");
  fprintf(yyout, "%*cProcedureDef\n", level, ' ');
  spec->dump(level + 4);
  if (items)
    items->dump(level + 4);
  if (stmts)
    stmts->dump(level + 4);
}

void ProcedureDef::genCppCode() {
  SymbolEntry *se = spec->getProcedureSymbol();
  CppUnit *unit = builder->getUnit();
  Function *curFunc = new Function(unit, se);
  unit->insertFunc(curFunc);
  builder->setCurrFunc(curFunc);
  spec->genCppCode();
  if (items)
    items->genCppCode();
  if (stmts)
    stmts->genCppCode();
}

void CondClause::dump(int level) {
  fprintf(yyout, "%*cCondClause\n", level, ' ');
  cond->dump(level + 4);
  stmts->dump(level + 4);
  if (this->getNext())
    this->getNext()->dump(level);
}

void CondClause::genCppCode() {}

void IfStmt::dump(int level) {
  fprintf(yyout, "%*cIfStmt\n", level, ' ');
  clause->dump(level + 4);
  if (elsestmt)
    elsestmt->dump(level + 4);
}

void IfStmt::genCppCode() {}

void Range::dump(int level) {
  fprintf(yyout, "%*cRange\n", level, ' ');
  lowerbound->dump(level + 4);
  upperbound->dump(level + 4);
}

void Range::genCppCode() {}

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

void DiscreteRange::genCppCode() {}

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

void Choice::genCppCode() {}

void Alternative::dump(int level) {
  fprintf(yyout, "%*cAlternative\n", level, ' ');
  choices->dump(level + 4);
  stmts->dump(level + 4);
  if (this->getNext())
    this->getNext()->dump(level);
}

void Alternative::genCppCode() {}

void CaseStmt::dump(int level) {
  fprintf(yyout, "%*cCaseStmt\n", level, ' ');
  expr->dump(level + 4);
  if (alter)
    alter->dump(level + 4);
}

void CaseStmt::genCppCode() {}

void ExitStmt::dump(int level) {
  fprintf(yyout, "%*cExitStmt\n", level, ' ');
  if (cond)
    cond->dump(level + 4);
}

void ExitStmt::genCppCode() {}

void BasicLoopStmt::dump(int level) {
  fprintf(yyout, "%*cBasicLoopStmt\n", level, ' ');
  stmts->dump(level + 4);
}

void BasicLoopStmt::genCppCode() {}

void IterPart::dump(int level) {
  std::string name;
  name = se->dump();
  fprintf(yyout, "%*cIterPart\tname: %s\n", level, ' ', name.c_str());
}

void IterPart::genCppCode() {}

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

void Iteration::genCppCode() {}

void LabelOpt::dump(int level) {
  std::string name;
  name = se->dump();
  fprintf(yyout, "%*cIterPart\tname: %s\n", level, ' ', name.c_str());
}

void LabelOpt::genCppCode() {}

void LoopStmt::dump(int level) {
  fprintf(yyout, "%*cLoopStmt\n", level, ' ');
  if (label)
    label->dump(level + 4);
  if (iter)
    iter->dump(level + 4);
  loop->dump(level + 4);
}

void LoopStmt::genCppCode() {}

void Block::dump(int level) {
  fprintf(yyout, "%*cBlockStmt\n", level, ' ');
  if (label)
    label->dump(level + 4);
  decl->dump(level + 4);
  stmts->dump(level + 4);
}

void Block::genCppCode() {}

void Ast::genCppCode(CppUnit *unit) {
  CppBuilder *builder = new CppBuilder(unit);
  Node::setCppBuilder(builder);
  root->genCppCode();
}