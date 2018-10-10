#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED
#include "clientes.h"
#include "juegos.h"
#define RENT_EMPTY 0
#define RENT_USED 1
#define RENT_DELETE 2
typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;
typedef struct
{
    int idAlquiler;
    int idJuego;
    int idCliente;
    eFecha fechaAlquiler;
    int isEmpty;

} eAlquiler;
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param arrayAlquiler arrayAlquiler es el array de alquileres
 * \param lenAlquiler es la longitud del array alquiler;
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
void initAlquiler(eAlquiler* arrayAlquiler, int lenAlquiler );
/** \brief busca en la estructura por el valor recibido y devuelve el indice
 *
 * \param arrayAlquiler arrayAlquiler es el array de alquileres
 * \param lenAlquiler es la longitud del array alquiler;
 * \param   valor es el valor a buscar dentro del array
 * \return  devuelve -1 si no encuctra coincidencia o retornao el indice
 *
 */
int buscarPrimeraOcurrenciaAlquiler(eAlquiler* arrayAlquiler, int lenAlquiler, int valor);
/** \brief calcula el id correponciente al campo id alquileres
 * \param arrayAlquiler arrayAlquiler es el array de alquileres
 * \param lenAlquiler es la longitud del array alquiler;
 * \return
 *
 */
int id_findNexIdAlquiler(eAlquiler* arrayAlquiler, int lenAlquiler );
/** \brief carga los datos ingresados y validados por el ususario en el array
 *
 * \param arrayAlquiler arrayAlquiler es el array de alquileres
 * \param lenAlquiler es la longitud del array alquiler;
 * \param indice es lugar dentro del array alquileres
 *
 */
void setArrayAlquiler(eAlquiler* arrayAlquiler,int idAlquiler,int IdJuego,int idCliente,int indice,int dia,int mes,int anio);
/** \brief carga los datos de alquileres, juegos y clientes
  * \param arrayAlquiler arrayAlquiler es el array de alquileres
 * \param lenAlquiler es la longitud del array alquiler;
 * \param eClientes* ArrayClientes es el array de clientes
 * \param lenClientes es la longitud del array clientes
 * \param  eJuegos* arrayJuegos
 */
void AltaAlquiler(eAlquiler* arrayAlquiler, int lenAlquiler, eClientes* ArrayClientes, int lenClientes, eJuegos* arrayJuegos, int lenJuegos);
/** \brief controla carga y lista de los datos de alquileres, juegos y clientes
  * \param arrayAlquiler arrayAlquiler es el array de alquileres
 * \param lenAlquiler es la longitud del array alquiler;
 * \param eClientes* ArrayClientes es el array de clientes
 * \param lenClientes es la longitud del array clientes
 * \param  eJuegos* arrayJuegos
 */
void controllerAlquiler(eAlquiler* arrayAlquiler, int lenAlquiler, eClientes* ArrayClientes, int lenClientes, eJuegos* arrayJuegos, int lenJuegos);
/** \brief lista de los datos cargados en los array alquileres, juegos y clientes
  * \param arrayAlquiler arrayAlquiler es el array de alquileres
 * \param lenAlquiler es la longitud del array alquiler;
 * \param eClientes* ArrayClientes es el array de clientes
 * \param lenClientes es la longitud del array clientes
 * \param  eJuegos* arrayJuegos
 */
void listarAlquileres(eAlquiler* arrayAlquiler, int lenAlquiler, eClientes* ArrayClientes, int lenClientes, eJuegos* arrayJuegos, int lenJuegos);

void mostrarAlquileres(eAlquiler* arrayAlquiler, int lenAlquiler);
#endif // ALQUILER_H_INCLUDED
