#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "miBiblioteca.h"

Employee* employee_new()
{
	Employee* newEmployee;

	newEmployee=(Employee*)malloc(sizeof(Employee));
	if(newEmployee!=NULL)
	{
		newEmployee->id=0;
		strcpy(newEmployee->nombre,"-");
		newEmployee->horasTrabajadas=0;
		newEmployee->sueldo=0;
	}

	return newEmployee;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmployee;

	newEmployee=employee_new();

	if(newEmployee!=NULL)
	{
		if((employee_setId(newEmployee, atoi(idStr))
				|| employee_setNombre(newEmployee, nombreStr)
				|| employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr))
				|| employee_setSueldo(newEmployee, atoi(sueldoStr))))
		{
			employee_delete(newEmployee);
			newEmployee=NULL;
		}
	}

	return newEmployee;
}

void employee_delete(Employee* anEmployee)
{
    if(anEmployee!=NULL)
    {
        free(anEmployee);
    }
}

int employee_setId(Employee* anEmployee, int id)
{
	int error=1;

	if(anEmployee!=NULL && id>0)
	{
		anEmployee->id=id;
		error=0;
	}
	return error;
}
int employee_getId(Employee* anEmployee, int* id)
{
	int error=1;

	if(anEmployee!=NULL && id!=NULL)
	{
		*id=anEmployee->id;
		error=0;
	}
	return error;
}

int employee_setNombre(Employee* anEmployee, char nombre[])
{
    int error=1;

	if(anEmployee!=NULL && nombre!=NULL)
	{
        if(strlen(nombre)<128 && strlen(nombre)>1)
        {
            strcpy(anEmployee->nombre, nombre);
        }
		error=0;
	}
	return error;
}

int employee_getNombre(Employee* anEmployee, char* nombre)
{
    int error=1;
	if(anEmployee!=NULL && nombre!=NULL)
	{
		strcpy(nombre, anEmployee->nombre);
		error=0;
	}
	return error;
}

int employee_setHorasTrabajadas(Employee* anEmployee,int horasTrabajadas)
{
    int error=1;

	if(anEmployee!=NULL && horasTrabajadas>0 && horasTrabajadas<=350)
	{
		anEmployee->horasTrabajadas=horasTrabajadas;
		error=0;
	}
	return error;
}

int employee_getHorasTrabajadas(Employee* anEmployee,int* horasTrabajadas)
{
    int error=1;

    if(anEmployee!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=anEmployee->horasTrabajadas;
        error=0;
    }
    return error;
}

int employee_setSueldo(Employee* anEmployee, int sueldo)
{
    int error=1;

	if(anEmployee!=NULL && sueldo>0 && sueldo<=100000)
	{
		anEmployee->sueldo=sueldo;
		error=0;
	}
	return error;
}

int employee_getSueldo(Employee* anEmployee, int* sueldo)
{
    int error=1;

    if(anEmployee!=NULL && sueldo!=NULL)
    {
        *sueldo=anEmployee->sueldo;
        error=0;
    }
    return error;
}

int employee_sortById(void* employee1, void* employee2)
{
	int retorno=0;
	Employee* aux1=(Employee*) employee1;
	Employee* aux2=(Employee*) employee2;
	int id1;
	int id2;

	if(employee1!=NULL && employee2!=NULL)
	{
		employee_getId(aux1, &id1);
		employee_getId(aux2, &id2);

		if(id1>id2)
        {
			retorno=1;
		}
		else if(id1<id2)
		{
            retorno=-1;
        }
	}
	return retorno;
}

int employee_sortByName(void* employee1, void* employee2)
{
    int retorno=1;
    Employee* aux1=(Employee*) employee1;
    Employee* aux2=(Employee*) employee2;
    char nombre1[128];
    char nombre2[128];

    if(employee1!=NULL && employee2!=NULL)
    {
        employee_getNombre(aux1, nombre1);
		employee_getNombre(aux2, nombre2);

		retorno=strcmp(nombre1, nombre2);

        if(retorno>0)
		{
			retorno=1;
		}
		else if(retorno<0)
        {
            retorno=-1;
        }
    }

    return retorno;
}

int employee_sortByHours(void* employee1, void* employee2)
{
	int retorno=0;
	Employee* aux1=(Employee*) employee1;
	Employee* aux2=(Employee*) employee2;
	int horas1;
	int horas2;

	if(employee1!=NULL && employee2!=NULL)
	{
		employee_getHorasTrabajadas(aux1, &horas1);
		employee_getHorasTrabajadas(aux2, &horas2);

        if(horas1>horas2)
        {
            retorno=1;
        }
        else if(horas1<horas2)
        {
            retorno=-1;
        }
	}
	return retorno;
}

int employee_sortBySalary(void* employee1, void* employee2)
{
	int retorno=0;
	Employee* aux1=(Employee*) employee1;
	Employee* aux2=(Employee*) employee2;
	int sueldo1;
	int sueldo2;

	if(employee1!=NULL && employee2!=NULL)
	{
		employee_getSueldo(aux1, &sueldo1);
		employee_getSueldo(aux2, &sueldo2);

        if(sueldo1>sueldo2)
        {
            retorno=1;
        }
        else if(sueldo1<sueldo2)
        {
            retorno=-1;
        }
	}
	return retorno;
}
