/*
 ============================================================================
 Name        : TP4
 Author      : Cristian Andres Barraza 1ºE
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "Articulo.h"
#include "Controller.h"
#include "informes.h"

int main() {
	setbuf(stdout, NULL);

	eRubro rubro[] =
			{ { 1, "CUIDADO DE ROPA" }, { 2, "LIMPIEZA Y DESINFECCION" },

			{ 3, "CUIDADO PERSONAL E HIGIENE" }, { 4, "CUIDADO DEL AUTOMOTOR" } };

	int option = 0;
	int optionInformes = 0;
	int respuesta;
	int informes;
	char auxArchivo[60];
	int flagCargaTexto = 0;
	int reintentos = 3;
	int salidaAux = 0;

	LinkedList *listaArticulos = ll_newLinkedList();

	do {
		respuesta = utn_printMenu(&option, 1, 7, 3);
		if (!respuesta) {
			switch (option) {
			case 1:
				if (flagCargaTexto == 0) { //carga la lista el usuario ingresa el nombre
					do {
						utn_getNombre(auxArchivo, 60,
								"\nIngrese el nombre del archivo para cargar los productos (datos): ",
								"", 0);

						if (strcmp(auxArchivo, "datos") == 0) {
							controller_loadFromText(auxArchivo, listaArticulos);
							flagCargaTexto = 1;
							reintentos = 3;
							break;
						} else {
							printf("\nError: dato incorrecto\n");
						}
						reintentos--;
					} while (reintentos != 0);

					if (flagCargaTexto != 1) {
						printf("\nNo se pudo abrir el archivo\n");
						reintentos = 3;
					}

				} else {
					printf(
							"\nNo puede cargar una lista nuevamente. Primero debe guardar los cambios\n");
				}
				;
				break;
			case 2:
				if (flagCargaTexto == 1) {
					//ordena la lista de articulos
					controller_sort(listaArticulos);
				} else {
					printf("\nPrimero debe cargar una lista\n");
				}
				;
				break;
			case 3:
				if (flagCargaTexto == 1) {
					//imprime la lista de articulos
					controller_printList(listaArticulos, rubro);

				} else {
					printf("\nPrimero debe cargar una lista\n");
				}
				;
				break;

			case 4:
				if (flagCargaTexto == 1) {
					//aplica descuentos con map
					controller_desc(listaArticulos);

				} else {
					printf("\nPrimero debe cargar una lista\n");
				}
				;
				break;
			case 5:

				if (flagCargaTexto == 1) {
					// guardamos el archivo en mapeado.csv
					controller_saveAsText("mapeado.csv", listaArticulos);

				} else {
					printf("\nPrimero debe cargar una lista\n");
				}
				;
				break;
			case 6:
				if (flagCargaTexto == 1) {
					salidaAux=3;

					do {
						system("clear"); //UBUNTU

						informes = utn_printInformes(&optionInformes, 1, 3,0);
						salidaAux--;

						if (!informes) {
							switch (optionInformes) {
							case 1:
								contarArticulosMayorOf(listaArticulos);
								getchar();
								break;
							case 2:
								contarArticulosDeRubro(listaArticulos);
								getchar();
								break;
							case 3:
								salidaAux = 0;

								break;

							}
						}

					} while (salidaAux);
				} else {
					printf("\nPrimero debe cargar una lista\n");
				};

				break;
			case 7:
				free(listaArticulos);
				break;
			}
		}

		getchar();
		system("clear"); //UBUNTU
	} while (option != 7);
	return 0;
}
