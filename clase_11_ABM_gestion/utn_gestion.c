#include <stdio.h>
#include <stdlib.h>
#include "utn_gestion.h"
int getInt(char mensaje[])
{
    int aux;
    printf("%s",mensaje);
    scanf("%d", &aux);
    return aux;
}
float getFloat(char mensaje[])
{
    float aux;
    printf("%s",mensaje);
    scanf("%f", &aux);
    return aux;
}
char getChar(char mensaje[])
{
    char aux;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c", &aux);
    return aux;
}
void inicializarArrayStruct(eproductos prod[],int cantidad_elementos_arrayStruct,int valor)
{
    int i;
    for(i=0;i<cantidad_elementos_arrayStruct;i++)
    {
        prod[i].id = valor;
    }
}
int buscarPrimeraOcurrencia(eproductos prod[],int cantidad_elementos_arrayStruct,int valor)
{
    int i;
    for(i=0;i<cantidad_elementos_arrayStruct;i++)
    {
        if(prod[i].id == valor)
        {
            return i;
            break;
        }
    }
    return -1;
}
