#ifndef __ADA2C_CPP_UNIT_H__
#define __ADA2C_CPP_UNIT_H__

#include "Function.h"
#include <vector>

class CppUnit {
private:
  // The list of functions and procedures.
  std::vector<Function *> funcList;

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
  void output() const {
    for (auto &func : funcList)
      func->output(0);
  }
};

#endif