/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

/* Line 2068 of yacc.c  */
#line 39 "sa.y"

	Node *node;



/* Line 2068 of yacc.c  */
#line 162 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


