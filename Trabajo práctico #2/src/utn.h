/*
 * utn.h
 *
 *  Created on: 27 sep. 2020
 *      Author: Cristian Andres Barraza 1ºE
 */

#ifndef UTN_H_
#define UTN_H_
#include "ArrayEmployees.h"

/** \brief Valida el ingreso de un numero entero
* \param int puntero resultado
* \param mensaje que solicita un entero
* \param mensaje de error
* \param int minimo permitido
* \param int maximo permitido
* \param int cantidad de reintentos
* \return nos devuelve 0 si se valido la operacion o (-1) si se produjo un ERROR.
*
*/
int utn_getNumero(int * pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
/** \brief Valida el ingreso de un numero float
* \param float puntero resultado
* \param mensaje que solicita un entero
* \param mensaje de error
* \param int minimo permitido
* \param int maximo permitido
* \param int cantidad de reintentos
* \return nos devuelve 0 si se valido la operacion o (-1) si se produjo un ERROR.
*
*/
int utn_getNumerofloat(float* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);


/**
 * \brief Verifica y valida los datos ingresados(letras, espacio y longitud) que corresponda con la solicitado
 * \param pResultado puntero Resultado
 * \param int un máximo de longitud de la cadena de caracteres
 * \param mensaje que solicita un entero
 * \param mensaje de error
 * \param int cantidad de reintentos
 * \return Retorna 0 si se obtiene una cadena valida y -1 si se produjo un Error
 */
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);


/** \brief Calcula e imprime el promedio de Sueldos ingresados y la cantidad de sueldos por encima del promedio
* \al realizar la operacion verifica que isEmpty tenga el valor 0
* \param list Employee*
* \param int maximo permitido
*/
void utn_calcularPromediosueldo(Employees* list, int limite);

#endif /* UTN_H_ */
