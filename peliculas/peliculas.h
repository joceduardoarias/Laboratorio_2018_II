#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED
#define MOVIE_EMPTY 0
#define MOVIE_USED 1
#define MOVIE_DELETE 2
typedef struct
{
    int idPeliculas;
    char titulo[51];
    char nacionalidad[51];
    int anio;
    int idDirector;
    int isEmpty;
} ePeliculas;
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
void initMovie(ePeliculas* arrayPeliculas, int lenPeliculas );
/** \brief busca en la estructura por el valor recibido y devuelve el indice
 *
 * \param   eEmployee array a recorrer
 * \param   len longitud del array
 * \param   valor es el valor a buscar dentro del array
 * \return  devuelve -1 si no encuctra coincidencia o retornao el indice
 *
 */
int buscarPrimeraOcurrencia(ePeliculas* arrayPeliculas, int lenPeliculas, int valor);
/** \brief busca en la estructura por el id recibido y devuelve el indice
 *
 * \param   eEmployee array a recorrer
 * \param   len longitud del array
 * \param   valor es el valor a buscar dentro del array
 * \return  devuelve -1 si no encuctra coincidencia o retornao el indice
 *
 */
int buscarPrimeraOcurrenciaId(ePeliculas* arrayPeliculas, int lenPeliculas, int idPelicula);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int id_findNexId(ePeliculas* arrayPeliculas, int lenPeliculas);
/** \brief carga los datos ingresados y validados por el ususario en el array
 *
 * \param arrayPeliculas array de las peliculas
 * \param lenPeliculas longitud array peliculas
 * \param index indece del array peliculas
 * \param titulo es un array string
 * \param nacionalidad es un array string
 * \param anio varaiable tipo entero
 * \param idDirector varaiable tipo entero
 * \param IdPelicula varaiable tipo entero
 */
void setArrayPeliculas(ePeliculas* arrayPeliculas,int index,char* titulo,char* nacionalidad,int anio,int idDirector,int idPelicula,int estado);
/** \brief Imprime una elemnto del array de acuerdo al indice recibido
 *
 * \param ePeliculas* es array  peliculas
 * \param index posicion dentro del array
 *
 */
 void mostrarUnaPelicula(ePeliculas* arrayPeliculas, int index);
/** \brief controla las ATAS BAJAS Y MODIFICACIONES hechas por los usuarios
 * \param ePeliculas* es array  peliculas
 * \param lenPeliculas longitud del array peliculas
 */
 void controlleraAbmPeliculas(ePeliculas* arrayPeliculas, int lenPeliculas);
#endif // PELICULAS_H_INCLUDED
