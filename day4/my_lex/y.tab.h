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
     LPAREN = 258,
     RPAREN = 259,
     LBRACE = 260,
     RBRACE = 261,
     COMMA = 262,
     BIT_AND = 263,
     BIT_OR = 264,
     EQ = 265,
     ASSIGN = 266,
     NE = 267,
     GT = 268,
     GE = 269,
     LE = 270,
     LT = 271,
     SEMICOLON = 272,
     COLON = 273,
     ADD = 274,
     SUB = 275,
     MUL = 276,
     DIV = 277,
     MOD = 278,
     ADD_ASSIGN = 279,
     SUB_ASSIGN = 280,
     MUL_ASSIGN = 281,
     DIV_ASSIGN = 282,
     MOD_ASSIGN = 283,
     INCREMENT = 284,
     DECREMENT = 285,
     NOT = 286,
     DOT = 287,
     AND = 288,
     OR = 289,
     CR = 290,
     SPACE = 291,
     ENDOFFILE = 292,
     INT_LITERAL = 293,
     DOUBLE_LITERAL = 294,
     IDENTIFIER = 295,
     IF = 296,
     ELSE = 297,
     ELSIF = 298,
     WHILE = 299,
     FOR = 300,
     RETURN = 301,
     BREAK = 302,
     CONTINUE = 303,
     TRUE = 304,
     FALSE = 305,
     BOOLEAN_T = 306,
     INT_T = 307,
     DOUBLE_T = 308,
     STRING_T = 309
   };
#endif
/* Tokens.  */
#define LPAREN 258
#define RPAREN 259
#define LBRACE 260
#define RBRACE 261
#define COMMA 262
#define BIT_AND 263
#define BIT_OR 264
#define EQ 265
#define ASSIGN 266
#define NE 267
#define GT 268
#define GE 269
#define LE 270
#define LT 271
#define SEMICOLON 272
#define COLON 273
#define ADD 274
#define SUB 275
#define MUL 276
#define DIV 277
#define MOD 278
#define ADD_ASSIGN 279
#define SUB_ASSIGN 280
#define MUL_ASSIGN 281
#define DIV_ASSIGN 282
#define MOD_ASSIGN 283
#define INCREMENT 284
#define DECREMENT 285
#define NOT 286
#define DOT 287
#define AND 288
#define OR 289
#define CR 290
#define SPACE 291
#define ENDOFFILE 292
#define INT_LITERAL 293
#define DOUBLE_LITERAL 294
#define IDENTIFIER 295
#define IF 296
#define ELSE 297
#define ELSIF 298
#define WHILE 299
#define FOR 300
#define RETURN 301
#define BREAK 302
#define CONTINUE 303
#define TRUE 304
#define FALSE 305
#define BOOLEAN_T 306
#define INT_T 307
#define DOUBLE_T 308
#define STRING_T 309




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 7 "grammer.y"
{
    int iv;
    double dv;
    char *name;
}
/* Line 1529 of yacc.c.  */
#line 163 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

