#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Marca.h"

int inicializarlistaMarcas(sMarca listaMarcas[],int tam)
{
    int retorno = ERROR;
    if(listaMarcas != NULL && tam >0)
    {
        for(int i=0; i< tam; i++)
        {
            listaMarcas[i].isEmpty = 1;
        }
        retorno = OK;
    }
    return retorno;
}

void mostrarMarcas(sMarca listaMarcas)
{

    printf("% d     %s\n"
           ,listaMarcas.idMarca
           ,listaMarcas.descpMarca
          );
    printf("-----------------------------\n");
}

int mostrarListaDeMarcas(sMarca listaMarcas[],int tamMarcas)
{
    int flag = ERROR;
    system("cls");
    printf("  ** Lista De Marcas **\n\n");
    printf("id    Descripcion\n");
    printf("-----------------------------\n");

    for(int i=0; i<tamMarcas; i++)
    {
        if(listaMarcas[i].isEmpty == 0){
            mostrarMarcas(listaMarcas[i]);
            flag = OK;
        }
    }
    if (flag == ERROR){
        printf("No hay marcas cargadas!\n");
    }
    return 0;
}

int cargarDescripcionMarca(int id, sMarca listaMarcas[], int tamMarcas,char descrip[])
{

    int todoOk = ERROR;

    if(listaMarcas != NULL && tamMarcas > 0 && descrip != NULL){

        for(int i=0; i<tamMarcas; i++){

            if(listaMarcas[i].idMarca== id){

                strcpy(descrip,listaMarcas[i].descpMarca);

                todoOk = OK;
                break;
            }
        }
    }


    return todoOk;
}




