#include "CppType.h"

extern FILE *yyout;
bool AdaInteger::isUsed = false;
bool AdaNatural::isUsed = false;

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
  friend AdaInteger operator-(AdaInteger& _left, int _right) {
    return AdaInteger(_left.value - _right);
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

void AdaNatural::output() {
  fprintf(yyout, R"(class AdaNatural {
private:
  int value;
public:
  AdaNatural() = default;
  AdaNatural(int _value) : value(_value) {};
  AdaNatural operator-() {
    return AdaNatural(-value);
  }
  friend AdaNatural operator+(AdaNatural& _left, AdaNatural& _right) {
    return AdaNatural(_left.value + _right.value);
  }
  friend AdaNatural operator+(AdaNatural& _left, int _right) {
    return AdaNatural(_left.value + _right);
  }
  friend AdaNatural operator-(AdaNatural& _left, AdaNatural& _right) {
    return AdaNatural(_left.value - _right.value);
  }
  friend AdaNatural operator-(AdaNatural& _left, int _right) {
    return AdaNatural(_left.value - _right);
  }
  friend bool operator>(AdaNatural& _left, AdaNatural& _right) {
    return _left.value > _right.value;
  }
  friend bool operator>(AdaNatural& _left, int _right) {
    return _left.value > _right;
  }
  friend bool operator<(AdaNatural& _left, AdaNatural& _right) {
    return _left.value < _right.value;
  }
  friend bool operator<(AdaNatural& _left, int _right) {
    return _left.value < _right;
  }
  friend bool operator==(AdaNatural& _left, AdaNatural& _right) {
    return _left.value == _right.value;
  }
  friend bool operator==(AdaNatural& _left, int _right) {
    return _left.value == _right;
  }
  friend bool operator!=(AdaNatural& _left, AdaNatural& _right) {
    return _left.value != _right.value;
  }
  friend bool operator!=(AdaNatural& _left, int _right) {
    return _left.value != _right;
  }
  friend bool operator<=(AdaNatural& _left, AdaNatural& _right) {
    return _left.value <= _right.value;
  }
  friend bool operator<=(AdaNatural& _left, int _right) {
    return _left.value <= _right;
  }
  friend bool operator>=(AdaNatural& _left, AdaNatural& _right) {
    return _left.value >= _right.value;
  }
  friend bool operator>=(AdaNatural& _left, int _right) {
    return _left.value >= _right;
  }
};
)");
}