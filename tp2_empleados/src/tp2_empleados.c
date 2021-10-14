/*
 ============================================================================
 Name        : tp2_empleados.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#define TAM 1000


int main()
{
	setbuf(stdout, NULL);
    int iterador=1;
    int nextId=1;
    Employee lista[TAM];
    initEmployees(lista,TAM);

    do
    {

        switch(menuEmp())
        {
        case 1:
            addEmployee(lista,TAM,&nextId);
            break;
        case 2:
            if(checkEmpleadoCargado(lista,TAM)==1)
            {
              editEmployee(lista,TAM,findEmployeeByID(lista,TAM));
            }
            else
            {
                printf("Lista de empleados vacia. Ingrese al menos uno para modificar.\n");
                system("pause");
            }

            break;
        case 3:
            if(checkEmpleadoCargado(lista,TAM)==1)
            {
              removeEmployee(lista, TAM, findEmployeeByID(lista,TAM));
            }
            else
            {
                printf("Lista de empleados vacia. Ingrese al menos uno para dar de baja.\n");
                system("pause");
            }
            break;
        case 4:
            if(checkEmpleadoCargado(lista,TAM)==1)
            {
               menuInformar(lista,TAM);
            }
            else
            {
                printf("No hay empleados para mostrar. Ingrese al menos uno.\n");
                system("pause");
            }
            break;
        case 5:
            if(salirABM())
            {
                printf("Decidiste salir.\n");
                iterador=0;
            }
            else
            {
                printf("Salida cancelada.\n");
                system("pause");
            }
            break;
        default:
            printf("Ingrese opcion valida.\n");
            system("pause");
            break;

        }

    }
    while(iterador==1);

    system("pause");




    return 0;
}

