#include "CppType.h"

extern FILE *yyout;
bool AdaInteger::isUsed = false;

void AdaInteger::output() {
  fprintf(yyout, R"(class AdaInteger {
private:
  int value;
public:
  AdaInteger() = default;
  AdaInteger(int _value) : value(_value) {};
  int getValue() { return value; }
  void setValue(int _value) { value = _value; }
  void operator=(int _value) {
    value = _value;
  }
  AdaInteger &operator+(AdaInteger _right) {
    AdaInteger res;
    res.setValue(value + _right.getValue());
    return res;
  }
  AdaInteger &operator+(int _right) {
    AdaInteger res;
    res.setValue(value + _right);
    return res;
  }
};
)");
}