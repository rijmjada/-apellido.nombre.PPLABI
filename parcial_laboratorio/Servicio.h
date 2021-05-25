#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED


#define ERROR -1
#define OK 1

typedef struct{

    int idServicio;
    char descpServicio[25];
    int precio;
    int isEmpty;

}sServicio;

#endif // SERVICIO_H_INCLUDED
int mostrarListaServicios(sServicio listaServicios[],int tam);
void mostrarService(sServicio listaServicios);
int buscarServicioId(sServicio listaSer[],int tam, int id);

