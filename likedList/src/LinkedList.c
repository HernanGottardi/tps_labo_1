#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;
    this = (LinkedList*)malloc(sizeof(LinkedList));
    this->size = 0;
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL){
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o
 * (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){
		pNode = this->pFirstNode;
		for(int i = 0; i < nodeIndex; i++){
			pNode = pNode->pNextNode;
		}
	}
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int returnAux = -1;
	Node *pNewNodo = NULL;
	Node *pNodePrevio = NULL;

	if (this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)) {
		pNewNodo = (Node*)malloc(sizeof(Node));
		if(pNewNodo != NULL){

			pNewNodo->pElement = pElement;
			if(nodeIndex == 0){
				// El nuevo nodo pasa a ser quien porta la referencia a la direccion de memoria del siguiente nodo, que anteriormente
				// llevaba la estructura LinkedList.
				pNewNodo->pNextNode = this->pFirstNode;
				// Y ahora el nodo esta situado justo despues de la estructura LinkedList.
				this->pFirstNode = pNewNodo;
			} else {
				pNodePrevio = getNode(this, nodeIndex - 1);
				pNewNodo->pNextNode = pNodePrevio->pNextNode;
				pNodePrevio->pNextNode = pNewNodo;
			}
			this->size += 1;
			returnAux = 0;
		}

	}
	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList *this, void *pElement) {


	int returnAux = -1;
	if(this != NULL){
		//Esta misma funcion se encarga de verificar los datos empleados
		// retornando 0 si se tuvo exito en la operacion o retornando
		// -1 en caso de que haya fallado.
		return addNode(this, ll_len(this), pElement);
	}
	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */


/*
Retorna un puntero al elemento que se encuentra en el índice especificado. Verificando que el
puntero this sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la
verificación falla la función retorna (NULL) y si tiene éxito retorna el elemento.
*/
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node *pNode;
    if(this != NULL && index >= 0 && index < ll_len(this)){
    	pNode = getNode(this, index);
    	return pNode->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

/*
Inserta un elemento en el LinkedList, en el índice especificado. Verificando que el puntero this
sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la verificación
falla la función retorna (-1) y si tiene éxito (0).

*/
int ll_set(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;
	Node *pNode = NULL;
	if (this != NULL && index >= 0 && index < ll_len(this)) {
		// obtengo el puntero al Nodo
		pNode = getNode(this, index);
		// asigno pElement al campo del Nodo
		pNode->pElement = pElement;

		returnAux = 0;
	}
	return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
/*
Elimina un elemento del LinkedList, en el índice especificado. Verificando que el puntero this
sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la verificación
falla la función retorna (-1) y si tiene éxito (0).

*/
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node *pBeforeNode = NULL;
    Node *pNextNode = NULL;
    Node *pRemoveNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this)){
    	pRemoveNode = getNode(this, index);
		if (pRemoveNode != NULL) {
			if (index == 0) {
				//pNextNode = pRemoveNode->pNextNode;
				this->pFirstNode = NULL;
			} else {
				pBeforeNode = getNode(this, index - 1);

				pNextNode = pRemoveNode->pNextNode;

				pBeforeNode->pNextNode = pNextNode;
			}

			free(pRemoveNode);
			this->size--;
			returnAux = 0;
		}
	}
	return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */

/*
 Borra todos los elementos de LinkedList. Verificando que el puntero this sea distinto de NULL.
 Si la verificación falla la función retorna (-1) y si tiene éxito (0).
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    for(int i = 0; i < ll_len(this); i++){
    	ll_remove(this, i);
    }
    if(ll_len(this) == 0){
    	this->size = 0;
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
	int returnAux = -1;
	if(this != NULL){
		ll_clear(this);
		free(this);
		returnAux = 0;
	}
	return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
/*

 Retorna el índice de la primera aparición de un elemento (element) en el LinkedList.
 Verificando que el puntero this sea distinto de NULL. Si la verificación falla o no encuentra el
 elemento la función retorna (-1) y si encuentra el elemento retorna su índice.

 */


int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    // void *
    Node * pElementNode = NULL;
    if(this != NULL){
    	for(int i = 0; i < ll_len(this); i++){
    		pElementNode = ll_get(this, i);
    		if(pElementNode == pElement){
    			returnAux = i;
    			break;
    		}
    	}
    }
    return returnAux;
}


/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList *this) {
	int returnAux = -1;
	if (this != NULL) {
		if (this->size > 0) {
			return 0;
		} else {
			return 1;
		}
	}
	return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
/*
Desplaza los elementos e inserta en la posición index. Verificando que el puntero this sea
distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la verificación falla
la función retorna (-1) y si tiene éxito (0).
*/
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && index >= 0 && index <= ll_len(this)){
    	returnAux = addNode(this, index, pElement);
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
/*
Retorna un puntero al elemento que se encuentra en el índice especificado y luego lo elimina
de la lista. Verificando que el puntero this sea distinto de NULL y que index sea positivo e
inferior al tamaño del array. Si la verificación falla la función retorna (NULL) y si tiene éxito
retorna el elemento.

*/
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL && index >= 0 && index <= ll_len(this)){
    	for(int i = 0; i < ll_len(this); i++){
    		if(index == i){
    			// Obtengo el puntero al elemento:
    			returnAux = ll_get(this, index);
    			// Borro el elemento/nodo.
    			ll_remove(this, index);
    		}
    	}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
/*Comprueba si existe el elemento que se le pasa como parámetro. Verificando que tanto el
puntero this sea distintos de NULL. Si la verificación falla la función retorna (-1) , si encuentra
el elemento (1) y si no lo encuentra (0).*/
int ll_contains(LinkedList* this, void* pElement)
 {
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

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/

/*
Comprueba si los elementos pasados son contenidos por el LinkedList. Verificando que tanto el
puntero this como pList2 sean distintos de NULL. Si la verificación falla o no encuentra el
elemento la función retorna (-1), si las listas difieren (0) y si ambas listas son iguales retorna
(1). */

int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* pElementListaDos = NULL;

    if(this != NULL && this2 != NULL){
    	returnAux = 1;
    	for(int i = 0; i < ll_len(this2); i++){
    		pElementListaDos = ll_get(this, i);
    		if(ll_contains(this, pElementListaDos) == 0){
    			returnAux = 0;
    			break;
    		}
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/

/*Retorna un nuevo LinkedList con el subconjunto de elementos. Verificando que el puntero this
sea distinto de NULL y que tanto el indice 'from' como 'to' sean positivos e inferiores al tamaño
del array. Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el nuevo
array.*/

LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement = NULL;
    if(this != NULL && from >= 0 && from < ll_len(this) && to > from && to <= ll_len(this)){
    	cloneArray = ll_newLinkedList();
    	for(int i = from; i < to; i++){
    		pElement = ll_get(this, i);
    		ll_add(cloneArray, pElement);
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
/*Retorna un nuevo LinkedList copia del LinkedList original. Verificando que el puntero this sea
distinto de NULL. Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el
nuevo array.*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL){
    	cloneArray = ll_newLinkedList();
    	if(ll_len(this) == 0){
    		cloneArray = this;
    	} else {
    		cloneArray = ll_subList(this, 0, ll_len(this));
    	}
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */

/*Ordena los elementos del array recibiendo como parámetro la función que sera la encargada
de determinar que elemento es mas grande que otro y si se debe ordenar de manera
ascendente o descendente. Verificando que tanto el puntero this como el puntero a la funcion
pFunc sean distintos de NULL. Si la verificación falla (-1) caso contrario retorna (1).*/

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    void* primerElemento = NULL;
    void* segundoElemento = NULL;
	if (this != NULL && pFunc != NULL && (order == 1 || order == 0)) {
		for (int i=0; i < ll_len(this)-1; i++) {
			for (int j=i+1; j < ll_len(this); j++) {
				primerElemento = ll_get(this, i);
				segundoElemento = ll_get(this, j);
				if ((order == 1 && pFunc(primerElemento, segundoElemento) == 1)
				||  (order == 0 && pFunc(primerElemento, segundoElemento) == -1)) {
					ll_set(this, i, segundoElemento);
					ll_set(this, j, primerElemento);
				}
			}
		}
		returnAux = 0;
	}
	return returnAux;
}

