#include "Type.h"

IntegerType TypeSystem::commonInteger = IntegerType(32);
NaturalType TypeSystem::commonNatural = NaturalType(32);
IntegerType TypeSystem::commonBool = IntegerType(1);

Type* TypeSystem::integerType = &commonInteger;
Type* TypeSystem::boolType = &commonBool;
Type* TypeSystem::naturalType = &commonNatural;