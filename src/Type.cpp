#include "Type.h"

IntegerType TypeSystem::commonInteger = IntegerType(32);
NaturalType TypeSystem::commonNatural = NaturalType(32);
BooleanType TypeSystem::commonBool = BooleanType(1);
StringType TypeSystem::commonString = StringType(16);

Type* TypeSystem::integerType = &commonInteger;
Type* TypeSystem::boolType = &commonBool;
Type* TypeSystem::naturalType = &commonNatural;
Type* TypeSystem::stringType = &commonString;

std::string IntegerType::dump() {
    return "Integer";
}

std::string IntegerType::toCppStr() {
    return "AdaInteger";
}

std::string BooleanType::dump() {
    return "Boolean";
}

std::string BooleanType::toCppStr() {
    return "bool";
}

std::string StringType::dump() {
    return "String";
}

std::string StringType::toCppStr() {
    return "AdaString";
}

std::string NaturalType::dump() {
    return "Natural";
}

std::string NaturalType::toCppStr() {
    AdaNatural::getInstance();
    return "AdaNatural";
}

std::string ProcedureType::dump() {
    return "Procedure";
}

std::string ProcedureType::toCppStr() {
    return "Procedure";
}

std::string FunctionType::dump() {
    return "Function";
}

std::string FunctionType::toCppStr() {
    return "Function";
}