%{  
void yyerror (char *s);
int yylex();
#include <stdio.h>     /* C declarations used in actions */
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
extern FILE* yyin;

// Aqui es para el codigo necesario para almacenar

// Comando Ahorrador:   :v
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

// Inicializacion atributos
Number* iniNode = NULL;
VectorIni* iniNodeVector = NULL;

%}

%union {
    char* str;
    int numberI;
    float numberF;
    struct VectorEle* vec;
}

%start line 
%token PARENTESISA 
%token PARENTESISB 
%token COMENTARIO          
%token ESPACIO                                                                         
%token MIENTRAS            
%token CONDICION                                           
%token CORCHETEA           
%token CORCHETEB
%token LLAVESA
%token LLAVESB            
%token MATRIZ  
%token SALIDA
%token ASIGNACION
%token VSALIDA
%token SIN
%token COS
%token TAN
%token COT
%token SEC
%token CSC

%token<str> ID   
%token<numberI> NUMERO_ENTERO
%token<numberF> NUMERO_FLOTANTE
%token<str> LOGICA 

%type <numberF> expr
%type <numberF> line
%type <numberF> term
%type <str> indent
%type <vec> vector
%type <numberF> functs

%left '+' '-'
%left '*' '/'
%left NUMERO_ENTERO NUMERO_FLOTANTE


%%

line    : line ';'                                      {;} 
        | indent ';'                                    {;}
        | line indent ';'                               {;}
        | expr ';'                                      {;}
        | expr ';' line                                 {;}
        | line functs ';'                               {;}
        | functs ';'                                    {;}
        | SALIDA PARENTESISA expr PARENTESISB ';'       {printf("%f \n",$3);}
        | line SALIDA PARENTESISA expr PARENTESISB ';'  {printf("%f \n",$4);}
        | SALIDA PARENTESISA ID PARENTESISB ';'         {printf("%s : %f", $3, getNumber(iniNode,$3));}
        | VSALIDA PARENTESISA ID PARENTESISB ';'        {salidaVector($3,iniNodeVector );}
        | line VSALIDA PARENTESISA ID PARENTESISB ';'   {salidaVector($4,iniNodeVector );}
        ;

expr    : term                                          {$$ = $1;}
        | expr '+' expr                                 {$$ = $1 + $3;}
        | expr '-' expr                                 {$$ = $1 - $3;}
        | expr '/' expr                                 {$$ = $1 / $3;}
        | expr '*' expr                                 {$$ = $1 * $3;}
        | functs                                        {;}
        ;

term    : NUMERO_ENTERO                                 {$<numberF>$ = (float)$1;}
        | NUMERO_FLOTANTE                               {$$ = $1;}
        | ID                                            {$$ = getNumber(iniNode,$1);}
        ; 

indent  : ID ASIGNACION expr                            {agregarNumero(iniNode,$1,$3);}
        | ID ASIGNACION CORCHETEA vector CORCHETEB      {nombrarVector(iniNodeVector, $1, $4);}
        ;

vector  : term                                          {$$ = crearVectorEle($1);}
        | vector term                                   {$$ = agregarVectorEle($1,crearVectorEle($2));}
        ;

functs  : SEC PARENTESISA expr PARENTESISB              {$$ = sec($3);}
        | CSC PARENTESISA expr PARENTESISB              {$$ = csc($3);}
        | COT PARENTESISA expr PARENTESISB              {$$ = cot($3);}
        | SIN PARENTESISA expr PARENTESISB              {$$ = sin($3);}
        | COS PARENTESISA expr PARENTESISB              {$$ = cos($3);}
        | TAN PARENTESISA expr PARENTESISB              {$$ = tan($3);} 
        ;
        
%%

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

// Se agrega el numero que se creo a la lista encadenada o se actualiza el valor
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
            head = crearVectorIni(nombre,elementos);
            return head->nombre; 
        }
        head = head->next;
    }
    if(strcmp(head->nombre , nombre) == 0){
        head = crearVectorIni(nombre, elementos);
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

/////////////////////Estructuras

/////// Funciones Incluidas

// Funciones Trigonométricas

float sec(float num) {
    return 1 / cos(num);
}

float csc(float num) {
    return 1 / sin(num);
}

float cot(float num) {
    return 1 / tan(num);
}

/////// Funciones Incluidas

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