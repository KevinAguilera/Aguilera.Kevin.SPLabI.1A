#include "LinkedList.h"
#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct
{
    int id_bike;
    char nombre[30];
    char tipo[20];
    int tiempo;
} eBicicleta;

#endif // BICICLETA_H_INCLUDED

/** \brief muestra opciones y devuelve la elegida por el usuario
 *
 * \return opcion elegida por el usuario
 */
int menu();

/** \brief constructor de eBicicleta
 *
 * \return un puntero a una eBicicleta
 */
eBicicleta* nuevaBicicleta();

/** \brief constructor de eBicicleta con atributos pasados por parametro
 *
 * \param char id de la bicicleta a crear
 * \param char nombre de la bicicleta a crear
 * \param char tipo de la bicicleta a crear
 * \param char tiempo de la bicicleta a crear
 * \return
 */
eBicicleta* nuevaBicicletaParam(char* id_bikeStr, char* nombre, char* tipo, char* tiempoStr);

/** \brief recibe por parametro el valor del id que le asignara a la bicicleta recibida
 *
 * \param eBicicleta* puntero a la eBicicleta a modificar
 * \param int id_bike que se le asignara a la eBicicleta recibida
 * \return 1 si pudo asignarla, -1 si no
 */
int bicicleta_setId_bici(eBicicleta* this, int id_bike);

/** \brief Establece un valor al campo nombre
 *
 * \param eBicicleta* El campo de la estructura donde se establecera el valor
 * \param char* El nombre que se va a establecer
 * \return int 1 si pudo establecer el valor, -1 si no pudo
 */
int bicicleta_setNombreBici(eBicicleta* this, char* nombre);

/** \brief Establece un valor al campo tipo
 *
 * \param eBicicleta* El campo de la estructura donde se establecera el valor
 * \param char* El tipo que se va a establecer
 * \return int 1 si pudo establecer el valor, -1 si no pudo
 */
int bicicleta_setTipoBici(eBicicleta* this, char* tipo);

/** \brief Establece un valor al campo tiempo
 *
 * \param eBicicleta* El campo de la estructura donde se establecera el valor
 * \param int Los tiempo que se van a establecer
 * \return int 1 si pudo establecer el valor, -1 si no pudo
 */
int bicicleta_setTiempoBici(eBicicleta* this, int tiempo);

/** \brief Obtiene un valor del campo tiempo
 *
 * \param eBicicleta* El campo de la estructura del que se desea obtener el valor
 * \param int* Donde se guardara el valor
 * \return int 1 si pudo establecer el valor, -1 si no pudo
 */
int bicicleta_getTiempoBici(eBicicleta* this, int* tiempo);

/** \brief Obtiene un valor del campo tipo
 *
 * \param eBicicleta* El campo de la estructura del que se desea obtener el valor
 * \param  char* Donde se guardara el valor
 * \return int 1 si pudo establecer el valor, -1 si no pudo
 */
int bicicleta_getTipoBici(eBicicleta* this, char* tipo);

/** \brief Libera el espacio en memoria
 *
 * \param eBicicleta* El campo de la estructura que se desea liberar
 * \return void
 */
void borrarBicicleta(eBicicleta* this );

/** \brief  Muestra una sola bicicleta y sus atributos
 *
 * \param eBicicleta* bicicleta a mostrar
 * \return int 1 si pudo mostrarla, -1 si no pudo
 */
int mostrarBicicleta(eBicicleta* this);

/** \brief Mapea las bicicletas por un tiempo aleatorio
 *
 * \param this void* La bicicleta a mapear
 * \return
 */
void* cambiarTiempos(void* this);

/** \brief Elige tipo de bicicleta
 *
 * \param
 * \return
 */
int elegirTipo();

/** \brief Pido por que tipo quiere filtrar
 *
 * \param
 * \param
 * \return
 */
void filtrarPorDistintosTipos(LinkedList* this);

/** \brief Si se filtra por tipo BMX
 *
 * \param
 * \param
 * \return
 */
int TipoBMX(void* this);

/** \brief Si se filtra por tipo Playera
 *
 * \param
 * \param
 * \return
 */
int TipoPlayera(void* this);


/** \brief Si se filtra por tipo Paseo
 *
 * \param
 * \param
 * \return
 */
int TipoPaseo(void* this);

/** \brief Si se filtra por tipo MTB
 *
 * \param
 * \param
 * \return
 */
int TipoMTB(void* this);

/** \brief Ordena los elementos por tipo y tiempo
 *
 * \param void* biciA El primer elemento a comparar
 * \param void* biciB El segundo elemento a comparar
 * \return
 */
int compararBicicletasPorTipoyTiempo(void* biciA,void* biciB);
