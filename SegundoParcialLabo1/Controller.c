#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "ePais.h"
#include <time.h>

int controller_loadFromText(char* path , LinkedList* pArrayListePais)
{
    int retorno = -1;
    char idAux[300];
    char nombreAux[300];
    char recuperadosAux[300];
    char infectadosAux[300];
    char muertosAux[300];
    FILE* fpArchivo;
    ePais* paisAux = NULL;

    if( pArrayListePais != NULL && path != NULL)
    {
        fpArchivo = fopen(path, "r");

        if( fpArchivo != NULL )
        {
            // LECTURA FANTASMA PARA SALTEAR EL ENCABEZADO
            fscanf(fpArchivo, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreAux, recuperadosAux, infectadosAux, muertosAux);

            do
            {
                if( fscanf(fpArchivo, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreAux, recuperadosAux, infectadosAux, muertosAux) == 5 )
                {
                    paisAux = ePais_newParametros(idAux, nombreAux, recuperadosAux, infectadosAux, muertosAux);

                    if( paisAux != NULL )
                    {
                        ll_add(pArrayListePais, paisAux);
                    }
                }
            }
            while( !feof(fpArchivo) );

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

int controller_ListePais(LinkedList* pArrayListePais)
{
    int retorno = -1;
    ePais* pePaisAux = NULL;
    int arrayLen = ll_len(pArrayListePais);

    if( pArrayListePais != NULL )
    {
        printf("\n\n");

        printf("    ###################################################\n");
        printf("    ################## LISTA DE PAISES ################\n");
        printf("    ###################################################\n\n");

        printf("   ID     |       Nombre       |  Recuperados  |  Infectados  |  Muertos  \n");
        printf("--------------------------------------------------------------------------\n\n");

        for( int i=0; i<arrayLen; i++ )
        {
            pePaisAux = (ePais*) ll_get(pArrayListePais, i);

            if( pePaisAux != NULL )
            {
                printePais( pePaisAux );
            }
        }

        printf("\n\n");

        retorno = 0;
    }

    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListePais)
{
    int retorno = -1;
    FILE* fpArchivo;
    int arrayLen = ll_len(pArrayListePais);
    ePais* pePaisAux = NULL;
    int idAux;
    char nombreAux[128];
    int recuperadosAux;
    int infectadosAux;
    int muertosAux;

    if( pArrayListePais != NULL && path != NULL)
    {
        fpArchivo = fopen(path, "w");

        if( fpArchivo != NULL )
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

            fclose(fpArchivo);
            retorno = 0;
        }
    }

    return retorno;
}

int getRandom(int minimo, int maximo)
{
     int aleatorio;

     aleatorio = rand()%(maximo + 1)+minimo;

     return aleatorio;
}

void controller_getMasCastigados(LinkedList* pArrayListePais)
{
    int mayorCantMuertos = mayorCantidadDeMuertos(pArrayListePais);
    int cantMuertosAux;
    int arrayLen = ll_len(pArrayListePais);
    ePais* paisAux = NULL;

    if( pArrayListePais != NULL )
    {

        printf("\n\n     ========> EL O LOS PAISES MAS CASTIGADOS <========== \n\n");
        printf(" ID     |       Nombre       |  Recuperados  |  Infectados  |  Muertos  \n");
        printf("--------------------------------------------------------------------------\n\n");

        for( int i = 0; i < arrayLen; i++ )
        {
            paisAux = (ePais*) ll_get(pArrayListePais, i);
            ePais_getMuertos(paisAux, &cantMuertosAux);

            if( cantMuertosAux == mayorCantMuertos )
            {
                printePais(paisAux);
            }
        }

        printf("\n\n");

    }

}

int mayorCantidadDeMuertos(LinkedList* pArrayListePais)
{
    ePais* paisAux = NULL;
    int retorno, cantComparar;
    int arrayLen = ll_len(pArrayListePais);

    if( pArrayListePais != NULL )
    {
        paisAux = (ePais*) ll_get(pArrayListePais, 0);
        ePais_getMuertos(paisAux, &retorno);

        for( int i = 1; i < arrayLen; i++ )
        {
            paisAux = (ePais*) ll_get(pArrayListePais, i);
            ePais_getMuertos(paisAux, &cantComparar);

            if( cantComparar > retorno )
            {
                retorno = cantComparar;
            }
        }
    }

    return retorno;
}
