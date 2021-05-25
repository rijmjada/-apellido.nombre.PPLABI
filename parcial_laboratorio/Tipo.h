#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

#define ERROR -1
#define TODO_OK 1



typedef struct{

    int idTipo;
    char descpTipo[20];
    int isEmpty;

}sTipo;

#endif // TIPO_H_INCLUDED


int mostrarListaDeTipos(sTipo listaTipos[],int tamTipos);
void mostrarTipo(sTipo listaTipos);
int cargarDescripcionTipo(int id, sTipo listaTipos[],int tamTipos,char descrip[]);


