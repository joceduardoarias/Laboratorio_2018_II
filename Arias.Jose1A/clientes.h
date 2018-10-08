#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#define CUSTUMER_EMPTY 0
#define CUSTUMER_USED 1
#define CUSTUMER_DELETE 2

typedef struct
{
    int idCliente;
    char apellido[51];
    char nombre[51];
    char sexo;
    char localidad[51];
    int idJuego;
    int isEmpty;
}eClientes;
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
void initCliente(eClientes* arrayClientes, int lenClientes );

/** \brief busca en la estructura por el valor recibido y devuelve el indice
 *
 * \param   eEmployee array a recorrer
 * \param   len longitud del array
 * \param   valor es el valor a buscar dentro del array
 * \return  devuelve -1 si no encuctra coincidencia o retornao el indice
 *
 */
int buscarPrimeraOcurrenciaCliente(eClientes* arrayClientes, int lenClientes , int valor);
/** \brief busca en la estructura por el id recibido y devuelve el indice
 *
 * \param   eEmployee array a recorrer
 * \param   len longitud del array
 * \param   valor es el valor a buscar dentro del array
 * \return  devuelve -1 si no encuctra coincidencia o retornao el indice
 *
 */
int buscarPrimeraOcurrenciaIdCliente(eClientes* arrayClientes, int lenClientes , int idCliente);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int id_findNexIdCliente(eClientes* arrayClientes, int lenClientes );
/** \brief carga los datos ingresados y validados por el ususario en el array
 *
 * \param eJuegos* arrayJuegos es el array de juegos
 * \param lenJuegos es la longitud del array juegos;
 * \param indice es lugar dentro del array juegos
 *
 */
void setArrayClientes(eClientes* arrayClientes,char* nombre,char* apellido,char sexo,char* localidad,int idCliente,int indice);
/** \brief Imprime una elemnto del array de acuerdo al indice recibido
  * \param eJuegos* arrayJuegos es el array de juegos
  * \param indice es lugar dentro del array juegos
 */
void mostrarUnCliente(eClientes* arrayClientes, int indice);
/** \brief Imprime todos los elemnto del array
  * \param eJuegos* arrayJuegos es el array de juegos
  * \param lenJuegos es la longitud del array juegos;
 */
void mostrarTodosClientes(eClientes* arrayClientes, int lenClientes );
void AltaClientes(eClientes* arrayClientes, int lenClientes );
void modificarClientes(eClientes* arrayClientes, int lenClientes );
void bajaClientes(eClientes* arrayClientes, int lenClientes );
void controllerClientes(eClientes* arrayClientes, int lenClientes );

#endif // CLIENTES_H_INCLUDED
