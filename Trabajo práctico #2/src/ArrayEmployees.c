/*
 * ArrayEmployees.c
 *
 *  Created on: 27 sep. 2020
 *      Cristian Andres Barraza 1ºE
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"

int initEmployees(Employees *list, int limite) {
	int retorno = -1;
	int i;
	if (list != NULL && limite > 0) {

		for (i = 0; i < limite; i++) {
			list[i].isEmpty = 1;
			strcpy(list[i].name, " ");
			strcpy(list[i].lastName, " ");
			list[i].salary = 0;
			list[i].sector = 0;
			list[i].id = 0;

		}
		retorno = 0;
	};
	return retorno;
}

int addEmployee(Employees *list, int limite, int *id, char name[],
		char lastName[], float salary, int sector) {
	int retorno = -1;
	Employees buffer;
	int indice = -1;
	int i;

	for (i = 0; i < limite; i++) { //busca un indice vacio
		if (list[i].isEmpty == 1) {
			indice = i;
			break;
		}
	}

	if (list != NULL && limite > 0 && id != NULL && indice != -1) {
		if (utn_getNombre(buffer.name, 51, "\nIngrese su nombre: ",
				"\n Se ingreso un nombre demasiado largo o un caracter que no es una letra. \n ",
				2) == 0
				&& utn_getNombre(buffer.lastName, 51, "\nIngrese su apellido: ",
						"\n Se ingreso un apellido demasiado largo o un caracter que no es una letra. \n",
						2) == 0
				&& utn_getNumerofloat(&buffer.salary, "\n Ingrese el salario: ",
						"\nIngreso un dato incorrecto: 0-500000", 0, 500000, 2)
						== 0
				&& utn_getNumero(&buffer.sector, "\n Ingrese el sector: 1-50 ",
						"\nIngreso un dato incorrecto", 1, 50, 2) == 0) {

			list[indice].isEmpty = 0;
			strcpy(list[indice].name, buffer.name);
			strcpy(list[indice].lastName, buffer.lastName);
			list[indice].salary = buffer.salary;
			list[indice].sector = buffer.sector;
			list[indice].id = *id;

			*id = *id + 1;
			retorno = 0;

		}
	} else {
		printf("\nYa esta cargado el número maximo de empleados permitido\n");
		getchar();
	}

	return retorno;
}

int findEmployeeById(Employees *list, int limite, int id) {
	int retorno = -1;
	int idObtenido = 0;
	int i;

	if (list != NULL && limite > 0 && list != NULL) {
		if (utn_getNumero(&idObtenido, "\n Ingrese el Número de ID :\n",
				"\nIngreso un dato incorrecto", 0, 999, 2) == 0) {

			for (i = 0; i < limite; i++)

				if (list[i].id == idObtenido) {
					retorno = i;
					break;
				};

		}

	}
	return retorno; //retorna el valor del indice o -1 si no se encuentra el ID
}
;

int modifyEmployeeById(Employees *list, int limite, int id) {
	int retorno = -1;
	int respuesta;
	int opcion;
	int indice = id;

	if (list != NULL && limite > 0 && list[indice].isEmpty == 0) {
		respuesta =
				utn_getNumero(&opcion,
						"\n\t<MODIFICAR OPCIONES>\n \n1-Nombre, 2-Apellido, 3-Salario o 4-Sector\n ",
						"\nIngreso una opcion incorrecta", 1, 4, 2);
		if (!respuesta) {
			switch (opcion) {
			case 1:
				if (utn_getNombre(list[indice].name, 51,
						"\nIngrese su nombre: ",
						"\n Se ingreso un nombre demasiado largo o un caracter que no es una letra. \n",
						2) == 0) {
					retorno = 0;
				}
				break;
			case 2:
				if (utn_getNombre(list[indice].lastName, 51,
						"\nIngrese su apellido: ",
						"\n Se ingreso un apellido demasiado largo o un caracter que no es una letra. \n",
						2) == 0) {
					retorno = 0;
				}
				break;
			case 3:
				if (utn_getNumerofloat(&list[indice].salary,
						"\n Ingrese el salario: \n",
						"\nIngreso un dato incorrecto: 0-500000", 0, 500000, 2)
						== 0) {
					retorno = 0;
				}
				break;
			case 4:
				if (utn_getNumero(&list[indice].sector,
						"\n Ingrese el sector: 1-50 \n",
						"\nIngreso un dato incorrecto", 1, 50, 2) == 0) {
					retorno = 0;
				}
				break;
			}

		};
	}
	return retorno;
}
;

int removeEmployee(Employees *list, int limite, int id) {
	int retorno = -1;
	int indice = id;
	if (list != NULL && limite > 0 && list[indice].isEmpty == 0 && id >= 0) {
		list[indice].isEmpty = 1;

		printf("\nBAJA de ID exitosa");
		retorno = 0;
	}
	getchar();
	return retorno;
}

int sortEmployees(Employees *list, int limite, int order) {

	int flag;
	int i;
	int retorno = -1;
	Employees buffer;

	if (list != NULL && limite > 0) {
		do {
			flag = 0;

			for (i = 0; i < limite - 1; i++) {
				if (order == 0) {
					if (strcmp(list[i].lastName, list[i + 1].lastName) > 0
							|| (strcmp(list[i].lastName, list[i + 1].lastName)
									== 0 && list[i].sector < list[i + 1].sector)) {

						flag = 1;
						buffer = list[i];
						list[i] = list[i + 1];
						list[i + 1] = buffer;
					}
				} else if (strcmp(list[i].lastName, list[i + 1].lastName) < 0
						|| (strcmp(list[i].lastName, list[i + 1].lastName) == 0
								&& list[i].sector > list[i + 1].sector)) {

					flag = 1;
					buffer = list[i];
					list[i] = list[i + 1];
					list[i + 1] = buffer;
				}

			}
		} while (flag);
		retorno = 0;
	};
	return retorno;

}
;

int printEmployees(Employees *list, int limite) {
	int retorno = -1;
	int i;
	if (list != NULL && limite > 0) {

		for (i = 0; i < limite; i++) {
			if (list[i].isEmpty == 0) { //IMPRIME LOS EMPLEADOS CARGADOS
				printf("\nID %d - Nombre: %s, %s - Sueldo: $%.2f - Sector: %d.",
						list[i].id, list[i].lastName, list[i].name,
						list[i].salary, list[i].sector);
			}
		};
		retorno = 0;
	}

	return retorno;
}

