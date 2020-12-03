#include <stdlib.h>
#include <ctype.h>
#include <stdio_ext.h>

char aux_getConfirmacion(char* mensajePedir, char* mensajeError)
{
    char confirmar;

    if( mensajePedir != NULL && mensajeError != NULL )
    {
        printf("\n\n%s\n", mensajePedir);
        __fpurge(stdin);
        confirmar = getchar();
        confirmar = toupper(confirmar);

        while( confirmar != 'S' && confirmar != 'N' )
        {
            printf("\n%s\n", mensajeError);
            __fpurge(stdin);
            confirmar = getchar();
            confirmar = toupper(confirmar);
        }
    }

    return confirmar;
}

int aux_getCadena(char* cadena, char* mensajePedir)
{
    int todoOk = 0;

    if( cadena != NULL && mensajePedir != NULL )
    {
        printf("\n%s", mensajePedir);
        __fpurge(stdin);
        scanf("%[^\n]", cadena);

        todoOk = 1;
    }

    return todoOk;
}

int aux_getRandom(int minimo, int maximo)
{
     int aleatorio;

     aleatorio = rand()%(maximo + 1)+minimo;

     return aleatorio;
}
