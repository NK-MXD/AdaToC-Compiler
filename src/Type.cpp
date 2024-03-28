#include "Type.h"

IntegerType TypeSystem::commonInteger = IntegerType(32);
NaturalType TypeSystem::commonNatural = NaturalType(32);
IntegerType TypeSystem::commonBool = IntegerType(1);
StringType TypeSystem::commonString = StringType(16);

Type* TypeSystem::integerType = &commonInteger;
Type* TypeSystem::boolType = &commonBool;
Type* TypeSystem::naturalType = &commonNatural;
Type* TypeSystem::stringType = &commonString;

std::string IntegerType::dump() {
    return "Integer";
}

std::string StringType::dump() {
    return "String";
}

std::string NaturalType::dump() {
    return "Natural";
}

std::string ProcedureType::dump() {
    return "Procedure";
}

std::string FunctionType::dump() {
    return "Function";
}