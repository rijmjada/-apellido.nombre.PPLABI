#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Servicio.h"

int inicializarlistaServicios(sServicio listarServicios[],int tamServi)
{
    int retorno = ERROR;
    if(listarServicios != NULL && tamServi >0)
    {
        for(int i=0; i< tamServi; i++)
        {
            listarServicios[i].isEmpty = 1;
        }
        retorno = OK;
    }
    return retorno;
}

int mostrarListaServicios(sServicio listaServicios[],int tam)
{
    int retorno = ERROR;
    system("cls");
    printf("   ** Lista De Servicios **\n\n");
    printf(" Id   Precio    Descripcion\n");
    printf("-------------------------------\n");
    for(int i=0; i<tam; i++)
    {
        mostrarService(listaServicios[i]);
    }
    return retorno;
}

void mostrarService(sServicio listaServicios)
{
    if(listaServicios.isEmpty == 0)
    {
        printf("%d    $%d      %s\n"
               ,listaServicios.idServicio
               ,listaServicios.precio
               ,listaServicios.descpServicio);
               printf("-------------------------------\n");
    }

}

int buscarServicioId(sServicio listaSer[],int tam, int id)
{

    int indice = ERROR;

    for(int i=0; i<tam; i++)
    {

        if(listaSer[i].idServicio == id && listaSer[i].isEmpty == 0)
        {
            indice = i; // RETORNA POSICION !!
            break;
        }

    }
    return indice;
}

int cargarDescripcionService(int id,sServicio lista[],int tam,char descrip[])
{

  int todoOk = -1;

    if(lista != NULL && tam > 0 && descrip != NULL){

        for(int i=0; i<tam; i++){

            if(lista[i].idServicio == id){

                strcpy(descrip,lista[i].descpServicio);

                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

