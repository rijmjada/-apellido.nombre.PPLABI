#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Marca.h"


void mostrarMarcas(sMarca listaMarcas){

    printf("    %d   %10s\n",listaMarcas.idMarca, listaMarcas.descpMarca);
}


void mostrarListaDeMarcas(sMarca listaMarcas[],int tamM)
{

    printf("    Lista De Marcas\n");
    printf("    Id Descripcion\n");
    for(int i=0;i<tamM;i++){
        mostrarMarcas(listaMarcas[i]);
    }
}
