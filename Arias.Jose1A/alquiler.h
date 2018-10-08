#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED
#define RENT_EMPTY 0
#define RENT_USED 1
#define RENT_DELETE 2
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;
typedef struct
{
    int idAlquiler;
    int idJuego;
    int idCliente;
    eFecha fechaAlquiler;
    int isEmpty;

}eAlquiler;
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
void initAlquiler(eAlquiler* arrayAlquiler, int lenAlquiler );
/** \brief busca en la estructura por el valor recibido y devuelve el indice
 *
 * \param   eEmployee array a recorrer
 * \param   len longitud del array
 * \param   valor es el valor a buscar dentro del array
 * \return  devuelve -1 si no encuctra coincidencia o retornao el indice
 *
 */
int buscarPrimeraOcurrenciaAlquiler(eAlquiler* arrayAlquiler, int lenAlquiler , int valor);
/** \brief busca en la estructura por el id recibido y devuelve el indice
 *
 * \param   eEmployee array a recorrer
 * \param   len longitud del array
 * \param   valor es el valor a buscar dentro del array
 * \return  devuelve -1 si no encuctra coincidencia o retornao el indice
 *
 */
int buscarPrimeraOcurrenciaIdAlquiler(eAlquiler* arrayAlquiler, int lenAlquiler , int idAlquiler);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int id_findNexIdAlquiler(eAlquiler* arrayAlquiler, int lenAlquiler );
/** \brief carga los datos ingresados y validados por el ususario en el array
 *
 * \param eJuegos* arrayJuegos es el array de juegos
 * \param lenJuegos es la longitud del array juegos;
 * \param indice es lugar dentro del array juegos
 *
 */
void setArrayAlquiler(eAlquiler* arrayAlquiler,int idAlquiler,int IdJuego,int idCliente,int indice,int dia,int mes,int anio);
/** \brief Imprime una elemnto del array de acuerdo al indice recibido
  * \param eJuegos* arrayJuegos es el array de juegos
  * \param indice es lugar dentro del array juegos
 */
void mostrarUnAlquiler(eAlquiler* arrayAlquiler, int indice);
/** \brief Imprime todos los elemnto del array
  * \param eJuegos* arrayJuegos es el array de juegos
  * \param lenJuegos es la longitud del array juegos;
 */
void mostrarTodosAlquileres(eAlquiler* arrayAlquiler, int lenAlquiler );
void AltaAlquiler(eAlquiler* arrayAlquiler, int lenAlquiler );
void controllerAlquiler(eAlquiler* arrayAlquiler, int lenAlquiler);
#endif // ALQUILER_H_INCLUDED
