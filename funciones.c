#include <stdio.h> /* necesario para utilizar printf */
#include <math.h>

#define SIZEOF(arr) sizeof(arr) / sizeof(*arr) /*Macro auxiliar para obtener el tamaño de un array*/

/* Funciones Trigonométricas */
double sec(double num)
{
    return 1 / cos(num);
}

double csc(double num)
{
    return 1 / sin(num);
}

double cot(double num)
{
    return 1 / tan(num);
}

/* Funciones Algebráicas */

double getRoot(double indice, double radicando)
{
    return pow(radicando, 1 / indice);
}

double getExp(double base, double exp)
{
    return pow(base, exp);
}

double getLog(double argumento, double base)
{
    return log(argumento) / log(base);
}

/* Funciones Estadísticas */

double getSumatoria(double datos[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += datos[i];
    }
    return sum;
}

double getMedia(double datos[], int size)
{
    return getSumatoria(datos, size) / size;
}

double getVarianza(double datos[], int size)
{
    double varianza = 0;
    double x = getMedia(datos, size);
    for (int i = 0; i < size; i++)
    {
        varianza += getExp(datos[i] - x, 2);
    }
    return varianza / size;
}

double getDesvTip(double datos[], int size)
{
    return getRoot(2, getVarianza(datos, size));
}

double getCovarianza(double datosA[], double datosB[], int size)
{
    double covarianza = 0;
    double x = getMedia(datosA, size);
    double y = getMedia(datosB, size);
    for (int i = 0; i < size; i++)
    {
        covarianza += (datosA[i] - x) * (datosB[i] - y);
    }
    return covarianza / size;
}

int main() /* tipo 'int' de retorno implícito */
{
    double pruebaA[] = {0, 4, 8};
    double pruebaB[] = {5, 5, 8};

    printf("%g\n", getCovarianza(pruebaA, pruebaB, SIZEOF(pruebaA)));
    printf("%g\n", sec(2));
    return 0;
}