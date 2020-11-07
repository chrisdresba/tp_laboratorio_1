
#include "LinkedList.h"
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

/** \brief //Pide memoria dinámica e inicializa los datos
 *
 *
 * \return un empleado inicializado
 *
 */
Employee* employee_new();

/** \brief Carga los datos de un empleado
 *
 * \param puntero int id
 * \param puntero char nombre
 * \param puntero int horasTrabajadas
 * \param puntero float sueldo
 * \return un empleado con los datos cargados
 *
 */
Employee* employee_newParametros(int* id,char* nombre,int* horasTrabajadas,float* sueldo);

/** \brief Elimina el empleado un empleado por parametro.
 *
 * \param puntero a un empleado
 *
 */
void employee_delete(Employee* this);

/** \brief Imprime un empleado
 *
 * \param puntero a un empleado
 * \return 1 si se cumplio la tarea / 0 si hubo un error
 *
 */
int employee_print(Employee* pUnEmpleado);

/** \brief Devuelve por puntero un Id para un empleado nuevo
 *
 * \param pArrayListEmployee LinkedList*
 * \param int puntero id
 * \return 0 si hubo un Error/ 1 si se realizo la operacion
 *
 */
int employee_setIdAuto(LinkedList *this, int* id);

/** \brief Ordena dos valores
 *
 * \param void* item1
 * \param void* item2
 * \return 1 si item1 es > que item2, sino retorna -1
 *
 */
int employee_funcionSort(void* item1, void* item2);

/** \brief Asigna el valor de id a un empleado
 *
 * \param puntero a un empleado
 * \param int id
 * \return 0 si hubo un Error/ 1 si se realizo la operacion
 *
 */
int employee_setId(Employee* this,int id);

/** \brief obtiene el valor de id de un empleado
 *
 * \param puntero a un empleado
 * \return -> el valor del id
 *
 */
int employee_getId(Employee* this);

/** \brief Asigna el valor de nombre a un empleado
 *
 * \param puntero a un empleado
 * \param char nombre
 * \return 0 si hubo un Error/ 1 si se realizo la operacion
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief obtiene el valor del nombre de un empleado
 *
 * \param puntero a un empleado
 * \return -> el valor de nombre
 *
 */
char* employee_getNombre(Employee* this);

/** \brief Asigna el valor de horasTrabajadas a un empleado
 *
 * \param puntero a un empleado
 * \param int horasTrabajadas
 * \return 0 si hubo un Error/ 1 si se realizo la operacion
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief obtiene el valor de horas trabajadas de un empleado
 *
 * \param puntero a un empleado
 * \return -> el valor de las horas trabajadas
 *
 */
int employee_getHorasTrabajadas(Employee* this);

/** \brief Asigna el valor de sueldo a un empleado
 *
 * \param puntero a un empleado
 * \param float sueldo
 * \return 0 si hubo un Error/ 1 si se realizo la operacion
 *
 */
int employee_setSueldo(Employee* this,float sueldo);

/** \brief obtiene el valor de sueldo de un empleado
 *
 * \param puntero a un empleado
 * \return -> el valor del sueldo
 *
 */
float employee_getSueldo(Employee* this);

/** \brief Devuelve el valor de id del empleado por puntero
 *
 * \param puntero a un empleado
 * \param puntero int id
 * \return 0 si hubo un Error/ 1 si se realizo la operacion
 *
 */
int buscarId(Employee *this, int* id);

/** \brief Guarda y devuelve el valor de id,nombre,horas trabajadas y sueldo del empleado por puntero
 *
 * \param puntero a un empleado
 * \param puntero int id
 * \param puntero char nombre
 * \param puntero int horas
 * \param puntero float sueldo
 * \return 0 si hubo un Error/ 1 si se realizo la operacion
 *
 */
int employee_save(Employee *pUnEmpleado,int* id,char* nombre,int* horas,float* sueldo);
#endif // employee_H_INCLUDED
