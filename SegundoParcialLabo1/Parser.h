/** \brief Parsea los datos de los paises desde el archivo pFile (modo texto).
 *
 * \param FILE* pFile
 * \param pArrayListePais LinkedList*
 * \return int
 *
 */
int parser_ePaisFromText(FILE* pFile , LinkedList* pArrayListePais);

/** \brief Guarda los datos de los paises en el archivo pFile (modo texto).
 *
 * \param pFile FILE*
 * \param pArrayListePais LinkedList*
 * \return int
 *
 */
int parser_saveePaisAsText(FILE* pFile , LinkedList* pArrayListePais);
