/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 95 "ijparser.y"
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
/* Line 1529 of yacc.c.  */
#line 142 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

