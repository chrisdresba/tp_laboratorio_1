/*
 * utn.c
 *
 *  Created on: 25 nov. 2020
 *      Author: Cristian Barraza
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int retorno = -1;
	int buffer = 0;
	char cadena[10];

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
		do {
			printf("%s", mensaje);
			__fpurge(stdin);

			fgets(cadena, sizeof cadena, stdin);

			if(cadena[0] != '\n'){

				buffer = atoi(cadena);

			    if (buffer >= minimo && buffer <= maximo) {
				    *pResultado = buffer;
				     retorno = 0;
					break;
			    }
			};
			reintentos--;

			printf("%s", mensajeError);


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
					"\n\t<---Distribuidora de Artículos de Limpieza y Perfumería--->\n \n1. Cargar los datos de los articulos desde el archivo.\n \n2. Ordenar los articulos.\n \n3. Listar los articulos\n \n4. Generar descuentos y promociones \n \n5. Guardar los datos en archivo mapeado\n \n6. Informes \n \n7. Salir\n",
					"\nIngreso una opcion incorrecta\n", minimo, maximo, reintentos) == 0){
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

int utn_printInformes(int *pResultado,int minimo, int maximo,int reintentos){

	int opcion =-1;
	int retorno = -1;

		if(pResultado != NULL && minimo <= maximo){

			do{
			if(utn_getNumero(&opcion,
					"\n\t<---INFORMES--->\n \n1-Cantidad de Artículos cuyo precio sea mayor a $100\n \n2-Cantidad de Artículos del Rubro: CUIDADO DE ROPA\n  \n3-SALIR\n ",
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










