%{  
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
int contadorVectorEle(VectorEle* vector);
int contadorMatrizProf(NodoVector* bloque);
MatrizProf* buscadorModeloDatos(char* nombre);
int nidot(int numero, char* nombre);
int ndotj(int numero, char* nombre);
int ndotdot(char* nombre);
VectorEle* concatenacionVectores(char* vector1, char* vector2,VectorIni* head);
VectorEle* UnionTratamiento(int numero, char* nombre);
VectorEle* UnionBloque(int numero, char* nombre);
VectorEle* UnionModelo(char* nombre);
VectorEle* buscarVector(char* nombre, VectorIni* head);
VectorEle* concatenacionVectoresD(VectorEle* vector1, VectorEle* vector2);



// Inicializacion atributos
Number* iniNode = NULL;
VectorIni* iniNodeVector = NULL;
MatrizIni* iniNodeMatriz = NULL;
MatrizProfIni* iniMatrizProf = NULL;

%}

%union {
    char* str;
    int numberI;
    float numberF;
    struct VectorEle* vec;
    struct MatrizFila* matx;
    struct NodoVector* nodx;
    struct MatrizProf* mProf;
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
%token SALIDA
%token ASIGNACION
%token VSALIDA
%token MSALIDA
%token SIN
%token COS
%token TAN
%token COT
%token SEC
%token CSC
%token GETROOT
%token GETEXP
%token GETLOG
%token PA
%token PB
%token OR
%token BSALIDA
%token NPP
%token NPJ
%token NIP
%token UNIONBLOQUE
%token UNIONMODELO
%token UNIONTRATAMIENTO
%token CONCATENACIONVECTORES
%token BUSCARVECTOR

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
%type <matx> matriz
%type <mProf> bloque
%type <nodx> vectorN

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
        | VSALIDA PARENTESISA ID PARENTESISB ';'        {salidaVector($3,iniNodeVector);}
        | line VSALIDA PARENTESISA ID PARENTESISB ';'   {salidaVector($4,iniNodeVector);}
	    | MSALIDA PARENTESISA ID PARENTESISB ';'        {salidaMatriz($3,iniNodeMatriz);}
        | line MSALIDA PARENTESISA ID PARENTESISB ';'   {salidaMatriz($4,iniNodeMatriz);}
        | BSALIDA PARENTESISA ID PARENTESISB ';'        {salidaMatrizProf($3);}
        | line BSALIDA PARENTESISA ID PARENTESISB ';'   {salidaMatrizProf($4);}
        ;

expr    : term                                          {$$ = $1;}
        | '-' term                                       {$$ = -$2;}
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
	    | ID ASIGNACION LLAVESA matriz LLAVESB          {nombrarMatriz($1, $4, iniNodeMatriz);}
        | ID ASIGNACION LLAVESA bloque LLAVESB          {nombrarMatrizProf($1, $4, iniMatrizProf);}
        ;

vector  : CONCATENACIONVECTORES PARENTESISA ID ID PARENTESISB           {$$ = concatenacionVectores($3,$4, iniNodeVector);}
        | UNIONTRATAMIENTO PARENTESISA expr ID PARENTESISB           {$$ = UnionTratamiento($3,$4);}
        | UNIONBLOQUE PARENTESISA expr ID PARENTESISB           {$$ = UnionBloque($3,$4);}
        | UNIONMODELO PARENTESISA ID PARENTESISB           {$$ = UnionModelo($3);}
        | term                                          {$$ = crearVectorEle($1);}
        | vector term                                   {$$ = agregarVectorEle($1,crearVectorEle($2));}
        ;

functs  : SEC PARENTESISA expr PARENTESISB              {$$ = sec($3);}
        | CSC PARENTESISA expr PARENTESISB              {$$ = csc($3);}
        | COT PARENTESISA expr PARENTESISB              {$$ = cot($3);}
        | SIN PARENTESISA expr PARENTESISB              {$$ = sin($3);}
        | COS PARENTESISA expr PARENTESISB              {$$ = cos($3);}
        | TAN PARENTESISA expr PARENTESISB              {$$ = tan($3);} 
        | GETROOT PARENTESISA expr  expr PARENTESISB    {$$ = getRoot($3,$4);}
        | GETEXP PARENTESISA expr  expr PARENTESISB     {$$ = getExp($3,$4);}
        | GETLOG PARENTESISA expr  expr PARENTESISB     {$$ = getLog($3,$4);}
        | NPP PARENTESISA ID PARENTESISB                {$$ = ndotdot($3);}
        | NPJ PARENTESISA expr ID PARENTESISB           {$$ = ndotj($3,$4);}
        | NIP PARENTESISA expr ID PARENTESISB           {$$ = nidot($3,$4);}       
//| CONCATENADORB PARENTESISA ID PARENTESISB           {concatenadorB($3);}    
  //      | UNIONMODELO PARENTESISA ID ID PARENTESISB           {UnionModelo($3,$4);}
      //  | BUSCARVECTOR PARENTESISA ID ID PARENTESISB           {buscarVector($3,$4);}
        ;
	
matriz  : CORCHETEA vector CORCHETEB			        {$$ = crearFila(0, $2);}
        | matriz CORCHETEA vector CORCHETEB             {$$ = agregarFila($1, $3);}
        ;

vectorN : OR vector OR                                  {$$ = crearNodoVector(0, $2);}
        | vectorN OR vector OR                          {$$ = agregarNodoVector($1, $3);}
        ;

bloque  : PARENTESISA vectorN PARENTESISB               {$$ = crearMatrizProf(0, $2);printf("contador: %d ", contadorMatrizProf($2));}
        | bloque PARENTESISA vectorN PARENTESISB        {$$ = agregarProf($1, $3);printf("contador: %d ", contadorMatrizProf($3));}
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
    printf("Vectores que estan entrando\n");
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

//Total de datos del modelo de dos vías de clasificación.

int contadorVectorEle(VectorEle* vector) {  //Contador de vector de datos
    int sum = 0;
    while(vector != NULL){
        sum++;
        vector=vector->next;
    }
    return sum;
}

int contadorMatrizProf(NodoVector* bloque){       //Contador por bloque N_(i,.)
    int sum = 0;
    while(bloque != NULL){
        sum += contadorVectorEle(bloque->nextEleVector);
        bloque = bloque->nextNodoVector;
    }
    return sum;
}

MatrizProf* buscadorModeloDatos(char* nombre){
    MatrizProfIni* inicio = iniMatrizProf;
    while(inicio->next != NULL){
        if(strcmp(inicio->nombre, nombre) == 0){
            break;
        }
        inicio=inicio->next;
    }
    if(strcmp(inicio->nombre, nombre) != 0){
        printf("Upps... No se encontró el Modelo. Verifica el nombre");
        return NULL;
    } else{
        return inicio->matrizProfeleme;
    }

}

int ndotdot(char* nombre){    //N_(.,.) Total de datos del modelo de dos vías de clasificación.
    MatrizProf* modelo = buscadorModeloDatos(nombre);
    int sum = 0;
    while(modelo != NULL){
        sum += contadorMatrizProf(modelo->nextEleNodoVect);
        modelo= modelo->nextMatrizProf;
    }
    return sum;
}

int contadorTratamiento(int numero, NodoVector* bloque){       
    int j = 1;
    int sum = 0;
    while(bloque != NULL){
        if(j==numero){
            sum += contadorVectorEle(bloque->nextEleVector);
        }
        j++;
        bloque = bloque->nextNodoVector;
    }
    return sum;
}

int nidot(int numero, char* nombre){    //Contador por bloque N_(i,.)
    MatrizProf* modelo = buscadorModeloDatos(nombre);
    int i = 1;
    int sum = 0;
    while(modelo != NULL){
        if(i == numero){
            sum += contadorMatrizProf(modelo->nextEleNodoVect);
            break;
        }
        i++;
        modelo = modelo->nextMatrizProf;
    }
    return sum;
}

int ndotj(int numero, char* nombre){    //Contador por tratamiento N_(.,j)
    MatrizProf* modelo = buscadorModeloDatos(nombre);
    int sum = 0;
    while(modelo != NULL){
        sum += contadorTratamiento(numero, modelo->nextEleNodoVect);
        modelo= modelo->nextMatrizProf;
    }
    return sum;
}

VectorEle* buscarVector(char* nombre, VectorIni* head){
    while(head->next != NULL){
        if(strcmp(head->nombre, nombre) == 0){
            break;
        }
        head = head->next;
    }
    if(strcmp(head->nombre, nombre) != 0){
        printf("Vector not found\n");
        return NULL;
    }else{
        return head->nextEle;
    }
}

// uniones
VectorEle* concatenacionVectores(char* vector1, char* vector2, VectorIni* head) { 
     VectorEle* bvector1= buscarVector(vector1,head);
     VectorEle* bvector2= buscarVector(vector2,head);
     VectorEle* resultado= crearVectorEle(bvector1->num);
    
    bvector1=bvector1->next;
    while(bvector1 != NULL){

        agregarVectorEle(resultado,crearVectorEle(bvector1->num));
        bvector1=bvector1->next;
         }

     while(bvector2 != NULL){
        agregarVectorEle(resultado,crearVectorEle(bvector2->num));
        bvector2=bvector2->next;
        

    }
    return resultado;
}
VectorEle* concatenacionVectoresD(VectorEle* vector1, VectorEle* vector2) { 
     VectorEle* resultado= crearVectorEle(vector1->num);
    
    vector1=vector1->next;
    while(vector1 != NULL){

        agregarVectorEle(resultado,crearVectorEle(vector1->num));
        vector1=vector1->next;
         }

     while(vector2 != NULL){
        agregarVectorEle(resultado,crearVectorEle(vector2->num));
        vector2=vector2->next;
        

    }
    return resultado;
}


VectorEle* UnionTratamiento(int numero,char* nombre){       
    MatrizProf* modelo = buscadorModeloDatos(nombre);
    VectorEle* resultado= crearVectorEle(modelo->nextEleNodoVect->nextEleVector->num);  

    while(modelo != NULL){  
       NodoVector* bloque=  modelo->nextEleNodoVect;   
       int j = 1;

       while(bloque !=NULL){
        if(j==numero){
         resultado= concatenacionVectoresD(resultado,bloque->nextEleVector);                    
        }
        
         bloque=bloque->nextNodoVector;
        
        j++;
       }
      
       
     modelo = modelo->nextMatrizProf;

    }
    resultado=resultado->next;
    return resultado;
}
VectorEle* UnionBloque(int numero,char* nombre){       
    MatrizProf* modelo = buscadorModeloDatos(nombre);
    VectorEle* resultado= crearVectorEle(modelo->nextEleNodoVect->nextEleVector->num);  
    int j = 1;

    while(modelo != NULL){  
       NodoVector* bloque=  modelo->nextEleNodoVect;   
       if (j==numero){
       while(bloque !=NULL){
        if(j==numero){
         resultado= concatenacionVectoresD(resultado,bloque->nextEleVector);                    
        }
        
         bloque=bloque->nextNodoVector;
        

       }
       j++;
       }
     modelo = modelo->nextMatrizProf;

    }
    resultado=resultado->next;
    return resultado;
}

// Algoritmo Ordenamiento Burbuja

VectorEle* ordenamientoBurbuja (VectorEle* vector){
    VectorEle* ordenado=vector;
    VectorEle* a = vector;
    while(vector!=NULL){
        a = a->next;
    }
    //for(int i=0; i<n; i++){
        //for(int j=0; j<(n-i); j++){
            //if(a[j] > a[j+1]){
                //aux = a[j];
                //a[j] = a[j+1];
                //a[j+1] = aux;
            //}
        //}
    //}
    return ordenado;
}

//

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
