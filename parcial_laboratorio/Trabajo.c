#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Trabajo.h"

int inicializarlistaTrabajos(sTrabajo lista[],int tam)
{
    int retorno = ERROR;
    if(lista != NULL && tam >0)
    {
        for(int i=0; i< tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        retorno = OK;
    }
    return retorno;
}

int altaTrabajo(sTrabajo
                listaTrabajos[],
                int tamTrabajo,
                sNotebook listaNotebooks[],
                int tamNote,
                sServicio listaService[],
                int tamSer,
                sMarca listaMarcas[],
                int tamMarcas,
                sTipo listaTipos[],
                int tamTipos,
                int* idTrabajos)
{

    int retorno = ERROR;
    sTrabajo auxTrabajo;
    int indice, bufferIdNote,bufferIdServ,x;

    system("cls");
    printf("   Alta Trabajo\n\n");
    printf(" Id : %d\n",*idTrabajos);

    if(listaTrabajos !=NULL
            && tamTrabajo > 0
            && listaNotebooks != NULL
            && tamNote > 0
            && listaService != NULL
            && tamSer > 0
            && idTrabajos != NULL)
    {
        indice = buscarEspacioLibreTrabajo(listaTrabajos, tamTrabajo);

        if (indice == -1)
        {
            printf("\nNo hay lugar en el sistema\n");
        }
        else
        {
            mostrarListaNotebooks(listaNotebooks,tamNote,listaMarcas,tamMarcas,listaTipos,tamTipos);

            getInt(&bufferIdNote,"\nIngrese id notebook:\n","\nId Invalido\n",1,9999,3);

            if(validarIdNotebook(listaNotebooks,tamNote,bufferIdNote))
            {
                mostrarListaServicios(listaService,tamSer);
                fflush(stdin);
                getInt(&bufferIdServ,"\nIngrese id servicio:\n","\nId Invalido\n",20000,20020,5);

                if(validarIdServicio(listaService,tamSer,bufferIdServ))
                {
                    if(valFecha()== 1)
                    {
                        printf("\nAlta Exitosa\n");
                    }
                    else
                    {
                        printf("\nHubo un error en el alta\n");
                    }
                }
                else
                {
                    printf("\nDato Id servicio invalido\n");
                }
            }
            else
            {
                printf("\nDato Id Notebook invalido\n");

            }







            buscarServicioId(listaService,tamSer,&bufferIdServ);




            /*
                        listaNotebook[indice] =  nuevNote;
                        listaNotebook[indice].id = *idNotebooks;
                        listaNotebook[indice].isEmpty= 0;
                        *idNotebooks = *idNotebooks + 1;
            */
            retorno = TODO_OK;

        }

    }

    return retorno;
}


int buscarEspacioLibreTrabajo(sTrabajo listaTrabajos[],int tamTrabajo)
{

    int lugarLibreArray = ERROR;
    if (listaTrabajos != NULL && tamTrabajo > 0)
    {
        for(int i=0; i<tamTrabajo; i++)
        {

            if(listaTrabajos[i].isEmpty)
            {
                lugarLibreArray = i; // RETORNA POSICION LIBRE !!
                break;
            }
        }
    }


    return lugarLibreArray;
}

int validarIdNotebook(sNotebook listaNotebook[],int tam, int id)
{

    int retorno = ERROR;

    for(int i=0; i<tam; i++)
    {

        if(listaNotebook[i].id == id && listaNotebook[i].isEmpty == 0)
        {
            retorno = TODO_OK;
            break;
        }

    }
    return retorno;
}

int validarIdServicio(sServicio lista[],int tam,int id)
{

    int retorno = ERROR;

    for(int i=0; i<tam; i++)
    {

        if(lista[i].idServicio == id && lista[i].isEmpty == 0)
        {
            retorno = TODO_OK;
            break;
        }

    }
    return retorno;
}


int valFecha()
{
    int retorno = ERROR;
    int dd,mm,yy;
    printf("\nIngrese fecha <dd/mm/yyyy> : \n");
    scanf("%d/%d/%d",&dd,&mm,&yy);

    /*getInt(&dd,"","",1,31,3);
    getInt(&mm,"","",1,12,3);
    getInt(&yy,"","",2000,2100,3);*/


    if(yy>=2000 && yy<=2050)
    {
//check month
        if(mm>=1 && mm<=12)
        {
//check days
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
            {
                retorno = TODO_OK;
            }

            else
            {
                if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                {
                    retorno = TODO_OK;
                }

                else
                {
                    if((dd>=1 && dd<=28) && (mm==2))
                    {
                        retorno = TODO_OK;
                    }

                    else
                    {
                        if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
                        {
                            retorno = TODO_OK;
                        }

                        else
                            printf("Dia no valido!.\n");
                    }
                }
            }
        }
        else
        {
            printf("Mes no valido!.\n");
        }
    }
    else
    {
        printf("Fecha no valida!.\n");
    }

    return retorno;
}



