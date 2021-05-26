#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "Trabajo.h"
#include "Servicio.h"
#include "Tipo.h"
#include "Marca.h"
#include "Fecha.h"
#include "Notebook.h"

#define TAM_Notebooks 10
#define TAM_Marcas 4
#define TAM_Tipos 4
#define TAM_Servicios 4
#define TAM_Jobs 1000

int menu();
int subMenu();

int main()
{
    sNotebook listaNotebook[TAM_Notebooks];
    sTrabajo listaTrabajos[TAM_Jobs];

    inicializarlistaNotebook(listaNotebook,TAM_Notebooks); //inicializo lista iSempty
    inicializarlistaTrabajos(listaTrabajos,TAM_Jobs);

    //hardcodearNotebook();

    sMarca listaMarcas[TAM_Marcas]=
    {
        {1000,"Compaq",0},
        {1001,"Asus",0},
        {1002,"Acer",0},
        {1003,"HP",0}
    };

    sTipo listaTipos[TAM_Tipos]=
    {
        {5000,"Gamer",0},
        {5001,"Disenio",0},
        {5002,"Ultrabook",0},
        {5003,"Normalita",0}
    };

    sServicio listaServicios[TAM_Servicios]=
    {
        {20000,"Bateria",250,0},
        {20001,"Antivirus",300,0},
        {20002,"Actualizacion",400,0},
        {20003,"Fuente",600,0}
    };


    int idNotebooks = 1;
    int idTrabajos = 1;
    int flag = 0;
    int flagWork = 0;
    char exit = 'n';

    do
    {
        switch(menu())
        {

        case 1:
            if(altaNotebook(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,&idNotebooks)==1)
            {
                flag = 1;
            }
            break;

        case 2:
            if(flag)
            {
                modificarDatosNotebook(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos);
            }
            else
            {
                printf("\nAntes debe dar de alta una notebook!\n");
            }

            break;

        case 3:
            if(flag)
            {
                mostrarListaNotebooks(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos);
                bajaNotebook(listaNotebook,TAM_Notebooks);
            }
            else
            {
                printf("\nAntes debe dar de alta una notebook!\n");
            }
            break;

        case 4:
            if(flag)
            {
                ordenarNotebooks(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas);
                mostrarListaNotebooks(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos);
            }
            else
            {
                printf("\nAntes debe dar de alta una notebook!\n");
            }

            break;

        case 5:
            mostrarListaDeMarcas(listaMarcas,TAM_Marcas);
            break;

        case 6:
            mostrarListaDeTipos(listaTipos,TAM_Tipos);
            break;

        case 7:
            mostrarListaServicios(listaServicios,TAM_Servicios);
            break;

        case 8:
              if(flag)
            {
                if(altaTrabajo(listaTrabajos,TAM_Jobs,listaNotebook, TAM_Notebooks,listaServicios,TAM_Servicios,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,&idTrabajos)== 1)
                {
                    flagWork = 1;
                }
            }
            else
            {
                printf("\nAntes debe dar de alta una notebook!\n");
            }

            break;

        case 9:
            if(flagWork)
            {
                mostrarListaTrabajos(listaTrabajos,TAM_Jobs,listaNotebook,TAM_Notebooks,listaServicios,TAM_Servicios);
            }
            else
            {
                printf("\nAntes debe dar de alta un trabajo!\n");
            }
            break;

        case 10:

            switch(subMenu())
            {
            case 1:
                mostrarListaSeleccionTipo(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos);
                break;

            case 2:
                mostrarListaSeleccionMarca(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos);
                break;

            case 3:
                ordenarNotebooksPorPrecio(listaNotebook,TAM_Notebooks);
                mostrarListaNotebooks(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos);
                break;

            case 4:
                ordenarNotebooksPorMarca(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas);
                mostrarListaNotebooks(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos);
                break;

            case 5:
                mostrarListaDeMarcas(listaMarcas,TAM_Marcas);
                contarMarcasNotebook(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas);
                break;
            case 6:
                mostrarListaDeTipos(listaTipos,TAM_Tipos);
                contarTiposNotebook(listaNotebook,TAM_Notebooks,listaTipos,TAM_Tipos);
                break;
            case 7:
                printf("\n %d \n",flag);
                break;

            default:
                break;
            }

            break;

        case 11:
            printf("Confirma Salida ? <s/n> :\n");
            fflush(stdin);
            scanf("%c",&exit);
            break;

        case 98:
            hardcodearNotebooks(listaNotebook,TAM_Notebooks);
            flag = 1;
            break;

        case 99:
            hardcodearTrabajos(listaTrabajos,TAM_Jobs);
            flagWork = 1;
            break;

        default:
            break;

        }
        system("pause");
    }
    while(exit == 'n');



    return 0;
}

int menu()
{

    int opcionMenu;
    system("cls");
    printf("\n    *** MENU OPCIONES ***\n");
    printf("---------------------------\n");
    printf("\n1- Alta Notebook\n");
    printf("2- Modificar Notebook\n");
    printf("3- Baja Notebook\n");
    printf("4- Listar Notebook\n");
    printf("5- Listar Marcas\n");
    printf("6- Listar Tipos\n");
    printf("7- Listar Servicios\n");
    printf("8- Alta Trabajo\n");
    printf("9- Listar Trabajos\n");
    printf("10- Menu Extra\n");
    printf("11- SALIR\n");
    printf("\n\n");
    printf("98- hardcodear notebooks\n");
    printf("99- hardcodear trabajos\n");
    fflush(stdin);
    scanf("%d",&opcionMenu);

    return opcionMenu;

}
//--------------------------------Extras*-------------------BORRAR ARRIBA MAIN Y SWITCH !!!
int subMenu()
{

    int opcionMenu;
    system("cls");
    printf("\n    *** Menu Informes Seleccion ***\n");
    printf("---------------------------\n");
    printf("\n1-Listar tipos.\n");
    printf("2-Listar marcas.\n");
    printf("3-Ordenar por precio.\n");
    printf("4-Ordenar por marca.\n");
    printf("5-Contador unidades por marca.\n");
    printf("6-Contador unidades por tipo.\n");
    printf("7-Vacio\n");
    fflush(stdin);
    scanf("%d",&opcionMenu);

    return opcionMenu;

}
