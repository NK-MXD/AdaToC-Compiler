#ifndef __ADA2C_CPPBUILDER_H__
#define __ADA2C_CPPBUILDER_H__

#include <stack>
class CppUnit;
class Function;

class CppBuilder {
private:
  CppUnit *unit;
  std::stack<Function *> curFunc;

public:
  CppBuilder(CppUnit *unit) : unit(unit){};
  CppUnit *getUnit() { return unit; };
  void setCurrFunc(Function *func) { curFunc.push(func); };
  void removeCurrFunc() {
    if (curFunc.top())
      curFunc.pop();
  }
  Function *getCurrFunc() { return curFunc.top(); }
};

#endif