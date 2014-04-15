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
     BOOLIT = 264,
     VOID = 265,
     STRING = 266,
     NEW = 267,
     IF = 268,
     ELSE = 269,
     WHILE = 270,
     CLASS = 271,
     PUBLIC = 272,
     STATIC = 273,
     OCURV = 274,
     CCURV = 275,
     OBRACE = 276,
     CBRACE = 277,
     OSQUARE = 278,
     CSQUARE = 279,
     NOT = 280,
     ASSIGN = 281,
     SEMIC = 282,
     COMMA = 283,
     RESERVED = 284,
     OP1 = 285,
     OP2 = 286,
     OP3 = 287,
     OP4 = 288,
     INTLIT = 289,
     BOOLLIT = 290,
     ID = 291,
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
#define BOOLIT 264
#define VOID 265
#define STRING 266
#define NEW 267
#define IF 268
#define ELSE 269
#define WHILE 270
#define CLASS 271
#define PUBLIC 272
#define STATIC 273
#define OCURV 274
#define CCURV 275
#define OBRACE 276
#define CBRACE 277
#define OSQUARE 278
#define CSQUARE 279
#define NOT 280
#define ASSIGN 281
#define SEMIC 282
#define COMMA 283
#define RESERVED 284
#define OP1 285
#define OP2 286
#define OP3 287
#define OP4 288
#define INTLIT 289
#define BOOLLIT 290
#define ID 291
#define IFX 292
#define OPERSX 293




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 58 "ijparser.y"
{
	char* string;
	int number;
}
/* Line 1529 of yacc.c.  */
#line 130 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

