#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "juegos.h"
#include "clientes.h"
#include "alquiler.h"
#include "informes.h"
float totalJuegosAlquilados(eAlquiler* arrayAlquilres, int lenAlquilres,eJuegos* arrayJuegos,int lenJuegos)
{
    int i,j;
    float importeTotal;
    float acumulador = 0;

    for(i=0; i<lenAlquilres; i++)
    {
        if(arrayAlquilres[i].isEmpty == RENT_USED)
        {
            for(j=0; j<lenJuegos; j++)
            {
                if(arrayJuegos[j].isEmpty == GAME_USED && arrayJuegos[j].idJuego == arrayAlquilres[i].idJuego)
                {
                    acumulador = acumulador + arrayJuegos[j].importe;
                    importeTotal = acumulador;
                }
            }
        }
    }
    return importeTotal;
}
float promedioImporteJuegosAlquilados(eAlquiler* arrayAlquilres, int lenAlquilres,eJuegos* arrayJuegos,int lenJuegos)
{
    float importeTotal,importePromedio;
    int i,j;
    int contador = 0;
    importeTotal = totalJuegosAlquilados(arrayAlquilres,lenAlquilres,arrayJuegos,lenJuegos);
    for(i=0; i<lenAlquilres; i++)
    {
        if(arrayAlquilres[i].isEmpty == RENT_USED)
        {
            for(j=0; j<lenJuegos; j++)
            {
                if(arrayJuegos[j].isEmpty == GAME_USED && arrayJuegos[j].idJuego == arrayAlquilres[i].idJuego)
                {
                    contador++;
                }
            }
        }
    }
    importePromedio = importeTotal / contador;
    return importePromedio;
}
void cantidadJuegosPromedioAbajo(eAlquiler* arrayAlquilres, int lenAlquilres,eJuegos* arrayJuegos,int lenJuegos)
{
    int i;
    int contador = 0;
    float promedioImporte;

    promedioImporte = promedioImporteJuegosAlquilados(arrayAlquilres,lenAlquilres,arrayJuegos,lenJuegos);


    for(i=0; i<lenJuegos; i++)
    {
        if(arrayJuegos[i].isEmpty == GAME_USED)
        {
            if(arrayJuegos[i].importe < promedioImporte)
            {
                contador++;
            }
        }
    }
    printf("\n Cantidad de juegos por debajo del promedio: %d\n",contador);
    system("pause");
}
void listaClientesJuegoDeterminado(eAlquiler* arrayAlquilres, int lenAlquilres,eJuegos* arrayJuegos,int lenJuegos,eClientes* arrayClientes,int lenClientes)
{
    int i,j;
    int idJuego;

    mostrarTodosJuegos(arrayJuegos,lenJuegos);
    idJuego = getInt("\n Seleccion un juego: ");

    for(i=0; i<lenAlquilres; i++)
    {
        if(arrayAlquilres[i].idJuego == idJuego)
        {
            for(j=0; j<lenClientes; j++)
            {
                if(arrayClientes[j].idCliente == arrayAlquilres[i].idCliente)
                {
                    printf("\n Cliente \n %s \n",arrayClientes[j].nombre);
                }
            }
        }
    }
    system("pause");
}
void listaJuegosClientesDeterminado(eAlquiler* arrayAlquilres, int lenAlquilres,eJuegos* arrayJuegos,int lenJuegos,eClientes* arrayClientes,int lenClientes)
{
    int i,j;
    int idCliente;

    mostrarTodosClientes(arrayClientes,lenClientes);
    idCliente = getInt("\n Seleccion un cliente: ");

    for(i=0; i<lenAlquilres; i++)
    {
        if(arrayAlquilres[i].idCliente == idCliente )
        {
            for(j=0; j<lenClientes; j++)
            {
                if(arrayJuegos[j].idJuego == arrayAlquilres[i].idJuego)
                {
                    printf("\n Juego \n %s \n",arrayJuegos[j].descripcion);
                }
            }
        }
    }
    system("pause");
}
void controllerInformes(eAlquiler* arrayAlquilres, int lenAlquilres,eJuegos* arrayJuegos,int lenJuegos,eClientes* arrayClientes,int lenClientes)
{
    int opcion;
    char seguir = 's';

    do
    {


        system("cls");

        printf("\n1. PROMEDIO Y TOTAL  \n2. CANTIDAD \n3. LISTAR CLIENTES JUEGO DETERMINADO \n4. LISTAR JUEGOS CLIENTES DETERMINADO\n5. JUEGOS MENOS ALQUILADOS\n6. BURBUJEO MAS EFICIENTE\n7. ORDEMIENTO INSERCION\n8. LISTAR EL/LOS JUEGOS MENOS ALQUILADO/S \n10. SALIR \n");
        opcion= getInt("\n Seleccione una opcion: ");
        switch(opcion)
        {
        case 1:
            system("cls");
            printf("\n A.\n Importe Total: %.2f \n Importe Promedio: %.2f",totalJuegosAlquilados(arrayAlquilres,lenAlquilres,arrayJuegos,lenJuegos),promedioImporteJuegosAlquilados(arrayAlquilres,lenAlquilres,arrayJuegos,lenJuegos));
            system("pause");
            break;
        case 2:
            system("cls");
            cantidadJuegosPromedioAbajo(arrayAlquilres,lenAlquilres,arrayJuegos,lenJuegos);
            system("pause");
            break;
        case 3:
            system("cls");
            listaClientesJuegoDeterminado(arrayAlquilres,lenAlquilres,arrayJuegos,lenJuegos,arrayClientes,lenClientes);
            system("pause");
            break;
        case 4:
            system("cls");
            listaJuegosClientesDeterminado(arrayAlquilres,lenAlquilres,arrayJuegos,lenJuegos,arrayClientes,lenClientes);
            system("pause");
            break;
        case 6:
            bubbleSort(arrayJuegos,lenJuegos);
            break;
        case 7:
            ordenacion_insercion(arrayClientes,lenClientes);
            break;
        case 8:
            system("cls");
            juegosMenosAlquilados(arrayAlquilres,lenAlquilres,arrayJuegos,lenJuegos);
            system("pause");
            break;
        case 10:
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');

}

void bubbleSort (eJuegos* arrayJuegos,int lenJuegos)
{
    int j;
    eJuegos aux;
    int flagNoEstaOrdenado = 1;
    while (flagNoEstaOrdenado==1)
    {
        flagNoEstaOrdenado = 0;
        for (j = 1; j < lenJuegos; j++)
        {
            if (arrayJuegos[j].importe < arrayJuegos[j - 1].importe)
            {
                aux = arrayJuegos[j];
                arrayJuegos[j] = arrayJuegos[j - 1];
                arrayJuegos[j - 1] = aux;
                flagNoEstaOrdenado = 1;
            }
        }
    }
    mostrarTodosJuegos(arrayJuegos,lenJuegos);

}
void ordenacion_insercion (eClientes* arrayClientes, int lenClientes)
{
    int p, j;
    eClientes tmp;
    for (p = 1; p < lenClientes; p++)
    {
        tmp = arrayClientes[p];
        j = p - 1;
        while ((j >= 0) && (strcmpi(tmp.apellido, arrayClientes[j].apellido) <0 ))
        {
            arrayClientes[j + 1] = arrayClientes[j];
            j--;
        }
        arrayClientes[j + 1] = tmp;
    }
    mostrarTodosClientes(arrayClientes,lenClientes);
}
int cantidadAlquileresPorJuego(eAlquiler* arrayAlquilres, int lenAlquilres,int idJuego)
{
    int cantidad = 0;
    int i;

    for(i=0; i<lenAlquilres; i++)
    {
        if(arrayAlquilres[i].idJuego == idJuego && arrayAlquilres[i].isEmpty == RENT_USED)
        {
            cantidad++;
        }
    }
    return cantidad;
}
int minimoJuegosAlquilados(eAlquiler* arrayAlquilres, int lenAlquilres,eJuegos* arrayJuegos,int lenJuegos)
{
    int minimo;
    int flag = 0;
    int i;
    int cantidad;

    for(i=0; i<lenAlquilres; i++)
    {
        if(arrayAlquilres[i].isEmpty == RENT_USED)
        {
            cantidad =  cantidadAlquileresPorJuego(arrayAlquilres,lenAlquilres,arrayJuegos[i].idJuego);
            if(cantidad < minimo || flag == 0)
            {
                minimo = cantidad;
                flag = 1;
            }
        }

    }
    return minimo;
}
void juegosMenosAlquilados(eAlquiler* arrayAlquilres, int lenAlquilres,eJuegos* arrayJuegos,int lenJuegos)
{
    //int minimo;
    int cantidad;
    int i;

    cantidad = minimoJuegosAlquilados(arrayAlquilres,lenAlquilres,arrayJuegos,lenJuegos);

    printf("\n --- Juegos menos alquilados\n\n");

    for(i=0; i<lenAlquilres; i++)
    {
        if(arrayAlquilres[i].isEmpty == RENT_USED)
        {
            //cantidad = cantidadAlquileresPorJuego(arrayAlquilres,lenAlquilres,arrayJuegos[i].idJuego);
            if(cantidad == cantidadAlquileresPorJuego(arrayAlquilres,lenAlquilres,arrayJuegos[i].idJuego))
            {
                printf("\n %s \n",arrayJuegos[i].descripcion);
            }
        }

    }

}
