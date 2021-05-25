#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#define ERROR -1
#define TODO_OK 1

#include "Notebook.h"
#include "Servicio.h"
#include "Marca.h"
#include "Fecha.h"
#include "utn.h"

typedef struct{

    int idTrabajo;
    sNotebook idNotebook;
    sServicio idServicio;
    sFecha fecha;
    int isEmpty;

}sTrabajo;


#endif // TRABAJO_H_INCLUDED
int buscarEspacioLibreTrabajo(sTrabajo listaTrabajos[],int tamTrabajo);
int inicializarlistaTrabajos(sTrabajo lista[],int tam);
int validarIdNotebook(sNotebook listaNotebook[],int tam, int id);
int validarIdServicio(sServicio lista[],int tam,int id);
int valFecha();

int altaTrabajo(sTrabajo
                listaTrabajos[],
                int tamTrabajo,
                sNotebook listaNotebooks[]
                ,int tamNote,
                sServicio listaService[],
                int tamSer,
                sMarca listaMarcas[],
                int tamMarcas,
                sTipo listaTipos[],
                int tamTipos,
                int* idTrabajos);
