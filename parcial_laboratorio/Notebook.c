#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Notebook.h"
#include "Marca.h"
#include "Tipo.h"
#include "utn.h"
#include "Cliente.h"

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

int altaNotebook(sNotebook listaNotebook[],int tam,sMarca listaMarcas[],int tamM,sTipo listaTipos[],int tamTipos,sCliente listaCliente[],int tamCliente, int* idNotebooks)
{

    int retorno = ERROR;
    char bufferModelo[20];
    int bufferIdMarca,bufferIdTipo,bufferIdCliente,indice;
    float bufferPrecio;
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
            getString(bufferModelo,"\nIngrese nombre modelo : \n","\nERROR",2,19,3);

            mostrarListaDeMarcas(listaMarcas,tamM);                                         //Muestro lista de marcas
            getInt(&bufferIdMarca,"\nIngrese id marca <1000/1004>: \n","\nERROR",1000,1004,5);
            if(validarIdMarca(listaMarcas,tamM,bufferIdMarca) == 1 )
            {
                mostrarListaDeTipos(listaTipos,tamTipos);                                       //Muestro lista de Tipos
                getInt(&bufferIdTipo,"\nIngrese id tipo <5000/5004>: \n","\nERROR",5000,5004,5);

                if(validarIdTipo(listaTipos,tamTipos,bufferIdTipo) == 1)
                {
                    mostrarListaDeClientes(listaCliente,tamCliente);
                    getInt(&bufferIdCliente,"\nIngrese id cliente <1/999>: \n","\nERROR",1,999,5);

                    if(validarIdCliente(listaCliente,tamCliente,bufferIdCliente) == 1)
                    {
                        system("cls");
                        getFloat(&bufferPrecio,"\nIngrese precio $ : \n","\nERROR",1.1,999999.9,5);

                        strcpy(listaNotebook[indice].modelo,bufferModelo);
                        listaNotebook[indice].precio = bufferPrecio;
                        listaNotebook[indice].marcaN.idMarca = bufferIdMarca;
                        listaNotebook[indice].tipo.idTipo = bufferIdTipo;
                        listaNotebook[indice].id = *idNotebooks;
                        listaNotebook[indice].isEmpty= 0;
                        *idNotebooks = *idNotebooks + 1;

                        retorno = OK;
                    }
                }

                else
                {
                    printf("\nNo ingreso un ID valido\n");
                }
            }
            else
            {
                printf("\nNo ingreso un ID valido\n");
            }
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

    if(listaNotebook != NULL && tam >0)
    {
        for(int i=0; i<tam; i++)
        {

            if(listaNotebook[i].id == id && listaNotebook[i].isEmpty == 0)
            {
                indice = i; // RETORNA POSICION !!
                break;
            }
        }
    }
    return indice;
}

int mostrarNotebook(sNotebook listaNotebook,sMarca listaMarca[], int tamMarca, sTipo listaTipo[],int tamTipo,sCliente listaCliente[],int tamCliente)
{
    int retorno = ERROR;
    char descripMarca[20];
    char descritipo[20];
    char nombreCliente[20];

    if(listaMarca != NULL && tamMarca >0 && listaTipo != NULL && tamTipo >0)
    {
        cargarDescripcionMarca(listaNotebook.marcaN.idMarca, listaMarca,tamMarca,descripMarca);
        cargarDescripcionTipo(listaNotebook.tipo.idTipo, listaTipo,tamTipo,descritipo);
        cargarDescripcionCliente(listaNotebook.idCliente,listaCliente,tamCliente,nombreCliente);

        printf("%d     %s     %s       %s       %s     %.2f \n"
               ,listaNotebook.id
               ,descripMarca
               ,listaNotebook.modelo
               ,descritipo
               ,nombreCliente
               ,listaNotebook.precio
              );
        printf("----------------------------------------------------------------\n");
        retorno = TODO_OK;
    }

    return retorno;
}

int mostrarListaNotebooks(sNotebook listaNotebook[],int tam,sMarca listaMarcas[],int tamMarcas,sTipo listaTipos[],int tamTipos,sCliente listaCliente[],int tamCliente)
{

    int retorno = ERROR;

    if(listaNotebook != NULL && tam > 0 && listaMarcas != NULL && tamMarcas > 0 && listaTipos != NULL && tamTipos >0)
    {
        system("cls");
        printf("\n   ** Lista de Notebooks **\n\n");
        printf("id    Marca     Modelo      Tipo        Cliente      Precio\n\n");
        printf("----------------------------------------------------------------\n");
        retorno = TODO_OK;

        for(int i=0; i<tam; i++)
        {
            if(listaNotebook[i].isEmpty == 0)
            {
                mostrarNotebook(listaNotebook[i],listaMarcas,tamMarcas,listaTipos,tamTipos,listaCliente,tamCliente);
            }
        }

        printf("\n\n");
    }

    return retorno;
}

int modificarDatosNotebook(sNotebook listaNotebook[],int tam,sMarca listaMarcas[],int tamMarcas,sTipo listaTipos[],int tamTipos,sCliente listaClientes[],int tamClientes)
{
    int retorno = ERROR;
    int index;   // Variable donde se guarda el retorno de la llamada a la funcion BuscarNotebookID
    int id;     // Variable donde se guarda el Id que ingresa el usuario

    if(listaNotebook != NULL && tam >0 && listaMarcas != NULL && tamMarcas > 0 && listaTipos != NULL && tamTipos > 0)
    {
        system("cls");
        printf("\n  Modificar Datos Notebook\n\n");
        mostrarListaNotebooks(listaNotebook,tam,listaMarcas,tamMarcas,listaTipos,tamTipos,listaClientes,tamClientes);
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
                getFloat(&listaNotebook[index].precio,"\nIngrese NUEVO precio : \n","\nERROR",1.1,999999.9,5);
                break;
            case 2:
                mostrarListaDeTipos(listaTipos,tamTipos);
                getInt(&listaNotebook[index].tipo.idTipo,"\nIngrese id NUEVO tipo : \n","\nERROR",5000,5004,5);
                break;
            case 3:
                printf("\nOperacion cancelada por el usuario.\n\n");
                break;
            default:
                printf("No ingreso un dato valido!\n");
                break;
            }
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

    if(listaNotebook != NULL && tam > 0 && listaMarcas != NULL)
    {
        for(int i=0; i<tam -1 ; i ++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(listaNotebook[i].marcaN.idMarca > listaNotebook[j].marcaN.idMarca
                        || (listaNotebook[i].marcaN.idMarca == listaNotebook[j].marcaN.idMarca
                            && listaNotebook[i].precio > listaNotebook[j].precio))
                {
                    noteAux = listaNotebook[i];
                    listaNotebook[i]=listaNotebook[j];
                    listaNotebook[j]= noteAux;
                    retorno = OK;
                }
            }
        }
    }

    return retorno;
}

int cargarDescripcionNotebook(int id,sNotebook lista[],int tam,char descrip[])
{

    int todoOk = -1;

    if(lista != NULL && tam > 0 && descrip != NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].id == id)
            {
                strcpy(descrip,lista[i].modelo);
                todoOk = 1;
                break;
            }
        }
    }


    return todoOk;
}

int validarIdTipo(sTipo lista[],int tam, int id)
{

    int retorno = ERROR;

    if(lista != NULL && tam > 0 )
    {
        for(int i=0; i<tam; i++)
        {

            if(lista[i].idTipo == id && lista[i].isEmpty == 0)
            {
                retorno = TODO_OK;
                break;
            }

        }
    }

    return retorno;
}

int validarIdMarca(sMarca lista[],int tam, int id)
{
    int retorno = ERROR;

    if(lista != NULL && tam > 0 )
    {
        for(int i=0; i<tam; i++)
        {

            if(lista[i].idMarca == id && lista[i].isEmpty == 0)
            {
                retorno = TODO_OK;
                break;
            }

        }
    }


    return retorno;
}


//-----------------------------------------------------BORRAR EN .H------------------------------------------------------------------//
//---------------------------------------------------------EXTRAS-----------------------------------------------------------------//

int mostrarListaSeleccionTipo(sNotebook listaNotebook[],int tam,sMarca listaMarcas[],int tamMarcas,sTipo listaTipos[],int tamTipos,sCliente listaCliente[],int tamCliente)
{
    int retorno = ERROR;
    int bufferTipo;
    mostrarListaDeTipos(listaTipos,tamTipos);
    getInt(&bufferTipo,"\nIngrese id tipo <5000/5003> :\n","\nId Invalido\n",5000,5003,3);


    if(listaNotebook != NULL && tam > 0 && listaMarcas != NULL && tamMarcas > 0 && listaTipos != NULL && tamTipos >0)
    {
        system("cls");
        printf("\n   ** Lista de Notebooks **\n\n");
        printf("id    Marca     Modelo      Tipo    Cliente    Precio\n\n");
        printf("-----------------------------------------------------------------\n");
        retorno = TODO_OK;

        for(int i=0; i<tam; i++)
        {
            if(listaNotebook[i].tipo.idTipo == bufferTipo && listaNotebook[i].isEmpty == 0)
            {
                mostrarNotebook(listaNotebook[i],listaMarcas,tamMarcas,listaTipos,tamTipos,listaCliente,tamCliente);
            }
        }

        printf("\n\n");
    }

    return retorno;
}

int mostrarListaSeleccionMarca(sNotebook listaNotebook[],int tam,sMarca listaMarcas[],int tamMarcas,sTipo listaTipos[],int tamTipos,sCliente listaCliente[],int tamCliente)
{
    int retorno = ERROR;
    int bufferTipo;
    mostrarListaDeMarcas(listaMarcas,tamMarcas);
    getInt(&bufferTipo,"\nIngrese id marcas <1000/1003> :\n","\nId Invalido\n",1000,1003,3);


    if(listaNotebook != NULL && tam > 0 && listaMarcas != NULL && tamMarcas > 0 && listaTipos != NULL && tamTipos >0)
    {
        system("cls");
        printf("\n   ** Lista de Notebooks **\n\n");
        printf("id    Marca     Modelo      Tipo     Cliente      Precio\n\n");
        printf("-------------------------------------------------------------------\n");
        retorno = TODO_OK;

        for(int i=0; i<tam; i++)
        {
            if(listaNotebook[i].marcaN.idMarca == bufferTipo && listaNotebook[i].isEmpty == 0)
            {
                mostrarNotebook(listaNotebook[i],listaMarcas,tamMarcas,listaTipos,tamTipos,listaCliente,tamCliente);
            }
        }

        printf("\n\n");
    }

    return retorno;
}

void hardcodearNotebooks(sNotebook listaNote[],int tamNote)
{
    char x[]="ZBC";
    char y[]="TREX";
    char z[]="JUPITER";
    char q[]="AMAZON";
    int id = 1;
    int marca = 1000;
    float precio = 1505.5;
    int tipo = 5000;
    int idCliente= 1;


    listaNote[0].id = id;
    listaNote[0].isEmpty = 0;
    listaNote[0].marcaN.idMarca = marca;
    strcpy(listaNote[0].modelo,x);
    listaNote[0].precio = precio+10;
    listaNote[0].tipo.idTipo = tipo;
    listaNote[0].idCliente = idCliente;

    listaNote[1].id = id+1;
    listaNote[1].isEmpty = 0;
    listaNote[1].marcaN.idMarca = marca+1;
    strcpy(listaNote[1].modelo,y);
    listaNote[1].precio = precio+20;
    listaNote[1].tipo.idTipo = tipo+1;
    listaNote[1].idCliente = idCliente++;

    listaNote[2].id = id+2;
    listaNote[2].isEmpty = 0;
    listaNote[2].marcaN.idMarca = marca+2;
    strcpy(listaNote[2].modelo,z);
    listaNote[2].precio = precio+30;
    listaNote[2].tipo.idTipo = tipo+2;
    listaNote[2].idCliente = idCliente+2;

    listaNote[3].id = id+3;
    listaNote[3].isEmpty = 0;
    listaNote[3].marcaN.idMarca = marca+3;
    strcpy(listaNote[3].modelo,q);
    listaNote[3].precio = precio+40;
    listaNote[3].tipo.idTipo = tipo+3;
    listaNote[3].idCliente = idCliente+3;

    listaNote[4].id = id+4;
    listaNote[4].isEmpty = 0;
    listaNote[4].marcaN.idMarca = marca+4;
    strcpy(listaNote[4].modelo,x);
    listaNote[4].precio = precio+50;
    listaNote[4].tipo.idTipo = tipo;
    listaNote[4].idCliente = idCliente+4;

    listaNote[5].id = id+5;
    listaNote[5].isEmpty = 0;
    listaNote[5].marcaN.idMarca = marca;
    strcpy(listaNote[5].modelo,x);
    listaNote[5].precio = precio+60;
    listaNote[5].tipo.idTipo = tipo+2;
    listaNote[5].idCliente = idCliente+5;
}

int ordenarNotebooksPorPrecio(sNotebook listaNotebook[],int tam)
{
    int retorno = ERROR;
    sNotebook noteAux;

    if(listaNotebook != NULL && tam > 0 )
    {
        for(int i=0; i<tam -1 ; i ++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(listaNotebook[i].precio >= listaNotebook[j].precio)
                {
                    noteAux = listaNotebook[i];
                    listaNotebook[i]=listaNotebook[j];
                    listaNotebook[j]= noteAux;
                    retorno = OK;
                }
            }
        }
    }

    return retorno;
}

int ordenarNotebooksPorMarca(sNotebook listaNotebook[],int tam,sMarca listaMarca[],int tamMarca)
{
    int retorno = ERROR;
    sNotebook noteAux;

    if(listaNotebook != NULL && tam > 0 )
    {
        for(int i=0; i<tam -1 ; i ++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(listaNotebook[i].marcaN.idMarca >= listaNotebook[j].marcaN.idMarca)
                {
                    noteAux = listaNotebook[i];
                    listaNotebook[i]=listaNotebook[j];
                    listaNotebook[j]= noteAux;
                    retorno = OK;
                }
            }
        }
    }

    return retorno;
}

int contarMarcasNotebook(sNotebook listaNotebook[],int tam,sMarca listaMarca[],int tamMarca)
{
    int retorno = ERROR;
    int contador = 0;
    int bufferIdMarca;

    if(listaNotebook != NULL && tam > 0 )
    {

        getInt(&bufferIdMarca,"\nIngrese id marca <1000/1003>: \n","\nID ingresado no es valido!.\n",1000,1003,5);

        for(int i=0; i<tam ; i ++)
        {
            if(listaNotebook[i].marcaN.idMarca == bufferIdMarca)
            {
                contador++;
                retorno = OK;
            }
        }
        printf("\nLa cantidad registrada con ese ID es : %d\n",contador);
    }

    return retorno;
}

int contarTiposNotebook(sNotebook listaNotebook[],int tam,sTipo listaTipos[],int tamTipos)
{
    int retorno = ERROR;
    int contador = 0;
    int bufferIDtipo;

    if(listaNotebook != NULL && tam > 0 )
    {

        getInt(&bufferIDtipo,"\nIngrese id tipo <5000/5003>: \n","\nID ingresado no es valido!.\n",5000,5003,5);

        for(int i=0; i<tam ; i ++)
        {
            if(listaNotebook[i].tipo.idTipo == bufferIDtipo)
            {
                contador++;
                retorno = OK;
            }
        }
        printf("\nLa cantidad registrada con ese ID es : %d\n",contador);
    }

    return retorno;
}


int mostrarNotebookMasCara(sNotebook listaNotebook[],int tam,sMarca listaMarca[], int tamMarca, sTipo listaTipo[],int tamTipo,sCliente listaCliente[], int tamCliente)
{

    int retorno = ERROR;
    int bufferId;
    float bufferPrecio = 0.1;

    if(listaNotebook != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(listaNotebook[i].precio > bufferPrecio && listaNotebook[i].isEmpty == 0)
            {
                bufferPrecio = listaNotebook[i].precio;
                bufferId = listaNotebook[i].id;
            }
        }
        system("cls");
        printf("\n   ** Notebook mas cara **\n\n");
        printf("id    Marca     Modelo      Tipo       Dueño       Precio\n\n");
        printf("----------------------------------------------------------------\n");

        mostrarNotebook(listaNotebook[bufferId],listaMarca,tamMarca,listaTipo,tamTipo,listaCliente,tamCliente);
    }
    return retorno;
}

int mostrarNotebookMasBarata(sNotebook listaNotebook[],int tam,sMarca listaMarca[], int tamMarca, sTipo listaTipo[],int tamTipo,sCliente listaCliente[], int tamCliente)
{
    int retorno = ERROR;
    int bufferId;
    float bufferPrecio = 0.1;

    if(listaNotebook != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(listaNotebook[i].precio > bufferPrecio && listaNotebook[i].isEmpty == 0)
            {
                bufferPrecio = listaNotebook[i].precio;
                bufferId = listaNotebook[i].id;
            }
        }

        system("cls");
        printf("\n   ** Notebook mas cara **\n\n");
        printf("id    Marca     Modelo      Tipo       Dueño       Precio\n\n");
        printf("----------------------------------------------------------------\n");

        mostrarNotebook(listaNotebook[bufferId],listaMarca,tamMarca,listaTipo,tamTipo,listaCliente,tamCliente);
    }
    return retorno;
}
