


typedef struct{
    int id;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[200];
    int puntaje;
    char linkImagen[1500];
    int estado;
}EMovie;

/** \brief Funcion que permite el alta de una pelicula a puntero de EMovie
 *
 * \param EMovie* Puntero a cargar datos
 * \param int Limite del puntero
 * \return int mayor a 0 si se dio el alta,-2 si hay error de ortografia y -1 si no quedan mas espacios
 *
 */
int agregarPelicula(EMovie*,int);
/** \brief Funcion que permite borrar una pelicula a puntero de EMovie
 *
 * \param EMovie* Puntero a borrar datos
 * \param int Limite del puntero
 * \return int mayor a 0 si se pudo borrar y -1 si se cancelo la baja
 *
 */
int borrarPelicula(EMovie*,int);
/** \brief Funcion que permite modificar una pelicula a puntero de EMovie
 *
 * \param EMovie* Puntero a modificar datos
 * \param int Limite del puntero
 * \return int mayor a 0 si se pudo modificar y -1 si se cancelo la modificacion
 *
 */
int modificarPelicula(EMovie* ,int );
/** \brief Funcion que permite mostrar el menu del dato que se desea modificar
 *
 * \param EMovie* Puntero a modificar datos
 * \param int Limite del puntero
 * \return int mayor a 0 si se pudo modificar y -1 si se cancelo la modificacion
 *
 */
int menuModificar(EMovie* ,int );




/** \brief Funcion que muestra datos de una estructura
 *
 * \param eMovie* variable de tipo estructura a mostrar
 * \param int Longitud de la variable de tipo estructura
 * \return int 0 si no pudo mostrar , 1 si pudo mostrar
 *
 */
int mostrarPunteroArray(EMovie*,int );
/** \brief Funcion que muestra solo una posicion de una estructura
 *
 * \param eMovie*  variable de tipo estructura a mostrar
 * \return int 0 si no pudo mostrar, 1 si pudo mostrar
 *
 */
int mostrarpunteroUno(EMovie* );
/**
 * Obtiene el primer indice libre del puntero.
 * @param EMovie* el puntero se pasa como parametro.
 * @param int limite del puntero
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EMovie*,int );

/** \brief Funcion que inicializa el estado de una persona en 0 para indicar que esta vacio
 *
 * \param [] EMoive* puntero a iniciar
 * \param int Limite del puntero
 * \return int -1  si no se pudo inicializar y 0<  si pudo inicializarlo
 *
 */
int iniciarEstado( EMovie*,int );
/** \brief Funcion que permite el id autoncremental de un puntero de peliculas
 *
 * \param eMovie* puntero de peliculas
 * \param int Longitud del puntero de peliculas
 * \return int Devuelve el id del peliculas incrementado en 1 si se pudo y sino devuelve 0
 *
 */
int siguienteId(EMovie*,int );
/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param EMovie* el puntero se pasa como parametro.
 * @param dni el dni a ser buscado en el puntero.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorId(EMovie*, int ,int);


/**
 * \brief Verifica si el valor recibido es numérico entero
 * \param char* puntero con la cadena a ser analizada
 * \return 1 si es númerico entero y 0 si no lo es
 *
 */

int esNumerico(char *) ;
/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param char* puntero con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char *);
/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param char* puntero con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char *);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param char* Es el mensaje a ser mostrado
 * \param char* puntero donde se cargará el texto ingresado
 * \return void
 */
void getString(char* mensaje,char* input);
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param char* Es el mensaje a ser mostrado
 * \param char* puntero donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */

int getStringLetras(char* mensaje,char* input);
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param char[] Es el mensaje a ser mostrado
 * \param char[] puntero donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números enteros
 */
int getStringNumeros(char* mensaje,char* input);
/**
 * \brief Solicita un texto Alfa numérico al usuario y lo devuelve
 * \param char* Es el mensaje a ser mostrado
 * \param char* puntero donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números enteros o letras
 */
int getAlfaNumerico(char* mensaje,char* input);
/**
 * \brief Funcion que permite ordenar el id de un puntero de EMovide de manera ascendente
 * \param EMoive* Es el puntero a ordenar
 * \param int Limite del puntero
 * \return void
 */
void ordenarPeliculasId(EMovie* ,int);
/**
 * \brief Funcion que permite cargar datos a un archivo binario
 * \param EMoive* Es el puntero con datos a cargar
 * \param int Limite del puntero
 * \return 0 si no se pudo cargar , 1 si se pudo cargar
 */
int cargarDesdeArchivo(EMovie* listado,int limite);
/**
 * \brief Funcion que permite guardar datos a un archivo binario
 * \param EMoive* Es el puntero con datos a guardar
 * \param int Limite del puntero
 * \return 0 si no se pudo guardar , 1 si se pudo guardar
 */
int guardarEnArchivo(EMovie * listado,int limite);
/**
 * \brief Funcion que crea un archivo html listando las peliculas ingresadas
 * \param EMoive* Es el puntero con datos
 * \param int Limite del puntero
 * \return void
 */
void crearHtml(EMovie *listado, int limite);

