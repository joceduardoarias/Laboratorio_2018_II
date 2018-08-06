#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
int main()
{
    char nombre[200][20];
    char apellido[200][20];
    int legajo[200]= {101,102,103,104,105};
    char seguir='s';
    int opcion,i;
    int indiceLugarLibre;
    int indiceResultadoBusqueda;
    int auxLegajo;
    // char auxNombre;
    //char auxApellido;
    inicializarArrayInt(legajo,200,-1);

    do
    {
        printf("\n1. ALTA \n2. BAJA \n3. MODIFICACION\n4. LISTAR\n5. SALIR");
        opcion = getInt("\n Seleccione una opcion: ");

        switch(opcion)
        {
        case 1:
            indiceLugarLibre = buscarPrimeraOcurrencia(legajo,200,-1);

            if( indiceLugarLibre == -1)
            {
                printf("\n NO HAY LUGARES DISPONIBLES ");
                break;
            }
            printf("\n ALTA ");
            auxLegajo = getInt("\ningrese legajo: ");
            if(buscarPrimeraOcurrencia(legajo,200,auxLegajo)!= -1)
            {
                printf("\n El legajo %d  ya existe ", auxLegajo);
                break;
            }
            else
            {
                printf("\n ingrese el nombre: ");
                fflush(stdin);
                scanf("%s",nombre[indiceLugarLibre]);
                printf("\n ingrese el apellido: ");
                fflush(stdin);
                scanf("%s",apellido[indiceLugarLibre]);

            }
            legajo[indiceLugarLibre] =auxLegajo;


            break;
        case 2:
            printf("\n BAJA ");
            auxLegajo = getInt("\n ingrese legajo a dar de baja: ");
            indiceResultadoBusqueda = buscarPrimeraOcurrencia(legajo,200,auxLegajo);
            // la baja logica en el video es mas sencilla, pero de esta forma interprete las funciones
            // despues de probarlo funciona la baja logica sin problemas.
            if(buscarPrimeraOcurrencia(legajo,200,auxLegajo)!=-1)
            {
                legajo[indiceResultadoBusqueda] = -1;
                printf("\n El legajo %d %s %s fu dado de baja ", auxLegajo,nombre[indiceResultadoBusqueda],apellido[indiceResultadoBusqueda]);
            }
            else
            {
                printf("\n El legajo %d no se encuenta!!! ", auxLegajo);
            }
            break;
        case 3:
            printf("\nMODIFICACION ");
            auxLegajo = getInt("\n Ingrese legajo: ");
            indiceResultadoBusqueda = buscarPrimeraOcurrencia(legajo,200,auxLegajo);
            if(buscarPrimeraOcurrencia(legajo,200,auxLegajo)!= -1)
            {
                printf("\n ingrese nuevo nombre: ");
                scanf("%s", nombre[indiceResultadoBusqueda]);
                printf("\n ingrese nuevo apellido: ");
                scanf("%s", apellido[indiceResultadoBusqueda]);
            }
            else
            {
                printf(" El legajo %d no existe: ", auxLegajo);
            }
            break;
        case 4:
            printf("\n LEGAJO   NOMBRE   APELLIDO ");
            for(i=0; i<200; i++)
            {
                if(legajo[i] != -1)
                {
                    printf("\n %03d  %8s  %8s ", legajo[i],nombre[i],apellido[i]);
                }

            }
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');


    return 0;
}
