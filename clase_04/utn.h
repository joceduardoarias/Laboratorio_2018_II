#ifndef _LIB_H_
#define _LIB_H_
#include <stdio.h>
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
  *
  * \param desde limite inferior del intervalo
  * \param hasta limite superior del intervalo
  * \param iniciar indica si se trata del primer numero solicitado
  * \return retorna un numero aleatorio
  *
  */
 char getNumeroAleatorio(int desde , int hasta, int iniciar);
#endif
