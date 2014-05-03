/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    OP1 = 284,
    OP2 = 285,
    OP3 = 286,
    OP4 = 287,
    INTLIT = 288,
    BOOLLIT = 289,
    ID = 290,
    EXPR = 291,
    IFX = 292,
    OPERSX = 293
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
#define OP1 284
#define OP2 285
#define OP3 286
#define OP4 287
#define INTLIT 288
#define BOOLLIT 289
#define ID 290
#define EXPR 291
#define IFX 292
#define OPERSX 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 88 "ijparser.y" /* yacc.c:1909  */

	Program* program;
	Declaration* declaration;
	Statement* statement;
	VarDecl* var;
    Ids* ids;
    Exp* exp;
    Type type;
    ExpType expType;

	char* string;

#line 143 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
