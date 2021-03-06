#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#define ESC 27
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    char option = 's';
    char archivo[51];
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaConSueldos = NULL;
    do{
        system("cls");
            menu();
        switch(option)
        {
            case '1':
                system("cls");
                if(getStringLetras("\n Ingrese el nombre del archivo: \n",archivo)!= 1)
                {
                    printf("\n Ingrese solo letras\n");
                    break;
                }
                controller_loadFromText(archivo,listaEmpleados);
                system("pause");
                break;
//            case '2':
//                controller_loadFromBinary("data.bin",listaEmpleados);
//                break;
//            case '3':
//               controller_addEmployee(listaEmpleados);
//                break;
//            case '4':
//                controller_editEmployee(listaEmpleados);
//                break;
//            case '5':
//                controller_removeEmployee(listaEmpleados);
//                break;
//            case '6':
//                system("cls");
//                controller_ListEmployee(listaEmpleados);
//                break;
//            case '7':
//                controller_sortEmployee(listaEmpleados);
//                break;
//            case '8':
//                controller_saveAsText("data.csv",listaEmpleados);
//                break;
//            case '9':
//                controller_saveAsBinary("data.bin",listaEmpleados);
//                break;
            case 'a':
                listaConSueldos = ll_map(listaEmpleados,employee_filtro);
                controller_ListEmployee(listaConSueldos);
                break;
            case 'b':
                controller_saveAsText("info.csv",listaConSueldos);
                break;
        }
    }while((option = getch())!= ESC);
    return 0;
}
