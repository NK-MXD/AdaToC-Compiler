#include <SymbolTable.h>
#include <iostream>
#include <sstream>

SymbolEntry::SymbolEntry(int kind) { this->kind = kind; }

ConstantSymbolEntry::ConstantSymbolEntry(Type *type, int value)
    : SymbolEntry(SymbolEntry::CONSTANT), type(type) {
  this->value = value;
}

ConstantSymbolEntry::ConstantSymbolEntry(Type *type, bool bvalue)
    : SymbolEntry(SymbolEntry::CONSTANT), type(type) {
  this->bvalue = bvalue;
}

ConstantSymbolEntry::ConstantSymbolEntry(Type *type, char *str)
    : SymbolEntry(SymbolEntry::CONSTANT), type(type) {
  this->str = std::string(str);
}

std::string ConstantSymbolEntry::dump() {
  if (type->isInteger()) {
    std::ostringstream buffer;
    buffer << value;
    return buffer.str();
  } else if (type->isString()) {
    std::string res = "\"" + str + "\"";
    return res;
  } else if (type->isBoolean()) {
    if (bvalue)
      return std::string("true");
    else
      return std::string("false");
  } else {
    return std::string("");
  }
}

IdentifierSymbolEntry::IdentifierSymbolEntry(std::string name, int scope)
    : SymbolEntry(SymbolEntry::VARIABLE), name(name) {
  this->scope = scope;
}

IdentifierSymbolEntry::IdentifierSymbolEntry(Type *type, std::string name,
                                             int scope, bool isConst)
    : SymbolEntry(SymbolEntry::VARIABLE), type(type), name(name),
      isConst(isConst) {
  this->scope = scope;
}

std::string IdentifierSymbolEntry::dump() { return name; }

TemporarySymbolEntry::TemporarySymbolEntry(Type *type, int label)
    : SymbolEntry(SymbolEntry::TEMPORARY), type(type) {
  this->label = label;
}

std::string TemporarySymbolEntry::dump() {
  std::ostringstream buffer;
  buffer << "t" << label;
  return buffer.str();
}

SymbolTable::SymbolTable() {
  prev = nullptr;
  level = 0;
}

SymbolTable::SymbolTable(SymbolTable *prev) {
  this->prev = prev;
  this->level = prev->level + 1;
}

SymbolEntry *SymbolTable::lookup(std::string name) {
  SymbolTable *table = this;
  while (table != nullptr)
    if (table->symbolTable.find(name) != table->symbolTable.end()) {
      return table->symbolTable[name];
    } else {
      table = table->prev;
    }
  return nullptr;
}

// install the entry into current symbol table.
void SymbolTable::install(std::string name, SymbolEntry *entry) {
  if (this->symbolTable.find(name) != this->symbolTable.end()) {
    std::cerr << "Install SymbolEntry into SymbolTable Error!\n";
  } else {
    symbolTable[name] = entry;
  }
}

int SymbolTable::counter = 0;
static SymbolTable t;
SymbolTable *identifiers = &t;
SymbolTable *globals = &t;