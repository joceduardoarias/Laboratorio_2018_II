#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "peliculas.h"

void initMovie(ePeliculas* arrayPeliculas, int lenPeliculas )
{
    int i;
    for(i=0; i<lenPeliculas; i++)
    {
        arrayPeliculas[i].isEmpty= MOVIE_EMPTY;
    }
}
int buscarPrimeraOcurrencia(ePeliculas* arrayPeliculas, int lenPeliculas, int valor)
{
    int i;
    int retorno = -1;
    for(i=0; i<lenPeliculas; i++)
    {
        if(arrayPeliculas[i].isEmpty == valor || arrayPeliculas[i].isEmpty == MOVIE_DELETE)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int buscarPrimeraOcurrenciaId(ePeliculas* arrayPeliculas, int lenPeliculas, int idPelicula)
{
    int i;
    int retorno = -1;
    for(i=0; i<lenPeliculas; i++)
    {
        if(arrayPeliculas[i].idPeliculas == idPelicula && arrayPeliculas[i].isEmpty == MOVIE_USED)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int id_findNexId(ePeliculas* arrayPeliculas, int lenPeliculas)
{
    int i;
    int maxId = -1;
    int retorno = -1;
    if(arrayPeliculas != NULL && lenPeliculas > 0)
    {
        for(i=0; i<lenPeliculas; i++)
        {
            if(arrayPeliculas[i].isEmpty == MOVIE_USED || arrayPeliculas[i].isEmpty == MOVIE_DELETE)
            {
                if(arrayPeliculas[i].idPeliculas > maxId || maxId == -1)
                {
                    maxId = arrayPeliculas[i].idPeliculas;
                }
            }
        }
        retorno = maxId+1;
    }
    return retorno;
}
void setArrayPeliculas(ePeliculas* arrayPeliculas,int index,char* titulo,char* nacionalidad,int anio,int idDirector,int idPelicula,int estado)
{
    arrayPeliculas[index].idPeliculas = idPelicula;
    strcpy(arrayPeliculas[index].titulo,titulo);
    strcpy(arrayPeliculas[index].nacionalidad,nacionalidad);
    arrayPeliculas[index].anio = anio;
    arrayPeliculas[index].idDirector = idDirector;
    arrayPeliculas[index].isEmpty = estado;
}
void mostrarUnaPelicula(ePeliculas* arrayPeliculas, int index)
{
    printf("\n %03d\t\t%20s\t\t%s\t%d\t%d",arrayPeliculas[index].idPeliculas,arrayPeliculas[index].titulo,arrayPeliculas[index].nacionalidad,arrayPeliculas[index].anio,arrayPeliculas[index].idDirector);

}
void controlleraAbmPeliculas(ePeliculas* arrayPeliculas, int lenPeliculas)
{
    int opcion;
    char seguir = 's';
    int auxIdPelicula;
    int auxIdDirector;
    int anio;
    int i;
    int indiceResultadoBusqueda;

    char idPeliculaSrt[51];
    char tituloStr[51];
    char nacionalidadStr[51];
    char aniostr[20];
    char idDirectorStr[20];

    int IndexLugarLibre;
    do
    {
        system("cls");
        printf("\n1. ALTA \n2. BAJA \n3. MAODIFICACION \n4. LISTAR \n5. SALIR\n");
        opcion = getInt("\n Seleccione una opcion: ");
        switch(opcion)
        {
        case 1:
            system("cls");
            printf("\n ALTAS");
            IndexLugarLibre = buscarPrimeraOcurrencia(arrayPeliculas,lenPeliculas,MOVIE_EMPTY);
            if(IndexLugarLibre == -1)
            {
                printf("\n NO HAY LUGAR PARA CARGAR DATOS!!!");
                break;
            }
            auxIdPelicula = id_findNexId(arrayPeliculas,lenPeliculas);
            if(getStringLetras("\n Ingrese titulo pelicula: ",tituloStr)!= 1)
            {
                printf("\n INGRESE SOLO LETRAS!!!");
                break;
            }
            if(getStringLetras("\n Ingrese nacionalidad pelicula: ",nacionalidadStr)!= 1)
            {
                printf("\n INGRESE SOLO LETRAS!!!");
                break;
            }
            if(getStringNumeros("\nIngrese año estreno: ",aniostr)!=1)
            {
                printf("\nIngrese solo numeros: ");
                break;
            }
            anio = atoi(aniostr);
            if(getStringNumeros("\nIngrese id director: ",idDirectorStr)!=1)
            {
                printf("\nIngrese solo numeros: ");
                break;
            }
            auxIdDirector = atoi(idDirectorStr);
            setArrayPeliculas(arrayPeliculas,IndexLugarLibre,tituloStr,nacionalidadStr,anio,auxIdDirector,auxIdPelicula,MOVIE_USED);
            printf("\n\n");
            system("pause");
            break;
        case 2:
            printf("\n BAJAS");
            if(getStringNumeros("\n Ingrese Id pelicula: ", idPeliculaSrt)!= 1)
            {
                printf("\n Ingrese solo numeros!!!");
                break;
            }
            auxIdPelicula = atoi(idPeliculaSrt);
            if(buscarPrimeraOcurrenciaId(arrayPeliculas,lenPeliculas,auxIdPelicula)== -1)
            {
                printf("\n El id ingresado no esta en el sistema!!!");
                break;
            }
            indiceResultadoBusqueda = buscarPrimeraOcurrenciaId(arrayPeliculas,lenPeliculas,auxIdPelicula);
            mostrarUnaPelicula(arrayPeliculas,indiceResultadoBusqueda);
            seguir = getChar("\n confirmar baja (s/n): ");
            if(seguir == 's')
            {
                arrayPeliculas[indiceResultadoBusqueda].isEmpty = MOVIE_DELETE;
                printf("\n Baja existosa!!!");
            }
            else
            {
                printf("\n Baja cancelada.");
            }
            system("pause");
            break;
        case 3:
            system("cls");
            printf("\n MODIFICACION");
            do
            {
                system("cls");
                printf("\n1. TITULO \n2.NACIONALIDAD \n3.ANIO \n4.DIRECTOR\n5. SALIR \n");
                opcion = getInt("\n Seleccione una opcion: \n");
                switch(opcion)
                {
                case 1:
                    system("cls");
                    if(getStringNumeros("\n Ingrese id pelicula: ",idPeliculaSrt)!= 1)
                    {
                        printf("\n ingresar solo letras\n");
                        break;
                    }
                    auxIdPelicula = atoi(idPeliculaSrt);
                    if(buscarPrimeraOcurrenciaId(arrayPeliculas,lenPeliculas,auxIdPelicula)== -1)
                    {
                        printf("\n El id no existe en el sistema!!!");
                        break;
                    }
                    indiceResultadoBusqueda = buscarPrimeraOcurrenciaId(arrayPeliculas,lenPeliculas,auxIdPelicula);
                    mostrarUnaPelicula(arrayPeliculas,indiceResultadoBusqueda);
                    if(getStringLetras("\n Ingrese nuevo titulo: \n",tituloStr)!= 1)
                    {
                        printf("\n Ingrese solo letras !!!");
                        break;
                    }
                    seguir = getChar("\n Confirmar modificacion (s/n): \n");
                    if(seguir == 's')
                    {
                        strcpy(arrayPeliculas[indiceResultadoBusqueda].titulo,tituloStr);
                        printf("\n Modificacion exitosa!!!");
                    }
                    else
                    {
                        printf("\n Modificacion cancelada!!!");
                    }
                    printf("\n\n");
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    if(getStringNumeros("\n Ingrese id pelicula: ",idPeliculaSrt)!= 1)
                    {
                        printf("\n ingresar solo letras\n");
                        break;
                    }
                    auxIdPelicula = atoi(idPeliculaSrt);
                    if(buscarPrimeraOcurrenciaId(arrayPeliculas,lenPeliculas,auxIdPelicula)== -1)
                    {
                        printf("\n El id no existe en el sistema!!!");
                        break;
                    }
                    indiceResultadoBusqueda = buscarPrimeraOcurrenciaId(arrayPeliculas,lenPeliculas,auxIdPelicula);
                    mostrarUnaPelicula(arrayPeliculas,indiceResultadoBusqueda);
                    if(getStringLetras("\n Ingrese nuevo nacionalidad: \n",nacionalidadStr)!= 1)
                    {
                        printf("\n Ingrese solo letras !!!");
                        break;
                    }
                    seguir = getChar("\n Confirmar modificacion (s/n): \n");
                    if(seguir == 's')
                    {
                        strcpy(arrayPeliculas[indiceResultadoBusqueda].nacionalidad,nacionalidadStr);
                        printf("\n Modificacion exitosa!!!");
                    }
                    else
                    {
                        printf("\n Modificacion cancelada!!!");
                    }
                    printf("\n\n");
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    if(getStringNumeros("\n Ingrese id pelicula: ",idPeliculaSrt)!= 1)
                    {
                        printf("\n ingresar solo letras\n");
                        break;
                    }
                    auxIdPelicula = atoi(idPeliculaSrt);
                    if(buscarPrimeraOcurrenciaId(arrayPeliculas,lenPeliculas,auxIdPelicula)== -1)
                    {
                        printf("\n El id no existe en el sistema!!!");
                        break;
                    }
                    indiceResultadoBusqueda = buscarPrimeraOcurrenciaId(arrayPeliculas,lenPeliculas,auxIdPelicula);
                    mostrarUnaPelicula(arrayPeliculas,indiceResultadoBusqueda);
                    if(getStringNumeros("\n Ingrese nuevo anio: \n",aniostr)!= 1)
                    {
                        printf("\n Ingrese solo numeros !!!");
                        break;
                    }
                    anio = atoi(aniostr);
                    seguir = getChar("\n Confirmar modificacion (s/n): \n");
                    if(seguir == 's')
                    {
                        arrayPeliculas[indiceResultadoBusqueda].anio = anio;
                        printf("\n Modificacion exitosa!!!");
                    }
                    else
                    {
                        printf("\n Modificacion cancelada!!!");
                    }
                    printf("\n\n");
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    if(getStringNumeros("\n Ingrese id pelicula: ",idPeliculaSrt)!= 1)
                    {
                        printf("\n ingresar solo letras\n");
                        break;
                    }
                    auxIdPelicula = atoi(idPeliculaSrt);
                    if(buscarPrimeraOcurrenciaId(arrayPeliculas,lenPeliculas,auxIdPelicula)== -1)
                    {
                        printf("\n El id no existe en el sistema!!!");
                        break;
                    }
                    indiceResultadoBusqueda = buscarPrimeraOcurrenciaId(arrayPeliculas,lenPeliculas,auxIdPelicula);
                    mostrarUnaPelicula(arrayPeliculas,indiceResultadoBusqueda);
                    if(getStringNumeros("\n Seleccione director: \n",idDirectorStr)!= 1)
                    {
                        printf("\n Ingrese solo numeros !!!");
                        break;
                    }
                    auxIdDirector = atoi(idDirectorStr);
                    seguir = getChar("\n Confirmar modificacion (s/n): \n");
                    if(seguir == 's')
                    {
                        arrayPeliculas[indiceResultadoBusqueda].idDirector = auxIdDirector;
                        printf("\n Modificacion exitosa!!!");
                    }
                    else
                    {
                        printf("\n Modificacion cancelada!!!");
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
            break;
        case 4:
            printf("\n ID_PELEICULA \t\t TITULO \t NACIONALIDAD \t ANIO \t DIRECTOR\n");
            for(i=0; i<lenPeliculas; i++)
            {
                if(arrayPeliculas[i].isEmpty == MOVIE_USED)
                {
                    printf("\n %03d\t\t%20s\t\t%s\t%d\t%d\n",arrayPeliculas[i].idPeliculas,arrayPeliculas[i].titulo,arrayPeliculas[i].nacionalidad,arrayPeliculas[i].anio,arrayPeliculas[i].idDirector);

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
}
