/*
 * outputs.c
 *
 *  Created on: 8 nov. 2022
 *      Author: herni
 */
#include "outputs.h"
#include "jugador.h"
#include "seleccion.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrar_unJugador(Jugador * unJugadorcito, LinkedList* pArrayListSeleccion){

	Seleccion * unaSeleccion;
	int cantidadSelecciones = ll_len(pArrayListSeleccion);
	int idSelec;
	char paisSelec[20];

	int idAux;
	jug_getId(unJugadorcito, &idAux);
	char nombreAux[30];
	jug_getNombreCompleto(unJugadorcito, nombreAux);
	int edadAux;
	jug_getEdad(unJugadorcito, &edadAux);
	char posicionAux[30];
	jug_getPosicion(unJugadorcito, posicionAux);
	char nacionalidadAux[30];
	jug_getNacionalidad(unJugadorcito, nacionalidadAux);

	// convocado o no convocado
	char fueConvocado[45];
	int idSeleccionJugadorAux;
	jug_getSIdSeleccion(unJugadorcito, &idSeleccionJugadorAux);

	if(idSeleccionJugadorAux == 0){
		strcpy(fueConvocado, "No convocado");
	} else {
		for(int i = 0; i < cantidadSelecciones; i++){
			unaSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
			selec_getId(unaSeleccion, &idSelec);
			if(idSeleccionJugadorAux == idSelec){
				selec_getPais(unaSeleccion, paisSelec);
				strcpy(fueConvocado, paisSelec);
				break;
			}
		}
	}
	printf("\n%5i %25s %10i %30s %20s %15s", idAux, nombreAux, edadAux, posicionAux,
			nacionalidadAux, fueConvocado);
}

void mostrar_unaSeleccion(Seleccion * unaSeleccion){

	int idAux;
	selec_getId(unaSeleccion, &idAux);

	char pais[25];
	selec_getPais(unaSeleccion, pais);

	char confederacion[10];
	selec_getConfederacion(unaSeleccion, confederacion);

	int convocados;
	selec_getConvocados(unaSeleccion, &convocados);

	printf("\n%5i %25s %20s %15i", idAux, pais, confederacion, convocados);
}





