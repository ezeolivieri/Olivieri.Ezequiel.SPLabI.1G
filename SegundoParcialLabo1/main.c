#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio_ext.h>
#include "ePais.h"
#include "LinkedList.h"
#include "Controller.h"
#include <time.h>





/*********************** PROTOTIPOS ***********************/

/** \brief Despliegue de menu principal
 *
 * \return int Opcion ingresada por el usuario
 *
 */
int menu();

/** \brief Obtener un char (S/N) de confirmacion
 *
 * \param mensajePedir char*
 * \param mensajeError char*
 * \return char Caracter indicado por el usuario (S/N)
 *
 */
char getConfirmacion(char* mensajePedir, char* mensajeError);

/** \brief Obtener una cadena hasta el enter.
 *
 * \param cadena char*
 * \param mensajePedir char*
 * \return int Entero que indica si hubo errores.
 *
 */
int getCadena(char* cadena, char* mensajePedir);






int main()
{
    // FUNCION GET RANDOM

    // srand(time(NULL));
    // int aleatorio;

    // aleatorio = rand()%(a + 1)+b;

    int option = 0;
    char confirmaSalir = 'N';
    char nombreArchivo[100];

    LinkedList* listaPaises = ll_newLinkedList();




    do
    {
        system("clear");

        option = menu();

        switch(option)
        {
            case 1:
                system("clear");

                getCadena(nombreArchivo, "Ingrese el nombre del archivo: ");

                if( !(controller_loadFromText(nombreArchivo,listaPaises)) )
                {
                    printf("\n\n\n      Paises cargados desde archivo de texto con exito!.\n\n\n");
                }
                else
                {
                    printf("\n\n\n      Ha ocurrido un error.\n\n\n");
                }
                break;

            case 2:
                system("clear");
                if( !ll_isEmpty(listaPaises) )
                {
                    controller_listPais(listaPaises);
                }
                else
                {
                    printf("\n\nNO HAY PAISES CARGADOS EN EL SISTEMA.\n\n");
                }
                break;

            case 3:
                system("clear");

                break;

            case 4:
                system("clear");

                break;

            case 5:
                system("clear");

                break;

            case 6:
                system("clear");

                break;

            case 7:
                system("clear");

                break;

            case 8:
                confirmaSalir = getConfirmacion("Seguro que desea salir? (s - si / n - no): ", "Error. Ingrese una opcion valida: ");
                break;

            default:
                printf("\n\n OPCION INCORRECTA! \n\n");
                break;
        }

        if( option != 8 )
        {
            system("read -p 'Press Enter to continue...' var");
        }

    } while( confirmaSalir != 'S' );

    return 0;
}





/*******************************
            FUNCIONES
 *******************************/

int menu()
{
    int opcion;

    printf("\n");
    printf("                    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                    ~~~~~~     MENU PRINCIPAL    ~~~~~~\n");
    printf("                    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");

    printf("                    1) Cargar archivo.\n");
    printf("                    2) Imprimir lista.\n");
    printf("                    3) Asignar estadísticas.\n");
    printf("                    4) Filtrado por países exitosos.\n");
    printf("                    5) Filtrado por países en el horno.\n");
    printf("                    6) Ordenar por nivel de infección.\n");
    printf("                    7) Mostrar más castigado.\n\n");

    printf("                    8) Salir.\n\n");

    printf("                    Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

char getConfirmacion(char* mensajePedir, char* mensajeError)
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

int getCadena(char* cadena, char* mensajePedir)
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
