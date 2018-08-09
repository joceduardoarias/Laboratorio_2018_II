#ifndef UTN_GESTION_H_INCLUDED
#define UTN_GESTION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int id;
    char descripcion [20];
    float importe;
    int cantidad;

} eproductos;
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
/** \brief Inicializa el array estructura en el campo seleccionado con un valor determinado
 * \param prod es el array estructura con el que se va a manipular
 * \param cantidad_elementos_arrayStruct es la longitud de array estructura
 * \param valor el el valor definido para rellenar el campo seleccionado en array estructura
 * \return
 */
void inicializarArrayStruct(eproductos prod[],int cantidad_elementos_arrayStruct,int valor);
/** \brief busca un lugar libre en el campo seleccion del array estructura
 * \param prod es el array estructura a manipular
 * \param cantidad_elementos_arrayStruct es la longitud del array estructura
 * \param valor es el valor definido para hacer la comparacion
 * \return devuelve un entero que es el indice de un lugar libre de lo contrario devuelve -1
 */
int buscarPrimeraOcurrencia(eproductos prod[],int cantidad_elementos_arrayStruct,int valor);
#endif // UTN_GESTION_H_INCLUDED
