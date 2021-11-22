#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"

#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    FILE* f = NULL;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        f=fopen(path, "r");

        if(  f!=NULL  && (parser_EmployeeFromText(f, pArrayListEmployee)==1))
        {

            printf("Se ha cargado el archivo de texto.\n\n");
            todoOk=1;
        }
        else
        {
            printf("\nNo se pudo cargar el archivo de texto.\n\n");
        }
        fclose(f);
    }
    return todoOk;
}

/** \brief Carga los datos de los e;mpleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk=0;
	FILE* f = NULL;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		f=fopen(path, "rb");
		if(f!=NULL && (parser_EmployeeFromBinary(f, pArrayListEmployee)==1))
		{

			printf("\nCarga de archivo binario exitosa.\n\n");
			todoOk=1;
		}
		else
        {
            todoOk=0;
            printf("\nNo se pudo cargar el archivo.\n\n");
        }
		fclose(f);
	}
    return todoOk;
}

int controller_nextId()
{
	FILE* f=fopen("lastId.txt", "r");
	int* currentId=(int*) malloc(sizeof(int));
    int nextId;

    if(f==NULL)
    {
        nextId=1001;
    }
    else
    {
        fscanf(f, "%d", currentId);
        nextId=*currentId+1;
    }
    fclose(f);

    return nextId;
}

void controller_saveId(int currentId)
{
    FILE* f=fopen("lastId.txt", "r+");

    if(f==NULL)
    {
        f=fopen("lastId.txt", "w");
    }

    fprintf(f,"%d", currentId);
    fclose(f);
}


/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    Employee* auxEmp = NULL;
    int id;
    char nombre[128];
    int horas;
    int sueldo;
    int rta;

    if(pArrayListEmployee!=NULL)
    {
        auxEmp=employee_new();

        if(auxEmp!=NULL)
        {
            system("cls");
            printf("            *** Alta Empleado ***              \n");
            printf("---------------------------------------------\n");

            id=controller_nextId();
			employee_setId(auxEmp, id);



            rta = getStringLetras("Ingrese el nombre del empleado: ",nombre);

            while(rta==0)
            {
                rta = getStringLetras("error. Ingrese un nombre valido (solo letras): ",nombre);
            }


            employee_setNombre(auxEmp, nombre);


            printf("Ingrese las horas trabajadas del empleado (solo numerico >0 y <350): ");
            fflush(stdin);
            scanf("%d",&horas);

            while(horas<=0 || horas>=350 || (esSoloNumerico(horas))==0)
            {
                printf("error. Ingrese las horas trabajadas del empleado (solo numerico >0): ");
                fflush(stdin);
                scanf("%d",&horas);
            }

            employee_setHorasTrabajadas(auxEmp,horas);


            printf("Ingrese el sueldo del empleado (entre 0 y 100000): ");
            fflush(stdin);
            scanf("%d",&sueldo);

            while(sueldo<=0 || sueldo>100000 || (esSoloNumerico(sueldo))==0)
            {
                printf("error. Ingrese un sueldo valido (entre 0 y 100000): ");
                fflush(stdin);
                scanf("%d",&sueldo);
            }


            employee_setSueldo(auxEmp,sueldo);

            fflush(stdin);



            ll_add(pArrayListEmployee, auxEmp);
            controller_saveId(id);

            system("cls");
            printf("Alta exitosa.\n");
            todoOk=1;
            printf("Se ha dado de alta al siguiente empleado: \n\n");
            printf("   Id      Nombre      Horas         Sueldo\n");
            printf("---------------------------------------------\n");
            controller_printAnEmployee(auxEmp);
            printf("\n");

        }
    }
    return todoOk;

}

int controller_searchId(LinkedList* pArrayListEmployee, int id)
{
    int index=-1;
    int tam;
    Employee* emp = NULL;

    if(pArrayListEmployee!=NULL)
    {
        tam=ll_len(pArrayListEmployee);

        for(int i=0; i<tam; i++)
        {
            emp=ll_get(pArrayListEmployee, i);
            if(emp!=NULL)
            {
                employee_getId(emp, &index);
                if(index==id)
                {
                    index=i;
                    break;
                }
            }
        }
    }
    return index;





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
    int todoOk=0;
    int id;
    Employee* emp = NULL;
    char nombre[128];
    int horas;
    int sueldo;
    int rta;

    if(pArrayListEmployee!=NULL)
    {

        system("cls");
        printf("            *** Modificar empleado ***              \n");
        printf("---------------------------------------------\n");

        controller_ListEmployee(pArrayListEmployee);
        printf("---------------------------------------------\n");
        printf("Ingrese el id del empleado que desea modificar: ");
        fflush(stdin);
        scanf("%d",&id);

        id = controller_searchId(pArrayListEmployee,id);

        emp = ll_get(pArrayListEmployee,id);


        system("cls");

        if(emp!=NULL)
        {



            switch(subMenu())
            {
            case 1:


                rta = getStringLetras("Ingrese el nuevo nombre del empleado: ",nombre);

                while(rta==0)
                {
                    rta = getStringLetras("error. Ingrese un nombre valido (solo letras): ",nombre);
                }


                employee_setNombre(emp, nombre);
                printf("Nombre modificado con exito\n");
                todoOk=1;
                break;

            case 2:


                printf("Ingrese las nuevas horas trabajadas del empleado (solo numerico >0 y <350): ");
                fflush(stdin);
                scanf("%d",&horas);

                while(horas<=0 || horas>=350 ||(esSoloNumerico(horas))==0)
                {
                    printf("error. Ingrese las nuevas horas trabajadas del empleado (solo numerico >0 y <350): ");
                    fflush(stdin);
                    scanf("%d",&horas);
                }

                employee_setHorasTrabajadas(emp,horas);

                printf("Horas trabajadas modificadas con exito\n");
                todoOk=1;
                break;

            case 3:


                printf("Ingrese el nuevo sueldo del empleado (entre 0 y 100000): ");
                fflush(stdin);
                scanf("%d",&sueldo);

                while(sueldo<=0 || sueldo>100000 || (esSoloNumerico(sueldo))==0)
                {
                    printf("error. Ingrese un sueldo valido (entre 0 y 100000): ");
                    fflush(stdin);
                    scanf("%d",&sueldo);
                }


                employee_setSueldo(emp,sueldo);

                printf("Sueldo modificado con exito\n");
                todoOk=1;
                break;

            case 4:
                todoOk=1;
                break;

            default:
                printf("Opcion invalida\n");
                break;



            }
        }
        else
        {
            printf("No existe empleado asociado a ese id.\n\n");
        }

        todoOk=1;
    }





    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    Employee* emp = NULL;
    char rta;
    int id;
    int indice;


    if(pArrayListEmployee!=NULL)
    {

        system("cls");
        printf("            *** Eliminar empleado ***              \n");
        printf("---------------------------------------------\n");

        controller_ListEmployee(pArrayListEmployee);
        printf("---------------------------------------------\n");
        printf("Ingrese el id del empleado que desea eliminar: ");
        fflush(stdin);
        scanf("%d",&id);

        id = controller_searchId(pArrayListEmployee,id);

        emp = ll_get(pArrayListEmployee,id);
        indice = ll_indexOf(pArrayListEmployee,emp);

        system("cls");




        if(emp!=NULL)
        {



            printf("Se dara de baja al siguiente empleado: \n\n");
            printf("   Id      Nombre      Horas         Sueldo\n");
            printf("---------------------------------------------\n");
            controller_printAnEmployee(emp);
            printf("\n");

            printf("Confirma la baja? (s para si, n para no): ");
            fflush(stdin);
            scanf("%c",&rta);

            while(rta!='s'&&rta!='n')
            {
                printf("Opcion no valida. Confirma la baja? (s para si, n para no): ");
                fflush(stdin);
                scanf("%c",&rta);
            }

            if(rta=='s')
            {
                emp=ll_pop(pArrayListEmployee,indice);
                system("cls");
                printf("\n\n");
                controller_printAnEmployee(emp);
                printf("\n\n");
                printf("Se ha eliminado a este empleado con exito.\n");
            }
            else
            {
                printf("Baja cancelada\n");
            }

        }
        else
        {
            printf("No existe empleado asociado a ese id.\n\n");
        }




        todoOk=1;
    }
    return todoOk;
}


/** \brief Imprime un empleado en pantalla
 *
 * \param emp Employee* empleado a mostrar
 *
 * \return int
 *
 */
int controller_printAnEmployee(Employee* emp)
{
    int todoOk=0;
    int id;
    char nombre[30];
    int horas;
    int sueldo;

    if(emp!=NULL)
    {
        employee_getId(emp,&id);
        employee_getNombre(emp,nombre);
        employee_getHorasTrabajadas(emp,&horas);
        employee_getSueldo(emp,&sueldo);



        printf("   %d     %10s        %d          %d   \n",id,nombre,horas,sueldo);



        todoOk=1;
    }




    return todoOk;
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
    int todoOk=0;
    int tam;

    Employee* auxEmpleado = NULL;

    if(pArrayListEmployee!= NULL)
    {
        system("cls");
        printf("       *** Listado de Empleados ***      \n");
        printf("   Id      Nombre      Horas         Sueldo\n");
        printf("---------------------------------------------\n");

        tam=ll_len(pArrayListEmployee);

        if(tam>0)
        {
            for(int i=0; i<tam; i++)
            {
                auxEmpleado = ll_get(pArrayListEmployee, i);
                controller_printAnEmployee(auxEmpleado);


            }
        }
        printf("\n");





        todoOk=1;
    }




    return todoOk;



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
    int todoOk=0;
    LinkedList* copia = NULL;

    if(pArrayListEmployee!=NULL)
    {
        system("cls");

        copia = ll_clone(pArrayListEmployee);


        printf("            *** Ordenar empleados en lista clonada ***              \n");
        printf("---------------------------------------------\n");


        switch(menuOrdenar())
        {



        case 1:
            system("cls");
            printf("            *** Ordenar por id ***              \n");
            printf("---------------------------------------------\n");
            switch(menuCriterio())
            {
            case 1:
                printf("\nOrdenando....\n\n");
                ll_sort(copia, employee_ordenarId, 1);
                system("cls");
                controller_ListEmployee(copia);
                break;

            case 2:
                printf("\nOrdenando....\n\n");
                ll_sort(copia, employee_ordenarId, 0);
                system("cls");
                controller_ListEmployee(copia);
                break;

            case 3:
                break;

            }
            break;

        case 2:
            system("cls");
            printf("            *** Ordenar por Nombre ***              \n");
            printf("---------------------------------------------\n");
            switch(menuCriterio())
            {
            case 1:
                printf("\nOrdenando....\n\n");
                ll_sort(copia, employee_ordenarNombres,1);
                system("cls");
                controller_ListEmployee(copia);
                break;

            case 2:
                printf("\nOrdenando....\n\n");
                ll_sort(copia, employee_ordenarNombres,0);
                system("cls");
                controller_ListEmployee(copia);
                break;

            case 3:
                break;

            }
            break;

        case 3:
            system("cls");
            printf("            *** Ordenar por Horas de trabajo ***              \n");
            printf("---------------------------------------------\n");
            switch(menuCriterio())
            {
            case 1:
                printf("\nOrdenando....\n\n");
                ll_sort(copia, employee_ordenarHorasTrabajadas,1);
                system("cls");
                controller_ListEmployee(copia);
                break;

            case 2:
                printf("\nOrdenando....\n\n");
                ll_sort(copia, employee_ordenarHorasTrabajadas,0);
                system("cls");
                controller_ListEmployee(copia);
                break;

            case 3:
                break;

            }
            break;

        case 4:
            system("cls");
            printf("            *** Ordenar por sueldo ***              \n");
            printf("---------------------------------------------\n");
            switch(menuCriterio())
            {
            case 1:
                printf("\nOrdenando....\n\n");
                ll_sort(copia, employee_ordenarSueldos,1);
                system("cls");
                controller_ListEmployee(copia);
                break;

            case 2:
                printf("\nOrdenando....\n\n");
                ll_sort(copia, employee_ordenarSueldos,0);

                system("cls");
                controller_ListEmployee(copia);
                break;

            case 3:
                break;

            }
            break;

        case 5:
            break;



        }


        todoOk=1;
    }





    return todoOk;
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
    int todoOk=0;
    FILE* f = NULL;
    Employee* emp = NULL;
    int tam;
    int id;
	char nombre[128];
	int sueldo;
	int horas;


	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		f=fopen(path, "w");
		emp=employee_new();
		tam=ll_len(pArrayListEmployee);

		fprintf(f, "id,nombre,horasTrabajadas,sueldo\n");

		for(int i=0; i<tam; i++)
		{
			emp=ll_get(pArrayListEmployee, i);

			if(emp!=NULL)
			{
				employee_getId(emp, &id);
				employee_getNombre(emp, nombre);
				employee_getHorasTrabajadas(emp, &horas);
				employee_getSueldo(emp, &sueldo);

				fprintf(f, "%d,%s,%d,%d\n", id, nombre, horas, sueldo);
				todoOk=1;
			}
		}
		fclose(f);
		printf("El archivo de texto fue guardado con exito.\n");
	}

    return todoOk;

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
    int todoOk = 0;
	int tam = ll_len(pArrayListEmployee);

	FILE *f = NULL;

	Employee* auxEmp;

	if(pArrayListEmployee != NULL && path != NULL)
	{
        f = fopen(path, "wb");
		for (int i = 0; i < tam; i++)
		{
			auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
			fwrite(auxEmp, sizeof(Employee), 1, f);
		}
		todoOk=1;
		fclose(f);
		printf("\nArchivo guardado exitosamente.\n");
	}


    return todoOk;
}

int controller_setEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    Employee* auxEmp = NULL;
    int id;
    char nombre[128];
    int horas;
    int sueldo;
    int indice;
    int rta;

    if(pArrayListEmployee!=NULL)
    {
        auxEmp=employee_new();

        if(auxEmp!=NULL)
        {
            system("cls");
            printf("            *** Agregar empleado en indice especificado ***              \n");
            printf("---------------------------------------------\n");

            id=controller_nextId();
			employee_setId(auxEmp, id);



            rta = getStringLetras("Ingrese el nombre del empleado: ",nombre);

            while(rta==0)
            {
                rta = getStringLetras("error. Ingrese un nombre valido (solo letras): ",nombre);
            }


            employee_setNombre(auxEmp, nombre);


            printf("Ingrese las horas trabajadas del empleado (solo numerico >0 y <350): ");
            fflush(stdin);
            scanf("%d",&horas);

            while(horas<=0 || horas>=350 || (esSoloNumerico(horas))==0)
            {
                printf("error. Ingrese las horas trabajadas del empleado (solo numerico >0): ");
                fflush(stdin);
                scanf("%d",&horas);
            }

            employee_setHorasTrabajadas(auxEmp,horas);


            printf("Ingrese el sueldo del empleado (entre 0 y 100000): ");
            fflush(stdin);
            scanf("%d",&sueldo);

            while(sueldo<=0 || sueldo>100000 || (esSoloNumerico(sueldo))==0)
            {
                printf("error. Ingrese un sueldo valido (entre 0 y 100000): ");
                fflush(stdin);
                scanf("%d",&sueldo);
            }


            employee_setSueldo(auxEmp,sueldo);

            fflush(stdin);

            printf("Ingrese el indice al que desea mover al empleado (mayor o igual a 0 y menor o igual a %d: ",ll_len(pArrayListEmployee));
            fflush(stdin);
            scanf("%d",&indice);

            while(indice<0 || indice>ll_len(pArrayListEmployee))
            {
                 printf("Ingrese el indice en el que desea agregar al empleado (mayor o igual a 0 y menor o igual a %d: ",ll_len(pArrayListEmployee));
                fflush(stdin);
                scanf("%d",&indice);
            }

            ll_set(pArrayListEmployee,indice,auxEmp);

            controller_saveId(id);

            system("cls");
            printf("Alta exitosa.\n");
            todoOk=1;
            printf("Se ha dado de alta al siguiente empleado en el indice %d: \n\n",indice);
            printf("   Id      Nombre      Horas         Sueldo\n");
            printf("---------------------------------------------\n");
            controller_printAnEmployee(auxEmp);
            printf("\n");

        }
    }
    return todoOk;

}


