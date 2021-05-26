#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Extras.h"

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
    printf("\n1-Mostrar las notebooks del tipo seleccionado por el usuario.\n");
    printf("2-Mostrar notebooks de una marca seleccionada.\n");
    printf("3-Ordenar por precio.\n");
    printf("4-Mostrar un listado de las notebooks separadas por marca.\n");
    printf("5-Contador unidades por marca.\n");
    printf("6-Contador unidades por tipo.\n");
    printf("7-Mostrar Notebook mas cara\n");
    printf("8-Mostrar lista Clientes\n");
    printf("9-Mostrar notebook mas barata\n");
    fflush(stdin);
    scanf("%d",&opcionMenu);

    return opcionMenu;
}
