#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee) {

	int result = 0;
	int cant = 0;
	Employee *buffer;
	char var1[129];
	char var2[129];
	char var3[129];
	int auxId;
	char auxNombre[128];
	int auxHoras;
	float auxSueldo;


		if (pFile != NULL && pArrayListEmployee != NULL) {
		do {

			result = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", var1,
					auxNombre, var2, var3);

			if (result == 4) {

				auxId = atoi(var1);
				auxHoras = atoi(var2);
				auxSueldo = atoi(var3);

				buffer = employee_newParametros(&auxId, auxNombre, &auxHoras,
						&auxSueldo);
				cant++;
				ll_add(pArrayListEmployee, buffer);
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


int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee) {


	int cant = 0;
	Employee *pEmpleado;
	Employee *bufferBinario;


	if (pFile != NULL && pArrayListEmployee != NULL) {

		int auxId;
		char auxNombre[128];
		int auxHoras;
		float auxSueldo;

		while (!feof(pFile)) {

			 if(fread(&bufferBinario, sizeof(Employee), 1, pFile) == 1){


				 employee_save(bufferBinario,&auxId,auxNombre,&auxHoras,&auxSueldo);

				 pEmpleado = employee_new();

				 employee_setId(pEmpleado, auxId);
				 employee_setNombre(pEmpleado, auxNombre);
				 employee_setHorasTrabajadas(pEmpleado, auxHoras);
				 employee_setSueldo(pEmpleado,auxSueldo);


				cant++;

				ll_add(pArrayListEmployee, pEmpleado);
			}

		}

	} else {
		printf("error");
	};


	return cant;

}
