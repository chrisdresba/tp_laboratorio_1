/*
 * Articulo.h
 *
 *  Created on: 25 nov. 2020
 *      Author: Cristian Barraza
 */
#include "LinkedList.h"
#ifndef ARTICULO_H_
#define ARTICULO_H_

typedef struct
{
    int rubroId;
    char descripcion[128];

}eRubro;

typedef struct
{
    int id;
    char articulo[128];
    float precio;
    char medida[128];
    int rubroId;
}eArticulo;

/** \brief //Pide memoria dinámica e inicializa los datos
 *
 *
 * \return un articulo inicializado
 *
 */
eArticulo* articulo_new();

/** \brief Carga los datos de un articulo
 *
 * \param puntero int id
 * \param puntero char articulo
 * \param puntero float precio
 * \param puntero char medida
 * \param puntero int rubroId
 * \return un articulo con los datos cargados
 *
 */
eArticulo* articulo_newParametros(int *id, char *articulo,float *precio,char *medida,int *rubroId);

/** \brief Elimina un articulo por parametro.
 *
 * \param puntero a un articulo
 *
 */
void articulo_delete(eArticulo* this);

/** \brief Imprime un articulo
 *
 * \param puntero a un articulo
 * \param  Estructura rubro []
 * \return 1 si se cumplio la tarea / 0 si hubo un error
 *
 */
int articulo_print(eArticulo *pUnArticulo,eRubro rubro[]);

/** \brief Ordena dos valores
 *
 * \param void* item1
 * \param void* item2
 * \return 1 si item1 es > que item2, -1 si item1 es < que item2, sino retorna 0
 *
 */
int articulo_funcionSort(void* item1, void* item2);

/** \brief Asigna el valor de id a un articulo
 *
 * \param puntero a un articulo
 * \param int id
 * \return 0 si hubo un Error/ 1 si se realizo la operacion
 *
 */
int articulo_setId(eArticulo *this, int id);

/** \brief obtiene el valor de id de un articulo
 *
 * \param puntero a un articulo
 * \return -> el valor del id
 *
 */
int articulo_getId(eArticulo *this);

/** \brief Asigna el valor del nombre de un articulo
 *
 * \param puntero a un articulo
 * \param char* articulo
 * \return 0 si hubo un Error/ 1 si se realizo la operacion
 *
 */
int articulo_setArticulo(eArticulo *this, char *articulo);

/** \brief obtiene el valor del nombre de un articulo
 *
 * \param puntero a un articulo
 * \return -> el char articulo
 *
 */
char* articulo_getArticulo(eArticulo *this);

/** \brief Asigna el valor del precio a un articulo
 *
 * \param puntero a un articulo
 * \param float precio
 * \return 0 si hubo un Error/ 1 si se realizo la operacion
 *
 */
int articulo_setPrecio(eArticulo *this, float precio);

/** \brief obtiene el valor del precio de un articulo
 *
 * \param puntero a un articulo
 * \return -> el valor del precio
 *
 */
float articulo_getPrecio(eArticulo *this);

/** \brief Asigna el valor de medida a un articulo
 *
 * \param puntero a un articulo
 * \param char medida
 * \return 0 si hubo un Error/ 1 si se realizo la operacion
 *
 */
int articulo_setMedida(eArticulo *this, char *medida);

/** \brief obtiene el valor de la medida de un articulo
 *
 * \param puntero a un articulo
 * \return -> el char medida
 *
 */
char* articulo_getMedida(eArticulo *this);

/** \brief Asigna el valor de rubro a un articulo
 *
 * \param puntero a un articulo
 * \param int rubroId
 * \return 0 si hubo un Error/ 1 si se realizo la operacion
 *
 */
int articulo_setRubro(eArticulo *this, int rubroId);

/** \brief obtiene el valor de idRubro de un articulo
 *
 * \param puntero a un articulo
 * \return -> el valor del rubro
 *
 */
int articulo_getRubro(eArticulo *this);

/** \brief Devuelve el valor de id del articulo por puntero
 *
 * \param puntero a un articulo
 * \param puntero int id
 * \return 0 si hubo un Error/ 1 si se realizo la operacion
 *
 */
int buscarId(eArticulo *this, int* id);

/** \brief Guarda y devuelve el valor de id,articulo,precio,medida y rubroId del articulo por puntero
 *
 * \param puntero int id
 * \param puntero char articulo
 * \param puntero float precio
 * \param puntero char medida
 * \param puntero int rubroId
 * \return 0 si hubo un Error/ 1 si se realizo la operacion
 *
 */
int articulo_save(eArticulo *pUnArticulo,int* id,char* articulo,float* precio,char* medida,int* rubroId);

/** \brief Parsea los datos de los articulos desde el archivo datos.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 0 si hubo un Error/ mayor que 0 si se realizo la operacion
 *
 */
int articulo_parserFromText(FILE *pFile, LinkedList *pArrayList);

/** \brief descuentos en los un articulos seleccionados
 *
 * \param puntero a un articulo
 *
 */
void calcularDescuento(eArticulo *this) ;

/** \brief A traves de id rubro se devuelve por puntero la descripcion
 *
 * \param int id
 * \param  Estructura rubro []
 * \param  char* descripcion
 * \return 0 si hubo un Error/ 1 si se realizo la operacion
 *
 */
int articulo_IdRubro(int id, eRubro rubro[], char *descripcion);

/** \brief comprueba que el precio sea mayor a 100
 *
 * \param puntero a un articulo
 * \return 1 si es mayor - 0 si es menor
 *
 */
int calcularPorPrecio(eArticulo *this);

/** \brief comprueba que un articulo sea de un rubro determinado
 *
 * \param puntero a un articulo
 * \return 1 si coincide - 0 si no hay coincidencia
 *
 */
int calcularPorRubro(eArticulo *this);

#endif /* ARTICULO_H_ */
