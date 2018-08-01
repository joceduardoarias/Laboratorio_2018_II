#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int valorIngresado (void);


float AreaCirculo (float r);
int main()
{
    float valor;
    float Area;

    valor = valorIngresado();
    Area = AreaCirculo(valor);
    printf("Area del Circulo: %.2f ",Area);
    return 0;
}
/** \brief Solicita al usuario ingresar un valor
 * \return  retorna un valor tipo float
 */
int valorIngresado(void)
{
    int retorno;
    printf("ingrese un numero:");
    scanf("%d", &retorno);
    return retorno;
}
/** \brief recibe un valor de radio ingresado por el usuario y retorna el calculo del area respectiva.
 * \param r valor de radio
 * \return AreaRetornada retorna el area del circulo
 */
float AreaCirculo (float r)
{
    float AreaRetornada;
    AreaRetornada = 3.14 * pow(r,2);
    return AreaRetornada;
}
