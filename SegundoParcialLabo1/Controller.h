#include "LinkedList.h"

int controller_loadFromText(char* path , LinkedList* pArrayListePais);
int controller_ListePais(LinkedList* pArrayListePais);
int controller_saveAsText(char* path , LinkedList* pArrayListePais);

/** \brief Genera un numero entero aleatorio entre minimo y maximo
 *
 * \param minimo int
 * \param maximo int
 * \return int Numero entero aleatorio entre minimo y maximo
 *
 */
int getRandom(int minimo, int maximo);

void controller_getMasCastigados(LinkedList* pArrayListePais);
int mayorCantidadDeMuertos(LinkedList* pArrayListePais);
