#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

#define ERROR -1
#define OK 1




typedef struct{

    int idMarca;
    char descpMarca[20];
    int isEmpty;

}sMarca;

#endif // MARCA_H_INCLUDED

void mostrarMarcas(sMarca listaMarcas);
int mostrarListaDeMarcas(sMarca listaMarcas[],int tamMarcas);
int inicializarlistaMarcas(sMarca listaMarcas[],int tam);
int cargarDescripcionMarca(int id, sMarca listaMarcas[], int tamMarcas,char descrip[]);




