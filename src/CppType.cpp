#include "CppType.h"

extern FILE *yyout;
bool AdaInteger::isUsed = false;

void AdaInteger::output() {
  fprintf(yyout, "\
class AdaInteger {\n\
private:\n\
  int value;\n\
public:\n\
  AdaInteger() = default;\n\
  AdaInteger(int _value) : value(_value) {};\n\
  int getValue() { return value; }\n\
  void setValue(int _value) { value = _value; }\n\
  void operator=(int _value) {\n\
    value = _value;\n\
  }\n\
  AdaInteger &operator+(AdaInteger _right) {\n\
    AdaInteger res;\n\
    res.setValue(value + _right.getValue());\n\
    return res;\n\
  }\n\
  AdaInteger &operator+(int _right) {\n\
    AdaInteger res;\n\
    res.setValue(value + _right);\n\
    return res;\n\
  }\n\
};\n");
}