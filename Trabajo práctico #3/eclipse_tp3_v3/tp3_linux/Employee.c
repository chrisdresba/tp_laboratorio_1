#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"


Employee* employee_new() {

	Employee *nuevoEmpleado = NULL;

	nuevoEmpleado = (Employee*) malloc(sizeof(Employee));

	if (nuevoEmpleado != NULL)

	{
		nuevoEmpleado->id = 0;
		strcpy(nuevoEmpleado->nombre, " ");
		nuevoEmpleado->horasTrabajadas = 0;
		nuevoEmpleado->sueldo = 0;

	}

	return nuevoEmpleado;
}
;

Employee* employee_newParametros(int *id, char *nombre, int *horasTrabajadas,
		float *sueldo) {


	Employee *nuevoEmpleado = employee_new();

	if (nuevoEmpleado != NULL && nombre != NULL && horasTrabajadas != NULL && sueldo != NULL) {
		if (!(employee_setId(nuevoEmpleado, *id)
				&& employee_setNombre(nuevoEmpleado, nombre)
				&& employee_setHorasTrabajadas(nuevoEmpleado, *horasTrabajadas)
				&& employee_setSueldo(nuevoEmpleado, *sueldo)))

		{
			free(nuevoEmpleado);
			nuevoEmpleado = NULL;

		}

	}

	return nuevoEmpleado;
}
;

void employee_delete(Employee* this){

	if (this != NULL){
		free(this);
	}

};

int employee_print(Employee *pUnEmpleado)

{
	int retorno = 0;

	if (pUnEmpleado != NULL)

	{
		retorno = 1;
		printf("%-8d %-16s %-15d $%-15.2f\n", employee_getId(pUnEmpleado),
				employee_getNombre(pUnEmpleado),
				employee_getHorasTrabajadas(pUnEmpleado),
				employee_getSueldo(pUnEmpleado));
	}

	return retorno;

}

int employee_setIdAuto(LinkedList *this, int* id) {

	int retorno = 0;
	int limite;
	int result;

	Employee* aux;
	limite = ll_len(this);

	if(this != NULL && id != NULL){

	if(limite == 0){
				*id = 1;
			}else{

				aux = ll_get(this, limite-1);
				result = employee_getId(aux);
				*id=result+1;
				retorno=1;

			};

}
return retorno;

}
;


int employee_funcionSort(void* item1, void* item2) {

	int retorno = 0;
	Employee* empl1;
	Employee* empl2;
	float sueldo1;
	float sueldo2;


	empl1 = (Employee*) item1;
	sueldo1 = employee_getSueldo(empl1);
	empl2 = (Employee*) item2;
	sueldo2 = employee_getSueldo(empl2);


		if(sueldo1 > sueldo2){
          retorno = 1;
		}else if(sueldo1 < sueldo2){
			retorno = -1;
		}else{
			retorno = 0;
		}

return retorno;

}
;


int employee_setId(Employee *this, int id) {

	int retorno = 0;
	if (this != NULL && id > 0)

	{
		this->id = id;
		retorno = 1;
	}

	return retorno;

}
;

int employee_getId(Employee *this) {
	return this->id;
}
;


int employee_setNombre(Employee *this, char *nombre) {

	int retorno = 0;

	if (this != NULL && nombre != NULL)

	{
		strcpy(this->nombre, nombre);
		retorno = 1;

	}

	return retorno;
}
;


char* employee_getNombre(Employee *this) {
	return this->nombre;
}
;


int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas) {

	int retorno = 0;
	if (this != NULL && horasTrabajadas >= 0)

	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 1;
	}

	return retorno;
}
;


int employee_getHorasTrabajadas(Employee *this) {


	return this->horasTrabajadas;

}
;


int employee_setSueldo(Employee *this, float sueldo) {
	int retorno = 0;

	if (this != NULL && sueldo > 0)

	{
		this->sueldo = sueldo;

		retorno = 1;

	}

	return retorno;
}
;


float employee_getSueldo(Employee *this) {
	return this->sueldo;
}
;


int buscarId(Employee *this, int* id){

	int retorno = 0;


		if (this != NULL && id != NULL)

		{
					*id = this->id;

					retorno = 1;
		}

	    return retorno;
}

int employee_save(Employee *pUnEmpleado,int* id,char* nombre,int* horas,float* sueldo)

{
	int retorno = 0;

	if (pUnEmpleado != NULL && id != NULL && nombre != NULL && horas !=NULL && sueldo != NULL)

	{
				*id = pUnEmpleado->id;
				strcpy(nombre,pUnEmpleado->nombre);
				*horas = pUnEmpleado->horasTrabajadas;
				*sueldo = pUnEmpleado->sueldo;
				retorno = 1;
	}

	return retorno;

}


