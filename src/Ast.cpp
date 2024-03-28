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

void ReturnStmt::dump(int level) {
  fprintf(yyout, "%*cReturnStmt\n", level, ' ');
  retValue->dump(level + 4);
}

void ReturnStmt::genCppCode() {}

void AssignStmt::dump(int level) {
  fprintf(yyout, "%*cAssignStmt\n", level, ' ');
  lval->dump(level + 4);
  expr->dump(level + 4);
}

void AssignStmt::genCppCode() {}

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
  fprintf(yyout, "%*cParam\tname: %s\ttype: %s\n", level, ' ',
          name.c_str(), type.c_str());
  init->dump(level + 4);
}

void ParamNode::genCppCode() {}

void ProcedureSpec::dump(int level) {
  std::string name, type;
  name = se->dump();
  type = se->getType()->dump();
  fprintf(yyout, "%*cProcedure\tname: %s\ttype: %s\n", level, ' ',
          name.c_str(), type.c_str());
  params->dump(level + 4);
}

void ProcedureSpec::genCppCode() {}

void ProcedureDecl::dump(int level) {
  fprintf(yyout, "%*cProcedureDecl\n", level, ' ');
  spec->dump(level + 4);
}

void ProcedureDecl::genCppCode() {}

void ProcedureDef::dump(int level) {
  fprintf(yyout, "%*cProcedureDef\n", level, ' ');
  spec->dump(level + 4);
}

void ProcedureDef::genCppCode() {}