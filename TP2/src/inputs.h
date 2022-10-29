/*
 * inputs.h
 *
 *  Created on: 17 oct. 2022
 *      Author: herni
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

 int confirmacion(char comentario[], char* confirmacion);
//----------------------------------------------------------------------
 int utn_getCaracter(char *pResultado, char *mensaje, char *mensajeError, char minimo, char maximo);
//----------------------------------------------------------------------
 int esNumerica(char *cadena);
 int myGets(char *cadena, int longitud);
 int getInt(int *pResultado);
 int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo);
//----------------------------------------------------------------------

 int utn_getFloat(float*pResultado, char *mensaje, char* mensajeError, int minimo, int maximo);
 int getFloat(float *pResultado);
 int esFlotante(char *cadena);

//----------------------------------------------------------------------
 int getCadena(char mensaje[], char cadena[], int tamCadena);
 int sonLetrasEspacios(char cadena[], int tamCadena);
 int convertirInicialesEnMayusculas(char cadena[], int tamCadena);
//----------------------------------------------------------------------
 int getShort(short *pResultado);
 int utn_getShort(short *pResultado, char *mensaje, char *mensajeError);



#endif /* INPUTS_H_ */
