#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ePais.h"
#include "Controller.h"
#include "aux.h"

ePais* ePais_new()
{
    ePais* nuevoPais = (ePais*) malloc(sizeof(ePais));

    if( nuevoPais != NULL )
    {
        ePais_setId(nuevoPais, 0);
        ePais_setNombre(nuevoPais, "-");
        ePais_setRecuperados(nuevoPais, 0);
        ePais_setInfectados(nuevoPais, 0);
        ePais_setMuertos(nuevoPais, 0);
    }

    return nuevoPais;
}

ePais* ePais_newParametros(char* id, char* name, char* recuperados, char* infectados, char* muertos)
{
    ePais* nuevoPais = ePais_new();

    if( nuevoPais != NULL )
    {
        if( !( ePais_setId(nuevoPais, atoi(id)) &&
               ePais_setNombre(nuevoPais, name) &&
               ePais_setRecuperados(nuevoPais, atoi(recuperados)) &&
               ePais_setInfectados(nuevoPais, atoi(infectados)) &&
               ePais_setMuertos(nuevoPais, atoi(muertos)) ) )
        {
            ePais_delete(nuevoPais);
        }

        ePais_setId(nuevoPais, atoi(id));
        ePais_setNombre(nuevoPais, name);
        ePais_setRecuperados(nuevoPais, atoi(recuperados));
        ePais_setInfectados(nuevoPais, atoi(infectados));
        ePais_setMuertos(nuevoPais, atoi(muertos));
    }

    return nuevoPais;
}

void ePais_delete(ePais* this)
{
    free( this );
}

int ePais_setId(ePais* this,int id)
{
    int todoOk = 0;

    if( this != NULL )
    {
        this->id = id;
        todoOk = 1;
    }

    return todoOk;
}
int ePais_getId(ePais* this,int* id)
{
    int todoOk = 0;

    if( this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }

    return todoOk;
}

int ePais_setNombre(ePais* this,char* nombre)
{
    int todoOk = 0;

    if( this != NULL && nombre != NULL )
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;
}
int ePais_getNombre(ePais* this,char* nombre)
{
    int todoOk = 0;

    if( this != NULL && nombre != NULL )
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }

    return todoOk;
}

int ePais_setRecuperados(ePais* this,int recuperados)
{
    int todoOk = 0;

    if( this != NULL )
    {
        this->recuperados = recuperados;
        todoOk = 1;
    }

    return todoOk;
}
int ePais_getRecuperados(ePais* this,int* recuperados)
{
    int todoOk = 0;

    if( this != NULL && recuperados != NULL)
    {
        *recuperados = this->recuperados;
        todoOk = 1;
    }

    return todoOk;
}

int ePais_setInfectados(ePais* this,int infectados)
{
    int todoOk = 0;

    if( this != NULL )
    {
        this->infectados = infectados;
        todoOk = 1;
    }

    return todoOk;
}
int ePais_getInfectados(ePais* this,int* infectados)
{
    int todoOk = 0;

    if( this != NULL && infectados != NULL)
    {
        *infectados = this->infectados;
        todoOk = 1;
    }

    return todoOk;
}

int ePais_setMuertos(ePais* this,int muertos)
{
    int todoOk = 0;

    if( this != NULL )
    {
        this->muertos = muertos;
        todoOk = 1;
    }

    return todoOk;
}
int ePais_getMuertos(ePais* this,int* muertos)
{
    int todoOk = 0;

    if( this != NULL && muertos != NULL)
    {
        *muertos = this->muertos;
        todoOk = 1;
    }

    return todoOk;
}

int printePais(ePais* pePais)
{
    int todoOk = 0;
    int idAux;
    char nameAux[900];
    int recuperadosAux;
    int infectadosAux;
    int muertosAux;

    if( pePais != NULL )
    {
        if( ePais_getId(pePais,&idAux) &&
            ePais_getNombre(pePais,nameAux) &&
            ePais_getRecuperados(pePais,&recuperadosAux) &&
            ePais_getInfectados(pePais,&infectadosAux) &&
            ePais_getMuertos(pePais, &muertosAux) )
        {
            printf("%6d %20s    %10d       %10d    %10d\n",idAux,nameAux,recuperadosAux, infectadosAux, muertosAux);
        }
        else
        {
            printf("Error intentando obtener los datos del PAIS.\n");
        }

        todoOk = 1;
    }

    return todoOk;
}

void* ePais_setRandomValues(void* pePais)
{
    int recuperadosAux;
    int infectadosAux;
    int muertosAux;

    if( pePais != NULL )
    {
        recuperadosAux = aux_getRandom(5000, 10000);
        infectadosAux = aux_getRandom(4000, 20000);
        muertosAux = aux_getRandom(1000, 50000);

        ePais_setRecuperados( (ePais*) pePais, recuperadosAux );
        ePais_setInfectados( (ePais*) pePais, infectadosAux );
        ePais_setMuertos( (ePais*) pePais, muertosAux );
    }

    return pePais;
}

int ePais_getPaisExitoso(void* pePais)
{
    int muertosAux;

    if( pePais != NULL )
    {
        ePais_getMuertos( (ePais*) pePais, &muertosAux );

        if( muertosAux < 5000 )
        {
            return 1;
        }
    }

    return 0;
}

int ePais_getPaisEnElHorno(void* pePais)
{
    int infectadosAux;
    int recuperadosAux;

    if( pePais != NULL )
    {
        ePais_getInfectados( (ePais*) pePais, &infectadosAux );
        ePais_getRecuperados( (ePais*) pePais, &recuperadosAux );

        if( (recuperadosAux * 3) <= infectadosAux )
        {
            return 1;
        }
    }

    return 0;
}

int ePais_sortByInfected(void* pePaisUno, void* pePaisDos)
{
    int infectadosAuxUno;
    int infectadosAuxDos;

    if( pePaisUno != NULL && pePaisDos != NULL )
    {
        ePais_getInfectados( (ePais*) pePaisUno, &infectadosAuxUno );
        ePais_getInfectados( (ePais*) pePaisDos, &infectadosAuxDos );

        if( infectadosAuxUno > infectadosAuxDos )
        {
            return 1;
        }

        if( infectadosAuxDos > infectadosAuxUno )
        {
            return -1;
        }
    }

    return 0;
}
