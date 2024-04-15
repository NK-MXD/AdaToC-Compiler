#ifndef __ADA2C_CPP_UNIT_H__
#define __ADA2C_CPP_UNIT_H__

#include "CppType.h"
#include "Function.h"
#include <map>
#include <vector>

class CppUnit {
private:
  // The list of functions and procedures.
  std::vector<Function *> funcList;
  // The list of all static operands
  std::map<Function *, std::vector<Operand*>*> opList;

public:
  CppUnit() = default;
  ~CppUnit() {
    // auto deleteList = funcList;
    // for (auto &func : deleteList)
    //   delete func;
  }
  void insertFunc(Function *func) { funcList.push_back(func); }
  void removeFunc(Function *func) {
    funcList.erase(std::find(funcList.begin(), funcList.end(), func));
  }
  void insertOp(Function *func, Operand *op) {
    if(!opList.count(func)) {
      std::vector<Operand*>* vec = new std::vector<Operand*>();
      vec->push_back(op);
      opList[func] = vec;
    } else {
      opList[func]->push_back(op);
    }
  }
  Function *getFunction(SymbolEntry *se) {
    for(auto func = funcList.begin(); func != funcList.end(); func++) {
      if((*func)->getName() == se->dump()) {
        return *func;
      }
    }
    return nullptr;
  }
  void output() const;
  static std::string getOpFullName(Function* func, Operand* op); 
};

#endif