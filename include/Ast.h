#ifndef __ADA2C_AST_H__
#define __ADA2C_AST_H__

#include <SymbolTable.h>
#include <Type.h>

class SymbolEntry;

class Node {
private:
  static int counter;
  int seq;

public:
  Node();
  int getSeq() const { return seq; };
  virtual void dump(int level) = 0;
};

class ExprNode : public Node {
protected:
  SymbolEntry *symbolEntry;

public:
  ExprNode(SymbolEntry *symbolEntry) : symbolEntry(symbolEntry){};
  SymbolEntry *getSymbolEntry() { return symbolEntry; };
};

class BinaryExpr : public ExprNode {
private:
  int op;
  ExprNode *expr1, *expr2;

public:
  enum { ADD, SUB, AND, OR, LESS };
  BinaryExpr(SymbolEntry *se, int op, ExprNode *expr1, ExprNode *expr2)
      : ExprNode(se), op(op), expr1(expr1), expr2(expr2){};
  void dump(int level);
};

class Constant : public ExprNode {
public:
  Constant(SymbolEntry *se) : ExprNode(se){};
  void dump(int level);
};

class Id : public ExprNode {
public:
  Id(SymbolEntry *se) : ExprNode(se){};
  void dump(int level);
};

class StmtNode : public Node {};

class CompoundStmt : public StmtNode {
private:
  StmtNode *stmt;

public:
  CompoundStmt(StmtNode *stmt) : stmt(stmt){};
  void dump(int level);
};

class SeqNode : public StmtNode {
private:
  StmtNode *stmt1, *stmt2;

public:
  SeqNode(StmtNode *stmt1, StmtNode *stmt2) : stmt1(stmt1), stmt2(stmt2){};
  void dump(int level);
};

class DeclStmt : public StmtNode {
private:
  Id *id;

public:
  DeclStmt(Id *id) : id(id){};
  Id *getId() { return id; };
  void dump(int level);
};

class IfSectionStmt : public StmtNode {
private:
  ExprNode *cond;
  StmtNode *thenStmt, *elsifStmt, *elseStmt;

public:
  IfSectionStmt(ExprNode *cond, StmtNode *thenStmt, StmtNode *elsifStmt,
                StmtNode *elseStmt)
      : cond(cond), thenStmt(thenStmt), elsifStmt(elsifStmt),
        elseStmt(elseStmt){};
  void dump(int level);
};

class IfStmt : public StmtNode {
private:
  ExprNode *cond;
  StmtNode *thenStmt;

public:
  IfStmt(ExprNode *cond, StmtNode *thenStmt) : cond(cond), thenStmt(thenStmt){};
  void dump(int level);
};

class ReturnStmt : public StmtNode {
private:
  ExprNode *retValue;

public:
  ReturnStmt(ExprNode *retValue) : retValue(retValue){};
  void dump(int level);
};

class AssignStmt : public StmtNode {
private:
  ExprNode *lval;
  ExprNode *expr;

public:
  AssignStmt(ExprNode *lval, ExprNode *expr) : lval(lval), expr(expr){};
  void dump(int level);
};

class FunctionDef : public StmtNode {
private:
  SymbolEntry *se;
  StmtNode *stmt;

public:
  FunctionDef(SymbolEntry *se, StmtNode *stmt) : se(se), stmt(stmt){};
  void dump(int level);
};

class Ast {
private:
  Node *root;

public:
  Ast() { root = nullptr; }
  void setRoot(Node *n) { root = n; }
  void dump();
};

#endif