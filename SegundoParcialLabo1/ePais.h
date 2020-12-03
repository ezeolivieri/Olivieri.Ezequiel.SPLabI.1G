#ifndef EPAIS_H_INCLUDED
#define EPAIS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int recuperados;
    int infectados;
    int muertos;
} ePais;

ePais* ePais_new();
ePais* ePais_newParametros(char* id, char* name, char* recuperados, char* infectados, char* muertos);
void ePais_delete(ePais* this);

// GETTERS Y SETTERS
int ePais_setId(ePais* this,int id);
int ePais_getId(ePais* this,int* id);
int ePais_setNombre(ePais* this,char* nombre);
int ePais_getNombre(ePais* this,char* nombre);
int ePais_setRecuperados(ePais* this,int recuperados);
int ePais_getRecuperados(ePais* this,int* recuperados);
int ePais_setInfectados(ePais* this,int infectados);
int ePais_getInfectados(ePais* this,int* infectados);
int ePais_setMuertos(ePais* this,int muertos);
int ePais_getMuertos(ePais* this,int* muertos);

int printePais(ePais* ePais);


/** \brief Setea los campos: muertos, infectados y recuperados de pePais con valores aleatorios
 *
 * \param pePais void*
 * \return void*
 *
 */
void* ePais_setRandomValues(void* pePais);

/** \brief Retorna 1 si es un pais exitoso o 0 si no lo es
 *
 * \param pePais void*
 * \return int
 *
 */
int ePais_getPaisExitoso(void* pePais);

/** \brief Retorna 1 si es un pais en el horno o 0 si no lo es
 *
 * \param pePais void*
 * \return int
 *
 */
int ePais_getPaisEnElHorno(void* pePais);

/** \brief Retorna el pais con mas infectados
 *
 * \param pePaisUno void*
 * \param pePaisDos void*
 * \return int
 *
 */
int ePais_sortByInfected(void* pePaisUno, void* pePaisDos);

#endif // EPAIS_H_INCLUDED
