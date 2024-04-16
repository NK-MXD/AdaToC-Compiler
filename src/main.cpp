#include "Ast.h"
#include "CppUnit.h"
#include "common.h"
#include <iostream>
#include <string.h>
#include <unistd.h>

extern FILE *yyin;
extern FILE *yyout;

int yyparse();
Ast ast;
CppUnit unit;

char outfile[256] = "a.out";
bool dump_token = false;
dump_type_t dump_type = CPP;

int main(int argc, char *argv[]) {
  int opt;
  while ((opt = getopt(argc, argv, "acto:")) != -1) {
    switch (opt) {
    case 'o':
      strcpy(outfile, optarg);
      break;
    case 'a':
      strcpy(outfile, "a.ast");
      dump_type = AST;
      break;
    case 't':
      strcpy(outfile, "a.toks");
      dump_type = TOKENS;
      dump_token = true;
      break;
    case 'c':
      strcpy(outfile, "a.cpp");
      dump_type = CPP;
      break;
    default:
      fprintf(stderr, "Usage: %s [-o outfile] infile\n", argv[0]);
      exit(EXIT_FAILURE);
      break;
    }
  }
  if (optind >= argc) {
    fprintf(stderr, "no input file\n");
    exit(EXIT_FAILURE);
  }
  if (!(yyin = fopen(argv[optind], "r"))) {
    fprintf(stderr, "%s: No such file or directory\nno input file\n",
            argv[optind]);
    exit(EXIT_FAILURE);
  }
  if (!(yyout = fopen(outfile, "w"))) {
    fprintf(stderr, "%s: fail to open output file\n", outfile);
    exit(EXIT_FAILURE);
  }
  yyparse();
  if (dump_type == AST)
    ast.dump();

  if (dump_type == CPP) {
    ast.genCppCode(&unit);
    unit.output();
  }
  return 0;
}