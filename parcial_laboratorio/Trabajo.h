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

/** \brief Busca espacio libre dentro del array "listaTrabajos"
 * \param listaTrabajos array de Trabajos
 * \param tamTrabajo tamaño del array "listaTrabajos"
 * \return -1 si no encontro espacio, caso contrario retorna la primera posicion libre
 */
int buscarEspacioLibreTrabajo(sTrabajo listaTrabajos[],int tamTrabajo);

/** \brief Inicializa el array "lista" poniendo 1 en su variable isEmpty
 * \param lista array de Trabajos
 * \param tam tamaño del array "lista"
 * \return -1 si hay un error, 1 si logra su funcion
 */
int inicializarlistaTrabajos(sTrabajo lista[],int tam);


/** \brief Comparada si el id pasado como parametro es valido dentro del array "listaNotebook"
 * \param listaNotebook array de Notebooks
 * \param tam tamaño del array "listaNotebook"
 * \return -1 si hay un error, 1 si logra su funcion
 */
int validarIdNotebook(sNotebook listaNotebook[],int tam, int id);

/** \brief Comparada si el id pasado como parametro es valido dentro del array "lista"
 * \param lista array de Servicios
 * \param tam tamaño del array "lista"
 * \return -1 si hay un error, 1 si logra su funcion
 */
int validarIdServicio(sServicio lista[],int tam,int id);

/** \brief Valida si la fecha ingresada es correcta
 * \param dd representa el dia
 * \param mm representa el mes
 * \param yy representa el año
 * \return -1 si hay un error, 1 si logra su funcion
 */
int valFecha(int dd, int mm, int yy);

/** \brief Muestra la lista de trabajos que esten activos
 * \param listaTrabajo array de Trabajos
 * \param tam tamaño del array "listaTrabajo"
 * \param listaNote array de Notebooks
 * \param tam tamaño del array "listaNote"
 * \param listaServi array de Servicios
 * \param tamSer tamaño del array "listaServi"
 * \return -1 si hay un error, 1 si logra su funcion
 */

int mostrarListaTrabajos(sTrabajo listaTrabajo[],int tam,sNotebook listaNote[],int tamNote,sServicio listaServi[],int tamSer);

/** \brief Da de alta un trabajo
 * \param listaTrabajo array de Trabajos
 * \param tamTrabajo tamaño del array "listaTrabajo"
 * \param listaNotebooks array de Notebooks
 * \param tamNote tamaño del array "listaNotebooks"
 * \param listaService array de Servicios
 * \param tamSer tamaño del array "listaService"
 * \param listaTipos array de Tipos
 * \param tamTipos tamaño del array "listaTipos"
 * \param *idTrabajos puntero al id de trabajos
 * \return -1 si hay un error, 1 si logra su funcion
 */
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

//----------------------------------------------------EXTRAS------------------------------------------------//


/** \brief Carga una secuencia determinada en el array "lista"
 * \param lista array de Trabajos
 * \param tam tamaño del array "lista"
 * \return -1 si hay un error, 1 si logra su funcion
 */
void hardcodearTrabajos(sTrabajo lista[],int tam);
