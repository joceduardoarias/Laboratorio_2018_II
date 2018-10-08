#ifndef DIRECTORES_H_INCLUDED
#define DIRECTORES_H_INCLUDED
typedef struct
{
    int dia;
    int mes;
    int año;
} eFecha;
typedef struct
{
    int idDirector;
    char nombre[51];
    char pais[51];
    eFecha fechaNcimiento;
} eDirector;
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
void initMovie(eDirector* directores,int lenDirector);
/** \brief busca en la estructura por el valor recibido y devuelve el indice
 *
 * \param   eDirector* directores array a recorrer
 * \param    lenDirector longitud del array
 * \param   valor es el valor a buscar dentro del array
 * \return  devuelve -1 si no encuctra coincidencia o retornao el indice
 *
 */
int buscarPrimeraOcurrencia(eDirector* directores,int lenDirector, int valor);
/** \brief busca en la estructura por el id recibido y devuelve el indice
 *
 * \param   eDirector* directores a recorrer
 * \param    lenDirector longitud del array
 * \param   valor es el valor a buscar dentro del array
 * \return  devuelve -1 si no encuctra coincidencia o retornao el indice
 *
 */
int buscarPrimeraOcurrenciaId(eDirector* directores,int lenDirector, int idPelicula);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int id_findNexId(eDirector* directores,int lenDirector);
/** \brief carga los datos ingresados y validados por el ususario en el array
 *
  * \param   eDirector* directores a recorrer
 * \param index indece del array peliculas
 * \param nombre es un array string
 * \param pais es un array string
 * \param anio varaiable tipo entero
 * \param idDirector varaiable tipo entero
 */
void setArrayPeliculas(eDirector* directores,int index,char* nombre,char* pais,int dia,int mes,int anio,int idDirector,int estado);
/** \brief Imprime una elemnto del array de acuerdo al indice recibido
 *
 * \param ePeliculas* es array  peliculas
 * \param index posicion dentro del array
 *
 */
void mostrarUnaPelicula(ePeliculas* arrayPeliculas, int index);
/** \brief controla las ATAS BAJAS Y MODIFICACIONES hechas por los usuarios
 * \param   eDirector* directores a recorrer
 * \param    lenDirector longitud del array
*/
void controllerAbmDirectores(eDirector* directores,int lenDirector);

#endif // DIRECTORES_H_INCLUDED
