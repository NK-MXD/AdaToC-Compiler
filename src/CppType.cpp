#include "CppType.h"

extern FILE *yyout;
bool AdaInteger::isUsed = false;
bool AdaNatural::isUsed = false;
bool AdaString::isUsed = false;

void AdaInteger::output() {
  fprintf(yyout, R"(#include <climits>
#include <string>
class AdaInteger {
private:
  int value;

public:
  static AdaInteger Last;
  AdaInteger() = default;
  AdaInteger(int _value) : value(_value){};
  AdaInteger operator-() { return AdaInteger(-value); }
  friend AdaInteger operator+(AdaInteger &_left, AdaInteger &_right) {
    return AdaInteger(_left.value + _right.value);
  }
  friend AdaInteger operator+(AdaInteger &_left, int _right) {
    return AdaInteger(_left.value + _right);
  }
  friend AdaInteger operator-(AdaInteger &_left, AdaInteger &_right) {
    return AdaInteger(_left.value - _right.value);
  }
  friend AdaInteger operator-(AdaInteger &_left, int _right) {
    return AdaInteger(_left.value - _right);
  }
  friend bool operator>(AdaInteger &_left, AdaInteger &_right) {
    return _left.value > _right.value;
  }
  friend bool operator>(AdaInteger &_left, int _right) {
    return _left.value > _right;
  }
  friend bool operator<(AdaInteger &_left, AdaInteger &_right) {
    return _left.value < _right.value;
  }
  friend bool operator<(AdaInteger &_left, int _right) {
    return _left.value < _right;
  }
  friend bool operator==(AdaInteger &_left, AdaInteger &_right) {
    return _left.value == _right.value;
  }
  friend bool operator==(AdaInteger &_left, int _right) {
    return _left.value == _right;
  }
  friend bool operator!=(AdaInteger &_left, AdaInteger &_right) {
    return _left.value != _right.value;
  }
  friend bool operator!=(AdaInteger &_left, int _right) {
    return _left.value != _right;
  }
  friend bool operator<=(AdaInteger &_left, AdaInteger &_right) {
    return _left.value <= _right.value;
  }
  friend bool operator<=(AdaInteger &_left, int _right) {
    return _left.value <= _right;
  }
  friend bool operator>=(AdaInteger &_left, AdaInteger &_right) {
    return _left.value >= _right.value;
  }
  friend bool operator>=(AdaInteger &_left, int _right) {
    return _left.value >= _right;
  }
  static std::string Image(AdaInteger I) { return std::to_string(I.value); }
};
AdaInteger AdaInteger::Last = AdaInteger(INT_MAX);
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

void AdaString::output() {
  fprintf(yyout, R"(#include <string>
class AdaString {
private:
  std::string value;

public:
  AdaString() = default;
  AdaString(std::string _value) : value(_value){};
  AdaString(const char *_value) { value = std::string(_value); };
  AdaString(const AdaString &a) { value = a.getValue(); };
  std::string getValue() const { return value; }
  void setValue(std::string _value) { value = _value; }
  friend AdaString operator+(AdaString &_left, AdaString &_right) {
    return AdaString(_left.value + _right.value);
  }
  friend AdaString operator+(AdaString &_left, std::string _right) {
    return AdaString(_left.value + _right);
  }
};
)");
}