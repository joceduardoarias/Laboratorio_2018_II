#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "utn.h"

void initEmployee(eEmployee* arrayEmployee, int len )
{
    int i;
    for(i=0; i<len; i++)
    {
        arrayEmployee[i].isEmpty = 1;
    }
}
int buscarPrimeraOcurrencia(eEmployee* arrayEmpleado, int len, int valor)
{
    int i;
    int retorno = -1;
    for(i=0;i<len;i++)
    {
        if(arrayEmpleado[i].isEmpty == valor)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int buscarPrimeraOcurrenciaId(eEmployee* arrayEmpleado, int len, int valor)
{
    int i;
    int retorno = -1;
    for(i=0;i<len;i++)
    {
        if(arrayEmpleado[i].id == valor)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
void setArrayEmployee(eEmployee*  arrayEmpleado,int index,char* name,char* lastName,float salary,int sector,int id,int isEpmty)
{
    arrayEmpleado[index].id = id;
    strcpy(arrayEmpleado[index].name,name);
    strcpy(arrayEmpleado[index].lastName,lastName);
    arrayEmpleado[index].salary = salary;
    arrayEmpleado[index].sector = sector;
    arrayEmpleado[index].isEmpty = 0;
}
