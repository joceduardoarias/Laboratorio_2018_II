#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "juegos.h"
#include "utn.h"
void initGame(eJuegos* arrayJuegos, int lenJuegos )
{

    int i;
    for(i=0; i<lenJuegos; i++)
    {
        arrayJuegos[i].isEmpty= GAME_EMPTY;
    }
}
int buscarPrimeraOcurrencia(eJuegos* arrayJuegos, int lenJuegos, int valor)
{
    int i;
    int retorno = -1;
    for(i=0; i<lenJuegos; i++)
    {
        if(arrayJuegos[i].isEmpty == valor || arrayJuegos[i].isEmpty == GAME_DELETE)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int buscarPrimeraOcurrenciaId(eJuegos* arrayJuegos, int lenJuegos, int idJuego)
{
    int i;
    int retorno = -1;
    for(i=0; i<lenJuegos; i++)
    {
        if(arrayJuegos[i].idJuego == idJuego && arrayJuegos[i].isEmpty == GAME_USED)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int id_findNexId(eJuegos* arrayJuegos, int lenJuegos)
{
    int i;
    int maxId = -1;
    int retorno = -1;
    if(arrayJuegos != NULL && lenJuegos > 0)
    {
        for(i=0; i<lenJuegos; i++)
        {
            if(arrayJuegos[i].isEmpty == GAME_USED || arrayJuegos[i].isEmpty == GAME_DELETE)
            {
                if(arrayJuegos[i].idJuego > maxId || maxId == -1)
                {
                    maxId = arrayJuegos[i].idJuego;
                }
            }
        }
        retorno = maxId+1;
    }
    return retorno;
}
void setArrayJuegos(eJuegos* arrayJuegos,char* descripcion,float importe,int idJuego,int indice)
{
    arrayJuegos[indice].idJuego = idJuego;
    strcpy(arrayJuegos[indice].descripcion,descripcion);
    arrayJuegos[indice].importe = importe;
    arrayJuegos[indice].isEmpty = GAME_USED;
}
void mostrarUnaJuego(eJuegos* arrayJuegos, int indice)
{
    printf("\n %d \t %20s \t %.2f ",arrayJuegos[indice].idJuego,arrayJuegos[indice].descripcion,arrayJuegos[indice].importe);
}
void mostrarTodosJuegos(eJuegos* arrayJuegos, int lenJuegos)
{
    int i;
    system("cls");
    printf("\n ID_JUEGO \t DESCRIPCION  \t IMPORTE\n");
    for(i=0; i<lenJuegos; i++)
    {
        if(arrayJuegos[i].isEmpty == GAME_USED)
        {
            mostrarUnaJuego(arrayJuegos,i);
        }
    }
    printf("\n\n");
    system("pause");

}
void AltaJuegos(eJuegos* arrayJuegos, int lenJuegos)
{
    char seguir = 's';
    int indexLugarLIbre;
    int auxId;
    float auxImporte;

    char descripcionSrt[51];
    char importeSrt[51];
    system("cls");
    printf("\n ALTA \n");
    while(seguir == 's')
    {
        indexLugarLIbre = buscarPrimeraOcurrencia(arrayJuegos,lenJuegos,GAME_EMPTY);
        if(indexLugarLIbre == -1)
        {
            printf("\n No hay espacio en el sistema \n");
            break;
        }
        auxId = id_findNexId(arrayJuegos,lenJuegos);
        if(getStringLetras("\n Ingrese descripcion: ",descripcionSrt)!= 1)
        {
            printf("\n Ingrese solo letras!!!");
            break;
        }
        if(getStringNumerosFlotantes("\n Ingrese importe: ",importeSrt)!= 1)
        {
            printf("\n Ingrese solo numeros");
            break;
        }
        auxImporte = atof(importeSrt);
        setArrayJuegos(arrayJuegos,descripcionSrt,auxImporte,auxId,indexLugarLIbre);
        seguir = getChar("\n seguir cargando datos (s/n): ");
    }

    printf("\n\n");
    system("pause");
}
void modificarJuegos(eJuegos* arrayJuegos, int lenJuegos)
{
    int opcion;
    char seguir = 's';
    int indexResultadoBusqueda;
    int auxId;
    float auxImporte;

    char idJuegosSrt[51];
    char descripcionSrt[51];
    char importeSrt[51];
    system("cls");
    printf("\n MODIFICACIONES\n");
    do
    {
        system("cls");
        printf("\n1. DESCRIPCION \n2. IMPORTE\n3. SALIR\n");
        opcion = getInt("\n Seleccione una opcion: ");
        switch(opcion)
        {
        case 1:
            system("cls");
            printf("\n MODIFICAR DESCRIPCION");
            if(getStringNumeros("\n Ingrese id Juego: ",idJuegosSrt)!= 1)
            {
                printf("\n Ingrese solo numeros!!!\n");
                break;
            }
            auxId = atoi(idJuegosSrt);
            if(buscarPrimeraOcurrenciaId(arrayJuegos,lenJuegos,auxId)==-1)
            {
                printf("\n El id ingresado no esta en el sistema \n");
                break;
            }
            indexResultadoBusqueda = buscarPrimeraOcurrenciaId(arrayJuegos,lenJuegos,auxId);
            mostrarUnaJuego(arrayJuegos,indexResultadoBusqueda);
            if(getStringLetras("\n Ingrese nueva descripcion: ",descripcionSrt)!= 1)
            {
                printf("\n Ingrese solo letras\n");
                break;
            }
            seguir = getChar("\n Confirmar modificacion (s/n): ");
            if(seguir == 's')
            {
                strcpy(arrayJuegos[indexResultadoBusqueda].descripcion,descripcionSrt);
                printf("\n MODIFICACION EXITOSA !!!\n");
            }
            else
            {
                printf("\n Modificacion Cancelda!!!\n");
            }
            printf("\n\n");
            system("pause");
            break;
        case 2:
            system("cls");
            printf("\n MODIFICAR IMPORTE");
            if(getStringNumeros("\n Ingrese id Juego: ",idJuegosSrt)!= 1)
            {
                printf("\n Ingrese solo numeros!!!\n");
                break;
            }
            auxId = atoi(idJuegosSrt);
            if(buscarPrimeraOcurrenciaId(arrayJuegos,lenJuegos,auxId)==-1)
            {
                printf("\n El id ingresado no esta en el sistema \n");
                break;
            }
            indexResultadoBusqueda = buscarPrimeraOcurrenciaId(arrayJuegos,lenJuegos,auxId);
            mostrarUnaJuego(arrayJuegos,indexResultadoBusqueda);
            if(getStringNumerosFlotantes("\n Ingrese nuevo Importe: ",importeSrt)!= 1)
            {
                printf("\n Ingrese solo numeros\n");
                break;
            }
            auxImporte = atof(importeSrt);
            seguir = getChar("\n Confirmar modificacion (s/n): ");
            if(seguir == 's')
            {
                arrayJuegos[indexResultadoBusqueda].importe = auxImporte;
                printf("\n MODIFICACION EXITOSA !!!\n");
            }
            else
            {
                printf("\n Modificacion Cancelda!!!\n");
            }
            printf("\n\n");
            system("pause");
            break;
        case 3:
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');
    printf("\n\n");
    system("pause");
}
void bajaJuegos(eJuegos* arrayJuegos, int lenJuegos)
{

    char seguir = 's';

    int indexResultadoBusqueda;
    int auxId;


    char idJuegosSrt[51];


    system("cls");
    printf("\nBAJAS\n");
    while(seguir == 's')
    {
        if(getStringNumeros("\n Ingrese id Juegos: ",idJuegosSrt)!= 1)
        {
            printf("\n Ingrese solo numeros!!!");
            break;
        }
        auxId = atoi(idJuegosSrt);
        if(buscarPrimeraOcurrenciaId(arrayJuegos,lenJuegos,auxId)== -1)
        {
            printf("\n El id ingresado no esta en el sistema!!!");
            break;
        }
        indexResultadoBusqueda = buscarPrimeraOcurrenciaId(arrayJuegos,lenJuegos,auxId);
        mostrarUnaJuego(arrayJuegos,indexResultadoBusqueda);
        seguir = getChar("\n Confirmar baja(s/n): ");
        if(seguir == 's')
        {
            arrayJuegos[indexResultadoBusqueda].isEmpty = GAME_DELETE;
            printf("\n Baja confirmada\n");
            break;
        }
        else
        {
            printf("\n Baja Cancelada!!!\n");
            break;
        }
        seguir = getChar("\n Continuar (s/n): ");
    }

    printf("\n\n");
    system("pause");
}
void ordenamientoImprteDescripcion(eJuegos* arrayJuegos, int lenJuegos)
{
    int i,j;
    eJuegos auxjuegos;

    for(i=0; i<lenJuegos-1; i++)
    {
        if(arrayJuegos[i].isEmpty == GAME_USED)
        {
            for(j=i+1; j<lenJuegos; j++)
            {
                if(arrayJuegos[i].importe > arrayJuegos[j].importe)
                {
                    auxjuegos = arrayJuegos[i];
                    arrayJuegos[i] = arrayJuegos[j];
                    arrayJuegos[j] = auxjuegos;
                }
                else
                {
                    if(arrayJuegos[i].importe == arrayJuegos[j].importe)
                    {
                        if(strcmpi(arrayJuegos[i].descripcion,arrayJuegos[j].descripcion)<0)
                        {
                            auxjuegos = arrayJuegos[i];
                            arrayJuegos[i] = arrayJuegos[j];
                            arrayJuegos[j] = auxjuegos;
                        }
                    }
                }
            }
        }
    }
}
void controllerJuegos(eJuegos* arrayJuegos, int lenJuegos)
{
    int opcion;
    char seguir = 's';

    do
    {
        system("cls");
        printf("\n1. ALTA \n2. MODIFICACION \n3. BAJA\n4. LISTAR\n5. ORDENAMIENTO \n6. SALIR");
        opcion = getInt("\n Seleccione una opcion: ");
        switch(opcion)
        {
        case 1:
            AltaJuegos(arrayJuegos,lenJuegos);
            break;
        case 2:
            modificarJuegos(arrayJuegos,lenJuegos);
            break;
        case 3:
            bajaJuegos(arrayJuegos,lenJuegos);
            break;
        case 4:
            mostrarTodosJuegos(arrayJuegos,lenJuegos);
            break;
        case 5:
            ordenamientoImprteDescripcion(arrayJuegos,lenJuegos);
            break;
        case 6:
            seguir = 'n';
            break;

        }
    }
    while(seguir == 's');
}
