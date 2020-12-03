#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "ePais.h"
#include "Controller.h"
#include "aux.h"





/*********************** PROTOTIPOS ***********************/

/** \brief Despliegue de menu principal
 *
 * \return int Opcion ingresada por el usuario
 *
 */
int menu();





/****************** FUNCION MAIN ********************/

int main()
{
    srand(time(NULL));

    int option = 0;
    char confirmaSalir = 'N';
    char path[100];

    LinkedList* listaPaises = ll_newLinkedList();



    do
    {
        system("clear");

        option = menu();

        switch(option)
        {
            case 1:
                system("clear");

                aux_getCadena(path, "Ingrese nombre del archivo: ");

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
                    controller_MapePais(listaPaises);
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
                    controller_FilterAndSavePaisesExitosos(listaPaises);
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
                    controller_FilterAndSavePaisesEnElHorno(listaPaises);
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
                    if( !ll_sort( listaPaises, ePais_sortByInfected, 0 ) )
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
                confirmaSalir = aux_getConfirmacion("Seguro que desea salir? (s - si / n - no): ", "Error. Ingrese una opcion valida: ");
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

