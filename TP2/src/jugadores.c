/*
 * jugadores.c
 *
 *  Created on: 17 oct. 2022
 *      Author: herni
 */


#include <stdio.h>
#include <stdlib.h>

#include "confederacion.h"
#include "inputs.h"
#include "jugadores.h"
#include "outputs.h"

#define VACIO 0
#define LLENO 1

/**
 * \fn int inicializar_estado_jugadores(eJugador[], int)
 * \brief Funcion encargada de inicializar todos los campos isEmpty del array
 * de estructuras del tipo eJugador, para que esten vacios y disponibles para cargarle datos.
 *
 * \param jugadores - array de estructuras del tipo eJugador.
 * \param tamJugadores - tamaño del array de estructuras del tipo eJugador.

 */
int inicializar_estado_jugadores(eJugador jugadores[], int tamJugadores){
	int retorno = 0;
	eJugador* jugador;
	jugador = jugadores;

	if(jugadores != NULL && tamJugadores > 0){
		retorno = 1;
		for(int i = 0; i < tamJugadores; i++){
			//jugadores[i].isEmpty = VACIO;
			(jugador + i)->isEmpty = VACIO;
		}
	}
	return retorno;
}

/**
 * \fn int elegirPosicion(char[], char[], int)
 * \brief Funcion encargada de desplegar una serie de opciones al usuario,
 * para que elija via numericamente, cual posicion desea elegir.
 *
 * \param mensaje - Cadena de texto que se encargara de imprimir en pantalla detallando lo que debe ingresar el usuario.
 * \param cadenaPosicion - cadena de caracteres donde se guardara automaticamente la posicion, segun la opcion numerica que ingrese.
 * \param tamPosicion - cantidad de caracteres que permite la cadena de caracteres posicion.
 */
int elegirPosicion (char mensaje[], char cadenaPosicion[], int tamPosicion){
	int retorno = 0;
	int opcionPosicion;
	if(cadenaPosicion != NULL && tamPosicion > 0){
		retorno = 1;
		printf("\nLista de posiciones: ");
		printf("\n1-Arquero\n2-Defensor\n3-Medio Campista\n4-Delantero");
		utn_getNumero(&opcionPosicion, mensaje, "\nError, elegir numero de posicion: ", 1, 4);
		switch(opcionPosicion){
		case 1:
			strcpy(cadenaPosicion, "Arquero");
			break;
		case 2:
			strcpy(cadenaPosicion, "Defensor");
			break;
		case 3:
			strcpy(cadenaPosicion, "Medio Campista");
			break;
		case 4:
			strcpy(cadenaPosicion, "Delantero");
			break;
		}
	}
	return retorno;
}
/**
 * \fn int darAltaJugador(eJugador[], int, eConfederacion[], int, int)
 * \brief Funcion encargada de rellenar los espacios de los campos de la
 * estructura eJugador.
 *
 * \param jugadores - array de estructuras del tipo eJugador.
 * \param tamJugadores - cantidad de estructuras del tipo eJugador.
 * \param confeder - array de estructuras del tipo eConfederacion.
 * \param tamConf - cantidad de estructuras del tipo eConfederacion.
 * \param idAutomatico - id que se cargara automaticamente en campo id de la estructura
 * eJuagdor, sin necesidad de que el usuario lo ingrese.
 */
int darAltaJugador(eJugador jugadores[], int tamJugadores, eConfederacion confeder[], int tamConf, int idAutomatico){
	int retorno = 0;
	eJugador* pJugador;
	pJugador = jugadores;
	if(jugadores != NULL && tamJugadores > 0){
		for(int i = 0; i < tamJugadores; i++){
			if((*(jugadores + i)).isEmpty == VACIO){
				//INGRESO ID
				(*(jugadores + i)).id = idAutomatico;
				//INGRESO NOMBRE
				getCadena("\nIngresar nombre del jugador: ", (pJugador + i)->nombre, 50);
				fflush(stdin);
				//INGRESO POSICION
				elegirPosicion("\nIngresar NUMERO de posicion: ", (pJugador + i)->posicion, 50);
				//INGRESO NUM CAMISETA
				utn_getShort(&(pJugador + i)->numeroCamiseta, "\nIngresar numero de camiseta: ", "\nError, ingresar numero en rango: ");
				//INGRESO SALARIO
				utn_getFloat(&(pJugador + i)->salario, "\nIngresar salario: ", "\nError, ingresar numero en rango: ", 1,10000000);
				//INGRESO AÑOS DE CONTRATO
				utn_getShort(&(pJugador + i)->aniosContrato, "\nIngresar cantidad de años de contrato: ", "\nError, ingresar de nuevo: ");
				//INGRESO ID CONFEDERACION
				mostrarConfederaciones(confeder, tamConf);
				utn_getNumero(&(pJugador + i)->idConfederacion, "\nIngresar ID de confederacion: ", "\nError, ingrese numero en rango [1-6]: ", 1, 6);
				//CAMBIO ESTADO
				(pJugador + i)->isEmpty = LLENO;
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \fn int darBajaJugador(eJugador[], int, eConfederacion[], int)
 * \brief Funcion encargada de cambiar el estado del campo isEmpty de una estructura
 * eJugador, para devolverle la disponibilidad y asi poder ser reescrito nuevamente.
 *
 * \param jugadores - array de estructuras del tipo eJugador.
 * \param tamJugadores - cantidad de estructuras del tipo eJugador.
 * \param confederaciones - array de estructuras del tipo eConfederacion.
 * \param tamConfe - cantidad de estructuras del tipo eConfederacion.
 */

int darBajaJugador(eJugador jugadores[], int tamJugadores, eConfederacion confederaciones[], int tamConfe){
	int retorno = 0;
	int idAux;
	char confirmar;

	mostrarJugadores(jugadores, tamJugadores, confederaciones,tamConfe);
	utn_getNumero(&idAux, "\nEscribir ID de jugador a eliminar: ", "\nError, el ID no existe", 1, tamJugadores);

	if(jugadores != NULL && tamJugadores > 0){
		for(int i = 0; i < tamJugadores; i++){
			if( jugadores[i].isEmpty == LLENO && jugadores[i].id == idAux){
				confirmacion("\n¿Seguro que desea darlo de baja? [s/n]: ", &confirmar);
		     	if(confirmar == 'S'){
		     		jugadores[i].isEmpty = VACIO;
		     		retorno = 1;
		     		 printf("\n--------- Se dio de baja exitosamente ---------");
		     	} else {
		     		printf("\n--------- Se cancelo el dar de baja ---------");
		     	}
			}
		}
	}
	return retorno;
}
/**
 * \fn int modificarJugador(eJugador[], int, eConfederacion[], int)
 * \brief Funcion encargada de modificar alguno de los campos de
 * la estructura del tipo eJugador.
 *
 * \param jugadores - array de estructuras del tipo eJugador.
 * \param tamJugadores - cantidad de estructuras del tipo eJugador.
 * \param confederaciones - array de estructuras del tipo eConfederacion.
 * \param tamConfe - cantidad de estructuras del tipo eConfederacion.
 */
int modificarJugador(eJugador jugadores[], int tamJugadores, eConfederacion confederaciones[], int tamConfede){
	int retorno = 0;
	int opcionMof;
	int idAux;
	if(jugadores != NULL && tamJugadores > 0){
		mostrarJugadores(jugadores, tamJugadores, confederaciones, tamConfede);
		utn_getNumero(&idAux, "\nIngresar ID de jugador a modificar: ", "\nError, volver a ingresar: ", 1, tamJugadores);
		for(int i = 0; i < tamJugadores; i++){
			if(jugadores[i].id == idAux && jugadores[i].isEmpty == LLENO){
				retorno = 1;
				printf("\nSe encontro el jugador ingresado.");
				printf("\n¿Que desea modificarle?");
				printf("\n1-NOMBRE\n2-POSICION\n3-NUMERO CAMISETA\n4-ID CONFEDERACION\n5-SALARIO\n6-AÑOS CONTRATO");
				utn_getNumero(&opcionMof, "\nIngresar opcion: ", "\nError la opcion no existe: ", 1, 6);
				switch(opcionMof){
				case 1:
					modificarNombre(jugadores[i].nombre);
					break;
				case 2:
					modificarPosicion(jugadores[i].posicion);
					break;
				case 3:
					modificarCamiseta(&jugadores[i].numeroCamiseta);
					break;
				case 4:
					modificarIdConfederacion(&jugadores[i].idConfederacion, confederaciones, tamConfede);
					break;
				case 5:
					modificarSalario(&jugadores[i].salario);
					break;
				case 6:
					modificarContrato(&jugadores[i].aniosContrato);
					break;
				}
			}
		}
	}
	return retorno;
}

/**
 * \fn int modificarNombre(char[])
 * \brief Funcion encargada de modificar el campo nombre del jugador dentro de la estructura
 * del tipo eJugador.
 *
 * \param nombre - campo nombre dentro de la estructura eJugador.
 */

int modificarNombre(char nombre[]){
	int retorno = 1;
	char confirmar;
	char nombreAux[50];

	printf("\nEl nombre del jugador es ---> %s", nombre);
	getCadena("\nIngresar nuevo nombre para el jugador: ", nombreAux, 50);
    confirmacion("\n¿Seguro desea modificarlo? [s/n]: ", &confirmar);

	if(confirmar == 'S'){
		strcpy(nombre, nombreAux);
	} else {
		retorno = 0;
	}
	return retorno;
}

/**
 * \fn int modificarPosicion(char[])
 * \brief Funcion encargada de modificar el campo posicion dentro de la estructura eJugador
 *
 * \param posicion - campo posicion dentro de la estructura eJugador.

 */

int modificarPosicion(char posicion[]){
	int retorno = 1;
	char confirmar;
	char posicionAux[50];
	printf("\nLa posicion actual es ---> %s", posicion);
	elegirPosicion("\nIngresar ID de posicion: ", posicionAux, 50);
	confirmacion("\n¿Seguro desea modificarlo? [s/n]: ", &confirmar);
	if(confirmar == 'S'){
			strcpy(posicion, posicionAux);
		} else {
			retorno = 0;
		}
	return retorno;
}

/**
 *\fn int modificarCamiseta(short*)
 * \brief Funcion encargada de modificar el valor del campo camiseta
 * dentro de la estructura eJugador.
 *
 * \param camiseta - campo numero de camiseta dentro de estructura eJugador.
 */
int modificarCamiseta(short* camiseta) {
	int retorno = 1;
	char confirmar;
	short camisetaAux;
	printf("\nEl numero de camiseta actual es: %i", *camiseta);
	utn_getShort(&camisetaAux, "\nIngresar nuevo numero de camiseta: ", "\nError, ingresar un numero de camiseta: ");
	confirmacion("\n¿Seguro desea modificarlo? [s/n]: ", &confirmar);
	if (confirmar == 'S') {
		*camiseta = camisetaAux;
	} else {
		retorno = 0;
	}
	return retorno;
}

/**
 * \fn int modificarIdConfederacion(int*, eConfederacion[], int)
 * \brief Funcion encargada de modificar campo id confederacion dentro
 * de la estructura eJugador.
 *
 * \param idConfederacion - puntero a variable id, dentro de la estructura
 * eJugador.
 * \param confederaciones - array de estructuras del tipo eConfederacion.
 * \param tamConfe - cantidad de elementos dentro del array de estructuras
 * eConfederacion.
 */

int modificarIdConfederacion(int* idConfederacion, eConfederacion confederaciones[], int tamConfe){
	int retorno = 1;
	char confirmar;
	int idConfederacionAux;
	printf("\nEl numero de ID actual es: %i", *idConfederacion);
	mostrarConfederaciones(confederaciones, tamConfe);
	utn_getNumero(&idConfederacionAux, "\nIngresar nuevo ID de Confederacion: ", "\nError, ingresar en rango [1-6]: ", 1, 6);
	confirmacion("\n¿Seguro desea modificarlo? [s/n]: ", &confirmar);
		if (confirmar == 'S') {
			printf("\nEl ID ingresado es %i", idConfederacionAux);
			*idConfederacion = idConfederacionAux;
		} else {
			retorno = 0;
		}
		return retorno;

}

/**
 * \fn int modificarSalario(float*)
 * \brief Funcion encargada de modificar el campo salario dentro
 * del array de estructuras eJugador.
 *
 * \param salario - campo salario dentro
 * del array de estructuras eJugador.

 */
int modificarSalario(float* salario){
	int retorno = 1;
	char confirmar;
	float salarioAux;
	printf("\nEl salario actual es: %f", *salario);
	utn_getFloat(&salarioAux, "\nIngresar nuevo salario: ", "\nError, tiene que ser mayor a 0 y minimo a 1 millon: ", 1, 1000000);
	confirmacion("\n¿Seguro desea modificarlo? [s/n]: ", &confirmar);
	if (confirmar == 'S') {
		*salario = salarioAux;
	} else {
		retorno = 0;
	}
	return retorno;
}
/**
 * \fn int modificarContrato(short*)
 * \brief Funcion encargada de modificar el campo años de contrato dentro
 * del array de estructuras eJugador.
 *
 * \param contrato - campo años de contrato dentro
 * del array de estructuras eJugador.

 */

int modificarContrato(short* contrato) {
	int retorno = 1;
	char confirmar;
	short contratoAux;
	printf("\nLa duracion del contrato es de %i años", *contrato);
	utn_getShort(&contratoAux, "\nIngresar nueva cantidad de años: ", "\nError, ingresar numero de cantidad de años: ");
	confirmacion("\n¿Seguro desea modificarlo? [s/n]: ", &confirmar);
	if (confirmar == 'S') {
		*contrato = contratoAux;
	} else {
		retorno = 0;
	}
	return retorno;
}
















