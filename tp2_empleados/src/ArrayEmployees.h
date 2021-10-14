#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#ifndef MIBIBLIOTECA_H_INCLUDED
#define MIBIBLIOTECA_H_INCLUDED



#endif // MIBIBLIOTECA_H_INCLUDED
typedef struct
    {
     int id;
     char name[51];
     char lastName[51];
     float salario;
     int sector;
     int isEmpty;
    }Employee;


/** \brief imprime un menu con el cual se puede interactuar, orientado a un sistema AMB
 * \return int retorna la opcion elegida por el usuario.
 *
 */
int menuEmp();
/** \brief               formatea nombres y apellidos de forma que queden en minuscula, con unicamente la inicial mayuscula
 *
 * \param nombre[] char  string a formatear
 * \return int           retorna 1 en caso de que la string sea valida, 0 en caso de que no
 *
 */
int formateoNombre(char nombre[]);

/** \brief               imprime en pantalla un empleado y sus respectivos campos, menos isEmpty
 *
 * \param x Employee     empleado a imprimir
 * \return void
 *
 */
void mostrarEmpleado(Employee x);

/** \brief               funcionando en conjunto con mostrarEmpleado(), le envia una lista de empleados para que la misma imprima todos en orden
 *
 * \param vec[] Employee lista de empleados
 * \param tam int        tamaño de la lista
 * \return int           retorna 1 en caso de que los parametros sean validos 0 en caso de que no
 *
 */
int mostrarEmpleados(Employee vec[], int tam);

/** \brief               inicializa la lista de empleados para que funcione de manera logica, es decir, pone todos los espacios en isEmpty == 1 para indicar que estan vacios y disponibles
 *
 * \param vec[] Employee lista de empleados
 * \param tam int        tamaño de la lista
 * \return int           retorna 1 en caso de que los parametros sean validos 0 en caso de que no
 *
 */
int initEmployees(Employee vec[], int tam);

/** \brief               busca en la lista de empleados el primer espacio libre (isEmpty==1)
 *
 * \param vec[] Employee lista de empleados
 * \param tam int        tamaño de la lista
 * \return int           retorna la posicion (index) del espacio libre
 *
 */
int buscarLibre(Employee vec[], int tam);

/** \brief              le pide al usuario un tipo de dato string y lo valida
 *
 * \param texto[] char  seria "lo que se pide" a la hora de pedir dicho dato, por ejemplo, "apellido" hara que la funcion imprima "Ingrese apellido:"
 * \param campo char*   la direccion donde se guardará dicho dato
 * \param tam int       limite del string, si apellido tiene de espacio [20] y el usuario ingresa mas caracteres de la cuenta, le pedira reingreso
 * \return int          retorna 1 en caso de que los parametros sean validos 0 en caso de que no
 *
 */
int ingresarStr(char texto[],char* campo,int tam);

/** \brief              le pide al usuario un tipo de dato int positivo y lo valida
 *
 * \param texto[] char  seria "lo que se pide" a la hora de pedir dicho dato, por ejemplo, "sector" hara que la funcion imprima "Ingrese sector:"
 * \param campo int*    la direccion donde se guardará dicho dato
 * \param limite int    para limitar el largo del dato (para poner un valor maximo)
 * \return int          retorna 1 en caso de que los parametros sean validos 0 en caso de que no
 *
 */
int ingresarIntPos(char texto[],int* campo,int limite);

/** \brief              le pide al usuario un dato de tipo float positivo y lo valida
 *
 * \param texto[] char  seria "lo que se pide" a la hora de pedir dicho dato, por ejemplo, "salario" hara que la funcion imprima "Ingrese salario:"
 * \param campo float*  la direccion donde se guardará dicho dato
 * \param limite int    para limitar el largo del dato (para poner un valor maximo)
 * \return int          retorna 1 en caso de que los parametros sean validos 0 en caso de que no
 *
 */
int ingresarFloatPos(char texto[],float* campo,int limite);

/** \brief                carga un empleado de manera logica, calculando el ID automaticamente y pidiendo los demas campos al usuario
 *
 * \param list Employee*  lista de empleados
 * \param tam int         tamaño de la lista
 * \param nextId int*     ubicacion del valor de ID que tiene que utilizar para despues sumarle 1, dejandolo preparado para la proxima carga
 * \return int            retorna 1 en caso de que los parametros sean validos y pueda cargar con exito 0 en caso de que no
 *
 */
int addEmployee(Employee* list, int tam, int* nextId);

/** \brief                permite modificar algun campo dentro de un empleado (nombre apellido salario sector)
 *
 * \param list Employee*  lista de empleados
 * \param tam int         tamaño de la lista
 * \param index int       indice del empleado a modificar
 * \return int            retorna 1 en caso de que los parametros sean validos, 0 en caso de que no
 *
 */
int editEmployee(Employee* list, int tam, int index);

/** \brief                permite averiguar el index de un empleado dentro de la lista, utilizando como parametro de busqueda su ID
 *
 * \param list Employee*  lista de empleados
 * \param tam int         tamaño de la lista
 * \return int            retorna la posicion de la lista donde se encuentra el empleado con dicho ID
 *
 */
int findEmployeeByID(Employee* list, int tam);

/** \brief                le da de baja a un empleado de manera logica (isEmpty == 1)
 *
 * \param list Employee*  lista de empleados
 * \param tam int         tamaño de la lista
 * \param index int       index del empleado a dar de baja
 * \return int            retorna 1 en caso de que los parametros sean validos, 0 en caso de que no
 *
 */
int  removeEmployee(Employee* list,int tam, int index);

/** \brief                es una bandera dinamica, retornara 1 en caso de que haya al menos un empleado ingresado
 *
 * \param list Employee*  lista de empleados
 * \param tam int         tamaño de la lista
 * \return int            retorna 1 si hay un empleado cargado (isEmpty==0) o 0 si no hay ninguno.
 *
 */
int checkEmpleadoCargado(Employee* list,int tam);

/** \brief                ordena la lista de empleados utilizando el orden pedido por menuInformar()
 *
 * \param list Employee*  lista de empleados
 * \param tam int         tamaño de la lista
 * \param orden int       criterio de ordenamiento
 * \return int            retorna 1 en caso de que los parametros sean validos, 0 en caso de que no
 *
 */
int sortEmployees(Employee* list, int tam,int orden);

/** \brief                calcula la suma de todos los salarios, personas asalariadas, promedio de salario y cantidad de personas que superen ese promedio
 *
 * \param list Employee*  lista de empleados
 * \param tam int         tamaño de la lista
 * \return int            retorna 1 en caso de que los parametros sean validos, 0 en caso de que no
 *
 */
int promedioSalarios(Employee* list, int tam);

/** \brief                es el menu que aparece a la hora de seleccionar 'INFORMAR'  y le pide al usuario el criterio de ordenamiento
 *
 * \param list Employee*  lista de empleados
 * \param tam int         tamaño de la lista
 * \return int            retorna 1 en caso de que los parametros sean validos, 0 en caso de que no
 *
 */
int menuInformar(Employee* list,int tam);

/** \brief                le pide confirmacion al usuario para salir del programa
 *
 * \return int            retorna 1 en caso de querer salir, 0 en caso de que no
 *
 */
int salirABM();

