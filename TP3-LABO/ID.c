/*
 * id.c
 *
 *  Created on: 7 nov. 2022
 *      Author: herni
 */

#include "ID.h"

#include "jugador.h"
#include "inputs.h"
#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \fn int sumar_idArchivo(char*)
 * \brief Funcion encargada de aumentar en una unidad a la cadena de texto pasada como parametro.
 *
 * \param idString - cadena de texto.
 */

int sumar_idArchivo(char* idString){
	int retorno = 0;
	int idAux;
	idAux = atoi(idString);
	idAux++;
	itoa(idAux, idString, 10);

	FILE * archivoId;
	archivoId = fopen("id.csv", "w");
	if(archivoId != NULL){
		fwrite(idString, sizeof(char), strlen(idString), archivoId);
		retorno = 1;
	}
	fclose(archivoId);
	return retorno;
}
/**
 * \fn int leer_incrementar_ArchivoId(char*)
 * \brief Funcion encargada de leer el archivo de texto ID, dedicado a ser el lugar donde se aloja el proximo
 * ID a asignarle a un jugador. Incrementandose por unidad cada vez que se efectua una alta de juagdor.

 * \param id - lugar donde se va a alojar el nuevo id para jugador.

 */
int leer_incrementar_ArchivoId(char* id){
	int retorno = 0;
	char idStr[10];

	FILE * archivoId;
	archivoId = fopen("id.csv", "r");
	if(archivoId != NULL && id != NULL){
		while(!feof(archivoId)){
			fscanf(archivoId, "%[^\n]\n", idStr);
			strcpy(id, idStr);
		}
		fclose(archivoId);
		sumar_idArchivo(idStr);
		retorno = 1;
	}
	fclose(archivoId);
	return retorno;
}
