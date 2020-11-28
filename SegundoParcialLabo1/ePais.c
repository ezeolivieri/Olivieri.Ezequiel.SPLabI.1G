#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ePais.h"

ePais* pais_new()
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

ePais* pais_newParametrosChar(char* id, char* name, char* recuperados, char* infectados, char* muertos)
{
    ePais* nuevoPais = pais_new();

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

    if( this != NULL && id > 0)
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

    if( this != NULL && nombre != NULL && strlen(nombre) > 3 )
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

    if( this != NULL && recuperados > 0 )
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

    if( this != NULL && infectados > 0 )
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

    if( this != NULL && muertos > 0 )
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

int printPais(ePais* pais)
{
    int todoOk = 0;
    int idAux;
    char nameAux[900];
    int recuperadosAux;
    int infectadosAux;
    int muertosAux;

    if( pais != NULL )
    {
        if( ePais_getId(pais,&idAux) &&
            ePais_getNombre(pais,nameAux) &&
            ePais_getRecuperados(pais,&recuperadosAux) &&
            ePais_getInfectados(pais,&infectadosAux) &&
            ePais_getMuertos(pais, &muertosAux) )
        {
            printf("%8d %15s %8d %8d %8d\n",idAux,nameAux,recuperadosAux,infectadosAux,muertosAux);
        }
        else
        {
            printf("Error intentando obtener los datos del pais.\n");
        }

        todoOk = 1;
    }

    return todoOk;
}
