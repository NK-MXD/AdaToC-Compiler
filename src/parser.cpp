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
    DECIMIAL = 345,
    Identifier = 346,
    STRINGLITERAL = 347,
    INTEGER = 348,
    STRING = 349,
    NATURAL = 350,
    COLON = 351,
    SEMICOLON = 352,
    LPAREN = 353,
    RPAREN = 354,
    COMMA = 355,
    SINGLEAND = 356,
    SINGLEOR = 357
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

#line 264 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"

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
#define YYLAST   302

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  103
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  137
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  216

#define YYUNDEFTOK  2
#define YYMAXUTOK   357


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
      95,    96,    97,    98,    99,   100,   101,   102
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   140,   140,   146,   149,   155,   158,   164,   170,   198,
     199,   205,   211,   214,   220,   227,   230,   233,   238,   239,
     245,   245,   257,   258,   265,   268,   274,   279,   287,   290,
     297,   300,   306,   309,   316,   319,   325,   328,   331,   334,
     337,   343,   346,   349,   352,   358,   364,   371,   374,   380,
     390,   396,   397,   403,   409,   412,   419,   425,   431,   436,
     437,   443,   449,   450,   461,   467,   470,   477,   480,   483,
     489,   494,   500,   505,   506,   513,   514,   517,   523,   530,
     531,   537,   543,   544,   551,   556,   561,   562,   568,   574,
     579,   580,   586,   592,   595,   598,   604,   607,   610,   616,
     619,   625,   628,   631,   634,   640,   643,   646,   649,   652,
     655,   661,   664,   670,   673,   676,   682,   685,   691,   694,
     697,   703,   706,   712,   715,   718,   721,   727,   730,   733,
     736,   742,   745,   749,   755,   761,   765,   769
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
  "WHILE", "WITH", "XOR", "DECIMIAL", "Identifier", "STRINGLITERAL",
  "INTEGER", "STRING", "NATURAL", "COLON", "SEMICOLON", "LPAREN", "RPAREN",
  "COMMA", "SINGLEAND", "SINGLEOR", "$accept", "Program", "CompUnit",
  "Unit", "SubprogDecl", "SubprogSpec", "FormalPartOpt", "FormalPart",
  "Params", "Param", "Type", "InitOpt", "SubprogBody", "$@1", "DeclPart",
  "Decl", "ObjectDecl", "DeclItemOrBodys", "DeclItemOrBody", "Statements",
  "Statement", "SimpleStmt", "CompoundStmt", "NullStmt", "AssignStmt",
  "ReturnStmt", "ProcedureCall", "ExitStmt", "WhenOpt", "IfStmt",
  "CondClauses", "CondClause", "CondPart", "Condition", "ElseOpt",
  "CaseStmt", "Alternatives", "Alternative", "Choices", "Choice",
  "DiscreteWithRange", "LoopStmt", "LabelOpt", "Iteration", "IterPart",
  "ReverseOpt", "BasicLoop", "IdOpt", "DiscreteRange", "RangeConstrOpt",
  "Range", "Block", "BlockDecl", "BlockBody", "Expression", "Logical",
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
     355,   356,   357
};
# endif

#define YYPACT_NINF (-106)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-133)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -35,   -46,   103,   -35,  -106,  -106,    -8,  -106,    16,  -106,
    -106,  -106,  -106,    27,  -106,  -106,    10,    30,   -56,  -106,
      39,  -106,  -106,    89,  -106,  -106,    10,  -106,   106,    27,
    -106,    56,   211,    98,  -106,  -106,  -106,  -106,   126,  -106,
     106,   126,    64,    67,    64,    71,    55,     2,   197,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
     -15,  -106,    67,    64,  -106,   126,    94,    85,    85,  -106,
    -106,  -106,  -106,  -106,  -106,    64,   118,  -106,    22,   139,
     108,  -106,   173,  -106,  -106,  -106,   107,    25,  -106,   211,
     120,   -14,  -106,  -106,    20,    64,  -106,  -106,  -106,    10,
     119,    64,   159,   136,    89,   115,   -14,   117,  -106,  -106,
    -106,    -5,   134,  -106,   182,  -106,    64,    64,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,   170,  -106,  -106,  -106,    64,
      82,   139,   108,  -106,  -106,  -106,  -106,   139,    85,    64,
     122,   211,    64,   185,   167,  -106,  -106,   109,  -106,   189,
    -106,   211,    67,  -106,   130,   208,  -106,  -106,  -106,  -106,
     -18,  -106,  -106,  -106,  -106,   133,    14,  -106,     3,   108,
    -106,  -106,  -106,  -106,   204,  -106,   201,  -106,  -106,   210,
     152,   -22,  -106,  -106,    67,   224,    73,  -106,    64,   157,
     209,  -106,    64,  -106,   164,   166,  -106,   195,   -10,  -106,
    -106,  -106,   -14,     1,   133,  -106,  -106,  -106,  -106,  -106,
      64,   211,    73,  -106,   186,  -106
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     3,     5,     0,     6,     9,     1,
       4,    20,     7,     0,     8,    10,    22,     0,     0,    12,
       0,    25,    30,     0,    31,    24,    23,    28,     0,     0,
      11,     0,    73,     0,    29,    15,    16,    17,    18,    13,
       0,    18,     0,    82,     0,     0,     0,     0,    73,    32,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      75,    44,    82,     0,    14,    18,     0,     0,     0,   117,
     116,   137,   135,   132,   136,     0,     0,    93,   101,     0,
     114,   121,   127,   133,   131,    83,    51,    59,    54,    73,
       0,    58,    45,    47,     0,     0,    74,    49,    33,    22,
       0,     0,     0,    79,     0,     0,    19,     0,    26,   129,
     128,     0,    96,    62,    97,    98,     0,     0,   108,   110,
     106,   109,   107,   105,   111,     0,   119,   118,   120,     0,
       0,     0,   113,   123,   124,   125,   126,     0,     0,     0,
       0,    73,     0,     0,    73,    57,    48,     0,    91,     0,
      76,    73,    82,    80,     0,     0,    21,    27,   134,    99,
       0,   100,    94,    95,   112,   102,   104,   103,     0,   115,
     122,   130,    52,    50,    73,    55,     0,    46,    78,    73,
       0,   132,    77,    85,    82,     0,     0,    63,     0,     0,
       0,    72,     0,    84,     0,     0,    69,   132,     0,    65,
      68,    71,    67,   101,    88,    53,    81,    87,    89,    61,
       0,    73,     0,    70,    73,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -106,  -106,  -106,   262,   181,  -106,  -106,  -106,  -106,   237,
      11,    -2,   192,  -106,   168,  -106,  -106,  -106,   244,   -87,
     -47,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,   131,  -106,   -49,  -106,  -106,  -106,  -106,  -106,    62,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,   -59,  -106,  -106,
    -104,  -106,  -106,   171,   -42,  -106,  -106,   -21,  -106,  -106,
    -105,  -106,  -106,   -57,  -106,   142,   -30,  -106,  -106
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    21,     6,    14,    15,    18,    19,
      38,    64,    22,    16,    23,    24,    25,    26,    27,    48,
      49,    50,    51,    52,    53,    54,    55,    56,   140,    57,
      87,    88,    89,    90,   143,    58,   160,   187,   198,   199,
     200,    59,    60,   102,   103,   154,   152,    86,   182,   193,
     201,    61,   104,    33,    91,   116,   117,    77,   129,   130,
      78,    79,   131,    80,   137,    81,    82,    83,    84
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      76,    98,   144,   105,    94,   188,   211,   188,   118,   119,
     112,   120,   -90,   121,   122,   123,    99,    95,  -132,   112,
     185,   106,   132,  -132,   165,   168,   167,   100,   -86,   118,
     119,     1,   120,   111,   121,   122,   123,   109,   110,    66,
      11,    29,    41,    30,   112,     8,   114,   192,   124,   168,
     183,    65,   150,   147,   174,   114,   125,   126,   127,   126,
     127,   141,   142,   107,   179,  -132,  -132,  -132,   186,   124,
    -132,  -132,   101,    67,   169,   115,     1,   125,   126,   127,
     114,   203,    67,   204,   115,  -132,    40,   168,   207,    12,
     172,    67,   212,   180,   158,   162,   163,    98,    96,    97,
      67,    20,   128,     9,   128,   168,   213,   203,   171,   115,
      68,    69,    70,    71,    13,  -132,    32,   146,    17,    68,
      69,    70,    71,   128,   214,   194,    28,    98,    68,    69,
      70,    71,    98,   112,   196,    31,    62,    68,    69,    70,
      71,    63,   112,    71,   202,    72,    73,    74,    67,    35,
      36,    37,    93,    75,    72,    73,    74,    67,    85,   133,
     134,   135,    75,    72,   197,    74,   113,    98,    92,   114,
     202,    75,    72,   166,    74,    72,    73,    74,   114,   136,
      75,     5,   138,    75,     5,    68,    69,    70,    71,   126,
     127,   108,     7,   139,    68,     7,    42,    71,   115,    35,
      36,    37,   145,   -56,   -56,   -56,   177,   115,    43,   151,
     149,   153,   156,    44,   157,    42,   159,   164,   161,   173,
      72,   181,    74,   176,   -64,    45,    42,    43,    75,    72,
      73,    74,    44,    42,   128,   -92,   178,    75,    43,    42,
      42,    46,   -60,    44,    45,    43,   184,   189,   190,   191,
      44,    43,    43,   195,   205,    45,    44,    44,    47,   206,
      46,   208,    45,   209,   210,    10,    39,   148,    45,    45,
      34,    46,   -64,   175,   215,   155,     0,    47,    46,   170,
       0,     0,     0,     0,    46,    46,     0,     0,    47,     0,
       0,     0,     0,     0,     0,    47,     0,     0,     0,     0,
       0,    47,    47
};

static const yytype_int16 yycheck[] =
{
      42,    48,    89,    62,    46,     4,    16,     4,     7,     8,
      24,    10,    27,    12,    13,    14,    31,    15,     4,    24,
      38,    63,    79,     9,   129,   130,   130,    42,    50,     7,
       8,    66,    10,    75,    12,    13,    14,    67,    68,    41,
      48,    97,    31,    99,    24,    91,    60,    69,    47,   154,
     154,    40,   101,    95,   141,    60,    55,    56,    57,    56,
      57,    36,    37,    65,   151,    51,    52,    53,    86,    47,
      56,    57,    87,    18,   131,    89,    66,    55,    56,    57,
      60,   186,    18,   188,    89,    71,    30,   192,   192,    97,
     139,    18,   102,   152,    99,   116,   117,   144,    96,    97,
      18,    91,   101,     0,   101,   210,   210,   212,   138,    89,
      55,    56,    57,    58,    98,   101,    27,    97,    91,    55,
      56,    57,    58,   101,   211,   184,    96,   174,    55,    56,
      57,    58,   179,    24,    61,    96,    38,    55,    56,    57,
      58,    15,    24,    58,   186,    90,    91,    92,    18,    93,
      94,    95,    97,    98,    90,    91,    92,    18,    91,    51,
      52,    53,    98,    90,    91,    92,    48,   214,    97,    60,
     212,    98,    90,    91,    92,    90,    91,    92,    60,    71,
      98,     0,     9,    98,     3,    55,    56,    57,    58,    56,
      57,    97,     0,    86,    55,     3,    29,    58,    89,    93,
      94,    95,    82,    36,    37,    38,    97,    89,    41,    50,
      91,    75,    97,    46,    97,    29,    82,    47,    36,    97,
      90,    91,    92,    38,    38,    58,    29,    41,    98,    90,
      91,    92,    46,    29,   101,    38,    47,    98,    41,    29,
      29,    74,    38,    46,    58,    41,    38,    46,    38,    97,
      46,    41,    41,    29,    97,    58,    46,    46,    91,    50,
      74,    97,    58,    97,    69,     3,    29,    99,    58,    58,
      26,    74,    86,   142,   212,   104,    -1,    91,    74,   137,
      -1,    -1,    -1,    -1,    74,    74,    -1,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,
      -1,    91,    91
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    66,   104,   105,   106,   107,   108,   115,    91,     0,
     106,    48,    97,    98,   109,   110,   116,    91,   111,   112,
      91,   107,   115,   117,   118,   119,   120,   121,    96,    97,
      99,    96,    27,   156,   121,    93,    94,    95,   113,   112,
      30,   113,    29,    41,    46,    58,    74,    91,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   132,   138,   144,
     145,   154,    38,    15,   114,   113,   114,    18,    55,    56,
      57,    58,    90,    91,    92,    98,   157,   160,   163,   164,
     166,   168,   169,   170,   171,    91,   150,   133,   134,   135,
     136,   157,    97,    97,   157,    15,    96,    97,   123,    31,
      42,    87,   146,   147,   155,   150,   157,   114,    97,   169,
     169,   157,    24,    48,    60,    89,   158,   159,     7,     8,
      10,    12,    13,    14,    47,    55,    56,    57,   101,   161,
     162,   165,   166,    51,    52,    53,    71,   167,     9,    86,
     131,    36,    37,   137,   122,    82,    97,   157,   117,    91,
     136,    50,   149,    75,   148,   156,    97,    97,    99,    82,
     139,    36,   160,   160,    47,   163,    91,   153,   163,   166,
     168,   169,   136,    97,   122,   134,    38,    97,    47,   122,
     150,    91,   151,   153,    38,    38,    86,   140,     4,    46,
      38,    97,    69,   152,   150,    29,    61,    91,   141,   142,
     143,   153,   157,   163,   163,    97,    50,   153,    97,    97,
      69,    16,   102,   153,   122,   142
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   103,   104,   105,   105,   106,   106,   107,   108,   109,
     109,   110,   111,   111,   112,   113,   113,   113,   114,   114,
     116,   115,   117,   117,   118,   118,   119,   119,   120,   120,
     121,   121,   122,   122,   123,   123,   124,   124,   124,   124,
     124,   125,   125,   125,   125,   126,   127,   128,   128,   129,
     130,   131,   131,   132,   133,   133,   134,   135,   136,   137,
     137,   138,   139,   139,   140,   141,   141,   142,   142,   142,
     143,   143,   144,   145,   145,   146,   146,   146,   147,   148,
     148,   149,   150,   150,   151,   151,   152,   152,   153,   154,
     155,   155,   156,   157,   157,   157,   158,   158,   158,   159,
     159,   160,   160,   160,   160,   161,   161,   161,   161,   161,
     161,   162,   162,   163,   163,   163,   164,   164,   165,   165,
     165,   166,   166,   167,   167,   167,   167,   168,   168,   168,
     168,   169,   169,   169,   170,   171,   171,   171
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     2,     3,     0,
       1,     3,     1,     3,     4,     1,     1,     1,     0,     2,
       0,     8,     0,     1,     1,     1,     5,     6,     1,     2,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     2,     3,     2,
       4,     0,     2,     6,     1,     3,     2,     2,     1,     0,
       2,     7,     0,     2,     4,     1,     3,     1,     1,     1,
       3,     1,     5,     0,     2,     0,     2,     3,     3,     0,
       1,     4,     0,     1,     2,     1,     0,     2,     3,     6,
       0,     2,     2,     1,     3,     3,     1,     1,     1,     2,
       2,     1,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     2,     2,
       3,     1,     1,     1,     3,     1,     1,     1
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
#line 140 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        ast.setRoot((yyvsp[0].StmtType));
    }
#line 1647 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 3:
#line 146 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
           {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1655 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 4:
#line 149 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                    {
        (yyval.StmtType) = new SeqNode((yyvsp[-1].StmtType), (yyvsp[0].StmtType));
    }
#line 1663 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 5:
#line 155 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1671 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 6:
#line 158 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                      {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1679 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 7:
#line 164 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                            {
        (yyval.StmtType) = new ProcedureDecl(dynamic_cast<ProcedureSpec*>((yyvsp[-1].StmtType)));
    }
#line 1687 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 8:
#line 170 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                         {
        DEBUG_YACC("Enter SubprogSpec");
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
        DEBUG_YACC("Leave SubprogSpec");
    }
#line 1717 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 9:
#line 198 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             { (yyval.StmtType) = nullptr; }
#line 1723 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 10:
#line 199 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1731 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 11:
#line 205 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                           {
        (yyval.StmtType) = (yyvsp[-1].StmtType);
    }
#line 1739 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 12:
#line 211 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
            {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1747 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 13:
#line 214 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                 {
        (yyval.StmtType) = (yyvsp[-2].StmtType);
        (yyvsp[-2].StmtType)->setNext((yyvsp[0].StmtType));
    }
#line 1756 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 14:
#line 220 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                      {
        SymbolEntry *se = new IdentifierSymbolEntry((yyvsp[-1].type), (yyvsp[-3].StrType), IdentifierSymbolEntry::PARAM);
        (yyval.StmtType) = new ParamNode(se, dynamic_cast<InitOptStmt*>((yyvsp[0].StmtType)));
    }
#line 1765 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 15:
#line 227 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.type) = TypeSystem::integerType;
    }
#line 1773 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 16:
#line 230 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.type) = TypeSystem::stringType;
    }
#line 1781 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 17:
#line 233 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.type) = TypeSystem::naturalType;
    }
#line 1789 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 18:
#line 238 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 { (yyval.StmtType) = nullptr; }
#line 1795 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 19:
#line 239 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                            {
        (yyval.StmtType) = new InitOptStmt((yyvsp[0].ExprType));
    }
#line 1803 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 20:
#line 245 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        // Enter into new scope.
        identifiers = new SymbolTable(identifiers);
    }
#line 1812 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 21:
#line 248 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                             {
        (yyval.StmtType) = new ProcedureDef(dynamic_cast<ProcedureSpec*>((yyvsp[-7].StmtType)), dynamic_cast<DeclItemOrBodyStmt*>((yyvsp[-4].StmtType)), (yyvsp[-3].StmtType));
        // Leave the scope.
        SymbolTable* ScopeTable = identifiers;
        identifiers = identifiers->getPrev();
        delete ScopeTable;
    }
#line 1824 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 22:
#line 257 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 { (yyval.StmtType) = nullptr; }
#line 1830 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 23:
#line 258 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                          {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1838 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 24:
#line 265 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.StmtType) = new DeclStmt(dynamic_cast<ObjectDeclStmt*>((yyvsp[0].StmtType)));
    }
#line 1846 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 25:
#line 268 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  {
        (yyval.StmtType) = new DeclStmt(dynamic_cast<SubprogDecl*>((yyvsp[0].StmtType)));
    }
#line 1854 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 26:
#line 274 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                              {
        SymbolEntry *se = new IdentifierSymbolEntry((yyvsp[-2].type), (yyvsp[-4].StrType), identifiers->getLevel());
        identifiers->install((yyvsp[-4].StrType), se);
        (yyval.StmtType) = new ObjectDeclStmt(se, dynamic_cast<InitOptStmt*>((yyvsp[-1].StmtType)));
    }
#line 1864 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 27:
#line 279 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                                       {
        SymbolEntry *se = new IdentifierSymbolEntry((yyvsp[-2].type), (yyvsp[-5].StrType), identifiers->getLevel(), true);
        identifiers->install((yyvsp[-5].StrType), se);
        (yyval.StmtType) = new ObjectDeclStmt(se, dynamic_cast<InitOptStmt*>((yyvsp[-1].StmtType)));
    }
#line 1874 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 28:
#line 287 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1882 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 29:
#line 290 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                         {
        (yyval.StmtType) = (yyvsp[-1].StmtType);
        (yyvsp[-1].StmtType)->setNext((yyvsp[0].StmtType));
    }
#line 1891 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 30:
#line 297 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  {
        (yyval.StmtType) = new DeclItemOrBodyStmt(dynamic_cast<ProcedureDef*>((yyvsp[0].StmtType)));
    }
#line 1899 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 31:
#line 300 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.StmtType) = new DeclItemOrBodyStmt(dynamic_cast<DeclStmt*>((yyvsp[0].StmtType)));
    }
#line 1907 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 32:
#line 306 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1915 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 33:
#line 309 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                               {
        (yyval.StmtType) = (yyvsp[-1].StmtType);
        (yyvsp[-1].StmtType)->setNext((yyvsp[0].StmtType));
    }
#line 1924 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 34:
#line 316 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.StmtType) = new Stmt((yyvsp[0].StmtType));
    }
#line 1932 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 35:
#line 319 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                       {
        (yyval.StmtType) = new Stmt((yyvsp[0].StmtType));
    }
#line 1940 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 36:
#line 325 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1948 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 37:
#line 328 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1956 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 38:
#line 331 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1964 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 39:
#line 334 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                        {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1972 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 40:
#line 337 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1980 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 41:
#line 343 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1988 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 42:
#line 346 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                   {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 1996 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 43:
#line 349 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                   {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2004 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 44:
#line 352 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2012 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 45:
#line 358 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.StmtType) = nullptr;
    }
#line 2020 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 46:
#line 364 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                             {
        SymbolEntry *se = identifiers->lookup((yyvsp[-3].StrType));
        (yyval.StmtType) = new AssignStmt(se, (yyvsp[-1].ExprType));
    }
#line 2029 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 47:
#line 371 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                       {
        (yyval.StmtType) = new ReturnStmt(nullptr);
    }
#line 2037 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 48:
#line 374 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                      {
        (yyval.StmtType) = new ReturnStmt((yyvsp[-1].ExprType));
    }
#line 2045 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 49:
#line 380 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                           {
        SymbolEntry* se = identifiers->lookup((yyvsp[-1].StrType));
        if(!se || !se->getType()->isProcedure()) {
            std::cerr << "Can't not get Procedure type SymbolEntry!\n";
        }
        (yyval.StmtType) = new CallStmt(se);
    }
#line 2057 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 50:
#line 390 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                   {
        (yyval.StmtType) = new ExitStmt((yyvsp[-1].ExprType));
    }
#line 2065 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 51:
#line 396 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             { (yyval.ExprType) = nullptr; }
#line 2071 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 52:
#line 397 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                         {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2079 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 53:
#line 403 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                              {
        (yyval.StmtType) = new IfStmt(dynamic_cast<CondClause*>((yyvsp[-4].StmtType)), dynamic_cast<Stmt*>((yyvsp[-3].StmtType)));
    }
#line 2087 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 54:
#line 409 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2095 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 55:
#line 412 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                       {
        (yyval.StmtType) = (yyvsp[-2].StmtType);
        (yyvsp[-2].StmtType)->setNext((yyvsp[0].StmtType));
    }
#line 2104 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 56:
#line 419 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                          {
        (yyval.StmtType) = new CondClause((yyvsp[-1].ExprType), dynamic_cast<Stmt*>((yyvsp[0].StmtType)));
    }
#line 2112 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 57:
#line 425 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        (yyval.ExprType) = (yyvsp[-1].ExprType);
    }
#line 2120 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 58:
#line 431 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.ExprType) = (yyvsp[0].ExprType); 
    }
#line 2128 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 59:
#line 436 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 { (yyval.StmtType) = nullptr; }
#line 2134 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 60:
#line 437 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                          {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2142 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 61:
#line 443 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                                         {
        (yyval.StmtType) = new CaseStmt((yyvsp[-5].ExprType), dynamic_cast<Alternative*>((yyvsp[-3].StmtType)));
    }
#line 2150 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 62:
#line 449 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             { (yyval.StmtType) = nullptr; }
#line 2156 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 63:
#line 450 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                   {
        if((yyvsp[-1].StmtType)) {
            (yyval.StmtType) = (yyvsp[-1].StmtType);
            (yyvsp[-1].StmtType)->setNext((yyvsp[0].StmtType));
        } else {
            (yyval.StmtType) = (yyvsp[0].StmtType);
        }
    }
#line 2169 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 64:
#line 461 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                         {
        (yyval.StmtType) = new Alternative(dynamic_cast<Choice*>((yyvsp[-2].StmtType)), dynamic_cast<Stmt*>((yyvsp[0].StmtType)));
    }
#line 2177 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 65:
#line 467 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2185 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 66:
#line 470 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                  {
        (yyval.StmtType) = (yyvsp[-2].StmtType);
        (yyvsp[-2].StmtType)->setNext((yyvsp[0].StmtType));
    }
#line 2194 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 67:
#line 477 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.StmtType) = new Choice((yyvsp[0].ExprType));
    }
#line 2202 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 68:
#line 480 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                            {
        (yyval.StmtType) = new Choice(dynamic_cast<DiscreteRange*>((yyvsp[0].StmtType)));
    }
#line 2210 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 69:
#line 483 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.StmtType) = new Choice(true);
    }
#line 2218 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 70:
#line 489 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                             {
        Type* type = dynamic_cast<Range*>((yyvsp[0].StmtType))->getType();
        SymbolEntry* se = new IdentifierSymbolEntry(type, (yyvsp[-2].StrType));
        (yyval.StmtType) = new DiscreteRange((yyvsp[-2].StrType), dynamic_cast<Range*>((yyvsp[0].StmtType)));
    }
#line 2228 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 71:
#line 494 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                {
        (yyval.StmtType) = new DiscreteRange(dynamic_cast<Range*>((yyvsp[0].StmtType)));
    }
#line 2236 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 72:
#line 500 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                                   {
        (yyval.StmtType) = new LoopStmt(dynamic_cast<LabelOpt*>((yyvsp[-4].StmtType)), dynamic_cast<Iteration*>((yyvsp[-3].StmtType)), dynamic_cast<BasicLoopStmt*>((yyvsp[-2].StmtType)));
    }
#line 2244 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 73:
#line 505 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  { (yyval.StmtType) = nullptr; }
#line 2250 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 74:
#line 506 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                           {
        SymbolEntry *se = new IdentifierSymbolEntry(IdentifierSymbolEntry::IntegerType, (yyvsp[-1].StrType), identifiers->getLevel());
        identifiers->install((yyvsp[-1].StrType), se);
        (yyval.StmtType) = new LabelOpt(se);
    }
#line 2260 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 75:
#line 513 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                   { (yyval.StmtType) = nullptr; }
#line 2266 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 76:
#line 514 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                          {
        (yyval.StmtType) = new Iteration((yyvsp[0].ExprType));
    }
#line 2274 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 77:
#line 517 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                            {
        (yyval.StmtType) = new Iteration(dynamic_cast<IterPart*>((yyvsp[-2].StmtType)), (yyvsp[-1].SignType), dynamic_cast<DiscreteRange*>((yyvsp[0].StmtType)));
    }
#line 2282 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 78:
#line 523 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                        {
        SymbolEntry *se = new IdentifierSymbolEntry(IdentifierSymbolEntry::IntegerType, (yyvsp[-1].StrType), identifiers->getLevel());
        identifiers->install((yyvsp[-1].StrType), se);
        (yyval.StmtType) = new IterPart(se);
    }
#line 2292 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 79:
#line 530 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                    { (yyval.SignType) = nullptr; }
#line 2298 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 80:
#line 531 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  {
        (yyval.SignType) = new OpSignNode(OpSignNode::REVERSE);
    }
#line 2306 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 81:
#line 537 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                               {
        (yyval.StmtType) = new BasicLoopStmt(dynamic_cast<Stmt*>((yyvsp[-2].StmtType)));
    }
#line 2314 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 82:
#line 543 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 { (yyval.ExprType) = nullptr; }
#line 2320 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 83:
#line 544 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        SymbolEntry* se = identifiers->lookup((yyvsp[0].StrType));
        (yyval.ExprType) = new Id(se);
    }
#line 2329 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 84:
#line 551 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                {
        SymbolEntry *se = new IdentifierSymbolEntry(IdentifierSymbolEntry::IntegerType, (yyvsp[0].StmtType), identifiers->getLevel());
        identifiers->install((yyvsp[0].StmtType), se);
        (yyval.StmtType) = new DiscreteRange((yyvsp[-1].StrType), dynamic_cast<Range*>((yyvsp[0].StmtType)));
    }
#line 2339 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 85:
#line 556 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                {
        (yyval.StmtType) = new DiscreteRange(dynamic_cast<Range*>((yyvsp[0].StmtType)));
    }
#line 2347 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 86:
#line 561 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                        { (yyval.StmtType) = nullptr; }
#line 2353 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 87:
#line 562 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                      {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2361 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 88:
#line 568 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                               {
        (yyval.StmtType) = new Range((yyvsp[-2].ExprType), (yyvsp[0].ExprType));
    }
#line 2369 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 89:
#line 574 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                                       {
        (yyval.StmtType) = new Block(dynamic_cast<LabelOpt*>((yyvsp[-5].StmtType)), dynamic_cast<DeclItemOrBody*>((yyvsp[-4].StmtType)), dynamic_cast<Stmt*>((yyvsp[-3].StmtType)));
    }
#line 2377 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 90:
#line 579 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                   { (yyval.StmtType) = nullptr; }
#line 2383 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 91:
#line 580 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                           {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2391 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 92:
#line 586 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                       {
        (yyval.StmtType) = (yyvsp[0].StmtType);
    }
#line 2399 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 93:
#line 592 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2407 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 94:
#line 595 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                      {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2415 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 95:
#line 598 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                           {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2423 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 96:
#line 604 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
          {
        (yyval.SignType) = new OpSignNode(OpSignNode::AND);
    }
#line 2431 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 97:
#line 607 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.SignType) = new OpSignNode(OpSignNode::OR);
    }
#line 2439 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 98:
#line 610 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::XOR);
    }
#line 2447 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 99:
#line 616 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.SignType) = new OpSignNode(OpSignNode::ANDTHEN);
    }
#line 2455 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 100:
#line 619 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                  {
        (yyval.SignType) = new OpSignNode(OpSignNode::ORELSE);
    }
#line 2463 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 101:
#line 625 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                       {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2471 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 102:
#line 628 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                                       {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2479 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 103:
#line 631 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                            {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), dynamic_cast<Range*>((yyvsp[0].StmtType)), (yyvsp[-1].SignType));
    }
#line 2487 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 104:
#line 634 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                                 {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].StrType), (yyvsp[-1].SignType));
    }
#line 2495 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 105:
#line 640 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
         {
        (yyval.SignType) = new OpSignNode(OpSignNode::EQ);
    }
#line 2503 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 106:
#line 643 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.SignType) = new OpSignNode(OpSignNode::NE);
    }
#line 2511 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 107:
#line 646 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.SignType) = new OpSignNode(OpSignNode::LE);
    }
#line 2519 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 108:
#line 649 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.SignType) = new OpSignNode(OpSignNode::LTEQ);
    }
#line 2527 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 109:
#line 652 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.SignType) = new OpSignNode(OpSignNode::GE);
    }
#line 2535 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 110:
#line 655 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.SignType) = new OpSignNode(OpSignNode::GTEQ);
    }
#line 2543 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 111:
#line 661 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
         {
        (yyval.SignType) = new OpSignNode(OpSignNode::IN);
    }
#line 2551 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 112:
#line 664 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.SignType) = new OpSignNode(OpSignNode::NOTIN);
    }
#line 2559 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 113:
#line 670 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                 {
        (yyval.ExprType) = new BinaryExpr((yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2567 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 114:
#line 673 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2575 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 115:
#line 676 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                       {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2583 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 116:
#line 682 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
          {
        (yyval.SignType) = new OpSignNode(OpSignNode::ADD);
    }
#line 2591 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 117:
#line 685 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::SUB);
    }
#line 2599 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 118:
#line 691 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
          {
        (yyval.SignType) = new OpSignNode(OpSignNode::ADD);
    }
#line 2607 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 119:
#line 694 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::SUB);
    }
#line 2615 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 120:
#line 697 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                    {
        (yyval.SignType) = new OpSignNode(OpSignNode::SINGLEAND);
    }
#line 2623 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 121:
#line 703 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
             {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2631 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 122:
#line 706 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                  {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), (yyvsp[-1].SignType));
    }
#line 2639 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 123:
#line 712 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
          {
        (yyval.SignType) = new OpSignNode(OpSignNode::MUL);
    }
#line 2647 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 124:
#line 715 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::DIV);
    }
#line 2655 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 125:
#line 718 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::MOD);
    }
#line 2663 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 126:
#line 721 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.SignType) = new OpSignNode(OpSignNode::REM);
    }
#line 2671 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 127:
#line 727 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2679 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 128:
#line 730 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                      {
        (yyval.ExprType) = new FactorExpr((yyvsp[0].ExprType), FactorExpr::NOT);
    }
#line 2687 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 129:
#line 733 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                      {
        (yyval.ExprType) = new FactorExpr((yyvsp[0].ExprType), FactorExpr::ABS);
    }
#line 2695 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 130:
#line 736 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                                {
        (yyval.ExprType) = new BinaryExpr((yyvsp[-2].ExprType), (yyvsp[0].ExprType), new OpSignNode(OpSignNode::EXPON));
    }
#line 2703 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 131:
#line 742 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
              {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2711 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 132:
#line 745 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                     {
        SymbolEntry* se = identifiers->lookup((yyvsp[0].StrType));
        (yyval.ExprType) = new Id(se);
    }
#line 2720 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 133:
#line 749 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                               {
        (yyval.ExprType) = (yyvsp[0].ExprType);
    }
#line 2728 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 134:
#line 755 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                               {
        (yyval.ExprType) = (yyvsp[-1].ExprType);
    }
#line 2736 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 135:
#line 761 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        SymbolEntry* se = new ConstantSymbolEntry(TypeSystem::IntegerType, (yyvsp[0].IntType));
        (yyval.ExprType) = new Constant(se);
    }
#line 2745 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 136:
#line 765 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
                        {
        SymbolEntry* se = new ConstantSymbolEntry(TypeSystem::StringType, (yyvsp[0].StrType));
        (yyval.ExprType) = new Constant(se);
    }
#line 2754 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;

  case 137:
#line 769 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"
               {
        (yyval.ExprType) = nullptr;
    }
#line 2762 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"
    break;


#line 2766 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.cpp"

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
#line 773 "/mnt/d/WorkSpace/Ada2C-Project/src/parser.y"


int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}
