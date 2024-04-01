#include <SymbolTable.h>
#include <sstream>

SymbolEntry::SymbolEntry(Type *type, int kind) {
  this->type = type;
  this->kind = kind;
}

ConstantSymbolEntry::ConstantSymbolEntry(Type *type, int value)
    : SymbolEntry(type, SymbolEntry::CONSTANT) {
  this->value = value;
}

ConstantSymbolEntry::ConstantSymbolEntry(Type *type, std::string str)
    : SymbolEntry(type, SymbolEntry::CONSTANT) {
  this->str = str;
}

std::string ConstantSymbolEntry::dump() {
  std::ostringstream buffer;
  buffer << value;
  return buffer.str();
}

IdentifierSymbolEntry::IdentifierSymbolEntry(Type *type, std::string name, 
                                             int scope, bool isConst)
    : SymbolEntry(type, SymbolEntry::VARIABLE), name(name), isConst(isConst) {
  this->scope = scope;
}

std::string IdentifierSymbolEntry::dump() { return name; }

TemporarySymbolEntry::TemporarySymbolEntry(Type *type, int label)
    : SymbolEntry(type, SymbolEntry::TEMPORARY) {
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

SymbolEntry *SymbolTable::lookup(std::string name) { return nullptr; }

// install the entry into current symbol table.
void SymbolTable::install(std::string name, SymbolEntry *entry) {
  symbolTable[name] = entry;
}

int SymbolTable::counter = 0;
static SymbolTable t;
SymbolTable *identifiers = &t;
SymbolTable *globals = &t;