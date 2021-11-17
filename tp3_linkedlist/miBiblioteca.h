#ifndef MIBIBLIOTECA_H_INCLUDED
#define MIBIBLIOTECA_H_INCLUDED

/** \brief          es un menu enfocado a un ABM de bicicletas
 *
 * \return int      retorna un numero ingresado por el usuario para crear un menu dinamico en main utilizando un switch con un case que corresponda a cada opcion
 *
 */
int menu();

/** \brief              permite ingresar un int positivo y valida que este dentro de un rango delimitado, luego lo envia a guardar a un campo por direccion de memoria
 *
 * \param texto[] char  en este parametro va una string donde se le avisa al usuario lo que se le esta pidiendo, si se ingresa "salario" le pedira "ingrese salario: "
 * \param campo int*    es el destino donde se almacenara el dato
 * \param minimo int    es el minimo aceptado (es decir, se incluye a si mismo) dentro del rango deseado
 * \param limite int    es el maximo aceptado (es decir, se incluye a si mismo) dentro del rango deseado
 * \return int          retorna 0 en caso de que la validacion de parametros sea erronea, 1 en caso de que todo este bien
 *
 */
int ingresarIntPos(char texto[],int* campo,int minimo,int limite);

/** \brief               permite ingresar un string y valida que el mismo no exceda el tamaño de su futuro destino, luego lo envia a guardar ese destino por direccion de memoria
 *
 * \param texto[] char   lo que se le pide al usuario, si este parametro es "nombre", el usuario vera "Ingrese nombre: "
 * \param campo char*    destino, por referencia de memoria, donde se almacenara el dato
 * \param tam int        tamaño del destino que no puede ser excedido
 * \return int           retorna 0 en caso de que la validacion de parametros sea erronea, 1 en caso de que todo este bien
 *
 */
int ingresarStr(char texto[],char* campo,int tam);
/** \brief              funcion para salir de un abm, que pide confirmacion al usuario
 *
 * \return int          retorna 1 en caso de que realmente quiera salir, 0 en caso de que se arrepienta.
 *
 */
int salirABM();
/** \brief      submenu que imprime en pantalla las opciones sobre informes
 *
 * \return int  retorna el numero elegido por usuario
 *
 */
int submenu();

#endif // MIBIBLIOTECA_H_INCLUDED
