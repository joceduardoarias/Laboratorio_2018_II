#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "juegos.h"
#include "clientes.h"
#include "alquiler.h"
/** \brief calcula el total de los importes de los juegos alquilados
 * \param eAlquiler* es el array de alquileres
 * \param lenAlquiler el la longitud de los alquilres
 * \param eJuegos arraJuegos es el array juegos
 * \param lenJuegos es la longitud del array juegos
 * \return float devuelve el total de los juegos alquilados
 */
float totalJuegosAlquilados(eAlquiler* arrayAlquilres, int lenAlquilres,eJuegos* arrayJuegos,int lenJuegos);
/** \brief calcula el promedio de los importes de los juegos alquilados.
* \param eAlquiler* es el array de alquileres
 * \param lenAlquiler el la longitud de los alquilres
 * \param eJuegos arraJuegos es el array juegos
 * \param lenJuegos es la longitud del array juegos
 * \return retorna el importe promedio de juegos alquilados
 */
float promedioImporteJuegosAlquilados(eAlquiler* arrayAlquilres, int lenAlquilres,eJuegos* arrayJuegos,int lenJuegos);
/** \brief calcula la cantidad de juegos que no superan el importe promedio
  * \param eAlquiler* es el array de alquileres
 * \param lenAlquiler el la longitud de los alquilres
 * \param eJuegos arraJuegos es el array juegos
 * \param lenJuegos es la longitud del array juegos
 */
void cantidadJuegosPromedioAbajo(eAlquiler* arrayAlquilres, int lenAlquilres,eJuegos* arrayJuegos,int lenJuegos);
/** \brief lista todo los clientes que arrendaron un juego determinado
 * \param eAlquiler* es el array de alquileres
 * \param lenAlquiler el la longitud de los alquilres
 * \param eJuegos arraJuegos es el array juegos
 * \param lenJuegos es la longitud del array juegos
 * \param eClientes arrayCliente es el array clientes
 * \param lenClientes es la longotud del array clientes
 */
void listaClientesJuegoDeterminado(eAlquiler* arrayAlquilres, int lenAlquilres,eJuegos* arrayJuegos,int lenJuegos,eClientes* arrayClientes,int lenClientes);
/** \brief lista todo los juegos que arrendaron un cliente determinado
 * \param eAlquiler* es el array de alquileres
 * \param lenAlquiler el la longitud de los alquilres
 * \param eJuegos arraJuegos es el array juegos
 * \param lenJuegos es la longitud del array juegos
 * \param eClientes arrayCliente es el array clientes
 * \param lenClientes es la longotud del array clientes
 */
void listaJuegosClientesDeterminado(eAlquiler* arrayAlquilres, int lenAlquilres,eJuegos* arrayJuegos,int lenJuegos,eClientes* arrayClientes,int lenClientes);
/** \brief controla el acceso a los informes
 * \param eAlquiler* es el array de alquileres
 * \param lenAlquiler el la longitud de los alquilres
 * \param eJuegos arraJuegos es el array juegos
 * \param lenJuegos es la longitud del array juegos
 * \param eClientes arrayCliente es el array clientes
 * \param lenClientes es la longotud del array clientes
 */
void controllerInformes(eAlquiler* arrayAlquilres, int lenAlquilres,eJuegos* arrayJuegos,int lenJuegos,eClientes* arrayClientes,int lenClientes);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void bubbleSort (eJuegos* arrayJuegos,int lenJuegos);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void ordenacion_insercion (eClientes* arrayClientes, int lenClientes);
/** \brief listar juegos alquilados fecha determinada
 * \param eAlquiler* es el array de alquileres
* \param lenAlquiler el la longitud de los alquilres
* \param eJuegos arraJuegos es el array juegos
* \param lenJuegos es la longitud del array juegos
* \param eClientes arrayCliente es el array clientes
* \param lenClientes es la longotud del array clientes
 */

/** \brief calcula la cantidad de veces que un juego fue alquilado
 *
 * \param eAlquiler* es el array de alquileres
 * \param lenAlquiler el la longitud de los alquilres
 * \param idJuego es el id del juego alquilado
 * \return la cantidad de veces que un juego fue alquilado
 */
int cantidadAlquileresPorJuego(eAlquiler* arrayAlquilres, int lenAlquilres,int idJuego);
/** \brief calcula el minimo de juegos alquildos
 *
 * \param eAlquiler* es el array de alquileres
 * \param lenAlquiler el la longitud de los alquilres
 * \param eJuegos arraJuegos es el array juegos
 * \param lenJuegos es la longitud del array juegos
 * \return el minimo de juegos alquilados
 */
int minimoJuegosAlquilados(eAlquiler* arrayAlquilres, int lenAlquilres,eJuegos* arrayJuegos,int lenJuegos);
/** \brief lista los juegos Menos Alquilados
 *
 * \param eAlquiler* es el array de alquileres
 * \param lenAlquiler el la longitud de los alquilres
 * \param eJuegos arraJuegos es el array juegos
 * \param lenJuegos es la longitud del array juegos
 */
void juegosMenosAlquilados(eAlquiler* arrayAlquilres, int lenAlquilres,eJuegos* arrayJuegos,int lenJuegos);
#endif // INFORMES_H_INCLUDED
