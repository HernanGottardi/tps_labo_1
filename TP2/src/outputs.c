/*
 * outputs.c
 *
 *  Created on: 26 oct. 2022
 *      Author: herni
 */
#include <stdio.h>
#include <stdlib.h>

#include "outputs.h"
#include "confederacion.h"
#include "inputs.h"
#include "jugadores.h"

#define VACIO 0
#define LLENO 1

/**
 * \fn void mostrarJugadores(eJugador[], int, eConfederacion[], int)
 * \brief Funcion encargada de recorrer el array de estructuras eJugador y eConfederacion, para
 * imprimir la informacion que guardan los campos de las estructuras con estado LLENO.
 *
 * \param jugadores - array de estructuras del tipo eJugador.
 * \param tamJugadores - cantidad de estructuras del tipo eJugador.
 * \param confederaciones - array de estructuras del tipo eConfederacion.
 * \param tamConfe - cantidad de estructuras del tipo eConfederacion.
 */

void mostrarJugadores(eJugador jugadores[], int tamJugadores, eConfederacion confederaciones[], int tamConfe){
	eJugador* pJugador;
    eConfederacion* pConfederacion;
    pJugador = jugadores;
    pConfederacion = confederaciones;
	if(jugadores != NULL && tamJugadores > 0 && confederaciones != NULL && tamConfe > 0){
		//printf("\n\nLISTA DE JUGADORES INGRESADOS:");
		printf("\n=====================================================================================================================");
		printf("\n| %-4s| %-20s| %-15s| %-12s| %-15s| %-15s | %-20s |", "ID", "NOMBRE", "POSICION", "N-CAMISETA", "SALARIO", "CONFEDERACION", "AÑOS CONTRATO");
		printf("\n=====================================================================================================================");
		for(int i = 0; i < tamJugadores - 1; i++){
			if((pJugador + i)->isEmpty == LLENO){
			    for(int j = 0; j < tamConfe; j++){
					if((pJugador + i)->idConfederacion == (pConfederacion + j)->id){
						printf("\n| %-4d| %-20s| %-15s| %-12d| %-15.2f| %-15s | %-20d|",  (pJugador + i)->id, (pJugador + i)->nombre,
							(pJugador + i)->posicion, (pJugador + i)->numeroCamiseta,
							(pJugador + i)->salario, (pConfederacion + j)->nombre, (pJugador + i)->aniosContrato);
				    }
				}
			}
		}
		printf("\n=====================================================================================================================");
	}
}
/**
 * \fn void mostrarConfederaciones(eConfederacion[], int)
 * \brief Funcion encargada de recorrer las posiciones del array de estructuras
 * eConfederacion y mostrar sus campos.
 *
 * \param confederaciones - array de estructuras del tipo eConfederacion.
 * \param tamConfederaciones - cantidad de estructuras del tipo eConfederacion.
 */
void mostrarConfederaciones(eConfederacion confederaciones[], int tamConfederaciones){
	if(confederaciones != NULL && tamConfederaciones > 0){
		printf("\n\nLISTA DE CONFEDERACIONES:");
		printf("\n========================================================================");
		printf("\n| %-4s| %-20s| %-25s| %14s |", "ID", "NOMBRE", "REGION", "AÑO CREACION");
		printf("\n========================================================================");
		for(int i = 0; i < tamConfederaciones; i++){
			if (confederaciones[i].isEmpty == LLENO) {
				printf("\n| %-4d| %-20s| %-25s| %-14d|", confederaciones[i].id,
						confederaciones[i].nombre, confederaciones[i].region,
						confederaciones[i].anioCreacion);
			}
		}
		printf("\n========================================================================");
	}
}
/**
 * \fn void ordenarJugadores(eJugador[], int, eConfederacion[], int)
 * \brief Funcion encargada de ordenar el array de estructuras eJugador de acuerdo a dos
 * criterios de ordenamiento.
 *
 * \param jugadores - array de estructuras del tipo eJugador.
 * \param tamJugadores - cantidad de estructuras del tipo eJugador.
 * \param confederaciones - array de estructuras del tipo eConfederacion.
 * \param tamConfe - cantidad de estructuras del tipo eConfederacion.
 */
void ordenarJugadores(eJugador jugadores[], int tamJugadores, eConfederacion confederaciones[], int tamConfe){
	eJugador jugadorAux;

	if(jugadores != NULL && tamJugadores > 0 && confederaciones != NULL && tamConfe > 0){

		for (int i = 0; i < tamJugadores - 1; i++) {
			for(int j = 1 + i; j < tamJugadores; j++){
				if(jugadores[i].isEmpty == LLENO && jugadores[j].isEmpty == LLENO){

					for(int a = 0; a < tamConfe; a++){
						for(int b = 0; b < tamConfe; b++){
						  if(jugadores[i].idConfederacion == confederaciones[a].id && jugadores[j].idConfederacion == confederaciones[b].id){
							  if(strcmp(confederaciones[a].nombre, confederaciones[b].nombre) < 0){
									jugadorAux = jugadores[i];
									jugadores[i] = jugadores[j];
									jugadores[j] = jugadorAux;
							} else {
								   if(strcmp(confederaciones[a].nombre, confederaciones[b].nombre) == 0){
									   if(strcmpi(jugadores[i].nombre, jugadores[j].nombre) < 0){
										    jugadorAux = jugadores[i];
											jugadores[i] = jugadores[j];
											jugadores[j] = jugadorAux;
									}
								}
							}
						}
					}
				}
			}
		}
	}

	mostrarJugadores(jugadores, tamJugadores, confederaciones, tamConfe);
  }
}
/**
 * \fn void encontrarConfeConJugadores(eJugador[], int, eConfederacion[], int, int)
 * \brief Funcion encargada de recorrer, encontrar y mostrar los jugadores con sus
 * correspondientes confederaciones.
 *
 * \param jugadores - array de estructuras del tipo eJugador.
 * \param tamJugadores - cantidad de estructuras del tipo eJugador.
 * \param confederaciones - array de estructuras del tipo eConfederacion.
 * \param tamConfe - cantidad de estructuras del tipo eConfederacion.
 * \param idConfe - id de confederacion.
 */
void encontrarConfeConJugadores(eJugador jugadores[], int tamJugadores, eConfederacion confe[], int tamConfe, int idConfe){
	if(jugadores != NULL && confe != NULL && tamJugadores > 0 && tamConfe > 0){
		for(int i = 0; i < tamJugadores; i++){
			if(jugadores[i].isEmpty == LLENO){
				for(int j = 0; j < tamConfe; j++){
					if(jugadores[i].idConfederacion == idConfe && jugadores[i].idConfederacion == confe[j].id){
						printf("\n| %-20s| %-20s|", jugadores[i].nombre, confe[j].nombre);
					}
				}
			}
		}
	}
}

/**
 * \fn void mostrarConfederacionesConJugadores(eJugador[], int, eConfederacion[], int)
 * \brief Funcion encargada de mostrar los campos de la estructura eJugador con sus
 * respectivas confederaciones dentro de la estructura eConfederacion.
 *
 * \param jugadores - array de estructuras del tipo eJugador.
 * \param tamJugadores - cantidad de estructuras del tipo eJugador.
 * \param confederaciones - array de estructuras del tipo eConfederacion.
 * \param tamConfe - cantidad de estructuras del tipo eConfederacion.
 */

void mostrarConfederacionesConJugadores(eJugador jugadores[], int tamJugadores, eConfederacion confe[], int tamConfe){

	if(jugadores != NULL && confe != NULL && tamJugadores > 0 && tamConfe > 0){
		printf("\n=============================================");
		printf("\n| %-20s| %-20s|", "JUGADORES", "CONFEDERACIONES");
		printf("\n=============================================");
		for(int i = 1; i < 7; i++){
			encontrarConfeConJugadores(jugadores, tamJugadores, confe, tamConfe, i);
		}
		printf("\n=============================================\n");
	}
}
/**
 * \fn void mostrarTotalPromedio(eJugador[], int)
 * \brief Funcion encargada de calcular y mostrar el promedio de los salarios de los jugadores
 * del array de estructuras eJugador.
 *
 * \param jugadores - array de estructuras del tipo eJugador.
 * \param tamJugadores - cantidad de estructuras del tipo eJugador.
 */
void mostrarTotalPromedio(eJugador jugadores[], int tamJugadores){
	float promedio;
	int acumSalarios = 0;
	int contadorSalarios = 0;
	int contadorSalariosMayores = 0;
	if(jugadores != NULL && tamJugadores > 0){
		for(int i = 0; i < tamJugadores; i++){
			if(jugadores[i].isEmpty == LLENO){
				acumSalarios += jugadores[i].salario;
				contadorSalarios++;
			}
		}
		promedio = (float) acumSalarios / contadorSalarios;
		for(int i = 0; i < tamJugadores; i++){
			if(jugadores[i].isEmpty == LLENO && jugadores[i].salario > promedio){
				contadorSalariosMayores++;
			}
		}
		printf("\n--------------------------------------------------------------------------------------------------");
		printf("\nTOTAL SALARIOS: %i\nPROMEDIO SALARIOS: %0.2f\nCANTIDAD JUGADORES CON SALARIO MAYOR A PROMEDIO: %i",
				acumSalarios, promedio, contadorSalariosMayores);
		printf("\n--------------------------------------------------------------------------------------------------");
	}

}
/**
 * \fn void encontrarMayorAniosConfe(int, int, int, int, int, int, char[])
 * \brief Funcion encargada de encontrar que confederacion tiene la mayor
 * cantidad de anios de contrato.
 *
 * \param acumConmebol - acumulador encargado de guardar la cantidad de anios total
 * de contrato de la confederacion conmebol.
 * \param acumAfc - acumulador encargado de guardar la cantidad de anios total
 * de contrato de la confederacion afc.
 * \param acumCaf - acumulador encargado de guardar la cantidad de anios total
 * de contrato de la confederacion caf.
 * \param acumConcacaf - acumulador encargado de guardar la cantidad de anios total
 * de contrato de la confederacion concacaf.
 * \param acumOfc - acumulador encargado de guardar la cantidad de anios total
 * de contrato de la confederacion ofc.
 * \param acumUefa - acumulador encargado de guardar la cantidad de anios total
 * de contrato de la confederacion uefa.
 * \param guardar - en esta cadena de caracteres se guardara en nombre de la
 * confederacion con mayor acumulacion de anios de contrato
 */
void encontrarMayorAniosConfe(int acumConmebol, int acumAfc, int acumCaf,
		int acumConcacaf, int acumOfc, int acumUefa, char guardar[]){

	if(acumConmebol > acumAfc && acumConmebol > acumCaf &&
			acumConmebol > acumConcacaf && acumConmebol > acumOfc
					&& acumConmebol > acumUefa){
				strcpy(guardar, "CONMEBOL");
			} else {
				if(acumAfc > acumCaf && acumAfc > acumConcacaf &&
						acumAfc > acumOfc && acumAfc > acumUefa){
					strcpy(guardar, "AFC");
				} else {
					if(acumCaf > acumConcacaf && acumCaf > acumOfc &&
							acumCaf > acumUefa){
						strcpy(guardar, "CAF");
					} else {
						if(acumConcacaf > acumOfc && acumConcacaf > acumUefa){
							strcpy(guardar, "CONCACAF");
						} else {
							if(acumOfc > acumUefa){
								strcpy(guardar, "OFC");
							} else {
								strcpy(guardar, "UEFA");
						}
					}
				}
		  }
	 }
}

/**
 * \fn void mostrarConfederacionMasAnios(eJugador[], int, eConfederacion[], int)
 * \brief Funcion encargada de mostrar nombre de la confederacion con mayor
 * cantidad de anios.
 *
 * \param jugadores - array de estructuras del tipo eJugador.
 * \param tamJugadores - cantidad de estructuras del tipo eJugador.
 * \param confederaciones - array de estructuras del tipo eConfederacion.
 * \param tamConfe - cantidad de estructuras del tipo eConfederacion.
 */
void mostrarConfederacionMasAnios(eJugador jugadores[], int tamJug, eConfederacion confe[], int tamConfe){

	int contadorAniosConmebol = 0;
	int contadorAniosUefa = 0;
	int contadorAniosAfc = 0;
	int contadorAniosCaf = 0;
	int contadorAniosConcacaf = 0;
	int contadorAniosOfc = 0;

	char confederacionesMayor[50];

	if(jugadores != NULL && confe != NULL && tamJug > 0 && tamConfe > 0){
		for(int i = 0; i < tamJug; i++){
			if(jugadores[i].isEmpty == LLENO){
				switch(jugadores[i].idConfederacion){
				case 1:
					contadorAniosConmebol += jugadores[i].aniosContrato;
					break;
				case 2:
					contadorAniosUefa += jugadores[i].aniosContrato;
					break;
				case 3:
					contadorAniosAfc += jugadores[i].aniosContrato;
					break;
				case 4:
					contadorAniosCaf += jugadores[i].aniosContrato;
					break;
				case 5:
					contadorAniosConcacaf += jugadores[i].aniosContrato;
					break;
				case 6:
					contadorAniosOfc += jugadores[i].aniosContrato;
					break;
				}
			}
		}
		encontrarMayorAniosConfe(contadorAniosConmebol, contadorAniosAfc,
				contadorAniosCaf, contadorAniosConcacaf, contadorAniosOfc, contadorAniosUefa, confederacionesMayor);
		printf("\n-------------------------------------------------------------------------------");
		printf("\nConfederacion con mayor cantidad de años de contrato: %s", confederacionesMayor);
		printf("\n-------------------------------------------------------------------------------");

	}
}
/**
 * \fn void mostrarPorcentajeConfe(eJugador[], int)
 * \brief Funcion encargada de mostrar el porcentaje de jugadores por cada confederacion.
 *
 * \param jugadores - array de estructuras del tipo eJugador.
 * \param tamJugadores - cantidad de estructuras del tipo eJugador.

 */

void mostrarPorcentajeConfe(eJugador jugadores[], int tamJugadores){

	int contadorJugadoresConmebol = 0;
	float porcentajeConmebol;
	int contadorJugadoresUefa = 0;
	float porcentajeUefa;
	int contadorJugadoresAfc = 0;
	float porcentajeAfc;
	int contadorJugadoresCaf = 0;
	float porcentajeCaf;
	int contadorJugadoresConcacaf = 0;
	float porcentajeConcacaf;
	int contadorJugadoresOfc = 0;
	float porcentajeOfc;

	int contadorTotal = 0;

	if(jugadores != NULL && tamJugadores > 0){
		for(int i = 0; i < tamJugadores; i++){
			if (jugadores[i].isEmpty == LLENO) {
				switch (jugadores[i].idConfederacion) {
				case 1:
					contadorJugadoresConmebol++;
					contadorTotal++;
					break;
				case 2:
					contadorJugadoresUefa++;
					contadorTotal++;
					break;
				case 3:
					contadorJugadoresAfc++;
					contadorTotal++;
					break;
				case 4:
					contadorJugadoresCaf++;
					contadorTotal++;
					break;
				case 5:
					contadorJugadoresConcacaf++;
					contadorTotal++;
					break;
				case 6:
					contadorJugadoresOfc++;
					contadorTotal++;
					break;
				}
			}
		}

		porcentajeConmebol = (float)contadorJugadoresConmebol * 100 / contadorTotal;
		porcentajeAfc = (float) contadorJugadoresAfc * 100 / contadorTotal;
		porcentajeConcacaf = (float) contadorJugadoresConcacaf * 100 / contadorTotal;
		porcentajeCaf = (float) contadorJugadoresCaf * 100 / contadorTotal;
		porcentajeOfc = (float) contadorJugadoresOfc * 100 / contadorTotal;
		porcentajeUefa = (float) contadorJugadoresUefa * 100 / contadorTotal;

		printf("\n---------------------------");
		printf("\nPorcentaje CONMEBOL: %0.2f porciento", porcentajeConmebol);
		printf("\nPorcentaje CONCACAF: %0.2f porciento", porcentajeConcacaf);
		printf("\nPorcentaje AFC: %0.2f porciento", porcentajeAfc);
		printf("\nPorcentaje CAF: %0.2f porciento", porcentajeCaf);
		printf("\nPorcentaje OFC: %0.2f porciento", porcentajeOfc);
		printf("\nPorcentaje UEFA: %0.2f porciento", porcentajeUefa);
		printf("\n---------------------------");

	}
}
/**
 * \fn void encontrarMayorRegionJugadores(char[], int, int, int, int, int, int)
 * \brief Funcion encargada de mostrar la region con mayor cantidad de jugadores ingresados.
 *
 * \param guardarMayoRegion - cadena de caracteres donde se guardara el nombre de la region con
 * mayor cantidad de jugadores.
 * \param contSudAmerican - contador jugadores de la region sudamerica.
 * \param contAsia - contador jugadores de la region asia.
 * \param contOceania - contador jugadores de la region oceania.
 * \param contCentroNorteAmerica - contador jugadores de la region centro y norte america.
 * \param contEuropa - contador jugadores de la region europa.
 * \param contAfrica - contador jugadores de la region africa.
 */
void encontrarMayorRegionJugadores(char guardarMayoRegion[], int contSudAmerican, int contAsia, int contOceania,
		int contCentroNorteAmerica, int contEuropa, int contAfrica){

	if (contSudAmerican > contAsia && contSudAmerican > contOceania
			&& contSudAmerican > contCentroNorteAmerica && contSudAmerican > contAfrica
			&& contSudAmerican > contEuropa) {
		strcpy(guardarMayoRegion, "SUDAMERICA");
	} else {
		if (contAsia > contAfrica && contAsia > contCentroNorteAmerica && contAsia > contOceania
				&& contAsia > contEuropa) {
			strcpy(guardarMayoRegion, "ASIA");
		} else {
			if (contAfrica > contCentroNorteAmerica && contAfrica > contOceania
					&& contAfrica > contEuropa) {
				strcpy(guardarMayoRegion, "AFRICA");
			} else {
				if (contCentroNorteAmerica > contOceania && contCentroNorteAmerica > contEuropa) {
					strcpy(guardarMayoRegion, "CENTRO/NORTE AMERICA");
				} else {
					if (contOceania > contEuropa) {
						strcpy(guardarMayoRegion, "OCEANIA");
					} else {
						strcpy(guardarMayoRegion, "EUROPA");
					}
				}
			}
		}
	}

}
/**
 * \fn void mostrarRegionMasJugadores(eJugador[], int, eConfederacion[], int)
 * \brief Funcion encargada de mostrar la region con mas jugadores cargados.
 *
 * \param jugadores - array de estructuras del tipo eJugador.
 * \param tamJugadores - cantidad de estructuras del tipo eJugador.
 * \param confederaciones - array de estructuras del tipo eConfederacion.
 * \param tamConfe - cantidad de estructuras del tipo eConfederacion.
 */
void mostrarRegionMasJugadores(eJugador jugadores[], int tamJugadores,
		eConfederacion confede[], int tamConfe){
	int sudamerica = 0;
	int asia = 0;
	int oceania = 0;
	int centroNorteAmerica = 0;
	int europa = 0;
	int africa = 0;
	char region[50];

	if (jugadores != NULL && tamJugadores > 0) {
		for (int i = 0; i < tamJugadores; i++) {
			if (jugadores[i].isEmpty == LLENO) {
				switch (jugadores[i].idConfederacion) {
				case 1:
					sudamerica++;
					break;
				case 2:
					europa++;
					break;
				case 3:
					asia++;
					break;
				case 4:
					africa++;
					break;
				case 5:
					centroNorteAmerica++;
					break;
				case 6:
					oceania++;
					break;
				}
			}
		}
	encontrarMayorRegionJugadores(region, sudamerica, asia, oceania, centroNorteAmerica, europa, africa);
	printf("\n---------------------------------------------------------------------------------------------------------------------");
	printf("\nLa region con mayor cantidad de jugadores es: %s", region);
	mostrarJugadoresSegunRegion(jugadores, tamJugadores, confede, tamConfe, region, 50);
	}
}
/**
 * \fn void mostrarJugadoresSegunRegion(eJugador[], int, eConfederacion[], int, char[], int)
 * \brief Funcion encagaragada de imprimir por pantalla a los jugadores de la region con
 * mas jugadores cargados.
 *
 * \param jugadores - array de estructuras del tipo eJugador.
 * \param tamJugadores - cantidad de estructuras del tipo eJugador.
 * \param confederaciones - array de estructuras del tipo eConfederacion.
 * \param tamConfederaciones - cantidad de estructuras del tipo eConfederacion.
 * \param regionMasJugadores - bombre de la region con mas jugadores ingresados.

 */
void mostrarJugadoresSegunRegion(eJugador jugadores[], int tamJugadores, eConfederacion confederaciones[],
		int tamCofederaciones, char regionMasJugadores[]){

	if(jugadores != NULL && confederaciones != NULL && tamJugadores > 0 && tamCofederaciones > 0
			&& regionMasJugadores != NULL){

		printf("\nLISTA DE LOS JUGADORES DE LA REGION:");
		printf("\n=====================================================================================================================");
		printf("\n| %-4s| %-20s| %-15s| %-12s| %-15s| %-15s | %-20s |", "ID", "NOMBRE", "POSICION", "N-CAMISETA", "SALARIO", "CONFEDERACION", "AÑOS CONTRATO");
		printf("\n=====================================================================================================================");
		for(int i = 0; i < tamJugadores; i++){
			if (jugadores[i].isEmpty == LLENO) {
				for (int a = 0; a < tamCofederaciones; a++) {
					if(jugadores[i].idConfederacion == confederaciones[a].id &&
							strcmp(confederaciones[a].region, regionMasJugadores) == 0){
						printf("\n| %-4d| %-20s| %-15s| %-12d| %-15.2f| %-15s | %-20d|", jugadores[i].id, jugadores[i].nombre,
								jugadores[i].posicion, jugadores[i].numeroCamiseta,
								jugadores[i].salario, confederaciones[a].region, jugadores[i].aniosContrato);

					}
				}
			}
		}
		printf("\n=====================================================================================================================");
	}
}
/**
 * \fn int informar(eJugador[], int, eConfederacion[], int)
 * \brief Funcion encargada de mostrar al usuario las opciones que puede seleccionar
 * para entrar a las diferentes opciones y mostrarle lo que pida.
 *
 * \param jugadores - array de estructuras del tipo eJugador.
 * \param tamJugadores - cantidad de estructuras del tipo eJugador.
 * \param confederaciones - array de estructuras del tipo eConfederacion.
 * \param tamConfe - cantidad de estructuras del tipo eConfederacion.
 */
int informar(eJugador jugadores[], int tamJugadores, eConfederacion confede[], int tamConfe){
	int retorno = 0;
	int opcion;
	if(jugadores != NULL && tamJugadores > 0){
		printf("\nLISTA DE COSAS A INFORMAR: ");
		printf("\n1- Lista de jugadores ordenada\n2- Lista de confederaciones y sus jugadores.");
		printf("\n3- Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio.");
		printf("\n4- Informar la confederación con mayor cantidad de años de contratos total.");
		printf("\n5- Informar porcentaje de jugadores por cada confederación.");
		printf("\n6- Informar cual es la región con más jugadores y el listado de los mismos.");
		utn_getNumero(&opcion, "\nIngresar opcion de informe: ", "\nError, vuelva a intenar en el rango [1-6]", 1, 6);
		retorno = 1;
		switch(opcion){
		case 1:
			ordenarJugadores(jugadores, tamJugadores, confede, tamConfe);
			break;
		case 2:
			mostrarConfederacionesConJugadores(jugadores, tamJugadores, confede, tamConfe);
			break;
		case 3:
			mostrarTotalPromedio(jugadores, tamJugadores);
			break;
		case 4:
			mostrarConfederacionMasAnios(jugadores, tamJugadores, confede, tamConfe);
			break;
		case 5:
			mostrarPorcentajeConfe(jugadores, tamJugadores);
			break;
		case 6:
			mostrarRegionMasJugadores(jugadores, tamJugadores, confede, tamConfe);
			break;
		}
	}
	return retorno;
}
