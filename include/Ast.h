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
  void dump(int level) {};
  void genCppCode() {};
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

class AssignStmt : public StmtNode {
private:
  ExprNode *lval;
  ExprNode *expr;

public:
  AssignStmt(ExprNode *lval, ExprNode *expr) : lval(lval), expr(expr){};
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
  ParamNode(SymbolEntry *_se, InitOptStmt *_init)
      : se(_se), init(_init){}
  SymbolEntry* getParamSymbol() {
    return se;
  }
  void dump(int level);
  void genCppCode();
};

class ProcedureSpec : public StmtNode {
private:
  SymbolEntry *se;
  ParamNode *params;

public:
  ProcedureSpec(SymbolEntry *_se, ParamNode *_params = nullptr)
      : se(_se), params(_params){}
  SymbolEntry* getProcedureSymbol() {
    return se;
  }
  void dump(int level);
  void genCppCode();
};

class ProcedureDecl : public StmtNode {
private:
  ProcedureSpec *spec;

public:
  ProcedureDecl(ProcedureSpec *_spec)
      : spec(_spec){}
  SymbolEntry* getProcedureSymbol() {
    return spec->getProcedureSymbol();
  }
  void dump(int level);
  void genCppCode();
};

class ProcedureDef : public StmtNode {
private:
  ProcedureSpec *spec;

public:
  ProcedureDef(ProcedureSpec *_spec)
      : spec(_spec){}
  SymbolEntry* getProcedureSymbol() {
    return spec->getProcedureSymbol();
  }
  void dump(int level);
  void genCppCode();
};


class ObjectDecl : public StmtNode {
private:
  ProcedureSpec *spec;

public:
  DeclStmt(ProcedureSpec *_spec)
      : spec(_spec){}
  SymbolEntry* getProcedureSymbol() {
    return spec->getProcedureSymbol();
  }
  void dump(int level);
  void genCppCode();
};



class DeclStmt : public StmtNode {
private:
  ProcedureSpec *spec;

public:
  DeclStmt(ProcedureSpec *_spec)
      : spec(_spec){}
  SymbolEntry* getProcedureSymbol() {
    return spec->getProcedureSymbol();
  }
  void dump(int level);
  void genCppCode();
};

class DeclItemOrBodyStmt : public StmtNode {
private:
  
  ProcedureDef *prof;

public:
  DeclItemOrBody(ProcedureSpec *_spec)
      : spec(_spec){}
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