/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "sa.y"

/*
	Used for the syntax analyzer
*/
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "struct.h"
#define YYDEBUG 1
#define CODE_LENGTH 250
#define TYPE_NUMBER 100
#define ID_NUMBER 100

typedef char* string;
typedef struct _TYPE {
	char* type;
	struct _TYPE* next;
} Type;
typedef struct _IDENTIFIER {
	char* id;
	char* type;
	int space;
	int isPara;
} Identifier;

Node *head;
Node* Record(char *, ...);
Type* types;
Identifier* ids;
int ptr_types = 0;
int ptr_ids = 0;
int counter = 0;

FILE *fout;

extern int yydebug; 

/* Line 268 of yacc.c  */
#line 110 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ASSIGNOP = 258,
     TYPE = 259,
     LC = 260,
     RC = 261,
     STRUCT = 262,
     RETURN = 263,
     IF = 264,
     ELSE = 265,
     BREAK = 266,
     CONT = 267,
     FOR = 268,
     INT = 269,
     ID = 270,
     SEMI = 271,
     COMMA = 272,
     LP = 273,
     RP = 274,
     LB = 275,
     RB = 276,
     DOT = 277,
     LOGNOT = 278,
     INCR = 279,
     DECR = 280,
     BNOT = 281,
     MOD = 282,
     PRODUCT = 283,
     DIVISION = 284,
     PLUS = 285,
     MINUS = 286,
     SHLEFT = 287,
     SHRIGHT = 288,
     GREATER = 289,
     GREATEREQU = 290,
     LESS = 291,
     LESSEQU = 292,
     EQU = 293,
     NOTEQU = 294,
     BAND = 295,
     BXOR = 296,
     BOR = 297,
     LOGAND = 298,
     LOGOR = 299,
     PLUSAN = 300,
     MINUSAN = 301,
     PRODUCTAN = 302,
     DIVISIONAN = 303,
     BANDAN = 304,
     BXORAN = 305,
     BORAN = 306,
     SHLEFTAN = 307,
     SHRIGHTAN = 308
   };
#endif
/* Tokens.  */
#define ASSIGNOP 258
#define TYPE 259
#define LC 260
#define RC 261
#define STRUCT 262
#define RETURN 263
#define IF 264
#define ELSE 265
#define BREAK 266
#define CONT 267
#define FOR 268
#define INT 269
#define ID 270
#define SEMI 271
#define COMMA 272
#define LP 273
#define RP 274
#define LB 275
#define RB 276
#define DOT 277
#define LOGNOT 278
#define INCR 279
#define DECR 280
#define BNOT 281
#define MOD 282
#define PRODUCT 283
#define DIVISION 284
#define PLUS 285
#define MINUS 286
#define SHLEFT 287
#define SHRIGHT 288
#define GREATER 289
#define GREATEREQU 290
#define LESS 291
#define LESSEQU 292
#define EQU 293
#define NOTEQU 294
#define BAND 295
#define BXOR 296
#define BOR 297
#define LOGAND 298
#define LOGOR 299
#define PLUSAN 300
#define MINUSAN 301
#define PRODUCTAN 302
#define DIVISIONAN 303
#define BANDAN 304
#define BXORAN 305
#define BORAN 306
#define SHLEFTAN 307
#define SHRIGHTAN 308




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 39 "sa.y"

	Node *node;



/* Line 293 of yacc.c  */
#line 258 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 270 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   732

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  167

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    13,    17,    19,    23,
      24,    26,    28,    34,    37,    39,    40,    42,    47,    52,
      56,    58,    59,    62,    67,    70,    71,    74,    76,    80,
      87,    97,   100,   103,   106,   107,   110,   111,   115,   119,
     121,   123,   127,   129,   133,   135,   139,   143,   147,   151,
     155,   159,   163,   167,   171,   175,   179,   183,   187,   191,
     195,   199,   203,   207,   211,   215,   219,   223,   227,   231,
     235,   239,   243,   247,   251,   254,   257,   260,   263,   266,
     270,   275,   278,   280,   281,   286,   287,   291
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    56,    -1,    57,    56,    -1,    -1,    59,
      58,    16,    -1,    59,    63,    66,    -1,    73,    -1,    73,
      17,    58,    -1,    -1,     4,    -1,    60,    -1,     7,    61,
       5,    70,     6,    -1,     7,    15,    -1,    15,    -1,    -1,
      15,    -1,    62,    20,    14,    21,    -1,    15,    18,    64,
      19,    -1,    65,    17,    64,    -1,    65,    -1,    -1,    59,
      62,    -1,     5,    70,    67,     6,    -1,    68,    67,    -1,
      -1,    75,    16,    -1,    66,    -1,     8,    75,    16,    -1,
       9,    18,    75,    19,    68,    69,    -1,    13,    18,    75,
      16,    75,    16,    75,    19,    68,    -1,    12,    16,    -1,
      11,    16,    -1,    10,    68,    -1,    -1,    71,    70,    -1,
      -1,    59,    72,    16,    -1,    73,    17,    72,    -1,    73,
      -1,    62,    -1,    62,     3,    74,    -1,    75,    -1,     5,
      77,     6,    -1,    15,    -1,    75,    30,    75,    -1,    75,
      31,    75,    -1,    75,    28,    75,    -1,    75,    29,    75,
      -1,    75,    45,    75,    -1,    75,    46,    75,    -1,    75,
      47,    75,    -1,    75,    48,    75,    -1,    75,    27,    75,
      -1,    75,    32,    75,    -1,    75,    33,    75,    -1,    75,
      34,    75,    -1,    75,    35,    75,    -1,    75,    36,    75,
      -1,    75,    37,    75,    -1,    75,    38,    75,    -1,    75,
      39,    75,    -1,    75,    40,    75,    -1,    75,    41,    75,
      -1,    75,    42,    75,    -1,    75,    43,    75,    -1,    75,
      44,    75,    -1,    75,    49,    75,    -1,    75,    50,    75,
      -1,    75,    51,    75,    -1,    75,    52,    75,    -1,    75,
      53,    75,    -1,    75,    22,    75,    -1,    75,     3,    75,
      -1,    31,    75,    -1,    24,    75,    -1,    25,    75,    -1,
      26,    75,    -1,    23,    75,    -1,    18,    75,    19,    -1,
      15,    18,    77,    19,    -1,    15,    76,    -1,    14,    -1,
      -1,    20,    75,    21,    76,    -1,    -1,    75,    17,    77,
      -1,    75,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    84,    84,    88,    89,    93,    94,    98,    99,   100,
     104,   105,   109,   110,   114,   115,   119,   120,   124,   128,
     129,   130,   134,   138,   142,   143,   147,   148,   149,   150,
     151,   152,   153,   157,   158,   162,   163,   167,   171,   172,
     176,   177,   181,   182,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   228,   229,   233,   234
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGNOP", "TYPE", "LC", "RC", "STRUCT",
  "RETURN", "IF", "ELSE", "BREAK", "CONT", "FOR", "INT", "ID", "SEMI",
  "COMMA", "LP", "RP", "LB", "RB", "DOT", "LOGNOT", "INCR", "DECR", "BNOT",
  "MOD", "PRODUCT", "DIVISION", "PLUS", "MINUS", "SHLEFT", "SHRIGHT",
  "GREATER", "GREATEREQU", "LESS", "LESSEQU", "EQU", "NOTEQU", "BAND",
  "BXOR", "BOR", "LOGAND", "LOGOR", "PLUSAN", "MINUSAN", "PRODUCTAN",
  "DIVISIONAN", "BANDAN", "BXORAN", "BORAN", "SHLEFTAN", "SHRIGHTAN",
  "$accept", "PROGRAM", "EXTDEFS", "EXTDEF", "EXTVARS", "SPEC", "STSPEC",
  "OPTTAG", "VAR", "FUNC", "PARAS", "PARA", "STMTBLOCK", "STMTS", "STMT",
  "ESTMT", "DEFS", "DEF", "DECS", "DEC", "INIT", "EXP", "ARRS", "ARGS", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    58,    58,    58,
      59,    59,    60,    60,    61,    61,    62,    62,    63,    64,
      64,    64,    65,    66,    67,    67,    68,    68,    68,    68,
      68,    68,    68,    69,    69,    70,    70,    71,    72,    72,
      73,    73,    74,    74,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    76,    76,    77,    77
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     3,     1,     3,     0,
       1,     1,     5,     2,     1,     0,     1,     4,     4,     3,
       1,     0,     2,     4,     2,     0,     2,     1,     3,     6,
       9,     2,     2,     2,     0,     2,     0,     3,     3,     1,
       1,     3,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     2,     3,
       4,     2,     1,     0,     4,     0,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    10,    15,     0,     2,     4,     9,    11,    13,     0,
       1,     3,    16,     0,    40,     0,     7,    36,    21,     5,
      83,     0,    36,     6,     9,     0,     0,    36,     0,     0,
      20,    83,    82,    44,    83,    83,    83,    83,    83,    83,
      41,    42,     0,    83,    16,     8,     0,    39,    12,    35,
      22,    18,    21,    87,     0,    83,    83,    81,     0,    78,
      75,    76,    77,    74,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    17,    83,     0,     0,     0,     0,    27,
       0,    83,     0,    37,     0,    19,    83,    43,     0,     0,
      79,    73,    72,    53,    47,    48,    45,    46,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    49,    50,    51,    52,    67,    68,    69,    70,    71,
       0,    83,    32,    31,    83,    23,    24,    26,    38,    86,
      80,    85,    28,     0,     0,    84,    83,    83,    34,     0,
      83,    29,    83,    33,     0,    83,    30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    25,     7,     9,    14,    15,
      29,    30,    99,   100,   101,   161,    26,    27,    46,    16,
      40,   102,    57,    54
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -153
static const yytype_int16 yypact[] =
{
       2,  -153,   -13,    12,  -153,     2,    -8,  -153,    17,    32,
    -153,  -153,    20,    24,     0,    36,    25,     2,     2,  -153,
      91,    29,     2,  -153,    61,    61,    71,     2,    61,    59,
      62,   157,  -153,     7,   157,   157,   157,   157,   157,   157,
    -153,   575,    72,    76,  -153,  -153,    67,    75,  -153,  -153,
      77,  -153,     2,   116,    89,   157,   157,  -153,   167,    81,
      81,    81,    81,   112,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,  -153,   157,    80,    88,    92,    93,  -153,
     104,    76,   218,  -153,    61,  -153,   157,  -153,    94,   269,
    -153,   575,  -153,    81,    81,    81,   112,   112,    98,    98,
       1,     1,     1,     1,   251,   251,   557,   692,   672,   651,
     629,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     320,   157,  -153,  -153,   157,  -153,  -153,  -153,  -153,  -153,
    -153,   103,  -153,   371,   422,  -153,   624,   157,   102,   473,
     624,  -153,   157,  -153,   524,   624,  -153
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,   113,  -153,   106,    21,  -153,  -153,   107,  -153,
      79,  -153,   117,    35,  -152,  -153,   -17,  -153,    69,   -24,
    -153,   -20,    23,   -31
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -26
static const yytype_int16 yytable[] =
{
      41,    47,     8,    20,   158,    43,     1,    12,   163,     2,
      49,    53,    10,   166,    58,    59,    60,    61,    62,    63,
      21,     6,   -14,    65,   108,    55,     6,    56,    66,    67,
      68,    69,    70,    71,    72,    53,   109,    17,    18,    28,
      19,    22,    24,    42,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,    28,   140,   149,    44,    48,    51,    52,
      47,    22,   -25,   103,    94,    95,    53,    96,    97,    98,
      32,    33,   104,    93,    34,   107,    31,    21,   141,    35,
      36,    37,    38,    65,   142,    32,    33,    39,   143,    34,
     145,   144,   160,   150,    35,    36,    37,    38,    11,    64,
      65,   153,    39,    56,   154,    66,    67,    68,    69,    70,
      45,   105,    23,   106,    65,    50,   146,   159,    65,    66,
      67,    68,   164,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      64,    32,    33,   148,   155,    34,     0,     0,     0,     0,
      35,    36,    37,    38,     0,     0,   110,     0,    39,    65,
       0,     0,     0,     0,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   147,     0,     0,     0,     0,     0,
      65,     0,     0,     0,     0,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    64,    65,     0,     0,     0,     0,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,     0,
     151,    65,     0,     0,     0,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   152,     0,     0,     0,
       0,     0,    65,     0,     0,     0,     0,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     156,     0,     0,    65,     0,     0,     0,     0,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   157,     0,
       0,     0,     0,     0,    65,     0,     0,     0,     0,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   162,
       0,     0,     0,     0,     0,    65,     0,     0,     0,     0,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,     0,     0,    65,     0,     0,     0,
       0,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    64,    65,
       0,     0,     0,     0,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    65,     0,     0,
       0,     0,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    22,
       0,     0,    94,    95,     0,    96,    97,    98,    32,    33,
       0,     0,    34,     0,     0,     0,     0,    35,    36,    37,
      38,    65,     0,     0,     0,    39,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    65,     0,     0,     0,     0,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    65,     0,     0,     0,     0,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    65,     0,     0,     0,     0,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-153))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      20,    25,    15,     3,   156,    22,     4,    15,   160,     7,
      27,    31,     0,   165,    34,    35,    36,    37,    38,    39,
      20,     0,     5,    22,    55,    18,     5,    20,    27,    28,
      29,    30,    31,    32,    33,    55,    56,     5,    18,    18,
      16,     5,    17,    14,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    52,    94,   106,    15,     6,    19,    17,
     104,     5,     6,    16,     8,     9,   106,    11,    12,    13,
      14,    15,    17,    21,    18,     6,     5,    20,    18,    23,
      24,    25,    26,    22,    16,    14,    15,    31,    16,    18,
       6,    18,    10,    19,    23,    24,    25,    26,     5,     3,
      22,   141,    31,    20,   144,    27,    28,    29,    30,    31,
      24,    52,    15,    17,    22,    28,   101,   157,    22,    27,
      28,    29,   162,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       3,    14,    15,   104,   151,    18,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    -1,    -1,    19,    -1,    31,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     3,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,     3,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     3,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     5,
      -1,    -1,     8,     9,    -1,    11,    12,    13,    14,    15,
      -1,    -1,    18,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    22,    -1,    -1,    -1,    31,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     7,    55,    56,    57,    59,    60,    15,    61,
       0,    56,    15,    58,    62,    63,    73,     5,    18,    16,
       3,    20,     5,    66,    17,    59,    70,    71,    59,    64,
      65,     5,    14,    15,    18,    23,    24,    25,    26,    31,
      74,    75,    14,    70,    15,    58,    72,    73,     6,    70,
      62,    19,    17,    75,    77,    18,    20,    76,    75,    75,
      75,    75,    75,    75,     3,    22,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    21,     8,     9,    11,    12,    13,    66,
      67,    68,    75,    16,    17,    64,    17,     6,    77,    75,
      19,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    18,    16,    16,    18,     6,    67,    16,    72,    77,
      19,    21,    16,    75,    75,    76,    19,    16,    68,    75,
      10,    69,    16,    68,    75,    19,    68
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
      int yyn = yypact[*yyssp];
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
      yychar = YYLEX;
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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

/* Line 1806 of yacc.c  */
#line 84 "sa.y"
    {(yyval.node) = Record("PROGRAM", (yyvsp[(1) - (1)].node), NULL);}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 88 "sa.y"
    {(yyval.node) = Record("EXTDEFS", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), NULL);}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 89 "sa.y"
    {(yyval.node) = Record("EXTDEFS", NULL);}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 93 "sa.y"
    {(yyval.node) = Record("EXTDEF", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 94 "sa.y"
    {(yyval.node) = Record("EXTDEF", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 98 "sa.y"
    {(yyval.node) = Record("EXTVARS", (yyvsp[(1) - (1)].node), NULL);}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 99 "sa.y"
    {(yyval.node) = Record("EXTVARS", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 100 "sa.y"
    {(yyval.node) = Record("EXTVARS", NULL);}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 104 "sa.y"
    {(yyval.node) = Record("SPEC", (yyvsp[(1) - (1)].node), NULL);}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 105 "sa.y"
    {(yyval.node) = Record("SPEC", (yyvsp[(1) - (1)].node), NULL);}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 109 "sa.y"
    {(yyval.node) = Record("STSPEC", (yyvsp[(1) - (5)].node), (yyvsp[(2) - (5)].node), (yyvsp[(3) - (5)].node), (yyvsp[(4) - (5)].node), (yyvsp[(5) - (5)].node), NULL);}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 110 "sa.y"
    {(yyval.node) = Record("STSPEC", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), NULL);}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 114 "sa.y"
    {(yyval.node) = Record("OPTTAG", (yyvsp[(1) - (1)].node), NULL);}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 115 "sa.y"
    {(yyval.node) = Record("OPTTAG", NULL);}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 119 "sa.y"
    {(yyval.node) = Record("VAR", (yyvsp[(1) - (1)].node), NULL);}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 120 "sa.y"
    {(yyval.node) = Record("VAR", (yyvsp[(1) - (4)].node), (yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node), NULL);}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 124 "sa.y"
    {(yyval.node) = Record("FUNC", (yyvsp[(1) - (4)].node), (yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node), NULL);}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 128 "sa.y"
    {(yyval.node) = Record("PARAS", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 129 "sa.y"
    {(yyval.node) = Record("PARAS", (yyvsp[(1) - (1)].node), NULL);}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 130 "sa.y"
    {(yyval.node) = Record("PARAS", NULL);}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 134 "sa.y"
    {(yyval.node) = Record("PARA", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), NULL);}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 138 "sa.y"
    {(yyval.node) = Record("STMTBLOCK", (yyvsp[(1) - (4)].node), (yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node), NULL);}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 142 "sa.y"
    {(yyval.node) = Record("STMTS", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), NULL);}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 143 "sa.y"
    {(yyval.node) = Record("STMTS", NULL);}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 147 "sa.y"
    {(yyval.node) = Record("STMT", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), NULL);}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 148 "sa.y"
    {(yyval.node) = Record("STMT", (yyvsp[(1) - (1)].node), NULL);}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 149 "sa.y"
    {(yyval.node) = Record("STMT", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 150 "sa.y"
    {(yyval.node) = Record("STMT", (yyvsp[(1) - (6)].node), (yyvsp[(2) - (6)].node), (yyvsp[(3) - (6)].node), (yyvsp[(4) - (6)].node), (yyvsp[(5) - (6)].node), (yyvsp[(6) - (6)].node), NULL);}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 151 "sa.y"
    {(yyval.node) = Record("STMT", (yyvsp[(1) - (9)].node), (yyvsp[(2) - (9)].node), (yyvsp[(3) - (9)].node), (yyvsp[(4) - (9)].node), (yyvsp[(5) - (9)].node), (yyvsp[(6) - (9)].node), (yyvsp[(7) - (9)].node), (yyvsp[(8) - (9)].node), (yyvsp[(9) - (9)].node), NULL);}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 152 "sa.y"
    {(yyval.node) = Record("STMT", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), NULL);}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 153 "sa.y"
    {(yyval.node) = Record("STMT", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), NULL);}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 157 "sa.y"
    {(yyval.node) = Record("ESTMT", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), NULL);}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 158 "sa.y"
    {(yyval.node) = Record("ESTMT", NULL);}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 162 "sa.y"
    {(yyval.node) = Record("DEFS", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), NULL);}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 163 "sa.y"
    {(yyval.node) = Record("DEFS", NULL);}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 167 "sa.y"
    {(yyval.node) = Record("DEF", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 171 "sa.y"
    {(yyval.node) = Record("DECS", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 172 "sa.y"
    {(yyval.node) = Record("DECS", (yyvsp[(1) - (1)].node), NULL);}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 176 "sa.y"
    {(yyval.node) = Record("DEC", (yyvsp[(1) - (1)].node), NULL);}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 177 "sa.y"
    {(yyval.node) = Record("DEC", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 181 "sa.y"
    {(yyval.node) = Record("INIT", (yyvsp[(1) - (1)].node), NULL);}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 182 "sa.y"
    {(yyval.node) = Record("INIT", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 185 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (1)].node), NULL);}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 186 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 187 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 188 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 189 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 190 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 191 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 192 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 193 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 194 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 195 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 196 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 197 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 198 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 199 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 200 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 201 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 202 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 203 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 204 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 205 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 206 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 207 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 208 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 209 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 210 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 211 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 212 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 213 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 214 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 215 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), NULL);}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 216 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), NULL);}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 217 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), NULL);}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 218 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), NULL);}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 219 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), NULL);}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 220 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 221 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (4)].node), (yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node), NULL);}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 222 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), NULL);}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 223 "sa.y"
    {(yyval.node) = Record("EXP", (yyvsp[(1) - (1)].node), NULL);}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 224 "sa.y"
    {(yyval.node) = Record("EXP", NULL);}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 228 "sa.y"
    {(yyval.node) = Record("ARRS", (yyvsp[(1) - (4)].node), (yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node), NULL);}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 229 "sa.y"
    {(yyval.node) = Record("ARRS", NULL);}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 233 "sa.y"
    {(yyval.node) = Record("ARGS", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node), NULL);}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 234 "sa.y"
    {(yyval.node) = Record("ARGS", (yyvsp[(1) - (1)].node), NULL);}
    break;



/* Line 1806 of yacc.c  */
#line 2358 "y.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 237 "sa.y"

char* getVAR_ID(Node* n);
char* getID_eliminatePara(char* id);
void pop_ids(int);
char* getID_type(char* id);
int getID_space(char* id);
void printIDS();
char* get_TMP();

void code_PROGRAM(Node *n);
void code_EXTDEFS(Node* n);
void code_EXTDEF(Node* n);
void code_EXTVARS(Node* n, char* type);
char* code_SPEC(Node* n);
char* code_STSPEC(Node* n);
void code_DEC(Node* n, char* type);
char* code_EXP(Node* n);
char* code_FUNC(Node* n);
char* code_PARAS(Node* n);
char* code_PARA(Node* n, int mode);
void code_STMTBLOCK(Node* n);
void code_DEFS(Node* n);
void code_DEF(Node* n);
void code_DECS(Node* n, char* type);
void code_STMTS(Node* n);
void code_STMT(Node* n);
void code_ESTMT(Node* n);
char* code_ARGS(Node* n);
char* code_ARRS(Node* n);
void deal_with_read(Node* n);
void deal_with_write(Node* n);
void codeGenerator(Node *n);


void walkGraph(Node* n, int layer) {
	fprintf(fout, "%*s_%d", layer*10, n->token, n->attr.space);
	if (n->content != NULL) fprintf(fout, "_%s_%d", n->content, n->attr.space);

	if (n->child != NULL) {
		fprintf(fout, ":\n");
		walkGraph(n->child, layer+1);
	}
	else fprintf(fout, "\n");
	if (n->next != NULL) walkGraph(n->next, layer);

	return;
}
char* get_TMP() {
	char* ret;
	ret = malloc(sizeof(char)*50);
	sprintf(ret, "%%tmp_%d", counter++);
	return ret;
}

char* getID_type(char* id) {
	int i;
	for (i = 0; i < ptr_ids; ++i) {
		if (strcmp(id, ids[i].id) == 0)
			return ids[i].type;
	}
	return NULL;
}
int getID_space(char* id) {
	int i;
	for (i = 0; i < ptr_ids; ++i) {
		if (strcmp(id, ids[i].id) == 0)
			return ids[i].space;
	}
	return 0;	
}

void updateAttr(Node* n, Attr attr) {
	n->attr = attr;
	n = n->child;
	while (n!=NULL) {
		updateAttr(n, attr);
		n = n->next;
	}
	return;
}

void record_ids(char* var_id, char* type, int space, int isPara) {
	ids[ptr_ids].id = strdup(var_id);
	ids[ptr_ids].type = strdup(type);
	ids[ptr_ids].space = space;
	ids[ptr_ids].isPara = isPara;
	ptr_ids += 1;
	return;
}

void pop_ids(int space){
	while (ids[ptr_ids-1].space == space) {
		ptr_ids -= 1;
	}
	return;
}

void deal_with_read(Node* n) {
	n = n->child;
	Attr attr = {n->attr.space, 1};
	updateAttr(n->next->next, attr);
	char* args_code = code_ARGS(n->next->next);
	char ret[CODE_LENGTH] = "";
	sprintf(ret, "%%call%d", counter++);
	fprintf(fout, "%s = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), %s)\n", ret, args_code);
	return;
}

void deal_with_write(Node* n){
	n = n->child;
	char* args_code = code_ARGS(n->next->next);
	char ret[CODE_LENGTH] = "";
	sprintf(ret, "%%call%d", counter++);
	fprintf(fout, "%s = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), %s)\n", ret, args_code);
	return;	
}

void code_PROGRAM(Node* n) {
	printf("PROGRAM\n");
	char* code;
	code = strdup(";author ZZQ\n");
	strcat(code, "@.str = private unnamed_addr constant [3 x i8] c\"%d\\00\", align 1\n");
	strcat(code, "@.str1 = private unnamed_addr constant [4 x i8] c\"%d\\0A\\00\", align 1\n");
	strcat(code, "declare i32 @printf(i8*, ...)\n");
	strcat(code, "declare i32 @__isoc99_scanf(i8*, ...)\n");
	fprintf(fout, "%s", code);
	code_EXTDEFS(n->child);
	return;
}

void code_EXTDEFS(Node* n) {
	printf("EXTDEFS\n");
	if (n->child == NULL) return;
	n = n->child;         //EXTDEF EXTDEFS
	code_EXTDEF(n);
	code_EXTDEFS(n->next);
	return;
}

void code_EXTDEF(Node* n) {
	printf("EXTDEF\n");
	n = n->child;
	char* type;
	char code[CODE_LENGTH] = "";

	type = code_SPEC(n);
	n = n->next;
	if (strcmp(n->token, "EXTVARS") == 0) {
		code_EXTVARS(n, type);
	}
	else {     //FUNC
		Attr tmp_attr = {n->attr.space+1};
		updateAttr(n, tmp_attr);
		updateAttr(n->next, tmp_attr);
		char tmp[CODE_LENGTH] = "";
		sprintf(tmp, "define %s ", type);
		strcat(code, tmp);
		strcat(code, code_FUNC(n));

		fprintf(fout, "%s", code);
		code_STMTBLOCK(n->next);
		fprintf(fout, "}\n");

		pop_ids(n->attr.space);
	}
	return;
}

void code_EXTVARS(Node* n, char* type) {
	printf("EXTVARS\n");
	n = n->child;
	while (n!= NULL){
		if (strcmp(n->token, "DEC") == 0) code_DEC(n, type);
		else if (strcmp(n->token, "EXTVARS") == 0) code_EXTVARS(n, type);
		else {}
		n = n->next;
	}
	return;	
}

char* code_SPEC(Node* n) {
	printf("SPEC\n");
	char* code = "";
	n = n->child;
	if (strcmp(n->token, "TYPE")==0) return "i32";
	else return code_STSPEC(n); //STSPEC
}

char* code_STSPEC(Node* n) {
	printf("STSPEC\n");
	return "STSPEC";
} 

void code_OPTTAG(Node* n) {
	
}

void code_VAR(Node* n) {
	
}

char* code_FUNC(Node* n) {
	n = n->child;
	char* ret_code;
	ret_code = (char*)malloc(sizeof(char)*CODE_LENGTH);
	char* func_id = n->content;
	char* paras = code_PARAS(n->next->next);
	sprintf(ret_code, "@%s(%s", func_id, paras);
	return ret_code;
}

char* code_PARAS(Node* n) {
	char* ret_code;
	ret_code = (char*)malloc(sizeof(char)*CODE_LENGTH);

	char para_code[CODE_LENGTH] = "";
	char init_code[CODE_LENGTH] = "";
	while(1==1) {
		n = n->child;
		if (n == NULL) break;
		strcat(ret_code, code_PARA(n, 0));
		strcat(init_code, code_PARA(n, 1));
		if (n->next != NULL){
			strcat(ret_code, ", ");
			n = n->next->next;
		}
		else break;
	}
	strcat(ret_code, ") {\nentry:\n");
	strcat(ret_code, init_code);
	return ret_code;
}

char* code_PARA(Node* n, int mode) {
	n = n->child;
	char* ret_code;
	ret_code = (char*)malloc(sizeof(char)*CODE_LENGTH);
	char* type = code_SPEC(n);
	char* var_id = getVAR_ID(n->next);

	if (mode == 0)	{			// get parameter code
		sprintf(ret_code, "%s %%%s", type, var_id);
	}
	else {						// init parameter code
		sprintf(ret_code, "%%%s.addr = alloca i32, align 4\nstore i32 %%%s, i32* %%%s.addr, align 4\n", var_id, var_id, var_id);
		record_ids(var_id, type, n->attr.space, 1);
	}
	return ret_code;
}

void code_STMTBLOCK(Node* n) {
	n = n->child;
	char code[CODE_LENGTH] = "";
	n = n->next;  //DEFS
	code_DEFS(n);
	n = n->next;  //STMTS
	code_STMTS(n);
	return;
}

void code_STMTS(Node* n) {     // | STMT STMTS
	while (n->child != NULL) {
		n = n->child;    //STMT
		code_STMT(n);
		n = n->next;
	}
	return;	
}

void code_STMT(Node* n) {
	n = n->child;

	if (strcmp(n->token, "EXP") == 0)  {				// EXP SEMI
		char* exp_ret = code_EXP(n);
	}
	else if (strcmp(n->token, "STMTBLOCK") == 0) {		// STMTBLOCK
		code_STMTBLOCK(n);
	}
	else if (strcmp(n->token, "RETURN") == 0) {			// RETURN EXP SEMI
		char* exp_code = code_EXP(n->next);
		fprintf(fout, "ret i32 %s\n", exp_code);
	}
	else if (strcmp(n->token, "IF") == 0) {				// IF LP EXP RP STMT ESTMT
		char* exp_code = code_EXP(n->next->next);
		if (strcmp(n->next->next->attr.type, "i32") == 0) {
			char* reg = get_TMP();
			fprintf(fout, "%s = icmp ne i32 %s, 0\n", reg, exp_code);
			exp_code = reg;
		}
		fprintf(fout, "br i1 %s, label %%if.then%d, label %%if.else%d\n\n", exp_code, counter, counter);
		int tmp_counter = counter++;
		fprintf(fout, "if.then%d:\n", tmp_counter);
		code_STMT(n->next->next->next->next);
		fprintf(fout, "br label %%if.end%d\n\n", tmp_counter);
		fprintf(fout, "if.else%d:\n", tmp_counter);
		code_ESTMT(n->next->next->next->next->next);
		fprintf(fout, "br label %%if.end%d\n\n", tmp_counter);
		fprintf(fout, "if.end%d:\n", tmp_counter);
	}
	else if (strcmp(n->token, "FOR") == 0) {			// FOR LP EXP SEMI EXP SEMI EXP RP STMT
		int tmp_counter = counter++;
		char* exp_code;
		n = n->next->next;				//first EXP
		exp_code = code_EXP(n);
		fprintf(fout, "br label %%for.cond%d\n\n", tmp_counter);
		fprintf(fout, "for.cond%d:\n", tmp_counter);
		n = n->next->next;				//second EXP
		exp_code = code_EXP(n);
		if (strcmp(n->attr.type, "i32") == 0) {
			char* reg = get_TMP();
			fprintf(fout, "%s = icmp ne i32 %s, 0\n", reg, exp_code);
			exp_code = reg;
		}
		fprintf(fout, "br i1 %s, label %%for.body%d, label %%for.end%d\n\n", exp_code, tmp_counter, tmp_counter);
		fprintf(fout, "for.body%d:\n", tmp_counter);
		code_STMT(n->next->next->next->next);
		fprintf(fout, "br label %%for.inc%d\n\n", tmp_counter);
		fprintf(fout, "for.inc%d:\n", tmp_counter);
		exp_code = code_EXP(n->next->next);
		fprintf(fout, "br label %%for.cond%d\n\n", tmp_counter);
		fprintf(fout, "for.end%d:\n", tmp_counter);
	}
	else if (strcmp(n->token, "CONT") == 0) {			// CONT SEMI

	}
	else if (strcmp(n->token, "BREAK") == 0) {			// BREAK SEMI

	}
	else {}

	return;
}

void code_ESTMT(Node* n) {
	n = n->child;
	if (n == NULL) {					// nothing
	}
	else {								// ELSE STMT
		code_STMT(n->next);
	}
	return;
}

void code_DEFS(Node* n) {
	n = n->child;
	while(n != NULL) {
		code_DEF(n);
		n = n->next->child;
	}
	return;
}

void code_DEF(Node* n) {
	printf("DEF\n");
	n = n->child;
	char* type;
	char code[CODE_LENGTH] = "";

	type = code_SPEC(n);
	n = n->next;          //DECS
	code_DECS(n, type);
	n = n->child;

}

void code_DECS(Node* n, char* type) {
	printf("DECS\n");
	n = n->child;     //DEC
	while (n!= NULL){
		code_DEC(n, type);
		if (n->next != NULL) n = n->next->next->child;
		else break;
	}
	return;	
}

char* getID_eliminatePara(char* id){
	int i;
	for (i = 0; i < ptr_ids; ++i) {
		if ((strcmp(id, ids[i].id) == 0) && (ids[i].isPara == 1)){
			char* ret;
			ret = (char*)malloc(sizeof(char)*CODE_LENGTH);
			sprintf(ret, "%s.addr", id);
			return ret;
		}
	}
	return id;
}
char* getVAR_ID(Node* n){
	while(n != NULL) {
		if (strcmp(n->token, "ID") == 0) return getID_eliminatePara(n->content);
		n = n->child;
	}
	return "NULL";
}
char* getVAR_INDEX(Node* n){
	if (strcmp(n->child->token, "VAR") != 0) return "-1";
	return n->child->next->next->content;
}

void code_DEC(Node* n, char* type) {
	printf("DEC\n");
	char code[CODE_LENGTH] = "";
	n = n->child;
	
	char* var_id = getVAR_ID(n);
	// record this variable
	// record_ids(var_id, type, n->attr.space, 0);

	//declare
	printf("DEC.declare\n");
	char* res = getVAR_INDEX(n);
	char tmp[CODE_LENGTH] = "";
	if (strcmp(res, "-1") == 0) {    // is not array
		if (n->attr.space == 0) sprintf(tmp, "@%s = common global %s ", var_id, type);
		else sprintf(tmp, "%%%s = alloca %s, align 4\n", var_id, type);
		record_ids(var_id, type, n->attr.space, 0);
		printf("get all\n");
	}
	else {           				// is array
		if (n->attr.space == 0) sprintf(tmp, "@%s = common global [%s x %s] ", var_id, res, type);
		else sprintf(tmp, "%%%s = alloca [%s x %s], align 4\n", var_id, res, type);
		char tmp[CODE_LENGTH] = "";
		sprintf (tmp, "%s x %s", res, type);
		record_ids(var_id, tmp, n->attr.space, 0);
	}
	strcat(code, tmp);

	printf("__DEC.init__\n");
	//init
	if (n->next != NULL) {
		Node* init_node = n->next->next;
		if (strcmp(init_node->child->token, "EXP") == 0) {
			char* reg_name = code_EXP(init_node->child);
			if (n->attr.space == 0) sprintf(tmp, "%s, align 4\n", reg_name);
			else sprintf(tmp, "store i32 %s, i32* %%%s, align 4\n", reg_name, var_id);
			strcat(code, tmp);
		}
		else {   //list
			Node* args_node = init_node->child->next;
			int i = 0;
			//begin
			Node* exp_node = args_node->child;
			char* reg_name = code_EXP(exp_node);
			if (n->attr.space == 0) {
				sprintf(tmp, "[%s %s", type, reg_name);
			}
			else {
				sprintf(tmp, "%%array%s.d%d = getelementptr inbounds [%s x %s]* %%%s, i32 0, i32 0\n", var_id, i, res, type, var_id);
				strcat(code, tmp);
				sprintf(tmp, "store i32 %s, i32* %%array%s.d%d\n", reg_name, var_id, i);
			}
			strcat(code, tmp);
			while(exp_node->next != NULL) {
				printf ("flag\n");
				exp_node = exp_node->next->next->child;
				i = i + 1;
				reg_name = code_EXP(exp_node);
				if (n->attr.space == 0) {
					sprintf(tmp, ", %s %s", type, reg_name);
				}
				else {
					sprintf(tmp, "%%array%s.d%d = getelementptr inbounds i32* %%array%s.d%d, i32 1\n", var_id, i, var_id, i-1);
					strcat(code, tmp);
					sprintf(tmp, "store i32 %s, i32* %%array%s.d%d\n", reg_name, var_id, i);
				}
				strcat(code, tmp);
			}
			if (n->attr.space == 0) strcat(code, "], align 4\n");	
		}
	}
	else {
		if (n->attr.space == 0) strcat(code, "zeroinitializer, align 4\n");	
	}
	fprintf(fout, "%s", code);
	return;	
}

void code_INIT(Node* n) {
	
}

// if EXP is a INT, return that INT
// else return the name of that register, which store the EXP result.
char* code_EXP(Node* n) {
	char* ret;
	ret = malloc(sizeof(char)*CODE_LENGTH);
	Node* org = n;
	n = n->child;
	if (n == NULL) {													// nothing
		sprintf(ret, "");
	}
	else if (strcmp(n->token, "ID") ==  0) {
		if (n->next == NULL) {											// ID
			char c;
			if (getID_space(n->content) == 0) c = '@';
			else c = '%';
			if (org->attr.isLeft == 0) {
				ret = get_TMP();
				fprintf(fout, "%s = load i32* %c%s, align 4\n", ret, c, getID_eliminatePara(n->content));
			}
			else {
				sprintf(ret, "%c%s", c, getID_eliminatePara(n->content));
			}
			org->attr.type = strdup("i32");
		}
		else if (strcmp(n->next->token, "LP") == 0) {					// ID LP ARGS RP
			if (strcmp(n->content, "read") == 0) deal_with_read(org);
			else if (strcmp(n->content, "write") == 0) deal_with_write(org);
			else {
				char* args_code = code_ARGS(n->next->next);
				sprintf(ret, "%%call%d", counter++);
				fprintf(fout, "%s = call i32 @%s (%s)\n", ret, n->content, args_code);
			}
			org->attr.type = strdup("i32");	
		}
		else if (strcmp(n->next->token, "ARRS") == 0) {					// ID ARRS
			ret = get_TMP();
			char c;
			char* arrs_code;

			arrs_code = code_ARRS(n->next);
			if (getID_space(n->content) == 0) c = '@';
			else c = '%';
			if (org->attr.isLeft == 0) {
				char* reg = get_TMP();
				fprintf(fout, "%s = getelementptr inbounds [%s]* %c%s, i32 0, %s\n", reg, getID_type(n->content), c, getID_eliminatePara(n->content), arrs_code);
				fprintf(fout, "%s = load i32* %s, align 4\n", ret, reg);
			}
			else {
				fprintf(fout, "%s = getelementptr inbounds [%s]* %c%s, i32 0, %s\n", ret, getID_type(n->content), c, getID_eliminatePara(n->content), arrs_code);
			}
			org->attr.type = strdup("i32");
		}
		else {}
	}
	else if (strcmp(n->token, "EXP") == 0) {
		ret = get_TMP();
		if (strcmp(n->next->token, "PLUS") == 0) {						// EXP PLUS EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			fprintf(fout, "%s = add i32 %s, %s \n", ret, opr1, opr2);
			org->attr.type = strdup("i32");
		}
		else if (strcmp(n->next->token, "MINUS") == 0) {				// EXP MINUS EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			fprintf(fout, "%s = sub i32 %s, %s\n", ret, opr1, opr2);	
			org->attr.type = strdup("i32");
		}
		else if (strcmp(n->next->token, "PRODUCT") == 0) {				// EXP PRODUCT EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			fprintf(fout, "%s = mul i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i32");
		}
		else if (strcmp(n->next->token, "DIVISION") == 0) {				// EXP DIVISION EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			fprintf(fout, "%s = sdiv i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i32");
		}
		else if (strcmp(n->next->token, "MOD") == 0) {					// EXP MOD EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			fprintf(fout, "%s = srem i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i32");
		}
		else if (strcmp(n->next->token, "BAND") == 0) {					// EXP BAND EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			fprintf(fout, "%s = and i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i32");
		}
		else if (strcmp(n->next->token, "BXOR") == 0) {					// EXP BXOR EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			fprintf(fout, "%s = xor i32 %s, %s\n", ret, opr1, opr2);	
			org->attr.type = strdup("i32");
		}
		else if (strcmp(n->next->token, "BOR") == 0) {					// EXP BOR EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			fprintf(fout, "%s = or i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i32");
		}
		else if (strcmp(n->next->token, "SHLEFT") == 0) {				// EXP SHLEFT EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			fprintf(fout, "%s = shl i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i32");
		}
		else if (strcmp(n->next->token, "SHRIGHT") == 0) {				// EXP SHRIGHT EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			fprintf(fout, "%s = lshr i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i32");
		}
		else if (strcmp(n->next->token, "LOGAND") == 0) {				// EXP LOGAND EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			fprintf(fout, "%s = and i1 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i1");
		}
		else if (strcmp(n->next->token, "LOGOR") == 0) {				// EXP LOGOR EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			fprintf(fout, "%s = or i1 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i1");
		}
		else if (strcmp(n->next->token, "GREATER") == 0) {				// EXP GREATER EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			fprintf(fout, "%s = icmp sgt i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i1");
		}
		else if (strcmp(n->next->token, "GREATEREQU") == 0) {			// EXP GREATEREQU EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			fprintf(fout, "%s = icmp sge i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i1");
		}
		else if (strcmp(n->next->token, "LESS") == 0) {					// EXP LESS EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			fprintf(fout, "%s = icmp slt i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i1");
		}
		else if (strcmp(n->next->token, "LESSEQU") == 0) {				// EXP LESSEQU EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			fprintf(fout, "%s = icmp sle i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i1");
		}
		else if (strcmp(n->next->token, "EQU") == 0) {					// EXP EQU EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			fprintf(fout, "%s = icmp eq i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i1");
		}
		else if (strcmp(n->next->token, "NOTEQU") == 0) {				// EXP NOTEQU EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			fprintf(fout, "%s = icmp ne i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i1");
		}
		else if (strcmp(n->next->token, "DOT") == 0) {

		}
		else if (strcmp(n->next->token, "ASSIGNOP") == 0) {				// EXP ASSIGNOP EXP
			n->attr.isLeft = 1;
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			fprintf(fout, "store i32 %s, i32* %s, align 4\n", opr2, opr1);
			org->attr.type = strdup("i32");
		}
		else {		// some operation and then assign     EXP ***AN EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			Attr attr = n->attr;
			attr.isLeft = 1;
			updateAttr(n, attr);
			char* opr = code_EXP(n);
			if (strcmp(n->next->token, "PLUSAN") == 0) {				// EXP PLUSAN EXP
				fprintf(fout, "%s = add i32 %s, %s \n", ret, opr1, opr2);
			}
			else if (strcmp(n->next->token, "MINUSAN") == 0) {			// EXP MINUSAN EXP
				fprintf(fout, "%s = sub i32 %s, %s \n", ret, opr1, opr2);
			}
			else if (strcmp(n->next->token, "PRODUCTAN") == 0) {		// EXP PRODECTAN EXP
				fprintf(fout, "%s = mul i32 %s, %s \n", ret, opr1, opr2);
			}
			else if (strcmp(n->next->token, "DIVISIONAN") == 0) {		// EXP DIVISIONAN EXP
				fprintf(fout, "%s = sdiv i32 %s, %s \n", ret, opr1, opr2);
			}
			else if (strcmp(n->next->token, "BANDAN") == 0) {			// EXP BANDAN EXP
				fprintf(fout, "%s = and i32 %s, %s \n", ret, opr1, opr2);
			}
			else if (strcmp(n->next->token, "BXORAN") == 0) {			// EXP BXORAN EXP
				fprintf(fout, "%s = xor i32 %s, %s \n", ret, opr1, opr2);
			}
			else if (strcmp(n->next->token, "BORAN") == 0) {			// EXP BORAN EXP
				fprintf(fout, "%s = or i32 %s, %s \n", ret, opr1, opr2);
			}
			else if (strcmp(n->next->token, "SHLEFTAN") == 0) {			// EXP SHLEFTAN EXP
				fprintf(fout, "%s = shl i32 %s, %s \n", ret, opr1, opr2);
			}
			else if (strcmp(n->next->token, "SHRIGHTAN") == 0) {		// EXP SHRIGHTAN EXP
				fprintf(fout, "%s = lshr i32 %s, %s \n", ret, opr1, opr2);
			}
			else {}
			fprintf(fout, "store i32 %s, i32* %s, align 4\n", ret, opr);
			org->attr.type = strdup("i32");
		}

	}
	else if (strcmp(n->token, "MINUS") == 0) {							// MINUS EXP
		ret = get_TMP();
		char* opr = code_EXP(n->next);
		fprintf(fout, "%s = sub i32 0, %s\n", ret, opr);	
	}
	else if (strcmp(n->token, "INCR") == 0) {							// INCR EXP
		ret = get_TMP();
		char* opr = code_EXP(n->next);
		fprintf(fout, "%s = add i32 %s, 1 \n", ret, opr);
		Attr attr = n->attr;
		attr.isLeft = 1;
		updateAttr(n->next, attr);
		opr = code_EXP(n->next);
		fprintf(fout, "store i32 %s, i32* %s, align 4\n", ret, opr);
		org->attr.type = strdup("i32");
	}
	else if (strcmp(n->token, "DECR") == 0) {							// DECR EXP
		ret = get_TMP();
		char* opr = code_EXP(n->next);
		fprintf(fout, "%s = sub i32 %s, 1 \n", ret, opr);
		Attr attr = n->attr;
		attr.isLeft = 1;
		updateAttr(n->next, attr);
		opr = code_EXP(n->next);
		fprintf(fout, "store i32 %s, i32* %s, align 4\n", ret, opr);
		org->attr.type = strdup("i32");
	}
	else if (strcmp(n->token, "BNOT") == 0) {							// BNOT EXP
		ret = get_TMP();
		char* opr = code_EXP(n->next);
		fprintf(fout, "%s = xor i32 %s, -1\n", ret, opr);
		org->attr.type = strdup("i32");
	}
	else if (strcmp(n->token, "LOGNOT") == 0) {							// LOGNOT EXP
		ret = get_TMP();
		char* opr = code_EXP(n->next);
		if (strcmp(n->next->attr.type, "i32") == 0)
			fprintf(fout, "%s = icmp eq i32 %s, 0\n", ret, opr);
		else
			fprintf(fout, "%s = xor i1 %s, -1\n", ret, opr);
		org->attr.type = strdup("i1");
	}
	else if (strcmp(n->token, "LP") == 0) {								// LP EXP RP
		ret = code_EXP(n->next);
		org->attr.type = strdup(n->next->attr.type);
	}
	else if (strcmp(n->token, "INT") == 0) {							// INT
		sprintf(ret, "%s", n->content);
		org->attr.type = strdup("i32");
	}
	else {}

	return ret;
}

char* code_ARGS(Node* n) {
	char ret[CODE_LENGTH] = "";
	char tmp[CODE_LENGTH] = "";
	char c;
	if (n->attr.isLeft == 0) c = ' ';
	else c = '*';

	n = n->child;
	char* exp_code = code_EXP(n);
	sprintf(tmp, "i32%c %s", c, exp_code);
	strcat(ret, tmp);
	while (n->next != NULL) {
		n = n->next->next->child;
		exp_code = code_EXP(n);
		sprintf(tmp, ", i32 %s", exp_code);
		strcat(ret, tmp);
	}
	return ret;	
}

char* code_ARRS(Node* n) {					// LB EXP RB ARRS
	char* ret;
	ret = (char*)malloc(sizeof(char)*CODE_LENGTH);
	n = n->child;
	char* exp_code = code_EXP(n->next);
	sprintf(ret, "i32 %s", exp_code);
	return ret;
}

void codeGenerator(Node *n) {
	if (strcmp(n->token, "PROGRAM") == 0) code_PROGRAM(n);
	else if (strcmp(n->token, "EXTDEFS") == 0) code_EXTDEFS(n);
	else if (strcmp(n->token, "EXTDEF") == 0) code_EXTDEF(n);
	else if (strcmp(n->token, "SPEC") == 0) code_SPEC(n);
	else if (strcmp(n->token, "STSPEC") == 0) code_STSPEC(n);
	else if (strcmp(n->token, "OPTTAG") == 0) code_OPTTAG(n);
	else if (strcmp(n->token, "VAR") == 0) code_VAR(n);
	else if (strcmp(n->token, "FUNC") == 0) code_FUNC(n);
	else if (strcmp(n->token, "PARAS") == 0) code_PARAS(n);
	else if (strcmp(n->token, "STMTBLOCK") == 0) code_STMTBLOCK(n);
	else if (strcmp(n->token, "STMTS") == 0) code_STMTS(n);
	else if (strcmp(n->token, "STMT") == 0) code_STMT(n);
	else if (strcmp(n->token, "ESTMT") == 0) code_ESTMT(n);
	else if (strcmp(n->token, "DEFS") == 0) code_DEFS(n);
	else if (strcmp(n->token, "DEF") == 0) code_DEF(n);
	else if (strcmp(n->token, "INIT") == 0) code_INIT(n);
	else if (strcmp(n->token, "EXP") == 0) code_EXP(n);
	else if (strcmp(n->token, "ARGS") == 0) code_ARGS(n);
	else return;
	return;
}
void some_init() {
	types = malloc(sizeof(Type)*TYPE_NUMBER);
	ids = malloc(sizeof(Identifier)*ID_NUMBER);

	types[0].type = strdup("i32");
}
void printIDS(){
	int i = 0;
	for (i = 0; i < ptr_ids; i++) {
		printf("%s %s %d %d\n", ids[i].id, ids[i].type, ids[i].space, ids[i].isPara);
	}
}
int main(int argc, char* argv[]){
	//printf ("%s%s\n", argv[0], argv[1]);
	yydebug=0;	//set it to 1, that should be DEBUG mode, to 0, that will disable DEBUG
	freopen(argv[1], "r", stdin);
	//fout = stdout;
	fout = fopen(argv[2], "w");
	yyparse();
	printf("\n\n");
	// walkGraph(head, 1);
	// fclose(fout);
	// printf("walk Graph has done\n");
 
	some_init();
	codeGenerator(head);

	printIDS();
	return 0;
}

int yyerror(char *msg){
	fprintf(fout, "ERROR.", msg);
	exit(0);
	return 0;
}

Node* Record(char* content, ...){
	Node *res = malloc(sizeof(Node));
	res->token = strdup(content);
	res->content = NULL;

	va_list ap;
	va_start(ap, content);

	Node *tmp;
	tmp = va_arg(ap, Node*);

	res->child = tmp;
	res->next = NULL;

	Node *ttmp;
	while(tmp != NULL) {
		ttmp = va_arg(ap, Node*);
		tmp->next = ttmp;
		tmp = ttmp;
	}
	va_end(ap);

	head = res;
	return res;
}


