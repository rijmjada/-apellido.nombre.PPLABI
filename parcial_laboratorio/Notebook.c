#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Notebook.h"
#include "Marca.h"
#include "Tipo.h"
#include "utn.h"



int inicializarlistaNotebook(sNotebook listaNotebook[],int tam)
{
    int retorno = ERROR;
    if(listaNotebook != NULL && tam >0)
    {
        for(int i=0; i< tam; i++)
        {
            listaNotebook[i].isEmpty = 1;
        }
        retorno = OK;
    }
    return retorno;
}

int altaNotebook(sNotebook listaNotebook[],int tam,sMarca listaMarcas[],int tamM,sTipo listaTipos[],int tamTipos, int* idNotebooks)
{

    int retorno = ERROR;
    sNotebook nuevNote;
    int indice;

    system("cls");
    printf("   Alta Notebook\n\n");
    printf(" Id : %d\n",*idNotebooks);

    if(listaNotebook !=NULL
            && tam > 0
            && listaMarcas!=NULL
            && tamM > 0
            && listaTipos !=NULL
            && tamTipos > 0
            && idNotebooks!=NULL)
    {
        indice = buscarEspacioLibre(listaNotebook, tam);

        if (indice == -1)
        {
            printf("\nNo hay lugar en el sistema\n");
        }
        else
        {
            getString(nuevNote.modelo,"\nIngrese nombre modelo : \n","\nERROR",2,19,3);
            mostrarListaDeMarcas(listaMarcas,tamM);                                         //Muestro lista de marcas
            getInt(&nuevNote.marcaN.idMarca,"\nIngrese id marca <1000/1004>: \n","\nERROR",1000,1004,3);
            mostrarListaDeTipos(listaTipos,tamTipos);                                       //Muestro lista de Tipos
            getInt(&nuevNote.tipo.idTipo,"\nIngrese id tipo <5000/5004>: \n","\nERROR",5000,5004,3);
            system("cls");
            getInt(&nuevNote.precio,"\nIngrese precio $ : \n","\nERROR",1,999999,2);


            listaNotebook[indice] = nuevNote;
            listaNotebook[indice].id = *idNotebooks;
            listaNotebook[indice].isEmpty= 0;
            *idNotebooks = *idNotebooks + 1;

            retorno = OK;

        }

    }

    return retorno;
}


int buscarEspacioLibre(sNotebook listaNotebook[],int tam)
{

    int lugarLibreArray = ERROR;
    if (listaNotebook != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {

            if(listaNotebook[i].isEmpty)
            {
                lugarLibreArray = i; // RETORNA POSICION LIBRE !!
                break;
            }
        }
    }


    return lugarLibreArray;
}

int bajaNotebook(sNotebook listaNotebook[],int tam)
{

    int retorno = ERROR;
    int id;
    int indice;
    char confirma;

    if(listaNotebook != NULL && tam > 0)
    {

        printf("    Baja Notebook\n");
        printf("Ingrese id : \n");
        scanf("%d",&id);

        indice = buscarNotebookId(listaNotebook,tam,id);

        if(indice == -1)
        {
            printf("No hay ninguna notebook con el id : %d\n",id);
        }
        else
        {

            printf("Confirma baja <s/n>? \n");
            fflush(stdin);
            scanf("%c",&confirma);

            if(confirma == 's')
            {

                listaNotebook[indice].isEmpty = 1;
                retorno = OK;
            }
            else
            {
                printf("Baja cancelada por el usuario.\n");
            }

        }
    }


    return retorno;
}

int buscarNotebookId(sNotebook listaNotebook[],int tam, int id)
{

    int indice = ERROR;

    for(int i=0; i<tam; i++)
    {

        if(listaNotebook[i].id == id && listaNotebook[i].isEmpty == 0)
        {
            indice = i; // RETORNA POSICION !!
            break;
        }

    }
    return indice;
}

void mostrarNotebook(sNotebook listaNotebook,sMarca listaMarca[], int tamMarca, sTipo listaTipo[],int tamTipo)
{
    char descripMarca[20];
    char descritipo[20];
    cargarDescripcionMarca(listaNotebook.marcaN.idMarca, listaMarca,tamMarca,descripMarca);
    cargarDescripcionTipo(listaNotebook.tipo.idTipo, listaTipo,tamTipo,descritipo);

    printf("%d     %s     %s      %s     %d\n"
           ,listaNotebook.id
           ,descripMarca
           ,listaNotebook.modelo
           ,descritipo
           ,listaNotebook.precio
          );
    printf("-------------------------------------------------\n");

}

void mostrarListaNotebooks(sNotebook listaNotebook[],int tam,sMarca listaMarcas[],int tamMarcas,sTipo listaTipos[],int tamTipos)
{

    system("cls");
    printf("\n   ** Lista de Notebooks **\n\n");
    printf("id    Marca     Modelo      Tipo      Precio\n\n");
    printf("-------------------------------------------------\n");


    for(int i=0; i<tam; i++)
    {
        if(listaNotebook[i].isEmpty == 0)
        {
            mostrarNotebook(listaNotebook[i],listaMarcas,tamMarcas,listaTipos,tamTipos);
        }
    }

    printf("\n\n");
}

int modificarDatosNotebook(sNotebook listaNotebook[],int tam,sMarca listaMarcas[],int tamMarcas,sTipo listaTipos[],int tamTipos)
{
    int retorno = ERROR;
    int index;   // Variable donde se guarda el retorno de la llamada a la funcion BuscarNotebookID
    int id;     // Variable donde se guarda el Id que ingresa el usuario

    system("cls");
    printf("\n  Modificar Datos Notebook\n\n");
    mostrarListaNotebooks(listaNotebook,tam,listaMarcas,tamMarcas,listaTipos,tamTipos);
    getInt(&id,"\nIngrese la id que desea modificar:\n","\nDato Invalido\n",1,999,3);


    index = buscarNotebookId(listaNotebook,tam,id);

    if(index == -1)
    {
        printf("\nNo existe notebook con ese ID\n\n");
    }
    else
    {


        switch(menuModif())
        {

        case 1:
            getInt(&listaNotebook[index].precio,"\nIngrese NUEVO precio : \n","\nERROR",1,999999,5);
            break;

        case 2:
            mostrarListaDeTipos(listaTipos,tamTipos);
            getInt(&listaNotebook[index].tipo.idTipo,"\nIngrese id NUEVO tipo : \n","\nERROR",1,4,5);
            break;

        case 3:
            printf("\nOperacion cancelada por el usuario.\n\n");
            break;

        default:
            printf("No ingreso un dato valido!\n");
            break;
        }


    }
    return retorno;
}


int menuModif()
{
    int option;
    system("cls");
    printf("\n ** Elija una opcion ** \n");
    printf("1-Modificar Precio\n");
    printf("2-Modificar Tipo\n");
    printf("3- Salir\n");

    getInt(&option,"\nIngrese opcion: ","Error. opcion no valida.",1,3,5);
    return option;
}

int ordenarNotebooks(sNotebook listaNotebook[],int tam,sMarca listaMarcas[],int tamMarcas)
{
    int retorno = ERROR;
    sNotebook noteAux;

    for(int i=0; i<tam -1 ; i ++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(listaNotebook[i].marcaN.descpMarca[i] > listaNotebook[j].marcaN.descpMarca[j] &&
                    (strcmp(listaNotebook[i].marcaN.descpMarca,listaNotebook[j].marcaN.descpMarca) == 0 && listaNotebook[i].precio > listaNotebook[j].precio))
            {
                noteAux = listaNotebook[i];
                listaNotebook[i]=listaNotebook[j];
                listaNotebook[j]= noteAux;
                retorno = OK;
            }
        }
    }
    return retorno;
}
