/*
 * informes.c
 *
 *  Created on: 26 nov. 2020
 *      Author: dresba
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "informes.h"

int contarArticulosMayorOf(LinkedList *pArrayList) {

	int retorno = 0;

	if (pArrayList != NULL) {

		retorno = ll_count(pArrayList,calcularPorPrecio);

		if (retorno > 0) {
			printf(
					"\nLos Artículos cuyo precio superan los $100 son: %d productos.\n",
					retorno);
		} else {
			printf("\nNo se encontraron Artículos que superen los $100.\n");
		}
	}

	return retorno;
}

int contarArticulosDeRubro(LinkedList *pArrayList) {
	int retorno = -1;

	if (pArrayList != NULL) {

		retorno = ll_count(pArrayList,calcularPorRubro);
		if (retorno > 0) {
			printf(
					"\nPuede encontrar %d Artículos del rubro cuidado de ropa.\n",
					retorno);
		} else {
			printf(
					"\nNo se encontraron Artículos del rubro cuidado de ropa.\n");
		}
	}

	return retorno;
}
