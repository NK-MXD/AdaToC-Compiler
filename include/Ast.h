#ifndef __ADA2C_AST_H__
#define __ADA2C_AST_H__

#include "CppUnit.h"
#include <SymbolTable.h>
#include <Type.h>
#include <iostream>
using namespace std;

class SymbolEntry;
class CppUnit;
class Function;
class Procedure;
class CppBuilder;

// Split up Ada grammar to some Grammar Node
// The Nodes are following Ada grammar.

class Node {
private:
  static int counter;
  int seq;
  Node *next;

protected:
  static CppBuilder *builder;

public:
  Node();
  int getSeq() const { return seq; };
  void setNext(Node *node);
  Node *getNext() { return next; }
  static void setCppBuilder(CppBuilder *cb) { builder = cb; };
  virtual void dump(int level) = 0;
  virtual void genCppCode() = 0;
};

class ExprNode : public Node {
protected:
  SymbolEntry *symbolEntry;

public:
  ExprNode(SymbolEntry *symbolEntry) : symbolEntry(symbolEntry){};
  SymbolEntry *getSymbolEntry() { return symbolEntry; };
  void dump(int level);
  void genCppCode();
};

class BinaryExpr : public ExprNode {
private:
  int op;
  ExprNode *expr1, *expr2;

public:
  enum {
    ADD,
    SUB,
    MUL,
    DIV,
    AND,
    OR,
    EQUAL,
    LESS,
    LESSEQUAL,
    GREATER,
    GREATEREQUAL,
  };
  BinaryExpr(SymbolEntry *se, int op, ExprNode *expr1, ExprNode *expr2)
      : ExprNode(se), op(op), expr1(expr1), expr2(expr2){};
  void dump(int level);
  void genCppCode();
};

class Constant : public ExprNode {
public:
  Constant(SymbolEntry *se) : ExprNode(se){};
  void dump(int level);
  void genCppCode();
};

class Id : public ExprNode {
public:
  Id(SymbolEntry *se) : ExprNode(se){};
  void dump(int level);
  void genCppCode();
};

class CallExpr : public ExprNode {
private:
  ExprNode *param;

public:
  CallExpr(SymbolEntry *se, ExprNode *param = nullptr)
      : ExprNode(se), param(param) {}
  CallExpr(const CallExpr &c) = default;
  void dump(int level);
  void genCppCode();
};

class StmtNode : public Node {};

class ExprStmt : public StmtNode {
private:
  ExprNode *expr;

public:
  ExprStmt(ExprNode *expr) : expr(expr){};
  void dump(int level);
  void genCppCode();
};

class CompoundStmt : public StmtNode {
private:
  StmtNode *stmt;

public:
  CompoundStmt(StmtNode *stmt) : stmt(stmt){};
  void dump(int level);
  void genCppCode();
};

class SeqNode : public StmtNode {
private:
  StmtNode *stmt1, *stmt2;

public:
  SeqNode(StmtNode *stmt1, StmtNode *stmt2) : stmt1(stmt1), stmt2(stmt2){};
  void dump(int level);
  void genCppCode();
};

class DeclStmt : public StmtNode {
private:
  Id *id;

public:
  DeclStmt(Id *id) : id(id){};
  Id *getId() { return id; };
  void dump(int level);
  void genCppCode();
};

class IfSectionStmt : public StmtNode {
private:
  StmtNode *ifStmt, *elsifStmt, *elseStmt;

public:
  IfSectionStmt(StmtNode *ifStmt, StmtNode *elsifStmt = nullptr,
                StmtNode *elseStmt = nullptr)
      : ifStmt(ifStmt), elsifStmt(elsifStmt), elseStmt(elseStmt){};
  void dump(int level){};
  void genCppCode(){};
};

class IfStmt : public StmtNode {
private:
  ExprNode *cond;
  StmtNode *thenStmt;
  bool isElsif, isElse;

public:
  IfStmt(ExprNode *cond, StmtNode *thenStmt, bool isElsif = false)
      : cond(cond), thenStmt(thenStmt), isElsif(isElsif){};
  IfStmt(StmtNode *thenStmt) : cond(nullptr), thenStmt(thenStmt) {
    isElse = true;
  };
  void dump(int level);
  void genCppCode();
};

class ReturnStmt : public StmtNode {
private:
  ExprNode *retValue;

public:
  ReturnStmt(ExprNode *retValue) : retValue(retValue){};
  void dump(int level);
  void genCppCode();
};

class FunctionDef : public StmtNode {
private:
  SymbolEntry *se;
  DeclStmt *decl;
  StmtNode *stmt;

public:
  FunctionDef(SymbolEntry *se, DeclStmt *decl, StmtNode *stmt)
      : se(se), decl(decl), stmt(stmt){};
  void dump(int level);
  void genCppCode();
};

class InitOptStmt : public StmtNode {
private:
  ExprNode *expr;

public:
  InitOptStmt(ExprNode *expr) : expr(expr){};
  void dump(int level);
  void genCppCode();
};

class ParamNode : public StmtNode {
private:
  SymbolEntry *se;
  InitOptStmt *init;

public:
  ParamNode(SymbolEntry *_se, InitOptStmt *_init) : se(_se), init(_init) {}
  SymbolEntry *getParamSymbol() { return se; }
  void dump(int level);
  void genCppCode();
};

class ProcedureSpec : public StmtNode {
private:
  SymbolEntry *se;
  ParamNode *params;

public:
  ProcedureSpec(SymbolEntry *_se, ParamNode *_params = nullptr)
      : se(_se), params(_params) {}
  SymbolEntry *getProcedureSymbol() { return se; }
  void dump(int level);
  void genCppCode();
};

class ProcedureDecl : public StmtNode {
private:
  ProcedureSpec *spec;

public:
  ProcedureDecl(ProcedureSpec *_spec) : spec(_spec) {}
  SymbolEntry *getProcedureSymbol() { return spec->getProcedureSymbol(); }
  void dump(int level);
  void genCppCode();
};

class ObjectDeclStmt : public StmtNode {
private:
  SymbolEntry *se;
  InitOptStmt *init;

public:
  ObjectDeclStmt(SymbolEntry *_se, InitOptStmt *_init) : se(_se), init(_init) {}
  SymbolEntry *getObjectSymbol() { return se; }
  void dump(int level);
  void genCppCode();
};

class DeclStmt : public StmtNode {
private:
  ObjectDeclStmt *objectDecl;
  ProcedureDecl *procedureDecl;

public:
  DeclStmt(ObjectDeclStmt *_objectDecl) : objectDecl(_objectDecl) {}
  DeclStmt(ProcedureDecl *_procedureDecl) : procedureDecl(_procedureDecl) {}
  void dump(int level);
  void genCppCode();
};

class DeclItemOrBodyStmt : public StmtNode {
private:
  DeclStmt *decl;
  ProcedureDef *prof;

public:
  DeclItemOrBodyStmt(DeclStmt *_decl) : decl(_decl) {}
  DeclItemOrBodyStmt(ProcedureDef *_prof) : prof(_prof) {}
  void dump(int level);
  void genCppCode();
};

class AssignStmt : public StmtNode {
private:
  SymbolEntry *se;
  ExprNode *expr;

public:
  AssignStmt(SymbolEntry *_se, ExprNode *_expr) : se(_se), expr(_expr){};
  void dump(int level);
  void genCppCode();
};

class ReturnStmt : public StmtNode {
private:
  ExprNode *retValue;

public:
  ReturnStmt(ExprNode *_retValue = nullptr) : retValue(_retValue){};
  void dump(int level);
  void genCppCode();
};

class CallStmt : public StmtNode {
private:
  SymbolEntry *se;

public:
  CallStmt(SymbolEntry *_se) : se(_se){};
  void dump(int level);
  void genCppCode();
};

class Stmt : public StmtNode {
private:
  StmtNode *stmt;

public:
  Stmt(StmtNode *_stmt) : stmt(_stmt){};
  void dump(int level);
  void genCppCode();
};

class ProcedureDef : public StmtNode {
private:
  ProcedureSpec *spec;
  DeclItemOrBodyStmt *items;
  Stmt *stmts;

public:
  ProcedureDef(ProcedureSpec *_spec, DeclItemOrBodyStmt *_items = nullptr,
               Stmt *_stmts = nullptr)
      : spec(_spec), items(_items), stmts(_stmts){};
  SymbolEntry *getProcedureSymbol() { return spec->getProcedureSymbol(); }
  void dump(int level);
  void genCppCode();
};

class CondClause : public StmtNode {
private:
  ExprNode *cond;
  Stmt *stmts;

public:
  CondClause(ExprNode *_cond, Stmt *_stmts) : cond(_cond), stmts(_stmts){};
  void dump(int level);
  void genCppCode();
};

class IfStmt : public StmtNode {
private:
  CondClause *clause;
  Stmt *elsestmt;

public:
  IfStmt(CondClause *_clause, Stmt *_elsestmt)
      : clause(_clause), elsestmt(_elsestmt){};
  void dump(int level);
  void genCppCode();
};

class Range : public StmtNode {
private:
  ExprNode *lowerbound;
  ExprNode *upperbound;

public:
  Range(ExprNode *_lowerbound, ExprNode *_upperbound)
      : lowerbound(_lowerbound), upperbound(_upperbound){};
  void dump(int level);
  void genCppCode();
};

class DiscreteRange : public StmtNode {
private:
  SymbolEntry *se;
  Range *range;

public:
  DiscreteRange(SymbolEntry *_se, Range *_range = nullptr)
      : se(_se), range(_range){};
  DiscreteRange(Range *_range) : range(_range){};
  void dump(int level);
  void genCppCode();
};

class Choice : public StmtNode {
private:
  ExprNode *expr;
  DiscreteRange *discret;
  bool others = false;

public:
  Choice(ExprNode *_expr) : expr(_expr){};
  Choice(DiscreteRange *_discret) : discret(_discret){};
  Choice(bool _others) : others(_others){};
  void dump(int level);
  void genCppCode();
};

class Alternative : public StmtNode {
private:
  Choice *choices;
  Stmt *stmts;

public:
  Alternative(Choice *_choices, Stmt *_stmts)
      : choices(_choices), stmts(_stmts){};
  void dump(int level);
  void genCppCode();
};

class CaseStmt : public StmtNode {
private:
  ExprNode *expr;
  Alternative *alter;

public:
  CaseStmt(ExprNode *_expr, Alternative *_alter) : expr(_expr), alter(_alter){};
  void dump(int level);
  void genCppCode();
};

class Id : public ExprNode {
public:
  Id(SymbolEntry *se) : ExprNode(se){};
  void dump(int level);
  void genCppCode();
};

class ExitStmt : public StmtNode {
private:
  Id *id;
  ExprNode *cond;

public:
  ExitStmt(Id *_id, ExprNode *_cond) : id(_id), cond(_cond){};
  void dump(int level);
  void genCppCode();
};

class BasicLoopStmt : public StmtNode {
private:
  Stmt *stmts;

public:
  BasicLoopStmt(Stmt *_stmts) : stmts(_stmts){};
  void dump(int level);
  void genCppCode();
};

class SignNode : public Node {
private:
  int kind;

public:
  enum {
    REVERSE,
  };
  SignNode(int _kind) : kind(_kind){};
  void dump(int level);
  void genCppCode();
};

class IterPart : public StmtNode {
private:
  SymbolEntry *se;

public:
  IterPart(SymbolEntry *_se) : se(_se){};
  void dump(int level);
  void genCppCode();
};

class Iteration : public StmtNode {
private:
  IterPart *iter;
  SignNode *sign;
  DiscreteRange *range;

  ExprNode *cond;

public:
  Iteration(ExprNode *_cond) : cond(_cond){};
  Iteration(IterPart *_iter, SignNode *_sign, DiscreteRange *_range)
      : iter(_iter), sign(_sign), range(_range){};
  void dump(int level);
  void genCppCode();
};

class LabelOpt : public StmtNode {
private:
  SymbolEntry *se;

public:
  LabelOpt(SymbolEntry *_se) : se(_se){};
  void dump(int level);
  void genCppCode();
};

class LoopStmt : public StmtNode {
private:
  LabelOpt *label;
  Iteration *iter;
  BasicLoopStmt *loop;
  Id *id;

public:
  LoopStmt(LabelOpt *_label, Iteration *_iter, BasicLoopStmt *_loop, Id *_id;)
      : label(_label), iter(_iter), loop(_loop), id(_id){};
  void dump(int level);
  void genCppCode();
};

class Block : public StmtNode {
private:
  LabelOpt *label;
  DeclItemOrBodyStmt *decl;
  Stmt *stmts;

public:
  Block(LabelOpt *_label, DeclItemOrBodyStmt *_decl, Stmt *_stmts)
      : label(_label), decl(_decl), stmts(_stmts){};
  void dump(int level);
  void genCppCode();
};

class Ast {
private:
  Node *root;

public:
  Ast() { root = nullptr; }
  void setRoot(Node *n) { root = n; }
  void dump();
  void genCppCode(CppUnit *unit);
};

#endif