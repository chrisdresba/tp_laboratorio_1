/*
 * Articulo.c
 *
 *  Created on: 26 nov. 2020
 *      Author: Cristian Barraza
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Articulo.h"
#include "utn.h"
#define RUBROCANT 4

eArticulo* articulo_new() {

	eArticulo *nuevoArticulo = NULL;

	nuevoArticulo = (eArticulo*) malloc(sizeof(eArticulo));

	if (nuevoArticulo != NULL)

	{
		nuevoArticulo->id = 0;
		strcpy(nuevoArticulo->articulo, " ");
		nuevoArticulo->precio = 0;
		strcpy(nuevoArticulo->medida, " ");
		nuevoArticulo->rubroId = 0;
	}

	return nuevoArticulo;
}
;

eArticulo* articulo_newParametros(int *id, char *articulo, float *precio,
		char *medida, int *rubroId) {

	eArticulo *nuevoArticulo = articulo_new();

	if (nuevoArticulo != NULL && id != NULL && articulo != NULL
			&& precio != NULL && medida != NULL && rubroId != NULL) {
		if (!(articulo_setId(nuevoArticulo, *id)
				&& articulo_setArticulo(nuevoArticulo, articulo)
				&& articulo_setPrecio(nuevoArticulo, *precio)
				&& articulo_setMedida(nuevoArticulo, medida)
				&& articulo_setRubro(nuevoArticulo, *rubroId)))

		{
			free(nuevoArticulo);
			nuevoArticulo = NULL;

		}

	}

	return nuevoArticulo;
}
;

void articulo_delete(eArticulo *this) {

	if (this != NULL) {
		free(this);
	}

}
;

int articulo_print(eArticulo *pUnArticulo, eRubro rubro[])

{
	int retorno = 0;
	char auxdes[128];

	if (pUnArticulo != NULL && rubro != NULL)

	{

		articulo_IdRubro(articulo_getRubro(pUnArticulo), rubro, auxdes);
		retorno = 1;
		printf("%-8d %-40s %-10s $%-10.2f %-15s\n", articulo_getId(pUnArticulo),
				articulo_getArticulo(pUnArticulo),
				articulo_getMedida(pUnArticulo),
				articulo_getPrecio(pUnArticulo), auxdes);
	}

	return retorno;

}

int articulo_funcionSort(void *item1, void *item2) {

	int retorno = 0;

	if (item1 != NULL && item2 != NULL) {

		if (strcmp(articulo_getArticulo(item1), articulo_getArticulo(item2))
				> 0) {
			retorno = 1;
		} else if (strcmp(articulo_getArticulo(item1),
				articulo_getArticulo(item2)) < 0) {
			retorno = -1;
		} else {
			retorno = 0;
		}
	}
	return retorno;

}

int articulo_setId(eArticulo *this, int id) {

	int retorno = 0;
	if (this != NULL && id > 0)

	{
		this->id = id;
		retorno = 1;
	}

	return retorno;

}
;

int articulo_getId(eArticulo *this) {
	return this->id;
}
;

int articulo_setArticulo(eArticulo *this, char *articulo) {

	int retorno = 0;

	if (this != NULL && articulo != NULL)

	{
		strcpy(this->articulo, articulo);
		retorno = 1;

	}

	return retorno;
}
;

char* articulo_getArticulo(eArticulo *this) {
	return this->articulo;
}
;

int articulo_setPrecio(eArticulo *this, float precio) {

	int retorno = 0;
	if (this != NULL && precio >= 0)

	{
		this->precio = precio;
		retorno = 1;
	}

	return retorno;
}
;

float articulo_getPrecio(eArticulo *this) {

	return this->precio;

}
;

int articulo_setMedida(eArticulo *this, char *medida) {

	int retorno = 0;

	if (this != NULL && medida != NULL)

	{
		strcpy(this->medida, medida);
		retorno = 1;

	}

	return retorno;
}
;

char* articulo_getMedida(eArticulo *this) {
	return this->medida;
}
;

int articulo_setRubro(eArticulo *this, int rubroId) {

	int retorno = 0;
	if (this != NULL && rubroId > 0)

	{
		this->rubroId = rubroId;
		retorno = 1;
	}

	return retorno;

}
;

int articulo_getRubro(eArticulo *this) {
	return this->rubroId;
}
;

int buscarId(eArticulo *this, int *id) {

	int retorno = 0;

	if (this != NULL && id != NULL)

	{
		*id = this->id;

		retorno = 1;
	}

	return retorno;
}

int articulo_save(eArticulo *pUnArticulo, int *id, char *articulo,
		float *precio, char *medida, int *rubroId)

{
	int retorno = 0;

	if (pUnArticulo != NULL && id != NULL && articulo != NULL && precio != NULL
			&& medida != NULL && rubroId != NULL)

	{
		*id = pUnArticulo->id;
		strcpy(articulo, pUnArticulo->articulo);
		*precio = pUnArticulo->precio;
		strcpy(medida, pUnArticulo->medida);
		*rubroId = pUnArticulo->rubroId;
		retorno = 1;
	}

	return retorno;

}

int articulo_parserFromText(FILE *pFile, LinkedList *pArrayList) {

	int result = 0;
	int cant = 0;
	eArticulo *buffer;
	char var1[128];
	char var2[128];
	char var3[128];
	int auxId;
	char auxArt[128];
	float auxPrecio;
	char auxMedida[128];
	int auxRubroId;

	if (pFile != NULL && pArrayList != NULL) {
		do {

			result = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", var1,
					auxArt, auxMedida, var2, var3);

			if (result == 5) {

				auxId = atoi(var1);
				auxPrecio = atoi(var2);
				auxRubroId = atoi(var3);

				buffer = articulo_newParametros(&auxId, auxArt, &auxPrecio,
						auxMedida, &auxRubroId);
				cant++;
				ll_add(pArrayList, buffer);
			} else {
				break;
			}
		} while (!feof(pFile));

	} else {
		printf("error");
	}

	return cant;

}
;

void calcularDescuento(eArticulo *this) {

	if (this != NULL) {

		if (articulo_getRubro(this) == 1 && articulo_getPrecio(this) >= 120) {

			articulo_setPrecio(this, ((articulo_getPrecio(this) / 100) * 80));

		};
		if (articulo_getRubro(this) == 2 && articulo_getPrecio(this) <= 200) {

			articulo_setPrecio(this, ((articulo_getPrecio(this) / 100) * 90));

		};

	}

}

int articulo_IdRubro(int id, eRubro rubro[], char *descripcion) {
	int retorno = -1;

	int i;

	if (id > 0 && rubro != NULL && descripcion != NULL) {

		for (i = 0; i < RUBROCANT; i++) {

			if (rubro[i].rubroId == id) {

				strcpy(descripcion, rubro[i].descripcion);
				retorno = 0;
				break;
			};

		}

	}
	return retorno; //retorna el valor del indice o -1 si no se encuentra el ID
}
;

int calcularPorPrecio(eArticulo *this) {

	int retorno = 0;

	if (this != NULL) {

		if (articulo_getPrecio(this) > 100) {

			retorno = 1;

		};

	}
	return retorno;

}

int calcularPorRubro(eArticulo *this) {

	int retorno = 0;
	if (this != NULL) {

		if (articulo_getRubro(this) == 1) {

			retorno = 1;

		};

	}
	return retorno;

}

