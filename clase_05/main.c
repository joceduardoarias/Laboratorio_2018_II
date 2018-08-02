#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
int main()
{
    int vec[5];
    int i,maxi,mini,pos,opcion;
    float promedio,suma;
    char seguir = 's';
    do
    {
        printf("\n1. CARGAR DATOS\n2. MODIFICAR\n3. LISTAR\n4. MAX-MINI-PROM\n5. SALIR ");
        opcion = getInt("\nSELECCIONE UNA OPCION: ");
        switch(opcion)
        {
        case 1:
            for(i=0; i<5; i++)
            {
                vec[i] = getInt("\ningrese un numero: ");
            }

            break;
        case 2:
            pos = getInt("\n ingrese posicion a modificar");
            vec[pos] = getInt("\ningrese nuevo numero: ");
            break;
        case 3:
            for(i=0; i<5; i++)
            {
                printf("\n %d ", vec[i]);
            }

            break;
        case 4:
            suma = 0;
            for(i=0; i<5; i++)
            {
                suma = suma + vec[i];
            }
            promedio = suma/i;
            maxi = vec[0];
            mini = vec[0];
            for(i=0; i<5; i++)
            {
                if(vec[i] > maxi)
                {
                    maxi = vec[i];
                }
                if(vec[i]< mini)
                {
                    mini = vec[i];
                }
            }
            printf("\n maximo: %d \n minimo: %d \n promedio: %.2f", maxi,mini,promedio);
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');


    return 0;
}
