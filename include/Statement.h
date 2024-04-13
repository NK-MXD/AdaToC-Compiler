#ifndef __ADA2C_STATEMENT_H__
#define __ADA2C_STATEMENT_H__

#include "SymbolTable.h"
#include <iostream>
using namespace std;

class Function;

// The Ast Node of Cpp Grammar
class CppNode {
private:
  static int counter;
  int seq;
  CppNode *next;

public:
  CppNode();
  int getSeq() const { return seq; };
  void setNext(CppNode *node);
  CppNode *getNext() { return next; }
  virtual std::string output() const = 0;
};

// Statement in Cpp
class CppStmt : public CppNode {
private:
  CppStmt *next;

public:
  CppStmt(Function *func);
  std::string output() const {};
};

// Expr in Cpp
class CppExpr : public CppNode {
public:
  std::string output() const {};
};

class CppId : public CppExpr {
private:
  SymbolEntry *se;
  CppExpr *expr;

public:
  CppId(SymbolEntry *_se) : se(_se){};
  std::string output() const;
};

class CppConstant : public CppExpr {
private:
  SymbolEntry *se;

public:
  CppConstant(SymbolEntry *_se) : se(_se){};
  std::string output() const;
};

class CppFactor : public CppExpr {
private:
  CppExpr *cExpr;
  int op;

public:
  enum {
    NOT,
    ABS,
  };
  CppFactor(CppExpr *_expr, int _op) : cExpr(_expr), op(_op){};
  std::string output() const;
};

class CppBinaryExpr : public CppExpr {
private:
  CppExpr *cExpr1, *cExpr2;
  SymbolEntry *se;
  int sign;

public:
  enum {
    MUL,
    DIV,
    MOD,
    REM,
    ADD,
    SUB,
    SINGLEAND,
    IN,
    NOTIN,
    EQ,
    NE,
    LE,
    LTEQ,
    GE,
    GTEQ,
    ANDTHEN,
    ORELSE,
    AND,
    OR,
    XOR,
    EXPON,
  };
  CppBinaryExpr(CppExpr *_expr1, CppExpr *_expr2, int _sign)
      : cExpr1(_expr1), cExpr2(_expr2), sign(_sign){};
  CppBinaryExpr(CppExpr *_expr1, SymbolEntry *_se, int _sign)
      : cExpr1(_expr1), se(_se), sign(_sign){};
  std::string output() const;
};

class CppDummyStmt : public CppStmt {
public:
  CppDummyStmt() : CppStmt(nullptr){};
  std::string output(){};
};

class CppAssignStmt : public CppStmt {
private:
  SymbolEntry *se;
  CppExpr *cExpr;

public:
  CppAssignStmt(Function *func, SymbolEntry *_se, CppExpr *_cExpr)
      : CppStmt(func) {
    se = _se;
    cExpr = _cExpr;
  };
  std::string output() const;
};

#endif