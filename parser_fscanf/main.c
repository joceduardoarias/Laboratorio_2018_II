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
    int cantidadLeida ;
    int i;
    cantidadLeida = loadDataFile("datos.txt.txt",datos,20);
    printf("\n USUARIO \t CLAVE \n");
    for(i=0; i<cantidadLeida; i++)
    {
        printf("\n %s \t %20s ",datos[i].key,datos[i].value);
    }

    return 0;
}

int loadDataFile(char* fileName,sData* array,int len)
{
    FILE* pArchivo;
    char auxKey[50];
    char auxValue[50];
    char* pKey;
    char* pValue;
    int keyLen;
    int valueLen;
    int cantidadLeida;
    int index = 0;
    pArchivo = fopen(fileName,"r");
    if(pArchivo == NULL)
    {
        printf("\n Problemas al cargar el arcvivo!!!");
        exit(EXIT_FAILURE);
    }

    do
    {
        cantidadLeida = fscanf(pArchivo,"%[^=] = %[^\n]",auxKey,auxValue);
        //printf("%d",cantidadLeida);
        if(cantidadLeida==2)
        {
            keyLen = strlen(auxKey);
            valueLen = strlen(auxValue);
            //RESERVO MEMORIA PARA LAS DOS CADENAS
            pKey = (char*)malloc(sizeof(char)*(keyLen+1));
            pValue =(char*)malloc(sizeof(char)*(valueLen+1));

            strcpy(pKey,auxKey);
            strcpy(pValue,auxValue);

            array[index].key = pKey;
            array[index].value=pValue;
            index++;
        }
        else
        {
            break;
        }
    }
    while(!feof(pArchivo));

    //printf("\n %d", index);
    fclose(pArchivo);
    return index; //DEVUELVE LA CANTIDAD DE ELEMENTOS QUE CARGO EN EL ARRAY DE ESTRUCTURA
}
