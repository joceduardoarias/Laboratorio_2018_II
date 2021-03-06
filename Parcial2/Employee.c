#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include <string.h>
Employee* employee_new()
{
    Employee* this;

    this = malloc(sizeof(Employee));

    return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
    int horasTrabajadasAux;
    int idAux;
    int flag = 1;
    float sueldoAux;
    Employee* this;

    this = employee_new();

    idAux = atoi(idStr);
    if(employee_setId(this,idAux)!= 1)
    {
        flag=0;
    }

    horasTrabajadasAux = atoi(horasTrabajadasStr);
    if(employee_setHorasTrabajadas(this,horasTrabajadasAux)!= 1)
    {
        flag=0;
    }

    if(employee_setNombre(this,nombreStr)!= 1)
    {
        flag=0;
    }

    sueldoAux = atof(sueldo);
    if(employee_setSueldo(this,sueldoAux)!=1)
    {
        flag=0;
    }

    if(flag == 1)
    {
        printf("\n todos lo parametros se cargaron correctamente\n");
    }
    return this;
}
int employee_setId(Employee* this,int id)
{
    int retorno = 0;
    if(id>=0)
    {
        this->id = id;
    }
    else
    {
        retorno = 1;
    }

    return retorno;
}
int employee_getId(Employee* this,int* id)
{

    int retorno = 0;
    if(this != NULL && id >0)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    strcpy(this->nombre,nombre);
    return 1;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = 0;
    if(this != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 1;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = 0;
    if( horasTrabajadas>=0)
    {
        this->horasTrabajadas= horasTrabajadas;
        retorno = 1;
    }


    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = 0;

    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,float sueldo)
{
    int retorno = 0;
    if( sueldo>=0)
    {
        this->sueldo= sueldo;
        retorno = 1;
    }


    return retorno;
}
int employee_getSueldo(Employee* this,float* sueldo)
{
    int retorno=0;
    if(this != NULL)
    {
        *sueldo = this->sueldo;
        retorno=1;
    }
    return retorno;
}

int employeeByName(void* employeeA,void* employeeB)
{
    int retorno = 0;

    Employee* auxA;
    Employee* auxB;

    if(employeeA != NULL && employeeB != NULL)
    {
        auxA =(Employee*) employeeA;
        auxB =(Employee*) employeeB;
        if(strcmpi(auxA->nombre,auxB->nombre)<0)
        {
            retorno = 1;
        }
        if(strcmpi(auxA->nombre,auxB->nombre)>0)
        {
            retorno = -1;
        }

    }
    return retorno;
}
int employeeById(void* employeeA,void* employeeB)
{

    int retorno = 0;

    if(((Employee*)employeeA)->id<((Employee*)employeeB)->id)
    {
        retorno=1;
    }
    if(((Employee*)employeeA)->id>((Employee*)employeeB)->id)
    {
        retorno=-1;
    }
    return retorno;
}
int employeeByHorasTrabajadas(void* employeeA,void* employeeB)
{
    int retorno = 0;

    if(((Employee*)employeeA)->horasTrabajadas<((Employee*)employeeB)->horasTrabajadas)
    {
        retorno=1;
    }
    if(((Employee*)employeeA)->horasTrabajadas>((Employee*)employeeB)->horasTrabajadas)
    {
        retorno=-1;
    }
    return retorno;
}
int employeeBySalario(void* employeeA,void* employeeB)
{
    int retorno = 0;
    if(((Employee*)employeeA)->sueldo<((Employee*)employeeB)->sueldo)
    {
        retorno=1;
    }
    if(((Employee*)employeeA)->sueldo>((Employee*)employeeB)->sueldo)
    {
        retorno=-1;
    }
    return retorno;
}
int employee_filtro(void* p)
{
    float retorno;
    Employee* empleado;

    if(p != NULL)
    {
        empleado =(Employee*)p;
        retorno = empleado->horasTrabajadas;

    }
    return retorno;
}
