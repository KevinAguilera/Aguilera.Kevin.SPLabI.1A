#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "bicicleta.h"
#include "Controller.h"
#include "LinkedList.h"
#include "parser.h"
#include "validations.h"

int controller_loadFromText(char* path, LinkedList* pListaBicicletas)
{
    int Ok = -1;
    FILE* pFile;
    if(path != NULL && pListaBicicletas != NULL)
    {
        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            if( parser_BiciFromText(pFile, pListaBicicletas) == 1)
            {
                Ok = 1;
                printf("Bicicletas cargadas. \n");
            }
            else
            {
                printf("No se pudieron cargar las bicicletas.\n");
            }
            fclose(pFile);
        }
        else
        {
            printf("\n El archivo no pudo abrirse.\n");
        }
    }
    return Ok;
}

int controller_ListarBicis(LinkedList* pListaBicicletas)
{
    eBicicleta* auxBici;
    int Ok = -1;
    int tam = ll_len(pListaBicicletas);
    int flag = 0;

    if( pListaBicicletas != NULL)
    {
        Ok = 1;
        printf("\n  ID                       Nombre                Tipo                        Tiempo \n");

        for(int i = 0; i< tam; i++)
        {
            auxBici = (eBicicleta*) ll_get(pListaBicicletas, i);
            if (  auxBici  != NULL )
            {
                mostrarBicicleta( auxBici );
                flag = 1;
            }
        }
        printf("\n\n");
        if(flag == 0)
        {
            printf("\nNo hay bicicletas.\n");
        }
    }
    return Ok;

}

int controller_guardarComoTexto(char* path, LinkedList* pListaBicicletas)
{
    FILE* f = fopen(path,"w") ;
    int tam =  ll_len(pListaBicicletas);
    eBicicleta* auxBicicleta;
    int Ok = -1;

    if(f != NULL)
    {
        fprintf(f,"id_bike,nombre,tipo,tiempo\n");
        for (int i =0; i<tam; i++)
        {
            auxBicicleta = (eBicicleta*) ll_get(pListaBicicletas, i);
            if (auxBicicleta !=NULL)
            {
                fprintf(f, "%d,%s,%s,%d\n", auxBicicleta->id_bike, auxBicicleta->nombre, auxBicicleta-> tipo, auxBicicleta->tiempo);
                Ok = 1;
            }
        }
        fclose(f);
    }
    return Ok;
}

int controller_sortBicis(LinkedList* pListaBicicletas)
{
    int ord = 1;
    int Ok =-1;

    if( pListaBicicletas != NULL)
    {
        Ok = ll_sort(pListaBicicletas, compararBicicletasPorTipoyTiempo, ord);
    }
    return Ok;
}
