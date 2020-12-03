/** \brief Obtener un char (S/N) de confirmacion
 *
 * \param mensajePedir char*
 * \param mensajeError char*
 * \return char Caracter indicado por el usuario (S/N)
 *
 */
char aux_getConfirmacion(char* mensajePedir, char* mensajeError);

/** \brief Obtener una cadena hasta el enter.
 *
 * \param cadena char*
 * \param mensajePedir char*
 * \return int Entero que indica si hubo errores.
 *
 */
int aux_getCadena(char* cadena, char* mensajePedir);

/** \brief Genera un numero entero aleatorio entre minimo y maximo
 *
 * \param minimo int
 * \param maximo int
 * \return int Numero entero aleatorio entre minimo y maximo
 *
 */
int aux_getRandom(int minimo, int maximo);
