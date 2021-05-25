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

int main()
{
    sNotebook listaNotebook[TAM_Notebooks];
    sTrabajo listaTrabajos[TAM_Jobs];

    inicializarlistaNotebook(listaNotebook,TAM_Notebooks); //inicializo lista iSempty
    inicializarlistaTrabajos(listaTrabajos,TAM_Jobs);

    sMarca listaMarcas[TAM_Marcas]={
        {1000,"Compaq",0},
        {1002,"Asus",0},
        {1003,"Acer",0},
        {1004,"HP",0}
    };

    sTipo listaTipos[TAM_Tipos]=
    {
        {5000,"Gamer",0},
        {5001,"Disenio",0},
        {5003,"Ultrabook",0},
        {5004,"Normalita",0}
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


    char exit = 'n';

    do
    {
        switch(menu())
        {

            case 1:
                altaNotebook(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,&idNotebooks);
                break;

            case 2:
                modificarDatosNotebook(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos);
                break;

            case 3:
                mostrarListaNotebooks(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos);
                bajaNotebook(listaNotebook,TAM_Notebooks);
                break;

            case 4:
                ordenarNotebooks(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas);
                mostrarListaNotebooks(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos);
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
                altaTrabajo(
                            listaTrabajos,TAM_Jobs,
                            listaNotebook, TAM_Notebooks,
                            listaServicios,TAM_Servicios,
                            listaMarcas,TAM_Marcas,
                            listaTipos,TAM_Tipos,&idTrabajos
                            );
                break;

            case 9:
                printf("%d %d %s %d %d"
                       ,listaNotebook[0].id
                       ,listaNotebook[0].marcaN.idMarca
                       ,listaNotebook[0].modelo
                       ,listaNotebook[0].tipo.idTipo
                       ,listaNotebook[0].precio);
                break;

            case 11:
                printf("Confirma Salida ? <s/n> :\n");
                fflush(stdin);
                scanf("%c",&exit);
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
    printf("6- LISTAR TIPOS\n");
    printf("7- Listar SERVICIOS\n");
    printf("8- ALTA TRABAJO\n");
    printf("9- LISTAR TRABAJOS\n");
    printf("10- Total\n");
    printf("11- SALIR\n");
    fflush(stdin);
    scanf("%d",&opcionMenu);

    return opcionMenu;

}
