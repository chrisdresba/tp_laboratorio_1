/*
 * Controller.c
 *
 *  Created on: 26 nov. 2020
 *      Author: Cristian Barraza
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "utn.h"
#include "Articulo.h"

int controller_loadFromText(char *path, LinkedList *pArrayList) {

	int retorno = -1;
	FILE *file = NULL;

	strcat(path,".csv");

	if (pArrayList != NULL) {
		file = fopen(path, "r+");

		if (file != NULL) {

			retorno = articulo_parserFromText(file, pArrayList);
		}
	}

	fclose(file);

	if (retorno > 0) {
		printf("La carga se realizo con exito");
	}

	return retorno;

}

int controller_sort(LinkedList *pArrayList) {

	int retorno = -1;
	int opcion = 1;

	if (pArrayList != NULL) {

		printf("\nProcesando...\n");
		ll_sort(pArrayList, articulo_funcionSort, opcion);
		printf("\nSe han ordenado los articulos alfabeticamente.\n");
		retorno = 0;

	}
	return retorno;

}

int controller_printList(LinkedList *pArrayList, eRubro rubro[]) {
	int retorno = 0;
	int i;
	int limite;
	eArticulo *auxArticulo;

	if (pArrayList != NULL) {

		limite = ll_len(pArrayList);
		printf("***************************************************************************************************");
		printf("\n|ID     |\tARTICULO\t\t\t|  MEDIDA   |  PRECIO   |  RUBRO \t\t  |\n");
		printf("***************************************************************************************************\n");
		for (i = 0; i <= limite; i++) {

			auxArticulo = (eArticulo*) ll_get(pArrayList, i);
			articulo_print(auxArticulo, rubro);
			retorno = 1;

		}
	}
	return retorno;
}

int controller_desc(LinkedList *pArrayList) {
	int retorno = -1;

	if (pArrayList != NULL) {

		ll_map(pArrayList, calcularDescuento);
		printf(
				"\nSe ha realizado un Descuento de un 20-OFF en articulos seleccionados de CUIDADO DE ROPA \n y un 10-OFF en articulos seleccionados de ELEMENTOS DE LIMPIEZA.\n");

		retorno = 0;
	}
	return retorno;
}

int controller_saveAsText(char *path, LinkedList *pArrayList) {

	int retorno = 0;
	FILE *file;
	int limite;
	int i;
	int auxId;
	char auxArt[128];
	float auxPrecio;
	char auxMedida[128];
	int auxRubroId;
	eArticulo *auxArticulo;

	if (path != NULL && pArrayList != NULL) {

		limite = ll_len(pArrayList);

		file = fopen(path, "w+");

		if (limite > 0) {

			for (i = 1; i < limite; i++) {

				auxArticulo = (eArticulo*) ll_get(pArrayList, i);

				articulo_save(auxArticulo, &auxId, auxArt, &auxPrecio,
						auxMedida, &auxRubroId);

				fprintf(file, "%d,%s,%s,%.2f,%d\n", auxId, auxArt, auxMedida,
						auxPrecio, auxRubroId);

				retorno++;
			}

		}

		fclose(file);

		if (retorno > 0) {
			printf("\nSe han guardado los datos con exito\n");
		} else {
			printf("\nError: Fallo la operacion\n");
		}

	}

	return retorno;
}
