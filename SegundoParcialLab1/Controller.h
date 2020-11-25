/** \brief Carga los datos desde el archivo data.csv (modo texto).
 *
 * \param path char* La ruta donde se encuentra el archivo
 * \param listaBicicletas LinkedList* La lista de bicicletas
 * \return int 1 si se cargo el archivo, -1 si no se cargo
 */
int controller_loadFromText(char* path, LinkedList* pListaBicicletas);

/** \brief Lista bicicletas
 *
 * \param listaBicicletas LinkedList* La lista de bicicletas
 * \return int 1 si se cargo el archivo, -1 si no se cargo
 */
int controller_ListarBicis(LinkedList* pListaBicicletas);

/** \brief Guarda los datos de los bicicletas en el archivo data.csv (modo texto).
 *
 * \param path char* La ruta donde se guardara el archivo
 * \param listaBicicletas LinkedList* La lista de bicicletas a guardar
 * \return int (1) si se guardaron bicicletas (-1) si no se guardaron
 */
int controller_guardarComoTexto(char* path, LinkedList* pListaBicicletas);

/** \brief Ordena los bicicletas
 *
 * \param listaBicicletas LinkedList* La lista de bicicletas
 * \return
 */
int controller_sortBicis(LinkedList* pListaBicicletas);
