%option noyywrap
%option yylineno
%{
    #define YY_NO_UNPUT
    #define YY_NO_INPUT
    #include "parser.h"
    #include <ostream>
    #include <fstream>
    #include <iostream>
    using namespace std;
    extern FILE *yyin; 
    extern FILE *yyout;
    int offsets = 0;
    int newoffsets = 0;

    void update_loc(){
        offsets = newoffsets;
        newoffsets = offsets + strlen(yytext);
    }
    #define YY_USER_ACTION update_loc();  
    
%}

DECIMIAL ([1-9][0-9]*|0)
ID [[:alpha:]_][[:alpha:][:digit:]_]*
EOL (\r\n|\n|\r)
WHITE [\t ]

LINECOMMENT --[^\n]*

%%
"+" {
    return ADD;
}
"-" {
    return SUB;
}
"*" {
    return MUL;
}
"/" {
    return DIV;
}
"=" {
    return EQUAL;
}
"!=" {
    return NOTEQUAL;
}
":=" {
    return ASSIGN;
}

"<" {
    return LESS;
}
"<=" {
    return LESSEQUAL;
}
">" {
    return GREATER;
}
">=" {
    return GREATEREQUAL;
}
"%" {
    return MOD;
}
"&&" {
    return AND;
}
"||" {
    return OR;
}
"int" {
    return INT;
}
"const" {
    return CONST;
}
"if" {
    return IF;
};
"else" {
    return ELSE;
};
"return" {
    return RETURN;
}
"while" {
    return WHILE;
}
"break" {
    return BREAK;
}
"continue" {
    return CONTINUE;
}
"!" {
    return NOT;
}
";" {
    return SEMICOLON;
}
"(" {
    return LPAREN;
}
")" {
    return RPAREN;
}
"{" {
    return LBRACE;
}
"}" {
    return RBRACE;
}
"[" {
    return LBRACKET;
}
"]" {
    return RBRACKET;
}
"," {
    return COMMA;
}

