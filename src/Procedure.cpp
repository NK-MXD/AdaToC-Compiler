#include "Procedure.h"
#include "CppUnit.h"
#include "Type.h"
#include <list>

extern FILE *yyout;

Procedure::Procedure(CppUnit *unit, SymbolEntry *symbol) {
  unit->setMain(this);
  sym_ptr = symbol;
  parent = unit;
}

Procedure::~Procedure() { parent->removeMain(); }

void Procedure::output() const {
  // translate Procedure in ada grammar to cpp grammar
  // eg.
  /* add
  procedure example is
  begin
     null;
  end example;
  */
  /* cpp
  void example {
   ;
  }
  */
  ProcedureType *proType = dynamic_cast<ProcedureType *>(sym_ptr->getType());
  fprintf(yyout, "void %s {\n", sym_ptr->dump().c_str());
  fprintf(yyout, "}\n");
}