
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "inputs.h"

/****************************************************
fdgd
  1) Carga de archivos. [X]
  2) Alta de jugador. [X]
  3) Modificacion de jugador. [X]
  4) Baja de jugador. [X]
  5) Listados. [X]
  6) Convocar jugadores. [X]
  7) Ordenar y listar. [X]
  8) Generar archivo binario. [O - Leer]
  9) Cargar archivo binario. [O - Leer]
  10) Guardar archivos .csv [X]
  11) Salir. [X]

****************************************************/

int main()
{
	setbuf(stdout,NULL);
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();
    LinkedList* auxConvocados = NULL;
    //auxConvocados = ll_clone(listaJugadores);
    //ll_clear(auxConvocados);
    char salir = 'N';
    int flagGuardado = 0;
    int flagCargado = 0;

    do {
		switch (menu()) {
		case 1:
			if (flagCargado == 0) {
				if (controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores)
						&& controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones)) {
					printf("\nLos datos de archivo de texto se cargaron bien!");
				}
				flagCargado++;
			} else {
				printf("\nYa existe un archivo en memoria.");
			}

			break;
		case 2:
			controller_agregarJugador(listaJugadores);
			break;
		case 3:
			controller_listarJugadores(listaJugadores, listaSelecciones);
			controller_editarJugador(listaJugadores);
			break;
		case 4:
			if (ll_len(listaJugadores) > 0) {
				if (controller_removerJugador(listaJugadores)) {
					printf("\nBaja realizada con exito!\n");
					printf("\nCantidad de pasajeros: %i\n", ll_len(listaJugadores));
				}
			} else {
				printf("\nNo puede dar de baja porque aun no se ingresaron jugadores. \n\n");
			}
			break;
		case 5:
			switch (menuListados()) {
			case 1:
				controller_listarJugadores(listaJugadores, listaSelecciones);
				break;
			case 2:
				controller_listarSelecciones(listaSelecciones);
				break;
			case 3:
				controller_mostrarJugadoresConvocados(listaSelecciones, listaJugadores);
				break;
			}
			break;
		case 6:
			if(menuConvocar() == 1){
				controller_convocarjugadores(listaJugadores, listaSelecciones);
			} else {
				controller_quitarConvocado(listaJugadores, listaSelecciones);
			}
			break;
		case 7:
			controller_ordenarYListar(listaJugadores, listaSelecciones);
			break;
		case 8:
			controller_GenerarArchivoConvocadosPorConfederacion(listaJugadores, listaSelecciones, auxConvocados);
			break;
		case 9:
			controller_imprimirArchivoConvocados(listaJugadores, "convocadosConfe.bin");
			break;
		case 10:
			if (ll_len(listaJugadores) > 0) {
				if (controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores)
					&& controller_guardarSeleccionesModoTexto("selecciones.csv", listaSelecciones)) {
					printf("\nArchivos de texto guardado exitosamente!");
					flagGuardado++;
				}
			} else {
				printf("\nAun no se ingresaron jugadores. \n\n");
			}
			break;
		case 11:
			if (flagGuardado == 0) {
				printf("\nAntes de salir debe guardar el archivo...");
			} else {
				confirmacion("\n¿Seguro que desea salir? [S/N]: ", &salir);
			}
			break;
		}
	} while (salir != 'S');

	ll_deleteLinkedList(listaJugadores);
	ll_deleteLinkedList(listaSelecciones);
	return 0;
}

