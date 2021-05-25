#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Tipo.h"



void mostrarTipo(sTipo listaTipos)
{

        printf("% d     %s\n"
               ,listaTipos.idTipo
               ,listaTipos.descpTipo
              );
        printf("----------------------------\n");

}


int mostrarListaDeTipos(sTipo listaTipos[],int tamTipos)
{
    int flag = ERROR;
    system("cls");
    printf("    Lista De Tipos\n\n");
    printf("ID    Descripcion\n");
    printf("----------------------------\n");

    for(int i=0; i<tamTipos; i++)
    {
        if(listaTipos[i].isEmpty == 0)
        {
            mostrarTipo(listaTipos[i]);
            flag = TODO_OK;
        }
    }
    if (flag == ERROR)
    {
        printf("No hay tipos cargads!\n");
    }
    return 0;
}

int cargarDescripcionTipo(int id, sTipo listaTipos[],int tamTipos,char descrip[])
{

    int retorno = ERROR;

    if(listaTipos != NULL && tamTipos > 0 && descrip != NULL)
    {

        for(int i=0; i<tamTipos; i++)
        {

            if(listaTipos[i].idTipo== id)
            {

                strcpy(descrip,listaTipos[i].descpTipo);

                retorno = TODO_OK;
                break;
            }
        }
    }


    return retorno;
}
