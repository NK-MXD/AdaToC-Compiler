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

    std::vector<bool> whileIters;
    std::vector<ProcedureSpec*> procedureIters;

    #define DEBUG_SWITCH_TYPE_CHECK 0
    #if DEBUG_SWITCH_TYPE_CHECK
    #define DEBUG_YACC(str) std::cerr<<"[YACC INFO]:"<<str<<"\n";
    #else
    #define DEBUG_YACC(str) //
    #endif

    int yylex();
    int yyerror(char const*);

#line 93 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"




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
#line 27 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"

    #include "SymbolTable.h"
    #include "Ast.h"

#line 144 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"

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

#line 270 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"

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
#define YYLAST   361

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  106
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  78
/* YYNRULES -- Number of rules.  */
#define YYNRULES  154
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  239

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
       0,   145,   145,   151,   154,   160,   163,   169,   181,   181,
     215,   216,   222,   228,   231,   237,   245,   248,   251,   254,
     259,   260,   266,   266,   285,   286,   293,   296,   302,   313,
     328,   331,   338,   346,   349,   356,   359,   365,   368,   375,
     378,   384,   387,   390,   393,   396,   402,   405,   408,   411,
     417,   423,   435,   438,   444,   450,   456,   457,   463,   469,
     472,   479,   485,   491,   496,   497,   503,   509,   510,   521,
     527,   530,   537,   540,   543,   549,   554,   560,   571,   572,
     579,   583,   587,   594,   602,   603,   609,   615,   616,   623,
     628,   633,   634,   640,   646,   651,   652,   658,   667,   670,
     673,   679,   682,   685,   691,   694,   700,   703,   706,   709,
     716,   719,   722,   725,   728,   731,   737,   740,   746,   749,
     752,   758,   761,   767,   770,   773,   779,   782,   788,   791,
     794,   797,   803,   806,   809,   812,   818,   821,   824,   830,
     837,   840,   843,   851,   857,   860,   867,   873,   879,   885,
     891,   895,   899,   902,   906
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
  "$@1", "FormalPartOpt", "FormalPart", "Params", "Param", "Type",
  "InitOpt", "SubprogBody", "$@2", "DeclPart", "Decl", "ObjectDecl",
  "DefIds", "DefId", "DeclItemOrBodys", "DeclItemOrBody", "Statements",
  "Statement", "SimpleStmt", "CompoundStmt", "NullStmt", "AssignStmt",
  "ReturnStmt", "ProcedureCall", "ExitStmt", "WhenOpt", "IfStmt",
  "CondClauses", "CondClause", "CondPart", "Condition", "ElseOpt",
  "CaseStmt", "Alternatives", "Alternative", "Choices", "Choice",
  "DiscreteWithRange", "LoopStmt", "LabelOpt", "Iteration", "IterPart",
  "ReverseOpt", "BasicLoop", "IdOpt", "DiscreteRange", "RangeConstrOpt",
  "Range", "Block", "BlockDecl", "BlockBody", "Expression", "Logical",
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

#define YYPACT_NINF (-132)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-140)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -41,   -62,    39,   -41,  -132,  -132,   -16,  -132,  -132,  -132,
    -132,  -132,  -132,   -53,   -39,   -27,  -132,  -132,  -132,  -132,
    -132,    47,  -132,  -132,    -2,  -132,   -39,  -132,    -3,   -47,
    -132,   253,    80,    84,    31,  -132,    33,   -27,  -132,   131,
      40,   131,    26,   118,   -10,  -132,   250,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,    96,  -132,
       7,  -132,  -132,    40,    33,  -132,  -132,  -132,  -132,   120,
    -132,   120,  -132,   260,   260,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,   131,    95,  -132,    30,   147,    99,  -132,
     128,     3,  -132,  -132,  -132,    61,   164,  -132,   253,    81,
      57,  -132,  -132,    10,   131,  -132,  -132,   -39,    73,   131,
     121,    93,    47,    85,  -132,   131,    91,   120,   131,   107,
    -132,  -132,  -132,   -11,   138,  -132,   149,  -132,   131,   131,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,   184,  -132,  -132,
    -132,   131,   159,   147,    99,  -132,  -132,  -132,  -132,   147,
     260,   131,   133,   253,   131,   198,   239,  -132,  -132,    56,
    -132,   199,  -132,   253,    40,  -132,   172,   207,  -132,  -132,
      57,   132,  -132,  -132,   155,    57,  -132,  -132,  -132,    14,
    -132,  -132,  -132,  -132,    -6,     5,  -132,     8,    99,  -132,
    -132,  -132,  -132,   254,  -132,   201,  -132,  -132,   264,   156,
      -9,  -132,  -132,    40,  -132,   131,  -132,   228,   103,  -132,
     131,   158,   209,  -132,   131,  -132,   161,  -132,   170,  -132,
     202,     0,  -132,  -132,  -132,    57,    16,    -6,  -132,  -132,
    -132,  -132,  -132,   131,   253,   103,  -132,   240,  -132
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     3,     5,     0,     6,     8,     1,
       4,    22,     7,    10,    24,     0,     9,    11,    32,    27,
      35,     0,    36,    26,     0,    30,    25,    33,     0,     0,
      13,    78,     0,     0,     0,    34,     0,     0,    12,     0,
      87,     0,     0,     0,   139,   142,    78,    37,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    80,    49,
       0,   140,   141,    87,     0,    16,    18,    19,    17,    20,
      31,    20,    14,     0,     0,   122,   121,   152,   153,   154,
     150,   139,   151,     0,     0,    98,   106,     0,   119,   126,
     132,   137,   138,   136,    88,    56,    64,    59,    78,     0,
      63,    50,    52,     0,     0,    79,    38,    24,     0,     0,
       0,    84,     0,     0,    54,     0,     0,    20,     0,     0,
      15,   134,   133,     0,   101,    67,   102,   103,     0,     0,
     113,   115,   111,   114,   112,   110,   116,     0,   124,   123,
     125,     0,     0,     0,   118,   128,   129,   130,   131,     0,
       0,     0,     0,    78,     0,     0,    78,    62,    53,     0,
      96,     0,    81,    78,    87,    85,     0,     0,   148,   147,
     146,     0,   144,    23,     0,    21,    28,   149,   104,     0,
     105,    99,   100,   117,   107,   109,   108,     0,   120,   127,
     135,    57,    55,    78,    60,     0,    51,    83,    78,     0,
     139,    82,    90,    87,   143,     0,    29,     0,     0,    68,
       0,     0,     0,    77,     0,    89,     0,   145,     0,    74,
     139,     0,    70,    73,    76,    72,   106,    93,    58,    86,
      92,    94,    66,     0,    78,     0,    75,    78,    71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,  -132,   269,   141,  -132,  -132,  -132,  -132,  -132,
     237,   -19,    22,   154,  -132,   177,  -132,  -132,  -132,   255,
    -132,   261,   -94,   -45,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,   136,  -132,   -76,  -132,  -132,  -132,
    -132,  -132,    66,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
     -61,  -132,  -132,  -131,  -132,  -132,   191,   -36,  -132,  -132,
     115,  -132,  -132,  -120,  -132,  -132,   -51,  -132,   157,   -55,
     -31,  -132,  -132,   102,  -132,  -132,  -132,  -132
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    19,     6,    13,    16,    17,    29,
      30,    69,   119,    20,    14,    21,    22,    23,    24,    25,
      26,    27,    46,    47,    48,    49,    50,    51,    52,    53,
      54,   152,    55,    96,    97,    98,    99,   155,    56,   179,
     209,   221,   222,   223,    57,    58,   110,   111,   166,   164,
      95,   201,   215,   224,    59,   112,    32,   100,   128,   129,
      85,   141,   142,    86,    87,   143,    88,   149,    89,    90,
      91,    61,   171,   172,    62,   169,    92,    93
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      60,   106,   116,    84,   156,   104,   113,   103,  -139,  -139,
     113,   186,   210,   124,  -139,    60,   234,    71,   121,   122,
     210,   184,   187,   130,   131,     1,   132,     1,   133,   134,
     135,     8,    11,   162,   124,   202,   144,   130,   131,     9,
     132,   -91,   133,   134,   135,   117,   187,   123,    15,   126,
     138,   139,   207,    37,    18,    38,  -139,  -139,  -139,   193,
     214,  -139,  -139,   136,   138,   139,    28,    60,   159,   198,
     126,   137,   138,   139,    31,   191,  -139,   136,   127,   170,
     124,   124,   175,   230,    12,   137,   138,   139,   226,   105,
     227,   177,   188,   120,   187,   190,    36,    33,   140,   127,
     208,    34,   236,   199,   115,   235,  -139,   114,   115,  -139,
     158,   106,   140,   187,    64,   226,   126,   126,    63,   124,
     140,    73,    60,   -95,    18,    60,   101,   107,    65,    66,
      67,    68,    60,    94,   140,   118,    73,   150,   108,   174,
     237,     5,   216,   125,     5,   127,   127,   151,   106,    73,
     145,   146,   147,   106,     7,   126,   196,     7,    74,    75,
      76,    77,    60,   157,   219,    73,   161,    60,   165,   170,
     148,   163,   225,    74,    75,    76,    77,    73,   168,    65,
      66,    67,    68,   109,   127,   180,    74,    75,    76,    77,
      73,   173,   106,    78,    79,    80,   220,    82,    45,   225,
     153,   154,    74,    60,    83,    77,    60,   176,    78,    79,
      80,    81,    82,    45,    74,    75,    76,    77,   102,    83,
     178,    78,    79,    80,    81,    82,    45,    74,    75,    76,
      77,   183,    83,   192,   204,   205,   195,    78,    79,    80,
      81,    82,    45,   181,   182,   203,   197,   211,    83,    78,
      79,    80,   185,    82,    45,   206,   213,   218,   228,   229,
      83,   231,    78,    79,    80,   200,    82,    45,    39,    39,
     232,   233,    10,    83,    72,   -61,   -61,   -61,   -69,    39,
      40,    40,    39,    39,   160,    41,    41,    35,   -97,    70,
     194,    40,   -65,    39,    40,    40,    41,    42,    42,    41,
      41,   238,   212,   167,     0,    40,   189,   217,    42,     0,
      41,    42,    42,    43,    43,     0,     0,     0,    77,     0,
       0,     0,    42,     0,    43,     0,   -69,    43,    43,     0,
       0,     0,    44,    44,    45,    45,     0,     0,    43,     0,
       0,     0,     0,    44,     0,    45,    44,    44,    45,    45,
      78,    79,    80,    81,    82,    45,     0,    44,     0,    45,
       0,    83
};

static const yytype_int16 yycheck[] =
{
      31,    46,    63,    39,    98,    15,     3,    43,     3,     4,
       3,   142,     4,    24,     9,    46,    16,    36,    73,    74,
       4,   141,   142,     7,     8,    66,    10,    66,    12,    13,
      14,    93,    48,   109,    24,   166,    87,     7,     8,     0,
      10,    50,    12,    13,    14,    64,   166,    83,   101,    60,
      56,    57,    38,   100,    93,   102,    51,    52,    53,   153,
      69,    56,    57,    47,    56,    57,    93,    98,   104,   163,
      60,    55,    56,    57,    27,   151,    71,    47,    89,   115,
      24,    24,   118,   214,   100,    55,    56,    57,   208,    99,
     210,   102,   143,    71,   214,   150,    99,    99,   104,    89,
      86,   103,   233,   164,   101,   105,   101,   100,   101,   104,
     100,   156,   104,   233,    30,   235,    60,    60,    38,    24,
     104,    18,   153,    27,    93,   156,   100,    31,    95,    96,
      97,    98,   163,    93,   104,    15,    18,     9,    42,   117,
     234,     0,   203,    48,     3,    89,    89,    86,   193,    18,
      51,    52,    53,   198,     0,    60,   100,     3,    55,    56,
      57,    58,   193,    82,    61,    18,    93,   198,    75,   205,
      71,    50,   208,    55,    56,    57,    58,    18,    93,    95,
      96,    97,    98,    87,    89,    36,    55,    56,    57,    58,
      18,   100,   237,    90,    91,    92,    93,    94,    95,   235,
      36,    37,    55,   234,   101,    58,   237,   100,    90,    91,
      92,    93,    94,    95,    55,    56,    57,    58,   100,   101,
      82,    90,    91,    92,    93,    94,    95,    55,    56,    57,
      58,    47,   101,   100,   102,   103,    38,    90,    91,    92,
      93,    94,    95,   128,   129,    38,    47,    46,   101,    90,
      91,    92,    93,    94,    95,   100,   100,    29,   100,    50,
     101,   100,    90,    91,    92,    93,    94,    95,    29,    29,
     100,    69,     3,   101,    37,    36,    37,    38,    38,    29,
      41,    41,    29,    29,   107,    46,    46,    26,    38,    34,
     154,    41,    38,    29,    41,    41,    46,    58,    58,    46,
      46,   235,    38,   112,    -1,    41,   149,   205,    58,    -1,
      46,    58,    58,    74,    74,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    58,    -1,    74,    -1,    86,    74,    74,    -1,
      -1,    -1,    93,    93,    95,    95,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    93,    -1,    95,    93,    93,    95,    95,
      90,    91,    92,    93,    94,    95,    -1,    93,    -1,    95,
      -1,   101
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    66,   107,   108,   109,   110,   111,   119,    93,     0,
     109,    48,   100,   112,   120,   101,   113,   114,    93,   110,
     119,   121,   122,   123,   124,   125,   126,   127,    93,   115,
     116,    27,   162,    99,   103,   127,    99,   100,   102,    29,
      41,    46,    58,    74,    93,    95,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   138,   144,   150,   151,   160,
     176,   177,   180,    38,    30,    95,    96,    97,    98,   117,
     125,   117,   116,    18,    55,    56,    57,    58,    90,    91,
      92,    93,    94,   101,   163,   166,   169,   170,   172,   174,
     175,   176,   182,   183,    93,   156,   139,   140,   141,   142,
     163,   100,   100,   163,    15,    99,   129,    31,    42,    87,
     152,   153,   161,     3,   100,   101,   156,   117,    15,   118,
     118,   175,   175,   163,    24,    48,    60,    89,   164,   165,
       7,     8,    10,    12,    13,    14,    47,    55,    56,    57,
     104,   167,   168,   171,   172,    51,    52,    53,    71,   173,
       9,    86,   137,    36,    37,   143,   128,    82,   100,   163,
     121,    93,   142,    50,   155,    75,   154,   162,    93,   181,
     163,   178,   179,   100,   118,   163,   100,   102,    82,   145,
      36,   166,   166,    47,   169,    93,   159,   169,   172,   174,
     175,   142,   100,   128,   140,    38,   100,    47,   128,   156,
      93,   157,   159,    38,   102,   103,   100,    38,    86,   146,
       4,    46,    38,   100,    69,   158,   156,   179,    29,    61,
      93,   147,   148,   149,   159,   163,   169,   169,   100,    50,
     159,   100,   100,    69,    16,   105,   159,   128,   148
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   106,   107,   108,   108,   109,   109,   110,   112,   111,
     113,   113,   114,   115,   115,   116,   117,   117,   117,   117,
     118,   118,   120,   119,   121,   121,   122,   122,   123,   123,
     124,   124,   125,   126,   126,   127,   127,   128,   128,   129,
     129,   130,   130,   130,   130,   130,   131,   131,   131,   131,
     132,   133,   134,   134,   135,   136,   137,   137,   138,   139,
     139,   140,   141,   142,   143,   143,   144,   145,   145,   146,
     147,   147,   148,   148,   148,   149,   149,   150,   151,   151,
     152,   152,   152,   153,   154,   154,   155,   156,   156,   157,
     157,   158,   158,   159,   160,   161,   161,   162,   163,   163,
     163,   164,   164,   164,   165,   165,   166,   166,   166,   166,
     167,   167,   167,   167,   167,   167,   168,   168,   169,   169,
     169,   170,   170,   171,   171,   171,   172,   172,   173,   173,
     173,   173,   174,   174,   174,   174,   175,   175,   175,   176,
     176,   176,   176,   177,   178,   178,   179,   180,   181,   182,
     183,   183,   183,   183,   183
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     2,     0,     4,
       0,     1,     3,     1,     3,     4,     1,     1,     1,     1,
       0,     2,     0,     8,     0,     1,     1,     1,     5,     6,
       1,     3,     1,     1,     2,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     2,     3,     2,     4,     0,     2,     6,     1,
       3,     2,     2,     1,     0,     2,     7,     0,     2,     4,
       1,     3,     1,     1,     1,     3,     1,     5,     0,     2,
       0,     2,     3,     3,     0,     1,     4,     0,     1,     2,
       1,     0,     2,     3,     6,     0,     2,     2,     1,     3,
       3,     1,     1,     1,     2,     2,     1,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     2,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     1,     1
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
#line 145 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        ast.setRoot((yyvsp[0].StmtType));
    }
#line 1682 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 3:
#line 151 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
           {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1690 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 4:
#line 154 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                    {
        (yyval.StmtType) = new SeqNode((yyvsp[-1].StmtType), (yyvsp[0].StmtType));
    }
#line 1698 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 5:
#line 160 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1706 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 6:
#line 163 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                      {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1714 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 7:
#line 169 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                            {
        DEBUG_YACC("================Enter SubprogDecl=================");
        (yyval.StmtType) = new ProcedureDecl(dynamic_cast<ProcedureSpec*>((yyvsp[-1].StmtType)));

        SymbolTable* ScopeTable = identifiers;
        identifiers = identifiers->getPrev();
        delete ScopeTable;
        DEBUG_YACC("================Leave SubprogDecl=================");
    }
#line 1728 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 8:
#line 181 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                           {
        DEBUG_YACC("================Enter SubprogSpec=================");
        // Register procedure name into symbol table.
        Type* proType = new ProcedureType();
        SymbolEntry *se = identifiers->lookup((yyvsp[0].StrType));
        if(!se) {
            se = new IdentifierSymbolEntry(proType, (yyvsp[0].StrType), identifiers->getLevel());
            identifiers->install((yyvsp[0].StrType), se);
        }
        identifiers = new SymbolTable(identifiers);
    }
#line 1744 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 9:
#line 191 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                    {
        SymbolEntry *se = identifiers->lookup((yyvsp[-2].StrType));
        ProcedureType* proType = dynamic_cast<ProcedureType*>(se->getType());
        // Define procedure type.
        ParamNode* param = nullptr;
        if((yyvsp[0].StmtType)) {
            param = dynamic_cast<ParamNode*>((yyvsp[0].StmtType));
            std::vector<Type*> paramTypes;
            std::vector<SymbolEntry*> paramIds;
            while (param) {
                SymbolEntry* paramSe = param->getParamSymbol();
                paramTypes.push_back(paramSe->getType());
                paramIds.push_back(paramSe);
                param = dynamic_cast<ParamNode*>(param->getNext());
            }
            proType->setParams(paramTypes, paramIds);
        }
        // Define SubprogSpec with ast node.
        (yyval.StmtType) = new ProcedureSpec(se, param);
        DEBUG_YACC("================Leave SubprogSpec=================");
    }
#line 1770 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 10:
#line 215 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             { (yyval.StmtType) = nullptr; }
#line 1776 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 11:
#line 216 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1784 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 12:
#line 222 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                           {
        (yyval.StmtType) = (yyvsp[-1].StmtType);
    }
#line 1792 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 13:
#line 228 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
            {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1800 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 14:
#line 231 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                 {
        (yyval.StmtType) = (yyvsp[-2].StmtType);
        (yyvsp[-2].StmtType)->setNext((yyvsp[0].StmtType));
    }
#line 1809 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 15:
#line 237 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                      {
        SymbolEntry *se = new IdentifierSymbolEntry((yyvsp[-1].type), (yyvsp[-3].StrType), IdentifierSymbolEntry::PARAM);
        identifiers->install((yyvsp[-3].StrType), se);
        (yyval.StmtType) = new ParamNode(se, dynamic_cast<InitOptStmt*>((yyvsp[0].StmtType)));
    }
#line 1819 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 16:
#line 245 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.type) = TypeSystem::integerType;
    }
#line 1827 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 17:
#line 248 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.type) = TypeSystem::boolType;
    }
#line 1835 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 18:
#line 251 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.type) = TypeSystem::stringType;
    }
#line 1843 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 19:
#line 254 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.type) = TypeSystem::naturalType;
    }
#line 1851 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 20:
#line 259 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 { (yyval.StmtType) = nullptr; }
#line 1857 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 21:
#line 260 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                            {
        (yyval.StmtType) = new InitOptStmt((yyvsp[0].ExprType));
    }
#line 1865 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 22:
#line 266 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        DEBUG_YACC("================Enter SubprogBody=================");
        // Enter into new scope.
        identifiers = new SymbolTable(identifiers);
        procedureIters.push_back(dynamic_cast<ProcedureSpec*>((yyvsp[-1].StmtType)));
    }
#line 1876 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 23:
#line 271 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                             {
        procedureIters.pop_back();
        ProcedureSpec* prev = procedureIters.empty()? nullptr : procedureIters.back();
        (yyval.StmtType) = new ProcedureDef(dynamic_cast<ProcedureSpec*>((yyvsp[-7].StmtType)), dynamic_cast<DeclItemOrBodyStmt*>((yyvsp[-4].StmtType)), dynamic_cast<Stmt*>((yyvsp[-3].StmtType)), prev);
        // Leave the scope.
        SymbolTable* ScopeTable = identifiers;
        SymbolTable* PrevTable = identifiers->getPrev();
        identifiers = PrevTable->getPrev();
        delete ScopeTable;
        delete PrevTable;
        DEBUG_YACC("================Leave SubprogBody=================");
    }
#line 1893 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 24:
#line 285 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 { (yyval.StmtType) = nullptr; }
#line 1899 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 25:
#line 286 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                          {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1907 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 26:
#line 293 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.StmtType) = new DeclStmt(dynamic_cast<ObjectDeclStmt*>((yyvsp[0].StmtType)));
    }
#line 1915 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 27:
#line 296 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  {
        (yyval.StmtType) = new DeclStmt(dynamic_cast<ProcedureDecl*>((yyvsp[0].StmtType)));
    }
#line 1923 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 28:
#line 302 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
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
#line 1939 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 29:
#line 313 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
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
#line 1956 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 30:
#line 328 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
            {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1964 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 31:
#line 331 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                         {
        (yyval.StmtType) = (yyvsp[-2].StmtType);
        (yyvsp[-2].StmtType)->setNext((yyvsp[0].StmtType));
    }
#line 1973 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 32:
#line 338 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        IdentifierSymbolEntry *se = new IdentifierSymbolEntry((yyvsp[0].StrType), identifiers->getLevel());
        identifiers->install((yyvsp[0].StrType), se);
        (yyval.StmtType) = new DefId(se);
    }
#line 1983 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 33:
#line 346 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1991 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 34:
#line 349 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                         {
        (yyval.StmtType) = (yyvsp[-1].StmtType);
        (yyvsp[-1].StmtType)->setNext((yyvsp[0].StmtType));
    }
#line 2000 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 35:
#line 356 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  {
        (yyval.StmtType) = new DeclItemOrBodyStmt(dynamic_cast<ProcedureDef*>((yyvsp[0].StmtType)));
    }
#line 2008 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 36:
#line 359 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.StmtType) = new DeclItemOrBodyStmt(dynamic_cast<DeclStmt*>((yyvsp[0].StmtType)));
    }
#line 2016 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 37:
#line 365 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2024 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 38:
#line 368 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                               {
        (yyval.StmtType) = (yyvsp[-1].StmtType);
        (yyvsp[-1].StmtType)->setNext((yyvsp[0].StmtType));
    }
#line 2033 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 39:
#line 375 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.StmtType) = new Stmt((yyvsp[0].StmtType));
    }
#line 2041 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 40:
#line 378 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                       {
        (yyval.StmtType) = new Stmt((yyvsp[0].StmtType));
    }
#line 2049 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 41:
#line 384 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2057 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 42:
#line 387 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2065 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 43:
#line 390 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2073 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 44:
#line 393 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                        {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2081 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 45:
#line 396 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2089 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 46:
#line 402 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2097 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 47:
#line 405 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                   {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2105 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 48:
#line 408 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                   {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2113 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 49:
#line 411 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2121 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 50:
#line 417 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.StmtType) = new NullStmt();
    }
#line 2129 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 51:
#line 423 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                             {
        DEBUG_YACC("================Enter AssignStmt=================");
        SymbolEntry *se = identifiers->lookup((yyvsp[-3].StrType));
        if(!se) {
            std::cerr << "[YACC ERROR]: Can't not get symbolEntry: "<< (yyvsp[-3].StrType) << "\n";
        }
        (yyval.StmtType) = new AssignStmt(se, (yyvsp[-1].ExprType));
        DEBUG_YACC("================Leave AssignStmt=================");
    }
#line 2143 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 52:
#line 435 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                       {
        (yyval.StmtType) = new ReturnStmt(nullptr);
    }
#line 2151 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 53:
#line 438 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                      {
        (yyval.StmtType) = new ReturnStmt((yyvsp[-1].ExprType));
    }
#line 2159 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 54:
#line 444 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.StmtType) = new CallStmt(dynamic_cast<Id*>((yyvsp[-1].ExprType)));
    }
#line 2167 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 55:
#line 450 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                   {
        (yyval.StmtType) = new ExitStmt((yyvsp[-1].ExprType));
    }
#line 2175 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 56:
#line 456 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             { (yyval.ExprType) = nullptr; }
#line 2181 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 57:
#line 457 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                         {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2189 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 58:
#line 463 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                              {
        (yyval.StmtType) = new IfStmt(dynamic_cast<CondClause*>((yyvsp[-4].StmtType)), dynamic_cast<Stmt*>((yyvsp[-3].StmtType)));
    }
#line 2197 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 59:
#line 469 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2205 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 60:
#line 472 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                       {
        (yyval.StmtType) = (yyvsp[-2].StmtType);
        (yyvsp[-2].StmtType)->setNext((yyvsp[0].StmtType));
    }
#line 2214 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 61:
#line 479 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                          {
        (yyval.StmtType) = new CondClause((yyvsp[-1].ExprType), dynamic_cast<Stmt*>((yyvsp[0].StmtType)));
    }
#line 2222 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 62:
#line 485 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.ExprType) = (yyvsp[-1].ExprType);
    }
#line 2230 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 63:
#line 491 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.ExprType) = (yyvsp[0].ExprType); 
    }
#line 2238 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 64:
#line 496 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 { (yyval.StmtType) = nullptr; }
#line 2244 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 65:
#line 497 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                          {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2252 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 66:
#line 503 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                                         {
        (yyval.StmtType) = new CaseStmt((yyvsp[-5].ExprType), dynamic_cast<Alternative*>((yyvsp[-3].StmtType)));
    }
#line 2260 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 67:
#line 509 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             { (yyval.StmtType) = nullptr; }
#line 2266 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 68:
#line 510 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                   {
        if((yyvsp[-1].StmtType)) {
            (yyval.StmtType) = (yyvsp[-1].StmtType);
            (yyvsp[-1].StmtType)->setNext((yyvsp[0].StmtType));
        } else {
            (yyval.StmtType) = (yyvsp[0].StmtType);
        }
    }
#line 2279 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 69:
#line 521 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                         {
        (yyval.StmtType) = new Alternative(dynamic_cast<Choice*>((yyvsp[-2].StmtType)), dynamic_cast<Stmt*>((yyvsp[0].StmtType)));
    }
#line 2287 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 70:
#line 527 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2295 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 71:
#line 530 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                  {
        (yyval.StmtType) = (yyvsp[-2].StmtType);
        (yyvsp[-2].StmtType)->setNext((yyvsp[0].StmtType));
    }
#line 2304 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 72:
#line 537 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.StmtType) = new Choice((yyvsp[0].ExprType));
    }
#line 2312 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 73:
#line 540 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                            {
        (yyval.StmtType) = new Choice(dynamic_cast<DiscreteRange*>((yyvsp[0].StmtType)));
    }
#line 2320 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 74:
#line 543 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.StmtType) = new Choice(true);
    }
#line 2328 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 75:
#line 549 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                             {
        Type* type = dynamic_cast<Range*>((yyvsp[0].StmtType))->getType();
        SymbolEntry* se = new IdentifierSymbolEntry(type, (yyvsp[-2].StrType), identifiers->getLevel());
        (yyval.StmtType) = new DiscreteRange(se, dynamic_cast<Range*>((yyvsp[0].StmtType)));
    }
#line 2338 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 76:
#line 554 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                {
        (yyval.StmtType) = new DiscreteRange(dynamic_cast<Range*>((yyvsp[0].StmtType)));
    }
#line 2346 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 77:
#line 560 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                                   {
        (yyval.StmtType) = new LoopStmt(dynamic_cast<LabelOpt*>((yyvsp[-4].StmtType)), dynamic_cast<Iteration*>((yyvsp[-3].StmtType)), dynamic_cast<BasicLoopStmt*>((yyvsp[-2].StmtType)));
        if(!whileIters.empty() && whileIters.back()) {
            SymbolTable* ScopeTable = identifiers;
            identifiers = identifiers->getPrev();
            delete ScopeTable;
        }
        whileIters.pop_back();
    }
#line 2360 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 78:
#line 571 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  { (yyval.StmtType) = nullptr; }
#line 2366 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 79:
#line 572 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                           {
        SymbolEntry *se = new IdentifierSymbolEntry(TypeSystem::integerType, (yyvsp[-1].StrType), identifiers->getLevel());
        identifiers->install((yyvsp[-1].StrType), se);
        (yyval.StmtType) = new LabelOpt(se);
    }
#line 2376 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 80:
#line 579 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                   {
        whileIters.push_back(false);
        (yyval.StmtType) = nullptr; 
    }
#line 2385 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 81:
#line 583 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                          {
        (yyval.StmtType) = new Iteration((yyvsp[0].ExprType));
        whileIters.push_back(false);
    }
#line 2394 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 82:
#line 587 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                            {
        (yyval.StmtType) = new Iteration(dynamic_cast<IterPart*>((yyvsp[-2].StmtType)), (yyvsp[-1].SignType), dynamic_cast<DiscreteRange*>((yyvsp[0].StmtType)));
        whileIters.push_back(true);
    }
#line 2403 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 83:
#line 594 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                        {
        identifiers = new SymbolTable(identifiers);
        SymbolEntry *se = new IdentifierSymbolEntry(TypeSystem::integerType, (yyvsp[-1].StrType), identifiers->getLevel());
        identifiers->install((yyvsp[-1].StrType), se);
        (yyval.StmtType) = new IterPart(se);
    }
#line 2414 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 84:
#line 602 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                    { (yyval.SignType) = nullptr; }
#line 2420 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 85:
#line 603 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  {
        (yyval.SignType) = new OpSignNode(OpSignNode::REVERSE);
    }
#line 2428 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 86:
#line 609 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                               {
        (yyval.StmtType) = new BasicLoopStmt(dynamic_cast<Stmt*>((yyvsp[-2].StmtType)));
    }
#line 2436 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 87:
#line 615 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 { (yyval.ExprType) = nullptr; }
#line 2442 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 88:
#line 616 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        SymbolEntry* se = identifiers->lookup((yyvsp[0].StrType));
        (yyval.ExprType) = new Id(se);
    }
#line 2451 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 89:
#line 623 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                {
        SymbolEntry *se = new IdentifierSymbolEntry(TypeSystem::integerType, (yyvsp[-1].StrType), identifiers->getLevel());
        identifiers->install((yyvsp[-1].StrType), se);
        (yyval.StmtType) = new DiscreteRange(se, dynamic_cast<Range*>((yyvsp[0].StmtType)));
    }
#line 2461 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 90:
#line 628 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                {
        (yyval.StmtType) = new DiscreteRange(dynamic_cast<Range*>((yyvsp[0].StmtType)));
    }
#line 2469 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 91:
#line 633 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                        { (yyval.StmtType) = nullptr; }
#line 2475 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 92:
#line 634 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                      {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2483 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 93:
#line 640 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                               {
        (yyval.StmtType) = new Range((yyvsp[-2].ExprType), (yyvsp[0].ExprType));
    }
#line 2491 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 94:
#line 646 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                                       {
        (yyval.StmtType) = new Block(dynamic_cast<LabelOpt*>((yyvsp[-5].StmtType)), dynamic_cast<DeclItemOrBodyStmt*>((yyvsp[-4].StmtType)), dynamic_cast<Stmt*>((yyvsp[-3].StmtType)));
    }
#line 2499 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 95:
#line 651 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                   { (yyval.StmtType) = nullptr; }
#line 2505 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 96:
#line 652 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                           {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2513 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 97:
#line 658 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                       {
        DEBUG_YACC("================Enter BlockBody=================");
        (yyval.StmtType) = (yyvsp[0].StmtType);
        DEBUG_YACC("================Enter BlockBody=================");

    }
#line 2524 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 98:
#line 667 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2532 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 99:
#line 670 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                      {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2540 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 100:
#line 673 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                           {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2548 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 101:
#line 679 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
          {
        (yyval.SignType) = new OpSignNode(OpSignNode::AND);
    }
#line 2556 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 102:
#line 682 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.SignType) = new OpSignNode(OpSignNode::OR);
    }
#line 2564 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 103:
#line 685 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::XOR);
    }
#line 2572 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 104:
#line 691 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.SignType) = new OpSignNode(OpSignNode::ANDTHEN);
    }
#line 2580 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 105:
#line 694 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  {
        (yyval.SignType) = new OpSignNode(OpSignNode::ORELSE);
    }
#line 2588 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 106:
#line 700 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                       {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2596 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 107:
#line 703 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                                       {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2604 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 108:
#line 706 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                            {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), dynamic_cast<Range*>((yyvsp[0].StmtType)), (yyvsp[-1].SignType));
    }
#line 2612 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 109:
#line 709 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                                 {
        SymbolEntry* se = new IdentifierSymbolEntry(TypeSystem::integerType, (yyvsp[0].StrType), identifiers->getLevel());
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), se, (yyvsp[-1].SignType));
    }
#line 2621 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 110:
#line 716 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
         {
        (yyval.SignType) = new OpSignNode(OpSignNode::EQ);
    }
#line 2629 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 111:
#line 719 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.SignType) = new OpSignNode(OpSignNode::NE);
    }
#line 2637 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 112:
#line 722 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.SignType) = new OpSignNode(OpSignNode::LE);
    }
#line 2645 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 113:
#line 725 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.SignType) = new OpSignNode(OpSignNode::LTEQ);
    }
#line 2653 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 114:
#line 728 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.SignType) = new OpSignNode(OpSignNode::GE);
    }
#line 2661 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 115:
#line 731 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.SignType) = new OpSignNode(OpSignNode::GTEQ);
    }
#line 2669 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 116:
#line 737 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
         {
        (yyval.SignType) = new OpSignNode(OpSignNode::IN);
    }
#line 2677 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 117:
#line 740 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.SignType) = new OpSignNode(OpSignNode::NOTIN);
    }
#line 2685 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 118:
#line 746 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.ExprType) = new BinaryExpr((yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2693 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 119:
#line 749 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2701 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 120:
#line 752 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                       {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2709 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 121:
#line 758 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
          {
        (yyval.SignType) = new OpSignNode(OpSignNode::ADD);
    }
#line 2717 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 122:
#line 761 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::SUB);
    }
#line 2725 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 123:
#line 767 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
          {
        (yyval.SignType) = new OpSignNode(OpSignNode::ADD);
    }
#line 2733 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 124:
#line 770 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::SUB);
    }
#line 2741 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 125:
#line 773 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                    {
        (yyval.SignType) = new OpSignNode(OpSignNode::SINGLEAND);
    }
#line 2749 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 126:
#line 779 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2757 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 127:
#line 782 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                  {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2765 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 128:
#line 788 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
          {
        (yyval.SignType) = new OpSignNode(OpSignNode::MUL);
    }
#line 2773 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 129:
#line 791 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::DIV);
    }
#line 2781 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 130:
#line 794 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::MOD);
    }
#line 2789 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 131:
#line 797 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::REM);
    }
#line 2797 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 132:
#line 803 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2805 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 133:
#line 806 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                      {
        (yyval.ExprType) = new FactorExpr((yyvsp[0].ExprType), FactorExpr::NOT);
    }
#line 2813 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 134:
#line 809 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                      {
        (yyval.ExprType) = new FactorExpr((yyvsp[0].ExprType), FactorExpr::ABS);
    }
#line 2821 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 135:
#line 812 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), new OpSignNode(OpSignNode::EXPON));
    }
#line 2829 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 136:
#line 818 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2837 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 137:
#line 821 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2845 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 138:
#line 824 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                               {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2853 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 139:
#line 830 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        SymbolEntry* se = identifiers->lookup((yyvsp[0].StrType));
        if(!se) {
            std::cerr << "[YACC ERROR]: Can't not get SymbolEntry "<< (yyvsp[0].StrType) << " !\n";
        }
        (yyval.ExprType) = new Id(se);
    }
#line 2865 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 140:
#line 837 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2873 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 141:
#line 840 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2881 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 142:
#line 843 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        SymbolEntry *se = new IdentifierSymbolEntry(TypeSystem::integerType, "Integer", 0);
        globals->install("Integer", se);
        (yyval.ExprType) = new Id(se);
    }
#line 2891 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 143:
#line 851 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                {
        (yyval.ExprType) = new Id(dynamic_cast<Id*>((yyvsp[-3].ExprType)), (yyvsp[-1].ExprType));
    }
#line 2899 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 144:
#line 857 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
            {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2907 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 145:
#line 860 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                             {
        (yyval.ExprType) = (yyvsp[-2].ExprType);
        (yyvsp[-2].ExprType)->setNext((yyvsp[0].ExprType));
    }
#line 2916 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 146:
#line 867 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2924 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 147:
#line 873 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                           {
        (yyval.ExprType) = new Id(dynamic_cast<Id*>((yyvsp[-2].ExprType)), (yyvsp[0].StrType));
    }
#line 2932 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 148:
#line 879 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.StrType) = (yyvsp[0].StrType);
    }
#line 2940 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 149:
#line 885 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                               {
        (yyval.ExprType) = (yyvsp[-1].ExprType);
    }
#line 2948 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 150:
#line 891 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        SymbolEntry* se = new ConstantSymbolEntry(TypeSystem::integerType, (yyvsp[0].IntType));
        (yyval.ExprType) = new Constant(se);
    }
#line 2957 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 151:
#line 895 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                        {
        SymbolEntry* se = new ConstantSymbolEntry(TypeSystem::stringType, (yyvsp[0].StrType));
        (yyval.ExprType) = new Constant(se);
    }
#line 2966 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 152:
#line 899 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.ExprType) = nullptr;
    }
#line 2974 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 153:
#line 902 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
           {
        SymbolEntry* se = new ConstantSymbolEntry(TypeSystem::boolType, true);
        (yyval.ExprType) = new Constant(se);
    }
#line 2983 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 154:
#line 906 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
            {
        SymbolEntry* se = new ConstantSymbolEntry(TypeSystem::boolType, false);
        (yyval.ExprType) = new Constant(se);
    }
#line 2992 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;


#line 2996 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"

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
#line 911 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"


int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}
