

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona [],int );

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona [], int ,int);

/** \brief Funcion que inicializa el estado de una persona en 0 para indicar que esta vacio
 *
 * \param [] EPersona Array a iniciar
 * \param int Longitud del array
 * \return int -1  si no se pudo inicializar y 0<  si pudo inicializarlo
 *
 */
int iniciarEstado( EPersona [],int );
/** \brief Funcion que permite en ingreso de datos al array de EPersona
 *
 * \param [] EPersona Array a cargar datos
 * \param int Longitud del array
 * \param int si no hay lugar,-2 si ingresa dato erroneo,0< si ingreso la persona
 */
int EPersona_alta(EPersona [],int);
/** \brief Funcion que permite dar de baja una persona
 *
 * \param EPersona[] Array a dar de baja
 * \param int Longitud del array
 * \return int -1si el dni es incorrecto,-2 si ingresa dato erroneo,0< si la baja esta realizada
 *
 */
int EPersona_baja(EPersona[],int);

void EPersona_mostrarUno(EPersona );
/** \brief Funcion que muestra los datos de todas las personas ingresadas
 *
 * \param [] EPersona Array a mostrar
 * \param int Longitud del array
 * \return void
 *
 */
void EPersona_mostrarListado(EPersona [],int );
/** \brief Funcion que permite ordenar de manera alfabetica un array
 *
 * \param [] EPersona Array a ordenar
 * \param int Longitud del array

 * \return void
 *
 */
void ordenarPersona(EPersona [],int );

void grafico(EPersona [],int );

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param char[] Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char []);
/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char []);

/**
 * \brief Solicita un char al usuario y devuelve el resultado
 * \param char [] Es el mensaje a ser mostrado
 * \return El char ingresado por el usuario
 *
 */
char getChar(char []);


/**
 * \brief Verifica si el valor recibido es numérico entero
 * \param char[] Array con la cadena a ser analizada
 * \return 1 si es númerico entero y 0 si no lo es
 *
 */

int esNumerico(char []) ;
/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param char[] Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char []);
/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param char[] Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char []);
/**
 * \brief Verifica si el valor recibido es numérico flotante
 * \param char[] Array con la cadena a ser analizada
 * \return 1 si es númerico flotante  y 0 si no lo es
 *
 */
int esNumericoFlotante(char []);


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param char[] Es el mensaje a ser mostrado
 * \param char[] Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param char[] Es el mensaje a ser mostrado
 * \param char[] Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param char[] Es el mensaje a ser mostrado
 * \param char[] Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números enteros
 */
int getStringNumeros(char mensaje[],char input[]);
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param char[] Es el mensaje a ser mostrado
 * \param char[] Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números enteros o flotantes
 */
int getStringNumerosFlotantes(char mensaje[],char input[]);





