/*
 * confederacion.h
 *
 *  Created on: 17 oct. 2022
 *      Author: herni
 */

#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_


typedef struct{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	int isEmpty;
}eConfederacion;

void harcodearConfederacion (eConfederacion confederaciones[], int tamConfe);
int inicializarConfederaciones(eConfederacion confederaciones[], int tamConfe);
int abmConfederacion(eConfederacion confederaciones[], int tamConfe, int* idAutomatico, int* contador);

int elegirConfederacion (char mensaje[], char cadenaNombre[], char cadenaRegion[], int tamNombre, int tamRegion, int* anio);

int altaConfederacion(eConfederacion confederaciones[], int tamConfe, int idAutomatico);
int bajaConfederacion(eConfederacion confederacion[], int tamConfe);
int modificarConfederacion(eConfederacion confederaciones[], int tamConfe);

int modificarNombreConfederacion(eConfederacion confederaciones[], int tamConfederaciones, int idElegido);
int modificarRegionConfederacion(eConfederacion confederaciones[], int tamConfederaciones, int idElegido);
int modificarAnioCreacion(eConfederacion confederaciones[], int tamConfederaciones, int idElegido);




#endif /* CONFEDERACION_H_ */
