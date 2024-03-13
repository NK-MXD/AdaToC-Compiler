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
%token <StrType> ID STRINGLITERAL
%token INTEGER STRING NATURAL
%token ADD SUB MUL DIV EQUAL LESS LESSEQUAL GREATER GREATEREQUAL ASSIGN
%token ARROW COLON SEMICOLON LPAREN RPAREN COMMA
%token SINGLEAND SINGLEOR SINGLEQUOTES ELLIPISIS
%token CONSTANT IF ELSIF ELSE FOR LOOP EXIT CASE WHEN OTHERS OR REVERSE IN
%token IMAGE LAST
%token PROCEDURE IS THEN BEGINLITERAL END DECLARE NULLLITERAL

%type<StmtType> RegionStmts RegionStmt ProceRegion Procedure ProDeclStmt VarDeclStmt IfSection IfStmt ElsifStmt ElsifStmts ElseStmt
%type<StmtType> ProceStmts ProceStmt BeginRegion AssignStmt BlankStmt DeclStmts DeclStmt
%type<StmtType> DeclParamList DeclParams ExprStmt
%type<ExprType> LVal Cond Expr PrimaryExpr MulExpr AddExpr RelExpr LAndExpr LOrExpr
%type<ExprType> VarDeclSpecifier InitList DefParams UnaryExpr
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
    : PROCEDURE ID DeclParamList SEMICOLON {
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
    } IS DeclStmts BeginRegion ID SEMICOLON {
        SymbolEntry *se;
        se = identifiers->lookup($2);
        assert(se != nullptr);
        $$ = new FunctionDef(se, dynamic_cast<DeclStmt*>($6), $7);
        SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
        delete []$2;
    }
    ;

DeclParamList
    : LPAREN DeclParams RPAREN {
        $$ = $2;
    }
    | %empty {$$ = nullptr;}
    ;

DeclParams
    : DeclParams SEMICOLON VarDeclSpecifier {
        $$ = $1;
        $1->setNext($3);
    }
    | VarDeclSpecifier {
        $$ = new DeclStmt(dynamic_cast<Id*>($1));
    }
    ;

VarDeclSpecifier
    : ID COLON Type {
        SymbolEntry *se = new IdentifierSymbolEntry($3, $1, identifiers->getLevel());
        identifiers->install($1, se);
        $$ = new Id(se);
    }
    ;

BeginRegion
    : BEGINLITERAL ProceStmts END{
        $$ = $2;
    }
    | BEGINLITERAL END { $$ = nullptr; }
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
    : VarDeclSpecifier InitList SEMICOLON{
        $$ = new AssignStmt($1, $2);
    }
    ;

InitList
    : ASSIGN Expr {
        $$ = $2; 
    }
    ;

ExprStmt
    : Cond SEMICOLON {
        $$ = new ExprStmt($1);
    }
    ;

ProceStmt
    : BlankStmt {
        $$ = $1;
    }
    | AssignStmt {
        $$ = $1;
    }
    | IfSection {
        $$ = $1;
    }
    | ExprStmt {
        $$ = $1;
    }
    ;

BlankStmt
    : NULLLITERAL SEMICOLON {
        $$ = nullptr;
    }
    ;

AssignStmt
    : LVal InitList SEMICOLON {
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
            printTyCk("identifier " << (char*)$1 << " is not defined.");
        }
        $$ = new Id(se);
        delete []$1;
    }
    ;

PrimaryExpr
    : LPAREN Expr RPAREN {
        $$ = $2;
    }
    | LVal {
        $$ = $1;
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

UnaryExpr
    : 
    PrimaryExpr {$$ = $1;}
    | ID LPAREN DefParams RPAREN { 
        SymbolEntry* se = identifiers->lookup($1);
        if(se == nullptr) {
            printTyCk("Fun: "  << (char*)$1 <<" is not defined.");
        }
        $$ = new CallExpr(se, $3);
    }
    ;

MulExpr
    :
    UnaryExpr {$$ = $1;}
    | MulExpr MUL UnaryExpr {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::integerType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::MUL, $1, $3);
    }
    | MulExpr DIV UnaryExpr {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::integerType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::DIV, $1, $3);
    }
    ;

AddExpr
    :
    MulExpr {$$ = $1;}
    | AddExpr ADD MulExpr {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::integerType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::ADD, $1, $3);
    }
    | AddExpr SUB MulExpr {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::integerType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::SUB, $1, $3);
    }
    ;

RelExpr
    :
    AddExpr {$$ = $1;}
    | RelExpr EQUAL AddExpr {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::integerType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::EQUAL, $1, $3);
    }
    | RelExpr LESS AddExpr {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::integerType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::LESS, $1, $3);
    }
    | RelExpr LESSEQUAL AddExpr {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::integerType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::LESSEQUAL, $1, $3);
    }
    | RelExpr GREATER AddExpr {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::integerType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::GREATER, $1, $3);
    }
    | RelExpr GREATEREQUAL AddExpr {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::integerType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::GREATEREQUAL, $1, $3);
    }
    ;

LAndExpr
    :
    RelExpr {$$ = $1;}
    | LAndExpr SINGLEAND RelExpr {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::integerType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::AND, $1, $3);
    }
    ;

LOrExpr
    :
    LAndExpr {$$ = $1;}
    | LOrExpr SINGLEOR LAndExpr {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::integerType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::OR, $1, $3);
    }
    ;

Expr
    :
    AddExpr {$$ = $1;}
    ;

Cond
    :
    LOrExpr {$$ = $1;}
    ;

DefParams
    : Cond {
        $$ = $1;
    }
    | DefParams COMMA Cond {
        $$ = $1;
        $$->setNext($3);
    }
    ;

IfSection
    : IfStmt END IF {
        $$ = new IfSectionStmt($1);
    }
    | IfStmt ElsifStmts END IF {
        $$ = new IfSectionStmt($1, $2, nullptr);
    }
    | IfStmt ElsifStmts ElseStmt END IF {
        $$ = new IfSectionStmt($1, $2, $3);
    }
    | IfStmt ElseStmt END IF {
        $$ = new IfSectionStmt($1, nullptr, $2);
    }
    ;

IfStmt
    : IF Cond THEN ProceStmts{
        $$ = new IfStmt($2, $4);
    }
    ;

ElsifStmt
    : ELSIF Cond THEN ProceStmts{
        $$ = new IfStmt($2, $4, true);
    }
    ;

ElsifStmts
    : ElsifStmt { $$ = $1; } 
    | ElsifStmts ElsifStmt {
        $$ = new SeqNode($1, $2);
    }
    ;

ElseStmt
    : ELSE ProceStmts{
        $$ = new IfStmt($2);
    }
    ;

%%

int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}
