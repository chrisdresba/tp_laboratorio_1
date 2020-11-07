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


int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int retorno = -1;
	int buffer;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
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
			&& minimo <= maximo && reintentos >= 0) {
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

int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos){
	int retorno = -1;
	char buffer;
			if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >=0)
			{
				do{
				printf("%s",mensaje);
				__fpurge(stdin);

				if(scanf("%c", &buffer) == 1){

				if(buffer >= minimo && buffer <= maximo){
				*pResultado = buffer;
				retorno=0;
				break;
				}else{
					printf("%s",mensajeError);
					reintentos--;
					};
			     };
				}while(reintentos >= 0);

				}
	return retorno;
};


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
					if ((!(isspace(bufferString[i]))) && bufferString[i] != 164
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


int utn_printMenu(int *pResultado,int minimo, int maximo,int reintentos){

	int opcion =-1;
	int retorno = -1;

		if(pResultado != NULL && minimo <= maximo){

			do{
			if(utn_getNumero(&opcion,
					"\n\t<---TRABAJO PRACTICO 3--->\n \n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n \n2. Cargar los datos de los empleados desde el archivo bin.dat (modo binario).\n \n3. Alta de empleado\n \n4. Modificar datos de empleado\n \n5. Baja de empleado\n \n6. Listar empleados\n \n7. Ordenar empleados\n \n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n \n9. Guardar los datos de los empleados en el archivo bin.dat (modo binario).\n \n10.Salir\n",
					"\nIngreso una opcion incorrecta\n", minimo, maximo, 0) == 0){
							*pResultado = opcion;
							retorno = 0;
							break;
				}else{
					reintentos--;
				}

			}while(reintentos >=0);
			}

	return retorno;
};











