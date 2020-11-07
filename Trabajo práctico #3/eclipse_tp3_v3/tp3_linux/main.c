#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
 Menu:
 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
 3. Alta de empleado
 4. Modificar datos de empleado
 5. Baja de empleado
 6. Listar empleados
 7. Ordenar empleados
 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
 10. Salir
 *****************************************************/

int main() {
	setbuf(stdout,NULL);

	int option = 0;
	int respuesta;
	int flagCargaTexto = 0;
	int flagCargaBin = 0;
	int flagAdd = 0;
	int flagSave = -1;

	LinkedList *listaEmpleados = ll_newLinkedList();

	do {
		respuesta = utn_printMenu(&option, 1, 10, 3);
		if (!respuesta) {
			switch (option) {
			case 1:
				if (flagCargaTexto == 0 && flagCargaBin == 0) {

					controller_loadFromText("data.csv", listaEmpleados);

					flagCargaTexto = 1;
					flagCargaBin = 1;
				} else {
					printf(
							"\nNo puede cargar una lista nuevamente. Primero debe guardar los cambios\n");
				}
				;
				getchar();
				break;
			case 2:
				if (flagCargaTexto == 0 && flagCargaBin == 0 && flagSave == 0) {
					controller_loadFromBinary("bin.dat", listaEmpleados);
					flagCargaTexto = 1;
					flagCargaBin = 1;
				}else if(flagSave != 0){
					printf(
					"\nPara abrir la lista primero debe guardar los datos en modo Binario\n");

				}else {
					printf(
							"\nNo puede cargar una lista nuevamente. Primero debe guardar\n");
				}
				getchar();
				break;
			case 3:
				if (flagCargaTexto == 1 || flagCargaBin == 1) {

					controller_addEmployee(listaEmpleados);
					flagAdd++;

				} else {
					printf("\nPrimero debe cargar una lista\n");
				}
				;
				getchar();
				break;
			case 4:
				if (flagAdd > 0) {
					if (flagCargaTexto == 1 || flagCargaBin == 1) {

						controller_editEmployee(listaEmpleados);

					} else {
						printf("\nPrimero debe cargar una lista\n");
					};
				} else {
					printf("\nPrimero debe dar de Alta a un empleado\n");
				}
				;
				getchar();
				break;
			case 5:
				if (flagAdd > 0) {
					if (flagCargaTexto == 1 || flagCargaBin == 1) {

						controller_removeEmployee(listaEmpleados);

					} else {
						printf("\nPrimero debe cargar una lista\n");
					}
				} else {
					printf("\nPrimero debe dar de Alta a un empleado\n");
				}
				;
				getchar();
				break;
			case 6:
				if (flagCargaTexto == 1 || flagCargaBin == 1) {

					controller_ListEmployee(listaEmpleados);

				} else {
					printf("\nPrimero debe cargar una lista\n");
				}
				;
				getchar();
				break;
			case 7:
				if (flagCargaTexto == 1 || flagCargaBin == 1) {

					controller_sortEmployee(listaEmpleados);

				} else {
					printf("\nPrimero debe cargar una lista\n");
				}
				;
				getchar();
				break;
			case 8:

				if (flagCargaTexto == 1 || flagCargaBin == 1) {

					controller_saveAsText("data.csv", listaEmpleados);

					flagCargaTexto = 0;
					flagCargaBin = 0;
					flagAdd = 0;

					free(listaEmpleados);
					listaEmpleados = ll_newLinkedList();

				}else {
					printf("\nPrimero debe cargar una lista\n");
				}
				;
				getchar();
				break;
			case 9:
				if (flagCargaTexto == 1 || flagCargaBin == 1) {

					controller_saveAsBinary("bin.dat", listaEmpleados);

					flagCargaTexto = 0;
					flagCargaBin = 0;
					flagAdd = 0;
					flagSave = 0;

					free(listaEmpleados);
					listaEmpleados = ll_newLinkedList();
				}else {
					printf("\nPrimero debe cargar una lista\n");
				}
				;
				getchar();
				break;
			case 10:
				free(listaEmpleados);
				break;
			}
		}

		 getchar();
		 system("clear"); //UBUNTU
	} while (option != 10);
	return 0;
}

