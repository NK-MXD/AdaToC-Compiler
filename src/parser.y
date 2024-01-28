%code top{
    #include <cstring>
    #include <stack>
    #include <vector>
    #include <iostream>
    #include <assert.h>
    #include <algorithm>
    #include "parser.h"
    extern int yylineno;
    extern char* yytext;
    extern Ast ast;

    #define DEBUG_SWITCH_TYPE_CHECK 1
    #if DEBUG_SWITCH_TYPE_CHECK
    #define printTyCk(str) std::cerr<<"[error]:"<<str<<"\n";
    #else
    #define printTyCk(str) //
    #endif

    int yylex();
    int yyerror(char const*);
}

%code requires {
    #include "SymbolTable.h"
    #include "Ast.h"
}

%union {
    char* StrType;
    int IntType;
    StmtNode* StmtType;
    ExprNode* ExprType;
    Type* type;
}

%start Program
%token <IntType> DECIMIAL
%token <StrType> ID SYRINGLITERAL
%token INTEGER STRING NATURAL
%token 

%type<StmtType> DeclStmts DeclStmt Procedure ProDeclStmt VarDeclStmt VarDeclSpecifier
%type<StmtType> ProceStmts ProceStmt BeginRegion AssignStmt BlankStmt IfStmt WhileStmt
%type<StmtType> InitList DeclParamList DefParamList DeclParams DefParams
%type<ExprType> Expr PrimaryExpr
%type<ExprType> LVal
%type<type> Type

%precedence THEN
%precedence ELSE
%%

Program
    : DeclStmts {
        ast.setRoot($1);
    }
    ;
DeclStmts
    : DeclStmt {

    }
    | DeclStmts DeclStmt {

    }
    ;
ProceStmts
    : ProceStmt {

    }
    | ProceStmts ProceStmt {

    }
    ;
DeclStmt
    : Procedure { 
        $$ = $1; 
    }
    | ProDeclStmt {
        $$ = $1;
    }
    | VarDeclStmt { 
        $$ = $1; 
    }
    ;
ProceStmt
    : BlankStmt {

    }
    | AssignStmt {

    }
    ;
InitList
    : ASSIGN Expr {

    }
    ;
DeclParams
    : DeclParams COMMA VarDeclSpecifier {

    }
    | VarDeclSpecifier {

    }
    ;
DeclParamList
    : LPAREN DeclParams RPAREN {

    }
    | %empty {$$ = nullptr;}
    ;
DefParams
    : Expr {

    }
    | DefParams COMMA Expr {
        
    }
    ;
DefParamList
    : LPAREN DefParams RPAREN {

    }
    ;
VarDeclStmt
    : VarDeclSpecifier DeclParamList SEMICOLOD{

    }
    ;
VarDeclSpecifier
    : ID COLON Type {

    }
    ;
ProDeclStmt
    : PROCEDURE ID DeclParamList SEMICOLOD {

    }
    ;
Procedure
    : PROCEDURE ID DeclParamList {

    } IS DeclStmts {

    } BeginRegion ID
    ;
BeginRegion
    : BEGIN ProceStmts {

    } END
    | BEGIN END { $$ = $1; }
    ;
BlankStmt
    : NULL SEMICOLOD {
        $$ = $1;
    }
    ;
AssignStmt
    : ID InitList {

    }
    ;

Type
    : INTEGER {

    }
    | STRING {

    }
    | NATURAL {

    }
    ;
LVal
    : ID {

    }
    ;
PrimaryExpr
    : LPAREN Expr LPAREN {

    }
    | LVal {

    }
    | DECIMIAL {

    }
    | STRINGLITERAL {

    }
    ;

%%

int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}
