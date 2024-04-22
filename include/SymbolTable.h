#ifndef __ADA2C_SYMBOLTALBE_H__
#define __ADA2C_SYMBOLTALBE_H__

#include "Type.h"
#include <map>

class SymbolEntry {
private:
  int kind;

protected:
  enum { CONSTANT, VARIABLE, TEMPORARY };

public:
  SymbolEntry(int kind);
  virtual ~SymbolEntry(){};
  bool isConstant() const { return kind == CONSTANT; };
  bool isTemporary() const { return kind == TEMPORARY; };
  bool isVariable() const { return kind == VARIABLE; };
  virtual std::string dump() = 0;
  virtual Type* getType() = 0;
};

class ConstantSymbolEntry : public SymbolEntry {
private:
  int value;
  std::string str;
  Type* type;
  bool bvalue;

public:
  ConstantSymbolEntry(Type *type, int value);
  ConstantSymbolEntry(Type *type, bool bvalue);
  ConstantSymbolEntry(Type *type, char* str);
  virtual ~ConstantSymbolEntry(){};
  int getValue() const { return value; };
  Type *getType() { return type; };
  void setType(Type* _type) { type = _type; };
  std::string dump();
};

class IdentifierSymbolEntry : public SymbolEntry {
private:
  std::string name;
  int scope;
  bool isConst;
  Type* type;

public:
  enum { GLOBAL, PARAM, LOCAL };

public:
  IdentifierSymbolEntry(std::string name, int scope);
  IdentifierSymbolEntry(Type *type, std::string name, int scope, bool isConst = false);
  virtual ~IdentifierSymbolEntry(){};
  Type *getType() { return type; };
  std::string dump();
  void setType(Type* _type) { type = _type; };
  void setConst() { isConst = true; };
  bool getConst() { return isConst; };
  int getScope() const { return scope; };
};

class TemporarySymbolEntry : public SymbolEntry {
private:
  int label;
  Type* type;

public:
  TemporarySymbolEntry(Type *type, int label);
  virtual ~TemporarySymbolEntry(){};
  Type *getType() { return type; };
  std::string dump();
};

class SymbolTable {
private:
  std::map<std::string, SymbolEntry *> symbolTable;
  SymbolTable *prev;
  int level;
  static int counter;

public:
  SymbolTable();
  SymbolTable(SymbolTable *prev);
  void install(std::string name, SymbolEntry *entry);
  SymbolEntry *lookup(std::string name);
  SymbolTable *getPrev() { return prev; };
  int getLevel() { return level; };
  static int getLabel() { return counter++; };
};

extern SymbolTable *identifiers;
extern SymbolTable *globals;

#endif