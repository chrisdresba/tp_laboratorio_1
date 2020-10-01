/*
 * utn.c
 *
 *  Created on: 27 sep. 2020
 *      Author: Cristian Andres Barraza 1ºE
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int retorno = -1;
	int buffer;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& reintentos >= 0) {
		do {
			printf("%s", mensaje);
			__fpurge(stdin);

			if (scanf("%d", &buffer) == 1) {

				if (buffer >= minimo && buffer <= maximo) {
					*pResultado = buffer;
					retorno = 0;
					break;
				}
			};
			printf("%s", mensajeError);
			reintentos--;

		} while (reintentos >= 0);
	}
	return retorno;
}
;

int utn_getNumerofloat(float *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int retorno = -1;
	float buffer;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& reintentos >= 0) {
		do {
			printf("%s", mensaje);
			__fpurge(stdin);

			if (scanf("%f", &buffer) == 1) {

				if (buffer >= minimo && buffer <= maximo) {
					*pResultado = buffer;
					retorno = 0;
					break;
				}
			}
			printf("%s", mensajeError);
			reintentos--;

		} while (reintentos >= 0);

	}
	return retorno;
}
;

int utn_getNombre(char *pResultado, int longitud, char *mensaje,
		char *mensajeError, int reintentos) {
	char bufferString[100];
	int retorno = -1;
	int i;

	if (pResultado != NULL && mensaje != NULL && longitud > 0
			&& mensajeError != NULL && reintentos >= 0) {

		while (reintentos >= 0) {

			reintentos--;
			printf("%s", mensaje);
			__fpurge(stdin);
			fgets(bufferString, sizeof(bufferString), stdin);

			bufferString[strlen(bufferString) - 1] = '\0';

			if (strlen(bufferString) > 1 && strlen(bufferString) < longitud) {
				retorno = 0;

				for (i = 0; bufferString[i] != '\0' && i < longitud; i++) {
					if ((!(isspace(bufferString[i])))
							&& (!(isalpha(bufferString[i])))) {

						retorno = -1;

					}
				}

				if (retorno != -1) {

					strncpy(pResultado, bufferString, longitud);
					retorno = 0;
					break;
				}
			}
			printf("%s", mensajeError);

		}
	}
	return retorno;
}

void utn_calcularPromediosueldo(Employees *list, int limite) {
	float acum = 0;
	int cargados = 0;
	float pResultado = 0;
	int pCant = 0;
	int i;

	if (list != NULL && limite > 0) {

		for (i = 0; i < limite; i++) {

			if (list[i].isEmpty == 0) {
				acum = acum + list[i].salary;
				cargados++;
			}
		};
		pResultado = acum / cargados;

		for (i = 0; i < limite; i++) {

			if (list[i].isEmpty == 0 && list[i].salary > pResultado) {
				pCant++;
			}
		};

		printf(
				"\nEl total es $%.2f, con un sueldo promedio de $%.2f. \nLa cantidad de empleados que superan el sueldo promedio es %d persona/s",
				acum, pResultado, pCant);
	}

}
;
