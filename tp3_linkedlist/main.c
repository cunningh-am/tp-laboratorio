#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "miBiblioteca.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    char seguir='s';
    LinkedList* listaEmpleados = ll_newLinkedList();
    int archivoCargado=0;
    int nextId;
    do
    {
        system("cls");
        switch(menu())
        {
        case 1:
            if(archivoCargado)
            {
                printf("\nNo se puede cargar, ya hay un archivo cargado.\n\n");
                system("pause");
            }
            else
            {
                if(controller_loadFromText("data.csv",listaEmpleados))
                {
                    controller_loadID("nextId.csv",&nextId);
                    archivoCargado=1;
                    system("pause");

                }

            }
            break;
        case 2:
            if(archivoCargado)
            {
                printf("\nNo se puede cargar, ya hay un archivo cargado.\n\n");
                system("pause");
            }
            else
            {
                if(!controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    controller_loadID("nextId.csv",&nextId);
                    archivoCargado=1;
                    system("pause");
                }
            }
            break;
        case 3:
            controller_addEmployee(listaEmpleados,&nextId);
            break;
        case 4:
            if(listaEmpleados->size)
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("\nNo se puede modificar un empleado sin antes cargar un archivo o dar una alta.\n\n");
                system("pause");
            }
            break;
        case 5:
            if(listaEmpleados->size)
            {
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("\nNo se puede remover un empleado sin antes cargar un archivo o dar una alta.\n\n");
                system("pause");
            }

            break;
        case 6:
            if(listaEmpleados->size)
            {
                controller_ListEmployee(listaEmpleados);
                system("pause");
            }
            else
            {
                printf("\nNo puede listar empleados sin antes cargar un archivo de texto/binario o dar una alta.\n\n");
                system("pause");
            }
            break;
        case 7:
            if(listaEmpleados->size)
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("\nNo puede listar empleados sin antes cargar un archivo de texto/binario o dar una alta.\n\n");
                system("pause");
            }
            break;
        case 8:
            if(listaEmpleados->size)
            {
                controller_saveAsText("data.csv",listaEmpleados);
                controller_saveID("nextId.csv",&nextId);
                system("pause");
            }
            else
            {
                printf("\nNo se puede guardar una lista sin empleados.\n\n");
                system("pause");
            }
            break;
        case 9:
             if(listaEmpleados->size)
            {
                controller_saveAsBinary("data.bin",listaEmpleados);
                controller_saveID("nextId.csv",&nextId);
                system("pause");
            }
            else
            {
                printf("\nNo se puede guardar una lista sin empleados.\n\n");
                system("pause");
            }
            break;
        }
    }
    while(seguir=='s');
    return 0;
}
