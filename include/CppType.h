#ifndef __ADA2C_CPPTYPE_H__
#define __ADA2C_CPPTYPE_H__

#include <iostream>

class AdaInteger {
private:
  int value;

public:
  static bool isUsed;
  AdaInteger() = default;
  static AdaInteger getInstance() {
    AdaInteger i;
    AdaInteger::isUsed = true;
    return i;
  }
  AdaInteger(int _value) : value(_value){};
  // Define some operator or function which used in Ada grammar/
  int getValue() { return value; }
  void setValue(int _value) { value = _value; }
  void operator=(AdaInteger _right) { value = _right.getValue(); }
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
  static void output();
};

class AdaNatural {
private:
  int value;

public:
  static bool isUsed;
  AdaNatural() = default;
  static AdaNatural getInstance() {
    AdaNatural i;
    AdaNatural::isUsed = true;
    return i;
  }
  AdaNatural(int _value) : value(_value){};
  // Define some operator or function which used in Ada grammar/
  int getValue() { return value; }
  void setValue(int _value) { value = _value; }
  static void output();
};

class AdaString {
private:
  std::string value;

public:
  static bool isUsed;
  AdaString() = default;
  static AdaString getInstance() {
    AdaString i;
    AdaString::isUsed = true;
    return i;
  }
  AdaString(std::string _value): value(_value) {};
  std::string getValue() { return value; }
  void setValue(std::string _value) { value = _value; }
  static void output();
};

#endif