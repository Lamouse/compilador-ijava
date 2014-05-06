/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PRINT = 258,
     PARSEINT = 259,
     RETURN = 260,
     DOTLENGTH = 261,
     INT = 262,
     BOOL = 263,
     VOID = 264,
     STRING = 265,
     NEW = 266,
     IF = 267,
     ELSE = 268,
     WHILE = 269,
     CLASS = 270,
     PUBLIC = 271,
     STATIC = 272,
     OCURV = 273,
     CCURV = 274,
     OBRACE = 275,
     CBRACE = 276,
     OSQUARE = 277,
     CSQUARE = 278,
     NOT = 279,
     ASSIGN = 280,
     SEMIC = 281,
     COMMA = 282,
     RESERVED = 283,
     OP11 = 284,
     OP12 = 285,
     OP21 = 286,
     OP22 = 287,
     OP3 = 288,
     OP4 = 289,
     INTLIT = 290,
     BOOLLIT = 291,
     ID = 292,
     EXPR = 293,
     IFX = 294,
     OPERSX = 295
   };
#endif
/* Tokens.  */
#define PRINT 258
#define PARSEINT 259
#define RETURN 260
#define DOTLENGTH 261
#define INT 262
#define BOOL 263
#define VOID 264
#define STRING 265
#define NEW 266
#define IF 267
#define ELSE 268
#define WHILE 269
#define CLASS 270
#define PUBLIC 271
#define STATIC 272
#define OCURV 273
#define CCURV 274
#define OBRACE 275
#define CBRACE 276
#define OSQUARE 277
#define CSQUARE 278
#define NOT 279
#define ASSIGN 280
#define SEMIC 281
#define COMMA 282
#define RESERVED 283
#define OP11 284
#define OP12 285
#define OP21 286
#define OP22 287
#define OP3 288
#define OP4 289
#define INTLIT 290
#define BOOLLIT 291
#define ID 292
#define EXPR 293
#define IFX 294
#define OPERSX 295




/* Copy the first part of user declarations.  */
#line 1 "ijparser.y"

#include<stdio.h>
#include<string.h>
#include "ijparser.h"

extern int colunaAux;
extern int linhaAux;
extern char* yytext;


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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 94 "ijparser.y"
{
	Program* program;
	Declaration* declaration;
	Statement* statement;
	VarDecl* var;
    Ids* ids;
    Exp* exp;
    Type type;
    ExpType expType;

	char* string;
}
/* Line 193 of yacc.c.  */
#line 199 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 212 "y.tab.c"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   246

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNRULES -- Number of states.  */
#define YYNSTATES  137

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     9,    11,    12,    15,    17,    19,    21,
      24,    35,    38,    40,    42,    43,    48,    50,    51,    55,
      57,    60,    62,    65,    69,    73,    75,    78,    80,    84,
      86,    90,    93,    99,   105,   110,   118,   122,   128,   130,
     131,   137,   139,   143,   147,   151,   155,   159,   163,   168,
     170,   172,   174,   177,   180,   183,   191,   196,   200,   202,
     203,   207,   209,   211,   213,   215,   219,   221
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    15,    37,    20,    43,    21,    -1,    44,
      -1,    -1,    45,    44,    -1,    45,    -1,    46,    -1,    47,
      -1,    17,    53,    -1,    16,    17,    63,    37,    18,    49,
      19,    20,    48,    21,    -1,    51,    55,    -1,    51,    -1,
      55,    -1,    -1,    10,    22,    23,    37,    -1,    50,    -1,
      -1,    52,    27,    50,    -1,    52,    -1,    53,    51,    -1,
      53,    -1,    64,    37,    -1,    64,    54,    26,    -1,    37,
      27,    54,    -1,    37,    -1,    56,    55,    -1,    56,    -1,
      57,    13,    56,    -1,    57,    -1,    20,    55,    21,    -1,
      20,    21,    -1,    14,    18,    59,    19,    56,    -1,     3,
      18,    59,    19,    26,    -1,    37,    25,    59,    26,    -1,
      37,    22,    59,    23,    25,    59,    26,    -1,     5,    58,
      26,    -1,    12,    18,    59,    19,    56,    -1,    59,    -1,
      -1,    11,    65,    22,    59,    23,    -1,    60,    -1,    59,
      29,    59,    -1,    59,    30,    59,    -1,    59,    31,    59,
      -1,    59,    32,    59,    -1,    59,    33,    59,    -1,    59,
      34,    59,    -1,    60,    22,    59,    23,    -1,    37,    -1,
      35,    -1,    36,    -1,    59,     6,    -1,    33,    59,    -1,
      24,    59,    -1,     4,    18,    37,    22,    59,    23,    19,
      -1,    37,    18,    61,    19,    -1,    18,    59,    19,    -1,
      62,    -1,    -1,    59,    27,    62,    -1,    59,    -1,     9,
      -1,    64,    -1,    65,    -1,    65,    22,    23,    -1,     7,
      -1,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   108,   108,   110,   111,   113,   114,   116,   117,   119,
     121,   123,   124,   125,   126,   128,   129,   130,   132,   133,
     135,   136,   138,   140,   142,   143,   145,   146,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   158,   160,   161,
     163,   164,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   183,   184,
     186,   187,   189,   190,   192,   193,   195,   196
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINT", "PARSEINT", "RETURN",
  "DOTLENGTH", "INT", "BOOL", "VOID", "STRING", "NEW", "IF", "ELSE",
  "WHILE", "CLASS", "PUBLIC", "STATIC", "OCURV", "CCURV", "OBRACE",
  "CBRACE", "OSQUARE", "CSQUARE", "NOT", "ASSIGN", "SEMIC", "COMMA",
  "RESERVED", "OP11", "OP12", "OP21", "OP22", "OP3", "OP4", "INTLIT",
  "BOOLLIT", "ID", "EXPR", "IFX", "OPERSX", "$accept", "program",
  "declarations", "declarationList", "declaration", "fieldDecl",
  "methodDecl", "statements", "params", "paramList", "varList", "param",
  "varDecl", "ids", "stateList", "statement", "ifState", "optionalExp",
  "expr", "safeExpr", "optionalArgs", "args", "type", "varType", "numType", 0
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
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    45,    45,    46,
      47,    48,    48,    48,    48,    49,    49,    49,    50,    50,
      51,    51,    52,    53,    54,    54,    55,    55,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    57,    58,    58,
      59,    59,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    61,    61,
      62,    62,    63,    63,    64,    64,    65,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     1,     0,     2,     1,     1,     1,     2,
      10,     2,     1,     1,     0,     4,     1,     0,     3,     1,
       2,     1,     2,     3,     3,     1,     2,     1,     3,     1,
       3,     2,     5,     5,     4,     7,     3,     5,     1,     0,
       5,     1,     3,     3,     3,     3,     3,     3,     4,     1,
       1,     1,     2,     2,     2,     7,     4,     3,     1,     0,
       3,     1,     1,     1,     1,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     0,     0,     3,
       6,     7,     8,     0,    66,    67,     9,     0,    64,     2,
       5,    62,     0,    63,    25,     0,     0,     0,     0,    23,
      65,    17,    24,     0,     0,    16,    19,     0,     0,     0,
       0,    22,     0,    14,    18,    15,     0,    39,     0,     0,
       0,     0,     0,    12,    21,    13,    27,    29,     0,     0,
       0,     0,     0,     0,    50,    51,    49,     0,    38,    41,
       0,     0,    31,     0,     0,     0,    10,    11,    20,    26,
       0,     0,     0,     0,     0,    54,    53,    59,    36,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
       0,     0,    28,     0,     0,     0,    57,    61,     0,    58,
      42,    43,    44,    45,    46,    47,     0,     0,     0,     0,
      34,    33,     0,     0,     0,    56,    48,    37,    32,     0,
       0,    40,    60,     0,     0,    35,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     8,     9,    10,    11,    12,    52,    34,    35,
      53,    36,    54,    25,    55,    56,    57,    67,   107,    69,
     108,   109,    22,    17,    18
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -80
static const yytype_int16 yypact[] =
{
      -6,   -16,    18,     6,   -80,   -12,    19,    33,    32,   -80,
     -12,   -80,   -80,   106,   -80,   -80,   -80,    20,    40,   -80,
     -80,   -80,    23,   -80,    28,    39,    41,    54,    20,   -80,
     -80,   102,   -80,    58,    62,   -80,    56,    53,    94,   107,
      33,   -80,    91,     5,   -80,   -80,   108,    52,   111,   112,
      47,   -19,   120,    17,    33,   -80,    17,   132,    52,   114,
      33,    52,    52,    52,   -80,   -80,   115,   121,   212,   124,
      52,    52,   -80,   140,    52,    52,   -80,   -80,   -80,   -80,
      17,    67,   133,   149,    73,   156,    -4,    52,   -80,   -80,
      52,    52,    52,    52,    52,    52,    52,    89,   105,   -80,
     119,   134,   -80,   146,   151,    52,   -80,   148,   155,   -80,
     125,     1,   110,    60,    -4,   156,   163,    17,    17,   159,
     -80,   -80,    52,   177,    52,   -80,   -80,   -80,   -80,    52,
     192,   -80,   -80,   206,   157,   -80,   -80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   -80,   175,   -80,   -80,   -80,   -80,   -80,   147,
     135,   -80,   181,   162,    21,   -79,   -80,   -80,   -47,   -80,
     -80,    75,   -80,    38,   131
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      68,   102,    89,    74,     6,     7,    75,    89,    46,     1,
      47,    81,    14,    15,    84,    85,    86,    48,     4,    49,
      46,     3,    47,    97,    98,    50,     5,   100,   101,    48,
      95,    49,    92,    93,    94,    95,    13,    50,   127,   128,
      14,    15,    51,   110,   111,   112,   113,   114,   115,   116,
      46,    23,    47,    19,    51,    28,    59,    24,   123,    48,
      27,    49,    26,    60,    30,    29,    89,    50,    72,    37,
      61,    73,    31,    89,    77,   130,    62,    79,    37,    89,
      38,    39,   133,    40,    51,    63,   103,    64,    65,    66,
      41,    92,   106,    94,    95,    89,    90,    91,    92,    93,
      94,    95,    90,    91,    92,    93,    94,    95,   117,    14,
      15,    89,    33,    14,    15,    21,    89,    42,    90,    91,
      92,    93,    94,    95,   118,    89,    58,    43,    45,    70,
      71,    89,    82,    87,    90,    91,    92,    93,    94,    95,
      89,    76,   119,    94,    95,    80,    96,    88,    90,    91,
      92,    93,    94,    95,    89,    91,    92,    93,    94,    95,
     120,    99,    89,    90,    91,    92,    93,    94,    95,    89,
     104,   105,   121,   122,   125,   124,   136,    90,    91,    92,
      93,    94,    95,    89,   129,    20,   126,    44,    16,    78,
      32,    83,    90,    91,    92,    93,    94,    95,    89,   132,
     131,     0,     0,     0,     0,     0,    90,    91,    92,    93,
      94,    95,    89,     0,     0,   134,     0,     0,    89,     0,
       0,    90,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,   135,     0,     0,    90,    91,    92,    93,    94,
      95,    90,    91,    92,    93,    94,    95
};

static const yytype_int16 yycheck[] =
{
      47,    80,     6,    22,    16,    17,    25,     6,     3,    15,
       5,    58,     7,     8,    61,    62,    63,    12,     0,    14,
       3,    37,     5,    70,    71,    20,    20,    74,    75,    12,
      34,    14,    31,    32,    33,    34,    17,    20,   117,   118,
       7,     8,    37,    90,    91,    92,    93,    94,    95,    96,
       3,    13,     5,    21,    37,    27,     4,    37,   105,    12,
      37,    14,    22,    11,    23,    26,     6,    20,    21,    31,
      18,    50,    18,     6,    53,   122,    24,    56,    40,     6,
      22,    19,   129,    27,    37,    33,    19,    35,    36,    37,
      37,    31,    19,    33,    34,     6,    29,    30,    31,    32,
      33,    34,    29,    30,    31,    32,    33,    34,    19,     7,
       8,     6,    10,     7,     8,     9,     6,    23,    29,    30,
      31,    32,    33,    34,    19,     6,    18,    20,    37,    18,
      18,     6,    18,    18,    29,    30,    31,    32,    33,    34,
       6,    21,    23,    33,    34,    13,    22,    26,    29,    30,
      31,    32,    33,    34,     6,    30,    31,    32,    33,    34,
      26,    21,     6,    29,    30,    31,    32,    33,    34,     6,
      37,    22,    26,    22,    19,    27,    19,    29,    30,    31,
      32,    33,    34,     6,    25,    10,    23,    40,     7,    54,
      28,    60,    29,    30,    31,    32,    33,    34,     6,   124,
      23,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,     6,    -1,    -1,    23,    -1,    -1,     6,    -1,
      -1,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    29,    30,    31,    32,    33,
      34,    29,    30,    31,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    42,    37,     0,    20,    16,    17,    43,    44,
      45,    46,    47,    17,     7,     8,    53,    64,    65,    21,
      44,     9,    63,    64,    37,    54,    22,    37,    27,    26,
      23,    18,    54,    10,    49,    50,    52,    64,    22,    19,
      27,    37,    23,    20,    50,    37,     3,     5,    12,    14,
      20,    37,    48,    51,    53,    55,    56,    57,    18,     4,
      11,    18,    24,    33,    35,    36,    37,    58,    59,    60,
      18,    18,    21,    55,    22,    25,    21,    55,    51,    55,
      13,    59,    18,    65,    59,    59,    59,    18,    26,     6,
      29,    30,    31,    32,    33,    34,    22,    59,    59,    21,
      59,    59,    56,    19,    37,    22,    19,    59,    61,    62,
      59,    59,    59,    59,    59,    59,    59,    19,    19,    23,
      26,    26,    22,    59,    27,    19,    23,    56,    56,    25,
      59,    23,    62,    59,    23,    26,    19
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 108 "ijparser.y"
    {program = newProgram((yyvsp[(2) - (5)].string), (yyvsp[(4) - (5)].declaration));}
    break;

  case 3:
#line 110 "ijparser.y"
    {(yyval.declaration) = (yyvsp[(1) - (1)].declaration); }
    break;

  case 4:
#line 111 "ijparser.y"
    {(yyval.declaration) = NULL;}
    break;

  case 5:
#line 113 "ijparser.y"
    {(yyval.declaration) = connectDeclaration((yyvsp[(1) - (2)].declaration), (yyvsp[(2) - (2)].declaration));}
    break;

  case 6:
#line 114 "ijparser.y"
    {(yyval.declaration) = (yyvsp[(1) - (1)].declaration);}
    break;

  case 7:
#line 116 "ijparser.y"
    {(yyval.declaration) = (yyvsp[(1) - (1)].declaration);}
    break;

  case 8:
#line 117 "ijparser.y"
    {(yyval.declaration) = (yyvsp[(1) - (1)].declaration);}
    break;

  case 9:
#line 119 "ijparser.y"
    {(yyval.declaration) = newFieldDecl((yyvsp[(2) - (2)].var));}
    break;

  case 10:
#line 121 "ijparser.y"
    {(yyval.declaration) = declareMethod((yyvsp[(3) - (10)].type), (yyvsp[(4) - (10)].string), (yyvsp[(6) - (10)].var), (yyvsp[(9) - (10)].declaration));}
    break;

  case 11:
#line 123 "ijparser.y"
    {(yyval.declaration) = newMethod((yyvsp[(1) - (2)].var), (yyvsp[(2) - (2)].statement));}
    break;

  case 12:
#line 124 "ijparser.y"
    {(yyval.declaration) = newMethod((yyvsp[(1) - (1)].var), NULL);}
    break;

  case 13:
#line 125 "ijparser.y"
    {(yyval.declaration) = newMethod(NULL, (yyvsp[(1) - (1)].statement));}
    break;

  case 14:
#line 126 "ijparser.y"
    {(yyval.declaration) = newMethod(NULL, NULL);}
    break;

  case 15:
#line 128 "ijparser.y"
    {(yyval.var) = newVarDecl(StringArray, newIds((yyvsp[(4) - (4)].string)));}
    break;

  case 16:
#line 129 "ijparser.y"
    {(yyval.var) = (yyvsp[(1) - (1)].var);}
    break;

  case 17:
#line 130 "ijparser.y"
    {(yyval.var) = NULL;}
    break;

  case 18:
#line 132 "ijparser.y"
    {(yyval.var) = connectVarDecl((yyvsp[(1) - (3)].var), (yyvsp[(3) - (3)].var));}
    break;

  case 19:
#line 133 "ijparser.y"
    {(yyval.var) = (yyvsp[(1) - (1)].var);}
    break;

  case 20:
#line 135 "ijparser.y"
    {(yyval.var) = connectVarDecl((yyvsp[(1) - (2)].var), (yyvsp[(2) - (2)].var));}
    break;

  case 21:
#line 136 "ijparser.y"
    {(yyval.var) = (yyvsp[(1) - (1)].var);}
    break;

  case 22:
#line 138 "ijparser.y"
    {(yyval.var) = newVarDecl((yyvsp[(1) - (2)].type), newIds((yyvsp[(2) - (2)].string)));}
    break;

  case 23:
#line 140 "ijparser.y"
    {(yyval.var) = newVarDecl((yyvsp[(1) - (3)].type), (yyvsp[(2) - (3)].ids));}
    break;

  case 24:
#line 142 "ijparser.y"
    {(yyval.ids) = connectIds(newIds((yyvsp[(1) - (3)].string)), (yyvsp[(3) - (3)].ids));}
    break;

  case 25:
#line 143 "ijparser.y"
    {(yyval.ids) = newIds((yyvsp[(1) - (1)].string));}
    break;

  case 26:
#line 145 "ijparser.y"
    {(yyval.statement) = connectStatement((yyvsp[(1) - (2)].statement), (yyvsp[(2) - (2)].statement));}
    break;

  case 27:
#line 146 "ijparser.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 28:
#line 148 "ijparser.y"
    {(yyval.statement) = newElse((yyvsp[(1) - (3)].statement), (yyvsp[(3) - (3)].statement));}
    break;

  case 29:
#line 149 "ijparser.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 30:
#line 150 "ijparser.y"
    {(yyval.statement) = (yyvsp[(2) - (3)].statement);}
    break;

  case 31:
#line 151 "ijparser.y"
    {(yyval.statement) = NULL;}
    break;

  case 32:
#line 152 "ijparser.y"
    {(yyval.statement) = newWhile((yyvsp[(3) - (5)].exp), (yyvsp[(5) - (5)].statement));}
    break;

  case 33:
#line 153 "ijparser.y"
    {(yyval.statement) = newPrint((yyvsp[(3) - (5)].exp));}
    break;

  case 34:
#line 154 "ijparser.y"
    {(yyval.statement) = newStore((yyvsp[(1) - (4)].string), NULL, (yyvsp[(3) - (4)].exp));}
    break;

  case 35:
#line 155 "ijparser.y"
    {(yyval.statement) = newStore((yyvsp[(1) - (7)].string), (yyvsp[(3) - (7)].exp), (yyvsp[(6) - (7)].exp));}
    break;

  case 36:
#line 156 "ijparser.y"
    {(yyval.statement) = newReturn((yyvsp[(2) - (3)].exp));}
    break;

  case 37:
#line 158 "ijparser.y"
    {(yyval.statement) = newIf((yyvsp[(3) - (5)].exp), (yyvsp[(5) - (5)].statement));}
    break;

  case 38:
#line 160 "ijparser.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 39:
#line 161 "ijparser.y"
    {(yyval.exp) = NULL;}
    break;

  case 40:
#line 163 "ijparser.y"
    {(yyval.exp) = newAnonymousOper((yyvsp[(4) - (5)].exp), NULL, (yyvsp[(2) - (5)].type) == Int ? NewInt:NewBool);}
    break;

  case 41:
#line 164 "ijparser.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 42:
#line 166 "ijparser.y"
    {(yyval.exp) = newAnonymousOper((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), getOperType((yyvsp[(2) - (3)].string)));}
    break;

  case 43:
#line 167 "ijparser.y"
    {(yyval.exp) = newAnonymousOper((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), getOperType((yyvsp[(2) - (3)].string)));}
    break;

  case 44:
#line 168 "ijparser.y"
    {(yyval.exp) = newAnonymousOper((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), getOperType((yyvsp[(2) - (3)].string)));}
    break;

  case 45:
#line 169 "ijparser.y"
    {(yyval.exp) = newAnonymousOper((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), getOperType((yyvsp[(2) - (3)].string)));}
    break;

  case 46:
#line 170 "ijparser.y"
    {(yyval.exp) = newAnonymousOper((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), getOperType((yyvsp[(2) - (3)].string)));}
    break;

  case 47:
#line 171 "ijparser.y"
    {(yyval.exp) = newAnonymousOper((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), getOperType((yyvsp[(2) - (3)].string)));}
    break;

  case 48:
#line 172 "ijparser.y"
    {(yyval.exp) = newAnonymousOper((yyvsp[(1) - (4)].exp), (yyvsp[(3) - (4)].exp), LoadArray);}
    break;

  case 49:
#line 173 "ijparser.y"
    {(yyval.exp) = newId((yyvsp[(1) - (1)].string));}
    break;

  case 50:
#line 174 "ijparser.y"
    {(yyval.exp) = newLiteral((yyvsp[(1) - (1)].string), IntLit);}
    break;

  case 51:
#line 175 "ijparser.y"
    {(yyval.exp) = newLiteral((yyvsp[(1) - (1)].string), BoolLit);}
    break;

  case 52:
#line 176 "ijparser.y"
    {(yyval.exp) = newAnonymousOper((yyvsp[(1) - (2)].exp), NULL, Length);}
    break;

  case 53:
#line 177 "ijparser.y"
    {(yyval.exp) = newAnonymousOper((yyvsp[(2) - (2)].exp), NULL, !strcmp((yyvsp[(1) - (2)].string), "+") ? Plus : Minus);}
    break;

  case 54:
#line 178 "ijparser.y"
    {(yyval.exp) = newAnonymousOper((yyvsp[(2) - (2)].exp), NULL, Not);}
    break;

  case 55:
#line 179 "ijparser.y"
    {(yyval.exp) = newAnonymousOper(newId((yyvsp[(3) - (7)].string)), (yyvsp[(5) - (7)].exp), Parse);}
    break;

  case 56:
#line 180 "ijparser.y"
    {(yyval.exp) = newOper((yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].exp), Call);}
    break;

  case 57:
#line 181 "ijparser.y"
    {(yyval.exp) = (yyvsp[(2) - (3)].exp);}
    break;

  case 58:
#line 183 "ijparser.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 59:
#line 184 "ijparser.y"
    {(yyval.exp) = NULL;}
    break;

  case 60:
#line 186 "ijparser.y"
    {(yyval.exp) = connectExp((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 61:
#line 187 "ijparser.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 62:
#line 189 "ijparser.y"
    {(yyval.type) = Void;}
    break;

  case 63:
#line 190 "ijparser.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 64:
#line 192 "ijparser.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 65:
#line 193 "ijparser.y"
    {(yyval.type) = (yyvsp[(1) - (3)].type) == Int ? IntArray:BoolArray;}
    break;

  case 66:
#line 195 "ijparser.y"
    {(yyval.type) = Int;}
    break;

  case 67:
#line 196 "ijparser.y"
    {(yyval.type) = Bool;}
    break;


/* Line 1267 of yacc.c.  */
#line 1874 "y.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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


#line 198 "ijparser.y"

int main(int argc, char **argv) {
	int tree = 0, table = 0; 
	argc--;
	argv++;

	while(argc--) {
		if(!strcmp(*argv, "-t"))
			tree = 1;
		else if(!strcmp(*argv, "-s"))
			table = 1;
		
		*argv++;
	}
	
	yyparse();

	if (!hasErrors){
		//checkDuplicateDeclaration();
		//checkTypeIssues();

		if(tree){
			printProgram(program);
		}
		if(table){
			printProgramSymbols(program);
		}
		


		//free memory
		cleanProgram(program);
	}

	return 0;
}

int yyerror (char *s) { 
	hasErrors = 1;
	printf ("Line %d, col %d: %s: %s\n", linhaAux, colunaAux, s, yytext); 
}

