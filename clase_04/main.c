#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
int main()
{
    int numeroIngresado;
    int numeroOculto;
    char respuesta = 's';
    int jugar;
    while(respuesta == 's')
    {
        numeroOculto = getNumeroAleatorio(1,100,1);
        jugar = 1;
        while(jugar == 1)
        {
            numeroIngresado = getInt("\n Adivina el numero: ");
            if (numeroIngresado < 0)
            {
                jugar = 0;
            }
            else
            {
                if(numeroIngresado == numeroOculto)
                {
                    printf("\n !!!! FELICADES GANASTE !!!!");
                    jugar = 0;
                }
                else
                {
                    if(numeroIngresado > numeroOculto)
                    {
                        printf("\n EL NUMERO QUE INGRESASTE ES MUY GRANDE :(");
                    }
                    else
                    {
                        if(numeroIngresado< numeroOculto)
                        {
                            printf("\n EL NUMERO INGRESADO ES MUY CHICO :(");
                        }
                    }
                }
            }
        }
        respuesta = getChar("Deseas continuar jugando S/N: ");
    }

    return 0;
}

