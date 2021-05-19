#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED



#include "Marca.h"
#include "Tipo.h"

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
int altaNotebook(sNotebook listaNotebook[],int tam,sMarca listaMarcas[],int tamM, int* idNotebooks);

int buscarNotebookId(sNotebook listaNotebook[],int tam, int id);
int bajaNotebook(sNotebook listaNotebook[],int tam);
int menuModif();

#endif // NOTEBOOK_H_INCLUDED
