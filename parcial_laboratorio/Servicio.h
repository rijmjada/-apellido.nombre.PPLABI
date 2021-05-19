#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED



typedef struct{

    int idServicio;
    char descpServicio[25];
    int precio;
    int isEmpty;

}sServicio;

#endif // SERVICIO_H_INCLUDED
int listarServicios(sServicio listaServicios[],int tam);
void mostrarService(sServicio listaServicios);
int inicializarlistaService(sServicio listaServicios[],int tam);
