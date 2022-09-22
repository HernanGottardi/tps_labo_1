/*
 * validaciones.c
 *
 *  Created on: 14 sept 2022
 *      Author: herni
 */

#include "inputs.h"

int utn_getCaracter(char *pResultado, char *mensaje, char *mensajeError,

char minimo, char maximo, int reintentos) {

	int retorno = 0;

	char buffer;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {

		do {
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &buffer);

			if (buffer >= minimo && buffer <= maximo) {
				*pResultado = buffer;
				retorno = 1;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		} while (reintentos >= 0);

	}
	return retorno;
}

// ------------------------------------------------------------------------------------------------------------------------------

int esNumerica(char *cadena) {
	int retorno = 0;
	int i = 0;



	if (cadena[0] == '-') {
		i = 1;
	}

	for (; cadena[i] != '\0'; i++) {

		if (cadena[i] > '9' || cadena[i] < '0') {
			break;
		} else {
			retorno = 1;
		}
	}
	return retorno;
}

//----------------------------------------------------------------

// Para reemplazar scanf en getInt
int myGets(char *cadena) {

	fflush(stdin);
	//fgets(cadena, longitud, stdin);
	scanf("%[^\n]", cadena);

	return 1;

}

//----------------------------------------------------------------



int getInt(int *pResultado) {
	int retorno = 0;
	char buffer[4096];

	if (myGets(buffer) && esNumerica(buffer)) {
		retorno = 1;
		*pResultado = atoi(buffer);
	}

	return retorno;
}

// ---------------------------------------------------------------

int getFloat(int *pResultado) {
	int retorno = 0;
	char buffer[4096];

	if (myGets(buffer) == 1 && esNumerica(buffer)) {
		retorno = 1;
		*pResultado = atoi(buffer);
	}

	return retorno;
}

// ---------------------------------------------------------------

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int retorno = 0;
	int buffer;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {

		do {
			printf("%s", mensaje);
			//scanf("%i", &buffer);
			if (getInt(&buffer) == 1 && buffer <= maximo && buffer >= minimo) {
				*pResultado = buffer;
				retorno = 1;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		} while (reintentos >= 0);

	}

	return retorno;

}

