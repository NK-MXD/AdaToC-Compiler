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
    OpSignNode* SignType;
    Type* type;
}

%start Program
%token TIC
%token DOTDOT
%token LTLT
%token BOX
%token LTEQ
%token GTEQ
%token EXPON
%token NE
%token GTGT
%token GE
%token LE
%token EQ
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
%token MUL
%token DIV
%token MOD
%token NEW
%token NOT
%token SUB
%token ADD
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
%token SINGLEAND SINGLEOR

%type<StmtType> CompUnit Unit SubprogDecl SubprogBody SubprogSpec FormalPartOpt FormalPart Params Param InitOpt DeclPart DeclItemOrBody DeclItemOrBodys ObjectDecl Decl Statements Statement SimpleStmt CompoundStmt NullStmt AssignStmt ReturnStmt ProcedureCall ExitStmt IfStmt CaseStmt LoopStmt Iteration IterPart LabelOpt Block CondClause CondClauses ElseOpt Range RangeConstrOpt DiscreteRange DiscreteWithRange Choice Choices Alternative Alternatives BasicLoop BlockBody BlockDecl
%type<type> Type
%type<ExprType> Expression Condition CondPart IdOpt WhenOpt Literal ParenthesizedPrimary Primary Factor Term SimpleExpression Relation  
%type<SignType> ReverseOpt Multiplying Adding Unary Membership Relational ShortCircuit Logical

%%

Program
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
        $$ = new ProcedureDecl(dynamic_cast<SubprogDecl*>($1));
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
            param = param->getNext();
        }
        proType = new ProcedureType(paramTypes, paramIds);

        // Register procedure name into symbol table.
        SymbolEntry *se = new IdentifierSymbolEntry(proType, $2, identifiers->getLevel());
        identifiers->install($2, se);
        
        // Define SubprogSpec with ast node.
        $$ = new ProcedureSpec(se, param);
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
        $$ = new ParamNode(se, dynamic_cast<InitOptStmt>($4));
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
        $$ = new ProcedureDef(dynamic_cast<SubprogSpec*>($1), dynamic_cast<DeclItemOrBodyStmt*>($4), $5);
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
    :
    ObjectDecl {
        $$ = new DeclStmt(dynamic_cast<ObjectDeclStmt*>($1));
    }
    | SubprogDecl {
        $$ = new DeclStmt(dynamic_cast<SubprogDecl*>($1));
    }
    ;

ObjectDecl
    : Identifier COLON Type InitOpt SEMICOLON {
        SymbolEntry *se = new IdentifierSymbolEntry($3, $1, identifiers->getLevel());
        identifiers->install($1, se);
        $$ = new ObjectDeclStmt(se, dynamic_cast<InitOptStmt*>($4));
    }
    | Identifier COLON CONSTANT Type InitOpt SEMICOLON {
        SymbolEntry *se = new IdentifierSymbolEntry($4, $1, identifiers->getLevel(), true);
        identifiers->install($1, se);
        $$ = new ObjectDeclStmt(se, dynamic_cast<InitOptStmt*>($5));
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
        $$ = new DeclItemOrBodyStmt(dynamic_cast<ProcedureDef*>($1));
    }
	| Decl {
        $$ = new DeclItemOrBodyStmt(dynamic_cast<DeclStmt*>($1));
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
        if(!se || !se->getType()->isProcedure()) {
            std::cerr << "Can't not get Procedure type SymbolEntry!\n";
        }
        $$ = new CallStmt(se);
    }
	;

ExitStmt
    : EXIT IdOpt WhenOpt SEMICOLON {
        $$ = new ExitStmt($3);
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
        $$ = new IfStmt(dynamic_cast<CondClause*>($2), dynamic_cast<Stmt*>($3));
    }
	;

CondClauses
    : CondClause {
        $$ = $1;
    }
	| CondClauses ELSIF CondClause {
        $$ = $1;
        $1->setNext($3);
    }
	;

CondClause
    : CondPart Statements {
        $$ = new CondClause($1, dynamic_cast<Stmt*>($2));
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
        $$ = new CaseStmt($2, dynamic_cast<Alternative*>($4));
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
        $$ = new Alternative(dynamic_cast<Choice*>($2), dynamic_cast<Stmt*>($4));
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
        $$ = new Choice(dynamic_cast<DiscreteRange*>($1));
    }
	| OTHERS {
        $$ = new Choice(true);
    }
	;

DiscreteWithRange
    : Identifier RANGE Range {
        Type* type = dynamic_cast<Range*>($3)->getType();
        SymbolEntry* se = new IdentifierSymbolEntry(type, $1);
        $$ = new DiscreteRange($1, dynamic_cast<Range*>($3));
    }
	| Range {
        $$ = new DiscreteRange(dynamic_cast<Range*>($1));
    }
	;

LoopStmt
    : LabelOpt Iteration BasicLoop IdOpt SEMICOLON {
        $$ = new LoopStmt(dynamic_cast<LabelOpt*>($1), dynamic_cast<Iteration*>($2), dynamic_cast<BasicLoopStmt*>($3));
    }
	;

LabelOpt : %empty { $$ = nullptr; }
	| Identifier COLON {
        SymbolEntry *se = new IdentifierSymbolEntry(IdentifierSymbolEntry::IntegerType, $1, identifiers->getLevel());
        identifiers->install($1, se);
        $$ = new LabelOpt(se);
    }
	;

Iteration : %empty { $$ = nullptr; }
	| WHILE Condition {
        $$ = new Iteration($2);
    }
	| IterPart ReverseOpt DiscreteRange {
        $$ = new Iteration(dynamic_cast<IterPart*>($1), $2, dynamic_cast<DiscreteRange*>($3));
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
        $$ = new OpSignNode(OpSignNode::REVERSE);
    }
	;

BasicLoop
    : LOOP Statements END LOOP {
        $$ = new BasicLoopStmt(dynamic_cast<Stmt*>($2));
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
    : Identifier RangeConstrOpt {
        SymbolEntry *se = new IdentifierSymbolEntry(IdentifierSymbolEntry::IntegerType, $2, identifiers->getLevel());
        identifiers->install($2, se);
        $$ = new DiscreteRange($1, dynamic_cast<Range*>($2));
    }
	| Range {
        $$ = new DiscreteRange(dynamic_cast<Range*>($1));
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
        $$ = new Block(dynamic_cast<LabelOpt*>($1), dynamic_cast<DeclItemOrBody*>($2), dynamic_cast<Stmt*>($3));
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
        $$ = $1;
    }
	| Expression Logical Relation {
        $$ = new BinaryExpr($1, $3, $2);
    }
	| Expression ShortCircuit Relation {
        $$ = new BinaryExpr($1, $3, $2);
    }
	;

Logical
    : AND {
        $$ = new OpSignNode(OpSignNode::AND);
    }
	| OR {
        $$ = new OpSignNode(OpSignNode::OR);
    }
	| XOR {
        $$ = new OpSignNode(OpSignNode::XOR);
    }
	;

ShortCircuit
    : AND THEN {
        $$ = new OpSignNode(OpSignNode::ANDTHEN);
    }
	| OR ELSE {
        $$ = new OpSignNode(OpSignNode::ORELSE);
    }
	;

Relation
    : SimpleExpression {
        $$ = $1;
    }
	| SimpleExpression Relational SimpleExpression {
        $$ = new BinaryExpr($1, $3, $2);
    }
	| SimpleExpression Membership Range {
        $$ = new BinaryExpr($1, dynamic_cast<Range*>($3), $2);
    }
	| SimpleExpression Membership Identifier {
        $$ = new BinaryExpr($1, $3, $2);
    }
	;

Relational
    : EQ {
        $$ = new OpSignNode(OpSignNode::EQ);
    }
	| NE {
        $$ = new OpSignNode(OpSignNode::NE);
    }
	| LE {
        $$ = new OpSignNode(OpSignNode::LE);
    }
	| LTEQ {
        $$ = new OpSignNode(OpSignNode::LTEQ);
    }
	| GE {
        $$ = new OpSignNode(OpSignNode::GE);
    }
 	| GTEQ {
        $$ = new OpSignNode(OpSignNode::GTEQ);
    }
	;

Membership
    : IN {
        $$ = new OpSignNode(OpSignNode::IN);
    }
	| NOT IN {
        $$ = new OpSignNode(OpSignNode::NOTIN);
    }
	;

SimpleExpression
    : Unary Term {
        $$ = new BinaryExpr($2, $1);
    }
	| Term {
        $$ = $1;
    }
	| SimpleExpression Adding Term {
        $$ = new BinaryExpr($1, $3, $2);
    }
	;

Unary
    : ADD {
        $$ = new OpSignNode(OpSignNode::ADD);
    }
	| SUB {
        $$ = new OpSignNode(OpSignNode::SUB);
    }
	;

Adding
    : ADD {
        $$ = new OpSignNode(OpSignNode::ADD);
    }
	| SUB {
        $$ = new OpSignNode(OpSignNode::SUB);
    }
	| SINGLEAND {
        $$ = new OpSignNode(OpSignNode::SINGLEAND);
    }
	;

Term
    : Factor {
        $$ = $1;
    }
	| Term Multiplying Factor {
        $$ = new BinaryExpr($1, $3, $2);
    }
	;

Multiplying
    : MUL {
        $$ = new OpSignNode(OpSignNode::MUL);
    }
	| DIV {
        $$ = new OpSignNode(OpSignNode::DIV);
    }
	| MOD {
        $$ = new OpSignNode(OpSignNode::MOD);
    }
	| REM {
        $$ = new OpSignNode(OpSignNode::REM);
    }
	;

Factor
    : Primary {
        $$ = $1;
    }
	| NOT Primary {
        $$ = new FactorExpr($2, FactorExpr::NOT);
    }
	| ABS Primary {
        $$ = new FactorExpr($2, FactorExpr::ABS);
    }
	| Primary EXPON Primary {
        $$ = new BinaryExpr($1, $3, new OpSignNode(OpSignNode::EXPON));
    }
	;

Primary
    : Literal {
        $$ = $1;
    }
	| Identifier {
        SymbolEntry* se = identifiers->lookup($1);
        $$ = new Id(se);
    }
	| ParenthesizedPrimary {
        $$ = $1;
    }
	;

ParenthesizedPrimary
    : LPAREN Expression RPAREN {
        $$ = $2;
    }
	;

Literal
    : DECIMIAL {
        SymbolEntry* se = new ConstantSymbolEntry(TypeSystem::IntegerType, $1);
        $$ = new Constant(se);
    }
	| STRINGLITERAL {
        SymbolEntry* se = new ConstantSymbolEntry(TypeSystem::StringType, $1);
        $$ = new Constant(se);
    }
	| NuLL {
        $$ = nullptr;
    }
	;
%%

int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}
