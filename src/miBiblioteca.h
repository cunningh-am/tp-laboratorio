#include <stdio.h>
#include <stdlib.h>
#ifndef MIBIBLIOTECA_H_INCLUDED
#define MIBIBLIOTECA_H_INCLUDED



#endif // MIBIBLIOTECA_H_INCLUDED

/** \brief Promedia dos numeros
 *
 * \param x int primer numero ingresado
 * \param y int segundo numero ingresado
 * \return float devuelve promedio
 *
 */
float promediar(int x, int y);

/** \brief imprime un menu con el cual se puede interactuar
 *
 * \return int
 *
 */
int menu();

/** \brief imprime un menu con el cual se puede interactuar, orientado a una calculadora de 2 operandos.
 *
 * \return int retorna la opcion elegida por el usuario.
 *
 */
int menuCalc();

/** \brief Hace pasaje por referencia para modificar una variable, en este caso enfocado a banderas.
 *
 * \param bandera int* | la direccion de memoria de la variable a modificar
 * \param valor int | el valor deseado
 * \return void
 *
 */
void setFlag(int* bandera, int valor);

/** \brief intercambia el valor de dos variables (por referencia)
 *
 * \param x int* primer referencia
 * \param y int* segunda referencia
 * \return void
 *
 */
void swap(int* x, int* y);
/** \brief Suma dos variables por valor y almacena el resultado en una direccion de memoria
 *
 * \param x int primer valor
 * \param y int segundo valor
 * \param resultado int* direccion de memoria
 * \return int retorna 0 en caso de no poder (direccion de memoria erronea), 1 en caso de poder
 *
 */
int sumar(int x,int y, int* resultado);

/** \brief resta dos variables usando sus valores, y escribe el resultado en una direccion de memoria
 *
 * \param x int
 * \param y int
 * \param resultado int*
 * \return int retorna 0 en caso de que la direccion sea erronea.
 *
 */
int restar(int x, int y, int* resultado);

/** \brief divide la primer variable por la segunda variable, y escribe el reusltado en una direccion de memoria
 *
 * \param x int
 * \param y int
 * \param resultado int*
 * \return int retorna un 0 en caso de que la direccion sea erronea
 *
 */
int division(int x, int y, float* resultado);

/** \brief multiplica el valor de la primer variable por la segunda, y escribe el resultado en una direccion de memoria
 *
 * \param x int
 * \param y int
 * \param resultado int*
 * \return int retorna 0 en caso de que la direccion sea erronea
 *
 */
 int multiplicacion(int x, int y, int* resultado);

 /** \brief calcula el factorial de un numero y escribe el resultado en una direccion de memoria
  *
  * \param x int
  * \param resultado int*
  * \return int retorna 0 en caso de que la direccion sea erronea o no se pueda calcular el factorial
  *
  */
 int factorial(int x, int* resultado);
