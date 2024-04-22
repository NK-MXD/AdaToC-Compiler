#ifndef __ADA2C_STATEMENT_H__
#define __ADA2C_STATEMENT_H__

#include "Operand.h"
#include "SymbolTable.h"
#include <cstring>
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
  virtual ~CppNode() {}
  int getSeq() const { return seq; };
  void setNext(CppNode *node);
  CppNode *getNext() const { return next; };
};

// Statement in Cpp
class CppStmt : public CppNode {
protected:
  CppStmt *next;

public:
  CppStmt(Function *func);
  void setNext(CppStmt *stmt);
  CppStmt *getNext() const { return next; };
  virtual std::string output(int level) const = 0;
};

// Expr in Cpp
class CppExpr : public CppNode {
public:
  virtual std::string output() const = 0;
};

class CppRange : public CppStmt {
private:
  CppExpr *cLow;
  CppExpr *cUpper;

public:
  CppRange(CppExpr *_low, CppExpr *_upper)
      : CppStmt(nullptr), cLow(_low), cUpper(_upper){};
  CppExpr *getLow() { return cLow; }
  CppExpr *getUpper() { return cUpper; }
  std::string output(int level) const { return ""; };
};

class CppId : public CppExpr {
private:
  SymbolEntry *se;
  CppId *name;
  CppExpr *expr;
  std::string attr;

public:
  CppId(SymbolEntry *_se) : se(_se){};
  CppId(CppId *_id, CppExpr *_expr) : name(_id), expr(_expr){};
  CppId(CppId *_id, std::string _attr) : name(_id), attr(_attr){};
  CppExpr *getParam() { return expr; }
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
  CppRange *cRange;
  SymbolEntry *se;
  int sign;
  bool isUnary;
  bool isMember;

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
  CppBinaryExpr(CppExpr *_expr1, int _sign) : cExpr1(_expr1), sign(_sign) {
    isUnary = true;
  };
  CppBinaryExpr(CppExpr *_expr1, CppRange *_range, int _sign)
      : cExpr1(_expr1), cRange(_range), sign(_sign) {
    isMember = true;
  };
  CppBinaryExpr(CppExpr *_expr1, SymbolEntry *_se, int _sign)
      : cExpr1(_expr1), se(_se), sign(_sign) {
    isMember = true;
  };
  std::string output() const;
};

class CppSeqStmt : public CppStmt {
private:
  CppStmt *stmt;

public:
  CppSeqStmt() : CppStmt(nullptr){};
  CppSeqStmt(Function *func) : CppStmt(func){};
  CppSeqStmt(Function *func, CppStmt *_stmt) : CppStmt(func), stmt(_stmt){};
  std::string output(int level) const;
};

class CppDummyStmt : public CppStmt {
public:
  CppDummyStmt() : CppStmt(nullptr){};
  CppDummyStmt(Function *func) : CppStmt(func){};
  std::string output(int level) const;
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
  std::string output(int level) const;
};

class CppCallStmt : public CppStmt {
private:
  CppId *cId;

public:
  CppCallStmt(Function *_func, CppId *_cId) : CppStmt(_func), cId(_cId){};
  std::string output(int level) const;
};

class CppCondClause : public CppStmt {
private:
  CppExpr *cond;
  CppSeqStmt *stmts;

public:
  CppCondClause(Function *_func, CppExpr *_cond, CppSeqStmt *_stmts)
      : CppStmt(_func) {
    cond = _cond;
    stmts = _stmts;
  };
  CppExpr *getCond() { return cond; }
  CppStmt *getStmts() { return stmts; }
  std::string output(int level) const;
};

class CppIfStmt : public CppStmt {
private:
  CppCondClause *clause;
  CppSeqStmt *elsestmt; // maybe is nullptr

public:
  CppIfStmt(Function *_func, CppCondClause *_clause,
            CppSeqStmt *_elsestmt = nullptr)
      : CppStmt(_func) {
    clause = _clause;
    elsestmt = _elsestmt;
  };
  std::string output(int level) const;
};

class CppIteration : public CppStmt {
private:
  SymbolEntry *se;
  CppRange *range;
  bool isReverse;

  CppExpr *cond = nullptr;

public:
  CppIteration(SymbolEntry *_se, CppRange *_range, bool _isReverse = false)
      : CppStmt(nullptr), se(_se), range(_range), isReverse(_isReverse){};
  CppIteration(CppExpr *_cond) : CppStmt(nullptr), cond(_cond){};
  std::string output(int level) const;
};

class CppLoopStmt : public CppStmt {
private:
  CppIteration *cIter;
  CppSeqStmt *loop;

public:
  CppLoopStmt(Function *_func, CppIteration *_cIter, CppSeqStmt *_loop)
      : CppStmt(_func), cIter(_cIter), loop(_loop){};
  std::string output(int level) const;
};

class CppChoice : public CppStmt {
private:
  CppExpr *cExpr;
  CppRange *range;
  bool isOther = false;
  bool isExpr = false;
  bool isRange = false;

public:
  CppChoice(CppExpr *_cExpr) : CppStmt(nullptr), cExpr(_cExpr) {
    isExpr = true;
  };
  CppChoice(CppRange *_range) : CppStmt(nullptr), range(_range) {
    isRange = true;
  };
  bool getIsExpr() { return isExpr; }
  bool getIsRange() { return isRange; }
  bool getIsOther() { return isOther; }
  CppExpr *getExpr() { return cExpr; }
  CppRange *getRange() { return range; }
  CppChoice(bool _isOther) : CppStmt(nullptr), isOther(_isOther){};
  std::string output(int level) const { return ""; };
};

class CppAlternative : public CppStmt {
private:
  CppChoice *choices;
  CppSeqStmt *stmts;

public:
  CppAlternative(CppChoice *_choices, CppSeqStmt *_stmts)
      : CppStmt(nullptr), choices(_choices), stmts(_stmts){};
  CppChoice *getChoices() { return choices; }
  CppSeqStmt *getStmts() { return stmts; }
  std::string output(int level) const {};
};

class CppCaseStmt : public CppStmt {
private:
  CppExpr *cExpr;
  CppAlternative *alter;

public:
  CppCaseStmt(Function *_func, CppExpr *_cExpr, CppAlternative *_alter)
      : CppStmt(_func), cExpr(_cExpr), alter(_alter){};
  std::string output(int level) const;
};

class CppExitStmt : public CppStmt {
private:
  CppExpr *cCond;

public:
  CppExitStmt(CppExpr *_cCond = nullptr) : CppStmt(nullptr), cCond(_cCond){};
  std::string output(int level) const;
};

class CppBlockStmt : public CppStmt {
private:
  CppSeqStmt *stmts;
  std::vector<Operand *> declvec;

public:
  CppBlockStmt(Function *_func, CppSeqStmt *_stmts)
      : CppStmt(_func), stmts(_stmts){};
  void addOps(Operand *_op) { declvec.push_back(_op); }
  std::string output(int level) const;
};

class CppFuncDecl: public CppStmt {
private:
  SymbolEntry* se;

public:
  CppFuncDecl(Function *_func, SymbolEntry* _se);
  std::string output(int level) const;
};

#endif