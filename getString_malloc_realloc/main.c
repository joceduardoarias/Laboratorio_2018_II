#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utn.h>
char* getStringDinamic(char mensaje[]);
int main()
{
    char* nombre;
    nombre = getStringDinamic("\n Ingrese su nombre: ");
    printf("\n su nombre es: %s",nombre);
    return 0;
}
char* getStringDinamic(char mensaje[])
{
    char* pAux;
    char* retorno;
    int len;

    printf(mensaje);
    pAux = (char*)malloc(sizeof(char)*1024);
    scanf("%1023s",pAux);
    if(pAux != NULL)
    {
        len = strlen(pAux);
        retorno = (char*)realloc(pAux,sizeof(char)*(len+1));
    }
    else
    {
        printf("\n no s cargo el mensaje!!!\n");
    }
    return retorno;
}
