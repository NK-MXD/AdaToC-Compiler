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
#line 27 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"

    #include "SymbolTable.h"
    #include "Ast.h"

#line 53 "/mnt/d/WorkSpace/Ada2C-Project/include/parser.h"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TIC = 258,
    DOTDOT = 259,
    LTLT = 260,
    BOX = 261,
    LTEQ = 262,
    GTEQ = 263,
    EXPON = 264,
    NE = 265,
    GTGT = 266,
    GE = 267,
    LE = 268,
    EQ = 269,
    ASSIGN = 270,
    RIGHTSHAFT = 271,
    ABORT = 272,
    ABS = 273,
    ABSTRACT = 274,
    ACCEPT = 275,
    ACCESS = 276,
    ALIASED = 277,
    ALL = 278,
    AND = 279,
    ARRAY = 280,
    AT = 281,
    BEGiN = 282,
    BODY = 283,
    CASE = 284,
    CONSTANT = 285,
    DECLARE = 286,
    DELAY = 287,
    DELTA = 288,
    DIGITS = 289,
    DO = 290,
    ELSE = 291,
    ELSIF = 292,
    END = 293,
    ENTRY = 294,
    EXCEPTION = 295,
    EXIT = 296,
    FOR = 297,
    FUNCTION = 298,
    GENERIC = 299,
    GOTO = 300,
    IF = 301,
    IN = 302,
    IS = 303,
    LIMITED = 304,
    LOOP = 305,
    MUL = 306,
    DIV = 307,
    MOD = 308,
    NEW = 309,
    NOT = 310,
    SUB = 311,
    ADD = 312,
    NuLL = 313,
    OF = 314,
    OR = 315,
    OTHERS = 316,
    OUT = 317,
    PACKAGE = 318,
    PRAGMA = 319,
    PRIVATE = 320,
    PROCEDURE = 321,
    PROTECTED = 322,
    RAISE = 323,
    RANGE = 324,
    RECORD = 325,
    REM = 326,
    RENAMES = 327,
    REQUEUE = 328,
    RETURN = 329,
    REVERSE = 330,
    SELECT = 331,
    SEPARATE = 332,
    SUBTYPE = 333,
    TAGGED = 334,
    TASK = 335,
    TERMINATE = 336,
    THEN = 337,
    TYPE = 338,
    UNTIL = 339,
    USE = 340,
    WHEN = 341,
    WHILE = 342,
    WITH = 343,
    XOR = 344,
    TRuE = 345,
    FALsE = 346,
    DECIMIAL = 347,
    Identifier = 348,
    STRINGLITERAL = 349,
    INTEGER = 350,
    STRING = 351,
    NATURAL = 352,
    BOOLEAN = 353,
    COLON = 354,
    SEMICOLON = 355,
    LPAREN = 356,
    RPAREN = 357,
    COMMA = 358,
    SINGLEAND = 359,
    SINGLEOR = 360
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 32 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"

    char* StrType;
    int IntType;
    StmtNode* StmtType;
    ExprNode* ExprType;
    OpSignNode* SignType;
    Type* type;

#line 179 "/mnt/d/WorkSpace/Ada2C-Project/include/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MNT_D_WORKSPACE_ADA2C_PROJECT_INCLUDE_PARSER_H_INCLUDED  */
