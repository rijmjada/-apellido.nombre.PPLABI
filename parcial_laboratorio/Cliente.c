#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cliente.h"
#include "data.h"

int inicializarCliente(sCliente listaCliente[],int tam){

    int retorno = ERROR;
    if(listaCliente != NULL)
    {
        for(int i=0; i< tam; i++)
        {
            listaCliente[i].isEmpty = 1;
        }
        retorno = TODO_OK;
    }
    return retorno;
}

int hardcodearClientes(sCliente lista[], int tam, int xCantidad, int* id)
{

    int cantidad = 0;
    if(lista != NULL && tam > 0 && cantidad >= 0 && cantidad <= 0 && id != NULL)
    {
        for(int i=0; i < xCantidad; i++)
        {
            lista[i].id = *id;
            (*id)++;  // PODRIA PONER TAMBIEN  " *pLegajo = *pLegajo + 1; "
            strcpy(lista[i].nombre,name[i]);
            lista[i].sexo = sexos[i];
            lista[i].isEmpty = 0;
            cantidad++;
        }
    }

    return cantidad;
}

int validarIdCliente(sCliente lista[],int tam, int id)
{

    int retorno = ERROR;

    if(lista != NULL && tam > 0 )
    {
        for(int i=0; i<tam; i++)
        {

            if(lista[i].id == id && lista[i].isEmpty == 0)
            {
                retorno = TODO_OK;
                break;
            }
        }
    }
    return retorno;
}

int mostrarListaDeClientes(sCliente lista[],int tam)
{
    int flag = ERROR;
    system("cls");
    printf("  ** Lista De Clientes **\n\n");
    printf("id    Nombre   Sexo\n");
    printf("-----------------------------\n");

    for(int i=0; i<tam; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            mostrarUnCliente(lista[i]);
            flag = TODO_OK;
        }
    }
    if (flag == ERROR)
    {
        printf("No hay Clientes cargados!\n");
    }
    return 0;
}

void mostrarUnCliente(sCliente lista)
{

    printf("% d     %s   %c\n"
           ,lista.id
           ,lista.nombre
           ,lista.sexo
          );
    printf("-----------------------------\n");
}

int cargarDescripcionCliente(int id, sCliente lista[], int tam,char descrip[])
{

    int todoOk = ERROR;

    if(lista != NULL && tam > 0 && descrip != NULL){

        for(int i=0; i<tam; i++){

            if(lista[i].id == id){

                strcpy(descrip,lista[i].nombre);

                todoOk = TODO_OK;
                break;
            }
        }
    }

    return todoOk;
}
