/*
 * validaciones.h
 *
 *  Created on: 14 sept 2022
 *      Author: herni
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int utn_getCaracter(char *pResultado, char *mensaje, char *mensajeError,
		char minimo, char maximo, int reintentos);

int esNumerica(char *cadena);

int myGets(char *cadena);

int getInt(int *pResultado);

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);

#endif /* INPUTS_H_ */
