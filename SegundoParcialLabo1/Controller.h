#include "LinkedList.h"

/** \brief Carga los datos de los paises desde el archivo path (modo texto).
 *
 * \param path char*
 * \param pArrayListePais LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListePais);

/** \brief Listar paises
 *
 * \param pArrayListePais LinkedList*
 * \return int
 *
 */
int controller_ListePais(LinkedList* pArrayListePais);

/** \brief Guarda los datos de los paises en el archivo path (modo texto).
 *
 * \param path char*
 * \param pArrayListePais LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListePais);

/** \brief Lista el o los paises mas castigados (con mayor cantidad de muertos)
 *
 * \param pArrayListePais LinkedList*
 * \return void
 *
 */
void controller_getMasCastigados(LinkedList* pArrayListePais);

/** \brief Retorna la mayor cantidad de muertos existente en pArrayListePais
 *
 * \param pArrayListePais LinkedList*
 * \return int
 *
 */
int getMayorCantidadDeMuertos(LinkedList* pArrayListePais);

/** \brief Setea valores random en los campos: infectados, muertos, recuperados de cada pais en pArrayListePais
 *
 * \param pArrayListePais LinkedList*
 * \return void
 *
 */
void controller_MapePais(LinkedList* pArrayListePais);

/** \brief Filtra pArrayListePais por los paises mas exitosos, los muestra, y los guarda en un archivo paisesExitosos.csv
 *
 * \param pArrayListePais LinkedList*
 * \return void
 *
 */
void controller_FilterAndSavePaisesExitosos(LinkedList* pArrayListePais);

/** \brief Filtra pArrayListePais por los paises en el horno, los muestra, y los guarda en un archivo paisesEnElHorno.csv
 *
 * \param pArrayListePais LinkedList*
 * \return void
 *
 */
void controller_FilterAndSavePaisesEnElHorno(LinkedList* pArrayListePais);
