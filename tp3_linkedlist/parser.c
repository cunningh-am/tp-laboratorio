#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int ret=0;
    char buffer[2][5];
    char auxNombre[128];

    if(pFile != NULL && pArrayListEmployee !=NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], auxNombre, buffer[1], buffer[2]);
        do
        {
            if((fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], auxNombre, buffer[1], buffer[2]))==4)
            {
                auxEmployee=employee_newParametros(buffer[0],auxNombre,buffer[1],buffer[2]);
                if(auxEmployee!=NULL)
                {
                    ll_add(pArrayListEmployee,auxEmployee);
                    ret=1;
                }

            }



        }
        while(!feof(pFile));
    }

    return ret;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int ret=1;
    Employee* auxEmployee;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        do
        {
            auxEmployee=employee_new();
            fread(auxEmployee, sizeof(Employee), 1, pFile);

            if(!feof(pFile))
            {
                if(ll_add(pArrayListEmployee, auxEmployee)!=0)
                {
                    employee_delete(auxEmployee);
                    ret=1;
                    break;
                }
                else
                {
                    ret=0;
                }
            }
            else
            {
                break;
            }
        }
        while(!feof(pFile));

    }
    return ret;
}
/** \brief  Parsea el numero de id de un archivo .csv
 *
 * \param pFile FILE*
 * \param pId int*
 * \return int
 *
 */
int parser_IdFromText(FILE* pFile, int* pId)
{

    int ret=0;
    char stringID[5];


    if(pFile != NULL && pId !=NULL)
    {
        fscanf(pFile, "%s",stringID);
        *pId=atoi(stringID);
        ret=1;

    }

    return ret;
}
