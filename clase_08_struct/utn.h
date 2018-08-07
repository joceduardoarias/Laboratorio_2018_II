#ifndef _LIB_H_
#define _LIB_H_
#include <stdio.h>
typedef struct
{
    char nombre[20];
    char apellido[20];
    int legajo;
}epersonas;
/** \brief Se encarga de obtener un numero entero
 * \param mensaje es el mensaje a ser mostrado
 * \return devuelve un numero entero
 */
int getInt(char mensaje[]);
/** \brief Se encarga de obtener un numero decimal
 * \param mensaje es el mensaje a ser mostrado
 * \return devuelve un numero entero
 */
float getFloat(char mensaje[]);
/** \brief Se encarga de obtener un dato tipo char
 * \param mensaje es el mensaje a ser mostrado
 * \return devuelve un el caracter ingresado por el usuario
 */
 char getChar(char mensaje[]);
 /** \brief Genera un numero aleatorio entre un intervalo dado
  * \param desde limite inferior del intervalo
  * \param hasta limite superior del intervalo
  * \param iniciar indica si se trata del primer numero solicitado
  * \return retorna un numero aleatorio
  *
  */
 char getNumeroAleatorio(int desde , int hasta, int iniciar);
 /** \brief Inicializar vector de enteros con el valor recibido
  *
  * \param vec vector a rellenar con el valor definido
  * \param valor es el valor que sera cargado en cada posicion del vector
  * \param cantidad_elementos_array es el tamaño total del vector
  *
  */
  void inicializarArrayInt(int vec[], int cantidad_elementos_array,int valor);
  /** \brief busca el primer espacion libre dentro del array para posteriormente cargar valores
   *
   * \param vec es el vector en donde se va a realizar la busqueda
   * \param cantidad_elementos_array es el tamaño total del vector
   * \param valor es valor a buscar dentro del vector
   * \return si no hay un lugar libre retorna (-1), si hay un lugar libre retorna la posicion de donde encontro el valor (i)
   *
   */
    int buscarPrimeraOcurrencia(int vec[],int cantidad_elementos_array, int valor );

/** \brief Inicializar vector de enteros con el valor recibido
 *
 * \param pers es el array estructura al cual se va rellenar el campo seleccionado con el valor definido
 * \param valor es el valor que sera cargado en cada posicion del campo definido para inicializar
 * \param cantidad_elementos_arrayEstruc es la cantida de elemntos de la estructura
 * \return
 *
 */
 void inicilizarEstructura(epersonas pers[],int cantidad_elementos_arrayEstruc,int valor);
/** \brief devuelve el indice primer espacio libre dentro del campo seleccionado dentro de la estructura
 *
 * \param pers es el array estructura al cual a traves de uno de sus campos se va a realizar la busqueda
 * \param valor es el valor a buscar en el campo definido
 * \param cantidad_elementos_arrayEstruc es la cantida de elemntos de la estructura
 * \return
 *
 */
int buscarPrimeraOcurrenciaEstructura(epersonas pers[],int cantidad_elementos_arrayEstruc, int valor);

#endif
