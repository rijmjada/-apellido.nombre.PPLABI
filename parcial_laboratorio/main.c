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
#define TAM_Marcas 5
#define TAM_Tipos 5
#define TAM_Servicios 5

int menu();

int main()
{


    sNotebook listaNotebook[TAM_Notebooks];

    //inicializarlistaNotebook(listaNotebook,TAM_Notebooks ); //inicializo lista iSempty
    //inicializarlistaService(listaServicios,TAM_Servicios);

    sMarca listaMarcas[TAM_Marcas]= {{1,"Compaq"},{2,"Asus"},{3,"Acer"},{4,"Hp"}};
    sTipo listaTipos[TAM_Tipos]= {{1,"Gamer"},{2,"Diseño"},{3,"Ultrabook"},{4,"Normalita"}};
    sServicio listaServicios[TAM_Servicios]={{1,"Formateo",200},{2,"Instalaciones", 150},{3,"Basico",205},{4,"Algomas",150}};



    int idNotebooks = 1;


    char exit = 'n';

    do
    {
        switch(menu())
        {

                case 1:
                    altaNotebook(listaNotebook,TAM_Notebooks ,listaMarcas,TAM_Marcas,&idNotebooks);
                    break;

                case 2:
                    //Modificar NOTEBOOK
                    break;

                case 3:
                    bajaNotebook(listaNotebook,TAM_Notebooks);
                    break;

                case 4:
                    mostrarListaNotebooks(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas);
                    break;

                case 5:
                    //E.	LISTAR  MARCAS
                    break;

                case 6:
                    //F.	LISTAR TIPOS
                    break;

                case 7:
                    //G.	LISTAR SERVICIOS
                    listarServicios(listaServicios,TAM_Servicios);
                    break;

                case 8:
                    //H.	ALTA TRABAJO
                    break;

                case 9:
                    //I.	LISTAR TRABAJOS
                    break;

                case 11:
                    printf("Confirma Salida ? <s/n> :\n");
                    fflush(stdin);
                    scanf("%c",exit);
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
