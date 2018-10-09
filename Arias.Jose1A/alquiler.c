#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "alquiler.h"
#include "clientes.h"
#include "juegos.h"


void initAlquiler(eAlquiler* arrayAlquiler, int lenAlquiler )
{

    int i;
    for(i=0; i<lenAlquiler; i++)
    {
        arrayAlquiler[i].isEmpty= RENT_EMPTY;
    }
}
int buscarPrimeraOcurrenciaAlquiler(eAlquiler* arrayAlquiler, int lenAlquiler, int valor)
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
/*
int buscarPrimeraOcurrenciaIdAlquiler(eAlquiler* arrayAlquiler, int lenAlquiler, int idAlquiler)
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
*/
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
    arrayAlquiler[indice].fechaAlquiler.anio = anio;
    arrayAlquiler[indice].isEmpty = RENT_USED;
}
void AltaAlquiler(eAlquiler* arrayAlquiler, int lenAlquiler, eClientes* ArrayClientes, int lenClientes, eJuegos* arrayJuegos, int lenJuegos)
{
    char seguir = 's';
    int indexLugarLIbre;
    int auxId;
    int auxIdClientes;
    int auxIdJuegos;
    int auxDia;
    int auxMes;
    int auxAnio;


    char idClientesSrt[51];
    char idJuegoSrt[51];
    char diaSrt[10];
    char mesSrt[10];
    char anioSrt[10];

    system("cls");
    printf("\n ALTA \n");
    while(seguir == 's')
    {
        indexLugarLIbre = buscarPrimeraOcurrenciaAlquiler(arrayAlquiler,lenAlquiler,RENT_EMPTY);
        if(indexLugarLIbre == -1)
        {
            printf("\n No hay espacio en el sistema \n");
            break;
        }
        auxId = id_findNexIdAlquiler(arrayAlquiler,lenAlquiler);
        mostrarTodosClientes(ArrayClientes,lenClientes);
        if(getStringNumeros("\n Seleccione id cliente: ",idClientesSrt)!= 1)
        {
            printf("\n Ingrese solo numeros!!!");
            break;
        }
        auxIdClientes = atoi(idClientesSrt);
        mostrarTodosJuegos(arrayJuegos,lenJuegos);
        if(getStringNumeros("\n Seleccione id juegos: ",idJuegoSrt)!= 1)
        {
            printf("\n Ingrese solo numeros");
            break;
        }
        auxIdJuegos = atoi(idJuegoSrt);
        if(getStringNumeros("\n Ingrese dia: ",diaSrt)!= 1)
        {
            printf("\n Ingrese solo numeros");
            break;
        }
        if(getStringNumeros("\n Ingrese mes: ",mesSrt)!= 1)
        {
            printf("\n Ingrese solo numeros");
            break;
        }
        if(getStringNumeros("\n Ingrese anio: ",anioSrt)!= 1)
        {
            printf("\n Ingrese solo numeros");
            break;
        }
        auxDia = atoi(diaSrt);
        auxMes = atoi(mesSrt);
        auxAnio = atoi(anioSrt);
        setArrayAlquiler(arrayAlquiler,auxId,auxIdJuegos,auxIdClientes,indexLugarLIbre,auxDia,auxMes,auxAnio);
        seguir = getChar("\n seguir cargando datos (s/n): ");
    }

    printf("\n\n");
    system("pause");
}
void listarAlquileres(eAlquiler* arrayAlquiler, int lenAlquiler, eClientes* ArrayClientes, int lenClientes, eJuegos* arrayJuegos, int lenJuegos)
{
    int i,j,k;
    char nombreCliente[51];
    char descripcionJuego[51];
    system("cls");
    printf("  *** LISTADO DE ALQUILERES ***\n\n");
    printf("\n ID_ALQUILER\tNOMBRE_CLIENTE \t\t\t JUEGO \t\t FECHA \n");
    for(i=0; i<lenAlquiler; i++)
    {
        if(arrayAlquiler[i].isEmpty == RENT_USED)
        {

            for(j=0; j<lenClientes; j++)
            {
                if(ArrayClientes[j].idCliente == arrayAlquiler[i].idCliente)
                {
                    strcpy(nombreCliente,ArrayClientes[j].nombre);
                    break;
                }
            }

            for(k=0; k<lenJuegos; k++)
            {
                if(arrayAlquiler[i].idJuego == arrayJuegos[k].idJuego)
                {
                    strcpy(descripcionJuego,arrayJuegos[k].descripcion);
                    break;
                }
            }
            printf("\n %d \t %20s \t %21s \t\t %02d/%02d/%d",arrayAlquiler[i].idAlquiler,nombreCliente,descripcionJuego,arrayAlquiler[i].fechaAlquiler.dia,arrayAlquiler[i].fechaAlquiler.mes,arrayAlquiler[i].fechaAlquiler.anio);
        }
    }



    printf("\n\n");
    system("pause");

}
void controllerAlquiler(eAlquiler* arrayAlquiler, int lenAlquiler, eClientes* ArrayClientes, int lenClientes, eJuegos* arrayJuegos, int lenJuegos)
{
    int opcion;
    char seguir = 's';
    do
    {
        system("cls");
        printf("\n1. ALTA\n2. LISTAR \n3. SALIR");
        opcion = getInt("\n Seleccione una opcion: ");
        switch(opcion)
        {
        case 1:
            AltaAlquiler(arrayAlquiler,lenAlquiler,ArrayClientes,lenClientes,arrayJuegos,lenJuegos);
            break;
        case 2:
            listarAlquileres(arrayAlquiler,lenAlquiler,ArrayClientes,lenClientes,arrayJuegos,lenJuegos);
            mostrarAlquileres(arrayAlquiler,lenAlquiler);
            break;
        case 3:
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');
}
void mostrarAlquileres(eAlquiler* arrayAlquiler, int lenAlquiler)
{
    int i;

    for(i=0; i<lenAlquiler; i++)
    {
        if(arrayAlquiler[i].isEmpty == RENT_USED)
        {
            printf("\n %d\t%d\t%d\t%d/%d/%d",arrayAlquiler[i].idAlquiler,arrayAlquiler[i].idCliente,arrayAlquiler[i].idJuego,arrayAlquiler[i].fechaAlquiler.dia,arrayAlquiler[i].fechaAlquiler.mes,arrayAlquiler[i].fechaAlquiler.anio);
        }
    }
    system("pause");
}
