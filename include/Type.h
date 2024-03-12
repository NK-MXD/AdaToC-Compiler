#ifndef __ADA2C_TYPE_H__
#define __ADA2C_TYPE_H__

#include "SymbolTable.h"
#include <string>
#include <vector>

class Type {
private:
  int kind;

protected:
  enum { INTEGER, STRING, NATURAL, PROCEDURE };

public:
  Type(int _kind) : kind(_kind){};
  ~Type(){};
  virtual std::string dump() = 0;
  bool isInteger() const { return kind == INTEGER; };
  bool isString() const { return kind == STRING; };
  bool isNatural() const { return kind == NATURAL; };
  bool isProcedure() const { return kind == PROCEDURE; };
};

class IntegerType : public Type {
private:
  int size;

public:
  IntegerType(int _size) : Type(Type::INTEGER), size(_size){};
  std::string dump();
};

class StringType : public Type {
private:
  int length;

public:
  StringType(int _length) : Type(Type::STRING), length(_length){};
  std::string dump();
};

class NaturalType : public Type {
private:
  int size;

public:
  NaturalType(int _size) : Type(Type::NATURAL), size(_size){};
  std::string dump();
};

class ProcedureType : public Type {
private:
  std::vector<Type *> paramsType;
  std::vector<SymbolEntry *> paramIds;

public:
  ProcedureType(std::vector<Type *> paramsType)
      : Type(Type::PROCEDURE), paramsType(paramsType){};
  ProcedureType(std::vector<Type *> paramsType,
                std::vector<SymbolEntry *> paramIds)
      : Type(Type::PROCEDURE), paramsType(paramsType), paramIds(paramIds) {};
  std::string dump();
};

class TypeSystem {
private:
  static IntegerType commonInteger;
  static NaturalType commonNatural;
  static IntegerType commonBool;
  static StringType commonString;

public:
  static Type *integerType;
  static Type *naturalType;
  static Type *boolType;
  static Type *stringType;
};

#endif