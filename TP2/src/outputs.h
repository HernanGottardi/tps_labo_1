/*
 * outputs.h
 *
 *  Created on: 26 oct. 2022
 *      Author: herni
 */

#ifndef OUTPUTS_H_
#define OUTPUTS_H_

#include "confederacion.h"
#include "jugadores.h"

void mostrarJugadores(eJugador jugadores[], int tamJugadores, eConfederacion confederaciones[], int tamConfe);
void mostrarConfederaciones(eConfederacion confederaciones[], int tamConfederaciones);

int informar(eJugador jugadores[], int tamJugadores, eConfederacion confede[], int tamConfe, int* contador);

void ordenarJugadores(eJugador jugadores[], int tamJugadores, eConfederacion confederaciones[], int tamConfe);
void encontrarConfeConJugadores(eJugador jugadores[], int tamJugadores, eConfederacion confe[], int tamConfe, int idConfe);
void mostrarConfederacionesConJugadores(eJugador jugadores[], int tamJugadores, eConfederacion confe[], int tamConfe);
void mostrarTotalPromedio(eJugador jugadores[], int tamJugadores);
void mostrarConfederacionMasAnios(eJugador jugadores[], int tamJug, eConfederacion confe[], int tamConfe);
void encontrarMayorAniosConfe(int acumConmebol, int acumAfc, int acumCaf, int acumConcacaf, int acumOfc, int acumUefa, char guardar[]);
void mostrarRegionMasJugadores(eJugador jugadores[], int tamJugadores,
		eConfederacion confede[], int tamConfe);
void mostrarPorcentajeConfe(float *porcConmebol, float *porAfc,float *porConcacaf, float *porCaf, float *porOfc, float *porUefa);
int calcularYmostrar_PorcentajeConfe(eJugador jugadores[], int tamJugadores);
void encontrarMayorRegionJugadores(char guardarMayoRegion[], int contSudAmerican, int contAsia, int contOceania,
		int contCentroNorteAmerica, int contEuropa, int contAfrica);
void mostrarJugadoresSegunRegion(eJugador jugadores[], int tamJugadores, eConfederacion confederaciones[],
		int tamCofederaciones, char regionMasJugadores[]);

#endif /* OUTPUTS_H_ */
