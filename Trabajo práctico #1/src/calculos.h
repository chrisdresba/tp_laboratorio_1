/*
 * calculos.h
 *
 *  Created on: 7 sep. 2020
 *      Author: Cristian Barraza
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
/** \brief Valida un dato ingresado
 *	\param un puntero que devuelve el dato ingresado
 * \param mensaje de Error
 * \param cantidad de reintentos que permitiremos
 * \return Nos indica con un valor si se pudo realizar la accion o no
 */
int validarmenu(int* vresultado,char* mensajeError);
/** \brief Realiza la suma de dos numeros
 *
 * \param un numero a sumar
 * \param un numero a sumar
 * \return Retorna la suma de los numeros
 */
int sumar(int a,int b);
/** \brief Realiza la resta de dos numeros
 *
 * \param un numero entero
 * \param un numero entero
 * \return la resta de dos numeros
 */
int restar(int a,int b);
/** \brief Realiza la multiplicacion de dos numeros
 *
 * \param un numero a multiplicar
 * \param un numero a multiplicar
 * \return El producto de dos numeros
 */
int multiplicar(int a,int b);
/** \brief Realiza la division de dos numeros
 *	\param  un puntero que devuelve el resultado de la operacion
 * \param un numero dividendo
 * \param un numero divisor
 * \return Nos devuelve un valor que indica si se pudo realizar la operacion o no
 */
float dividir(float* Resultado,int a,int b);
/** \brief Realiza el factorial de un numero
 *
 * \param un numero entero
 * \return El factorial de un numero
 */
double factorial(int a);
#endif /* CALCULOS_H_ */
