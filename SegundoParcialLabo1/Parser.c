#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "ePais.h"

int parser_ePaisFromText(FILE* fpArchivo , LinkedList* pArrayListePais)
{
    int error = -1;
    char ePaisAux[5][200];
    ePais* paisAux = NULL;

    if( pArrayListePais != NULL && fpArchivo != NULL)
    {
        // LECTURA FANTASMA PARA SALTEAR EL ENCABEZADO
        fscanf(fpArchivo, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", ePaisAux[0], ePaisAux[1], ePaisAux[2], ePaisAux[3], ePaisAux[4]);

        do
        {
            if( fscanf(fpArchivo, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", ePaisAux[0], ePaisAux[1], ePaisAux[2], ePaisAux[3], ePaisAux[4]) == 5 )
            {
                paisAux = ePais_newParametros(ePaisAux[0], ePaisAux[1], ePaisAux[2], ePaisAux[3], ePaisAux[4]);

                if( paisAux != NULL )
                {
                    ll_add(pArrayListePais, paisAux);
                }
            }
        }
        while( !feof(fpArchivo) );

        error = 0;
    }

    return error;
}

int parser_saveePaisAsText(FILE* fpArchivo , LinkedList* pArrayListePais)
{
    int error = -1;
    ePais* pePaisAux = NULL;
    int idAux;
    char nombreAux[128];
    int recuperadosAux;
    int infectadosAux;
    int muertosAux;
    int arrayLen = ll_len(pArrayListePais);

    if( pArrayListePais != NULL && fpArchivo != NULL)
    {
        for( int i=0; i < arrayLen; i++ )
        {
            pePaisAux = (ePais*) ll_get(pArrayListePais, i);

            if( pePaisAux != NULL )
            {
                if( ePais_getId(pePaisAux, &idAux) &&
                    ePais_getNombre(pePaisAux, nombreAux) &&
                    ePais_getRecuperados(pePaisAux, &recuperadosAux) &&
                    ePais_getInfectados(pePaisAux, &infectadosAux) &&
                    ePais_getMuertos(pePaisAux, &muertosAux) )
                {
                    fprintf(fpArchivo, "%d,%s,%d,%d,%d\n", idAux, nombreAux, recuperadosAux, infectadosAux, muertosAux);
                }
            }
        }

        error = 0;
    }

    return error;
}
