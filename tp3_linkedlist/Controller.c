#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "miBiblioteca.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int ret=(-1);
    FILE* f;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        f= fopen(path, "r");
        if(f!=NULL)
        {
            parser_EmployeeFromText(f,pArrayListEmployee);
            printf("\nCarga de archivo de texto exitosa.\n\n");
            ret=1;
        }
        else
        {
            printf("\nNo se pudo cargar el archivo.\n\n");
        }
        fclose(f);

    }
    return ret;
}
int controller_loadID(char* path, int* pID)
{
    int ret=0;
    FILE* f;
    if(path!=NULL && pID != NULL)
    {
        f=fopen(path,"r");
        if(f!=NULL)
        {
            parser_IdFromText(f,pID);
            printf("\nCarga de ID exitosa.\n\n");
            ret=1;
        }
        else
        {
            printf("\nNo se pudo cargar el archivo.\n\n");
        }
        fclose(f);

    }
    return ret;
}
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int ret=1;
	FILE* f;
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		f=fopen(path, "rb");
		if(f!=NULL)
		{
			parser_EmployeeFromBinary(f, pArrayListEmployee);
			printf("\nCarga de archivo binario exitosa.\n\n");
			ret=0;
		}
		else
        {
            ret=1;
            printf("\nNo se pudo cargar el archivo.\n\n");
        }
		fclose(f);
	}
    return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* nextId)
{
    int ret=0;
    int id=(*nextId);
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    Employee* unEmployee;

    if(pArrayListEmployee!=NULL && nextId != NULL)
    {
        unEmployee=employee_new();
        if(unEmployee!=NULL)
        {
            printf("\n");
            ingresarStr("nombre del empleado",nombre,128);
            printf("\n");
            ingresarIntPos("horas trabajadas",&horasTrabajadas,1,350);
            printf("\n");
            ingresarIntPos("sueldo",&sueldo,10000,100000);
            printf("\n");

            employee_setId(unEmployee,id);
            employee_setNombre(unEmployee,nombre);
            employee_setHorasTrabajadas(unEmployee,horasTrabajadas);
            employee_setSueldo(unEmployee,sueldo);
            printf("\nAlta exitosa.\n");
            system("pause");
            (*nextId)++;
            ll_add(pArrayListEmployee,unEmployee);
            controller_printEmployee(unEmployee);
            ret=1;
        }

    }


    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int ret=-1;
    int index=-1;
    int rta;
    Employee* auxEmployee;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    system("cls");
    printf("             MODIFICAR EMPLEADO           \n");
    printf("------------------------------------------\n");
    if(pArrayListEmployee!=NULL)
    {
        ret=0;
        index=controller_findEmployeeById(pArrayListEmployee);
        if(index>-1)
        {
            auxEmployee=ll_get(pArrayListEmployee,index);
            printf("------------------------------------------\n");
            controller_printEmployee(auxEmployee);
            printf("------------------------------------------\n");
            printf("Que parametro desea modificar?\n");
            printf("[1]-Nombre\n[2]-Horas trabajadas\n[3]-Sueldo\n[4]-Cancelar modificacion\n");
            ingresarIntPos("opcion",&rta,1,4);
            switch(rta)
            {
            case 1:
                printf("             MODIFICAR NOMBRE           \n");
                printf("------------------------------------------\n");
                printf("\n");
                ingresarStr("nuevo nombre",nombre,128);
                printf("\n");
                employee_setNombre(auxEmployee, nombre);

                break;
            case 2:
                printf("             MODIFICAR HORAS           \n");
                printf("------------------------------------------\n");
                ingresarIntPos("horas trabajadas",&horasTrabajadas,1,350);
                printf("\n");
                employee_setHorasTrabajadas(auxEmployee, horasTrabajadas);
                break;
            case 3:
                printf("             MODIFICAR SUELDO           \n");
                printf("------------------------------------------\n");
                ingresarIntPos("sueldo",&sueldo,10000,100000);
                printf("\n");
                employee_setSueldo(auxEmployee, sueldo);
                break;
            case 4:
                printf("Modificación cancelada.\n");
                system("pause");
                break;
            }
            if(rta>0 && rta<4)
            {
                system("cls");
                printf("Modificacion exitosa.\n");
                ret=1;
                printf("Se ha modificado al siguiente empleado: \n\n");
                printf("------------------------------------------\n");
                controller_printEmployee(auxEmployee);
                printf("------------------------------------------\n");
                printf("\n");
                system("pause");
            }



        }
    }









    return ret;
}
/** \brief  permite encontrar un empleado preguntando por su ID.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int  retorna el indice del empleado dentro de la ll.
 *
 */
int controller_findEmployeeById(LinkedList* pArrayListEmployee)
{
    int indiceId=-1;
    int idFind;
    int idAux;
    Employee* auxEmployee;
    if(pArrayListEmployee!=NULL)
    {
        ingresarIntPos("ID del empleado que desea localizar",&idFind,0,ll_len(pArrayListEmployee));

        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmployee=ll_get(pArrayListEmployee,i);
            if(auxEmployee!=NULL)
            {
                employee_getId(auxEmployee,&idAux);
                if(idAux==idFind)
                {
                    indiceId=i;
                    break;
                }
            }
        }

    }


    return indiceId;
}
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int  retorna 0 en caso de que la validacion sea incorrecta, 1 en caso de que el empleado sea eliminado con exito y -1 en caso de que el usuario se arrepienta
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int ret=0;
    int index=-1;
    char rta;
    Employee* auxEmployee;
    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        printf("             REMOVER EMPLEADO           \n");
        printf("------------------------------------------\n");
        index=controller_findEmployeeById(pArrayListEmployee);
        if(index>-1)
        {
            auxEmployee=ll_get(pArrayListEmployee,index);
            printf("------------------------------------------\n");
            controller_printEmployee(auxEmployee);
            printf("------------------------------------------\n\n");
            printf("Desea remover de forma permanentemente este empleado? (s/n) \n\n");
            fflush(stdin);
            scanf("%c",&rta);
            while(rta!= 's' && rta!= 'n')
            {
                printf("\nDebe responder con 's' o 'n'. \n");
                fflush(stdin);
                scanf("%c",&rta);
            }
            if(rta=='s')
            {
                system("cls");
                printf("Baja dada con exito.\n");

                ll_remove(pArrayListEmployee, index);
                employee_delete(auxEmployee);
                system("pause");
                ret=1;
            }
            else
            {
                ret=-1;
                printf("No se ha dado de baja al empleado.\n");
                system("pause");

            }

        }
        else
        {
            printf("No se encontro un empleado con dicho ID.\n");
            system("pause");
        }
    }


    return ret;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int ret=0;
    int len;
    Employee* unEmployee;

    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        printf("             LISTA DE EMPLEADOS           \n");
        printf("------------------------------------------\n");

        len=ll_len(pArrayListEmployee);

        if(len>0)
        {
            for(int i=0; i<len; i++)
            {
                unEmployee=ll_get(pArrayListEmployee, i);
                controller_printEmployee(unEmployee);
                printf("------------------------------------------\n");
            }
            ret=1;
        }
        printf("\n");






    }
    return ret;
}
int controller_printEmployee(Employee* unEmployee)
{
    int ret=0;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    if(unEmployee!=NULL)
    {
        ret=1;
        employee_getId(unEmployee,&id);
        employee_getNombre(unEmployee,nombre);
        employee_getHorasTrabajadas(unEmployee,&horasTrabajadas);
        employee_getSueldo(unEmployee,&sueldo);
        printf("ID:                  %d\nNOMBRE:              %s\nHORAS TRABAJADAS:    %d\nSUELDO:              %d\n",id,nombre,horasTrabajadas,sueldo);
    }
    return ret;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    LinkedList* auxLista;
    auxLista=ll_clone(pArrayListEmployee);
    int rta;
    if(pArrayListEmployee!=NULL)
    {


        system("cls");
        printf("        ORDENAR EMPLEADOS       \n");
        printf("--------------------------------\n");
        printf("Que parametro desea utilizar para el ordenamiento?\n");
        printf("[1]-ID\n[2]-Nombre\n[3]-Horas trabajadas\n[4]-Sueldo\n[5]-Cancelar ordenamiento\n");
        ingresarIntPos("opcion",&rta,1,5);
        switch(rta)
        {
        case 1:
            system("cls");
            printf("        ORDENAR EMPLEADOS POR ID       \n");
            printf("--------------------------------\n");
            printf("Ordenar de manera ascendente o descendente?\n");
            printf("[1]-Ascendente\n[2]-Descendente\n[3]-Cancelar ordenamiento\n");
            ingresarIntPos("opcion",&rta,1,3);
            switch(rta)
            {
            case 1:
                ll_sort(auxLista, employee_sortById, 1);
                system("cls");
                controller_ListEmployee(auxLista);
                system("pause");
                break;

            case 2:
                ll_sort(auxLista, employee_sortById, 0);
                system("cls");
                controller_ListEmployee(auxLista);
                system("pause");

                break;

            case 3:
                printf("\nOrdenamiento cancelado.\n\n");

                break;
            }
            break;
        case 2:
            system("cls");
            printf("        ORDENAR EMPLEADOS POR NOMBRE       \n");
            printf("--------------------------------\n");
            printf("Ordenar de manera ascendente o descendente?\n");
            printf("[1]-Ascendente\n[2]-Descendente\n[3]-Cancelar ordenamiento\n");
            ingresarIntPos("opcion",&rta,1,3);
            switch(rta)
            {
            case 1:
                printf("\nEspere un momomento...\n");
                ll_sort(auxLista, employee_sortByName, 1);
                system("cls");
                controller_ListEmployee(auxLista);
                system("pause");
                break;

            case 2:
                printf("\nEspere un momomento...\n");
                ll_sort(auxLista, employee_sortByName, 0);
                system("cls");
                controller_ListEmployee(auxLista);
                system("pause");

                break;

            case 3:
                printf("\nOrdenamiento cancelado.\n\n");

                break;
            }

            break;
        case 3:
            system("cls");
            printf("        ORDENAR EMPLEADOS POR HORAS       \n");
            printf("--------------------------------\n");
            printf("Ordenar de manera ascendente o descendente?\n");
            printf("[1]-Ascendente\n[2]-Descendente\n[3]-Cancelar ordenamiento\n");
            ingresarIntPos("opcion",&rta,1,3);
            switch(rta)
            {
            case 1:
                printf("\nEspere un momomento...\n");
                ll_sort(auxLista, employee_sortByHours, 1);
                system("cls");
                controller_ListEmployee(auxLista);
                system("pause");
                break;

            case 2:
                printf("\nEspere un momomento...\n");
                ll_sort(auxLista, employee_sortByHours, 0);
                system("cls");
                controller_ListEmployee(auxLista);
                system("pause");

                break;

            case 3:
                printf("\nOrdenamiento cancelado.\n\n");

                break;
            }


            break;
        case 4:
            system("cls");
            printf("        ORDENAR EMPLEADOS POR SUELDO       \n");
            printf("--------------------------------\n");
            printf("Ordenar de manera ascendente o descendente?\n");
            printf("[1]-Ascendente\n[2]-Descendente\n[3]-Cancelar ordenamiento\n");
            ingresarIntPos("opcion",&rta,1,3);
            switch(rta)
            {
            case 1:
                printf("\nEspere un momomento...\n");
                ll_sort(auxLista, employee_sortBySalary, 1);
                system("cls");
                controller_ListEmployee(auxLista);
                system("pause");
                break;

            case 2:
                printf("\nEspere un momomento...\n");
                ll_sort(auxLista, employee_sortBySalary, 0);
                system("cls");
                controller_ListEmployee(auxLista);
                system("pause");

                break;

            case 3:
                printf("\nOrdenamiento cancelado.\n\n");

                break;
            }


            break;
        case 5:
            printf("\nOrdenamiento cancelado.\n\n");

            break;
        }


    }









    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int ret=0;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    FILE* f;
    Employee* unEmployee;
    int len;


    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        f=fopen(path,"w");
        unEmployee=employee_new();
        len=ll_len(pArrayListEmployee);
        fprintf(f, "id,nombre,horasTrabajadas,sueldo\n");

        for(int i=0; i<len; i++)
        {
            unEmployee=ll_get(pArrayListEmployee,i);
            employee_getId(unEmployee,&id);
            employee_getNombre(unEmployee,nombre);
            employee_getHorasTrabajadas(unEmployee,&horasTrabajadas);
            employee_getSueldo(unEmployee,&sueldo);
            fprintf(f,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
        }
        fclose(f);
        printf("\nArchivo de texto guardado con exito.\n\n");
        ret=1;

    }
    return ret;
}
/** \brief  Guarda el dato del nextId dentro de un archivo de texto nextid.csv
 *
 * \param path char* direccion del archivo de texto
 * \param pId int*   direccion del next id
 * \return int  0 en caso de que la validacion sea incorrecta, 1 en caso de que este bien
 *
 */
int controller_saveID(char* path, int* pId)
{
    int ret=0;
    FILE* f;

    if(path!=NULL && pId!=NULL)
    {
        f=fopen(path,"w");

        fprintf(f,"%d",*pId);
        fclose(f);
        printf("\nID guardado con exito.\n\n");
        ret=1;
    }
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int ret=1;
	Employee* employee;
	FILE* f;
    int len;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		f=fopen(path, "wb");
		employee=employee_new();

		if(employee!=NULL)
		{
			len=ll_len(pArrayListEmployee);
			for(int i=0; i<len; i++)
            {
				employee=ll_get(pArrayListEmployee, i);
				fwrite(employee, sizeof(Employee), 1, f);
			}
			ret=0;
		}
		fclose(f);
		printf("\nArchivo binario guardado con éxito.\n\n");
	}

	return ret;
}


