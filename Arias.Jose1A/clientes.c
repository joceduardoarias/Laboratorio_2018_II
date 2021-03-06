#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "juegos.h"
#include "clientes.h"
void initCliente(eClientes* arrayClientes, int lenClientes )
{
    int i;
    for(i=0; i<lenClientes; i++)
    {
        arrayClientes[i].isEmpty= CUSTUMER_EMPTY;
    }
}
int buscarPrimeraOcurrenciaCliente(eClientes* arrayClientes, int lenClientes, int valor)
{
    int i;
    int retorno = -1;
    for(i=0; i<lenClientes; i++)
    {
        if(arrayClientes[i].isEmpty == valor || arrayClientes[i].isEmpty == CUSTUMER_DELETE)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int buscarPrimeraOcurrenciaIdCliente(eClientes* arrayClientes, int lenClientes, int idCliente)
{
    int i;
    int retorno = -1;
    for(i=0; i<lenClientes; i++)
    {
        if(arrayClientes[i].idCliente == idCliente && arrayClientes[i].isEmpty == CUSTUMER_USED)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int id_findNexIdCliente(eClientes* arrayClientes, int lenClientes )
{
    int i;
    int maxId = -1;
    int retorno = -1;
    if(arrayClientes != NULL && lenClientes > 0)
    {
        for(i=0; i<lenClientes; i++)
        {
            if(arrayClientes[i].isEmpty == CUSTUMER_USED || arrayClientes[i].isEmpty == CUSTUMER_DELETE)
            {
                if(arrayClientes[i].idCliente > maxId || maxId == -1)
                {
                    maxId = arrayClientes[i].idCliente;
                }
            }
        }
        retorno = maxId+1;
    }
    return retorno;
}
void setArrayClientes(eClientes* arrayClientes,char* nombre,char* apellido,char sexo,char* localidad,int idCliente,int indice)
{
    strcpy(arrayClientes[indice].nombre,nombre);
    strcpy(arrayClientes[indice].apellido,apellido);
    arrayClientes[indice].sexo = sexo;
    strcpy(arrayClientes[indice].localidad,localidad);
    arrayClientes[indice].idCliente = idCliente;
    arrayClientes[indice].isEmpty = CUSTUMER_USED;

}
void mostrarUnCliente(eClientes* arrayClientes, int indice)
{
    printf("\n %d \t %22s \t %16s \t %c \t %18s",arrayClientes[indice].idCliente,arrayClientes[indice].nombre,arrayClientes[indice].apellido,arrayClientes[indice].sexo,arrayClientes[indice].localidad);
}
void mostrarTodosClientes(eClientes* arrayClientes, int lenClientes )
{
    int i;
    system("cls");
    printf("\n ID_CLIENTE \t\t NOMBRE  \t\t APELLIDO \tSEXO \t\t LOCALIDAD \n");
    for(i=0; i<lenClientes; i++)
    {
        if(arrayClientes[i].isEmpty == CUSTUMER_USED)
        {
            mostrarUnCliente(arrayClientes,i);
        }
    }
    printf("\n\n");
    system("pause");
}
void AltaClientes(eClientes* arrayClientes, int lenClientes )
{
    char seguir = 's';
    int indexLugarLIbre;
    int auxId;
    char nombreSrt[51];
    char apellidoSrt[51];
    char localidadSrt[51];
    char sexo;

    system("cls");
    printf("\n ALTA \n");
    while(seguir == 's')
    {
        indexLugarLIbre = buscarPrimeraOcurrenciaCliente(arrayClientes,lenClientes,CUSTUMER_EMPTY);
        if(indexLugarLIbre == -1)
        {
            printf("\n No hay espacio en el sistema \n");
            break;
        }
        auxId = id_findNexIdCliente(arrayClientes,lenClientes);
        if(getStringLetras("\n Ingrese nombre: ",nombreSrt)!= 1)
        {
            printf("\n Ingrese solo letras!!!");
            break;
        }
        if(getStringLetras("\n Ingrese apellido: ",apellidoSrt)!= 1)
        {
            printf("\n Ingrese solo letras!!!\n");
            break;
        }
        if(getStringAlfanumerico("\n Ingrese direccion: ",localidadSrt)!= 1)
        {
            printf("\n Ingrese solo numeros o letras ");
            break;
        }
        sexo = getChar("\n Ingrese sexo (m/f): ");
        if(sexo!='f' && sexo!='m')
        {
            printf("\nSexo incorrecto, POR FAVOR PRESIONE 'f' para femeninio o 'm' para masculino!!!\n");
            break;
        }
        setArrayClientes(arrayClientes,nombreSrt,apellidoSrt,sexo,localidadSrt,auxId,indexLugarLIbre);
        seguir = getChar("\n seguir cargando datos (s/n): ");
    }

    printf("\n\n");
    system("pause");
}
void modificarClientes(eClientes* arrayClientes, int lenClientes )
{
    int opcion;
    char seguir = 's';
    int indexResultadoBusqueda;
    int auxIdCliente;

    char idClienteSrt[51];
    char nombreSrt[51];
    char apellidoSrt[51];
    char localidadSrt[51];
    char sexo;

    system("cls");
    printf("\n MODIFICACIONES\n");
    do
    {
        system("cls");
        printf("\n1. NOMBRE \n2. APELLIDO \n3. SEXO \n4. DIRECCION \n5. SALIR\n");
        opcion = getInt("\n Seleccione una opcion: ");
        switch(opcion)
        {
        case 1:
            system("cls");
            printf("\n MODIFICAR NOMBRE\n");
            if(getStringNumeros("\n Ingrese id cliente: ",idClienteSrt)!= 1)
            {
                printf("\n Ingrese solo numeros!!!\n");
                break;
            }
            auxIdCliente = atoi(idClienteSrt);
            if(buscarPrimeraOcurrenciaIdCliente(arrayClientes,lenClientes,auxIdCliente)==-1)
            {
                printf("\n El id ingresado no esta en el sistema \n");
                break;
            }
            indexResultadoBusqueda = buscarPrimeraOcurrenciaIdCliente(arrayClientes,lenClientes,auxIdCliente);
            mostrarUnCliente(arrayClientes,indexResultadoBusqueda);
            if(getStringLetras("\n Ingrese nueva nombre: ",nombreSrt)!= 1)
            {
                printf("\n Ingrese solo letras\n");
                break;
            }
            seguir = getChar("\n Confirmar modificacion (s/n): ");
            if(seguir == 's')
            {
                strcpy(arrayClientes[indexResultadoBusqueda].nombre,nombreSrt);
                printf("\n MODIFICACION EXITOSA !!!\n");
            }
            else
            {
                printf("\n Modificacion Cancelda!!!\n");
            }
            system("pause");
            break;
        case 2:
            system("cls");
            printf("\n MODIFICAR APELLIDO\n");
            if(getStringNumeros("\n Ingrese id cliente: ",idClienteSrt)!= 1)
            {
                printf("\n Ingrese solo numeros!!!\n");
                break;
            }
            auxIdCliente = atoi(idClienteSrt);
            if(buscarPrimeraOcurrenciaIdCliente(arrayClientes,lenClientes,auxIdCliente)==-1)
            {
                printf("\n El id ingresado no esta en el sistema \n");
                break;
            }
            indexResultadoBusqueda = buscarPrimeraOcurrenciaIdCliente(arrayClientes,lenClientes,auxIdCliente);
            mostrarUnCliente(arrayClientes,indexResultadoBusqueda);
            if(getStringLetras("\n Ingrese nueva apellido: ",apellidoSrt)!= 1)
            {
                printf("\n Ingrese solo letras\n");
                break;
            }
            seguir = getChar("\n Confirmar modificacion (s/n): ");
            if(seguir == 's')
            {
                strcpy(arrayClientes[indexResultadoBusqueda].apellido,apellidoSrt);
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
            system("cls");
            printf("\n MODIFICAR SEXO");
            if(getStringNumeros("\n Ingrese id cliente: ",idClienteSrt)!= 1)
            {
                printf("\n Ingrese solo numeros!!!");
                break;
            }
            auxIdCliente = atoi(idClienteSrt);
            if(buscarPrimeraOcurrenciaIdCliente(arrayClientes,lenClientes,auxIdCliente)==-1)
            {
                printf("\n El id ingresado no esta en el sistema \n");
                break;
            }
            indexResultadoBusqueda = buscarPrimeraOcurrenciaIdCliente(arrayClientes,lenClientes,auxIdCliente);
            mostrarUnCliente(arrayClientes,indexResultadoBusqueda);
            sexo = getChar("\n Ingrese nuevo sexo: ");
            if(sexo!='f' && sexo!='m')
            {
                printf("\nSexo incorrecto, POR FAVOR PRESIONE 'f' para femeninio o 'm' para masculino!!!\n");
                break;
            }
            seguir = getChar("\n Confirmar modificacion (s/n): ");
            if(seguir == 's')
            {
                arrayClientes[indexResultadoBusqueda].sexo = sexo;
                printf("\n MODIFICACION EXITOSA !!!\n");
            }
            else
            {
                printf("\n Modificacion Cancelda!!!\n");
            }
            break;
        case 4:
            system("cls");
            printf("\n MODIFICAR DIRECCION");
            if(getStringNumeros("\n Ingrese id cliente: ",idClienteSrt)!= 1)
            {
                printf("\n Ingrese solo numeros!!!");
                break;
            }
            auxIdCliente = atoi(idClienteSrt);
            if(buscarPrimeraOcurrenciaIdCliente(arrayClientes,lenClientes,auxIdCliente)==-1)
            {
                printf("\n El id ingresado no esta en el sistema \n");
                break;
            }
            indexResultadoBusqueda = buscarPrimeraOcurrenciaIdCliente(arrayClientes,lenClientes,auxIdCliente);
            mostrarUnCliente(arrayClientes,indexResultadoBusqueda);
            if(getStringAlfanumerico("\n Ingrese direccion: ",localidadSrt)!= 1)
            {
                printf("\n Ingrese solo numeros o letras ");
                break;
            }
            seguir = getChar("\n Confirmar modificacion (s/n): ");
            if(seguir == 's')
            {
                strcpy(arrayClientes[indexResultadoBusqueda].localidad,localidadSrt);
                printf("\n MODIFICACION EXITOSA !!!");
            }
            else
            {
                printf("\n Modificacion Cancelda!!!");
            }
            system("pause");
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');
    system("pause");
}
void bajaClientes(eClientes* arrayClientes, int lenClientes )
{
    char seguir = 's';

    int indexResultadoBusqueda;
    int auxId;


    char idClienteSrt[51];


    system("cls");
    printf("\nBAJAS\n");
    while(seguir == 's')
    {
        if(getStringNumeros("\n Ingrese id Cliente: ",idClienteSrt)!= 1)
        {
            printf("\n Ingrese solo numeros!!!");
            break;
        }
        auxId = atoi(idClienteSrt);
        if(buscarPrimeraOcurrenciaIdCliente(arrayClientes,lenClientes,auxId)== -1)
        {
            printf("\n El id ingresado no esta en el sistema!!!");
            break;
        }
        indexResultadoBusqueda = buscarPrimeraOcurrenciaIdCliente(arrayClientes,lenClientes,auxId);
        mostrarUnCliente(arrayClientes,indexResultadoBusqueda);
        seguir = getChar("\n Confirmar baja(s/n): ");
        if(seguir == 's')
        {
            arrayClientes[indexResultadoBusqueda].isEmpty = CUSTUMER_DELETE;
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
void controllerClientes(eClientes* arrayClientes, int lenClientes )
{
    int opcion;
    char seguir = 's';

    do
    {
        system("cls");
        printf("\n1. ALTA \n2. MODIFICACION \n3. BAJA \n4. LISTAR\n5. ORDENAMIENTO \n6. SALIR");
        opcion = getInt("\n Seleccione una opcion: ");
        switch(opcion)
        {
        case 1:
            AltaClientes(arrayClientes,lenClientes);
            break;
        case 2:
            modificarClientes(arrayClientes,lenClientes);
            break;
        case 3:
            bajaClientes(arrayClientes,lenClientes);
            break;
        case 4:
            mostrarTodosClientes(arrayClientes,lenClientes);
            break;
        case 5:
            ordenarmientoApellidoNombre(arrayClientes,lenClientes);
            break;
        case 6:
            seguir = 'n';
            break;

        }
    }
    while(seguir == 's');
}
void ordenarmientoApellidoNombre(eClientes* arrayClientes, int lenClientes)
{
    int i,j;
    eClientes auxClientes;

    for(i=0; i<lenClientes-1; i++)
    {
        if(arrayClientes[i].isEmpty == CUSTUMER_USED)
        {
            for(j=i+1; j<lenClientes; j++)
            {
                if(strcmpi(arrayClientes[i].apellido,arrayClientes[j].apellido)<0)
                {
                    auxClientes = arrayClientes[i];
                    arrayClientes[i] = arrayClientes[j];
                    arrayClientes[j] = auxClientes;
                }
                else
                {
                    if(strcmpi(arrayClientes[i].apellido,arrayClientes[j].apellido)==0)
                    {
                        if(strcmpi(arrayClientes[i].nombre,arrayClientes[j].nombre)<0)
                        {
                            auxClientes = arrayClientes[i];
                            arrayClientes[i] = arrayClientes[j];
                            arrayClientes[j] = auxClientes;
                        }
                    }
                }
            }
        }
    }

}
