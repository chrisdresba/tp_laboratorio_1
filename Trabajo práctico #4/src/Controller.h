/*
 * Controller.h
 *
  *  Created on: 25 nov. 2020
 *      Author: Cristian Barraza
 */
#include "LinkedList.h"
#include "Articulo.h"

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/** \brief Carga los datos de la entidad desde el archivo datos.csv (modo texto).
 *
 * \param  char* path
 * \param pArrayListEmployee LinkedList*
 * \return  >= 0 si se realizo la operacion y -1 si se produjo un Error
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayList);

/** \brief ordena la lista de la entidad
 *
 * \param  LinkedList* Entidad
 * \return 0 si se realizo la operacion y -1 si se produjo un Error
 *
 */
int controller_sort(LinkedList *pArrayList);

/** \brief imprime la lista de la entidad
 *
 * \param  LinkedList* Entidad
 * \param  Estructura rubro []
 * \return 0 si se realizo la operacion y -1 si se produjo un Error
 */
int controller_printList(LinkedList *pArrayList,eRubro rubro[]);

/** \brief genera descuentos en la lista de la entidad
 *
 * \param  LinkedList* Entidad
 * \return 0 si se realizo la operacion y -1 si se produjo un Error
 */
int controller_desc(LinkedList *pArrayList);

/** \brief guarda los datos de la entidad en el archivo mapeado.csv (modo texto).
 * \param  char* path
 * \param pArrayListEmployee LinkedList*
 * \return  mayor a 0 si se realizo la operacion y 0 si se produjo un Error
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayList) ;

#endif /* CONTROLLER_H_ */
