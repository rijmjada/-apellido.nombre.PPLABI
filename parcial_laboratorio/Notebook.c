#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Notebook.h"
#include "Marca.h"
#include "Tipo.h"
#include "utn.h"

int inicializarlistaNotebook(sNotebook listaNotebook[],int tam)
{
    int retorno = -1;
    if(listaNotebook != NULL && tam >0)
    {
        for(int i=0; i< tam; i++)
        {
            listaNotebook[i].isEmpty = 1;
        }
        retorno = 1;
    }
    return retorno;
}

int altaNotebook(sNotebook listaNotebook[],int tam,sMarca listaMarcas[],int tamM, int* idNotebooks)
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


int buscarEspacioLibre(sNotebook listaNotebook[],int tam)
{

    int lugarLibreArray = -1;
    for(int i=0; i<tam; i++)
    {

        if(listaNotebook[i].isEmpty)
        {
            lugarLibreArray = i; // devuelve la posicion libre
            break;
        }
    }

    return lugarLibreArray;
}

int bajaNotebook(sNotebook listaNotebook[],int tam)
{

    int todoOk = -1;
    int id;
    int indice;
    char confirma;

    system("cls");
    printf("    Baja Notebook\n");
    //mostrarEmpleados(lista,tam,sectores,tamSec);
    printf("Ingrese id : \n");
    scanf("%d",&id);

    indice = buscarNotebookId(listaNotebook,tam,id);

    if(indice == -1)
    {
        printf("No hay ninguna notebook con el id : %d\n",id);
    }
    else
    {
       // mostrarEmpleado(lista[indice],sectores,tamSec);
        printf("Confirma baja <s/n>? \n");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma == 's')
        {

            listaNotebook[indice].isEmpty = 1;
            todoOk = 1;
        }
        else
        {
            printf("Baja cancelada por el usuario.\n");
        }

    }

    return todoOk;
}

int buscarNotebookId(sNotebook listaNotebook[],int tam, int id)
{

    int indice = -1;

    for(int i=0; i<tam; i++)
    {

        if(listaNotebook[i].id == id && listaNotebook[i].isEmpty == 0)
        {
            indice = i;
            break;
        }

    }
    return indice;
}

void mostrarListaNotebooks(sNotebook listaNotebook[],int tam,sMarca listaMarcas[],int tamMarcas)
{

    int flag = 1;
    printf("    Lista de Notebooks\n");
    printf(" ID     MODELO   Marca  tipo  precio \n\n");

    for(int i=0; i<tam; i++)
    {
        if(listaNotebook[i].isEmpty == 0){
            printf("%d   %d   %s   %d  \n"
           ,listaNotebook[i].id
           ,listaNotebook[i].marcaN.idMarca
           ,listaNotebook[i].modelo
           ,listaNotebook[i].precio);

            flag = 0;
        }
    }
    if(flag)
    {
        printf("No hay notebooks para mostrar . \n");
    }

    printf("\n\n");
}

int modificarDatosNotebook(sNotebook listaNotebook[],int tam)
{
    int retorno = -1;
    int index;
    int id;

    system("cls");
    printf("\n  Modificar Notebook\n\n");
    scanf("%d",&id);

    index = buscarNotebookId(listaNotebook,tam,id);

    if(index == -1)
    {
        printf("\nNo existe notebook con ese ID\n\n");
    }
    else
    {
        retorno=0;
        //MUESTO EL EMPLEADO A MODIFICAR. MUY IMPORTANTE!!!!
       // showOneEmployee(listEmployee[index]);
       // printf("\n  ID      NOMBRE    APELLIDO      SALARIO($)   SECTOR\n\n");

        switch(menuModif())
        {
        case 1:
            getString(listaNotebook[index].modelo,"\nIngrese modelo : \n","\nERROR",2,19,3);
            break;
        case 2:
            getInt(&listaNotebook[index].marcaN.idMarca,"\nIngrese id modelo : \n","\nERROR",1,4,2);
            break;
        case 3:
           getInt(&listaNotebook[index].tipo.idTipo,"\nIngrese id tipo : \n","\nERROR",1,4,2);
            break;
        case 4:
            getInt(&listaNotebook[index].precio,"\nIngrese precio : \n","\nERROR",1,999999,2);
            break;
        case 5:
            printf("\nSe ha cancelado la modificacion.\n\n");
            break;
        default:
            printf("\nOpcion invalida!\n\n");
        }

    }
    return retorno;
}


int menuModif()
{
    int option;
    printf("\n*Elija que desea modificar*\n");
    printf("1 - Modificar modelo\n");
    printf("2 - Modificar marca\n");
    printf("3 - Modificar tipo\n");
    printf("4 - Modificar precio\n");
    printf("5 - Salir\n");

    getInt(&option,"\nIngrese opcion: ","Error. opcion no valida.",1,5,2);
    return option;
}
