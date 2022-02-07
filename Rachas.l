%option yylineno

%{
#include "y.tab.h"
void yyerror (char *s);
int yylex();
char* textValor();


%}

finLinea		[\n]+
espacio			[ \t]
digito			[0-9]
entero			{digito}+
flotante		{entero}[\.]{entero}+
letra			[a-zA-Z]
guion			[-_]
id				{letra}+({letra}|{digito}|{guion})*
comentario 		\$[^\n]*
asignacion      :=
logica          >|<|<=|>=|=|!=
mientras        "mientras"
condicion       "condicion"
matriz          "matriz"
operacion       \+|\-|\*|\/|\^|@|;|,

%%
{finLinea}          {}
{comentario}		{}
{espacio}			{}
"vsalida"           {return VSALIDA;}
"msalida"           {return MSALIDA;}
"salida"            {return SALIDA;}
"bsalida"           {return BSALIDA;}
"sin"               {return SIN;}
"cos"               {return COS;}
"tan"               {return TAN;}
"cot"               {return COT;}
"sec"               {return SEC;}
"csc"               {return CSC;}
"getRoot"           {return GETROOT;}
"getExp"            {return GETEXP;}
"getLog"            {return GETLOG;}
"ndotdot"           {return NPP;}
"nidot"             {return NIP;}
"ndotj"             {return NPJ;}
"concatenacionVectores"             {return CONCATENACIONVECTORES;}
"UnionTratamiento"             {return UNIONTRATAMIENTO;}
"UnionBloque"             {return UNIONBLOQUE;}
"UnionModelo"             {return UNIONMODELO;}





{mientras}			{return MIENTRAS;}
{condicion}			{return CONDICION;}
{asignacion}        {return ASIGNACION;}
{entero}			{yylval.numberI = atoi(yytext); return NUMERO_ENTERO;}
{flotante}			{yylval.numberF = atof(yytext); return NUMERO_FLOTANTE;} 
{id}				{yylval.str = textValor(); return ID;}
{operacion}			{return yytext[0];}
{logica}			{yylval.str = textValor(); return LOGICA;}
\(					{return PARENTESISA;}
\)					{return PARENTESISB;}
\[  				{return CORCHETEA;}
\]					{return CORCHETEB;}
\{					{return LLAVESA;}
\}					{return LLAVESB;}
\¿                  {return PA;}
\?                  {return PB;}
\|                  {return OR;}
.                   {ECHO; yyerror ("unexpected character");}

%%

char* textValor(){
    char* palabra = (char*) malloc(sizeof(char)*yyleng);
    snprintf(palabra, yyleng+1, "%s", yytext);
    return palabra;
}

int yywrap (void) {
    return 1;
}
