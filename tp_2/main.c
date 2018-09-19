#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "utn.h"
#define LEN_MAX 1000
void initEmployee(eEmployee* arrayEmployee, int len );
int main()
{
    eEmployee empleado[LEN_MAX];
    char seguir = 's';
    int opcion;
    int indiceLugarLibre;
    int indexResultadoBusqueda;
    int i;
    int contador = 0;

    int auxId;
    float auxSalario;
    int auxSector;

    char idSrt[51];
    char nombreSrt[51];
    char apellidoSrt[51];
    char salarioSrt[51];
    char sectorSrt[51];
    initEmployee(empleado,LEN_MAX);
    setArrayEmployee(empleado,0,"Jose","Arias",45.23,9,1,0);
    setArrayEmployee(empleado,1,"Juan","Munoz",56.23,2,2,0);
    setArrayEmployee(empleado,2,"Luis","Cadena",95.23,1,3,0);
    do
    {
        printf("\n1. ALTA \n2. BAJA \n3. MODIFICACION\n4. INFORMES\n5. SALIR");
        opcion = getInt("\n SELECCIONE UNA OPCION: ");

        switch(opcion)
        {
        case 1:
            system("cls");
            printf("\n ALTA");
            indiceLugarLibre = buscarPrimeraOcurrencia(empleado,LEN_MAX,1);
            if(indiceLugarLibre == -1)
            {
                printf("\n NO HAY ESPACIO PARA CARGAR DATOS!!!");
                break;
            }
            else
            {
                contador++;
            }

            /*
            if(getStringNumeros("\n Ingrese Id: ",idSrt) != 1)
            {
                printf("\n INGRESE SOLO NUMEROs!!!");
                break;
            }
            auxId = atoi(idSrt);
            if(buscarPrimeraOcurrencia(empleado,LEN_MAX,auxId)!= -1)
            {
                printf("\n EL ID YA EXISTE!!!");
                break;
            }
            */
            if(getStringLetras("\n Ingrese nombre: ",nombreSrt) != 1)
            {
                printf("\n INGRESE SOLO LETRAS!!!");
                break;
            }
            if(getStringLetras("\n Ingrese apellido: ",apellidoSrt) != 1)
            {
                printf("\n INGRESE SOLO LETRAS!!!");
                break;
            }

            if(getStringNumerosFlotantes("\n Ingrese el salario: ",salarioSrt) != 1)
            {
                printf("\n INGRESE SOLO NUMEROS!!!");
                break;
            }
            auxSalario = atof(salarioSrt);
            if(getStringNumeros("\n Ingrese sector: ",sectorSrt) != 1)
            {
                printf("\n INGRESE SOLO NUMEROs!!!");
                break;
            }
            auxSector = atoi(sectorSrt);
            setArrayEmployee(empleado,indiceLugarLibre,nombreSrt,apellidoSrt,auxSalario,auxSector,contador,0);
            system("pause");
            break;
        case 2:
            system("cls");
            printf("\n BAJA");
            if(getStringNumeros("\nIngrese Id: ",idSrt) != 1)
            {
                printf("\n INGRESE SOLO NUMEROs!!!");
                break;
            }
            auxId = atoi(idSrt);
            if(buscarPrimeraOcurrenciaId(empleado,LEN_MAX,auxId) == -1)
            {
                printf("\n EL ID NO EXISTE!!!");
                break;
            }
            indexResultadoBusqueda = buscarPrimeraOcurrenciaId(empleado,LEN_MAX,auxId);
            printf("\n ID\tNAME\tLASTNAME\tSALARY\tSECTOR");
            printf("\n %d \t%s\t%s\t\t%.2f \t%03d",empleado[i].id,empleado[indexResultadoBusqueda].name,empleado[indexResultadoBusqueda].lastName,empleado[indexResultadoBusqueda].salary,empleado[indexResultadoBusqueda].sector);
            seguir = getChar("\n CONTINUAR S/N: ");
            if(seguir == 's')
            {
                empleado[indexResultadoBusqueda].isEmpty = 1;
                printf("\n BAJA EXITOSA");
            }
            else
            {
                printf("\n BAJA CANCELADA");
                seguir = 's';
            }
            system("pause");
            break;
        case 4:
            system("cls");
            printf("\n INFORMES");
            printf("\n ID\tNAME\tLASTNAME\tSALARY\tSECTOR");
            for(i=0; i<LEN_MAX; i++)
            {
                if(empleado[i].isEmpty != 1)
                {
                    printf("\n %d \t%s\t%s\t\t%.2f \t%03d",empleado[i].id,empleado[i].name,empleado[i].lastName,empleado[i].salary,empleado[i].sector);
                }
            }
            printf("\n\n");
            system("pause");
            break;
        case 5:
            seguir = 'n';
            break;
        }

    }
    while(seguir == 's');
    return 0;
}
