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

/** \brief Muestra array listaTipos
 * \param listaTipos array de tipos
 * \param tamTipos tamaño del array listaTipos
 * \return 1 si cumplio la funcion 0 caso contrario
 */
int mostrarListaDeTipos(sTipo listaTipos[],int tamTipos);

/** \brief Muestra una posicion dentro del array "listaTipos"
 * \param listaTipos array de tipos
 */
void mostrarTipo(sTipo listaTipos);
int cargarDescripcionTipo(int id, sTipo listaTipos[],int tamTipos,char descrip[]);


