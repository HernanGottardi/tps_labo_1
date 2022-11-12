

#include "jugador.h"
#include "inputs.h"
#include "LinkedList.h"
#include "Seleccion.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \fn Seleccion selec_new*()
 * \brief Funcion encargada de reservar espacio en memoria dinamica
 * a una estructura Seleccion e inicializarla con valores predeterminados.
 *
 * \return variable que apunta a la direccion de memoria reservada (si todo sale bien)
 * o NULL si no se encontro lugar.
 */
Seleccion* selec_new(){
	Seleccion * pSeleccion;
	pSeleccion = (Seleccion*)malloc(sizeof(Seleccion));
	if(pSeleccion != NULL){
		inicializarSeleccion(pSeleccion);
	}
	return pSeleccion;
}
/**
 * \fn Seleccion selec_newParametros*(char*, char*, char*, char*)
 * \brief  Funcion encargada de reservar espacio en memoria dinamica para estructura del tipo Seleccion y asignarle
 * a sus campos, valores recibidos como parametros.
 *
 * \param idStr
 * \param paisStr
 * \param confederacionStr
 * \param convocadosStr
 */
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr){
	Seleccion *pSeleccion;
	pSeleccion = selec_new();
	if(pSeleccion != NULL){
		pSeleccion->id = atoi(idStr);
		strcpy(pSeleccion->pais, paisStr);
		strcpy(pSeleccion->confederacion, confederacionStr);
		pSeleccion->convocados = atoi(convocadosStr);
	}
	return pSeleccion;
}
/**
 * \fn void selec_delete(Seleccion*)
 * \brief Funcion encargada de liberar el espacio de memoria de una estructura del tipo Seleccion pasada como parametro.
 *
 * \param this  - puntero a la estructura Seleccion.
 */
void selec_delete(Seleccion* this){
	if(this != NULL){
		free(this);
	}
}

/**
 * \fn int selec_getId(Seleccion*, int*)
 * \brief Funcion encargada de obtener el segundo parametro del campo ID dentro de la estructura Selccion pasada como primer parametro.
 *
 * \param this - puntero a estructura Seleccion.
 * \param id - int id.
 */

int selec_getId(Seleccion* this,int* id){
	int retorno = 0;
	if(this != NULL && id != NULL){
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

/**
 * \fn int selec_getPais(Seleccion*, char*)
 * \brief Funcion encargada de obtener el segundo parametro del campo Pais dentro de la estructura Selccion pasada como primer parametro.
 *
 * \param this - puntero a estructura Seleccion.
 * \param pais - cadena de caract pais.
 */

int selec_getPais(Seleccion *this, char *pais) {
	int retorno = 0;
	if (this != NULL && pais != NULL) {
		strcpy(pais, this->pais);
		retorno = 1;
	}
	return retorno;
}
/**
 * \fn int selec_getConfederacion(Seleccion*, char*)
 * \brief Funcion encargada de obtener el segundo parametro del campo confederacion
 * dentro de la estructura Selccion pasada como primer parametro.

 * \param this - puntero a estructura Seleccion.
 * \param confederacion - cadena de caract confederacion.
 */
int selec_getConfederacion(Seleccion *this, char *confederacion) {
	int retorno = 0;
	if (this != NULL && confederacion != NULL) {
		strcpy(confederacion, this->confederacion);
		retorno = 1;
	}
	return retorno;
}
//----------------------------------------------------------------------

/**
 * \fn int selec_setConvocados(Seleccion*, int)
 * \brief Funcion encargada de asignar el segundo parametro, que es el numero de
 * convocados, dentro del campo convocados de la estructura Seleccion.

 * \param this - puntero a estructura Seleccion
 * \param convocados - numero a asignar.
 */

int selec_setConvocados(Seleccion* this,int convocados){
	int retorno = 0;
	if(this != NULL && convocados > -1){
		this->convocados = convocados;
		retorno = 1;
	}
	return retorno;
}
/**
 * \fn int selec_getConvocados(Seleccion*, int*)
 * \brief Funcion encargada de buscar el segundo parametro, que es el numero de
 * convocados, dentro del campo convocados de la estructura Seleccion.
 *
 * \param this - puntero a estructura Seleccion
 * \param convocados - numero a asignar.

 */
int selec_getConvocados(Seleccion *this, int *convocados) {
	int retorno = 0;
	if (this != NULL && convocados != NULL) {
		*convocados = this->convocados;
		retorno = 1;
	}
	return retorno;
}

/**
 * \fn int inicializarSeleccion(Seleccion*)
 * \brief  Funcion encargada de asginarle valores iniciales a todos los campos
 * de la estructura Seleccion.
 *
 * \param unaSeleccion - Puntero a la estructura Seleccion.
 */
int inicializarSeleccion(Seleccion * unaSeleccion){
	int retorno = 0;
	if(unaSeleccion != NULL){
		retorno = 1;
		unaSeleccion->id = 0;
		strcpy(unaSeleccion->confederacion, "0");
		strcpy(unaSeleccion->pais, "0");
		unaSeleccion->convocados = 0;
	}
	return retorno;
}

/**
 * \fn int getSeleccionIndexById(LinkedList*, int)
 * \brief Funcion encargada de buscar la posicion de una estructura a traves de su numero de id.
 *
 * \param listaSeleccion - puntero a estructura Seleccion.
 * \param id - id de la estructura seleccion.
 */
int obtenerIndexSeleccionConID(LinkedList* listaSeleccion, int id)
{
	int index = -1;
	Seleccion* auxSeleccion;
	int idAux;

	for(int i=0; i<ll_len(listaSeleccion); i++)
	{
		auxSeleccion = ll_get(listaSeleccion, i);
		selec_getId(auxSeleccion, &idAux);
		if(idAux == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

