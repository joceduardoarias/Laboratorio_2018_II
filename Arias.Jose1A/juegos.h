#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED
#define GAME_EMPTY 0
#define GAME_USED 1
#define GAME_DELETE 2
typedef struct
{
    int idJuego;
    char descripcion[51];
    float importe;
    int isEmpty;
} eJuegos;
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param eJuegos* arrayJuegos es el array de juegos
 * \param lenJuegos es la longitud del array juegos;
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
void initGame(eJuegos* arrayJuegos, int lenJuegos );
/** \brief busca en la estructura por el valor recibido y devuelve el indice
 *
 * \param eJuegos* arrayJuegos es el array de juegos
 * \param lenJuegos es la longitud del array juegos;
 * \param   valor es el valor a buscar dentro del array
 * \return  devuelve -1 si no encuctra coincidencia o retornao el indice
 *
 */
int buscarPrimeraOcurrencia(eJuegos* arrayJuegos, int lenJuegos, int valor);
/** \brief busca en la estructura por el id recibido y devuelve el indice
 *
 * \param eJuegos* arrayJuegos es el array de juegos
 * \param lenJuegos es la longitud del array juegos;
 * \param   valor es el valor a buscar dentro del array
 * \return  devuelve -1 si no encuctra coincidencia o retornao el indice
 *
 */
int buscarPrimeraOcurrenciaId(eJuegos* arrayJuegos, int lenJuegos, int idJuego);
/** \brief
 *
 * \param eJuegos* arrayJuegos es el array de juegos
 * \param lenJuegos es la longitud del array juegos;
* \return retorna el id calculado
 *
 */
int id_findNexId(eJuegos* arrayJuegos, int lenJuegos);
/** \brief carga los datos ingresados y validados por el ususario en el array
 *
 * \param eJuegos* arrayJuegos es el array de juegos
 * \param lenJuegos es la longitud del array juegos;
 * \param indice es lugar dentro del array juegos
 *
 */
void setArrayJuegos(eJuegos* arrayJuegos,char* descripcion,float importe,int idJuego,int indice);
/** \brief Imprime una elemnto del array de acuerdo al indice recibido
  * \param eJuegos* arrayJuegos es el array de juegos
  * \param indice es lugar dentro del array juegos
 */
void mostrarUnaJuego(eJuegos* arrayJuegos, int indice);
/** \brief Imprime todos los elemnto del array
  * \param eJuegos* arrayJuegos es el array de juegos
  * \param lenJuegos es la longitud del array juegos;
 */
void mostrarTodosJuegos(eJuegos* arrayJuegos, int lenJuegos);
/** \brief carga los datos al array juegos
 * \param eJuegos* arrayJuegos es el array de juegos
 * \param lenJuegos es la longitud del array juegos;
 */
void AltaJuegos(eJuegos* arrayJuegos, int lenJuegos);
/** \brief modifica los datos al array juegos
 * \param eJuegos* arrayJuegos es el array de juegos
 * \param lenJuegos es la longitud del array juegos;
 */
void modificarJuegos(eJuegos* arrayJuegos, int lenJuegos);
/** \brief realiza una baja logica los datos al array juegos
 * \param eJuegos* arrayJuegos es el array de juegos
 * \param lenJuegos es la longitud del array juegos;
 */
void bajaJuegos(eJuegos* arrayJuegos, int lenJuegos);
/** \brief controla la carga, modificacion y baja los datos al array juegos
 * \param eJuegos* arrayJuegos es el array de juegos
 * \param lenJuegos es la longitud del array juegos;
 */
void controllerJuegos(eJuegos* arrayJuegos, int lenJuegos);
/** \brief ordena los campos de los datos cargados por importe y descripcion
 * \param eJuegos* arrayJuegos es el array de juegos
 * \param lenJuegos es la longitud del array juegos;
 */
void ordenamientoImprteDescripcion(eJuegos* arrayJuegos, int lenJuegos);
#endif // JUEGOS_H_INCLUDED
