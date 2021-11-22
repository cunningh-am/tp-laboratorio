#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"


int main()
{

     /*startTesting(1);  // ll_newLinkedList
     startTesting(2);  // ll_len
     startTesting(3);  // getNode - test_getNode
     startTesting(4);  // addNode - test_addNode
     startTesting(5);  // ll_add
     startTesting(6);  // ll_get
     startTesting(7);  // ll_set
     startTesting(8);  // ll_remove
     startTesting(9);  // ll_clear
     startTesting(10); // ll_deleteLinkedList
     startTesting(11); // ll_indexOf
     startTesting(12); // ll_isEmpty
     startTesting(13); // ll_push
     startTesting(14); // ll_pop
     startTesting(15); // ll_contains
     startTesting(16); // ll_containsAll
     startTesting(17); // ll_subList
     startTesting(18); // ll_clone
     startTesting(19); // ll_sort */








    char salir = 'n';

    char rta = '/';
    char conf = '/';
    int id = 0;
    int indice = 0;

    Employee* emp = NULL;

    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaAux = NULL;

    do
    {

        switch(menu())
        {
        case 1:
            system("cls");

            if(!ll_isEmpty(listaEmpleados))
            {
                printf("No se puede cargar mas de una vez el archivo\n");
            }
            else
            {
                controller_loadFromText("data.csv",listaEmpleados);
                listaAux=ll_clone(listaEmpleados);




            }



            break;
        case 2:
            system("cls");
            if(!ll_isEmpty(listaEmpleados))
            {
                printf("No se puede cargar mas de una vez el archivo\n");
            }
            else
            {
                controller_loadFromBinary("data.bin",listaEmpleados);
                listaAux=ll_clone(listaEmpleados);


            }

            break;
        case 3:
            system("cls");
            if(ll_isEmpty(listaEmpleados))                                   //valido que se haya cargado algun archivo y que la lista no este vacia
            {
                printf("Antes de operar se debe cargar un archivo\n");
            }
            else
            {
                controller_addEmployee(listaEmpleados);
            }

            break;
        case 4:
            system("cls");
            if(ll_isEmpty(listaEmpleados))
            {
                printf("Antes de operar se debe cargar un archivo\n");
            }
            else
            {
                controller_editEmployee(listaEmpleados);
            }

            break;

        case 5:
            system("cls");
            if(ll_isEmpty(listaEmpleados))
            {
                printf("Antes de operar se debe cargar un archivo\n");
            }
            else
            {
                controller_removeEmployee(listaEmpleados);
            }

            break;


        case 6:
            system("cls");
            if(ll_isEmpty(listaEmpleados))
            {
                printf("Antes de operar se debe cargar un archivo\n");
            }
            else
            {

                controller_ListEmployee(listaEmpleados);
            }

            break;

        case 7:
            system("cls");
            if(ll_isEmpty(listaEmpleados))
            {
                printf("Antes de operar se debe cargar un archivo\n");
            }
            else
            {
                controller_sortEmployee(listaEmpleados);
            }

            break;
        case 8:
            system("cls");
            if(ll_isEmpty(listaEmpleados))
            {
                printf("Antes de operar se debe cargar un archivo\n");
            }
            else
            {

                getConfirmacion("Los contenidos del archivo data.csv seran sobreescritos. Confirma el guardado? (s para si, n para no) : ",&rta);


                if(rta=='s')
                {
                    controller_saveAsText("data.csv",listaEmpleados);
                    ll_clear(listaAux);
                    listaAux=ll_clone(listaEmpleados);
                    printf("Datos de texto guardados con exito.\n");
                }
                else
                {
                    printf("Guardado de datos de texto cancelado\n");
                }


            }


            break;
        case 9:
            system("cls");
            if(ll_isEmpty(listaEmpleados))
            {
                printf("Antes de operar se debe cargar un archivo\n");
            }
            else
            {

                getConfirmacion("Los contenidos del archivo data.bin seran sobreescritos. Confirma el guardado? (s para si, n para no):",&rta);


                if(rta=='s')
                {
                    controller_saveAsBinary("data.bin",listaEmpleados);
                    ll_clear(listaAux);
                    listaAux=ll_clone(listaEmpleados);
                    printf("Datos binarios guardados con exito.\n");
                }
                else
                {
                    printf("Guardado de datos binarios cancelado\n");
                }

            }

            break;

        case 10:
            system("cls");
            if(ll_isEmpty(listaEmpleados))
            {
                printf("Antes de operar se debe cargar un archivo\n");
            }
            else
            {

                LinkedList* nombre = ll_filter(listaEmpleados,employee_filterSueldo);
                controller_ListEmployee(nombre);
            }

            break;

        case 11:
            system("cls");
            if(ll_isEmpty(listaEmpleados))
            {
                printf("Antes de operar se debe cargar un archivo\n");
            }
            else
            {
                int from=0;
                int to=0;

                printf("Desde que indice se desea copiar? (sin contar a el mismo): ");
                fflush(stdin);
                scanf("%d",&from);

                printf("Hasta que indice se desea copiar?: ");
                fflush(stdin);
                scanf("%d",&to);






                LinkedList* copia= ll_subList(listaEmpleados,from,to);

                if(copia==NULL)
                {
                    printf("ERROR. El from debe ser menor al to y ambos deben ser menores a %d\n",ll_len(listaEmpleados));
                    break;

                }

                controller_ListEmployee(copia);

                ll_deleteLinkedList(copia);
            }

            break;

        case 12:
            system("cls");
            if(ll_isEmpty(listaEmpleados))
            {
                printf("Antes de operar se debe cargar un archivo\n");
            }
            else
            {

                if(ll_containsAll(listaAux,listaEmpleados)==1)
                {
                    printf("La lista de empleados y el data.csv estan al dia\n");

                }
                else
                {
                     printf("La lista de empleados difiere del data.csv\n");
                }

            }

            break;


          case 13:
            system("cls");
            if(ll_isEmpty(listaEmpleados))
            {
                printf("La lista ya esta vacia\n");
            }
            else
            {
                getConfirmacion("Seguro que desea limpiar la lista? debera volver a cargar datos desde el data.csv para poder operar (s para si, n para no): ",&conf);

                if(conf=='s')
                {
                    ll_clear(listaEmpleados);
                }
                else
                {
                    printf("Se cancelo el vaciado\n");

                }



            }

            break;

        case 14:
            system("cls");
            if(ll_isEmpty(listaEmpleados))
            {
                printf("La lista esta vacia\n");
            }
            else
            {
                controller_ListEmployee(listaEmpleados);
                printf("---------------------------------------------\n");
                printf("Ingrese el id del empleado que desea mover: ");
                fflush(stdin);
                scanf("%d",&id);
                id = controller_searchId(listaEmpleados,id);
                emp = ll_get(listaEmpleados,id);

                printf("Ingrese el indice al que desea mover al empleado: ");
                fflush(stdin);
                scanf("%d",&indice);

                if(ll_push(listaEmpleados,indice,emp)==-1)
                {
                    printf("No se pudo mover al empleado al indice especificado\n");
                }
                else
                {
                    system("cls");
                    printf("Se movio al empleado al indice %d\n",indice);
                }

            }

            break;


        case 15:
            system("cls");
            if(ll_isEmpty(listaEmpleados))
            {
                printf("La lista esta vacia\n");
            }
            else
            {
               controller_setEmployee(listaEmpleados);

            }

            break;




        case 16:
            getConfirmacion("Confirma la salida? (s para si, n para no): ",&salir);

            break;

        default:
            printf("Opcion no valida\n");

            break;



        }
        system("pause");
    }
    while(salir == 'n');

    ll_deleteLinkedList(listaEmpleados);

    return 0;
}


















