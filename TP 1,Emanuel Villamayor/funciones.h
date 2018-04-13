#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Funcion que suma dos numeros

 * \param float Primer numero a sumar
 * \param float Segundo numero a sumar
 * \return float La suma de los dos numeros
 *
 */
float suma(float,float);


/** \brief Funcion que resta dos numeros
 *
 * \param float Primer numero a ser restado
 * \param float Segundo numero a ser restado
 * \return float La resta de los dos numeros
 *
 */
float resta(float,float);


/** \brief Funcion que multiplica dos numeros
 *
 * \param float Ingreso del primer numero
 * \param float Ingreso del segundo numero
 * \return float Resultado entre la multiplicacion de los dos numeros
 *
 */

float multi(float,float);



/** \brief Funcion que divide dos numeros
 *
 * \param float numero divisor
 * \param float numero dividendo
 * \return float Resultado de division
 *
 */
float division(float ,float );
/** \brief  Calcula el factorial de un numero
 *
 * \param float Primer numero ingresado
 *
 * \return int El factor de el numero ingresado como parametro
 *
 */
 int factorial(float);

 /** \brief Funcion que valida que el factorial no sea decimal ni negativo
  *
  * \param float Primer numero ingresado
  * \return char que valida el resultado
  *
  */
 char validarFactorial(float );





#endif // FUNCIONES_H_INCLUDED
