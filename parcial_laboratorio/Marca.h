#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED


typedef struct{

    int idMarca;
    char descpMarca[20];


}sMarca;

#endif // MARCA_H_INCLUDED

void mostrarMarcas(sMarca listaMarcas);
void mostrarListaDeMarcas(sMarca listaMarcas[],int tamM);
