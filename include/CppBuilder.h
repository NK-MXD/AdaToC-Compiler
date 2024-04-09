#ifndef __ADA2C_CPPBUILDER_H__
#define __ADA2C_CPPBUILDER_H__

class CppUnit;
class Function;

class CppBuilder {
private:
  CppUnit *unit;
  Function *currentFunc;

public:
  CppBuilder(CppUnit *unit) : unit(unit){};
  CppUnit *getUnit() { return unit; };
  void setCurrFunc(Function *func) { currentFunc = func; };
  Function* getCurrFunc() {
    return currentFunc;
  }
};

#endif