
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.4.1"

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

/* Line 189 of yacc.c  */
#line 1 "Rachas.y"
  
void yyerror (char *s);
int yylex();
#include <stdio.h>     /* C declarations used in actions */
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
extern FILE* yyin;

// Aqui es para el codigo necesario para almacenar

// Comando Ahorrador:   
// flex Rachas.l && bison -dy Rachas.y && gcc lex.yy.c  y.tab.c -o a && ./a.exe pru.rach

typedef struct Number{
    struct Number* next;
    float num;
    char* nombre;
}Number;

typedef struct VectorEle{
    struct VectorEle* next;
    float num;
} VectorEle;

typedef struct VectorIni{
    struct VectorIni* next;
    struct VectorEle* nextEle;
    char* nombre;
} VectorIni;

typedef struct MatrizFila{
    struct VectorEle* nextEle;
    int num;
    struct MatrizFila* next;
} MatrizFila;

typedef struct MatrizIni{
    struct MatrizFila* elements;
    char* nombre;
    struct MatrizIni* next;
} MatrizIni; 

typedef struct MatrizProfIni{
    struct MatrizProf* matrizProfeleme;
    char* nombre;
    struct MatrizProfIni* next;
} MatrizProfIni; 

typedef struct MatrizProf{              //Bloque i
    struct NodoVector* nextEleNodoVect; //Apuntamos al primer NodoVector [j]
    int num;                            //ID
    struct MatrizProf* nextMatrizProf;  //Apuntamos al segundo elemento de la MatrizProf [i]
} MatrizProf;

typedef struct MatrizProfNombre{
    struct MatrizProf* matrizProf;
    char* nombre;
    struct MatrizProfNombre* nextMatrizProf;
} MatrizProfNombre;

typedef struct NodoVector{              //Matrices n_ij
    struct VectorEle* nextEleVector;    //Apuntamos al primer elemento del VectorEle [k]
    int num;                            //ID
    struct NodoVector* nextNodoVector;  //Apuntamos al segundo elemento del NodoVector [j]
} NodoVector;

// Declaracion de funciones
Number* crearNumero(char* nombre, float valor);
char* agregarNumero(Number* head, char* nombre, float valor);
float getNumber(Number* head, char* nombre);
VectorIni* crearVectorIni(char* nombre, VectorEle* elementos);
char* nombrarVector(VectorIni* head, char* nombre, VectorEle* elementos);
VectorEle* crearVectorEle(float valor);
VectorEle* agregarVectorEle(VectorEle* nodo,VectorEle* nuevo);
void salidaVector(char* nombre, VectorIni* head);
float sec(float num);
float csc(float num);
float cot(float num);
float getRoot(float indice, float radicando);
float getExp(float base, float exp);
float getLog(float argumento, float base);
float getSumatoria(float datos[], int size);
MatrizFila* crearFila(int numero, VectorEle* elementos);
MatrizFila* agregarFila(MatrizFila* fila, VectorEle* elementos);
MatrizIni* crearMatrizIni(char* nombre, MatrizFila* fila);
char* nombrarMatriz(char* nombre, MatrizFila* fila, MatrizIni* nodoIni );
void salidaMatriz(char* nombre, MatrizIni* nodoIni);
MatrizProf* crearMatrizProf(int numero, NodoVector* nextNodoVect);
MatrizProf* agregarProf(MatrizProf* matrizProfOriginal, NodoVector* nextNodoVect);
MatrizProfIni* crearMatrizProfIni(char* nombre, MatrizProf* matrizProf);
bool crearPrimeroMatrizProd(char* name, MatrizProf* matrizProf);
char* nombrarMatrizProf(char* name, MatrizProf* prof, MatrizProfIni* nodoIni);
NodoVector* crearNodoVector(int numero, VectorEle* nextEVector);
NodoVector* agregarNodoVector(NodoVector* nodoVectorOriginal, VectorEle* nextEVector);
void salidaVectorEle(VectorEle* vector);
void salidaNodoVector(NodoVector* nodoVector);
void salidaMatrizProf(char* nombre);

// Inicializacion atributos
Number* iniNode = NULL;
VectorIni* iniNodeVector = NULL;
MatrizIni* iniNodeMatriz = NULL;
MatrizProfIni* iniMatrizProf = NULL;



/* Line 189 of yacc.c  */
#line 183 "y.tab.c"

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

/* Line 214 of yacc.c  */
#line 110 "Rachas.y"

    char* str;
    int numberI;
    float numberF;
    struct VectorEle* vec;
    struct MatrizFila* matx;
    struct NodoVector* nodx;
    struct MatrizProf* mProf;



/* Line 214 of yacc.c  */
#line 297 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 309 "y.tab.c"

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
# if YYENABLE_NLS
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   294

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNRULES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    36,    34,     2,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     9,    13,    16,    20,    24,    27,
      33,    40,    46,    52,    59,    65,    72,    78,    85,    87,
      90,    94,    98,   102,   106,   108,   110,   112,   114,   118,
     124,   130,   136,   138,   141,   146,   151,   156,   161,   166,
     171,   177,   183,   189,   193,   198,   202,   207,   211
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    40,    38,    -1,    43,    38,    -1,    40,
      43,    38,    -1,    41,    38,    -1,    41,    38,    40,    -1,
      40,    45,    38,    -1,    45,    38,    -1,    13,     3,    41,
       4,    38,    -1,    40,    13,     3,    41,     4,    38,    -1,
      13,     3,    30,     4,    38,    -1,    15,     3,    30,     4,
      38,    -1,    40,    15,     3,    30,     4,    38,    -1,    16,
       3,    30,     4,    38,    -1,    40,    16,     3,    30,     4,
      38,    -1,    29,     3,    30,     4,    38,    -1,    40,    29,
       3,    30,     4,    38,    -1,    42,    -1,    35,    42,    -1,
      41,    34,    41,    -1,    41,    35,    41,    -1,    41,    37,
      41,    -1,    41,    36,    41,    -1,    45,    -1,    31,    -1,
      32,    -1,    30,    -1,    30,    14,    41,    -1,    30,    14,
       9,    44,    10,    -1,    30,    14,    11,    46,    12,    -1,
      30,    14,    11,    48,    12,    -1,    42,    -1,    44,    42,
      -1,    21,     3,    41,     4,    -1,    22,     3,    41,     4,
      -1,    20,     3,    41,     4,    -1,    17,     3,    41,     4,
      -1,    18,     3,    41,     4,    -1,    19,     3,    41,     4,
      -1,    23,     3,    41,    41,     4,    -1,    24,     3,    41,
      41,     4,    -1,    25,     3,    41,    41,     4,    -1,     9,
      44,    10,    -1,    46,     9,    44,    10,    -1,    28,    44,
      28,    -1,    47,    28,    44,    28,    -1,     3,    47,     4,
      -1,    48,     3,    47,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   170,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   188,   189,
     190,   191,   192,   193,   194,   197,   198,   199,   202,   203,
     204,   205,   208,   209,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   223,   224,   227,   228,   231,   232
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PARENTESISA", "PARENTESISB",
  "COMENTARIO", "ESPACIO", "MIENTRAS", "CONDICION", "CORCHETEA",
  "CORCHETEB", "LLAVESA", "LLAVESB", "SALIDA", "ASIGNACION", "VSALIDA",
  "MSALIDA", "SIN", "COS", "TAN", "COT", "SEC", "CSC", "GETROOT", "GETEXP",
  "GETLOG", "PA", "PB", "OR", "BSALIDA", "ID", "NUMERO_ENTERO",
  "NUMERO_FLOTANTE", "LOGICA", "'+'", "'-'", "'*'", "'/'", "';'",
  "$accept", "line", "expr", "term", "indent", "vector", "functs",
  "matriz", "vectorN", "bloque", 0
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
     285,   286,   287,   288,    43,    45,    42,    47,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    41,    41,
      41,    41,    41,    41,    41,    42,    42,    42,    43,    43,
      43,    43,    44,    44,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    46,    46,    47,    47,    48,    48
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     3,     2,     3,     3,     2,     5,
       6,     5,     5,     6,     5,     6,     5,     6,     1,     2,
       3,     3,     3,     3,     1,     1,     1,     1,     3,     5,
       5,     5,     1,     2,     4,     4,     4,     4,     4,     4,
       5,     5,     5,     3,     4,     3,     4,     3,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,    25,    26,     0,     0,     0,
      18,     0,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    19,     1,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       0,     0,     5,     3,     8,    27,     0,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28,     0,     0,     0,     0,     4,     7,    20,
      21,    23,    22,     6,     0,     0,     0,     0,    37,    38,
      39,    36,    34,    35,     0,     0,     0,     0,     0,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       9,    12,    14,    18,    40,    41,    42,    16,    29,    33,
       0,     0,     0,     0,    30,     0,    31,     0,     0,     0,
       0,     0,    47,     0,    43,     0,     0,    10,    13,    15,
      17,    45,     0,    44,    48,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    18,    19,    20,    21,   100,    57,   103,   121,   104
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -23
static const yytype_int16 yypact[] =
{
     196,    12,    17,    29,    51,    55,    56,    62,    63,    70,
      72,    81,    89,    90,    99,   -23,   -23,    39,    18,    92,
     -23,    66,    77,   236,   111,   116,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   125,   151,   -23,   -23,   -23,
     117,   153,   156,   163,    99,   -23,   139,   160,   255,   255,
     255,   255,   196,   -23,   -23,   115,    26,   -23,   195,   199,
      45,    53,    60,    64,    74,    87,   215,   215,   215,   203,
      39,    14,   207,   255,   170,   178,   192,   -23,   -23,   -12,
     -12,   -23,   -23,   172,   185,   186,   191,   210,   -23,   -23,
     -23,   -23,   -23,   -23,   255,    98,   103,   108,   224,   -23,
     121,   202,    39,     7,    10,   113,   259,   260,   265,   -23,
     -23,   -23,   -23,   266,   -23,   -23,   -23,   -23,   -23,   -23,
      39,    46,   148,    39,   -23,   202,   -23,   227,   243,   244,
     245,   133,   -23,    39,   -23,   174,    48,   -23,   -23,   -23,
     -23,   -23,   261,   -23,   -23,   -23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -23,   232,   -22,   -17,   -16,    34,     3,   -23,   169,   -23
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -20
static const yytype_int16 yytable[] =
{
      38,    56,    46,    22,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   125,    72,    23,   123,   101,    39,   124,
      24,    47,   126,   102,    50,    51,    79,    80,    81,    82,
      85,    40,    25,    41,    42,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    95,    96,    97,    43,    44,    88,
     132,   105,   144,    99,    26,    22,    45,    89,    27,    28,
      48,    49,    50,    51,    90,    29,    30,    46,    91,    37,
      15,    16,    80,    31,   133,    32,   133,   113,    92,    48,
      49,    50,    51,   119,    33,    99,    47,    48,    49,    50,
      51,    93,    34,    35,    48,    49,    50,    51,    48,    49,
      50,    51,   114,    99,    53,   119,    99,   115,    48,    49,
      50,    51,   116,    36,   119,    54,    99,   127,   119,    84,
      73,    48,    49,    50,    51,   119,    48,    49,    50,    51,
      52,   118,    48,    49,    50,    51,   122,    48,    49,    50,
      51,    58,    48,    49,    50,    51,    59,    48,    49,    50,
      51,    37,    15,    16,   131,    69,    74,   135,   134,    75,
      70,   141,    71,    37,    15,    16,    76,   142,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    77,    37,    15,
      16,    37,    15,    16,   143,    40,    17,    41,    42,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    78,    86,
     106,    43,    44,    87,    37,    15,    16,    98,   107,     1,
      45,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,   108,   109,   110,    13,    14,    15,    16,   111,
     120,    17,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    48,    49,    50,    51,    37,    15,    16,   112,    48,
      94,    50,    51,     4,     5,     6,     7,     8,     9,    10,
      11,    12,   117,   128,   129,   137,    55,    15,    16,   130,
     -19,    17,     4,     5,     6,     7,     8,     9,    10,    11,
      12,   138,   139,   140,    83,    37,    15,    16,     0,   145,
      17,    37,    15,    16,   136
};

static const yytype_int16 yycheck[] =
{
      17,    23,    18,     0,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     3,    36,     3,     9,     3,     0,    12,
       3,    18,    12,     9,    36,    37,    48,    49,    50,    51,
       4,    13,     3,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    66,    67,    68,    29,    30,     4,
       4,    73,     4,    70,     3,    52,    38,     4,     3,     3,
      34,    35,    36,    37,     4,     3,     3,    83,     4,    30,
      31,    32,    94,     3,    28,     3,    28,    94,     4,    34,
      35,    36,    37,   100,     3,   102,    83,    34,    35,    36,
      37,     4,     3,     3,    34,    35,    36,    37,    34,    35,
      36,    37,     4,   120,    38,   122,   123,     4,    34,    35,
      36,    37,     4,    14,   131,    38,   133,     4,   135,     4,
       3,    34,    35,    36,    37,   142,    34,    35,    36,    37,
      38,    10,    34,    35,    36,    37,   102,    34,    35,    36,
      37,    30,    34,    35,    36,    37,    30,    34,    35,    36,
      37,    30,    31,    32,   120,    30,     3,   123,    10,     3,
       9,    28,    11,    30,    31,    32,     3,   133,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    38,    30,    31,
      32,    30,    31,    32,    10,    13,    35,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    38,     4,
      30,    29,    30,     4,    30,    31,    32,     4,    30,    13,
      38,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    30,    38,    38,    29,    30,    31,    32,    38,
      28,    35,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    34,    35,    36,    37,    30,    31,    32,    38,    34,
      35,    36,    37,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    38,     4,     4,    38,    30,    31,    32,     4,
       4,    35,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    38,    38,    38,    52,    30,    31,    32,    -1,    28,
      35,    30,    31,    32,   125
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    29,    30,    31,    32,    35,    40,    41,
      42,    43,    45,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,    14,    30,    42,     0,
      13,    15,    16,    29,    30,    38,    43,    45,    34,    35,
      36,    37,    38,    38,    38,    30,    41,    45,    30,    30,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    30,
       9,    11,    41,     3,     3,     3,     3,    38,    38,    41,
      41,    41,    41,    40,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,    35,    41,    41,    41,     4,    42,
      44,     3,     9,    46,    48,    41,    30,    30,    30,    38,
      38,    38,    38,    42,     4,     4,     4,    38,    10,    42,
      28,    47,    44,     9,    12,     3,    12,     4,     4,     4,
       4,    44,     4,    28,    10,    44,    47,    38,    38,    38,
      38,    28,    44,    10,     4,    28
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
# if YYLTYPE_IS_TRIVIAL
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

/* Line 1455 of yacc.c  */
#line 170 "Rachas.y"
    {;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 171 "Rachas.y"
    {;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 172 "Rachas.y"
    {;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 173 "Rachas.y"
    {;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 174 "Rachas.y"
    {;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 175 "Rachas.y"
    {;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 176 "Rachas.y"
    {;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 177 "Rachas.y"
    {printf("%f \n",(yyvsp[(3) - (5)].numberF));}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 178 "Rachas.y"
    {printf("%f \n",(yyvsp[(4) - (6)].numberF));}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 179 "Rachas.y"
    {printf("%s : %f", (yyvsp[(3) - (5)].str), getNumber(iniNode,(yyvsp[(3) - (5)].str)));}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 180 "Rachas.y"
    {salidaVector((yyvsp[(3) - (5)].str),iniNodeVector);}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 181 "Rachas.y"
    {salidaVector((yyvsp[(4) - (6)].str),iniNodeVector);}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 182 "Rachas.y"
    {salidaMatriz((yyvsp[(3) - (5)].str),iniNodeMatriz);}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 183 "Rachas.y"
    {salidaMatriz((yyvsp[(4) - (6)].str),iniNodeMatriz);}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 184 "Rachas.y"
    {salidaMatrizProf((yyvsp[(3) - (5)].str));}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 185 "Rachas.y"
    {salidaMatrizProf((yyvsp[(4) - (6)].str));}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 188 "Rachas.y"
    {(yyval.numberF) = (yyvsp[(1) - (1)].numberF);}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 189 "Rachas.y"
    {(yyval.numberF) = -(yyvsp[(2) - (2)].numberF);}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 190 "Rachas.y"
    {(yyval.numberF) = (yyvsp[(1) - (3)].numberF) + (yyvsp[(3) - (3)].numberF);}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 191 "Rachas.y"
    {(yyval.numberF) = (yyvsp[(1) - (3)].numberF) - (yyvsp[(3) - (3)].numberF);}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 192 "Rachas.y"
    {(yyval.numberF) = (yyvsp[(1) - (3)].numberF) / (yyvsp[(3) - (3)].numberF);}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 193 "Rachas.y"
    {(yyval.numberF) = (yyvsp[(1) - (3)].numberF) * (yyvsp[(3) - (3)].numberF);}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 194 "Rachas.y"
    {;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 197 "Rachas.y"
    {(yyval.numberF) = (float)(yyvsp[(1) - (1)].numberI);}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 198 "Rachas.y"
    {(yyval.numberF) = (yyvsp[(1) - (1)].numberF);}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 199 "Rachas.y"
    {(yyval.numberF) = getNumber(iniNode,(yyvsp[(1) - (1)].str));}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 202 "Rachas.y"
    {agregarNumero(iniNode,(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].numberF));}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 203 "Rachas.y"
    {nombrarVector(iniNodeVector, (yyvsp[(1) - (5)].str), (yyvsp[(4) - (5)].vec));}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 204 "Rachas.y"
    {nombrarMatriz((yyvsp[(1) - (5)].str), (yyvsp[(4) - (5)].matx), iniNodeMatriz);}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 205 "Rachas.y"
    {nombrarMatrizProf((yyvsp[(1) - (5)].str), (yyvsp[(4) - (5)].mProf), iniMatrizProf);}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 208 "Rachas.y"
    {(yyval.vec) = crearVectorEle((yyvsp[(1) - (1)].numberF));}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 209 "Rachas.y"
    {(yyval.vec) = agregarVectorEle((yyvsp[(1) - (2)].vec),crearVectorEle((yyvsp[(2) - (2)].numberF)));}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 212 "Rachas.y"
    {(yyval.numberF) = sec((yyvsp[(3) - (4)].numberF));}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 213 "Rachas.y"
    {(yyval.numberF) = csc((yyvsp[(3) - (4)].numberF));}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 214 "Rachas.y"
    {(yyval.numberF) = cot((yyvsp[(3) - (4)].numberF));}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 215 "Rachas.y"
    {(yyval.numberF) = sin((yyvsp[(3) - (4)].numberF));}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 216 "Rachas.y"
    {(yyval.numberF) = cos((yyvsp[(3) - (4)].numberF));}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 217 "Rachas.y"
    {(yyval.numberF) = tan((yyvsp[(3) - (4)].numberF));}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 218 "Rachas.y"
    {(yyval.numberF) = getRoot((yyvsp[(3) - (5)].numberF),(yyvsp[(4) - (5)].numberF));}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 219 "Rachas.y"
    {(yyval.numberF) = getExp((yyvsp[(3) - (5)].numberF),(yyvsp[(4) - (5)].numberF));}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 220 "Rachas.y"
    {(yyval.numberF) = getLog((yyvsp[(3) - (5)].numberF),(yyvsp[(4) - (5)].numberF));}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 223 "Rachas.y"
    {(yyval.matx) = crearFila(0, (yyvsp[(2) - (3)].vec));}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 224 "Rachas.y"
    {(yyval.matx) = agregarFila((yyvsp[(1) - (4)].matx), (yyvsp[(3) - (4)].vec));}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 227 "Rachas.y"
    {(yyval.nodx) = crearNodoVector(0, (yyvsp[(2) - (3)].vec));}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 228 "Rachas.y"
    {(yyval.nodx) = agregarNodoVector((yyvsp[(1) - (4)].nodx), (yyvsp[(3) - (4)].vec));}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 231 "Rachas.y"
    {(yyval.mProf) = crearMatrizProf(0, (yyvsp[(2) - (3)].nodx));}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 232 "Rachas.y"
    {(yyval.mProf) = agregarProf((yyvsp[(1) - (4)].mProf), (yyvsp[(3) - (4)].nodx));}
    break;



/* Line 1455 of yacc.c  */
#line 1964 "y.tab.c"
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



/* Line 1675 of yacc.c  */
#line 241 "Rachas.y"


///////////////////Estructuras


// Se supone que crea un nuevo numero
Number* crearNumero(char* nombre, float valor){
    Number* number;
    number = (Number*)malloc(sizeof(Number));
    number->num = valor;
    number->nombre = nombre;
    number->next = NULL;
    return number;
}

//Se agrega el numero que se creo a la lista encadenada o se actualiza el valor
char* agregarNumero(Number* head, char* nombre, float valor){
    while(head->next != NULL){
        if(strcmp(head->nombre, nombre) == 0){
            head->num = valor;
            return head->nombre;
        }
        head = head->next;
    }
    if(strcmp(head->nombre, nombre)==0){
        head->num=valor;
        return head->nombre;
    }
    Number* number = crearNumero(nombre, valor);
    head->next=number;
    return nombre;
}

// Recuperar el numero
float getNumber(Number* head, char* nombre){
    while(head->next != NULL){
        if(strcmp(head->nombre, nombre) == 0){
            return(head->num);
        }
        head = head->next;
    }
    if(strcmp(head->nombre, nombre) == 0){
        return(head->num);
    }
    return 0.0000001;
}

// Vectores

VectorIni* crearVectorIni(char* nombre, VectorEle* elementos){
    VectorIni* vectorIni;
    vectorIni = (VectorIni*)malloc(sizeof(VectorIni));
    vectorIni->next = NULL;
    vectorIni->nombre = nombre;
    vectorIni->nextEle = elementos;
    return vectorIni;
}

char* nombrarVector(VectorIni* head, char* nombre, VectorEle* elementos){
    while(head->next != NULL){
        if(strcmp(head->nombre , nombre) == 0){
            head->nextEle = elementos;
            return head->nombre; 
        }
        head = head->next;
    }
    if(strcmp(head->nombre , nombre) == 0){
        head->nextEle = elementos;
        return head->nombre; 
    }
    VectorIni* vectorIni = crearVectorIni(nombre, elementos);
    head->next = vectorIni;
    return vectorIni->nombre;
}

VectorEle* crearVectorEle(float valor){
    VectorEle* vectorEle;
    vectorEle = (VectorEle*)malloc(sizeof(vectorEle));
    vectorEle->num = valor;
    vectorEle->next = NULL;
    return vectorEle;
}

VectorEle* agregarVectorEle(VectorEle* nodo, VectorEle* nuevo){
    VectorEle* ini = nodo;
    while(nodo->next != NULL){
        nodo = nodo->next;
    }
    nodo->next = nuevo;
    return ini;
}

void salidaVector(char* nombre, VectorIni* head){
    while(head->next != NULL){
        if(strcmp(head->nombre, nombre) == 0){
            break;
        }
        head = head->next;
    }
    if(strcmp(head->nombre, nombre) != 0){
        printf("Vector not found\n");
        return;
    }else{
        VectorEle* vectorEle = head->nextEle;
        printf("[");
        while(vectorEle != NULL){
            printf(" %f ",vectorEle->num);
            vectorEle = vectorEle->next;
        }
        printf("]\n");
    }
}

// Matrices

MatrizFila* crearFila(int numero, VectorEle* elementos){
    MatrizFila* matrizFila;
    matrizFila = (MatrizFila*)malloc(sizeof(matrizFila));
    matrizFila->num = numero;
    matrizFila->nextEle = elementos;
    matrizFila->next = NULL;
    return matrizFila;
}

MatrizFila* agregarFila(MatrizFila* fila, VectorEle* elementos){
    MatrizFila* filaOrigi = fila;
    while(fila->next !=  NULL){
        fila = fila->next;
    }
    int num = fila->num;
    MatrizFila* nuevaFila = crearFila(num+1, elementos);
    fila->next = nuevaFila;
    return filaOrigi;
}

MatrizIni* crearMatrizIni(char* nombre, MatrizFila* fila ){
    MatrizIni* matrizIni;
    matrizIni = (MatrizIni*)malloc(sizeof(matrizIni));
    matrizIni->elements = fila;
    matrizIni->nombre = nombre;
    matrizIni->next = NULL;
    return matrizIni;
}

void imprimirVector(MatrizFila* fila){
    printf("Vetores que estan entrando\n");
    while(fila != NULL){
        VectorEle* vect = fila->nextEle;
        printf("[");
        while(vect != NULL){
            printf(" %f ",vect->num);
            vect = vect->next;
        }
        printf("]\n");
        fila=fila->next;   
    }
}

bool crearPrimero(char* name, MatrizFila* fila){
    if(iniNodeMatriz == NULL){
        MatrizIni* matrizIni;
        matrizIni = (MatrizIni*)malloc(sizeof(matrizIni));
        matrizIni->elements = fila;
        matrizIni->nombre = name;
        matrizIni->next = NULL;
        iniNodeMatriz = matrizIni;
        return true;    
    }else{
        return false;
    }
}

char* nombrarMatriz(char* name, MatrizFila* fila, MatrizIni* nodoIni){
    if(crearPrimero(name, fila) == true){
        return name;
    }else{
        while(nodoIni->next != NULL){
            if(strcmp(nodoIni->nombre, name) == 0){
                nodoIni->elements = fila;
                return name;
            }
            nodoIni = nodoIni->next;
        }
        if(strcmp(nodoIni->nombre, name) == 0){
            nodoIni->elements = fila;
            return name;
        }
        MatrizIni* nuevoNodo = crearMatrizIni(name, fila);
        nodoIni->next = nuevoNodo;
        return nuevoNodo->nombre;
    } 
}

void salidaMatriz(char* nombre, MatrizIni* nodoIni){
    nodoIni = iniNodeMatriz;
    printf("\n Matriz  %s \n", nombre);
    while(nodoIni->next != NULL){
        if(strcmp(nodoIni->nombre, nombre) ==0){
            break;
        }
        nodoIni = nodoIni->next;
    }
    if(strcmp(nodoIni->nombre, nombre) != 0){
        printf("No matrix found");
        return;
    }else{
        MatrizFila* fila = nodoIni->elements;
        printf("[");
        while(fila != NULL){
            VectorEle* elementos = fila->nextEle;
            while(elementos != NULL){
                printf(" %f ",elementos->num);
                elementos = elementos->next;
            }
            printf(", \n");
            fila = fila->next;
        }
        printf("] \n");
    }
}


// Matrices Profundidad / Bloques
MatrizProf* crearMatrizProf(int numero, NodoVector* nextNodoVect){      //Bloque i
    MatrizProf* matrizProf;
    matrizProf = (MatrizProf*)malloc(sizeof(matrizProf));
    matrizProf->num = numero;
    matrizProf->nextEleNodoVect = nextNodoVect;
    matrizProf->nextMatrizProf = NULL;
    return matrizProf;
}

MatrizProf* agregarProf(MatrizProf* matrizProfOriginal, NodoVector* nextNodoVect){
    MatrizProf* profOriginal = matrizProfOriginal;
    while(matrizProfOriginal->nextMatrizProf != NULL){
        matrizProfOriginal = matrizProfOriginal->nextMatrizProf;
    }
    int num = matrizProfOriginal->num;
    MatrizProf* nuevaMatrizProf = crearMatrizProf(num+1, nextNodoVect);
    matrizProfOriginal->nextMatrizProf = nuevaMatrizProf;
    return matrizProfOriginal;
}

MatrizProfIni* crearMatrizProfIni(char* nombre, MatrizProf* matrizProf){
    MatrizProfIni* matrizProfIni;
    matrizProfIni = (MatrizProfIni*)malloc(sizeof(matrizProfIni));
    matrizProfIni->matrizProfeleme = matrizProf;
    matrizProfIni->nombre = nombre;
    matrizProfIni->next = NULL;
    return matrizProfIni;
}

bool crearPrimeroMatrizProf(char* name, MatrizProf* matrizProf){
    if(iniMatrizProf == NULL){
        MatrizProfIni* matrizProfInicial;
        matrizProfInicial = (MatrizProfIni*)malloc(sizeof(matrizProfInicial));
        matrizProfInicial->matrizProfeleme=matrizProf;
        matrizProfInicial->nombre=name;
        matrizProfInicial->next=NULL;
        iniMatrizProf = matrizProfInicial;
        return true;
    } else {
        return false;
    }
}

char* nombrarMatrizProf(char* name, MatrizProf* prof, MatrizProfIni* nodoIni){
    if(crearPrimeroMatrizProf(name, prof)==true){
        return name;
    } else{
        while(nodoIni->next != NULL){
            if(strcmp(nodoIni->nombre, name) == 0){
                nodoIni->matrizProfeleme = prof;
                return name;
            }
            nodoIni = nodoIni-> next;
        }
        if(strcmp(nodoIni->nombre, name) == 0){
            nodoIni->matrizProfeleme = prof;
            return name;
        }
        MatrizProfIni* nuevoNodo = crearMatrizProfIni(name, prof);
        nodoIni->next = nuevoNodo;
        return nuevoNodo->nombre;
    }
}

void salidaMatrizProf(char* nombre){
    MatrizProfIni* aux = iniMatrizProf;
    while(aux->next != NULL){
        if(strcmp(aux->nombre, nombre) == 0){
            break;
        }
        aux = aux->next;
    }
    if(strcmp(aux->nombre, nombre) != 0){
        printf("No matrixProf found");
        return;
    } else{
        MatrizProf* prof = aux->matrizProfeleme;
        printf(" Matriz de Datos %s :\n", nombre);
        printf("[\n");
        while(prof != NULL){
            printf("(");
            salidaNodoVector(prof->nextEleNodoVect);
            prof = prof->nextMatrizProf;
            printf(")\n");
        }
        printf("]\n");
    }
}

void salidaNodoVector(NodoVector* nodoVector){
    
    while(nodoVector != NULL){
        printf(" |");
        salidaVectorEle(nodoVector->nextEleVector);
        nodoVector=nodoVector->nextNodoVector;
        printf("| ");
    }
    
}

void salidaVectorEle(VectorEle* vector){
    while(vector != NULL){
        printf(" %f ",vector->num);
        vector= vector->next;
    }
}

// Nodos Vectores / Matriz n_ij
NodoVector* crearNodoVector(int numero, VectorEle* nextEVector){
    NodoVector* nodoVector;
    nodoVector = (NodoVector*)malloc(sizeof(nodoVector));
    nodoVector->num = numero;
    nodoVector->nextEleVector = nextEVector;
    nodoVector->nextNodoVector = NULL;
    return nodoVector;
}

NodoVector* agregarNodoVector(NodoVector* nodoVectorOriginal, VectorEle* nextEVector){
    NodoVector* vectorOriginal=nodoVectorOriginal;
    //vectorOriginal = (NodoVector*)malloc(sizeof(vectorOriginal));
    while(vectorOriginal->nextNodoVector != NULL){
        vectorOriginal = vectorOriginal->nextNodoVector;
    }
    int num = vectorOriginal->num;
    NodoVector* nuevoNodoVector = crearNodoVector(num+1, nextEVector);
    vectorOriginal->nextNodoVector = nuevoNodoVector;
    return nodoVectorOriginal;
}



/* Fin Estructuras */


/* Inicio Funciones Incluidas*/

/* Funciones Trigonométricas */

float sec(float num) {
    return 1 / cos(num);
}

float csc(float num) {
    return 1 / sin(num);
}

float cot(float num) {
    return 1 / tan(num);
}

/* Funciones Algebráicas */

float getRoot(float indice, float radicando) {
    return pow(radicando, 1 / indice);
}

float getExp(float base, float exp) {
    return pow(base, exp);
}

float getLog(float base, float argumento) {
    return log(argumento) / log(base);
}

/* Funciones Estadísticas */

/* Fin Funciones Incluidas*/

/*  Main de ejecución   */

int main (int argc, char **argv) {
    iniNode = crearNumero("PrimerVarialbeReservada", 0);
    VectorEle* elementos = crearVectorEle(0.0001);
    iniNodeVector =  crearVectorIni("SegundaVariableReservada", elementos);
	if(argc > 1) {
		yyin = fopen(argv[1], "r");
	}
	return yyparse ( );
}

void yyerror (char *s) {fprintf (stderr, "%s\n", s);} 

