#ifndef __ADA2C_CPPTYPE_H__
#define __ADA2C_CPPTYPE_H__

#include<iostream>

class AdaInteger {
private:
  int value;
  static bool isUsed;

public:
  AdaInteger() = default;
  static AdaInteger getInstance() {
    AdaInteger i;
    i.isUsed = true;
    return i;
  }
  AdaInteger(int _value) : value(_value) {};
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
  static void output() ;
};

#endif