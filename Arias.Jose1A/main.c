#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "juegos.h"
#include "clientes.h"
#define TAM_GAME 50
#define TAM_CUSTUMER 100
int main()
{
    eJuegos juegos[TAM_GAME];
    eClientes clientes[TAM_CUSTUMER];
    int opcion;
    char seguir = 's';
    int indexLugarLIbre;
    int indexResultadoBusqueda;
    int auxId;
    float auxImporte;

    char idJuegosSrt[51];
    char descripcionSrt[51];
    char importeSrt[51];
    initGame(juegos,TAM_GAME);
    setArrayJuegos(juegos,"Bingo",200,1,0);
    setArrayJuegos(juegos,"Cara o Cruz",400,2,1);
    setArrayJuegos(juegos,"Dados",900,3,2);
    setArrayJuegos(juegos,"Loteria",500,4,3);
    setArrayJuegos(juegos,"Poker",1000,5,4);
    do
    {   system("cls");
        printf("\n1. ABM JUEGOS \n2.ABM CLIENTES \n3.ABM ALQUILER\n4. SALIR");
        opcion = getInt("\n Seleccione una opcion: ");
        switch(opcion)
        {
        case 1:
            controllerJuegos(juegos,TAM_GAME);
            break;
        case 2:
            controllerClientes(clientes,TAM_CUSTUMER);
            break;
        case 3:
            break;
        case 4:
            seguir = 'n';
            break;

        }
    }while(seguir == 's');
    return 0;
}
