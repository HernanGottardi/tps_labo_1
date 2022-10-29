

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

	int idConfederacionAutoIncre = 1;
	int contadorConfederaciones = 0;

	int opcionPrincipal;
	char confirmarSalir;
	int bandera = 1;

	eJugador jugadores[TAM_JUGADORES];

	eConfederacion confederaciones[TAM_JUGADORES];
	harcodearConfederacion(confederaciones, TAM_CONFE);

	inicializar_estado_jugadores(jugadores,TAM_JUGADORES);
	do{
		printf("\nLista de opciones:");
		printf("\n1- Dar de ALTA\n2- Dar de BAJA\n3- MODIFICAR\n4- INFORMAR\n5- ABM-Confederacion\n6- SALIR");
		fflush(stdin);
		utn_getNumero(&opcionPrincipal, "\nIngresar opcion: ", "\nError, ingresar numero en rango [1-6]", 1, 6);
		switch(opcionPrincipal){
		case 1:
			// ALTA DE JUGADOR
			if (contadorJugadores < 3000) {
				if (darAltaJugador(jugadores, TAM_JUGADORES,confederaciones, TAM_CONFE, idJugadorAutoIncre) == 1) {
					printf("\n----------- La carga salio bien -----------\n");
					contadorJugadores++;
					idJugadorAutoIncre++;
				} else {
					printf("\n----------- La carga de jugador salio mal -----------\n");
				}
			} else {
				printf("\nNo hay mas espacio para carga de jugadores.");
			}
			break;
		case 2:
			// BAJA DE JUGADOR
			if(contadorJugadores > 0){
				if(darBajaJugador(jugadores, TAM_JUGADORES, confederaciones, TAM_CONFE) == 1){
					contadorJugadores--;
				} else {
					printf("\n----------- El ID ingreado no existe -----------\n");
				}
			}
			break;
		case 3:
			// MODIFICAR JUGADORES
			if(contadorJugadores > 0){
				if(modificarJugador(jugadores, TAM_JUGADORES, confederaciones, TAM_CONFE) != 1){
					printf("\n----------- El ID de jugador ingresado no existe -----------\n");
				}
			}
			break;
		case 4:
			if(contadorJugadores > 0){
				informar(jugadores, TAM_JUGADORES, confederaciones, TAM_CONFE);
			}
			break;
		case 5:
			abmConfederacion(confederaciones, TAM_CONFE, &idConfederacionAutoIncre, &contadorConfederaciones);
			break;
		case 6:
			confirmacion("\nSeguro que desea salir del programa? [s/n]: ", &confirmarSalir);
			if(confirmarSalir == 'S'){
				bandera = 0;
			}
			break;
		}
	}while(bandera == 1);

	return EXIT_SUCCESS;
}


























