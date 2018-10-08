#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "alquiler.h"


void initAlquiler(eAlquiler* arrayAlquiler, int lenAlquiler )
{

    int i;
    for(i=0; i<lenAlquiler; i++)
    {
        arrayAlquiler[i].isEmpty= RENT_EMPTY;
    }
}
int buscarPrimeraOcurrenciaAlquiler(eAlquiler* arrayAlquiler, int lenAlquiler , int valor)
{
    int i;
    int retorno = -1;
    for(i=0; i<lenAlquiler; i++)
    {
        if(arrayAlquiler[i].isEmpty == valor || arrayAlquiler[i].isEmpty == RENT_DELETE)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int buscarPrimeraOcurrenciaIdAlquiler(eAlquiler* arrayAlquiler, int lenAlquiler , int idAlquiler)
{
    int i;
    int retorno = -1;
    for(i=0; i<lenAlquiler; i++)
    {
        if(arrayAlquiler[i].idAlquiler == idAlquiler && arrayAlquiler[i].isEmpty == RENT_USED)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int id_findNexIdAlquiler(eAlquiler* arrayAlquiler, int lenAlquiler )
{
    int i;
    int maxId = -1;
    int retorno = -1;
    if(arrayAlquiler != NULL && lenAlquiler > 0)
    {
        for(i=0; i<lenAlquiler; i++)
        {
            if(arrayAlquiler[i].isEmpty == RENT_USED || arrayAlquiler[i].isEmpty == RENT_DELETE)
            {
                if(arrayAlquiler[i].idAlquiler > maxId || maxId == -1)
                {
                    maxId = arrayAlquiler[i].idAlquiler;
                }
            }
        }
        retorno = maxId+1;
    }
    return retorno;
}
void setArrayAlquiler(eAlquiler* arrayAlquiler,int idAlquiler,int IdJuego,int idCliente,int indice,int dia,int mes,int anio)
{
    arrayAlquiler[indice].idAlquiler = idAlquiler;
    arrayAlquiler[indice].idCliente = idCliente;
    arrayAlquiler[indice].idJuego = IdJuego;
    arrayAlquiler[indice].fechaAlquiler.dia = dia;
    arrayAlquiler[indice].fechaAlquiler.mes = mes;
    arrayAlquiler[indice].isEmpty = RENT_USED;
}
