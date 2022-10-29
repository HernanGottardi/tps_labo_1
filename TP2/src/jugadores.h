/*
 * jugadores.h
 *
 *  Created on: 17 oct. 2022
 *      Author: herni
 */

#ifndef JUGADORES_H_
#define JUGADORES_H_

#include "confederacion.h"

typedef struct{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;


int inicializar_estado_jugadores(eJugador jugadores[], int tamJugadores);
// -----------------------------------------------------------------------------------------------------------------
int elegirPosicion (char mensaje[], char cadenaPosicion[], int tamPosicion);
int darAltaJugador(eJugador jugadores[], int tamJugadores, eConfederacion confeder[], int tamConf, int idAutomatico);
// -----------------------------------------------------------------------------------------------------------------
int darBajaJugador(eJugador jugadores[], int tamJugadores, eConfederacion confederaciones[], int tamConfe);
// -----------------------------------------------------------------------------------------------------------------
int modificarJugador(eJugador jugadores[], int tamJugadores, eConfederacion confederaciones[], int tamConfeder);
int modificarNombre(char nombre[]);
int modificarPosicion(char posicion[]);
int modificarCamiseta(short *camiseta);
int modificarIdConfederacion(int *idConfederacion, eConfederacion confederaciones[], int tamConfe);
int modificarSalario(float *salario);
int modificarContrato(short *contrato);


#endif /* JUGADORES_H_ */
