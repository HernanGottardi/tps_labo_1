
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "calculos.h"
#include "inputs.h"

#define MAX_JUGADORES 22

int main(void) {
	setbuf(stdout, NULL);
	int opcionPrincipal;
	int opcionMantenimiento;
	int opcionPosicion;

// 1) MANTENIMIENTO
	int acumHospedaje = 0, acumComida = 0, acumTransporte = 0;
	int costo;
	int aumento;
	int costoConAumento;

// 2) CARGA DE JUGADORES.
	int numCamiseta;

	int contadorJugadores = 0;
	int contadorArqueros = 0; // Maximo 2
	int contadorDefensores = 0; // Maximo 8
	int contadorMedioCampistas = 0; // Maximo 8
	int contadorDelanteros = 0; // Maximo 4

// 3) y 4)
	 int contadorAFC = 0;
	 int contadorCAF = 0;
	 int contadorCONCACAF = 0;
	 int contadorCONMEBOL = 0;
	 int contadorUEFA = 0;
	 int contadorOFC = 0;

	 float promedioAFC;
	 float promedioCAF;
	 float promedioCONCACAF;
	 float promedioCONMEBOL;
	 float promedioUEFA;
	 float promedioOFC;

	do {
		printf("\n---------- Lista de opciones ----------\n");

		printf("\n1- Ingreso de los costos de Mantenimiento");
		printf("\nCosto de hospedaje -> $%i", acumHospedaje);
		printf("\nCosto de comida -> $%i", acumComida);
		printf("\nCosto de transporte -> $%i\n", acumTransporte);

		printf("\n2- Carga de jugadores");
		printf("\nArqueros -> %i", contadorArqueros);
		printf("\nDefensores -> %i", contadorDefensores);
		printf("\nMediocampistas -> %i", contadorMedioCampistas);
		printf("\nDelanteros -> %i\n", contadorDelanteros);

		printf("\n3- Realizar todos los calculos");
		printf("\n4- Informar todos los resultados");
		printf("\n5- Salir");

		utn_getNumero(&opcionPrincipal, "\n\nCual opcion desea elegir?",
				"\nError", 1, 5, 3);

		switch (opcionPrincipal) {
		case 1:
			do {

				printf("\n--------------------------------------------------------");
				printf("\nLista de opciones para cargar costos de mantenimiento:");
				printf("\n--------------------------------------------------------");
				printf("\n1 - Costo de hospedaje");
				printf("\n2 - Costo de comida");
				printf("\n3 - Costo de transporte");
				printf("\n4 - Salir");

				utn_getNumero(&opcionMantenimiento,"\nOpcion que desea elegir:", "\nError", 1, 4, 3);

					switch (opcionMantenimiento) {
				case 1:

					utn_getNumero(&costo, "\nIngresar costo con numero entero:",
							"\nError, costo no esta en el rango.", 0, 10000000,
							3);
					acumHospedaje += costo;
					break;
				case 2:
					utn_getNumero(&costo, "\nIngresar costo con numero entero:",
							"\nError, costo no esta en el rango.", 0, 10000000,
							3);
					acumComida += costo;
					break;
				case 3:
					utn_getNumero(&costo, "\nIngresar costo con numero entero:",
							"\nError, costo no esta en el rango.", 0, 10000000,
							3);
					acumTransporte += costo;
					break;
					}

			} while (opcionMantenimiento != 4);

			break;
			// OPCION NUMERO DOS PARA OPCION PRINCIPAL - CARGA DE JUGADORES
		case 2:
			do {
				if (contadorJugadores < MAX_JUGADORES) {
					printf("\n--------------------------------------------------------");
					printf("\nLista de posiciones de jugadores");
					printf("\n--------------------------------------------------------");
					printf("\n1 - Arquero\n2 - Defensor\n3 - Medio Campista\n4 - Delantero\n5 - Salir");

					utn_getNumero(&opcionPosicion, "\nIngresar opcion aqui:",
							"\nError, no es ninguan de las cuatro opciones", 1,
							5, 3);

					switch(opcionPosicion){
					case 1:
						if (contadorArqueros < 2) {
							contadorArqueros++;
							contadorJugadores++;
							elegirCondeferacion(&contadorAFC, &contadorCAF,
									&contadorCONCACAF, &contadorCONMEBOL,
									&contadorUEFA, &contadorOFC);
							utn_getNumero(&numCamiseta, "Ingresar NUMERO DE CAMISETA del jugador: ",
										"Error, la camiseta no esta en el rango [1-99]", 1, 99, 3);
							printf("\nIngresaste exitosamente a un Arquero\n");

						} else {
							printf(
									"\nError, La cantidad de arqueros fue alcanzada\n");
						}
						break;
					case 2:
						if (contadorDefensores < 8) {
							contadorDefensores++;
							contadorJugadores++;
							elegirCondeferacion(&contadorAFC, &contadorCAF,
									&contadorCONCACAF, &contadorCONMEBOL,
									&contadorUEFA, &contadorOFC);
							utn_getNumero(&numCamiseta, "Ingresar NUMERO DE CAMISETA del jugador: ",
										"Error, la camiseta no esta en el rango [1-99]", 1, 99, 3);
							printf("\nIngresaste exitosamente a un Defensor\n");
						} else {
							printf(
									"\nError, la cantidad de defensores fue alcanzada\n");
						}
						break;
					case 3:
						if (contadorMedioCampistas < 8) {
							contadorMedioCampistas++;
							contadorJugadores++;
							elegirCondeferacion(&contadorAFC, &contadorCAF,
									&contadorCONCACAF, &contadorCONMEBOL,
									&contadorUEFA, &contadorOFC);
							utn_getNumero(&numCamiseta, "Ingresar NUMERO DE CAMISETA del jugador: ",
										"Error, la camiseta no esta en el rango [1-99]", 1, 99, 3);
							printf(
									"\nIngresaste exitosamente a un mediocampista\n");
						} else {
							printf(
									"\nError, la cantidad de medioCampistas fue alcanzada\n");
						}
						break;
					case 4:
						if (contadorDelanteros < 4) {
							contadorDelanteros++;
							contadorJugadores++;
							elegirCondeferacion(&contadorAFC, &contadorCAF,
									&contadorCONCACAF, &contadorCONMEBOL,
									&contadorUEFA, &contadorOFC);
							utn_getNumero(&numCamiseta, "Ingresar NUMERO DE CAMISETA del jugador: ",
										"Error, la camiseta no esta en el rango [1-99]", 1, 99, 3);
							printf(
									"\nIngresaste exitosamente a un delantero\n");
						} else {
							printf(
									"\nError, la cantidad de delanteros fue alcanzada\n");
						}
						break;
					}
				} else {
					printf("\nLa cantidad de jugadores fue alcanzada\n");
					break;
				}
			} while(opcionPosicion != 5);
			break;
			// OPCION 3 PARA OPCION PRINCIPAL - CALCULOS
		case 3:

			if(contadorJugadores > 0 && verificarExistenGastos(&acumTransporte, &acumHospedaje, &acumComida) == 1){
				printf("\nLos calculos fueron hechos exitosamente!\n");
				promedioAFC = calcularPromedio(&contadorAFC, &contadorJugadores);
				promedioCAF =  calcularPromedio(&contadorCAF, &contadorJugadores);
				promedioCONCACAF = calcularPromedio(&contadorCONCACAF, &contadorJugadores);
				promedioCONMEBOL = calcularPromedio(&contadorCONMEBOL, &contadorJugadores);
				promedioOFC = calcularPromedio(&contadorOFC, &contadorJugadores);
				promedioUEFA = calcularPromedio(&contadorUEFA, &contadorJugadores);

				costo = acumComida + acumHospedaje + acumTransporte;
			} else {
				printf("\nError, todavia no se cargaron datos en opcion 1 y 2");
			}

			break;
		case 4:
			if (contadorJugadores > 0 && verificarExistenGastos(&acumTransporte, &acumHospedaje, &acumComida) == 1)
			{
				printf("\n----------Informar todos los calculos----------\n");
				printf("\nPorcentaje Uefa %0.2f", promedioUEFA);
				printf("\nPorcentaje Conmebol %0.2f", promedioCONMEBOL);
				printf("\nPorcentaje Concacaf %0.2f", promedioCONCACAF);
				printf("\nPorcentaje Afc %0.2f", promedioAFC);
				printf("\nPorcentaje Ofc %0.2f", promedioOFC);
				printf("\nPorcentaje Caf %0.2f", promedioCAF);
				if (contadorUEFA > contadorAFC && contadorUEFA > contadorOFC
						&& contadorUEFA > contadorCAF
						&& contadorUEFA > contadorCONCACAF
						&& contadorUEFA > contadorCONMEBOL)
				{
					aumento = costo * 35 / 100;
					costoConAumento = costo + aumento;
					printf(
							"\nEl costo de mantenimiento era de %i y "
									"recibio un aumento de $%i, su nuevo valor es de: $%i\n",
							costo, aumento, costoConAumento);
				} else {
					printf("\nEl costo de mantenimiento es de %i\n", costo);
				}

			} else {
				printf("\nError, todavia no se cargaron datos en opcion 1 y 2\n");
			}

			break;
		}
	} while (opcionPrincipal != 5);

	return EXIT_SUCCESS;
}

//-------------------------------------------------------------

