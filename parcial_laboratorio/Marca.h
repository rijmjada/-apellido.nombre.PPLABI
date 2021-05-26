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

/** \brief Muestra lista Marcas
 * \param listaMarcas array marcas
 */
void mostrarMarcas(sMarca listaMarcas);

/** \brief Muestra lista Marcas
 * \param listaMarcas array marcas
 * \param tamMarcas tamaño del array listaMarcas
 * \return 1 si cumplio la funcion 0 caso contrario
 */
int mostrarListaDeMarcas(sMarca listaMarcas[],int tamMarcas);

/** \brief Inicializa array listaMarcas
 * \param listaMarcas array marcas
 * \param tamMarcas tamaño del array listaMarcas
 * \return 1 si cumplio la funcion 0 caso contrario
 */
int inicializarlistaMarcas(sMarca listaMarcas[],int tam);

/** \brief Carga descripcion Marca
 * \param id variable de comparacion dentro de la funcion
 * \param listaMarcas array marcas
 * \param tamMarcas tamaño del array listaMarcas
 * \param descrip cadena  de caracteres donde se guardara la informacion
 * \return 1 si cumplio la funcion 0 caso contrario
 */
int cargarDescripcionMarca(int id, sMarca listaMarcas[], int tamMarcas,char descrip[]);




