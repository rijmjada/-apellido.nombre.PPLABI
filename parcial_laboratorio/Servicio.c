#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Servicio.h"

int listarServicios(sServicio listaServicios[],int tam)
{

    printf("    Lista De Servicios\n");
    printf("    Id Descripcion  Precio\n");
    for(int i=0; i<tam; i++)
    {
        mostrarService(listaServicios[i]);
    }
}


void mostrarService(sServicio listaServicios)
{
    if(listaServicios.isEmpty == 0)
    {
        printf("    %d   %10s  %d\n",listaServicios.idServicio
               ,listaServicios.descpServicio
               ,listaServicios.precio);
    }

}

int inicializarlistaService(sServicio listaServicios[],int tam)
{
    int retorno = -1;
    if(listaServicios != NULL && tam >0)
    {
        for(int i=0; i< tam; i++)
        {
            listaServicios[i].isEmpty = 1;
        }
        retorno = 1;
    }
    return retorno;
}


int altaServicio(sNotebook listaNotebook[],int tam,sMarca listaMarcas[],int tamM, int* idNotebooks)
{

    int todoOk = 0;
    sNotebook nuevNote;
    int indice;

    system("cls");
    printf("   Alta Notebook\n\n");
    printf(" Id : %d\n",*idNotebooks);

    if(listaNotebook != NULL && tam > 0 && idNotebooks != NULL)
    {
        indice = buscarEspacioLibre(listaNotebook, tam);

        if (indice == -1)
        {
            printf("\nNo hay lugar en el sistema\n");
        }
        else
        {
            if(getString(nuevNote.modelo,"\nIngrese modelo : \n","\nERROR",2,19,3) == 0 &&
            getInt(&nuevNote.marcaN.idMarca,"\nIngrese id marca : \n","\nERROR",1,4,2) == 0 &&
            getInt(&nuevNote.tipo.idTipo,"\nIngrese id tipo : \n","\nERROR",1,4,2) == 0 &&
            getInt(&nuevNote.precio,"\nIngrese precio : \n","\nERROR",1,999999,2) == 0)
            {

                        listaNotebook[indice] =  nuevNote;
            listaNotebook[indice].id = *idNotebooks; // ASIGNO EL VALOR DE NEXTLEGAJO A  nuevoEmpleado.legajo
            listaNotebook[indice].isEmpty= 0;       // isEmpty en 0 (espacio ocupado)
            *idNotebooks = *idNotebooks + 1;         // SUMO EL VALOR DE NEXTLEGAJO

            todoOk = 1;

            }

        }

    }

    return todoOk;
}


