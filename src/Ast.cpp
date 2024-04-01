#include "Ast.h"
#include "CppBuilder.h"
#include "CppUnit.h"
#include "Procedure.h"

#define DEBUG_SWITCH_AST_LOG 1
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
  fprintf(yyout, "program\n");
  printAstLog("program");
  if (root != nullptr)
    root->dump(4);
}

void Ast::genCppCode(CppUnit *unit) {
  CppBuilder *builder = new CppBuilder(unit);
  Node::setCppBuilder(builder);
  root->genCppCode();
}

void ExprNode::dump(int level) {
  std::string name, type;
  name = symbolEntry->dump();
  type = symbolEntry->getType()->dump();
  fprintf(yyout, "%*cconst string\ttype:%s\t%s\n", level, ' ', type.c_str(),
          name.c_str());
}

void ExprNode::genCppCode() {}

void BinaryExpr::dump(int level) {
  std::string op_str;
  switch (op) {
  case ADD:
    op_str = "add";
    break;
  case SUB:
    op_str = "sub";
    break;
  case AND:
    op_str = "and";
    break;
  case OR:
    op_str = "or";
    break;
  case LESS:
    op_str = "less";
    break;
  }
  fprintf(yyout, "%*cBinaryExpr\top: %s\n", level, ' ', op_str.c_str());
  expr1->dump(level + 4);
  expr2->dump(level + 4);
}

void BinaryExpr::genCppCode() {}

void Constant::dump(int level) {
  std::string type, value;
  type = symbolEntry->getType()->dump();
  value = symbolEntry->dump();
  fprintf(yyout, "%*cIntegerLiteral\tvalue: %s\ttype: %s\n", level, ' ',
          value.c_str(), type.c_str());
}

void Constant::genCppCode() {}

void CallExpr::dump(int level) {
  std::string name, type;
  int scope;
  if (symbolEntry) {
    name = symbolEntry->dump();
    type = symbolEntry->getType()->dump();
    scope = dynamic_cast<IdentifierSymbolEntry *>(symbolEntry)->getScope();
    fprintf(yyout, "%*cCallExpr\tfunction name: %s\tscope: %d\ttype: %s\n",
            level, ' ', name.c_str(), scope, type.c_str());
    Node *temp = param;
    while (temp) {
      temp->dump(level + 4);
      temp = temp->getNext();
    }
  }
}

void CallExpr::genCppCode() {}

void ExprStmt::dump(int level) {
  fprintf(yyout, "%*cExprStmt\n", level, ' ');
  expr->dump(level + 4);
}

void ExprStmt::genCppCode() {}

void CompoundStmt::dump(int level) {
  fprintf(yyout, "%*cCompoundStmt\n", level, ' ');
  stmt->dump(level + 4);
}

void CompoundStmt::genCppCode() {}

void SeqNode::dump(int level) {
  stmt1->dump(level);
  stmt2->dump(level);
}

void SeqNode::genCppCode() {
  stmt1->genCppCode();
  stmt2->genCppCode();
}

void DeclStmt::dump(int level) {
  fprintf(yyout, "%*cDeclStmt\n", level, ' ');
  id->dump(level + 4);
}

void DeclStmt::genCppCode() {}

void IfStmt::dump(int level) {
  fprintf(yyout, "%*cIfStmt\n", level, ' ');
  cond->dump(level + 4);
  thenStmt->dump(level + 4);
}

void IfStmt::genCppCode() {}

void FunctionDef::dump(int level) {
  std::string name, type;
  name = se->dump();
  type = se->getType()->dump();
  fprintf(yyout, "%*cFunctionDefine function name: %s, type: %s\n", level, ' ',
          name.c_str(), type.c_str());
  if (stmt)
    stmt->dump(level + 4);
  else
    fprintf(yyout, "%*cNull", level + 4, ' ');
}

void FunctionDef::genCppCode() {}

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
  init->dump(level + 4);
}

void ParamNode::genCppCode() {}

void ProcedureSpec::dump(int level) {
  std::string name, type;
  name = se->dump();
  type = se->getType()->dump();
  fprintf(yyout, "%*cProcedure\tname: %s\ttype: %s\n", level, ' ', name.c_str(),
          type.c_str());
  params->dump(level + 4);
}

void ProcedureSpec::genCppCode() {}

void ProcedureDecl::dump(int level) {
  fprintf(yyout, "%*cProcedureDecl\n", level, ' ');
  spec->dump(level + 4);
}

void ProcedureDecl::genCppCode() {}

void ObjectDeclStmt::dump(int level) {
  std::string name, type;
  name = se->dump();
  type = se->getType()->dump();
  fprintf(yyout, "%*cObjectDeclStmt\tname: %s\ttype: %s\n", level, ' ',
          name.c_str(), type.c_str());
  if (init)
    init->dump(level + 4);
}

void ObjectDeclStmt::genCppCode() {}

void DeclStmt::dump(int level) {
  fprintf(yyout, "%*cDeclStmt\n", level, ' ');
  if (objectDecl)
    objectDecl->dump(level + 4);
  if (procedureDecl)
    procedureDecl->dump(level + 4);
}

void DeclStmt::genCppCode() {}

void DeclItemOrBodyStmt::dump(int level) {
  fprintf(yyout, "%*cDeclItemOrBodyStmt\n", level, ' ');
  if (decl)
    decl->dump(level + 4);
  if (prof)
    prof->dump(level + 4);
}

void DeclItemOrBodyStmt::genCppCode() {}

void AssignStmt::dump(int level) {
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
  retValue->dump(level + 4);
}

void ReturnStmt::genCppCode() {}

void CallStmt::dump(int level) {
  std::string name, type;
  name = se->dump();
  type = se->getType()->dump();
  fprintf(yyout, "%*cCallStmt\tname: s\ttype: %s\n", level, ' ', name.c_str(),
          type.c_str());
}

void CallStmt::genCppCode() {}

void Stmt::dump(int level) {
  fprintf(yyout, "%*cStmt\n", level, ' ');
  if (stmt)
    stmt->dump(level + 4);
}

void Stmt::genCppCode() {}

void ProcedureDef::dump(int level) {
  fprintf(yyout, "%*cProcedureDef\n", level, ' ');
  spec->dump(level + 4);
  if (items)
    items->dump(level + 4);
  if (stmts)
    stmts->dump(level + 4);
}

void ProcedureDef::genCppCode() {}

void CondClause::dump(int level) {
  fprintf(yyout, "%*cCondClause\n", level, ' ');
  cond->dump(level + 4);
  stmts->dump(level + 4);
}

void CondClause::genCppCode() {}

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
    fprintf(yyout, "%*ctrue\n", level + 4, ' ');
  }
}

void Choice::genCppCode() {}

void Alternative::dump(int level) {
  fprintf(yyout, "%*cAlternative\n", level, ' ');
  choices->dump(level + 4);
  stmts->dump(level + 4);
}

void Alternative::genCppCode() {}

void CaseStmt::dump(int level) {
  fprintf(yyout, "%*cCaseStmt\n", level, ' ');
  expr->dump(level + 4);
  alter->dump(level + 4);
}

void CaseStmt::genCppCode() {}

void Id::dump(int level) {
  std::string name, type;
  int scope;
  name = symbolEntry->dump();
  type = symbolEntry->getType()->dump();
  scope = dynamic_cast<IdentifierSymbolEntry *>(symbolEntry)->getScope();
  fprintf(yyout, "%*cId\tname: %s\tscope: %d\ttype: %s\n", level, ' ',
          name.c_str(), scope, type.c_str());
}

void Id::genCppCode() {}

void ExitStmt::dump(int level) {
  fprintf(yyout, "%*cExitStmt\n", level, ' ');
  if (id)
    id->dump(level + 4);
  if (cond)
    cond->dump(level + 4);
}

void ExitStmt::genCppCode() {}

void BasicLoopStmt::dump(int level) {
  fprintf(yyout, "%*cBasicLoopStmt\n", level, ' ');
  stmts->dump(level + 4);
}

void BasicLoopStmt::genCppCode() {}

void SignNode::dump(int level) {
  fprintf(yyout, "%*cSign\n", level, ' ');
  if (kind == SignNode::REVERSE) {
    fprintf(yyout, "%*cREVERSE\n", level + 4, ' ');
  }
}

void SignNode::genCppCode() {}

void IterPart::dump(int level) {
  std::string name;
  name = se->dump();
  fprintf(yyout, "%*cIterPart\tname: %s\n", level, ' ', name.c_str());
}

void IterPart::genCppCode() {}

void Iteration::dump(int level) {
  fprintf(yyout, "%*cIteration\n", level, ' ');
  if(cond) {
    cond->dump(level + 4);
  } else {
    iter->dump(level + 4);
    if(sign)
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
  if(label)
    label->dump(level + 4);
  if(iter)
    iter->dump(level + 4);
  loop->dump(level + 4);
  if(id)
    id->dump(level + 4);
}

void LoopStmt::genCppCode() {}


void Block::dump(int level) {
  fprintf(yyout, "%*cBlockStmt\n", level, ' ');
  if(label) 
    label->dump(level + 4);
  decl->dump(level + 4);
  stmts->dump(level + 4);
}

void Block::genCppCode() {}
