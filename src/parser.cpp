/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* "%code top" blocks.  */
#line 1 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"

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

#line 90 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"




# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 141 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"

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
#line 29 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"

    char* StrType;
    int IntType;
    StmtNode* StmtType;
    ExprNode* ExprType;
    OpSignNode* SignType;
    Type* type;

#line 267 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MNT_D_WORKSPACE_ADA2C_PROJECT_INCLUDE_PARSER_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   322

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  106
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  143
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  223

#define YYUNDEFTOK  2
#define YYMAXUTOK   360


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   141,   141,   147,   150,   156,   159,   165,   173,   202,
     203,   209,   215,   218,   224,   231,   234,   237,   240,   245,
     246,   252,   252,   266,   267,   274,   277,   283,   294,   309,
     312,   319,   327,   330,   337,   340,   346,   349,   356,   359,
     365,   368,   371,   374,   377,   383,   386,   389,   392,   398,
     404,   416,   419,   425,   435,   441,   442,   448,   454,   457,
     464,   470,   476,   481,   482,   488,   494,   495,   506,   512,
     515,   522,   525,   528,   534,   539,   545,   550,   551,   558,
     559,   562,   568,   575,   576,   582,   588,   589,   596,   601,
     606,   607,   613,   619,   624,   625,   631,   640,   643,   646,
     652,   655,   658,   664,   667,   673,   676,   679,   682,   689,
     692,   695,   698,   701,   704,   710,   713,   719,   722,   725,
     731,   734,   740,   743,   746,   752,   755,   761,   764,   767,
     770,   776,   779,   782,   785,   791,   794,   798,   804,   810,
     814,   818,   821,   825
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIC", "DOTDOT", "LTLT", "BOX", "LTEQ",
  "GTEQ", "EXPON", "NE", "GTGT", "GE", "LE", "EQ", "ASSIGN", "RIGHTSHAFT",
  "ABORT", "ABS", "ABSTRACT", "ACCEPT", "ACCESS", "ALIASED", "ALL", "AND",
  "ARRAY", "AT", "BEGiN", "BODY", "CASE", "CONSTANT", "DECLARE", "DELAY",
  "DELTA", "DIGITS", "DO", "ELSE", "ELSIF", "END", "ENTRY", "EXCEPTION",
  "EXIT", "FOR", "FUNCTION", "GENERIC", "GOTO", "IF", "IN", "IS",
  "LIMITED", "LOOP", "MUL", "DIV", "MOD", "NEW", "NOT", "SUB", "ADD",
  "NuLL", "OF", "OR", "OTHERS", "OUT", "PACKAGE", "PRAGMA", "PRIVATE",
  "PROCEDURE", "PROTECTED", "RAISE", "RANGE", "RECORD", "REM", "RENAMES",
  "REQUEUE", "RETURN", "REVERSE", "SELECT", "SEPARATE", "SUBTYPE",
  "TAGGED", "TASK", "TERMINATE", "THEN", "TYPE", "UNTIL", "USE", "WHEN",
  "WHILE", "WITH", "XOR", "TRuE", "FALsE", "DECIMIAL", "Identifier",
  "STRINGLITERAL", "INTEGER", "STRING", "NATURAL", "BOOLEAN", "COLON",
  "SEMICOLON", "LPAREN", "RPAREN", "COMMA", "SINGLEAND", "SINGLEOR",
  "$accept", "Program", "CompUnit", "Unit", "SubprogDecl", "SubprogSpec",
  "FormalPartOpt", "FormalPart", "Params", "Param", "Type", "InitOpt",
  "SubprogBody", "$@1", "DeclPart", "Decl", "ObjectDecl", "DefIds",
  "DefId", "DeclItemOrBodys", "DeclItemOrBody", "Statements", "Statement",
  "SimpleStmt", "CompoundStmt", "NullStmt", "AssignStmt", "ReturnStmt",
  "ProcedureCall", "ExitStmt", "WhenOpt", "IfStmt", "CondClauses",
  "CondClause", "CondPart", "Condition", "ElseOpt", "CaseStmt",
  "Alternatives", "Alternative", "Choices", "Choice", "DiscreteWithRange",
  "LoopStmt", "LabelOpt", "Iteration", "IterPart", "ReverseOpt",
  "BasicLoop", "IdOpt", "DiscreteRange", "RangeConstrOpt", "Range",
  "Block", "BlockDecl", "BlockBody", "Expression", "Logical",
  "ShortCircuit", "Relation", "Relational", "Membership",
  "SimpleExpression", "Unary", "Adding", "Term", "Multiplying", "Factor",
  "Primary", "ParenthesizedPrimary", "Literal", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360
};
# endif

#define YYPACT_NINF (-119)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-137)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -27,   -71,    45,   -27,  -119,  -119,   -37,  -119,   -39,  -119,
    -119,  -119,  -119,    -5,  -119,  -119,    44,   -45,   -72,  -119,
    -119,  -119,  -119,    37,  -119,  -119,    31,  -119,    44,  -119,
     128,    -5,  -119,   228,    74,   116,    12,  -119,  -119,  -119,
    -119,  -119,    99,  -119,   101,    28,   101,    35,    60,    -8,
     218,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,    11,  -119,    28,   128,    99,  -119,   101,  -119,
     204,   204,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
     101,    22,  -119,    19,   148,   118,  -119,   120,  -119,  -119,
    -119,    54,   102,  -119,   228,    85,    66,  -119,  -119,    24,
     101,  -119,  -119,  -119,    44,    55,   101,   131,   111,    37,
      88,    99,    90,    66,  -119,  -119,    20,   114,  -119,   169,
    -119,   101,   101,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
     160,  -119,  -119,  -119,   101,   107,   148,   118,  -119,  -119,
    -119,  -119,   148,   204,   101,   109,   228,   101,   172,   214,
    -119,  -119,   144,  -119,   168,  -119,   228,    28,  -119,   127,
     178,  -119,   122,  -119,  -119,  -119,   -15,  -119,  -119,  -119,
    -119,    29,    16,  -119,     4,   118,  -119,  -119,  -119,  -119,
     225,  -119,   181,  -119,  -119,   229,   129,   -29,  -119,  -119,
      28,  -119,   201,    86,  -119,   101,   132,   184,  -119,   101,
    -119,   135,   137,  -119,   162,   -11,  -119,  -119,  -119,    66,
       2,    29,  -119,  -119,  -119,  -119,  -119,   101,   228,    86,
    -119,   207,  -119
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     3,     5,     0,     6,     9,     1,
       4,    21,     7,     0,     8,    10,    23,     0,     0,    12,
      31,    26,    34,     0,    35,    25,     0,    29,    24,    32,
       0,     0,    11,    77,     0,     0,     0,    33,    15,    17,
      18,    16,    19,    13,     0,    86,     0,     0,     0,     0,
      77,    36,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    79,    48,    86,     0,    19,    30,     0,    14,
       0,     0,   121,   120,   141,   142,   143,   139,   136,   140,
       0,     0,    97,   105,     0,   118,   125,   131,   137,   135,
      87,    55,    63,    58,    77,     0,    62,    49,    51,     0,
       0,    78,    53,    37,    23,     0,     0,     0,    83,     0,
       0,    19,     0,    20,   133,   132,     0,   100,    66,   101,
     102,     0,     0,   112,   114,   110,   113,   111,   109,   115,
       0,   123,   122,   124,     0,     0,     0,   117,   127,   128,
     129,   130,     0,     0,     0,     0,    77,     0,     0,    77,
      61,    52,     0,    95,     0,    80,    77,    86,    84,     0,
       0,    22,     0,    27,   138,   103,     0,   104,    98,    99,
     116,   106,   108,   107,     0,   119,   126,   134,    56,    54,
      77,    59,     0,    50,    82,    77,     0,   136,    81,    89,
      86,    28,     0,     0,    67,     0,     0,     0,    76,     0,
      88,     0,     0,    73,   136,     0,    69,    72,    75,    71,
     105,    92,    57,    85,    91,    93,    65,     0,    77,     0,
      74,    77,    70
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -119,  -119,  -119,   243,    47,  -119,  -119,  -119,  -119,   230,
      67,   -14,    93,  -119,   164,  -119,  -119,  -119,   237,  -119,
     249,   -91,   -49,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,   133,  -119,   -93,  -119,  -119,  -119,  -119,
    -119,    59,  -119,  -119,  -119,  -119,  -119,  -119,  -119,   -62,
    -119,  -119,  -118,  -119,  -119,   170,   -44,  -119,  -119,    52,
    -119,  -119,  -116,  -119,  -119,   -47,  -119,   140,   -36,  -119,
    -119
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    21,     6,    14,    15,    18,    19,
      42,    69,    22,    16,    23,    24,    25,    26,    27,    28,
      29,    50,    51,    52,    53,    54,    55,    56,    57,    58,
     145,    59,    92,    93,    94,    95,   148,    60,   166,   194,
     205,   206,   207,    61,    62,   107,   108,   159,   157,    91,
     188,   200,   208,    63,   109,    34,    96,   121,   122,    82,
     134,   135,    83,    84,   136,    85,   142,    86,    87,    88,
      89
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      81,   103,   110,   149,    99,   218,   195,   100,   195,   123,
     124,    11,   125,   155,   126,   127,   128,   173,   171,   174,
    -136,   -90,     8,   192,   113,  -136,   123,   124,    31,   125,
      32,   126,   127,   128,   114,   115,   116,   137,   -94,     1,
     199,   189,   104,   174,   117,     9,   117,     5,   117,   129,
       5,   178,   112,   105,    30,   180,   152,   130,   131,   132,
     131,   132,    13,    12,    33,   185,   129,  -136,  -136,  -136,
     118,   193,  -136,  -136,   130,   131,   132,   210,    70,   211,
     119,   214,   119,   174,   119,   131,   132,  -136,    17,   175,
     117,   101,   102,     7,   219,   186,     7,   162,   106,   220,
     103,   174,    66,   210,    70,    20,   133,   177,   133,   120,
       1,   120,    64,   120,    68,    71,    72,    73,    74,    70,
    -136,    90,   164,   133,   151,    70,   119,   221,   201,   143,
      35,   103,   111,   133,    36,    97,   103,    20,   146,   147,
     144,    71,    72,    73,    74,    70,    65,   203,   154,   209,
      75,    76,    77,    78,    79,   120,    71,    72,    73,    74,
      98,    80,    71,    72,    73,    74,    70,   150,   117,   138,
     139,   140,   103,   168,   169,   209,    75,    76,    77,   204,
      79,   156,    71,    72,    73,    74,   158,    80,   161,   141,
     163,    75,    76,    77,    78,    79,   165,    75,    76,    77,
     172,    79,    80,    71,   119,   167,    74,   170,    80,   179,
     182,    38,    39,    40,    41,   184,   190,    75,    76,    77,
     187,    79,   191,    38,    39,    40,    41,   196,    80,   198,
     202,   217,   212,   120,   213,   215,    44,   216,    75,    76,
      77,    78,    79,    44,   183,   -68,    10,    44,    45,    80,
     -60,   -60,   -60,    46,    44,    45,   -96,    44,    44,    45,
      46,    43,    74,   -64,    46,    47,    45,   197,   153,    45,
      45,    46,    47,    67,    46,    46,    47,    37,   222,   160,
     181,    48,   176,    47,     0,     0,    47,    47,    48,     0,
       0,     0,    48,   -68,    75,    76,    77,    78,    79,    48,
      49,     0,    48,    48,     0,    80,     0,    49,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,    49,     0,
       0,    49,    49
};

static const yytype_int16 yycheck[] =
{
      44,    50,    64,    94,    48,    16,     4,    15,     4,     7,
       8,    48,    10,   106,    12,    13,    14,   135,   134,   135,
       4,    50,    93,    38,    68,     9,     7,     8,   100,    10,
     102,    12,    13,    14,    70,    71,    80,    84,    27,    66,
      69,   159,    31,   159,    24,     0,    24,     0,    24,    47,
       3,   144,    66,    42,    99,   146,   100,    55,    56,    57,
      56,    57,   101,   100,    27,   156,    47,    51,    52,    53,
      48,    86,    56,    57,    55,    56,    57,   193,    18,   195,
      60,   199,    60,   199,    60,    56,    57,    71,    93,   136,
      24,    99,   100,     0,   105,   157,     3,   111,    87,   217,
     149,   217,    35,   219,    18,    93,   104,   143,   104,    89,
      66,    89,    38,    89,    15,    55,    56,    57,    58,    18,
     104,    93,   102,   104,   100,    18,    60,   218,   190,     9,
      99,   180,    65,   104,   103,   100,   185,    93,    36,    37,
      86,    55,    56,    57,    58,    18,    30,    61,    93,   193,
      90,    91,    92,    93,    94,    89,    55,    56,    57,    58,
     100,   101,    55,    56,    57,    58,    18,    82,    24,    51,
      52,    53,   221,   121,   122,   219,    90,    91,    92,    93,
      94,    50,    55,    56,    57,    58,    75,   101,   100,    71,
     100,    90,    91,    92,    93,    94,    82,    90,    91,    92,
      93,    94,   101,    55,    60,    36,    58,    47,   101,   100,
      38,    95,    96,    97,    98,    47,    38,    90,    91,    92,
      93,    94,   100,    95,    96,    97,    98,    46,   101,   100,
      29,    69,   100,    89,    50,   100,    29,   100,    90,    91,
      92,    93,    94,    29,   100,    38,     3,    29,    41,   101,
      36,    37,    38,    46,    29,    41,    38,    29,    29,    41,
      46,    31,    58,    38,    46,    58,    41,    38,   104,    41,
      41,    46,    58,    36,    46,    46,    58,    28,   219,   109,
     147,    74,   142,    58,    -1,    -1,    58,    58,    74,    -1,
      -1,    -1,    74,    86,    90,    91,    92,    93,    94,    74,
      93,    -1,    74,    74,    -1,   101,    -1,    93,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    93,    93
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    66,   107,   108,   109,   110,   111,   118,    93,     0,
     109,    48,   100,   101,   112,   113,   119,    93,   114,   115,
      93,   110,   118,   120,   121,   122,   123,   124,   125,   126,
      99,   100,   102,    27,   161,    99,   103,   126,    95,    96,
      97,    98,   116,   115,    29,    41,    46,    58,    74,    93,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   137,
     143,   149,   150,   159,    38,    30,   116,   124,    15,   117,
      18,    55,    56,    57,    58,    90,    91,    92,    93,    94,
     101,   162,   165,   168,   169,   171,   173,   174,   175,   176,
      93,   155,   138,   139,   140,   141,   162,   100,   100,   162,
      15,    99,   100,   128,    31,    42,    87,   151,   152,   160,
     155,   116,   117,   162,   174,   174,   162,    24,    48,    60,
      89,   163,   164,     7,     8,    10,    12,    13,    14,    47,
      55,    56,    57,   104,   166,   167,   170,   171,    51,    52,
      53,    71,   172,     9,    86,   136,    36,    37,   142,   127,
      82,   100,   162,   120,    93,   141,    50,   154,    75,   153,
     161,   100,   117,   100,   102,    82,   144,    36,   165,   165,
      47,   168,    93,   158,   168,   171,   173,   174,   141,   100,
     127,   139,    38,   100,    47,   127,   155,    93,   156,   158,
      38,   100,    38,    86,   145,     4,    46,    38,   100,    69,
     157,   155,    29,    61,    93,   146,   147,   148,   158,   162,
     168,   168,   100,    50,   158,   100,   100,    69,    16,   105,
     158,   127,   147
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   106,   107,   108,   108,   109,   109,   110,   111,   112,
     112,   113,   114,   114,   115,   116,   116,   116,   116,   117,
     117,   119,   118,   120,   120,   121,   121,   122,   122,   123,
     123,   124,   125,   125,   126,   126,   127,   127,   128,   128,
     129,   129,   129,   129,   129,   130,   130,   130,   130,   131,
     132,   133,   133,   134,   135,   136,   136,   137,   138,   138,
     139,   140,   141,   142,   142,   143,   144,   144,   145,   146,
     146,   147,   147,   147,   148,   148,   149,   150,   150,   151,
     151,   151,   152,   153,   153,   154,   155,   155,   156,   156,
     157,   157,   158,   159,   160,   160,   161,   162,   162,   162,
     163,   163,   163,   164,   164,   165,   165,   165,   165,   166,
     166,   166,   166,   166,   166,   167,   167,   168,   168,   168,
     169,   169,   170,   170,   170,   171,   171,   172,   172,   172,
     172,   173,   173,   173,   173,   174,   174,   174,   175,   176,
     176,   176,   176,   176
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     2,     3,     0,
       1,     3,     1,     3,     4,     1,     1,     1,     1,     0,
       2,     0,     8,     0,     1,     1,     1,     5,     6,     1,
       3,     1,     1,     2,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     2,     3,     2,     4,     0,     2,     6,     1,     3,
       2,     2,     1,     0,     2,     7,     0,     2,     4,     1,
       3,     1,     1,     1,     3,     1,     5,     0,     2,     0,
       2,     3,     3,     0,     1,     4,     0,     1,     2,     1,
       0,     2,     3,     6,     0,     2,     2,     1,     3,     3,
       1,     1,     1,     2,     2,     1,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     3,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     2,     2,     3,     1,     1,     1,     3,     1,
       1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 141 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        ast.setRoot((yyvsp[0].StmtType));
    }
#line 1664 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 3:
#line 147 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
           {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1672 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 4:
#line 150 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                    {
        (yyval.StmtType) = new SeqNode((yyvsp[-1].StmtType), (yyvsp[0].StmtType));
    }
#line 1680 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 5:
#line 156 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1688 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 6:
#line 159 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                      {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1696 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 7:
#line 165 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                            {
        DEBUG_YACC("Enter SubprogDecl");
        (yyval.StmtType) = new ProcedureDecl(dynamic_cast<ProcedureSpec*>((yyvsp[-1].StmtType)));
        DEBUG_YACC("Leave SubprogDecl");
    }
#line 1706 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 8:
#line 173 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                         {
        DEBUG_YACC("================Enter SubprogSpec=================");
        // Define procedure type.
        Type* proType;
        ParamNode* param = nullptr;
        if((yyvsp[0].StmtType))
          param = dynamic_cast<ParamNode*>((yyvsp[0].StmtType));
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
        SymbolEntry *se = new IdentifierSymbolEntry(proType, (yyvsp[-1].StrType), identifiers->getLevel());
        identifiers->install((yyvsp[-1].StrType), se);
        
        // Define SubprogSpec with ast node.
        (yyval.StmtType) = new ProcedureSpec(se, param);
        DEBUG_YACC("================Leave SubprogSpec=================");

    }
#line 1737 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 9:
#line 202 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             { (yyval.StmtType) = nullptr; }
#line 1743 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 10:
#line 203 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1751 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 11:
#line 209 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                           {
        (yyval.StmtType) = (yyvsp[-1].StmtType);
    }
#line 1759 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 12:
#line 215 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
            {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1767 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 13:
#line 218 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                 {
        (yyval.StmtType) = (yyvsp[-2].StmtType);
        (yyvsp[-2].StmtType)->setNext((yyvsp[0].StmtType));
    }
#line 1776 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 14:
#line 224 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                      {
        SymbolEntry *se = new IdentifierSymbolEntry((yyvsp[-1].type), (yyvsp[-3].StrType), IdentifierSymbolEntry::PARAM);
        (yyval.StmtType) = new ParamNode(se, dynamic_cast<InitOptStmt*>((yyvsp[0].StmtType)));
    }
#line 1785 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 15:
#line 231 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.type) = TypeSystem::integerType;
    }
#line 1793 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 16:
#line 234 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.type) = TypeSystem::boolType;
    }
#line 1801 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 17:
#line 237 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.type) = TypeSystem::stringType;
    }
#line 1809 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 18:
#line 240 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.type) = TypeSystem::naturalType;
    }
#line 1817 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 19:
#line 245 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 { (yyval.StmtType) = nullptr; }
#line 1823 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 20:
#line 246 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                            {
        (yyval.StmtType) = new InitOptStmt((yyvsp[0].ExprType));
    }
#line 1831 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 21:
#line 252 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        DEBUG_YACC("================Enter SubprogBody=================");
        // Enter into new scope.
        identifiers = new SymbolTable(identifiers);
    }
#line 1841 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 22:
#line 256 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                             {
        (yyval.StmtType) = new ProcedureDef(dynamic_cast<ProcedureSpec*>((yyvsp[-7].StmtType)), dynamic_cast<DeclItemOrBodyStmt*>((yyvsp[-4].StmtType)), dynamic_cast<Stmt*>((yyvsp[-3].StmtType)));
        // Leave the scope.
        SymbolTable* ScopeTable = identifiers;
        identifiers = identifiers->getPrev();
        delete ScopeTable;
        DEBUG_YACC("================Leave SubprogBody=================");
    }
#line 1854 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 23:
#line 266 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 { (yyval.StmtType) = nullptr; }
#line 1860 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 24:
#line 267 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                          {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1868 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 25:
#line 274 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.StmtType) = new DeclStmt(dynamic_cast<ObjectDeclStmt*>((yyvsp[0].StmtType)));
    }
#line 1876 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 26:
#line 277 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  {
        (yyval.StmtType) = new DeclStmt(dynamic_cast<ProcedureDecl*>((yyvsp[0].StmtType)));
    }
#line 1884 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 27:
#line 283 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                          {
        DEBUG_YACC("================Enter ObjectDecl=================");
        // Reset the type of id
        DefId* id = dynamic_cast<DefId*>((yyvsp[-4].StmtType));
        while(id) {
            id->setType((yyvsp[-2].type));
            id = dynamic_cast<DefId*>(id->getNext());
        }
        (yyval.StmtType) = new ObjectDeclStmt(dynamic_cast<DefId*>((yyvsp[-4].StmtType)), dynamic_cast<InitOptStmt*>((yyvsp[-1].StmtType)));
        DEBUG_YACC("================Leave ObjectDecl=================");
    }
#line 1900 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 28:
#line 294 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                                   {
        DEBUG_YACC("================Enter CONSTANT ObjectDecl=================");
        DefId* id = dynamic_cast<DefId*>((yyvsp[-5].StmtType));
        InitOptStmt* init = dynamic_cast<InitOptStmt*>((yyvsp[-1].StmtType));
        while(id) {
            id->setType((yyvsp[-2].type));
            id->setConst();
            id = dynamic_cast<DefId*>(id->getNext());
        }
        (yyval.StmtType) = new ObjectDeclStmt(dynamic_cast<DefId*>((yyvsp[-5].StmtType)), dynamic_cast<InitOptStmt*>((yyvsp[-1].StmtType)));
        DEBUG_YACC("================Leave CONSTANT ObjectDecl=================");
    }
#line 1917 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 29:
#line 309 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
            {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1925 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 30:
#line 312 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                         {
        (yyval.StmtType) = (yyvsp[-2].StmtType);
        (yyvsp[-2].StmtType)->setNext((yyvsp[0].StmtType));
    }
#line 1934 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 31:
#line 319 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        IdentifierSymbolEntry *se = new IdentifierSymbolEntry((yyvsp[0].StrType), identifiers->getLevel());
        identifiers->install((yyvsp[0].StrType), se);
        (yyval.StmtType) = new DefId(se);
    }
#line 1944 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 32:
#line 327 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1952 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 33:
#line 330 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                         {
        (yyval.StmtType) = (yyvsp[-1].StmtType);
        (yyvsp[-1].StmtType)->setNext((yyvsp[0].StmtType));
    }
#line 1961 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 34:
#line 337 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  {
        (yyval.StmtType) = new DeclItemOrBodyStmt(dynamic_cast<ProcedureDef*>((yyvsp[0].StmtType)));
    }
#line 1969 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 35:
#line 340 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.StmtType) = new DeclItemOrBodyStmt(dynamic_cast<DeclStmt*>((yyvsp[0].StmtType)));
    }
#line 1977 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 36:
#line 346 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1985 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 37:
#line 349 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                               {
        (yyval.StmtType) = (yyvsp[-1].StmtType);
        (yyvsp[-1].StmtType)->setNext((yyvsp[0].StmtType));
    }
#line 1994 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 38:
#line 356 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.StmtType) = new Stmt((yyvsp[0].StmtType));
    }
#line 2002 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 39:
#line 359 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                       {
        (yyval.StmtType) = new Stmt((yyvsp[0].StmtType));
    }
#line 2010 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 40:
#line 365 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2018 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 41:
#line 368 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2026 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 42:
#line 371 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2034 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 43:
#line 374 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                        {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2042 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 44:
#line 377 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2050 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 45:
#line 383 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2058 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 46:
#line 386 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                   {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2066 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 47:
#line 389 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                   {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2074 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 48:
#line 392 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2082 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 49:
#line 398 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.StmtType) = new NullStmt();
    }
#line 2090 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 50:
#line 404 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                             {
        DEBUG_YACC("================Enter AssignStmt=================");
        SymbolEntry *se = identifiers->lookup((yyvsp[-3].StrType));
        if(!se) {
            std::cerr << "[YACC ERROR]: Can't not get symbolEntry: "<< (yyvsp[-3].StrType) << "\n";
        }
        (yyval.StmtType) = new AssignStmt(se, (yyvsp[-1].ExprType));
        DEBUG_YACC("================Leave AssignStmt=================");
    }
#line 2104 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 51:
#line 416 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                       {
        (yyval.StmtType) = new ReturnStmt(nullptr);
    }
#line 2112 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 52:
#line 419 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                      {
        (yyval.StmtType) = new ReturnStmt((yyvsp[-1].ExprType));
    }
#line 2120 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 53:
#line 425 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                           {
        SymbolEntry* se = identifiers->lookup((yyvsp[-1].StrType));
        if(!se || !se->getType()->isProcedure()) {
            std::cerr << "[YACC ERROR]: Can't not get Procedure type SymbolEntry!\n";
        }
        (yyval.StmtType) = new CallStmt(se);
    }
#line 2132 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 54:
#line 435 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                   {
        (yyval.StmtType) = new ExitStmt((yyvsp[-1].ExprType));
    }
#line 2140 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 55:
#line 441 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             { (yyval.ExprType) = nullptr; }
#line 2146 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 56:
#line 442 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                         {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2154 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 57:
#line 448 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                              {
        (yyval.StmtType) = new IfStmt(dynamic_cast<CondClause*>((yyvsp[-4].StmtType)), dynamic_cast<Stmt*>((yyvsp[-3].StmtType)));
    }
#line 2162 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 58:
#line 454 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2170 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 59:
#line 457 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                       {
        (yyval.StmtType) = (yyvsp[-2].StmtType);
        (yyvsp[-2].StmtType)->setNext((yyvsp[0].StmtType));
    }
#line 2179 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 60:
#line 464 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                          {
        (yyval.StmtType) = new CondClause((yyvsp[-1].ExprType), dynamic_cast<Stmt*>((yyvsp[0].StmtType)));
    }
#line 2187 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 61:
#line 470 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.ExprType) = (yyvsp[-1].ExprType);
    }
#line 2195 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 62:
#line 476 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.ExprType) = (yyvsp[0].ExprType); 
    }
#line 2203 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 63:
#line 481 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 { (yyval.StmtType) = nullptr; }
#line 2209 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 64:
#line 482 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                          {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2217 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 65:
#line 488 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                                         {
        (yyval.StmtType) = new CaseStmt((yyvsp[-5].ExprType), dynamic_cast<Alternative*>((yyvsp[-3].StmtType)));
    }
#line 2225 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 66:
#line 494 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             { (yyval.StmtType) = nullptr; }
#line 2231 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 67:
#line 495 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                   {
        if((yyvsp[-1].StmtType)) {
            (yyval.StmtType) = (yyvsp[-1].StmtType);
            (yyvsp[-1].StmtType)->setNext((yyvsp[0].StmtType));
        } else {
            (yyval.StmtType) = (yyvsp[0].StmtType);
        }
    }
#line 2244 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 68:
#line 506 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                         {
        (yyval.StmtType) = new Alternative(dynamic_cast<Choice*>((yyvsp[-2].StmtType)), dynamic_cast<Stmt*>((yyvsp[0].StmtType)));
    }
#line 2252 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 69:
#line 512 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2260 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 70:
#line 515 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                  {
        (yyval.StmtType) = (yyvsp[-2].StmtType);
        (yyvsp[-2].StmtType)->setNext((yyvsp[0].StmtType));
    }
#line 2269 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 71:
#line 522 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.StmtType) = new Choice((yyvsp[0].ExprType));
    }
#line 2277 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 72:
#line 525 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                            {
        (yyval.StmtType) = new Choice(dynamic_cast<DiscreteRange*>((yyvsp[0].StmtType)));
    }
#line 2285 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 73:
#line 528 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.StmtType) = new Choice(true);
    }
#line 2293 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 74:
#line 534 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                             {
        Type* type = dynamic_cast<Range*>((yyvsp[0].StmtType))->getType();
        SymbolEntry* se = new IdentifierSymbolEntry(type, (yyvsp[-2].StrType), identifiers->getLevel());
        (yyval.StmtType) = new DiscreteRange(se, dynamic_cast<Range*>((yyvsp[0].StmtType)));
    }
#line 2303 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 75:
#line 539 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                {
        (yyval.StmtType) = new DiscreteRange(dynamic_cast<Range*>((yyvsp[0].StmtType)));
    }
#line 2311 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 76:
#line 545 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                                   {
        (yyval.StmtType) = new LoopStmt(dynamic_cast<LabelOpt*>((yyvsp[-4].StmtType)), dynamic_cast<Iteration*>((yyvsp[-3].StmtType)), dynamic_cast<BasicLoopStmt*>((yyvsp[-2].StmtType)));
    }
#line 2319 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 77:
#line 550 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  { (yyval.StmtType) = nullptr; }
#line 2325 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 78:
#line 551 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                           {
        SymbolEntry *se = new IdentifierSymbolEntry(TypeSystem::integerType, (yyvsp[-1].StrType), identifiers->getLevel());
        identifiers->install((yyvsp[-1].StrType), se);
        (yyval.StmtType) = new LabelOpt(se);
    }
#line 2335 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 79:
#line 558 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                   { (yyval.StmtType) = nullptr; }
#line 2341 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 80:
#line 559 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                          {
        (yyval.StmtType) = new Iteration((yyvsp[0].ExprType));
    }
#line 2349 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 81:
#line 562 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                            {
        (yyval.StmtType) = new Iteration(dynamic_cast<IterPart*>((yyvsp[-2].StmtType)), (yyvsp[-1].SignType), dynamic_cast<DiscreteRange*>((yyvsp[0].StmtType)));
    }
#line 2357 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 82:
#line 568 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                        {
        SymbolEntry *se = new IdentifierSymbolEntry(TypeSystem::integerType, (yyvsp[-1].StrType), identifiers->getLevel());
        identifiers->install((yyvsp[-1].StrType), se);
        (yyval.StmtType) = new IterPart(se);
    }
#line 2367 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 83:
#line 575 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                    { (yyval.SignType) = nullptr; }
#line 2373 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 84:
#line 576 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  {
        (yyval.SignType) = new OpSignNode(OpSignNode::REVERSE);
    }
#line 2381 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 85:
#line 582 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                               {
        (yyval.StmtType) = new BasicLoopStmt(dynamic_cast<Stmt*>((yyvsp[-2].StmtType)));
    }
#line 2389 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 86:
#line 588 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 { (yyval.ExprType) = nullptr; }
#line 2395 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 87:
#line 589 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        SymbolEntry* se = identifiers->lookup((yyvsp[0].StrType));
        (yyval.ExprType) = new Id(se);
    }
#line 2404 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 88:
#line 596 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                {
        SymbolEntry *se = new IdentifierSymbolEntry(TypeSystem::integerType, (yyvsp[-1].StrType), identifiers->getLevel());
        identifiers->install((yyvsp[-1].StrType), se);
        (yyval.StmtType) = new DiscreteRange(se, dynamic_cast<Range*>((yyvsp[0].StmtType)));
    }
#line 2414 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 89:
#line 601 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                {
        (yyval.StmtType) = new DiscreteRange(dynamic_cast<Range*>((yyvsp[0].StmtType)));
    }
#line 2422 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 90:
#line 606 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                        { (yyval.StmtType) = nullptr; }
#line 2428 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 91:
#line 607 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                      {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2436 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 92:
#line 613 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                               {
        (yyval.StmtType) = new Range((yyvsp[-2].ExprType), (yyvsp[0].ExprType));
    }
#line 2444 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 93:
#line 619 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                                       {
        (yyval.StmtType) = new Block(dynamic_cast<LabelOpt*>((yyvsp[-5].StmtType)), dynamic_cast<DeclItemOrBodyStmt*>((yyvsp[-4].StmtType)), dynamic_cast<Stmt*>((yyvsp[-3].StmtType)));
    }
#line 2452 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 94:
#line 624 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                   { (yyval.StmtType) = nullptr; }
#line 2458 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 95:
#line 625 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                           {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2466 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 96:
#line 631 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                       {
        DEBUG_YACC("================Enter BlockBody=================");
        (yyval.StmtType) = (yyvsp[0].StmtType);
        DEBUG_YACC("================Enter BlockBody=================");

    }
#line 2477 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 97:
#line 640 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2485 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 98:
#line 643 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                      {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2493 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 99:
#line 646 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                           {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2501 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 100:
#line 652 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
          {
        (yyval.SignType) = new OpSignNode(OpSignNode::AND);
    }
#line 2509 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 101:
#line 655 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.SignType) = new OpSignNode(OpSignNode::OR);
    }
#line 2517 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 102:
#line 658 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::XOR);
    }
#line 2525 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 103:
#line 664 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.SignType) = new OpSignNode(OpSignNode::ANDTHEN);
    }
#line 2533 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 104:
#line 667 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  {
        (yyval.SignType) = new OpSignNode(OpSignNode::ORELSE);
    }
#line 2541 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 105:
#line 673 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                       {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2549 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 106:
#line 676 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                                       {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2557 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 107:
#line 679 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                            {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), dynamic_cast<Range*>((yyvsp[0].StmtType)), (yyvsp[-1].SignType));
    }
#line 2565 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 108:
#line 682 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                                 {
        SymbolEntry* se = new IdentifierSymbolEntry(TypeSystem::integerType, (yyvsp[0].StrType), identifiers->getLevel());
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), se, (yyvsp[-1].SignType));
    }
#line 2574 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 109:
#line 689 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
         {
        (yyval.SignType) = new OpSignNode(OpSignNode::EQ);
    }
#line 2582 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 110:
#line 692 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.SignType) = new OpSignNode(OpSignNode::NE);
    }
#line 2590 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 111:
#line 695 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.SignType) = new OpSignNode(OpSignNode::LE);
    }
#line 2598 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 112:
#line 698 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.SignType) = new OpSignNode(OpSignNode::LTEQ);
    }
#line 2606 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 113:
#line 701 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.SignType) = new OpSignNode(OpSignNode::GE);
    }
#line 2614 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 114:
#line 704 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.SignType) = new OpSignNode(OpSignNode::GTEQ);
    }
#line 2622 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 115:
#line 710 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
         {
        (yyval.SignType) = new OpSignNode(OpSignNode::IN);
    }
#line 2630 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 116:
#line 713 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.SignType) = new OpSignNode(OpSignNode::NOTIN);
    }
#line 2638 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 117:
#line 719 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.ExprType) = new BinaryExpr((yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2646 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 118:
#line 722 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2654 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 119:
#line 725 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                       {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2662 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 120:
#line 731 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
          {
        (yyval.SignType) = new OpSignNode(OpSignNode::ADD);
    }
#line 2670 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 121:
#line 734 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::SUB);
    }
#line 2678 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 122:
#line 740 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
          {
        (yyval.SignType) = new OpSignNode(OpSignNode::ADD);
    }
#line 2686 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 123:
#line 743 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::SUB);
    }
#line 2694 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 124:
#line 746 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                    {
        (yyval.SignType) = new OpSignNode(OpSignNode::SINGLEAND);
    }
#line 2702 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 125:
#line 752 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2710 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 126:
#line 755 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                  {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2718 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 127:
#line 761 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
          {
        (yyval.SignType) = new OpSignNode(OpSignNode::MUL);
    }
#line 2726 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 128:
#line 764 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::DIV);
    }
#line 2734 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 129:
#line 767 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::MOD);
    }
#line 2742 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 130:
#line 770 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::REM);
    }
#line 2750 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 131:
#line 776 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2758 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 132:
#line 779 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                      {
        (yyval.ExprType) = new FactorExpr((yyvsp[0].ExprType), FactorExpr::NOT);
    }
#line 2766 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 133:
#line 782 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                      {
        (yyval.ExprType) = new FactorExpr((yyvsp[0].ExprType), FactorExpr::ABS);
    }
#line 2774 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 134:
#line 785 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), new OpSignNode(OpSignNode::EXPON));
    }
#line 2782 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 135:
#line 791 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2790 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 136:
#line 794 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        SymbolEntry* se = identifiers->lookup((yyvsp[0].StrType));
        (yyval.ExprType) = new Id(se);
    }
#line 2799 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 137:
#line 798 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                               {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2807 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 138:
#line 804 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                               {
        (yyval.ExprType) = (yyvsp[-1].ExprType);
    }
#line 2815 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 139:
#line 810 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        SymbolEntry* se = new ConstantSymbolEntry(TypeSystem::integerType, (yyvsp[0].IntType));
        (yyval.ExprType) = new Constant(se);
    }
#line 2824 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 140:
#line 814 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                        {
        SymbolEntry* se = new ConstantSymbolEntry(TypeSystem::stringType, (yyvsp[0].StrType));
        (yyval.ExprType) = new Constant(se);
    }
#line 2833 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 141:
#line 818 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.ExprType) = nullptr;
    }
#line 2841 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 142:
#line 821 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
           {
        SymbolEntry* se = new ConstantSymbolEntry(TypeSystem::boolType, true);
        (yyval.ExprType) = new Constant(se);
    }
#line 2850 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 143:
#line 825 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
            {
        SymbolEntry* se = new ConstantSymbolEntry(TypeSystem::boolType, false);
        (yyval.ExprType) = new Constant(se);
    }
#line 2859 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;


#line 2863 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 830 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"


int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}
