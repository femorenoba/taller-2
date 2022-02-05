
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
     PARENTESISA = 258,
     PARENTESISB = 259,
     COMENTARIO = 260,
     ESPACIO = 261,
     MIENTRAS = 262,
     CONDICION = 263,
     CORCHETEA = 264,
     CORCHETEB = 265,
     LLAVESA = 266,
     LLAVESB = 267,
     SALIDA = 268,
     ASIGNACION = 269,
     VSALIDA = 270,
     MSALIDA = 271,
     SIN = 272,
     COS = 273,
     TAN = 274,
     COT = 275,
     SEC = 276,
     CSC = 277,
     GETROOT = 278,
     GETEXP = 279,
     GETLOG = 280,
     PA = 281,
     PB = 282,
     OR = 283,
     BSALIDA = 284,
     ID = 285,
     NUMERO_ENTERO = 286,
     NUMERO_FLOTANTE = 287,
     LOGICA = 288
   };
#endif
/* Tokens.  */
#define PARENTESISA 258
#define PARENTESISB 259
#define COMENTARIO 260
#define ESPACIO 261
#define MIENTRAS 262
#define CONDICION 263
#define CORCHETEA 264
#define CORCHETEB 265
#define LLAVESA 266
#define LLAVESB 267
#define SALIDA 268
#define ASIGNACION 269
#define VSALIDA 270
#define MSALIDA 271
#define SIN 272
#define COS 273
#define TAN 274
#define COT 275
#define SEC 276
#define CSC 277
#define GETROOT 278
#define GETEXP 279
#define GETLOG 280
#define PA 281
#define PB 282
#define OR 283
#define BSALIDA 284
#define ID 285
#define NUMERO_ENTERO 286
#define NUMERO_FLOTANTE 287
#define LOGICA 288




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 110 "Rachas.y"

    char* str;
    int numberI;
    float numberF;
    struct VectorEle* vec;
    struct MatrizFila* matx;
    struct NodoVector* nodx;
    struct MatrizProf* mProf;



/* Line 1676 of yacc.c  */
#line 130 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


