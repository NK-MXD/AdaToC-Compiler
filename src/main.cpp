#include <iostream>
#include <string.h>
#include <unistd.h>
#include "common.h"
#include "Ast.h"

extern FILE *yyin;
extern FILE *yyout;

int yyparse();
Ast ast;

char outfile[256];
bool dump_token = false;
dump_type_t dump_type = ASM;

int main(int argc, char *argv[])
{
    int opt;
    while ((opt = getopt(argc, argv, "to:")) != -1)
    {
        switch (opt)
        {
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
        default:
            fprintf(stderr, "Usage: %s [-o outfile] infile\n", argv[0]);
            exit(EXIT_FAILURE);
            break;
        }
    }
    if (optind >= argc)
    {
        fprintf(stderr, "no input file\n");
        exit(EXIT_FAILURE);
    }
    if (!(yyin = fopen(argv[optind], "r")))
    {
        fprintf(stderr, "%s: No such file or directory\nno input file\n", argv[optind]);
        exit(EXIT_FAILURE);
    }
    if (!(yyout = fopen(outfile, "w")))
    {
        fprintf(stderr, "%s: fail to open output file\n", outfile);
        exit(EXIT_FAILURE);
    }
    yyparse();
    if(dump_type == AST)
        ast.dump();
    return 0;
}