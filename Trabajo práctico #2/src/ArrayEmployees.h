/*
 * ArrayEmployees.h
 *
 *  Created on: 27 sep. 2020
 *      Cristian Andres Barraza 1ºE
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct{

	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employees;

/** \brief Inicia isEmpty en verdadero en todas las posiciones del array
*
* \param list Employee* Puntero al array de employees
* \param limite del array
* \return retorna int (-1) si sucede un error y (0) si se pudo realizar la operacion*/

int initEmployees(Employees* list, int limite);

/** \brief agrega a una lista de empleados existente valores recibidos, calcula el primer indice vacio y carga los valores por parametros recibidos en dicha posicion(INDICE)
*
* \param list employee*
* \param limite maximo
* \param Puntero id
* \param char de nombre
* \param char de apellido
* \param salario float
* \param sector int
* \return retorna int (-1) si sucede un error y (0) si se pudo realizar la operacion
*
*/
int addEmployee(Employees* list, int limite, int* id, char name[],char lastName[],float salary,int sector);

/** \brief Encuentra un empleado por Id y lo devuelve por el retorno.
*
* \param list Employee*
* \param int limite tamaño
* \param int id
* \return Retorna el id del empleado o (-1) si [limite invalido o puntero NULL o no se encuentra la lista de empleados]
*
*/
int findEmployeeById(Employees* list, int limite,int id);

/** \brief permite modificar un empleado por Id, se puede modificar el nombre,apellido,sector y sueldo.
*
* \param list Employee*
* \param int limite tamaño
* \param int id
* \return retorna (-1) si [limite es invalido o puntero NULL o no se encuentra la lista de empleados] - 0 si se pudo realizar la modificacion
*
*/
int modifyEmployeeById(Employees* list, int limite,int id);

/** \brief Remueve un Empleado por Id (isEmpty en valor 1)
*
* \param list Employee*
* \param int limite tamaño
* \param id int
* \return retorna (-1) si se produjo un Error [limite invalido o puntero NULL o no encontrar la lista de empleados]
*  - (0) si se pudo realizar - mensaje:BAJA de ID exitosa
*
*/
int removeEmployee(Employees* list, int limite, int id);

/** \brief Ordena los elementos en el array de employees, el argumento order
indica el orden  A-Z o Z->A
*
* \param list Employee*
* \param int limite
* \param int order : Ordena listado: A-Z -> 0 - Z->A 1
* \return retorna (-1) si hay Error [Invalido limite o NULL el puntero] - (0) si esta Ok
*
*/
int sortEmployees(Employees* list, int limite, int order);
/** \brief Imprime el contenido del array de empleados.
*
* \param list Employee*
* \param int limite
* \return retorna (-1) si hay Error [Invalido limite o NULL el puntero] - (0) si esta Ok
*
*
*/
int printEmployees(Employees* list, int limite);


#endif /* ARRAYEMPLOYEES_H_ */
