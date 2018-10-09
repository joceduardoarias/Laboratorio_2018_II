#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "juegos.h"
#include "clientes.h"
#include "alquiler.h"
#define TAM_GAME 10
#define TAM_CUSTUMER 100
#define TAM_RENT 1000
int main()
{
    eJuegos juegos[TAM_GAME];
    eClientes clientes[TAM_CUSTUMER];
    eAlquiler alquileres[TAM_RENT];
    int opcion;
    char seguir = 's';

    initGame(juegos,TAM_GAME);
    initCliente(clientes,TAM_CUSTUMER);
    initAlquiler(alquileres,TAM_RENT);

    setArrayJuegos(juegos,"Bingo",200,1,0);
    setArrayJuegos(juegos,"Cara o Cruz",400,2,1);
    setArrayJuegos(juegos,"Dados",900,3,2);
    setArrayJuegos(juegos,"Loteria",500,4,3);
    setArrayJuegos(juegos,"Poker",1000,5,4);

    setArrayClientes(clientes,"Juan","Gonzales",'m',"caba",1,0);
    setArrayClientes(clientes,"Maria","Rodriguez",'f',"caba",2,1);
    setArrayClientes(clientes,"Guadalupe","Garcia",'m',"avellaneda",3,2);
    setArrayClientes(clientes,"Juana","Gomez",'f',"boedo",4,3);
    setArrayClientes(clientes,"Jose Luis","Martinez",'m',"villa del parque",5,4);

    setArrayAlquiler(alquileres,1,4,1,0,1,12,1992);
    setArrayAlquiler(alquileres,2,5,3,1,30,1,2002);
    setArrayAlquiler(alquileres,3,3,2,2,23,8,2018);
    setArrayAlquiler(alquileres,4,1,4,3,17,2,2011);
    setArrayAlquiler(alquileres,5,2,5,4,8,11,2017);


    do
    {
        system("cls");
        printf("\n1. ABM JUEGOS \n2. ABM CLIENTES \n3. ABM ALQUILER\n4. SALIR");
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
            controllerAlquiler(alquileres,TAM_RENT,clientes,TAM_CUSTUMER,juegos,TAM_GAME);
            break;
        case 4:
            seguir = 'n';
            break;

        }
    }
    while(seguir == 's');
    return 0;
}
