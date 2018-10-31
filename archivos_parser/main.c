#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char* key;
    char* value;

} sData;
int loadDataFile(char* fileName,sData* array,int len);

int main()
{
    sData datos[20];
    int cantidadLineasLeidas;
    int i;
    cantidadLineasLeidas = loadDataFile("datos.txt.txt",datos,20);
    printf("\n USUARIO \t CLAVE ");
    for(i=0;i<cantidadLineasLeidas;i++)
    {
        printf("\n %s \t %s ",datos[i].key,datos[i].value);
    }
    return 0;
}

int loadDataFile(char* fileName,sData* array,int len)
{
    FILE* pArchivo;
    char lineaSrt[128];
    char* pKey;
    char* pValue;
    int indexDivider;
    int keyLen;
    int valueLen;
    int index = 0;

    pArchivo = fopen(fileName,"r");
    if(pArchivo == NULL)
    {
        printf("\n Problemas al cargar el arcvivo!!!");
        exit(EXIT_FAILURE);
    }

    while(fgets(lineaSrt,128,pArchivo)!= NULL)
    {
        //BUSCO EL INDICE DONDE SE ENCUENTRA EL IGUAL DENTRO DE ESA CADENA
        indexDivider = strcspn(lineaSrt,"=");// DEVUELVE LA POSCION DONDE SE ENCUENTRA UBICADO EL CARACTER '='

        keyLen = indexDivider + 1; // SE SUMA 1 PARA QUE LA CADENA TERMINE EN '\0'

        valueLen = strlen(lineaSrt)-indexDivider-1;/* AL LINEA LEIDA SE LE RESTA LA CANTIDADDE CARACRTES DE LA CLAVE Y ME
                                                        COMO RESULTADO LA CANTIDAD DE CARACTERES DEL VALOR. */
        //RESERVO MEMORIA PARA LAS DOS CADENAS
        pKey = (char*)malloc(sizeof(char)*keyLen);
        pValue =(char*)malloc(sizeof(char)*valueLen);

        strncpy(pKey,lineaSrt,keyLen-1);
        pKey[keyLen-1]=0x00;
        strncpy(pValue,&lineaSrt[keyLen],valueLen-1);
        pValue[valueLen-1]= 0x00;

        array[index].key = pKey;
        array[index].value = pValue;
        index++;
        if(index >= len)
        {
            break;
        }
    }

    fclose(pArchivo);
    return index; //DEVUELVE LA CANTIDAD DE LINEAS QUE LEIMOS
}
