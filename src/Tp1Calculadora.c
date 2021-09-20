/*
 ============================================================================
 Name        : Tp1Calculadora.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "miBiblioteca.h"

int main(void) {
	        setbuf(stdout, NULL);
	        int opcion;
		    int flagOp1=0;
		    int flagOp2=0;
		    int primerNum=0;
		    int segundoNum=0;
		    int iterador=1;
		    int resultado1;
		    int resultado2;
		    float resultado3;
		    int resultado4;
		    int resultado5;
		    int resultado6;
		    int flagCalc=0;
		    char confSalir;

		    while(iterador==1)
		    {

		    opcion= menuCalc();

		        switch(opcion)
		            {
		                case 1:
		                    printf("\nIngrese el primer operando (valor actual: %d): ", primerNum);
		                    fflush(stdin);
		                    scanf("%d", &primerNum);
		                    setFlag(&flagOp1, 1);
		                    break;

		                case 2:
		                    printf("\nIngrese el segundo operando (valor actual: %d): ", segundoNum);
		                    fflush(stdin);
		                    scanf("%d", &segundoNum);
		                    if(segundoNum==0)
		                    {
		                        printf("\nRecuerde que si su operando es 0, no podra realizar la division satisfactoriamente.\n");
		                        system("pause");
		                    }
		                    setFlag(&flagOp2, 1);
		                    break;

		                case 3:
		                    if( (flagOp1+flagOp2)==2 )
		                    {
		                        int errores=6;
		                        errores-=sumar(primerNum,segundoNum,&resultado1);
		                        errores-=restar(primerNum,segundoNum, &resultado2);
		                        errores-=division(primerNum,segundoNum, &resultado3);
		                        errores-= multiplicacion(primerNum,segundoNum, &resultado4);
		                        errores-=factorial(primerNum, &resultado5);
		                        errores-=factorial(segundoNum, &resultado6);
		                        printf("\nSe realizaron las operaciones con un total de %d errores.\n\n.",errores);
		                        flagCalc=1;

		                        system("pause");
		                        break;
		                    }
		                    else
		                    {
		                        printf("\nNo ingreso los operadores necesarios, intentelo de nuevo.\n\n");
		                        system("pause");
		                        break;
		                    }
		                case 4:
		                    if(flagCalc==1)
		                    {
		                        printf("\n%10d --- Primer numero\n%10d --- Segundo numero\n%10d --- Suma de ambos numeros\n%10d --- Resta de ambos numeros\n%10.2f --- El producto de la division\n%10d --- El producto de la multiplicacion\n%10d --- Factorial del primer numero\n%10d --- Factorial del segundo numero\n\n",primerNum,segundoNum,resultado1,resultado2,resultado3,resultado4,resultado5,resultado6);
		                        system("pause");
		                        break;
		                    }
		                    else
		                        {
		                            printf("\nIngrese primero los operandos y realice las operaciones.\n\n");
		                            system("pause");
		                            break;
		                        }
		                case 5:
		                     printf("\n¿Seguro que desea salir? (S/N)\n");
		                     fflush(stdin);
		                     scanf("%c", &confSalir);
		                     confSalir=tolower(confSalir);
		                     if(confSalir=='s')
		                     {
		                         printf("\n\n Nos vemos!\n");
		                         iterador=0;
		                         break;
		                     }
		                     else
		                     {
		                            break;
		                     }
		                default:
		                    printf("\nOpcion invalida.\n");
		                    system("pause");
		                    break;

		            }


		    }



		    return 0;
}
