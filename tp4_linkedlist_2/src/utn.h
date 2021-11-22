
#ifndef UTN_H_
#define UTN_H_

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[]);


/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);




/**
 * \brief Verifica si el valor recibido contiene solo numeros
 * \param num int campo a ser analizado
 * \return 1 si contiene solo numeros y 0 si no los tiene.
 *
 */
int esSoloNumerico(int num);


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);




/** \brief muestra el mensaje recibido por parametro y valida que el usuario ingrese 's' o 'n' para confirmar
 *
 * \param mensaje[] char mensaje que se mostrara al usuario
 * \param rta char* variable donde se cargara la respuesta
 * \return void
 *
 */
void getConfirmacion(char mensaje[], char* rta);



/** \brief imprime en pantalla el menu principal y captura la eleccion del usuario
 *
 * \return int devuelve la eleccion del usuario
 *
 */
int menu();



/** \brief imprime en pantalla el submenu de modificar y capta la eleccion del usuario
 *
 * \return int retorna la eleccion
 *
 */
int subMenu();



/** \brief imprime en pantalla el submenu de ordenamientos y capta la eleccion del usuario
 *
 * \return int
 *
 */
int menuOrdenar();


/** \brief imprime en pantalla el submenu de criterios de ordenamiento y capta la eleccion del usuario
 *
 * \return int
 *
 */
int menuCriterio();


#endif /* UTN_H_ */
