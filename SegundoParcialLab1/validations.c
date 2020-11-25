#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validations.h"

int getString(char* cadena, int longitud)
{
    int retorno=-1;
    char bufferString[4096];

    if(cadena != NULL && longitud > 0)
    {
        fflush(stdin);
        if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
        {
            if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
            {
                bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
            }
            if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
            {
                strncpy(cadena,bufferString,longitud);
                retorno=0;
            }
        }
    }
    return retorno;
}

int getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    int bufferInt;
    do
    {
        printf("%s",mensaje);
        if(	getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
        {
            retorno = 1;
            *pResultado = bufferInt;
            break;
        }
        printf("%s",mensajeError);
        reintentos--;
    }
    while(reintentos>=0);

    return retorno;
}

int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[50];
    if(	pResultado != NULL &&
            getString(bufferString,sizeof(bufferString)) == 0 &&
            esNumerica(bufferString,sizeof(bufferString)))
    {
        retorno=0;
        *pResultado = atoi(bufferString) ;

    }
    return retorno;
}

int esNumerica(char* cadena, int limite)
{
    int retorno = -1;
    int i;
    if(cadena != NULL && limite > 0)
    {
        retorno = 1;
        for(i=0; i<limite && cadena[i] != '\0'; i++)
        {
            if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
            {
                continue;
            }
            if(cadena[i] < '0'||cadena[i] > '9')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
