#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int menuEmp()
{
    int opcion;
    system("cls");
    printf("--------Menu de opciones ABM--------\n\n");
    printf("1. ALTAS\n");
    printf("2. MODIFICAR\n");
    printf("3. BAJA\n");
    printf("4. INFORMAR\n");
    printf("5. Salir del programa.\n\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);



    return opcion;
}
int formateoNombre(char nombre[])
{
    int i=0;
    int ret=0;
    if(nombre!=NULL&&strlen(nombre)>0)
    {
        ret=1;
        strlwr(nombre);
        nombre[0]=toupper(nombre[0]);
        while(nombre[i]!='\0')
        {
            if(isspace(nombre[i]))
            {
                nombre[i+1]=toupper(nombre[i+1]);
            }
            i++;
        }
    }
    return ret;
}

void mostrarEmpleado(Employee x)
{
    printf("[ID]:        %d \nNOMBRE:      %s \nAPELLIDO:    %s \nSALARIO:     %.2f \nSECTOR:      %d \n",
           x.id,
           x.name,
           x.lastName,
           x.salario,
           x.sector);
    //     x.isEmpty);
}
int mostrarEmpleados(Employee vec[], int tam)
{
    int ret=0;
    if(vec!=NULL&&tam>0)
    {
        ret=1;
        system("cls");
        printf("---------LISTA DE EMPLEADOS---------\n");
        for(int i=0; i<tam; i++)
        {
            if(vec[i].isEmpty==0)
            {
                mostrarEmpleado(vec[i]);
                printf("------------------------------------\n");
            }
        }
    }
    return ret;
}
int initEmployees(Employee vec[], int tam)
{
    int ret=0;
    if(vec!=NULL&&tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            vec[i].isEmpty=1;
        }
        ret=1;
    }
    return ret;
}
int buscarLibre(Employee vec[], int tam)
{
    int libre=-1;
    if(vec!=NULL&&tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(vec[i].isEmpty==1)
            {
                libre=i;
                break;
            }
        }
    }
    return libre;
}
int ingresarStr(char texto[],char* campo,int tam)
{
    int ret=0;
    char auxStr[100];
    if(texto!=NULL&&campo!= NULL&&tam>0)
    {
        printf("Ingrese %s:\n",texto);
        fflush(stdin);
        gets(auxStr);
        while(strlen(auxStr)==0 || strlen(auxStr)>tam)
        {
            printf("Invalido. Reingresar %s:\n",texto);
            fflush(stdin);
            gets(auxStr);
        }
        strcpy(campo, auxStr);
        formateoNombre(campo);
        ret=1;
    }
    return ret;
}
int ingresarIntPos(char texto[],int* campo,int limite)
{
    int ret=0;
    int auxInt;
    if(limite==0)
    {
        limite=2147483647;
    }
    if(texto!=NULL&&campo!=NULL&&limite >(-1))
    {
        printf("Ingrese %s: \n",texto);
        fflush(stdin);
        scanf("%d",&auxInt);
        while(auxInt<0||auxInt>limite)
        {
            printf("Invalido. Reingresar %s.\n",texto);
            fflush(stdin);
            scanf("%d",&auxInt);
        }
        *campo=auxInt;
        ret=1;
    }
    return ret;
}
int ingresarFloatPos(char texto[],float* campo,int limite)
{
    int ret=0;
    float auxFloat;
    if(limite==0)
    {
        limite=2147483647;
    }
    if(texto!=NULL&&campo!=NULL&&limite >(-1) )
    {
        printf("Ingrese %s: \n",texto);
        fflush(stdin);
        scanf("%f",&auxFloat);
        while(auxFloat<0||auxFloat>limite)
        {
            printf("Invalido. Reingresar %s.\n",texto);
            fflush(stdin);
            scanf("%f",&auxFloat);
        }
        *campo=auxFloat;
        ret=1;
    }
    return ret;
}
int addEmployee(Employee* list, int tam, int* nextId)
{
    int ret=0;
    if(list!=NULL&&tam>0&&nextId!=NULL)
    {
        int actualIndex;
        system("cls");
        actualIndex=buscarLibre(list,tam);
        printf("\nEl ID del nuevo usuario es %d.\n",*nextId);
        list[actualIndex].id=(*nextId);
        (*nextId)++;
        system("pause");
        system("cls");
        ingresarStr("nombre",list[actualIndex].name,51);
        ingresarStr("apellido",list[actualIndex].lastName,51);
        ingresarFloatPos("salario",&list[actualIndex].salario,0);
        ingresarIntPos("sector",&list[actualIndex].sector,0);

        list[actualIndex].isEmpty=0;
        printf("\nEmpleado cargado con exito.\n");
        system("pause");
        ret=1;
    }
    return ret;
}
int editEmployee(Employee* list, int tam, int index)
{
    int ret=0;
    if(list!=NULL&&tam>0&&index>-1)
    {
        int opcion;
        printf("------------------------------------\n");
        mostrarEmpleado(list[index]);
        printf("------------------------------------\n");
        printf("Que desea modificar?\n[1]-Nombre\n[2]-Apellido\n[3]-Salario\n[4]-Sector\n");
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            ingresarStr("nombre",list[index].name,51);
            printf("\nNombre cambiado exitosamente. \n");
            system("pause");
            break;
        case 2:
            ingresarStr("apellido",list[index].lastName,51);
            printf("\nApellido cambiado exitosamente. \n");
            system("pause");
            break;
        case 3:
            ingresarFloatPos("salario",&list[index].salario,0);
            printf("\nSalario cambiado exitosamente. \n");
            system("pause");
            break;
        case 4:
            ingresarIntPos("sector",&list[index].sector,0);
            printf("\nSector cambiado exitosamente. \n");
            system("pause");
            break;
        }
        ret=1;
    }
    return ret;
}
int findEmployeeByID(Employee* list, int tam)
{
    int posicion=-1;

    if(list!=NULL&&tam>0)
    {
        int userInput;
        printf("Ingrese ID que desea modificar: ");
        fflush(stdin);
        scanf("%d",&userInput);

        for(int i=0; i<tam; i++)
        {
            if(list[i].isEmpty==1)
            {
                continue;
            }
            else if(list[i].id==userInput)
            {
                posicion=i;
                break;
            }
        }
        if(posicion==(-1))
        {
            printf("No se encontro dicho ID.\t");
            system("pause");
        }
    }
    return posicion;
}
int removeEmployee(Employee* list,int tam, int index)
{
    int ret=0;
    if(list!=NULL && tam>0 && index>(-1))
    {
        char rta;
        ret=1;
        printf("------------------------------------\n");
        mostrarEmpleado(list[index]);
        printf("------------------------------------\n");
        printf("\n Desea eliminar permanentemente este empleado? s/n \n");
        fflush(stdin);
        scanf("%c",&rta);
        if(rta=='s')
        {
            list[index].isEmpty=1;
            strcpy(list[index].name,"");
            strcpy(list[index].lastName,"");
            list[index].sector= 0;
            list[index].salario= 0;

            printf("Empleado eliminado exitosamente.\n");
            system("pause");
        }
        else
        {
            printf("No se eliminara al empleado.\n");
            system("pause");
        }

    }
    return ret;
}
int checkEmpleadoCargado(Employee* list,int tam)
{
    int check=0;
    if(list!= NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(list[i].isEmpty==0)
            {
                check=1;
                return check;
                break;
            }

        }
    }
    return check;
}
int sortEmployees(Employee* list, int tam,int orden)
{
    int ret=0;
    if(list!=NULL&&tam>0&&(orden==1||orden==2))
    {
        Employee aux;
        int ordenado;

        if(orden==2)
        {
            ordenado=-1;
        }
        else
        {
            ordenado=orden;
        }
        int i, j;
        for(i=0; i<tam-1; i++)
        {
            for(j=i+1; j<tam; j++)
            {
                if(list[i].isEmpty==1||list[j].isEmpty==1) // si alguna ubicacion esta vacia, no la somete a comparacion y salta a la siguiente
                {
                    continue;
                }
                else if((strcmp(list[i].lastName,list[j].lastName)==ordenado)||(strcmp(list[i].lastName,list[j].lastName)==0&&
                        list[i].sector>list[j].sector)) // ordena por apellido con el orden dependiendo del usuario (
                {
                    aux=list[i];
                    list[i]=list[j];
                    list[j]=aux;

                }
            }
        }
        ret=1;
    }
    return ret;
}
int promedioSalarios(Employee* list, int tam)
{
    int totalSalarios=0;
    int totalAsalariados=0;
    int promedio;
    int empleadosBienRemunerados=0;
    for(int i=0; i<tam; i++)
    {
        if(list[i].isEmpty==1)
        {
            continue;
        }
        totalSalarios+=list[i].salario;
        totalAsalariados++;
    }
    promedio=totalSalarios/totalAsalariados;
    for(int i=0; i<tam; i++)
    {
        if(list[i].isEmpty==1)
        {
            continue;
        }
        if(list[i].salario>promedio)
        {
            empleadosBienRemunerados++;
        }
    }
    printf("\n SUMA TOTAL DE SUELDOS: $%d\n CANTIDAD DE ASALARIADOS: %d\n\n %d empleados superan el sueldo promedio de $%d.\n\n",totalSalarios,totalAsalariados,empleadosBienRemunerados,promedio);
    return totalAsalariados;
}
int menuInformar(Employee* list,int tam)
{
    int ret=0;
    if(list!=NULL&&tam>0)
    {
        int orden;
        printf("Desea ordenar de forma ascendente (1) o descendente (2)?\n");
        fflush(stdin);
        scanf("%d",&orden);

        sortEmployees(list,tam,orden);
        mostrarEmpleados(list,tam);
        promedioSalarios(list,tam);
        system("pause");
        ret=1;
    }
    return ret;
}
int salirABM()
{
        char rta;
        printf("\nDesea salir del programa? s/n \n");
        fflush(stdin);
        scanf("%c",&rta);
        rta=tolower(rta);
        if(rta=='s')
        {
         return 1;
        }
        else
        {
        return 0;
        }
}
