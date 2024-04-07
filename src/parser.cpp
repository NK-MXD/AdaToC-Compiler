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
#define YYLAST   353

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  106
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  77
/* YYNRULES -- Number of rules.  */
#define YYNRULES  153
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  237

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
       0,   142,   142,   148,   151,   157,   160,   166,   174,   203,
     204,   210,   216,   219,   225,   232,   235,   238,   241,   246,
     247,   253,   253,   267,   268,   275,   278,   284,   295,   310,
     313,   320,   328,   331,   338,   341,   347,   350,   357,   360,
     366,   369,   372,   375,   378,   384,   387,   390,   393,   399,
     405,   417,   420,   426,   436,   442,   443,   449,   455,   458,
     465,   471,   477,   482,   483,   489,   495,   496,   507,   513,
     516,   523,   526,   529,   535,   540,   546,   551,   552,   559,
     560,   563,   569,   576,   577,   583,   589,   590,   597,   602,
     607,   608,   614,   620,   625,   626,   632,   641,   644,   647,
     653,   656,   659,   665,   668,   674,   677,   680,   683,   690,
     693,   696,   699,   702,   705,   711,   714,   720,   723,   726,
     732,   735,   741,   744,   747,   753,   756,   762,   765,   768,
     771,   777,   780,   783,   786,   792,   795,   798,   804,   808,
     811,   814,   822,   828,   831,   838,   844,   850,   856,   862,
     866,   870,   873,   877
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
  "Primary", "Name", "IndexedComp", "Values", "Value", "Attribute",
  "AttributeId", "ParenthesizedPrimary", "Literal", YY_NULLPTR
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

#define YYPACT_NINF (-133)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-139)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -28,   -76,    32,   -28,  -133,  -133,   -34,  -133,   -61,  -133,
    -133,  -133,  -133,   -42,  -133,  -133,   -35,   -45,    28,  -133,
    -133,  -133,  -133,    83,  -133,  -133,   -60,  -133,   -35,  -133,
     108,   -42,  -133,   259,    79,    25,    21,  -133,  -133,  -133,
    -133,  -133,   110,  -133,   117,    43,   117,    41,    76,    -7,
     223,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,   197,  -133,    43,   108,   110,  -133,   117,  -133,
     246,   246,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,   117,   154,  -133,    34,   182,    92,  -133,   137,     2,
    -133,  -133,  -133,  -133,  -133,    64,    61,  -133,   259,    72,
      26,  -133,  -133,    -4,   117,  -133,  -133,  -133,   -35,    69,
     117,   115,   105,    83,    81,   110,    84,    26,  -133,  -133,
     -15,    97,  -133,   147,  -133,   117,   117,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,   138,  -133,  -133,  -133,   117,   141,
     182,    92,  -133,  -133,  -133,  -133,   182,   246,    94,   117,
     117,    88,   259,   117,   175,   249,  -133,  -133,    51,  -133,
     168,  -133,   259,    43,  -133,   164,   178,  -133,   123,  -133,
    -133,  -133,    -2,  -133,  -133,  -133,  -133,    20,    12,  -133,
      22,    92,  -133,  -133,  -133,  -133,    26,    46,  -133,  -133,
    -133,   253,  -133,   171,  -133,  -133,   260,   125,   -20,  -133,
    -133,    43,  -133,   198,   100,  -133,   117,  -133,   117,   126,
     179,  -133,   117,  -133,   130,   144,  -133,   169,   -10,  -133,
    -133,  -133,    26,    15,    20,  -133,  -133,  -133,  -133,  -133,
    -133,   117,   259,   100,  -133,   222,  -133
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
       0,     0,   121,   120,   151,   152,   153,   149,   138,   150,
     141,     0,     0,    97,   105,     0,   118,   125,   131,   136,
     139,   140,   137,   135,    87,    55,    63,    58,    77,     0,
      62,    49,    51,     0,     0,    78,    53,    37,    23,     0,
       0,     0,    83,     0,     0,    19,     0,    20,   133,   132,
       0,   100,    66,   101,   102,     0,     0,   112,   114,   110,
     113,   111,   109,   115,     0,   123,   122,   124,     0,     0,
       0,   117,   127,   128,   129,   130,     0,     0,     0,     0,
       0,     0,    77,     0,     0,    77,    61,    52,     0,    95,
       0,    80,    77,    86,    84,     0,     0,    22,     0,    27,
     148,   103,     0,   104,    98,    99,   116,   106,   108,   107,
       0,   119,   126,   134,   147,   146,   145,     0,   143,    56,
      54,    77,    59,     0,    50,    82,    77,     0,   138,    81,
      89,    86,    28,     0,     0,    67,     0,   142,     0,     0,
       0,    76,     0,    88,     0,     0,    73,   138,     0,    69,
      72,    75,    71,   105,    92,   144,    57,    85,    91,    93,
      65,     0,    77,     0,    74,    77,    70
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,  -133,   238,   104,  -133,  -133,  -133,  -133,   214,
      17,   -56,   109,  -133,   139,  -133,  -133,  -133,   210,  -133,
     220,   -95,   -49,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,    96,  -133,   -97,  -133,  -133,  -133,  -133,
    -133,    29,  -133,  -133,  -133,  -133,  -133,  -133,  -133,   -62,
    -133,  -133,  -132,  -133,  -133,   140,   -44,  -133,  -133,    27,
    -133,  -133,  -104,  -133,  -133,   -67,  -133,   120,   -59,  -133,
    -133,  -133,    42,  -133,  -133,  -133,  -133
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    21,     6,    14,    15,    18,    19,
      42,    69,    22,    16,    23,    24,    25,    26,    27,    28,
      29,    50,    51,    52,    53,    54,    55,    56,    57,    58,
     151,    59,    96,    97,    98,    99,   154,    60,   172,   205,
     218,   219,   220,    61,    62,   111,   112,   165,   163,    95,
     199,   213,   221,    63,   113,    34,   100,   125,   126,    83,
     138,   139,    84,    85,   140,    86,   146,    87,    88,    89,
      90,   187,   188,    91,   185,    92,    93
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      82,   107,   114,   155,   103,   148,   232,   179,   104,   121,
     116,   118,   119,   161,    11,  -138,  -138,     8,   141,   206,
     121,  -138,   127,   128,   117,   129,   206,   130,   131,   132,
     -90,     1,     9,   200,   177,   180,   203,   120,     1,    35,
      13,   127,   128,    36,   129,   123,   130,   131,   132,   212,
     121,    17,    66,   189,    30,    65,   123,   191,    20,   168,
     158,   180,   133,  -138,  -138,  -138,    12,   196,  -138,  -138,
     134,   135,   136,   181,   124,   121,   135,   136,   135,   136,
     228,   133,   115,  -138,   204,   124,   123,   170,   183,   134,
     135,   136,   105,   106,    70,   233,   157,   152,   153,   234,
     223,   197,   224,   149,     5,   186,   107,     5,   180,     7,
      33,   123,     7,  -138,    20,   124,  -138,    64,    70,   137,
      38,    39,    40,    41,   137,    68,   137,   180,    31,   223,
      32,    71,    72,    73,    74,    70,    94,   235,   137,   214,
     124,   101,   107,   142,   143,   144,   147,   107,   207,   208,
     150,   194,   174,   175,   156,    71,    72,    73,    74,    70,
     222,   216,   160,   145,   186,   162,    75,    76,    77,    78,
      79,    80,    71,    72,    73,    74,   102,    81,   121,   171,
     164,   167,    70,   173,   169,   176,   107,   184,   190,   222,
      75,    76,    77,   217,    79,    80,    71,    72,    73,    74,
      70,    81,   122,    38,    39,    40,    41,    75,    76,    77,
      78,    79,    80,   193,   123,   195,   201,   209,    81,    71,
      72,    73,    74,   202,   -94,   211,   226,   215,   108,   227,
     229,    75,    76,    77,   178,    79,    80,    71,   231,   109,
      74,    10,    81,   124,   230,    43,    67,   159,    37,   192,
     225,    44,    44,   166,    75,    76,    77,   198,    79,    80,
     -68,   -96,   236,    45,    45,    81,   182,     0,    46,    46,
       0,     0,    75,    76,    77,    78,    79,    80,    44,     0,
      47,    47,    44,    81,   110,   -60,   -60,   -60,    44,    44,
      45,   -64,     0,     0,    45,    46,    48,    48,   210,    46,
      45,    45,     0,     0,    74,    46,    46,    47,   -68,     0,
       0,    47,     0,     0,     0,    49,    49,    47,    47,     0,
       0,     0,     0,    48,     0,     0,     0,    48,     0,     0,
       0,     0,     0,    48,    48,     0,    75,    76,    77,    78,
      79,    80,    49,     0,     0,     0,    49,    81,     0,     0,
       0,     0,    49,    49
};

static const yytype_int16 yycheck[] =
{
      44,    50,    64,    98,    48,     3,    16,   139,    15,    24,
      66,    70,    71,   110,    48,     3,     4,    93,    85,     4,
      24,     9,     7,     8,    68,    10,     4,    12,    13,    14,
      50,    66,     0,   165,   138,   139,    38,    81,    66,    99,
     101,     7,     8,   103,    10,    60,    12,    13,    14,    69,
      24,    93,    35,   150,    99,    30,    60,   152,    93,   115,
     104,   165,    47,    51,    52,    53,   100,   162,    56,    57,
      55,    56,    57,   140,    89,    24,    56,    57,    56,    57,
     212,    47,    65,    71,    86,    89,    60,   102,   147,    55,
      56,    57,    99,   100,    18,   105,   100,    36,    37,   231,
     204,   163,   206,   101,     0,   149,   155,     3,   212,     0,
      27,    60,     3,   101,    93,    89,   104,    38,    18,   104,
      95,    96,    97,    98,   104,    15,   104,   231,   100,   233,
     102,    55,    56,    57,    58,    18,    93,   232,   104,   201,
      89,   100,   191,    51,    52,    53,     9,   196,   102,   103,
      86,   100,   125,   126,    82,    55,    56,    57,    58,    18,
     204,    61,    93,    71,   208,    50,    90,    91,    92,    93,
      94,    95,    55,    56,    57,    58,   100,   101,    24,    82,
      75,   100,    18,    36,   100,    47,   235,    93,   100,   233,
      90,    91,    92,    93,    94,    95,    55,    56,    57,    58,
      18,   101,    48,    95,    96,    97,    98,    90,    91,    92,
      93,    94,    95,    38,    60,    47,    38,    46,   101,    55,
      56,    57,    58,   100,    27,   100,   100,    29,    31,    50,
     100,    90,    91,    92,    93,    94,    95,    55,    69,    42,
      58,     3,   101,    89,   100,    31,    36,   108,    28,   153,
     208,    29,    29,   113,    90,    91,    92,    93,    94,    95,
      38,    38,   233,    41,    41,   101,   146,    -1,    46,    46,
      -1,    -1,    90,    91,    92,    93,    94,    95,    29,    -1,
      58,    58,    29,   101,    87,    36,    37,    38,    29,    29,
      41,    38,    -1,    -1,    41,    46,    74,    74,    38,    46,
      41,    41,    -1,    -1,    58,    46,    46,    58,    86,    -1,
      -1,    58,    -1,    -1,    -1,    93,    93,    58,    58,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    74,    74,    -1,    90,    91,    92,    93,
      94,    95,    93,    -1,    -1,    -1,    93,   101,    -1,    -1,
      -1,    -1,    93,    93
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
      95,   101,   162,   165,   168,   169,   171,   173,   174,   175,
     176,   179,   181,   182,    93,   155,   138,   139,   140,   141,
     162,   100,   100,   162,    15,    99,   100,   128,    31,    42,
      87,   151,   152,   160,   155,   116,   117,   162,   174,   174,
     162,    24,    48,    60,    89,   163,   164,     7,     8,    10,
      12,    13,    14,    47,    55,    56,    57,   104,   166,   167,
     170,   171,    51,    52,    53,    71,   172,     9,     3,   101,
      86,   136,    36,    37,   142,   127,    82,   100,   162,   120,
      93,   141,    50,   154,    75,   153,   161,   100,   117,   100,
     102,    82,   144,    36,   165,   165,    47,   168,    93,   158,
     168,   171,   173,   174,    93,   180,   162,   177,   178,   141,
     100,   127,   139,    38,   100,    47,   127,   155,    93,   156,
     158,    38,   100,    38,    86,   145,     4,   102,   103,    46,
      38,   100,    69,   157,   155,    29,    61,    93,   146,   147,
     148,   158,   162,   168,   168,   178,   100,    50,   158,   100,
     100,    69,    16,   105,   158,   127,   147
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
     172,   173,   173,   173,   173,   174,   174,   174,   175,   175,
     175,   175,   176,   177,   177,   178,   179,   180,   181,   182,
     182,   182,   182,   182
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
       1,     1,     2,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     1,     3,     1,     3,     1,
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
#line 142 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        ast.setRoot((yyvsp[0].StmtType));
    }
#line 1677 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 3:
#line 148 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
           {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1685 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 4:
#line 151 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                    {
        (yyval.StmtType) = new SeqNode((yyvsp[-1].StmtType), (yyvsp[0].StmtType));
    }
#line 1693 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 5:
#line 157 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1701 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 6:
#line 160 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                      {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1709 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 7:
#line 166 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                            {
        DEBUG_YACC("Enter SubprogDecl");
        (yyval.StmtType) = new ProcedureDecl(dynamic_cast<ProcedureSpec*>((yyvsp[-1].StmtType)));
        DEBUG_YACC("Leave SubprogDecl");
    }
#line 1719 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 8:
#line 174 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
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
#line 1750 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 9:
#line 203 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             { (yyval.StmtType) = nullptr; }
#line 1756 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 10:
#line 204 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1764 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 11:
#line 210 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                           {
        (yyval.StmtType) = (yyvsp[-1].StmtType);
    }
#line 1772 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 12:
#line 216 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
            {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1780 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 13:
#line 219 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                 {
        (yyval.StmtType) = (yyvsp[-2].StmtType);
        (yyvsp[-2].StmtType)->setNext((yyvsp[0].StmtType));
    }
#line 1789 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 14:
#line 225 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                      {
        SymbolEntry *se = new IdentifierSymbolEntry((yyvsp[-1].type), (yyvsp[-3].StrType), IdentifierSymbolEntry::PARAM);
        (yyval.StmtType) = new ParamNode(se, dynamic_cast<InitOptStmt*>((yyvsp[0].StmtType)));
    }
#line 1798 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 15:
#line 232 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.type) = TypeSystem::integerType;
    }
#line 1806 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 16:
#line 235 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.type) = TypeSystem::boolType;
    }
#line 1814 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 17:
#line 238 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.type) = TypeSystem::stringType;
    }
#line 1822 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 18:
#line 241 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.type) = TypeSystem::naturalType;
    }
#line 1830 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 19:
#line 246 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 { (yyval.StmtType) = nullptr; }
#line 1836 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 20:
#line 247 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                            {
        (yyval.StmtType) = new InitOptStmt((yyvsp[0].ExprType));
    }
#line 1844 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 21:
#line 253 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        DEBUG_YACC("================Enter SubprogBody=================");
        // Enter into new scope.
        identifiers = new SymbolTable(identifiers);
    }
#line 1854 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 22:
#line 257 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                             {
        (yyval.StmtType) = new ProcedureDef(dynamic_cast<ProcedureSpec*>((yyvsp[-7].StmtType)), dynamic_cast<DeclItemOrBodyStmt*>((yyvsp[-4].StmtType)), dynamic_cast<Stmt*>((yyvsp[-3].StmtType)));
        // Leave the scope.
        SymbolTable* ScopeTable = identifiers;
        identifiers = identifiers->getPrev();
        delete ScopeTable;
        DEBUG_YACC("================Leave SubprogBody=================");
    }
#line 1867 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 23:
#line 267 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 { (yyval.StmtType) = nullptr; }
#line 1873 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 24:
#line 268 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                          {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1881 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 25:
#line 275 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.StmtType) = new DeclStmt(dynamic_cast<ObjectDeclStmt*>((yyvsp[0].StmtType)));
    }
#line 1889 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 26:
#line 278 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  {
        (yyval.StmtType) = new DeclStmt(dynamic_cast<ProcedureDecl*>((yyvsp[0].StmtType)));
    }
#line 1897 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 27:
#line 284 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
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
#line 1913 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 28:
#line 295 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                                   {
        DEBUG_YACC("================Enter CONSTANT ObjectDecl=================");
        DefId* id = dynamic_cast<DefId*>((yyvsp[-5].StmtType));
        // InitOptStmt* init = dynamic_cast<InitOptStmt*>($5);
        while(id) {
            id->setType((yyvsp[-2].type));
            id->setConst();
            id = dynamic_cast<DefId*>(id->getNext());
        }
        (yyval.StmtType) = new ObjectDeclStmt(dynamic_cast<DefId*>((yyvsp[-5].StmtType)), dynamic_cast<InitOptStmt*>((yyvsp[-1].StmtType)));
        DEBUG_YACC("================Leave CONSTANT ObjectDecl=================");
    }
#line 1930 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 29:
#line 310 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
            {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1938 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 30:
#line 313 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                         {
        (yyval.StmtType) = (yyvsp[-2].StmtType);
        (yyvsp[-2].StmtType)->setNext((yyvsp[0].StmtType));
    }
#line 1947 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 31:
#line 320 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        IdentifierSymbolEntry *se = new IdentifierSymbolEntry((yyvsp[0].StrType), identifiers->getLevel());
        identifiers->install((yyvsp[0].StrType), se);
        (yyval.StmtType) = new DefId(se);
    }
#line 1957 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 32:
#line 328 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1965 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 33:
#line 331 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                         {
        (yyval.StmtType) = (yyvsp[-1].StmtType);
        (yyvsp[-1].StmtType)->setNext((yyvsp[0].StmtType));
    }
#line 1974 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 34:
#line 338 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  {
        (yyval.StmtType) = new DeclItemOrBodyStmt(dynamic_cast<ProcedureDef*>((yyvsp[0].StmtType)));
    }
#line 1982 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 35:
#line 341 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.StmtType) = new DeclItemOrBodyStmt(dynamic_cast<DeclStmt*>((yyvsp[0].StmtType)));
    }
#line 1990 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 36:
#line 347 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1998 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 37:
#line 350 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                               {
        (yyval.StmtType) = (yyvsp[-1].StmtType);
        (yyvsp[-1].StmtType)->setNext((yyvsp[0].StmtType));
    }
#line 2007 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 38:
#line 357 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.StmtType) = new Stmt((yyvsp[0].StmtType));
    }
#line 2015 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 39:
#line 360 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                       {
        (yyval.StmtType) = new Stmt((yyvsp[0].StmtType));
    }
#line 2023 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 40:
#line 366 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2031 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 41:
#line 369 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2039 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 42:
#line 372 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2047 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 43:
#line 375 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                        {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2055 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 44:
#line 378 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2063 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 45:
#line 384 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2071 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 46:
#line 387 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                   {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2079 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 47:
#line 390 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                   {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2087 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 48:
#line 393 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2095 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 49:
#line 399 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.StmtType) = new NullStmt();
    }
#line 2103 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 50:
#line 405 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                             {
        DEBUG_YACC("================Enter AssignStmt=================");
        SymbolEntry *se = identifiers->lookup((yyvsp[-3].StrType));
        if(!se) {
            std::cerr << "[YACC ERROR]: Can't not get symbolEntry: "<< (yyvsp[-3].StrType) << "\n";
        }
        (yyval.StmtType) = new AssignStmt(se, (yyvsp[-1].ExprType));
        DEBUG_YACC("================Leave AssignStmt=================");
    }
#line 2117 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 51:
#line 417 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                       {
        (yyval.StmtType) = new ReturnStmt(nullptr);
    }
#line 2125 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 52:
#line 420 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                      {
        (yyval.StmtType) = new ReturnStmt((yyvsp[-1].ExprType));
    }
#line 2133 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 53:
#line 426 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                           {
        SymbolEntry* se = identifiers->lookup((yyvsp[-1].StrType));
        if(!se || !se->getType()->isProcedure()) {
            std::cerr << "[YACC ERROR]: Can't not get Procedure type SymbolEntry!\n";
        }
        (yyval.StmtType) = new CallStmt(se);
    }
#line 2145 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 54:
#line 436 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                   {
        (yyval.StmtType) = new ExitStmt((yyvsp[-1].ExprType));
    }
#line 2153 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 55:
#line 442 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             { (yyval.ExprType) = nullptr; }
#line 2159 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 56:
#line 443 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                         {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2167 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 57:
#line 449 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                              {
        (yyval.StmtType) = new IfStmt(dynamic_cast<CondClause*>((yyvsp[-4].StmtType)), dynamic_cast<Stmt*>((yyvsp[-3].StmtType)));
    }
#line 2175 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 58:
#line 455 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2183 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 59:
#line 458 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                       {
        (yyval.StmtType) = (yyvsp[-2].StmtType);
        (yyvsp[-2].StmtType)->setNext((yyvsp[0].StmtType));
    }
#line 2192 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 60:
#line 465 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                          {
        (yyval.StmtType) = new CondClause((yyvsp[-1].ExprType), dynamic_cast<Stmt*>((yyvsp[0].StmtType)));
    }
#line 2200 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 61:
#line 471 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.ExprType) = (yyvsp[-1].ExprType);
    }
#line 2208 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 62:
#line 477 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.ExprType) = (yyvsp[0].ExprType); 
    }
#line 2216 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 63:
#line 482 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 { (yyval.StmtType) = nullptr; }
#line 2222 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 64:
#line 483 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                          {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2230 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 65:
#line 489 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                                         {
        (yyval.StmtType) = new CaseStmt((yyvsp[-5].ExprType), dynamic_cast<Alternative*>((yyvsp[-3].StmtType)));
    }
#line 2238 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 66:
#line 495 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             { (yyval.StmtType) = nullptr; }
#line 2244 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 67:
#line 496 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                   {
        if((yyvsp[-1].StmtType)) {
            (yyval.StmtType) = (yyvsp[-1].StmtType);
            (yyvsp[-1].StmtType)->setNext((yyvsp[0].StmtType));
        } else {
            (yyval.StmtType) = (yyvsp[0].StmtType);
        }
    }
#line 2257 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 68:
#line 507 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                         {
        (yyval.StmtType) = new Alternative(dynamic_cast<Choice*>((yyvsp[-2].StmtType)), dynamic_cast<Stmt*>((yyvsp[0].StmtType)));
    }
#line 2265 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 69:
#line 513 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2273 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 70:
#line 516 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                  {
        (yyval.StmtType) = (yyvsp[-2].StmtType);
        (yyvsp[-2].StmtType)->setNext((yyvsp[0].StmtType));
    }
#line 2282 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 71:
#line 523 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.StmtType) = new Choice((yyvsp[0].ExprType));
    }
#line 2290 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 72:
#line 526 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                            {
        (yyval.StmtType) = new Choice(dynamic_cast<DiscreteRange*>((yyvsp[0].StmtType)));
    }
#line 2298 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 73:
#line 529 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.StmtType) = new Choice(true);
    }
#line 2306 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 74:
#line 535 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                             {
        Type* type = dynamic_cast<Range*>((yyvsp[0].StmtType))->getType();
        SymbolEntry* se = new IdentifierSymbolEntry(type, (yyvsp[-2].StrType), identifiers->getLevel());
        (yyval.StmtType) = new DiscreteRange(se, dynamic_cast<Range*>((yyvsp[0].StmtType)));
    }
#line 2316 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 75:
#line 540 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                {
        (yyval.StmtType) = new DiscreteRange(dynamic_cast<Range*>((yyvsp[0].StmtType)));
    }
#line 2324 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 76:
#line 546 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                                   {
        (yyval.StmtType) = new LoopStmt(dynamic_cast<LabelOpt*>((yyvsp[-4].StmtType)), dynamic_cast<Iteration*>((yyvsp[-3].StmtType)), dynamic_cast<BasicLoopStmt*>((yyvsp[-2].StmtType)));
    }
#line 2332 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 77:
#line 551 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  { (yyval.StmtType) = nullptr; }
#line 2338 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 78:
#line 552 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                           {
        SymbolEntry *se = new IdentifierSymbolEntry(TypeSystem::integerType, (yyvsp[-1].StrType), identifiers->getLevel());
        identifiers->install((yyvsp[-1].StrType), se);
        (yyval.StmtType) = new LabelOpt(se);
    }
#line 2348 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 79:
#line 559 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                   { (yyval.StmtType) = nullptr; }
#line 2354 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 80:
#line 560 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                          {
        (yyval.StmtType) = new Iteration((yyvsp[0].ExprType));
    }
#line 2362 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 81:
#line 563 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                            {
        (yyval.StmtType) = new Iteration(dynamic_cast<IterPart*>((yyvsp[-2].StmtType)), (yyvsp[-1].SignType), dynamic_cast<DiscreteRange*>((yyvsp[0].StmtType)));
    }
#line 2370 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 82:
#line 569 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                        {
        SymbolEntry *se = new IdentifierSymbolEntry(TypeSystem::integerType, (yyvsp[-1].StrType), identifiers->getLevel());
        identifiers->install((yyvsp[-1].StrType), se);
        (yyval.StmtType) = new IterPart(se);
    }
#line 2380 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 83:
#line 576 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                    { (yyval.SignType) = nullptr; }
#line 2386 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 84:
#line 577 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  {
        (yyval.SignType) = new OpSignNode(OpSignNode::REVERSE);
    }
#line 2394 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 85:
#line 583 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                               {
        (yyval.StmtType) = new BasicLoopStmt(dynamic_cast<Stmt*>((yyvsp[-2].StmtType)));
    }
#line 2402 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 86:
#line 589 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 { (yyval.ExprType) = nullptr; }
#line 2408 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 87:
#line 590 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        SymbolEntry* se = identifiers->lookup((yyvsp[0].StrType));
        (yyval.ExprType) = new Id(se);
    }
#line 2417 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 88:
#line 597 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                {
        SymbolEntry *se = new IdentifierSymbolEntry(TypeSystem::integerType, (yyvsp[-1].StrType), identifiers->getLevel());
        identifiers->install((yyvsp[-1].StrType), se);
        (yyval.StmtType) = new DiscreteRange(se, dynamic_cast<Range*>((yyvsp[0].StmtType)));
    }
#line 2427 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 89:
#line 602 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                {
        (yyval.StmtType) = new DiscreteRange(dynamic_cast<Range*>((yyvsp[0].StmtType)));
    }
#line 2435 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 90:
#line 607 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                        { (yyval.StmtType) = nullptr; }
#line 2441 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 91:
#line 608 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                      {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2449 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 92:
#line 614 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                               {
        (yyval.StmtType) = new Range((yyvsp[-2].ExprType), (yyvsp[0].ExprType));
    }
#line 2457 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 93:
#line 620 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                                       {
        (yyval.StmtType) = new Block(dynamic_cast<LabelOpt*>((yyvsp[-5].StmtType)), dynamic_cast<DeclItemOrBodyStmt*>((yyvsp[-4].StmtType)), dynamic_cast<Stmt*>((yyvsp[-3].StmtType)));
    }
#line 2465 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 94:
#line 625 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                   { (yyval.StmtType) = nullptr; }
#line 2471 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 95:
#line 626 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                           {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2479 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 96:
#line 632 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                       {
        DEBUG_YACC("================Enter BlockBody=================");
        (yyval.StmtType) = (yyvsp[0].StmtType);
        DEBUG_YACC("================Enter BlockBody=================");

    }
#line 2490 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 97:
#line 641 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2498 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 98:
#line 644 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                      {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2506 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 99:
#line 647 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                           {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2514 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 100:
#line 653 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
          {
        (yyval.SignType) = new OpSignNode(OpSignNode::AND);
    }
#line 2522 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 101:
#line 656 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.SignType) = new OpSignNode(OpSignNode::OR);
    }
#line 2530 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 102:
#line 659 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::XOR);
    }
#line 2538 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 103:
#line 665 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.SignType) = new OpSignNode(OpSignNode::ANDTHEN);
    }
#line 2546 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 104:
#line 668 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  {
        (yyval.SignType) = new OpSignNode(OpSignNode::ORELSE);
    }
#line 2554 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 105:
#line 674 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                       {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2562 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 106:
#line 677 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                                       {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2570 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 107:
#line 680 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                            {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), dynamic_cast<Range*>((yyvsp[0].StmtType)), (yyvsp[-1].SignType));
    }
#line 2578 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 108:
#line 683 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                                 {
        SymbolEntry* se = new IdentifierSymbolEntry(TypeSystem::integerType, (yyvsp[0].StrType), identifiers->getLevel());
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), se, (yyvsp[-1].SignType));
    }
#line 2587 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 109:
#line 690 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
         {
        (yyval.SignType) = new OpSignNode(OpSignNode::EQ);
    }
#line 2595 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 110:
#line 693 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.SignType) = new OpSignNode(OpSignNode::NE);
    }
#line 2603 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 111:
#line 696 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.SignType) = new OpSignNode(OpSignNode::LE);
    }
#line 2611 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 112:
#line 699 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.SignType) = new OpSignNode(OpSignNode::LTEQ);
    }
#line 2619 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 113:
#line 702 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.SignType) = new OpSignNode(OpSignNode::GE);
    }
#line 2627 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 114:
#line 705 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.SignType) = new OpSignNode(OpSignNode::GTEQ);
    }
#line 2635 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 115:
#line 711 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
         {
        (yyval.SignType) = new OpSignNode(OpSignNode::IN);
    }
#line 2643 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 116:
#line 714 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.SignType) = new OpSignNode(OpSignNode::NOTIN);
    }
#line 2651 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 117:
#line 720 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.ExprType) = new BinaryExpr((yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2659 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 118:
#line 723 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2667 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 119:
#line 726 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                       {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2675 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 120:
#line 732 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
          {
        (yyval.SignType) = new OpSignNode(OpSignNode::ADD);
    }
#line 2683 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 121:
#line 735 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::SUB);
    }
#line 2691 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 122:
#line 741 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
          {
        (yyval.SignType) = new OpSignNode(OpSignNode::ADD);
    }
#line 2699 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 123:
#line 744 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::SUB);
    }
#line 2707 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 124:
#line 747 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                    {
        (yyval.SignType) = new OpSignNode(OpSignNode::SINGLEAND);
    }
#line 2715 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 125:
#line 753 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2723 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 126:
#line 756 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                  {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2731 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 127:
#line 762 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
          {
        (yyval.SignType) = new OpSignNode(OpSignNode::MUL);
    }
#line 2739 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 128:
#line 765 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::DIV);
    }
#line 2747 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 129:
#line 768 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::MOD);
    }
#line 2755 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 130:
#line 771 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::REM);
    }
#line 2763 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 131:
#line 777 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2771 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 132:
#line 780 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                      {
        (yyval.ExprType) = new FactorExpr((yyvsp[0].ExprType), FactorExpr::NOT);
    }
#line 2779 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 133:
#line 783 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                      {
        (yyval.ExprType) = new FactorExpr((yyvsp[0].ExprType), FactorExpr::ABS);
    }
#line 2787 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 134:
#line 786 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), new OpSignNode(OpSignNode::EXPON));
    }
#line 2795 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 135:
#line 792 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2803 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 136:
#line 795 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2811 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 137:
#line 798 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                               {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2819 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 138:
#line 804 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        SymbolEntry* se = identifiers->lookup((yyvsp[0].StrType));
        (yyval.ExprType) = new Id(se);
    }
#line 2828 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 139:
#line 808 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2836 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 140:
#line 811 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2844 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 141:
#line 814 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        SymbolEntry *se = new IdentifierSymbolEntry(TypeSystem::integerType, "Integer", 0);
        globals->install("Integer", se);
        (yyval.ExprType) = new Id(se);
    }
#line 2854 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 142:
#line 822 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                {
        (yyval.ExprType) = new Id(dynamic_cast<Id*>((yyvsp[-3].ExprType)), (yyvsp[-1].ExprType));
    }
#line 2862 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 143:
#line 828 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
            {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2870 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 144:
#line 831 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                             {
        (yyval.ExprType) = (yyvsp[-2].ExprType);
        (yyvsp[-2].ExprType)->setNext((yyvsp[0].ExprType));
    }
#line 2879 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 145:
#line 838 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2887 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 146:
#line 844 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                           {
        (yyval.ExprType) = new Id(dynamic_cast<Id*>((yyvsp[-2].ExprType)), (yyvsp[0].StrType));
    }
#line 2895 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 147:
#line 850 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.StrType) = (yyvsp[0].StrType);
    }
#line 2903 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 148:
#line 856 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                               {
        (yyval.ExprType) = (yyvsp[-1].ExprType);
    }
#line 2911 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 149:
#line 862 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        SymbolEntry* se = new ConstantSymbolEntry(TypeSystem::integerType, (yyvsp[0].IntType));
        (yyval.ExprType) = new Constant(se);
    }
#line 2920 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 150:
#line 866 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                        {
        SymbolEntry* se = new ConstantSymbolEntry(TypeSystem::stringType, (yyvsp[0].StrType));
        (yyval.ExprType) = new Constant(se);
    }
#line 2929 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 151:
#line 870 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.ExprType) = nullptr;
    }
#line 2937 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 152:
#line 873 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
           {
        SymbolEntry* se = new ConstantSymbolEntry(TypeSystem::boolType, true);
        (yyval.ExprType) = new Constant(se);
    }
#line 2946 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 153:
#line 877 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
            {
        SymbolEntry* se = new ConstantSymbolEntry(TypeSystem::boolType, false);
        (yyval.ExprType) = new Constant(se);
    }
#line 2955 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;


#line 2959 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"

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
#line 882 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"


int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}
