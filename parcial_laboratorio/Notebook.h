#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED

#include "Marca.h"
#include "Tipo.h"

#define ERROR -1
#define OK 1

typedef struct
{

    int id;
    char modelo[20];
    sMarca marcaN;
    sTipo tipo;
    int precio;
    int isEmpty;

} sNotebook;


#endif // NOTEBOOK_H_INCLUDED

/** \brief Pone en 1 la variable isEmpty en todo el array "listaNotebook"
 * \param listaNotebook array de "notebooks"
 * \param tam tamaño del array "listaNotebook"
 * \param id variable a comparar y verificar dentro del array lista
 * \param descrip cadena de caracteres a cargar
 * \return 1 si cumplio la funcion, -1 caso contrario
 */
int inicializarlistaNotebook(sNotebook listaNotebook[],int tam);

/** \brief Busca espacio libre dentro del array "listaNotebook"
 * \param listaNotebook array de "notebooks"
 * \param tam tamaño del array "listaNotebook"
 * \return 1 si cumplio la funcion, -1 caso contrario
 */
int buscarEspacioLibre(sNotebook listaNotebook[],int tam);

/** \brief Da de alta una posicion dentro del array "listaNotebook"
 * \param listaNotebook array de "notebooks"
 * \param tam tamaño del array "listaNotebook"
 * \param listaMarcas array de "Marcas"
 * \param tamM tamaño del array "listaMarcas"
 * \param listaTipos array de "Tipos"
 * \param tamTipos tamaño del array "listaTipos"
 * \param *idNotebooks direccion de la variable a incrementar
 * \return 1 si cumplio la funcion, -1 caso contrario
 */
int altaNotebook(sNotebook listaNotebook[],int tam,sMarca listaMarcas[],int tamM,sTipo listaTipos[],int tamTipos, int* idNotebooks);

/** \brief Da de alta una posicion dentro del array "listaNotebook"
 * \param listaNotebook array de "notebooks"
 * \param tam tamaño del array "listaNotebook"
 * \param id variable a comparar
 * \return 1 si cumplio la funcion, -1 caso contrario
 */
int buscarNotebookId(sNotebook listaNotebook[],int tam, int id);

/** \brief Da de baja una posicion dentro del array "listaNotebook"
 * \param listaNotebook array de "notebooks"
 * \param tam tamaño del array "listaNotebook"
 * \return 1 si cumplio la funcion, -1 caso contrario
 */
int bajaNotebook(sNotebook listaNotebook[],int tam);

/** \brief Imprime en pantalla un menu
 * \return opcion seleccionada por el usuario
 */
int menuModif();

/** \brief Muestra una posicion dentro del array "listaNotebook"
 * \param listaNotebook array "Notebook"
 * \param tam tamaño del array "listaNotebook"
 * \param listaMarca array "Marcas"
 * \param tamMarca tamaño del array "listaMarca"
 * \param listaTipo array "Tipos"
 * \param tamTipo tamaño del array "listaTipo"
 * \return 1 si cumplio la funcion, -1 caso contrario
 */
int mostrarNotebook(sNotebook listaNotebook,sMarca listaMarca[], int tamMarca, sTipo listaTipo[],int tamTipo);



/** \brief Muestra lista activa del array "listaNotebook"
 * \param listaNotebook array "Notebook"
 * \param tam tamaño del array "listaNotebook"
 * \param listaMarcas array "Marcas"
 * \param tamMarcas tamaño del array "listaMarcas"
 * \param listaTipos array "Tipos"
 * \param tamTipos tamaño del array "listaTipos"
 * \return 1 si cumplio la funcion, -1 caso contrario
 */
int mostrarListaNotebooks(sNotebook listaNotebook[],int tam,sMarca listaMarcas[],int tamMarcas,sTipo listaTipos[],int tamTipos);

/** \brief Modifica una posicion seleccionada del array "listaNotebook"
 * \param listaNotebook array "Notebook"
 * \param tam tamaño del array "listaNotebook"
 * \param listaMarcas array "Marcas"
 * \param tamMarcas tamaño del array "listaMarcas"
 * \param listaTipos array "Tipos"
 * \param tamTipos tamaño del array "listaTipos"
 * \return 1 si cumplio la funcion, -1 caso contrario
 */
int modificarDatosNotebook(sNotebook listaNotebook[],int tam,sMarca listaMarcas[],int tamMarcas,sTipo listaTipos[],int tamTipos);


/** \brief Ordena el array de "listaNotebook"
 * \param listaNotebook array "Notebook"
 * \param tam tamaño del array "listaNotebook"
 * \param listaMarcas array "Marcas"
 * \param tamMarcas tamaño del array "listaMarcas"
 * \return 1 si cumplio la funcion, -1 caso contrario
 */
int ordenarNotebooks(sNotebook listaNotebook[],int tam,sMarca listaMarcas[],int tamMarcas);

/** \brief Carga la descripcion del "modelo" en la variable "descrip"
 * \param lista array "Notebook"
 * \param tam tamaño del array "listaNotebook"
 * \param descrip variable donde se copia la descripcion
 * \param id variable a comparar
 * \return 1 si cumplio la funcion, -1 caso contrario
 */
int cargarDescripcionNotebook(int id,sNotebook lista[],int tam,char descrip[]);

/** \brief Valida si el ID ingresado se encuentra dentro del array "lista"
 * \param lista array "Marcas"
 * \param tam tamaño del array "lista"
 * \param id variable a comparar
 * \return 1 si cumplio la funcion, -1 caso contrario
 */
int validarIdMarca(sMarca lista[],int tam, int id);

/** \brief Valida si el ID ingresado se encuentra dentro del array "lista"
 * \param lista array "Tipos"
 * \param tam tamaño del array "lista"
 * \param id variable a comparar
 * \return 1 si cumplio la funcion, -1 caso contrario
 */
int validarIdTipo(sTipo lista[],int tam, int id);


//------------------------------------------------EXTRAS----------------------------------------------------------------//

int mostrarListaSeleccionTipo(sNotebook listaNotebook[],int tam,sMarca listaMarcas[],int tamMarcas,sTipo listaTipos[],int tamTipos);
int mostrarListaSeleccionMarca(sNotebook listaNotebook[],int tam,sMarca listaMarcas[],int tamMarcas,sTipo listaTipos[],int tamTipos);
void hardcodearNotebooks(sNotebook listaNote[],int tamNote);
int ordenarNotebooksPorPrecio(sNotebook listaNotebook[],int tam);
int ordenarNotebooksPorMarca(sNotebook listaNotebook[],int tam,sMarca listaMarca[],int tamMarca);
int contarMarcasNotebook(sNotebook listaNotebook[],int tam,sMarca listaMarca[],int tamMarca);
int contarTiposNotebook(sNotebook listaNotebook[],int tam,sTipo listaTipos[],int tamTipos);

//------------------------------------------------------------------------------------------------------------------//
