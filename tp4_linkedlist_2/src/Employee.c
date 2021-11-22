#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "../inc/LinkedList.h"

#include "Employee.h"



/** \brief Crea un nuevo empleado, inicializando sus campos en 0
 *
 * \return Employee* retorna un puntero a empleado, o NULL en caso de error
 *
 */
Employee* employee_new()
{
    Employee* nuevoEmpleado;

    nuevoEmpleado = (Employee*) malloc(sizeof(Employee));

    if(nuevoEmpleado!=NULL)
    {
        nuevoEmpleado->id=0;

        strcpy(nuevoEmpleado->nombre,"nn");

        nuevoEmpleado->horasTrabajadas=0;

        nuevoEmpleado->sueldo=0;


    }

    return nuevoEmpleado;
}



/** \brief Borra un empleado , liberando su espacio de memoria
 *
 * \param this Employee*
 * \return void
 *
 */
void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }

}





/** \brief Crea una nueva estructura empleado, validando los campos ingresados y devuelve un puntero al empleado
 *
 * \param idStr char* campo id en forma de string
 * \param nombreStr char* campo nombre
 * \param horasTrabajadasStr char* campo horas en forma de string
 * \param sueldoStr char* campo sueldo en forma de string
 * \return Employee* puntero al empleado en caso de haberlo cargado, NULL en caso de error.
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{

    Employee* nuevoEmpleado;

    nuevoEmpleado = employee_new();

    if(nuevoEmpleado!=NULL)
    {
        if( !(employee_setId(nuevoEmpleado, atoi(idStr)) &&
                employee_setNombre(nuevoEmpleado, nombreStr) &&
                employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr)) &&
                employee_setSueldo(nuevoEmpleado, atoi(sueldoStr)))

          )
        {
            free(nuevoEmpleado);
            nuevoEmpleado=NULL;


        }



    }

    return nuevoEmpleado;

}

//getters y setters

/** \brief Valida que el id ingresado sea valido, y en el caso de ser valido lo carga en el campo id del empleado
 *
 * \param this Employee* empleado
 * \param id int valor a ser validado y cargado
 * \return int int devuelve 1 en caso de exito, 0 en caso de error
 *
 */
int employee_setId(Employee* this,int id)
{
    int todoOk=0;

    if(this != NULL && id>=1)
    {
        this->id = id;
        todoOk=1;
    }


    return todoOk;




}




/** \brief Carga el valor del campo id del empleado por referencia en la direccion de memoria recibida
 *
 * \param this Employee* empleado
 * \param id int* direccion de memoria donde se guardara el valor del campo
 * \return int devuelve 1 en caso de exito, 0 en caso de error
 *
 */
int employee_getId(Employee* this,int* id)
{
    int todoOk=0;

    if(this != NULL && id!= NULL)
    {
        *id = this->id;
        todoOk=1;
    }


    return todoOk;
}



/** \brief Valida que el nombre ingresado sea valido, y en el caso de ser valido lo carga en el campo nombre del empleado
 *
 * \param this Employee* empleado
 * \param nombre int valor a ser validado y cargado
 * \return int int devuelve 1 en caso de exito, 0 en caso de error
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk=0;

    if(this != NULL && nombre!=NULL)
    {

        if(strlen(nombre)<127)
        {
            strcpy(this->nombre,nombre);
            todoOk=1;
        }

    }


    return todoOk;
}


/** \brief Carga el valor del campo nombre del empleado por referencia en la direccion de memoria recibida
 *
 * \param this Employee* empleado
 * \param nombre int* direccion de memoria donde se guardara el valor del campo
 * \return int devuelve 1 en caso de exito, 0 en caso de error
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk=0;

    if(this != NULL && nombre!= NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk=1;
    }


    return todoOk;
}

/** \brief Valida que las horas trabajadas ingresadas sean validas, y en el caso de ser validas las carga en el campo horasTrabajadas del empleado
 *
 * \param this Employee* empleado
 * \param horasTrabajadas int valor a ser validado y cargado
 * \return int int devuelve 1 en caso de exito, 0 en caso de error
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk=0;

    if(this != NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas= horasTrabajadas;
        todoOk=1;
    }


    return todoOk;
}




/** \brief Carga el valor del campo horasTrabajadas del empleado por referencia en la direccion de memoria recibida
 *
 * \param this Employee* empleado
 * \param horasTrabajadas int* direccion de memoria donde se guardara el valor del campo
 * \return int devuelve 1 en caso de exito, 0 en caso de error
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk=0;

    if(this != NULL && horasTrabajadas!= NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk=1;
    }


    return todoOk;


}

/** \brief Valida que el sueldo ingresado sea valido, y en el caso de ser valido lo carga en el campo sueldo del empleado
 *
 * \param this Employee* empleado
 * \param sueldo int valor a ser validado y cargado
 * \return int int devuelve 1 en caso de exito, 0 en caso de error
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk=0;

    if(this != NULL && sueldo>0 && sueldo<=100000)
    {
        this->sueldo= sueldo;
        todoOk=1;
    }


    return todoOk;
}



/** \brief Carga el valor del campo sueldo del empleado por referencia en la direccion de memoria recibida
 *
 * \param this Employee* empleado
 * \param sueldo int* direccion de memoria donde se guardara el valor del campo
 * \return int devuelve 1 en caso de exito, 0 en caso de error
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk=0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk=1;
    }


    return todoOk;


}


/**
 * @brief Compara el Id de 2 empleados para ser ordenados.
 *
 * @param emp1 void*
 * @param emp2 void*
 * @return (0) en caso de que sean iguales y (1/-1) en caso de haber ordenamiento.
 */
int employee_ordenarId(void* emp1, void* emp2)
{
    int ordenamiento = 0;
    int id1;
    int id2;

    employee_getId(emp1, &id1);
    employee_getId(emp2, &id2);

    if(id1 > id2)
    {
        ordenamiento = 1;
    }
    else if(id1 < id2)
    {
        ordenamiento = -1;
    }

    return ordenamiento;
}



/**
 * @brief Compara el nombre de 2 empleados para que sean ordenados.
 *
 * @param emp1 void*
 * @param emp2 void*
 * @return (0) en caso de que sean iguales y (1/-1) en caso de haber ordenamiento.
 */
int employee_ordenarNombres(void* emp1, void* emp2)
{

    int ordenamiento = 0;
    char nombre1[128];
    char nombre2[128];

    employee_getNombre(emp1, nombre1);
    employee_getNombre(emp2, nombre2);

    if(strcmp(nombre1, nombre2) > 0)
    {
        ordenamiento = 1;
    }
    else if(strcmp(nombre1, nombre2) < 0)
    {
        ordenamiento = -1;
    }

    return ordenamiento;


}




/**
 * @brief Compara las horas trabajadas de 2 empleados para que sean ordenados.
 *
 * @param emp1 void*
 * @param emp2 void*
 * @return (0) en caso de que sean iguales y (1/-1) en caso de haber ordenamiento.
 */
int employee_ordenarHorasTrabajadas(void* emp1, void* emp2)
{
    int ordenamiento = 0;
    int hora1;
    int hora2;

    employee_getHorasTrabajadas(emp1, &hora1);
    employee_getHorasTrabajadas(emp2, &hora2);

    if(hora1 > hora2)
    {
        ordenamiento = 1;
    }
    else if(hora1 < hora2)
    {
        ordenamiento = -1;
    }


    return ordenamiento;



}



/**
 * @brief Compara el salario de 2 empleados para que sean ordenados.
 *
 * @param emp1
 * @param emp2
 * @return (0) en caso de error y (1/-1) en caso de haber criterio de ordenamiento .
 */
int employee_ordenarSueldos(void* emp1, void* emp2)
{
    int ordenamiento = 0;
    int salario1;
    int salario2;

    employee_getSueldo(emp1, &salario1);
    employee_getSueldo(emp2, &salario2);

    if(salario1 > salario2)
    {
        ordenamiento = 1;
    }
    else if(salario1 < salario2)
    {
        ordenamiento = -1;
    }
    return ordenamiento;



}

int employee_filterSueldo(void* pElement)
{
    return ((Employee*)pElement)->sueldo>20000;



}












