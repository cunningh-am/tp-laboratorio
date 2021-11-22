#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"

#include "Employee.h"
#include "parser.h"
#include "Controller.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    Employee* auxEmpleado = NULL;
    char buffer[3][5];
    char auxNombre[128];


    if(pFile != NULL && pArrayListEmployee != NULL )
    {

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n",buffer[0],auxNombre,buffer[1],buffer[2]);
        do
        {


            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n",buffer[0],auxNombre,buffer[1],buffer[2])<4)
            {
                break;
            }



            auxEmpleado = employee_newParametros(buffer[0],auxNombre,buffer[1],buffer[2]);

            if(auxEmpleado!=NULL)
            {

                ll_add(pArrayListEmployee, auxEmpleado);
                todoOk=1;

            }
            else
            {
                break;
            }


        }
        while(!feof(pFile));

        controller_saveId(atoi(buffer[0])); //guardo el ultimo id

    }

    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{


    int todoOk = 0;
    int id;
	Employee* auxEmp = NULL;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do {
			auxEmp = employee_new();

			if(fread(auxEmp ,sizeof(Employee), 1, pFile)==1)
			{

				ll_add(pArrayListEmployee, auxEmp);
                id=auxEmp->id;
				todoOk = 1;
			}


		} while (!feof(pFile));

		 controller_saveId(id); //guardo el ultimo id

	}
    return todoOk;

}









