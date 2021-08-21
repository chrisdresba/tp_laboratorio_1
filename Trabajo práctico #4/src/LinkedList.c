#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Articulo.h"

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList *this, int nodeIndex);

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList *this, int nodeIndex, void *pElement);


LinkedList* ll_newLinkedList(void) {
	LinkedList *this = NULL;

	this = (LinkedList*) malloc(sizeof(LinkedList));

	if (this != NULL) {
		this->size = 0;
		this->pFirstNode = NULL;
	}
	return this;
}

int ll_len(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {
		returnAux = this->size;
	}

	return returnAux;
}

static Node* getNode(LinkedList *this, int nodeIndex) {

	int i;

	Node *pNodeAuxiliar = NULL;

	if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)) {

		pNodeAuxiliar = this->pFirstNode;

		for (i = 0; i < nodeIndex; i++) {

			pNodeAuxiliar = pNodeAuxiliar->pNextNode;
		}
	}

	return pNodeAuxiliar;
}

Node* test_getNode(LinkedList *this, int nodeIndex) {

	return getNode(this, nodeIndex);
}

static int addNode(LinkedList *this, int nodeIndex, void *pElement) {

	int returnAux = -1;

	Node *pNewNode;

	if (this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)) {

		pNewNode = (Node*) malloc(sizeof(Node));

		if (pNewNode != NULL)

		{
			pNewNode->pElement = pElement;

			if (nodeIndex == 0)

			{
				pNewNode->pNextNode = this->pFirstNode;
				this->pFirstNode = pNewNode;

			} else {

				pNewNode->pNextNode = getNode(this, nodeIndex);
				getNode(this, nodeIndex - 1)->pNextNode = pNewNode;

			}

			this->size++;
			returnAux = 0;
		}
	}
	return returnAux;
}

int test_addNode(LinkedList *this, int nodeIndex, void *pElement) {
	return addNode(this, nodeIndex, pElement);
}

int ll_add(LinkedList *this, void *pElement) {
	int returnAux = -1;

	if (this != NULL) {
		returnAux = addNode(this, ll_len(this), pElement);
	}

	return returnAux;
}

void* ll_get(LinkedList *this, int index) {

	void *returnAux = NULL;

	if (this != NULL && index >= 0 && index < ll_len(this)) {

		Node *pNode = getNode(this, index);
		returnAux = pNode->pElement;

	}

	return returnAux;
}

int ll_set(LinkedList *this, int index, void *pElement) {

	int returnAux = -1;

	if (this != NULL && index >= 0 && index < ll_len(this)) {

		Node *pNode = getNode(this, index);

		pNode->pElement = pElement;
		returnAux = 0;

	}
	return returnAux;
}

int ll_remove(LinkedList *this, int index) {

	int returnAux = -1;
	Node *pAuxNode;
	Node *pPrevNode;

	if (this != NULL && index >= 0 && index < ll_len(this)) {

		pAuxNode = getNode(this, index);

		if (pAuxNode != NULL) {
			if (index == 0) {

				this->pFirstNode = pAuxNode->pNextNode;

			} else {

				pPrevNode = getNode(this, index - 1);
				pPrevNode->pNextNode = pAuxNode->pNextNode;

			}
		}
		free(pAuxNode);
		this->size--;
		returnAux = 0;

	}
	return returnAux;
}

int ll_clear(LinkedList *this) {

	int returnAux = -1;

	if (this != NULL) {

		while (ll_len(this) > 0) {

			ll_remove(this, 0);

		}
		returnAux = 0;

	}

	return returnAux;
}

int ll_deleteLinkedList(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {

		ll_clear(this);
		free(this);
		returnAux = 0;
	}

	return returnAux;
}

int ll_indexOf(LinkedList *this, void *pElement) {

	int returnAux = -1;
	int i;

	if (this != NULL) {

		for (i = 0; i < ll_len(this); i++) {

			if (ll_get(this, i) == pElement) {
				returnAux = i;
				break;
			}
		}

	};
	return returnAux;
}

int ll_isEmpty(LinkedList *this) {

	int returnAux = -1;

	if (this != NULL) {

		if (ll_len(this) == 0) {
			returnAux = 1;
		} else {
			returnAux = 0;
		}

	}
	return returnAux;
}

int ll_push(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;

	if (this != NULL && index >= 0 && index <= ll_len(this)) {

		returnAux = addNode(this, index, pElement);
	}

	return returnAux;
}

void* ll_pop(LinkedList *this, int index) {
	void *returnAux = NULL;

	if (this != NULL && index >= 0 && index <= ll_len(this)) {

		returnAux = (void*) ll_get(this, index);

		if (returnAux != NULL) {

			ll_remove(this, index);
		}
	}

	return returnAux;
}

int ll_contains(LinkedList *this, void *pElement) {
	int returnAux = -1;

	if (this != NULL) {

		if (ll_indexOf(this, pElement) != -1) {
			returnAux = 1;
		} else {
			returnAux = 0;
		}
	}

	return returnAux;
}

int ll_containsAll(LinkedList *this, LinkedList *this2) {
	int returnAux = -1;

	if (this != NULL && this2 != NULL) {

		returnAux = 1;

		for (int i = 0; i < ll_len(this2); i++) {

			if (!ll_contains(this, ll_get(this2, i))) {
				returnAux = 0;
				break;
			}
		}

	}

	return returnAux;
}

LinkedList* ll_subList(LinkedList *this, int from, int to) {
	LinkedList *cloneArray = NULL;
	int i;
	void *pElemento;

	if (this != NULL && from >= 0 && from <= ll_len(this) && from < to
			&& to <= ll_len(this)) {
		cloneArray = ll_newLinkedList();

		if (cloneArray != NULL) {
			for (i = from; i < to; i++) {
				pElemento = ll_get(this, i);
				ll_add(cloneArray, pElemento);

			}
		}
	}
	return cloneArray;
}

LinkedList* ll_clone(LinkedList *this) {
	LinkedList *cloneArray = NULL;
	int i;

	if (this != NULL) {

		cloneArray = ll_newLinkedList();
		for (i = 0; i < ll_len(this); i++) {

			cloneArray = ll_subList(this, 0, ll_len(this));
		}

	}

	return cloneArray;
}

int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order) {

	int returnAux = -1;
	void *pElement;

	int i;
	int j;

	if (this != NULL && pFunc != NULL && order >= 0 && order <= 1) {

		for (i = 1; i < ll_len(this) - 1; i++) {

			for (j = i + 1; j < ll_len(this); j++) {

				if (order == 1 && pFunc(ll_get(this, i), ll_get(this, j)) > 0) {
					pElement = ll_get(this, i);
					ll_set(this, i, ll_get(this, j));
					ll_set(this, j, pElement);

				} else if (order == 0
						&& pFunc(ll_get(this, i), ll_get(this, j)) < 0) {
					pElement = ll_get(this, i);
					ll_set(this, i, ll_get(this, j));
					ll_set(this, j, pElement);

				}
			}

		}

		returnAux = 0;

	};

	return returnAux;
}
LinkedList* ll_map(LinkedList *this, void (*fn)(void*)) {

	int i;
	void *pElement;

	if (this != NULL && fn != NULL) {

		for (i = 0; i < ll_len(this); i++) {

			pElement = ll_get(this, i);
			fn(pElement);
			ll_set(this, i, pElement);

		}
	}

	return this;
}

LinkedList* ll_filter(LinkedList *this, int (*pFunc)(void*)) {

	LinkedList *auxList = NULL;
	int i;
	void *pElement;

	if (this != NULL && pFunc != NULL) {

		auxList = ll_newLinkedList();
		if (auxList != NULL) {

			for (i = 0; i < ll_len(this); i++) {

				pElement = ll_get(this, i);

				if (pFunc(pElement)) {
					ll_add(auxList, pElement);
				}

			}
		}
	}

	return auxList;
}
;

int ll_count(LinkedList* this, int (*fn)(void*)){

		int acumulador = 0;
		int i;
		void *pElement;

		if (this != NULL && fn != NULL) {

			for (i = 0; i < ll_len(this); i++) {

				pElement = ll_get(this, i);

			     acumulador+=fn(pElement);

			}
		}
	return acumulador;
}
/*
 void calcularPrecioFinal(Producto* p)
 {
 if(p != NULL)
 {
 p->precioFinal = p->precioUnitario*p->cantidad;
 }
 return;
 }

 int filtrarMujeres(eEmpleado* emp)
 {
 int retorno = 0;
 if(emp != NULL){

 if(eEmpleado->sexo == 'f'){
 retorno = 1;
 }

 }
 return retorno;
 }
 */
