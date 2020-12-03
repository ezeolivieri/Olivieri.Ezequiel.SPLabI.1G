#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "ePais.h"
#include "Parser.h"
#include "aux.h"

int controller_loadFromText(char* path , LinkedList* pArrayListePais)
{
    int todoOk = -1;

    FILE* fpArchivo;

    if( path != NULL && pArrayListePais != NULL )
    {
        fpArchivo = fopen(path, "r");

        if( fpArchivo != NULL )
        {
            if( !parser_ePaisFromText(fpArchivo, pArrayListePais) )
            {
                todoOk = 0;
            }

            fclose(fpArchivo);
        }
        else
        {
            printf("\n\nERROR INTENTANDO ABRIR EL ARCHIVO.\n\n");
        }
    }

    return todoOk;
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

    if( pArrayListePais != NULL && path != NULL)
    {
        fpArchivo = fopen(path, "w");

        if( fpArchivo != NULL )
        {
            if( !parser_saveePaisAsText( fpArchivo, pArrayListePais ) )
            {
                retorno = 0;
            }

            fclose(fpArchivo);
        }
    }

    return retorno;
}

void controller_getMasCastigados(LinkedList* pArrayListePais)
{
    int mayorCantMuertos = getMayorCantidadDeMuertos(pArrayListePais);
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

int getMayorCantidadDeMuertos(LinkedList* pArrayListePais)
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

void controller_MapePais(LinkedList* pArrayListePais)
{
    if( pArrayListePais != NULL )
    {
        ll_map(pArrayListePais, ePais_setRandomValues);
        printf("\n\n\n    =======> LISTA ACTUALIZADA CON VALORES SETEADOS <======== \n\n\n");
        controller_ListePais(pArrayListePais);
    }
}

void controller_FilterAndSavePaisesExitosos(LinkedList* pArrayListePais)
{
    LinkedList* paisesExitosos = ll_newLinkedList();

    if( pArrayListePais != NULL )
    {
        paisesExitosos = ll_filter(pArrayListePais, ePais_getPaisExitoso);

        printf("\n\n\n    =======> LISTA DE PAISES EXITOSOS <======== \n\n\n");
        controller_ListePais(paisesExitosos);
        printf("\n\n\n");

        if( !controller_saveAsText("paisesExitosos.csv", paisesExitosos) )
        {
            printf("ARCHIVO paisesExitosos.csv GENERADO CORRECTAMENTE.\n\n");
        }
        else
        {
            printf("SE PRODUJO UN ERROR GENERANDO EL ARCHIVO paisesExitosos.csv\n\n");
        }
    }
}

void controller_FilterAndSavePaisesEnElHorno(LinkedList* pArrayListePais)
{
    LinkedList* paisesEnElHorno = ll_newLinkedList();

    if( pArrayListePais != NULL )
    {
        paisesEnElHorno = ll_filter(pArrayListePais, ePais_getPaisEnElHorno);

        printf("\n\n\n    =======> LISTA DE PAISES EN EL HORNO <======== \n\n\n");
        controller_ListePais(paisesEnElHorno);
        printf("\n\n\n");

        if( !controller_saveAsText("paisesEnElHorno.csv", paisesEnElHorno) )
        {
            printf("ARCHIVO paisesEnElHorno.csv GENERADO CORRECTAMENTE.\n\n");
        }
        else
        {
            printf("SE PRODUJO UN ERROR GENERANDO EL ARCHIVO paisesEnElHorno.csv\n\n");
        }
    }
}
