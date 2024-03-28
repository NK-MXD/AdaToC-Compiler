/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_MNT_D_WORKSPACE_ADA2C_PROJECT_INCLUDE_PARSER_H_INCLUDED
# define YY_YY_MNT_D_WORKSPACE_ADA2C_PROJECT_INCLUDE_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 24 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"

    #include "SymbolTable.h"
    #include "Ast.h"

#line 53 "/mnt/d/WorkSpace/Ada2C-Project/include/parser.h"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DECIMIAL = 258,
    ID = 259,
    STRINGLITERAL = 260,
    INTEGER = 261,
    STRING = 262,
    NATURAL = 263,
    ADD = 264,
    SUB = 265,
    MUL = 266,
    DIV = 267,
    EQUAL = 268,
    LESS = 269,
    LESSEQUAL = 270,
    GREATER = 271,
    GREATEREQUAL = 272,
    ASSIGN = 273,
    ARROW = 274,
    COLON = 275,
    SEMICOLON = 276,
    LPAREN = 277,
    RPAREN = 278,
    COMMA = 279,
    SINGLEAND = 280,
    SINGLEOR = 281,
    SINGLEQUOTES = 282,
    ELLIPISIS = 283,
    CONSTANT = 284,
    IF = 285,
    ELSIF = 286,
    ELSE = 287,
    FOR = 288,
    LOOP = 289,
    EXIT = 290,
    CASE = 291,
    WHEN = 292,
    OTHERS = 293,
    OR = 294,
    REVERSE = 295,
    IN = 296,
    IMAGE = 297,
    LAST = 298,
    PROCEDURE = 299,
    IS = 300,
    THEN = 301,
    BEGINLITERAL = 302,
    END = 303,
    DECLARE = 304,
    NULLLITERAL = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"

    char* StrType;
    int IntType;
    StmtNode* StmtType;
    ExprNode* ExprType;
    Type* type;

#line 123 "/mnt/d/WorkSpace/Ada2C-Project/include/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MNT_D_WORKSPACE_ADA2C_PROJECT_INCLUDE_PARSER_H_INCLUDED  */
