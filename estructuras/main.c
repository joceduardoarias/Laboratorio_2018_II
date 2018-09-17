#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3
typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;
typedef struct
{
    int legajo;
    char nombre[51];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;

} eEmpleado;

int main()
{
    eEmpleado unEmpleado[TAM] =
    {
        {1,"jose juan",'m',1324654,{1,5,2008}},
        {2,"maria jose",'f',346874,{1,5,2008}},
        {3,"diana carolina",'f',1324164,{1,5,2008}}
    };
    int cantidad,i;
/*
    // unEmpleado = {1,"jose",'m',15.95}; no se puede harcodear por fuera de la sentencia
    for(i=0; i<TAM; i++)
    {
        printf("\n ingrese legajo: ");
        scanf("%d",&unEmpleado[i].legajo);
        fflush(stdin);
        printf("\n ingrese nombre: ");
        fgets(unEmpleado[i].nombre,sizeof(unEmpleado[i].nombre),stdin);
        cantidad = strlen(unEmpleado[i].nombre);
        unEmpleado[i].nombre[cantidad-1] = '\0';
        fflush(stdin);
        printf("\n ingrese sexo: ");
        scanf("%c",&unEmpleado[i].sexo);
        printf("\n ingrese sueldo: ");
        scanf("%f",&unEmpleado[i].sueldo);
        printf("\n fecha ingreso d/m/anio: ");
        scanf("%d",&unEmpleado[i].fechaIngreso.dia);
        scanf("%d",&unEmpleado[i].fechaIngreso.mes);
        scanf("%d",&unEmpleado[i].fechaIngreso.anio);
    }
    */

    for(i=0; i<TAM; i++)
    {
        printf("\n %d \t %s \t %c \t %.2f \t %02d/  %02d/ %d",unEmpleado[i].legajo,unEmpleado[i].nombre,unEmpleado[i].sexo,unEmpleado[i].sueldo,unEmpleado[i].fechaIngreso.dia,unEmpleado[i].fechaIngreso.mes,unEmpleado[i].fechaIngreso.anio);

    }




    return 0;
}
