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
    #define DEBUG_YACC(str) std::cerr<<"[YACC INFO]:"<<str<<"\n";
    #else
    #define DEBUG_YACC(str) //
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

%start CompUnit
%token TIC
%token DOTDOT
%token LTLT
%token BOX
%token LTEQ
%token EXPON
%token NE
%token GTGT
%token GE
%token ASSIGN
%token RIGHTSHAFT
%token ABORT
%token ABS
%token ABSTRACT
%token ACCEPT
%token ACCESS
%token ALIASED
%token ALL
%token AND
%token ARRAY
%token AT
%token BEGiN
%token BODY
%token CASE
%token CONSTANT
%token DECLARE
%token DELAY
%token DELTA
%token DIGITS
%token DO
%token ELSE
%token ELSIF
%token END
%token ENTRY
%token EXCEPTION
%token EXIT
%token FOR
%token FUNCTION
%token GENERIC
%token GOTO
%token IF
%token IN
%token IS
%token LIMITED
%token LOOP
%token MOD
%token NEW
%token NOT
%token NuLL
%token OF
%token OR
%token OTHERS
%token OUT
%token PACKAGE
%token PRAGMA
%token PRIVATE
%token PROCEDURE
%token PROTECTED
%token RAISE
%token RANGE
%token RECORD
%token REM
%token RENAMES
%token REQUEUE
%token RETURN
%token REVERSE
%token SELECT
%token SEPARATE
%token SUBTYPE
%token TAGGED
%token TASK
%token TERMINATE
%token THEN
%token TYPE
%token UNTIL
%token USE
%token WHEN
%token WHILE
%token WITH
%token XOR
%token <IntType> DECIMIAL
%token <StrType> Identifier STRINGLITERAL
%token INTEGER STRING NATURAL
%token COLON SEMICOLON LPAREN RPAREN COMMA
%token SINGLEAND SINGLEOR DOTDOT


%type<StmtType> Unit SubprogDecl SubprogBody SubprogSpec FormalPartOpt FormalPart Params Param InitOpt DeclPart DeclItemOrBody DeclItemOrBodys ObjectDecl Decl BlockBody Statements Statement SimpleStmt CompoundStmt NullStmt AssignStmt ReturnStmt ProcedureCall IfStmt CaseStmt LoopStmt Block CondClause CondClauses ElseOpt Range RangeConstrOpt DiscreteRange DiscreteWithRange Choice Choices Alternative Alternatives BasicLoop BlockBody BlockDecl Block 
%type<type> Type
%type<ExprType> Expression Condition CondPart IdOpt WhenOpt


%type<StmtType> RegionStmts RegionStmt ProceRegion Procedure ProDeclStmt VarDeclStmt IfSection IfStmt ElsifStmt ElsifStmts ElseStmt
%type<StmtType> ProceStmts ProceStmt BeginRegion AssignStmt BlankStmt DeclStmts DeclStmt
%type<StmtType> DeclParamList DeclParams ExprStmt
%type<ExprType> LVal Cond Expr PrimaryExpr MulExpr AddExpr RelExpr LAndExpr LOrExpr
%type<ExprType> VarDeclSpecifier InitList DefParams UnaryExpr

%%

Progrom
    : CompUnit {
        ast.setRoot($1);
    }
    ;

CompUnit
    : Unit {
        $$ = $1;
    }
    | CompUnit Unit {
        $$ = new SeqNode($1, $2);
    }
    ;

Unit
    : SubprogDecl {
        $$ = $1;
    }
	| SubprogBody {
        $$ = $1;
    }
    ;

SubprogDecl
    : SubprogSpec SEMICOLON {
        $$ = new ProcedureDecl($1);
    }
    ;

SubprogSpec
    : PROCEDURE Identifier FormalPartOpt {
        DEBUG_YACC("Enter SubprogSpec");
        // Define procedure type.
        Type* proType;
        ParamNode* param = nullptr;
        if($3)
          param = dynamic_cast<ParamNode*>($3);
        std::vector<Type*> paramTypes;
        std::vector<SymbolEntry*> paramIds;
        while (param) {
            SymbolEntry* paramSe = param->getParamSymbol();
            paramTypes.push_back(paramSe->getType());
            paramIds.push_back(paramSe);
            param = dynamic_cast<ParamNode*>(param->getNext());
        }
        proType = new ProcedureType(paramTypes, paramIds);

        // Register procedure name into symbol table.
        SymbolEntry *se = new IdentifierSymbolEntry(proType, $2, identifiers->getLevel());
        identifiers->install($2, se);
        
        // Define SubprogSpec with ast node.
        $$ = new ProcedureSpec(se, $3);
        DEBUG_YACC("Leave SubprogSpec");
    }
    ;

FormalPartOpt
    : %empty { $$ = nullptr; }
	| FormalPart {
        $$ = $1;
    }
	;

FormalPart
    : LPAREN Params RPAREN {
        $$ = $2;
    }
    ;

Params
    : Param {
        $$ = $1;
    }
	| Params SEMICOLON Param {
        $$ = $1;
        $1->setNext($3);
    }
	;

Param : Identifier COLON Type InitOpt {
        SymbolEntry *se = new IdentifierSymbolEntry($3, $1, IdentifierSymbolEntry::Param);
        $$ = new ParamNode(se, $4);
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

InitOpt : %empty { $$ = nullptr; }
	| ASSIGN Expression {
        $$ = new InitOptStmt($2);
    }
	;

SubprogBody
    : SubprogSpec IS {
        // Enter into new scope.
        identifiers = new SymbolTable(identifiers);
    } DeclPart BlockBody END IdOpt SEMICOLON {
        $$ = new ProcedureDef($1, $4, $5);
        // Leave the scope.
        SymbolTable* ScopeTable = identifiers;
        identifiers = identifiers->getPrev();
        delete ScopeTable;
    }
	;

DeclPart :%empty { $$ = nullptr; }
	| DeclItemOrBodys {
        $$ = $1;
    }
	;

Decl
    ObjectDecl {
        $$ = new DeclStmt($1);
    }
    | SubprogDecl {
        $$ = new DeclStmt($1);
    }
    ;

ObjectDecl
    : Identifier COLON Type InitOpt SEMICOLON {
        SymbolEntry *se = new IdentifierSymbolEntry($3, $1, identifiers->getLevel());
        identifiers->install($1, se);
        $$ = new ObjectDeclStmt(se, $4);
    }
    | Identifier COLON CONSTANT Type InitOpt SEMICOLON {
        SymbolEntry *se = new IdentifierSymbolEntry($3, $1, identifiers->getLevel(), true);
        identifiers->install($1, se);
        $$ = new ObjectDeclStmt(se, $5);
    }
	;

DeclItemOrBodys
    : DeclItemOrBody {
        $$ = $1;
    }
	| DeclItemOrBodys DeclItemOrBody {
        $$ = $1;
        $1->setNext($2);
    }
	;

DeclItemOrBody
    : SubprogBody {
        $$ = new DeclItemOrBodyStmt($1);
    }
	| Decl {
        $$ = new DeclItemOrBodyStmt($1);
    }
	;

BlockBody
    : BEGIN Statements {
        $$ = $2;
    }
	;

Statements
    : Statement {
        $$ = $1;
    }
	| Statements Statement {
        $$ = $1;
        $1->setNext($2);
    }
	;

Statement
    : SimpleStmt {
        $$ = new Stmt($1);
    }
	| CompoundStmt {
        $$ = new Stmt($1);
    }
    ;

SimpleStmt
    : NullStmt {
        $$ = $1;
    }
	| AssignStmt {
        $$ = $1;
    }
	| ReturnStmt {
        $$ = $1;
    }
	| ProcedureCall {
        $$ = $1;
    }
    | ExitStmt {
        $$ = $1;
    }
	;

CompoundStmt
    : IfStmt {
        $$ = $1;
    }
	| CaseStmt {
        $$ = $1;
    }
	| LoopStmt {
        $$ = $1;
    }
	| Block {
        $$ = $1;
    }
	;

NullStmt
    : NuLL SEMICOLON {
        $$ = nullptr;
    }
	;

AssignStmt
    : Identifier ASSIGN Expression SEMICOLON {
        SymbolEntry *se = identifiers->lookup($1);
        $$ = new AssignStmt(se, $3);
    }
	;

ReturnStmt
    : RETURN SEMICOLON {
        $$ = new ReturnStmt(nullptr);
    }
	| RETURN Expression SEMICOLON {
        $$ = new ReturnStmt($2);
    }
	;

ProcedureCall
    : Identifier SEMICOLON {
        SymbolEntry* se = identifiers->lookup($1);
        $$ = new CallStmt(se);
    }
	;

ExitStmt
    : EXIT IdOpt WhenOpt SEMICOLON {
        $$ = new ExitStmt($2, $3);
    }
	;

WhenOpt
    : %empty { $$ = nullptr; }
	| WHEN Condition {
        $$ = $2;
    }
	;

IfStmt
    : IF CondClauses ElseOpt END IF SEMICOLON {
        $$ = new IfStmt($2, $3);
    }
	;

CondClauses
    : CondClause {
        $$ = $1;
    }
	| CondClauses ELSIF CondClause {
        $$ = $1;
        $1->setNext($2);
    }
	;

CondClause
    : CondPart Statements {
        $$ = new CondClause($1, $2);
    }
	;

CondPart
    : Condition THEN {
        $$ = $1;
    }
	;

Condition
    : Expression {
        $$ = $1; 
    }
	;

ElseOpt : %empty { $$ = nullptr; }
	| ELSE Statements {
        $$ = $2;
    }
	;

CaseStmt
    : CASE Expression IS Alternatives END CASE SEMICOLON {
        $$ = new CaseStmt($2, $4);
    }
	;

Alternatives
    : %empty { $$ = nullptr; }
	| Alternatives Alternative {
        if($1) {
            $$ = $1;
            $1->setNext($2);
        } else {
            $$ = $2;
        }
    }
	;

Alternative
    : WHEN Choices RIGHTSHAFT Statements {
        $$ = new Alternative($2, $4);
    }
	;

Choices
    : Choice {
        $$ = $1;
    }
	| Choices SINGLEOR Choice {
        $$ = $1;
        $1->setNext($3);
    }
	;

Choice
    : Expression {
        $$ = new Choice($1);
    }
	| DiscreteWithRange {
        $$ = new Choice($1);
    }
	| OTHERS {
        $$ = new Choice(true);
    }
	;

DiscreteWithRange
    : identifier RANGE Range {
        SymbolEntry* se = identifiers->lookup($1);
        $$ = new DiscreteRange($1, $3);
    }
	| Range {
        $$ = new DiscreteRange($1);
    }
	;

LoopStmt
    : LabelOpt Iteration BasicLoop IdOpt SEMICOLON {
        $$ = new LoopStmt($1, $2, $3, $4);
    }
	;

LabelOpt : %empty { $$ = nullptr; }
	| Identifier COLON {
        SymbolEntry *se = new IdentifierSymbolEntry(IdentifierSymbolEntry::IntegerType, $1, identifiers->getLevel());
        identifiers->install($1, se);
        $$ = new LabelOpt();
    }
	;

Iteration : %empty { $$ = nullptr; }
	| WHILE Condition {
        $$ = new Iteration($2);
    }
	| IterPart ReverseOpt DiscreteRange {
        $$ = new Iteration($1, $2, $3);
    }
	;

IterPart
    : FOR Identifier IN {
        SymbolEntry *se = new IdentifierSymbolEntry(IdentifierSymbolEntry::IntegerType, $2, identifiers->getLevel());
        identifiers->install($2, se);
        $$ = new IterPart(se);
    }
	;

ReverseOpt : %empty { $$ = nullptr; }
	| REVERSE {
        $$ = new SignNode(SignNode::REVERSE);
    }
	;

BasicLoop
    : LOOP Statements END LOOP {
        $$ = new BasicLoopStmt($2);
    }
	;

IdOpt
	: %empty { $$ = nullptr; }
	| Identifier {
        SymbolEntry* se = identifiers->lookup($1);
        $$ = new Id(se);
    }
	;

DiscreteRange
    : identifier RangeConstrOpt {
        SymbolEntry* se = identifiers->lookup($1);
        $$ = new DiscreteRange($1, $2);
    }
	| Range {
        $$ = new DiscreteRange($1);
    }
	;

RangeConstrOpt : %empty { $$ = nullptr; }
	| RANGE Range {
        $$ = $2;
    }
	;

Range
    : SimpleExpression DOTDOT SimpleExpression {
        $$ = new Range($1, $3);
    }
    ;

Block
    : LabelOpt BlockDecl BlockBody END IdOpt SEMICOLON {
        $$ = new Block($1, $2, $3);
    }
	;

BlockDecl : %empty { $$ = nullptr; }
	| DECLARE DeclPart {
        $$ = $2;
    }
	;

BlockBody
    : BEGiN Statements {
        $$ = $2;
    }
	;

Expression
    : Relation {

    }
	| Expression Logical Relation {

    }
	| Expression ShortCircuit Relation {

    }
	;

Logical
    : AND {

    }
	| OR {

    }
	| XOR {

    }
	;

ShortCircuit
    : AND THEN
	| OR ELSE
	;

Relation
    : SimpleExpression
	| SimpleExpression Relational SimpleExpression
	| SimpleExpression Membership range
	| SimpleExpression Membership name
	;

Relational
    : '='
	| NE
	| '<'
	| LT_EQ
	| '>'
	| GE
	;

Membership
    : IN
	| NOT IN
	;

SimpleExpression
    : Unary Term {

    }
	| Term {

    }
	| SimpleExpression Adding Term {

    }
	;

Unary
    : '+'
	| '-'
	;

Adding
    : '+'
	| '-'
	| '&'
	;

Term
    : Factor
	| Term Multiplying Factor
	;

Multiplying
    : '*'
	| '/'
	| MOD
	| REM
	;

Factor
    : Primary
	| NOT Primary
	| ABS Primary
	| Primary EXPON Primary
	;

Primary
    : Literal {

    }
	| Identifier {

    }
	| ParenthesizedPrimary {

    }
	;

ParenthesizedPrimary
    : LPAREN expression RPAREN {

    }
	;

Literal
    : DECIMIAL {

    }
	| STRINGLITERAL {
        
    }
	| NuLL {
        $$ = nullptr;
    }
	;











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
    : PROCEDURE Identifier DeclParamList SEMICOLON {
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
    : PROCEDURE Identifier DeclParamList IS DeclStmts BeginRegion Identifier SEMICOLON {
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
        $$ = new ProcedureDef(se, dynamic_cast<DeclStmt*>($3), $6);
        SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
        delete []$2;
    }
    | PROCEDURE Identifier DeclParamList IS BeginRegion Identifier SEMICOLON {
        printLog("enter");
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
        $$ = new ProcedureDef(se, dynamic_cast<DeclStmt*>($3), $5);
        SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
        delete []$2;
        printLog("leave");
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
    : Identifier COLON Type {
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
    : Identifier {
        SymbolEntry* se = identifiers->lookup($1);
        if(se == nullptr){
            printLog("identifier " << (char*)$1 << " is not defined.");
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
    | Identifier LPAREN DefParams RPAREN { 
        SymbolEntry* se = identifiers->lookup($1);
        if(se == nullptr) {
            printLog("Fun: "  << (char*)$1 <<" is not defined.");
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
