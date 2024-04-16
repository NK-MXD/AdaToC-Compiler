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
  AdaInteger operator-() {
    return AdaInteger(-value);
  }
  friend AdaInteger operator+(AdaInteger& _left, AdaInteger& _right) {
    return AdaInteger(_left.value + _right.value);
  }
  friend AdaInteger operator+(AdaInteger& _left, int _right) {
    return AdaInteger(_left.value + _right);
  }
  friend AdaInteger operator-(AdaInteger& _left, AdaInteger& _right) {
    return AdaInteger(_left.value - _right.value);
  }
  friend bool operator>(AdaInteger& _left, AdaInteger& _right) {
    return _left.value > _right.value;
  }
  friend bool operator>(AdaInteger& _left, int _right) {
    return _left.value > _right;
  }
  friend bool operator<(AdaInteger& _left, AdaInteger& _right) {
    return _left.value < _right.value;
  }
  friend bool operator<(AdaInteger& _left, int _right) {
    return _left.value < _right;
  }
  friend bool operator==(AdaInteger& _left, AdaInteger& _right) {
    return _left.value == _right.value;
  }
  friend bool operator==(AdaInteger& _left, int _right) {
    return _left.value == _right;
  }
  friend bool operator!=(AdaInteger& _left, AdaInteger& _right) {
    return _left.value != _right.value;
  }
  friend bool operator!=(AdaInteger& _left, int _right) {
    return _left.value != _right;
  }
  friend bool operator<=(AdaInteger& _left, AdaInteger& _right) {
    return _left.value <= _right.value;
  }
  friend bool operator<=(AdaInteger& _left, int _right) {
    return _left.value <= _right;
  }
  friend bool operator>=(AdaInteger& _left, AdaInteger& _right) {
    return _left.value >= _right.value;
  }
  friend bool operator>=(AdaInteger& _left, int _right) {
    return _left.value >= _right;
  }
};
)");
}