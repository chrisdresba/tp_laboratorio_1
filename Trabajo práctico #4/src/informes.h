/*
 * informes.h
 *
 *  Created on: 26 nov. 2020
 *      Author: dresba
 */
#include "Articulo.h"

#ifndef INFORMES_H_
#define INFORMES_H_

/** \brief ordena la lista de la entidad
 *
 * \param  LinkedList* Entidad
 * \return  mayor a 0 si se realizo la operacion , 0 si no se realizo la operacion , -1 si se produjo un Error
 *
 */
 int contarArticulosMayorOf(LinkedList *pArrayList);

 /** \brief ordena la lista de la entidad
  *
  * \param  LinkedList* Entidad
* \return  mayor a 0 si se realizo la operacion , 0 si no se realizo la operacion , -1 si se produjo un Error
  *
  */
 int contarArticulosDeRubro(LinkedList *pArrayList);


#endif /* INFORMES_H_ */
