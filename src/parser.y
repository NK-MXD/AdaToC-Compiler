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
%token ADD SUB MUL DIV EQUAL LESS LESSEQUAL GREATER GREATEREQUAL ASSIGN
%token ARROW COLON SEMICOLON LPAREN RPAREN COMMA
%token SINGLEAND SINGLEOR SINGLEQUOTES ELLIPISIS
%token CONSTANT IF ELSIF ELSE FOR LOOP EXIT CASE WHEN OTHERS OR REVERSE IN
%token IMAGE LAST
%token PROCEDURE IS THEN BEGIN END DECLARE NULL

%type<StmtType> RegionStmts RegionStmt ProceRegion Procedure ProDeclStmt VarDeclStmt VarDeclSpecifier
%type<StmtType> ProceStmts ProceStmt BeginRegion AssignStmt BlankStmt ProStmt
%type<StmtType> InitList DeclParamList DefParamList DeclParams DefParams
%type<ExprType> Expr PrimaryExpr
%type<ExprType> LVal
%type<type> Type

%%

Program
    : RegionStmts {
        ast.setRoot($1);
    }
    ;

RegionStmts
    : RegionStmt {
        $$ = $1;
    }
    | RegionStmts RegionStmt {
        $$ = new SeqNode($1, $2);
    }
    ;

RegionStmt
    : ProceRegion {
        $$ = $1;
    }
    ;

ProceRegion
    : ProDeclStmt {
        $$ = $1;
    }
    | Procedure {
        $$ = $1;
    }
    ;

ProDeclStmt
    : PROCEDURE ID DeclParamList SEMICOLOD {
        Type *proType;
        DeclStmt* temp = dynamic_cast<DeclStmt*>($3);
        std::vector<Type*> paramTypes;
        while (temp) {
            paramTypes.push_back(temp->getId()->getSymbolEntry()->getType());
            temp = dynamic_cast<DeclStmt*>(temp->getNext());
        }
        proType = new ProcedureType(paramTypes);
        SymbolEntry *se = new IdentifierSymbolEntry(proType, $2, identifiers->getLevel());
        identifiers->install($2, se);
        identifiers = new SymbolTable(identifiers);
    }
    ;

Procedure
    : PROCEDURE ID DeclParamList {
        Type *proType;
        DeclStmt* temp = dynamic_cast<DeclStmt*>($3);
        std::vector<Type*> paramTypes;
        std::vector<SymbolEntry*> paramIds;
        while (temp) {
            paramTypes.push_back(temp->getId()->getSymbolEntry()->getType());
            paramIds.push_back(temp->getId()->getSymbolEntry());
            temp = dynamic_cast<DeclStmt*>(temp->getNext());
        }
        proType = new ProcedureType(paramTypes, paramIds);
        SymbolEntry *se = new IdentifierSymbolEntry(proType, $2, identifiers->getLevel());
        identifiers->install($2, se);
        identifiers = new SymbolTable(identifiers);
    } IS DeclStmts BeginRegion {
        SymbolEntry *se;
        se = identifiers->lookup($2);
        assert(se != nullptr);
        $$ = new FunctionDef(se, $6, $7);
        SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
        delete []$2;
    } ID SEMICOLOD
    ;

DeclParamList
    : LPAREN DeclParams RPAREN {
        $$ = $2;
    }
    | %empty {$$ = nullptr;}
    ;

DeclParams
    : DeclParams SEMICOLOD VarDeclSpecifier {
        $$ = $1;
        $1->setNext($3);
    }
    | VarDeclSpecifier {
        $$ = $1;
    }
    ;

VarDeclSpecifier
    : ID COLON Type {
        SymbolEntry *se = new IdentifierSymbolEntry($1, $3, identifiers->getLevel());
        identifiers->install($1, se);
        $$ = new DeclStmt(new Id(se));
        delete []$1;
    }
    ;

BeginRegion
    : BEGIN ProceStmts {
        $$ = $2;
    } END
    | BEGIN END { $$ = nullptr; }
    ;

DeclStmts
    : DeclStmt {
        $$ = $1;
    }
    | DeclStmts DeclStmt {
        $$ = new SeqNode($1, $2);
    }
    ;

ProceStmts
    : ProceStmt {
        $$ = $1;
    }
    | ProceStmts ProceStmt {
        $$ = new SeqNode($1, $2);
    }
    ;

DeclStmt
    : ProceRegion {
        $$ = $1;
    }
    | VarDeclStmt { 
        $$ = $1; 
    }
    ;

VarDeclStmt
    : VarDeclSpecifier InitList SEMICOLOD{
        $$ = new AssignStmt($1, $2);
    }
    ;

InitList
    : ASSIGN Expr {
        $$ = $1; 
    }
    ;

ProceStmt
    : BlankStmt {
        $$ = $1;
    }
    | AssignStmt {
        $$ = $1;
    }
    | ProStmt {
        $$ = $1;
    }
    ;

ProStmt
    : ID LPAREN DefParams LPAREN SEMICOLOD {
        SymbolEntry* se = identifiers->lookup($1);
        if(se == nullptr) {
            printTyCk("Fun: "  << (char*)$1 <<" is not defined.");
        }
        $$ = new CallExpr(se, $3);
    }
    ;

DefParams
    : Expr {
        $$ = $1;
    }
    | DefParams COMMA Expr {
        $$ = new SeqNode($1, $2);
    }
    ;


BlankStmt
    : NULL SEMICOLOD {
        $$ = $1;
    }
    ;

AssignStmt
    : ID InitList SEMICOLOD {
        $$ = new AssignStmt($1, $2);
    }
    ;

Type
    : INTEGER {
        $$ = TypeSystem::integerType;
    }
    | STRING {
        $$ = TypeSystem::stringType;
    }
    | NATURAL {
        $$ = TypeSystem::naturalType;
    }
    ;

LVal
    : ID {
        SymbolEntry* se = identifiers->lookup($1);
        if(se == nullptr){
            fprintf("identifier " << (char*)$1 << " is not defined.");
        }
        $$ = new Id(se);
        delete []$1;
    }
    ;

PrimaryExpr
    : LPAREN Expr LPAREN {
        $$ = $2;
    }
    | LVal {
        SymbolEntry *se;
        se = identifiers->lookup($1);
        if(se == nullptr) {
            fprintf(stderr, "identifier \"%s\" is undefined\n", (char*)$1);
            delete [](char*)$1;
            assert(se != nullptr);
        }
        $$ = new Id(se);
        delete []$1;
    }
    | DECIMIAL {
        ConstantSymbolEntry *se = new ConstantSymbolEntry(TypeSystem::integerType, $1);
        $$ = new Constant(se);
    }
    | STRINGLITERAL {
        SymbolEntry* se;
        se = globals->lookup(std::string($1));
        if (se == nullptr) {
            Type* type = new StringType(strlen($1));
            se = new ConstantSymbolEntry(type, std::string($1));
            globals->install(std::string($1), se);
        }
        ExprNode* expr = new ExprNode(se);
        $$ = expr;
    }
    ;

%%

int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}
