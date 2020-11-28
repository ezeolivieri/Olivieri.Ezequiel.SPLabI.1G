#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Controller.h"
#include "LinkedList.h"
#include "ePais.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPais)
{
    int retorno = -1;
    char idAux[900];
    char nameAux[900];
    char recuperadosAux[900];
    char infectadosAux[900];
    char muertosAux[900];

    FILE* fpArchivo;
    ePais* paisAux = NULL;

    if( pArrayListPais != NULL && path != NULL)
    {
        fpArchivo = fopen(path, "r");

        if( fpArchivo != NULL )
        {
            do
            {
                if( fscanf(fpArchivo, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux, nameAux, recuperadosAux, infectadosAux, muertosAux) == 5 )
                {
                    paisAux = pais_newParametrosChar(idAux, nameAux, recuperadosAux, infectadosAux, muertosAux);

                    if( paisAux != NULL )
                    {
                        ll_add(pArrayListPais, paisAux);
                    }
                }
            }
            while( !feof(fpArchivo) );

            controller_listPais(pArrayListPais);

            fclose(fpArchivo);
            retorno = 0;
        }
        else
        {
            printf("\n\nERROR INTENTANDO ABRIR EL ARCHIVO.\n\n");
        }
    }

    return retorno;
}

int controller_listPais(LinkedList* pArrayListPais)
{
    int retorno = -1;
    ePais* paisAux = NULL;
    int arrayLen = ll_len(pArrayListPais);

    if( pArrayListPais != NULL )
    {
        for( int i=0; i<arrayLen; i++ )
        {
            paisAux = (ePais*) ll_get(pArrayListPais, i);

            if( paisAux != NULL )
            {
                printPais( paisAux );
            }
        }

        printf("\n\n");

        retorno = 0;
    }

    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListPais)
{
    int retorno = -1;
    FILE* fpArchivo;
    int arrayLen = ll_len(pArrayListPais);
    ePais* paisAux = NULL;
    int idAux;
    char nameAux[900];
    int recuperadosAux;
    int infectadosAux;
    int muertosAux;

    if( pArrayListPais != NULL && path != NULL)
    {
        fpArchivo = fopen(path, "w");

        if( fpArchivo != NULL )
        {
            for( int i=0; i < arrayLen; i++ )
            {
                paisAux = (ePais*) ll_get(pArrayListPais, i);

                if( paisAux != NULL )
                {
                    if( ePais_getId(paisAux, &idAux) &&
                        ePais_getNombre(paisAux, nameAux) &&
                        ePais_getRecuperados(paisAux, &recuperadosAux) &&
                        ePais_getInfectados(paisAux, &infectadosAux) &&
                        ePais_getMuertos(paisAux, &muertosAux) )
                    {
                        fprintf(fpArchivo, "%d,%s,%d,%d,%d\n", idAux, nameAux, recuperadosAux, infectadosAux, muertosAux);
                    }
                }
            }

            fclose(fpArchivo);
            retorno = 0;
        }
    }

    return retorno;
}
