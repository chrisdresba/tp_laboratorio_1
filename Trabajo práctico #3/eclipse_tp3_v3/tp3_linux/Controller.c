#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "Employee.h"
#include "utn.h"
#include "Controller.h"

int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {

	int retorno = -1;
	FILE *file = NULL;

	if (pArrayListEmployee != NULL) {
		file = fopen(path, "r+");

		if (file != NULL) {
			retorno = parser_EmployeeFromText(file, pArrayListEmployee);
		}
	}

	fclose(file);

	if (retorno > 0) {
		printf("La carga se realizo con exito");
	}

	return retorno;

}

int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {

	int retorno = -1;
	FILE *bin = NULL;

	if (pArrayListEmployee != NULL) {

		bin = fopen(path, "rb");

		if (bin != NULL) {

			retorno = parser_EmployeeFromBinary(bin, pArrayListEmployee);

		}

	}

	fclose(bin);

	if (retorno > 0) {
		printf("\nLa carga se realizo con exito");
	}

	return retorno;

}

int controller_addEmployee(LinkedList *pArrayListEmployee) {
	int retorno = 0;
	int auxId;
	char auxNombre[128];
	int auxHoras;
	float auxSueldo;

	Employee *buffer;

	if (pArrayListEmployee != NULL) {
		if (utn_getNombre(auxNombre, 129, "\nIngrese su nombre: ",
				"\n Se ingreso un nombre demasiado largo o un caracter que no es una letra. \n ",
				2) == 0
				&& utn_getNumero(&auxHoras,
						"\n Ingrese las horas trabajadas: 0-325 ",
						"\nIngreso un dato incorrecto", 0, 325, 2) == 0
				&& utn_getNumerofloat(&auxSueldo, "\n Ingrese el salario: ",
						"\nIngreso un dato incorrecto: 0-500000", 0, 500000, 2)
						== 0) {

			employee_setIdAuto(pArrayListEmployee, &auxId);

			buffer = employee_newParametros(&auxId, auxNombre, &auxHoras,
					&auxSueldo);

			ll_add(pArrayListEmployee, buffer);

			retorno = 1;

			if (retorno == 1) {
				printf("La carga se realizo con exito");

			}

		}
	} else {
		printf("\nError\n");

	}

	return retorno;

}

int controller_editEmployee(LinkedList *pArrayListEmployee) {

	int retorno = 0;
	int limite;
	int id;
	int auxId;
	char auxNombre[128];
	int auxHoras;
	float auxSueldo;
	int respuesta;
	int opcion;
	int reintentos = 2;

	Employee *buffer;

	if (pArrayListEmployee != NULL) {

		printf("\n\t<MODIFICAR EMPLEADO>\n ");

		controller_ListEmployee(pArrayListEmployee);
		do {

			/* Trabaje el limite de manera distinta obteniendo el ultimo ID
						 ya que si utilizo la funcion ll_len, obtengo el tamaño
						 pero si agrego 1 empleado (1001) y elimino 3 (998), no podria acceder al numero 1001
						 */

			employee_setIdAuto(pArrayListEmployee, &limite);

			limite -= 1;
			if (utn_getNumero(&id, "\n Ingrese el numero Id: \n",
					"\nIngreso un dato incorrecto", 0, limite, reintentos) != 0
					|| reintentos == 0) {
				break;
			};
			reintentos--;
			auxId = controller_findId(pArrayListEmployee, id);

			if (auxId > 0 && auxId <= limite) {

				buffer = ll_get(pArrayListEmployee, auxId);

				printf("\nSelecciono al empleado :\n");

				employee_print(buffer);
				respuesta =
						utn_getNumero(&opcion,
								"\n\t<MODIFICAR OPCIONES>\n \n1-Nombre, 2-Horas trabajadas, 3-Sueldo, 4-Salir\n ",
								"\nIngreso una opcion incorrecta", 1, 4, 2);
				if (!respuesta) {
					switch (opcion) {
					case 1:
						if (utn_getNombre(auxNombre, 129,
								"\nIngrese su nombre: ",
								"\n Se ingreso un nombre demasiado largo o un caracter que no es una letra. \n ",
								2) == 0) {
							employee_setNombre(buffer, auxNombre);
							retorno = 1;
						}
						break;
					case 2:
						if (utn_getNumero(&auxHoras,
								"\n Ingrese las horas trabajadas: 0-325 ",
								"\nIngreso un dato incorrecto", 0, 325, 2)
								== 0) {
							employee_setHorasTrabajadas(buffer, auxHoras);
							retorno = 1;
						}
						break;
					case 3:
						if (utn_getNumerofloat(&auxSueldo,
								"\n Ingrese el salario: ",
								"\nIngreso un dato incorrecto: 0-500000", 0,
								500000, 2) == 0) {
							employee_setSueldo(buffer, auxSueldo);
							retorno = 1;
						}
						break;
					case 4:

						break;
					}

				}

			}
		} while (retorno != 1 && opcion != 4);
	}

	if (retorno == 1) {
		printf("La modificacion se realizo con exito");
	} else {
		printf("\nNo se han realizado cambios\n");

	}

	return retorno;
}

int controller_removeEmployee(LinkedList *pArrayListEmployee) {
	int retorno = 0;
	int limite;
	int id;
	int auxId;
	int auxBaja;
	int reintentos = 2;
	Employee *buffer;

	if (pArrayListEmployee != NULL) {

		limite = ll_len(pArrayListEmployee);

		printf("\n\t<BORRAR EMPLEADO>\n ");
		controller_ListEmployee(pArrayListEmployee);

		do {

			/* Trabaje el limite de manera distinta obteniendo el ultimo ID
						 ya que si utilizo la funcion ll_len, obtengo el tamaño
						 pero si agrego 1 empleado (1001) y elimino 3 (998), no podria acceder al numero 1001
						 */

			employee_setIdAuto(pArrayListEmployee, &limite);

			limite -= 1;

			if (utn_getNumero(&id, "\n Ingrese el numero Id: \n",
					"\nIngreso un dato incorrecto", 0, limite, reintentos) != 0
					|| reintentos == 0) {
				break;
			};
			reintentos--;

			auxId = controller_findId(pArrayListEmployee, id);

			if (auxId > 0 && auxId <= limite) {

				buffer = ll_get(pArrayListEmployee, auxId);

				printf("\nDesea dar debaja al empleado :\n");
				employee_print(buffer);

				if (utn_getNumero(&auxBaja,
						"\n Ingrese 1 para Confirmar, 0 para Salir \n",
						"\nIngreso un dato incorrecto", 0, 1, 2) == 0) {

					if (auxBaja == 1) {
						ll_remove(pArrayListEmployee, auxId);
						employee_delete(buffer);

						printf("\nLa baja se realizo con exito\n");
						retorno = 1;
					} else {
						printf("\nNo se han realizado cambios\n");
						break;
					}
				}

			} else {
				printf("\nEl Id es incorrecto\n");

			}
		} while (retorno != 1);
	}

	return retorno;
}

int controller_ListEmployee(LinkedList *pArrayListEmployee) {
	int retorno = 0;
	int i;
	int limite;
	Employee *auxEmpleados;

	limite = ll_len(pArrayListEmployee);
	printf("ID    || NOMBRE     || HS TRABAJADAS ||  SUELDO \n");
	for (i = 0; i <= limite; i++) {

		auxEmpleados = (Employee*) ll_get(pArrayListEmployee, i);
		employee_print(auxEmpleados);
		retorno = 1;
	}

	return retorno;
}

int controller_sortEmployee(LinkedList *pArrayListEmployee) {

	int retorno = -1;
	int opcion;

	if (pArrayListEmployee != NULL) {
		do {
			if (utn_getNumero(&opcion,
					"\nIngrese el orden deseado: 1 Ascendente - 0 Descendente : ",
					"\nIngreso una opcion incorrecta", 0, 1, 2) == 0) {
				printf("\nProcesando...\n");
				ll_sort(pArrayListEmployee, employee_funcionSort, opcion);
				printf("\nTarea realizada.\n");
				retorno = 0;
				break;
			}
		} while (retorno == 0);
	}
	return retorno;

}

int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {

	int retorno = 0;
	FILE *file;
	int limite;
	int i;
	int auxId;
	char auxNombre[128];
	int auxHoras;
	float auxSueldo;
	Employee *auxEmpleado;

	if (path != NULL && pArrayListEmployee != NULL) {

		limite = ll_len(pArrayListEmployee);

		file = fopen(path, "w+");

		if (limite > 0) {

			for (i = 0; i < limite; i++) {

				auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);

				employee_save(auxEmpleado, &auxId, auxNombre, &auxHoras,
						&auxSueldo);

				fprintf(file, "%d,%s,%d,%.2f\n", auxId, auxNombre, auxHoras,
						auxSueldo);

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

int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {

	int retorno = 0;
	FILE *file = NULL;
	int limite;
	int i;

	Employee *auxEmpleado;

	if (path != NULL && pArrayListEmployee != NULL) {

		limite = ll_len(pArrayListEmployee);

		file = fopen(path, "w+b");

		if (limite > 0 && file != NULL) {

			for (i = 0; i < limite; i++) {

				auxEmpleado = ll_get(pArrayListEmployee, i);

				fwrite(&auxEmpleado, sizeof(Employee), 1, file);

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

int controller_findId(LinkedList *pArrayListEmployee, int id) {

	int retorno = 0;
	int limite;
	int i;
	int auxId;

	Employee *auxEmpleado;

	if (pArrayListEmployee != NULL) {

		limite = ll_len(pArrayListEmployee);

		if (limite > 0) {

			for (i = 0; i < limite; i++) {

				auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);

				buscarId(auxEmpleado, &auxId);

				if (auxId == id) {

					retorno = i;
				}
			}

		}

	}
	return retorno;
}

