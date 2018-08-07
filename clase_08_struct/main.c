#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main()
{
    char seguir = 's';
    int opcion,i;
    epersonas personaUno[200];
    int indiceLugarLibre;
    int indiceResultadoBusqueda;
    int auxLegajo;
    inicilizarEstructura(personaUno,200,-1);

    do
    {   system("cls");
        printf("\n                             AGENDA                                         ");
        printf("\n____________________________________________________________________________");
        printf(" \n ");
        printf("\n1. ALTAS\n2. BAJAS \n3. MODIFICACONES \n4. LISTAR \n5. ORDENAR \n6. SALIR ");
        opcion = getInt("\n Seleccione un opcion: ");
        system("pause");
        switch(opcion)
        {
        case 1:
            system("cls");
            printf("\n ALTA ");
            printf("  ");
            indiceLugarLibre = buscarPrimeraOcurrenciaEstructura(personaUno,200,-1);
            if(indiceLugarLibre == -1)
            {
                printf("\n NO EXISTE UN LUGAR LIBRE !!!");
                break;
            }
            auxLegajo = getInt("\n Ingrese el legajo: ");
            if(buscarPrimeraOcurrenciaEstructura(personaUno,200,auxLegajo)!= -1)
            {
                printf("\n EL LEGAJO %d YA EXISTE !!!", auxLegajo);
                break;
            }

            printf("\n ingrese el nombre: ");
            fflush(stdin);
            gets(personaUno[indiceLugarLibre].nombre);
            printf("\n ingrese el apellido: ");
            fflush(stdin);
            gets(personaUno[indiceLugarLibre].apellido);
            personaUno[indiceLugarLibre].legajo = auxLegajo;
            system("pause");
            break;
        case 2:
            system("cls");
            printf("\n BAJAS");
            printf(" ");
            auxLegajo = getInt("\nIngrese el legajo: ");
            indiceResultadoBusqueda = buscarPrimeraOcurrenciaEstructura(personaUno,200,auxLegajo);
            if(indiceResultadoBusqueda == -1)
            {
                printf("\n EL LEGAJO %d NO EXISTE", auxLegajo);
                break;
            }
            personaUno[indiceResultadoBusqueda].legajo = -1;
            printf("\n EL LEGAJO %d FUE DADO DE BAJA", auxLegajo);
            system("pause");
            break;
        case 3:
            system("cls");
            printf("\n MODIFICACION ");
            auxLegajo = getInt("\n Ingrese legajo a modificar: ");
            indiceResultadoBusqueda = buscarPrimeraOcurrenciaEstructura(personaUno,200,auxLegajo);
            if(indiceResultadoBusqueda == -1)
            {
                printf("\n EL LEGAJO %d NO EXISTE", auxLegajo);
                break;
            }
            printf("\n ingrese nuevo nombre: ");
            fflush(stdin);
            gets(personaUno[indiceResultadoBusqueda].nombre);
            printf("\n ingrese nuevo apellido: ");
            fflush(stdin);
            gets(personaUno[indiceResultadoBusqueda].apellido);
            system("pause");

            break;
        case 4:
            system("cls");
            printf("\n            LISTAR ");
            printf("\n _____________________________");
            printf("\n LEGAJO     NOMBRE    APELLIDO ");
            printf("\n _____________________________");
            for(i=0; i<200; i++)
            {
                if(personaUno[i].legajo != -1)
                {
                    printf("\n| %03d  | %8s | %8s | ", personaUno[i].legajo,personaUno[i].nombre,personaUno[i].apellido);
                    printf("\n _____________________________\n");
                }

            }
            system("pause");
            break;
        case 6:
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');
    return 0;
}
