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
#include "Extras.h"
#include "Cliente.h"

#define TAM_Notebooks 10
#define TAM_Marcas 4
#define TAM_Tipos 4
#define TAM_Servicios 4
#define TAM_Jobs 1000

#define TAM_Clientes 1000


int main()
{
    sNotebook listaNotebook[TAM_Notebooks];
    sTrabajo listaTrabajos[TAM_Jobs];
    sCliente listaClientes[TAM_Clientes];

    inicializarlistaNotebook(listaNotebook,TAM_Notebooks); //inicializo lista iSempty
    inicializarlistaTrabajos(listaTrabajos,TAM_Jobs);
    inicializarCliente(listaClientes,TAM_Clientes);

    int idCliente = 1;
    hardcodearClientes(listaClientes,TAM_Clientes,10,&idCliente);

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
            if(altaNotebook(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,listaClientes,TAM_Clientes,&idNotebooks)==1)
            {
                flag = 1;
            }
            break;

        case 2:
            if(flag)
            {
                //modificarDatosNotebook(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,listaClientes,TAM_Clientes);
            }
            else
            {
                printf("\nAntes debe dar de alta una notebook!\n");
            }

            break;

        case 3:
            if(flag)
            {
                mostrarListaNotebooks(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,listaClientes,TAM_Clientes);
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
                mostrarListaNotebooks(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,listaClientes,TAM_Clientes);
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
                if(altaTrabajo(listaTrabajos,TAM_Jobs,listaNotebook, TAM_Notebooks,listaServicios,TAM_Servicios,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,listaClientes,TAM_Clientes,&idTrabajos)== 1)
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
            if(flag)
            {
                 switch(subMenu())
            {
            case 1:
                mostrarListaSeleccionTipo(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,listaClientes,TAM_Clientes); // Seleeciona un "tipo" y muestra la lista de la misma
                break;

            case 2:
                mostrarListaSeleccionMarca(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,listaClientes,TAM_Clientes); // Seleeciona una "marca" y muestra la lista de la misma
                break;

            case 3:
                ordenarNotebooksPorPrecio(listaNotebook,TAM_Notebooks);  // ORDENA NOTEBOOKS POR PRECIO ASCENDENTE
                mostrarListaNotebooks(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,listaClientes,TAM_Clientes); // MUESTRO LA LISTA
                break;

            case 4:
                ordenarNotebooksPorMarca(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas); // ORDENA NOTEBOOKS POR MARCA
                mostrarListaNotebooks(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,listaClientes,TAM_Clientes);// MUESTRO LA LISTA
                break;

            case 5:
                mostrarListaDeMarcas(listaMarcas,TAM_Marcas); // MUESTRO LISTA DE MARCAS AL USUARIO PARA QUE SELECCIONE UNA
                contarMarcasNotebook(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas); // HAGO UN CONTEO SEGUN LA SELECCION DEL USUARIO
                break;
            case 6:
                mostrarListaDeTipos(listaTipos,TAM_Tipos);// MUESTRO LISTA DE TIPOS AL USUARIO PARA QUE SELECCIONE UNA
                contarTiposNotebook(listaNotebook,TAM_Notebooks,listaTipos,TAM_Tipos);// HAGO UN CONTEO SEGUN LA SELECCION DEL USUARIO
                break;

            case 7:
                mostrarNotebookMasCara(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,listaClientes,TAM_Clientes); // MUESTRA NOTEBOOK MAS CARA
                break;

            case 8:
                mostrarListaDeClientes(listaClientes,TAM_Clientes);
                break;

            case 9:
                mostrarNotebookMasBarata(listaNotebook,TAM_Notebooks,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,listaClientes,TAM_Clientes);
                break;

            default:
                break;
                }

            }
            else
            {
                printf("\nPrimero dar de alta!\n");
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
            printf("\n Primero Seleccione la opcion 98\n");
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


int menu();
int subMenu();



