#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED

#include "Marca.h"
#include "Tipo.h"


#define ERROR -1
#define OK 1


typedef struct{

    int id;
    char modelo[20];
    sMarca marcaN;
    sTipo tipo;
    int precio;
    int isEmpty;

}sNotebook;

int inicializarlistaNotebook(sNotebook listaNotebook[],int tam);
int buscarEspacioLibre(sNotebook listaNotebook[],int tam);
int altaNotebook(sNotebook listaNotebook[],int tam,sMarca listaMarcas[],int tamM,sTipo listaTipos[],int tamTipos, int* idNotebooks);

int buscarNotebookId(sNotebook listaNotebook[],int tam, int id);
int bajaNotebook(sNotebook listaNotebook[],int tam);
int menuModif();

void mostrarNotebook(sNotebook listaNotebook,sMarca listaMarca[], int tamMarca, sTipo listaTipo[],int tamTipo);
void mostrarListaNotebooks(sNotebook listaNotebook[],int tam,sMarca listaMarcas[],int tamMarcas,sTipo listaTipos[],int tamTipos);
int modificarDatosNotebook(sNotebook listaNotebook[],int tam,sMarca listaMarcas[],int tamMarcas,sTipo listaTipos[],int tamTipos);

int ordenarNotebooks(sNotebook listaNotebook[],int tam,sMarca listaMarcas[],int tamMarcas);
#endif // NOTEBOOK_H_INCLUDED
