#ifndef __ADA2C_STATEMENT_H__
#define __ADA2C_STATEMENT_H__

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
  virtual void output(int level) = 0;
};

// Statement in Cpp 
class CppStmt : public CppNode{
private:
    CppStmt* next;

public:
    void output() const {}; 
};

// Expr in Cpp
class CppExpr : public CppNode{
public:
    void output() const {}; 
};




#endif