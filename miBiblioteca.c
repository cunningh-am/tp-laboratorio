#include "miBiblioteca.h"
#include <stdio.h>
#include <stdlib.h>
float promediar(int x, int y)
{
    float z =(float) (x + y)/2;
    return z;
}
int menu()
{
    int opcion;
    system("cls");
    printf("Menu de opciones\n\n");
        printf("1.Saludar\n");
        printf("2.Brindar\n");
        printf("3.Retar\n");
        printf("4.Salir\n\n");

        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);


        return opcion;

}
int menuCalc()
{
  int opcion;
    system("cls");
    printf("Menu de opciones\n\n");
        printf("1. Ingresar primer operando.\n");
        printf("2. Ingresar segundo operando.\n");
        printf("3. Calcular todas las operaciones.\n");
        printf("4. Informar resultados.\n");
        printf("5. Salir de la calculadora.\n\n");

        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);



        return opcion;
}
void despedir()
{
    printf("Nos vemos!\n");
}
void setFlag(int* bandera, int valor)
{
    *bandera = valor;
}
void swap(int* x, int* y)
{
    int z;
    z=*x;
    *x=*y;
    *y=z;
}
int sumar(int x,int y, int* resultado)
{
    int flag=0;

    if(resultado != NULL)
    {
        *resultado= x + y;
        flag=1;
    }
    return flag;
}
int restar(int x, int y, int* resultado)
{
    int flagResta=0;

    if(resultado!= NULL)
    {
        *resultado= x-y;
        flagResta=1;
    }
    return flagResta;
}
int division(int x, int y, float* resultado)
{
    int flagDivision=0;

    if(resultado!= NULL && y!=0)
    {
        *resultado=(float) x/y;
        flagDivision=1;
    }
    return flagDivision;
}
int multiplicacion(int x, int y, int* resultado)
{
    int flagMulti=0;

    if(resultado!=NULL)
    {
      *resultado=x*y;
      flagMulti=1;
    }
    return flagMulti;
}
int factorial(int x, int* resultado)
{
    int flagFact=0;
    int fact=1;

    if(resultado!=NULL)
    {
        for(int i=1; i<=x; i++)
        {
           fact*=i;
        }
        *resultado=fact;
        flagFact=1;
    }
    return flagFact;
}



