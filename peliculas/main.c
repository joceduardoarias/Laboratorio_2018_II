#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "peliculas.h"
#include "directores.h"
#define QTY_MOVIE 1000
#define QTY_DIRECTOR 500

int main()
{
    ePeliculas peliculas[QTY_MOVIE];
    char seguir = 's';
    int opcion;

    initMovie(peliculas,QTY_MOVIE);
    setArrayPeliculas(peliculas,0,"lacosa","Estados Unidos",1991,2,1,MOVIE_USED);
    setArrayPeliculas(peliculas,1,"los niños","Estados Unidos",1993,1,2,MOVIE_USED);
    setArrayPeliculas(peliculas,2,"Virgen de los Sicarios","Colombia",1991,3,3,MOVIE_USED);
    setArrayPeliculas(peliculas,3,"Muertos","España",2011,2,4,MOVIE_USED);
    setArrayPeliculas(peliculas,4,"Ciudad De Dios","Brasil",2013,2,5,MOVIE_USED);

    do
    {
        system("cls");
        printf("\n1. AMB PELICULAS \n2. ABM DIRECTORES \n3. SALIR \n");
        opcion= getInt("\n Seleccione una opccion: ");
        switch(opcion)
        {
        case 1:
            system("cls");
            controlleraAbmPeliculas(peliculas,QTY_MOVIE);
            system("pause");
            break;
        case 2:

            break;
        case 3:
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');


    return 0;
}

