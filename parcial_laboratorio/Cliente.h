#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#define ERROR -1
#define TODO_OK 1



typedef struct{

    int id;
    char nombre[20];
    char sexo;
    int isEmpty;

}sCliente;

#endif // CLIENTE_H_INCLUDED

int inicializarCliente(sCliente listaCliente[],int tam);
int validarIdCliente(sCliente lista[],int tam, int id);
int mostrarListaDeClientes(sCliente lista[],int tam);
void mostrarUnCliente(sCliente lista);

int hardcodearClientes(sCliente lista[], int tam, int xCantidad, int* id);

int cargarDescripcionCliente(int id, sCliente lista[], int tam,char descrip[]);



