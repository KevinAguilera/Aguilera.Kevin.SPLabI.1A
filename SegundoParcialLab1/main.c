#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bicicleta.h"
#include "controller.h"
#include "LinkedList.h"

int main()
{
    srand (time(NULL));
    LinkedList* listaBicicletas = ll_newLinkedList();
    char seguir = 's';
    char confirm ='n';
    char archivo[40];
    int posiciones = -1;

    do
    {
        switch(menu())
        {
        case 1:
            printf("Ingrese el nombre del archivo a cargar (Ejemplo: bicicletas.csv): ");
            scanf("%s", archivo);
            controller_loadFromText(archivo, listaBicicletas);
            system("pause");
            break;
        case 2:
            if( !ll_isEmpty(listaBicicletas))
            {
                controller_ListarBicis(listaBicicletas);
            }
            else
            {
                printf("La lista de bicicletas esta vacia. Debe cargar el archivo primero\n\n");
            }
            system("pause");
            break;
        case 3:

            if( !ll_isEmpty(listaBicicletas))
            {
                listaBicicletas = ll_map(listaBicicletas, cambiarTiempos);
                posiciones = 1;
                controller_ListarBicis(listaBicicletas);
            }
            else
            {
                printf("La lista esta vacia, debe cargar el archivo primero.\n\n");
            }
            system("pause");
            break;
        case 4:
            filtrarPorDistintosTipos(listaBicicletas);
            break;
        case 5:
            if(posiciones == 1 &&  !ll_isEmpty(listaBicicletas))
            {
                if (controller_sortBicis(listaBicicletas) != -1)
                {
                    controller_ListarBicis(listaBicicletas);
                }
            }
            else
            {
                printf("La lista esta vacia o no se asignaron tiempos.\n\n");
            }

            system("pause");
            break;
        case 6:
            if( posiciones == 1 &&  !ll_isEmpty(listaBicicletas))
            {
                controller_guardarComoTexto("bicicletasOrdenadas.csv", listaBicicletas);
                printf(" Se guardó las bicicletas ordenadas por posiciones en el archivo bicicletasOrdenadas.csv\n\n");
            }
            else
            {
                printf("La lista esta vacia o no se asignaron tiempos.\n\n");
            }
            system("pause");
            break;
        case 7:
            printf("Seguro que desea salir? [s/n] : ");
            fflush(stdin);
            scanf("%c", &confirm);
            if (confirm == 's')
            {
                seguir = 'n';
            }
            break;
        }
    }
    while(seguir == 's');
    ll_deleteLinkedList(listaBicicletas);
    return 0;
}

