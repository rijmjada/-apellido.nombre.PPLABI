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

/** \brief Muestra array listaServicios
 * \param listaServicios array de servicios
 * \param tam tamaño del array listaServicios
 * \return 1 si cumplio la funcion, -1 caso contrario
 */
int mostrarListaServicios(sServicio listaServicios[],int tam);

/** \brief Muestra servicio en la posicion determinada
 * \param listaServicios array de servicios
 */
void mostrarService(sServicio listaServicios);

/** \brief Busca si un servicio existe comparado con el id pasado
 * \param listaSer array de servicios
 * \param tam tamaño del array listaSer
 * \param id variable a comparar y verificar dentro del array listaSer
 * \return 1 si cumplio la funcion, -1 caso contrario
 */
int buscarServicioId(sServicio listaSer[],int tam, int id);

/** \brief Carga la descripcion dentro del Array de Servicios
 * \param lista array de servicios
 * \param tam tamaño del array lista
 * \param id variable a comparar y verificar dentro del array lista
 * \param descrip cadena de caracteres a cargar
 * \return 1 si cumplio la funcion, -1 caso contrario
 */
int cargarDescripcionService(int id,sServicio lista[],int tam,char descrip[]);

