%option noyywrap
%option yylineno
%{
    #define YY_NO_UNPUT
    #define YY_NO_INPUT
    #define ONLY_FOR_LEX
    // #include "parser.h"
    #include <ostream>
    #include <fstream>
    #include <iostream>
    using namespace std;
    extern FILE *yyin; 
    extern FILE *yyout;
    extern bool dump_token;
    int offsets = 0;
    int newoffsets = 0;

    void DUMP_TOKEN(std::string s){
        std::string DEBUG_INFO = "[TOKEN]: \t" + s + "\n";
        fputs(DEBUG_INFO.c_str(), yyout);
    }

    void update_loc(){
        offsets = newoffsets;
        newoffsets = offsets + strlen(yytext);
    }
    #define YY_USER_ACTION update_loc();  
    
%}

DECIMIAL ([1-9][0-9]*|0)
ID [[:alpha:]_][[:alpha:][:digit:]_]*
STRINGLITERAL \".*\"
EOL (\r\n|\n|\r)
WHITE [\t ]

LINECOMMENT --[^\n]*

%%
"+" {
    if(dump_token) 
        DUMP_TOKEN("ADD\t+");
    return ADD;
}
"-" {
    if(dump_token) 
        DUMP_TOKEN("SUB\t-");
    return SUB;
}
"*" {
    if(dump_token) 
        DUMP_TOKEN("MUL\t*");
    return MUL;
}
"/" {
    if(dump_token) 
        DUMP_TOKEN("DIV\t/");
    return DIV;
}
"=" {
    if(dump_token) 
        DUMP_TOKEN("EQUAL\t=");
    return EQUAL;
}
"<" {
    if(dump_token) 
        DUMP_TOKEN("LESS\t<");
    return LESS;
}
"<=" {
    if(dump_token) 
        DUMP_TOKEN("LESSEQUAL\t<=");
    return LESSEQUAL;
}
">" {
    if(dump_token) 
        DUMP_TOKEN("GREATER\t>");
    return GREATER;
}
">=" {
    if(dump_token) 
        DUMP_TOKEN("GREATEREQUAL\t>=");
    return GREATEREQUAL;
}
":=" {
    if(dump_token) 
        DUMP_TOKEN("ASSIGN\t:=");
    return ASSIGN;
}
"=>" {
    if(dump_token) 
        DUMP_TOKEN("ARROW\t=>");
    return ARROW;
}
":" {
    if(dump_token) 
        DUMP_TOKEN("COLON\t:");
    return COLON;
}
";" {
    if(dump_token) 
        DUMP_TOKEN("SEMICOLON\t;");
    return SEMICOLON;
}
"(" {
    if(dump_token) 
        DUMP_TOKEN("LPAREN\t(");
    return LPAREN;
}
")" {
    if(dump_token) 
        DUMP_TOKEN("RPAREN\t)");
    return RPAREN;
}
"," {
    if(dump_token) 
        DUMP_TOKEN("COMMA\t,");
    return COMMA;
}
"&" {
    if(dump_token) 
        DUMP_TOKEN("SINGLEAND\t&");
    return SINGLEAND;
}
"|" {
    if(dump_token) 
        DUMP_TOKEN("SINGLEOR\t|");
    return SINGLEOR;
}
"'" {
    if(dump_token) 
        DUMP_TOKEN("SINGLEQUOTESt\t'");
    return SINGLEQUOTES;
}
".." {
    if(dump_token) 
        DUMP_TOKEN("ELLIPISIS\t..");
    return COMMA;
}
"constant" {
    if(dump_token) 
        DUMP_TOKEN("CONSTANT\tconstant");
    return CONSTANT;
}
"if" {
    if(dump_token) 
        DUMP_TOKEN("IF\tif");
    return IF;
}
"elsif" {
    if(dump_token) 
        DUMP_TOKEN("ELSIF\telsif");
    return ELSIF;
}
"else" {
    if(dump_token) 
        DUMP_TOKEN("ELSE\telse");
    return ELSIF;
}
"for" {
    if(dump_token) 
        DUMP_TOKEN("FOR\tfor");
    return FOR;
}
"loop" {
    if(dump_token) 
        DUMP_TOKEN("LOOP\tloop");
    return LOOP;
}
"exit" {
    if(dump_token) 
        DUMP_TOKEN("EXIT\texit");
    return EXIT;
}
"case" {
    if(dump_token) 
        DUMP_TOKEN("CASE\tcase");
    return CASE;
}
"when" {
    if(dump_token) 
        DUMP_TOKEN("WHEN\twhen");
    return WHEN;
}
"others" {
    if(dump_token) 
        DUMP_TOKEN("OTHERS\tothers");
    return OTHERS;
}
"or" {
    if(dump_token) 
        DUMP_TOKEN("OR\tor");
    return OR;
}
"reverse" {
    if(dump_token) 
        DUMP_TOKEN("REVERSE\treverse");
    return REVERSE;
}
"in" {
    if(dump_token) 
        DUMP_TOKEN("IN\tin");
    return IN;
}
"String" {
    if(dump_token) 
        DUMP_TOKEN("String\tString");
    return STRING;
}
"Integer" {
    if(dump_token) 
        DUMP_TOKEN("INTEGER\tInteger");
    return INTEGER;
}
"Image" {
    if(dump_token) 
        DUMP_TOKEN("IMAGE\tImage");
    return IMAGE;
}
"Last" {
    if(dump_token) 
        DUMP_TOKEN("LAST\tLast");
    return LAST;
}
"Natural" {
    if(dump_token) 
        DUMP_TOKEN("NATURAL\tNatural");
    return NATURAL;
}
"procedure" {
    if(dump_token) 
        DUMP_TOKEN("PROCEDURE\tprocedure");
    return PROCEDURE;
}
"is" {
    if(dump_token)
        DUMP_TOKEN("IS\tis");
    return IS;
}
"then" {
    if(dump_token)
        DUMP_TOKEN("THEN\tthen");
    return THEN;
}
"begin" {
    if(dump_token)
        DUMP_TOKEN("BEGIN\tbegin");
    return BEGIN;
}
"end" {
    if(dump_token)
        DUMP_TOKEN("END\tend");
    return END;
}
"declare" {
    if(dump_token)
        DUMP_TOKEN("DECLARE\tdeclare");
    return DECLARE;
}
"null" {
    if(dump_token)
        DUMP_TOKEN("NULL\tnull");
    return NULL;
}


{STRINGLITERAL} {
    char *token;
    token = new char[strlen(yytext) + 1];
    strcpy(token, yytext);
    yylval.StrType = token;
    if(dump_token)
        DUMP_TOKEN(std::string("STRINGLTTERAL\t") + std::string(token));
    return SYRINGLITERAL;
}

{DECIMIAL} {
    int num = atoi(yytext);
    if(dump_token)
        DUMP_TOKEN("DECIMIAL\t" + std::string(yytext));
    yylval.IntType = atoi(yytext);
    return DECIMIAL;
}

{ID} {
    char *token;
    token = new char[strlen(yytext) + 1];
    strcpy(token, yytext);
    yylval.StrType = token;
    if(dump_token)
        DUMP_TOKEN(std::string("ID\t") + std::string(token));
    return ID;
}

<*>{EOL} {
    newoffsets = 0;
}

{WHITE}
{LINECOMMENT} {}

%%
