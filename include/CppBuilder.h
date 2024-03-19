#ifndef __ADA2C_CPPBUILDER_H__
#define __ADA2C_CPPBUILDER_H__

class CppUnit;
class Function;

class CppBuilder {
private:
  CppUnit *unit;

public:
  CppBuilder(CppUnit *unit) : unit(unit){};
  CppUnit *getUnit() { return unit; };
};

#endif