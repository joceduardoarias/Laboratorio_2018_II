#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_gestion.h"

int main()
{
    eproductos producto[1000],auxStruc;
    char seguir = 's';
    int opcion,i,j;
    int indiceLugarLibre;
    int indiceResultadoBusqueda;
    int auxId;
    inicializarArrayStruct(producto,1000,-1);

    do
    {   system("cls");
        printf("\n1. ALTA\n2. BAJA\n3. MODIFICACION\n4. LISTAR\n5. ORDENAR\n6. SALIR ");
        opcion = getInt("\n Selecione una opcion: ");
        system("pause");
        switch(opcion)
        {
        case 1:
            system("cls");
            printf("\nALTA");
            indiceLugarLibre = buscarPrimeraOcurrencia(producto,1000,-1);
            if(indiceLugarLibre == -1)
            {
                printf("\n No hay lugares libres para cargar datos");
                break;
            }
            auxId = getInt("\n Ingrese el ID: ");
            if(buscarPrimeraOcurrencia(producto,1000,auxId)!= -1)
            {
                printf("\n El producto %d ya existe", auxId);
                break;
            }
            producto[indiceLugarLibre].id = auxId;
            printf("\n Ingrese descripcion del producto: ");
            fflush(stdin);
            gets(producto[indiceLugarLibre].descripcion);
            fflush(stdin);
            printf("\n Ingrese la cantidad: ");
            scanf("%d",&producto[indiceLugarLibre].cantidad);
            printf("\n Ingrese el importe: ");
            scanf("%f",&producto[indiceLugarLibre].importe);
            system("pause");
            break;
        case 2:
            system("cls");
            printf("\n BAJA ");
            auxId = getInt("\n Ingrese ID del producto a dar de baja: ");
            if(buscarPrimeraOcurrencia(producto,1000,auxId) == -1)
            {
                printf("\n El ID %03d del producto no existe ", auxId);
                break;
            }
            indiceResultadoBusqueda = buscarPrimeraOcurrencia(producto,1000,auxId);
            producto[indiceResultadoBusqueda].id = -1;
            system("pause");
            break;
        case 3:
            system("cls");
            printf("\n MODIFICACIONES ");
            auxId = getInt("\n Ingrese ID de producto a modificar: ");
            if(buscarPrimeraOcurrencia(producto,1000,auxId)== -1)
            {
                printf("\n El ID %d del producto no existe !!!",auxId);
                break;
            }
            indiceResultadoBusqueda = buscarPrimeraOcurrencia(producto,1000,auxId);
            printf("\n ingrese nueva descripcion: ");
            fflush(stdin);
            gets(producto[indiceResultadoBusqueda].descripcion);
            printf("\n Ingrese nuevo stock: ");
            fflush(stdin);
            scanf("%d",&producto[indiceResultadoBusqueda].cantidad);
            printf("\n Ingrese nuevo stock: ");
            fflush(stdin);
            scanf("%f",&producto[indiceResultadoBusqueda].importe);
            system("pause");
            break;
        case 4:
            system("cls");
            printf("\n ID   DESCRIPCION  CANTIDAD  IMPORTE ");
            for(i=0; i<1000; i++)
            {
                if(producto[i].id != -1)
                {
                    printf("\n %03d %10s %10d %10.2f ", producto[i].id,producto[i].descripcion,producto[i].cantidad,producto[i].importe);
                }
            }
            system("pause");
            break;
        case 5:
            printf("\n ORDENAR ");
            for(i=0;i<1000-1;i++)
            {
                for(j=i+1;j<1000;j++)
                {
                    if(strcmp(producto[i].descripcion,producto[j].descripcion)>0)
                    {
                        auxStruc = producto[i];
                        producto[i]=producto[j];
                        producto[j]=auxStruc;

                    }
                }
            }
            break;
        case 6:
            seguir = 'n';
            system("pause");
            break;
        }
    }
    while(seguir == 's');
    return 0;
}
