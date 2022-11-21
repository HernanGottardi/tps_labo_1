

#include <stdio.h>
#include <stdlib.h>

#include "jugadores.h"
#include "confederacion.h"
#include "inputs.h"
#include "outputs.h"

#define VACIO 0
#define LLENO 1

#define TAM_CONFE 6
#define TAM_JUGADORES 3000

int main(void) {
	setbuf(stdout, NULL);
	int idJugadorAutoIncre = 1;
	int contadorJugadores = 0;
	int contadorJugadoresAux;

	int idConfederacionAutoIncre = 1;
	int contadorConfederaciones = 0;

	char confirmarSalir = 'N';

	eJugador jugadores[TAM_JUGADORES];

	eConfederacion confederaciones[TAM_JUGADORES];
	harcodearConfederacion(confederaciones, TAM_CONFE);

	inicializar_estado_jugadores(jugadores,TAM_JUGADORES);
	do{

		switch(menuPrincipal()){
		case 1:
			// ALTA DE JUGADOR
			if (contadorJugadores < TAM_JUGADORES) {
				if (darAltaJugador(jugadores, TAM_JUGADORES,confederaciones, TAM_CONFE, idJugadorAutoIncre) == 1) {
					contadorJugadores++;
					idJugadorAutoIncre++;
				}
			} else {
				printf("\nNo hay mas espacio para carga de jugadores.");
			}
			break;
		case 2:
			// BAJA DE JUGADOR
			if(darBajaJugador(jugadores, TAM_JUGADORES, confederaciones, TAM_CONFE, &contadorJugadoresAux) == 1){
				contadorJugadores--;
			}
			break;
		case 3:
			// MODIFICAR JUGADORES
			modificarJugador(jugadores, TAM_JUGADORES, confederaciones,TAM_CONFE, &contadorJugadoresAux);
			break;
		case 4:
			// INFORMES
			informar(jugadores, TAM_JUGADORES, confederaciones, TAM_CONFE, &contadorJugadoresAux);
			break;
		case 5:
			//ABM CONFE
			abmConfederacion(confederaciones, TAM_CONFE, &idConfederacionAutoIncre, &contadorConfederaciones);
			break;
		case 6:
			// SALIR
			confirmacion("\nSeguro que desea salir del programa? [s/n]: ", &confirmarSalir);
			break;
		}
	}while(confirmarSalir == 'N');

	return EXIT_SUCCESS;
}
