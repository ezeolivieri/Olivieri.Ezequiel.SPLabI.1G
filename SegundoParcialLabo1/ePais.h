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

void* ePais_setRandomValues(void* pePais);
int ePais_getPaisExitoso(void* pePais);
int ePais_getPaisEnElHorno(void* pePais);

int ePais_sortByInfected(void* pePaisUno, void* pePaisDos);

#endif // EPAIS_H_INCLUDED
