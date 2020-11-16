/*
 ============================================================================
 Name        : Trabajo.c
 Author      : Cristian Andres Barraza 1ºE
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo Practico 2 - Sistema de administración hasta 1000 empleados.
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"
#define CANT_EMPLEADOS 1000

int main(void) {
	setbuf(stdout, NULL);
	Employees arrayEmpleados[CANT_EMPLEADOS];
	int opcion;
	int respuesta;
	int salida = -1;
	int id = 1;
	int flag = 0;
	int idModify;
	int idRemove;
	int idOrder;

	initEmployees(arrayEmpleados, CANT_EMPLEADOS);

	do {

		respuesta =
				utn_getNumero(&opcion,
						"\n\t<---EMPLEADOS--->\n \n1-ALTAS\n \n2-MODIFICAR\n \n3-BAJAS\n \n4-INFORMAR\n \n5-SALIR\n",
						"\nIngreso una opcion incorrecta", 1, 5, 2);
		if (!respuesta) {

			switch (opcion) {
			case 1:

				if (addEmployee(arrayEmpleados, CANT_EMPLEADOS, &id,
						arrayEmpleados->name, arrayEmpleados->lastName,
						arrayEmpleados->salary, arrayEmpleados->sector) == 0) {
					flag++;

				}
				;
				break;
			case 2:
				if (flag != 0) {
					printf("\n\t<---EMPLEADOS--->\n");
					printEmployees(arrayEmpleados, CANT_EMPLEADOS);
					idModify = findEmployeeById(arrayEmpleados, CANT_EMPLEADOS,
							id);

					if (idModify != -1) {

						modifyEmployeeById(arrayEmpleados, CANT_EMPLEADOS,
								idModify);

					} else {
						printf("\nNo se pudo realizar la operación, revise los datos ingresados.");

					}

				} else {
					printf("\nPrimero debe cargar un empleado\n");
					getchar();
				}

				break;
			case 3:
				if (flag != 0) {
					printf("\n\t<---EMPLEADOS--->\n");
					printEmployees(arrayEmpleados, CANT_EMPLEADOS);
					idRemove = findEmployeeById(arrayEmpleados, CANT_EMPLEADOS,
							id);

					if (removeEmployee(arrayEmpleados, CANT_EMPLEADOS, idRemove)
							!= -1) {

						flag--;

					} else{
						printf("\nNo se pudo realizar la operación, revise los datos ingresados.");

					};

				} else {
					printf("\nPrimero debe cargar un empleado\n");
					getchar();
				}
				;

				break;
			case 4:
				if (flag != 0) {
					if (utn_getNumero(&idOrder,
							"\n Ordenar listado: A-Z -> 0 - Z->A 1 :\n",
							"\nIngreso un dato incorrecto", 0, 50, 2) == 0) {
						sortEmployees(arrayEmpleados, CANT_EMPLEADOS, idOrder);
						printEmployees(arrayEmpleados, CANT_EMPLEADOS);
						utn_calcularPromediosueldo(arrayEmpleados,
						CANT_EMPLEADOS);

					};
				} else {
					printf("\nPrimero debe cargar un empleado\n");
				}
				getchar();
				break;
			case 5:
				salida = 0;
				break;

			};

		}
		getchar();
		system("clear"); //UBUNTU

	} while (salida);

	return 0;
}
