#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "Controller.h"
#include "validations.h"

int menu()
{
    int option;

    system("cls");
    printf("1. Cargar archivo \n");
    printf("2. Imprimir lista \n");
    printf("3. Asignar tiempos.\n");
    printf("4. Filtrar por tipo seleccionado.\n");
    printf("5. Mostrar posiciones.\n");
    printf("6. Guardar posiciones. \n");
    printf("7. Salir.\n\n");
    if(getNumero(&option, "Eliga option: ","",1,7,0) == -1)
    {
        option = 0;
    }
    return option;
}

eBicicleta* nuevaBicicleta()
{
    return (eBicicleta*) malloc(sizeof(eBicicleta));
}

eBicicleta* nuevaBicicletaParam(char* id_bikeStr, char* nombre, char* tipo, char* tiempoStr)
{
    eBicicleta*  nuevaBici;

    nuevaBici = nuevaBicicleta();

    if(nuevaBici != NULL)
    {

        if((bicicleta_setId_bici(nuevaBici, atoi(id_bikeStr)) == -1) ||
                (bicicleta_setNombreBici(nuevaBici, nombre) == -1) ||
                (bicicleta_setTipoBici(nuevaBici, tipo) == -1) ||
                (bicicleta_setTiempoBici(nuevaBici, atoi(tiempoStr)) == -1))
        {
            borrarBicicleta(nuevaBici);
            nuevaBici = NULL;
        }
    }
    return nuevaBici;
}

int bicicleta_setId_bici(eBicicleta* this, int id_bike)
{
    int Ok = -1;

    if ( this != NULL && id_bike > 1 && id_bike <= 1000)
    {
        this-> id_bike = id_bike;
        Ok = 1;
    }
    return Ok;
}

int bicicleta_setNombreBici(eBicicleta* this, char* nombre)
{
    int Ok = -1;

    if (this != NULL  && strlen(nombre) >= 3  && strlen(nombre) < 30)
    {
        strcpy(this -> nombre, nombre);
        Ok = 1;
    }
    return Ok;
}

int bicicleta_setTipoBici(eBicicleta* this, char* tipo)
{
    int Ok = -1;

    if (this != NULL  && strlen(tipo) >= 3  && strlen(tipo) < 20)
    {
        strcpy(this -> tipo, tipo);
        Ok = 1;
    }
    return Ok;
}

int bicicleta_setTiempoBici(eBicicleta* this, int tiempo)
{
    int Ok = -1;

    if ( this != NULL && tiempo >= 0 && tiempo <= 1000)
    {
        this-> tiempo = tiempo;
        Ok = 1;
    }
    return Ok;
}

int bicicleta_getTipoBici(eBicicleta* this, char* tipo)
{
    int Ok = -1;
    if (this != NULL && tipo != NULL)
    {
        strcpy(tipo, this -> tipo);
        Ok = 1;
    }
    return Ok;

}

int bicicleta_getTiempoBici(eBicicleta* this, int* tiempo)
{
    int Ok = -1;
    if (this!= NULL && tiempo != NULL)
    {
        *tiempo = this-> tiempo;
        Ok =1;
    }
    return Ok;

}

void borrarBicicleta(eBicicleta* this )
{

    if ( this != NULL)
    {
        free(this);
    }

}

int mostrarBicicleta(eBicicleta* this)
{
    int Ok =-1;
    if(this != NULL)
    {
        Ok = 1;
        printf("%4d  %30s  %20s                     %4d \n", this->id_bike, this->nombre, this-> tipo, this-> tiempo);
    }
    return Ok;
}

void* cambiarTiempos(void* this)
{
    eBicicleta* auxBici;
    void * retorno = NULL;
    int aleatorio;
    if( this != NULL)
    {
        auxBici = (eBicicleta*) this;
        aleatorio = rand()%(71)+50;
        bicicleta_setTiempoBici(auxBici, aleatorio);
        retorno = (void*) auxBici;
    }
    return retorno;
}

int elegirTipo()
{
    int opcion;
    int opcionOk;
    system("cls");
    printf("--- Tipos de Bicicletas --- \n" );
    printf("1. BMX.\n");
    printf("2. Playera.\n");
    printf("3. MTB.\n");
    printf("4. Paseo.\n\n");

    opcionOk = getNumero(&opcion, "Ingrese tipo de bicicleta: ", "Error. Debe ingresar un numero entre 1 y 4.\n", 1,4, 3);

    if (opcionOk !=1)
    {
        opcion = -1;
    }
    return opcion;

}

void filtrarPorDistintosTipos(LinkedList* this)
{
    LinkedList* listaFiltrada = NULL;
    switch(elegirTipo())
    {
    case 1:
        listaFiltrada = ll_filter(this, TipoBMX);
        if( !ll_isEmpty(listaFiltrada))
        {
            controller_guardarComoTexto("bicicletasBMX.csv", listaFiltrada);
            printf("Se guardó las bicicletas BMX en el archivo bicicletasBMX.csv .\n\n");
        }
        else
        {
            printf("No se genero un archivo. Primero debe cargarlo (Opcion 1).\n\n");
        }
        system("pause");
        break;
    case 2:
        listaFiltrada = ll_filter(this, TipoPlayera);
        if( !ll_isEmpty(listaFiltrada))
        {
            controller_guardarComoTexto("bicicletasPlayeras.csv", listaFiltrada);
            printf("Se guardó las bicicletas Playeras en el archivo bicicletasPlayeras.csv.\n\n");
        }
        else
        {
            printf("No se genero un archivo. Primero debe cargarlo (Opcion 1).\n\n");
        }
        system("pause");
        break;
    case 3:
        listaFiltrada = ll_filter(this, TipoMTB);
        if( !ll_isEmpty(listaFiltrada))
        {
            controller_guardarComoTexto("bicicletasMTB.csv", listaFiltrada);
            printf("Se guardó las bicicletas MTB en el archivo bicicletasMTB.csv.\n\n");
        }
        else
        {
            printf("No se genero un archivo. Primero debe cargarlo (Opcion 1).\n\n");
        }
        system("pause");
        break;
    case 4:
        listaFiltrada = ll_filter(this, TipoPaseo);
        if( !ll_isEmpty(listaFiltrada))
        {
            controller_guardarComoTexto("bicicletasPaseo.csv", listaFiltrada);
            printf("Se guardó las bicicletas Paseo en el archivo bicicletasPaseo.csv.\n\n");
        }
        else
        {
            printf("No se genero un archivo. Primero debe cargarlo (Opcion 1).\n\n");
        }
        system("pause");
        break;
    case -1:
        printf("No se ha ingresado una opcion valida.\n\n");
        break;
    }
}

int TipoPlayera(void* this)
{
    eBicicleta* auxBici;
    int retorno = -1;
    char tipoBici[40];

    if( this != NULL)
    {
        auxBici = (eBicicleta*) this;

        if (bicicleta_getTipoBici(auxBici, tipoBici) != -1)
        {
            strlwr(tipoBici);
            if(strcmp(tipoBici, "Playera")== 0)
            {
                retorno =1;
            }
        }
    }
    return retorno;
}

int TipoBMX(void* this)
{
    eBicicleta* auxBici;
    int retorno = -1;
    char tipoBici[40];

    if( this != NULL)
    {
        auxBici = (eBicicleta*) this;

        if (bicicleta_getTipoBici(auxBici, tipoBici) != -1)
        {
            strlwr(tipoBici);
            if(strcmp(tipoBici, "BMS") == 0)
            {
                retorno =1;
            }
        }
    }
    return retorno;
}

int TipoMTB(void* this)
{
    eBicicleta* auxBici;
    int retorno = -1;
    char tipoBici[40];

    if( this != NULL)
    {
        auxBici = (eBicicleta*) this;

        if (bicicleta_getTipoBici(auxBici, tipoBici) != -1)
        {
            strlwr(tipoBici);
            if(strcmp(tipoBici, "MTB")== 0)
            {
                retorno =1;
            }
        }
    }
    return retorno;
}

int TipoPaseo(void* this)
{
    eBicicleta* auxBici;
    int retorno = -1;
    char tipoBici[40];

    if( this != NULL)
    {
        auxBici = (eBicicleta*) this;

        if (bicicleta_getTipoBici(auxBici, tipoBici) != -1)
        {
            strlwr(tipoBici);
            if(strcmp(tipoBici, "PASEO")== 0)
            {
                retorno =1;
            }
        }
    }
    return retorno;
}

int compararBicicletasPorTipoyTiempo(void* bicicletaA,void* bicicletaB)
{
    int orden = 0;

    if( bicicletaA != NULL && bicicletaB != NULL )
    {
        int tiempoBicicletaA;
        int tiempoBicicletaB;
        eBicicleta* pBicicletaA = (eBicicleta*) bicicletaA;
        eBicicleta* pBicicletaB = (eBicicleta*) bicicletaB;
        char tipoBicicletaA[40];
        char tipoBicicletaB[40];

        bicicleta_getTiempoBici(pBicicletaA, &tiempoBicicletaA);
        bicicleta_getTiempoBici(pBicicletaB, &tiempoBicicletaB);
        bicicleta_getTipoBici(pBicicletaA,tipoBicicletaA);
        bicicleta_getTipoBici(pBicicletaB,tipoBicicletaB);

        if (strcmp(tipoBicicletaA, tipoBicicletaB) > 0 )
        {
            orden = 1;
        }
        else if ( strcmp(tipoBicicletaA, tipoBicicletaB) ==0 )
        {
            if(tiempoBicicletaA > tiempoBicicletaB)
            {
                orden = 1;
            }
            else
            {
                orden = -1;
            }
        }

    }
    return orden;
}
