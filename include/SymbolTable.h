#ifndef __ADA2C_SYMBOLTALBE_H__
#define __ADA2C_SYMBOLTABLE_H__
#include<Type.h>
#include<map>

class Type;

class SymbolEntry {
private:
    int kind;
protected:
    enum { CONSTANT, VARIABLE, TEMPORARY };
    Type* type;
public:
    SymbolEntry(Type* type, int kind);
    virtual ~SymbolEntry() {};
    bool isConstant() const { return kind == CONSTANT; };
    bool isTemporary() const { return kind == TEMPORARY; };
    bool isVariable() const { return kind == VARIABLE; };
    Type* getType() { return type; };
    virtual std::string dump() = 0;
};


template <typename T>
class ConstantSymbolEntry : public SymbolEntry
{
private:
    T value;
public:
    ConstantSymbolEntry(Type* type, T value);
    virtual ~ConstantSymbolEntry() {};
    T getValue() const { return value; };
    std::string dump();
};

class IdentifierSymbolEntry : public SymbolEntry
{
private:
    enum { GLOBAL, PARAM, LOCAL };
    std::string name;
    int scope;

public:
    IdentifierSymbolEntry(Type* type, std::string name, int scope);
    virtual ~IdentifierSymbolEntry() {};
    std::string dump();
    int getScope() const { return scope; };
};


class TemporarySymbolEntry : public SymbolEntry
{
private:
    int label;
public:
    TemporarySymbolEntry(Type* type, int label);
    virtual ~TemporarySymbolEntry() {};
    std::string dump();
};

class SymbolTable
{
private:
    std::map<std::string, SymbolEntry*> symbolTable;
    SymbolTable* prev;
    int level;
    static int counter;
public:
    SymbolTable();
    SymbolTable(SymbolTable* prev);
    void install(std::string name, SymbolEntry* entry);
    SymbolEntry* lookup(std::string name);
    SymbolTable* getPrev() { return prev; };
    int getLevel() { return level; };
    static int getLabel() { return counter++; };
};

extern SymbolTable* identifiers;
extern SymbolTable* globals;

#endif