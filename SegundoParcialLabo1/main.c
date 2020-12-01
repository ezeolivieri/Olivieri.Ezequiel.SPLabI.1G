#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio_ext.h>
#include <time.h>
#include "LinkedList.h"
#include "ePais.h"
#include "Controller.h"





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





/****************** FUNCION MAIN ********************/
int main()
{
    srand(time(NULL));

    int option = 0;
    char confirmaSalir = 'N';
    char path[100];

    LinkedList* listaPaises = ll_newLinkedList();
    LinkedList* paisesExitosos = ll_newLinkedList();
    LinkedList* paisesEnElHorno = ll_newLinkedList();



    do
    {
        system("clear");

        option = menu();

        switch(option)
        {
            case 1:
                system("clear");

                getCadena(path, "Ingrese nombre del archivo: ");

                if( !controller_loadFromText(path, listaPaises) )
                {
                    printf("\n\nARCHIVO CARGADO CON EXITO.\n\n");
                }
                else
                {
                    printf("\n\nOCURRIO UN ERROR AL CARGAR EL ARCHIVO.\n\n");
                }
                break;

            case 2:
                system("clear");
                if( !ll_isEmpty(listaPaises) )
                {
                    controller_ListePais(listaPaises);
                }
                else
                {
                    printf("\n\nNO HAY INFORMACION CARGADA EN EL SISTEMA\n\n");
                }
                break;

            case 3:
                system("clear");
                if( !ll_isEmpty(listaPaises) )
                {
                    ll_map(listaPaises, ePais_setRandomValues);
                    printf("\n\n\n    =======> LISTA ACTUALIZADA CON VALORES SETEADOS <======== \n\n\n");
                    controller_ListePais(listaPaises);
                }
                else
                {
                    printf("\n\nNO HAY INFORMACION CARGADA EN EL SISTEMA\n\n");
                }
                break;

            case 4:
                system("clear");
                if( !ll_isEmpty(listaPaises) )
                {
                    paisesExitosos = ll_filter(listaPaises, ePais_getPaisExitoso);

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
                else
                {
                    printf("\n\nNO HAY INFORMACION CARGADA EN EL SISTEMA\n\n");
                }
                break;

            case 5:
                system("clear");
                if( !ll_isEmpty(listaPaises) )
                {
                    paisesEnElHorno = ll_filter(listaPaises, ePais_getPaisEnElHorno);

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
                else
                {
                    printf("\n\nNO HAY INFORMACION CARGADA EN EL SISTEMA\n\n");
                }
                break;

            case 6:
                system("clear");
                if( !ll_isEmpty(listaPaises) )
                {
                    if( !ll_sort(listaPaises,ePais_sortByInfected,0) )
                    {
                        printf("\n\nSE ORDENO CORRECTAMENTE\n\n");
                    }
                    else
                    {
                        printf("\n\nSE PRODUJO UN ERROR AL INTENTAR ORDENAR\n\n");
                    }
                }
                else
                {
                    printf("\n\nNO HAY INFORMACION CARGADA EN EL SISTEMA\n\n");
                }
                break;

            case 7:
                system("clear");
                if( !ll_isEmpty(listaPaises) )
                {
                    controller_getMasCastigados(listaPaises);
                }
                else
                {
                    printf("\n\nNO HAY INFORMACION CARGADA EN EL SISTEMA\n\n");
                }
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

