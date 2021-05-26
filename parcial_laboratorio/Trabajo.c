#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Trabajo.h"

int inicializarlistaTrabajos(sTrabajo lista[],int tam){
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
                int* idTrabajos){

    int retorno = ERROR;
    int indice, bufferIdNote,bufferIdServ;
    int dd,mm,yy;

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
        indice = buscarEspacioLibreTrabajo(listaTrabajos, tamTrabajo); //BUSCO ESPACIO LIBRE SI LO HAY PARA CARGAR EL NUEVO TRABAJO Y GUARDO SU RETORNO EN "INDICE"

        if (indice == -1)
        {
            printf("\nNo hay lugar en el sistema\n");
        }
        else
        {
            mostrarListaNotebooks(listaNotebooks,tamNote,listaMarcas,tamMarcas,listaTipos,tamTipos); // MUESTRO LISTA DE NOTEBOOKS

            getInt(&bufferIdNote,"\nIngrese id notebook:\n","\nId Invalido\n",1,9999,3);// PIDO AL USUARIO INGRESE UN ID  DE NOTEBOOKS

            if(validarIdNotebook(listaNotebooks,tamNote,bufferIdNote) == 1 ) // VALIDO QUE EL ID EXISTA
            {
                mostrarListaServicios(listaService,tamSer); // MUESTRO LISTA DE SERVICIOS

                getInt(&bufferIdServ,"\nIngrese id servicio:\n","\nId Invalido\n",20000,20020,5); // PIDO AL USUARIO INGRESE UN ID DE SERVICIOS

                if(validarIdServicio(listaService,tamSer,bufferIdServ) == 1 )  // VALIDO QUE EL ID EXISTA
                {

                    printf("\nIngrese fecha <dd/mm/yyyy> : \n");
                    scanf("%d/%d/%d",&dd,&mm,&yy);

                    if(valFecha(dd,mm,yy)== 1)  // VALIDO FECHA
                    {
                        listaTrabajos[indice].fecha.dia = dd;
                        listaTrabajos[indice].fecha.mes = mm;
                        listaTrabajos[indice].fecha.anio = yy;
                        listaTrabajos[indice].idNotebook.id = bufferIdNote;
                        listaTrabajos[indice].idServicio.idServicio = bufferIdServ;
                        listaTrabajos[indice].idTrabajo = *idTrabajos; // ASIGNO ID
                        listaTrabajos[indice].isEmpty = 0;  // DECLARO EL LUGAR OCUPADO
                        *idTrabajos = *idTrabajos + 1;      // INCREMENTO EL ID EN EL MAIN

                        retorno = OK;
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

            retorno = TODO_OK;

        }

    }

    return retorno;
}

int buscarEspacioLibreTrabajo(sTrabajo listaTrabajos[],int tamTrabajo){

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

int validarIdNotebook(sNotebook listaNotebook[],int tam, int id){

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

int validarIdServicio(sServicio lista[],int tam,int id){

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

int valFecha(int dd,int mm, int yy){
    int retorno = ERROR;

    if(yy>=1986 && yy<=2050)
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

void mostrarTrabajo(sTrabajo listaTrabajo,int tam,sNotebook listaNote[],int tamNote,sServicio listaServi[],int tamSer){
    char descNote[20];
    char descServ[20];
    cargarDescripcionNotebook(listaTrabajo.idNotebook.id, listaNote,tamNote,descNote);
    cargarDescripcionService(listaTrabajo.idServicio.idServicio, listaServi,tamSer,descServ);

    printf("%d       [%d]%s           [%d]%s          %d/%d/%d\n"
           ,listaTrabajo.idTrabajo
           ,listaTrabajo.idNotebook.id
           ,descNote
           ,listaTrabajo.idServicio.idServicio
           ,descServ
           ,listaTrabajo.fecha.dia
           ,listaTrabajo.fecha.mes
           ,listaTrabajo.fecha.anio


          );
    printf("----------------------------------------------------------------------------------\n");

}

int mostrarListaTrabajos(sTrabajo listaTrabajo[],int tam,sNotebook listaNote[],int tamNote,sServicio listaServi[],int tamSer){

    int retorno = ERROR;

    if(listaTrabajo != NULL && tam >0 && listaNote != NULL && tamNote >0 && listaServi != NULL && tamSer >0)
    {
        system("cls");
        printf("\n                   ***Lista de Trabajos***\n\n");
        printf(" id         Notebook            Service                Fecha \n\n");
        printf("[id]      [id][modelo]       [id][descrip]          [dd/mm/yy] \n\n");
        printf("----------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(listaTrabajo[i].isEmpty == 0)
            {
                mostrarTrabajo(listaTrabajo[i],tam,listaNote,tamNote,listaServi,tamSer);
                retorno = TODO_OK;
            }
        }
        printf("\n\n");
    }

    if(retorno == ERROR)
    {
        printf("\n\nLista Vacia.\n\n");
    }

    return retorno;
}

void hardcodearTrabajos(sTrabajo lista[],int tam){
    int idT = 1;
    int dia = 1;
    int mes = 1;
    int anio = 2015;
    int idNote = 1;
    int idSer = 20000;

    for(int i=0; i<4; i++)
    {
        lista[i].idTrabajo = idT;
        lista[i].fecha.dia = dia;
        lista[i].fecha.mes = mes;
        lista[i].fecha.anio = anio;
        lista[i].idNotebook.id = idNote;
        lista[i].idServicio.idServicio = idSer;
        lista[i].isEmpty = 0;


        idT++;
        dia++;
        mes++;
        anio++;
        idNote++;
        idSer++;
    }
}
