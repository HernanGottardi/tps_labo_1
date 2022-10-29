/*
 * confederacion.c
 *
 *  Created on: 17 oct. 2022
 *      Author: herni
 */

#include <stdio.h>
#include <stdlib.h>

#include "confederacion.h"
#include "jugadores.h"
#include "outputs.h"
#include "inputs.h"

#define VACIO 0
#define LLENO 1
/**
 * \fn void harcodearConfederacion(eConfederacion[], int)
 * \brief Funcion encargada de guardar datos automaticamente dentro de la estructura eConfederacion.
 *
 * \param confederaciones - Array de estructuras del tipo eConfederacion, a las que se le asignaran datos.
 * \param tamConfe - cantidad de elementos que compone a dicho array de estructuras.
 */

void harcodearConfederacion (eConfederacion confederaciones[], int tamConfe){
	eConfederacion auxConfe[] = {
			{1, "CONMEBOL", "SUDAMERICA", 1916, 1},
			{2, "UEFA", "EUROPA", 1954, 1},
			{3, "AFC", "ASIA", 1954, 1},
			{4, "CAF", "AFRICA", 1957, 1},
			{5, "CONCACAF", "NORTE/CENTRO AMERICA", 1961, 1},
			{6, "OFC", "OCEANIA", 1966, 1}
	};
	for(int i = 0; i < tamConfe; i++){
		confederaciones[i] = auxConfe[i];
	}
}

/**
 * \fn int inicializarConfederaciones(eConfederacion[], int)
 * \brief Funcion encargada de establecer un valor inicial para el estado de los elementos del array de estructuras
 * eConfederacion. El valor sera 0.
 *
 * \param confederaciones - Array de estructuras del tipo eConfederacion, a las que se les pondra un valor inicial.
 * \param tamConfe - cantidad de elementos que compone a dicho array de estructuras.
 */

int inicializarConfederaciones(eConfederacion confederaciones[], int tamConfe){
	int retorno = 0;
	if(confederaciones != NULL && tamConfe > 0){
		for(int i = 0; i < tamConfe; i++){
			confederaciones[i].isEmpty = VACIO;
		}
		retorno = 1;
	}
	return retorno;
}

/**
 * \fn int abmConfederacion(eConfederacion[], int, int*, int*)
 * \brief Funcion encargada de preguntarle al usuario que opcion desea elegir. Alta, baja o
 * modificacion, segun responda llama a su funcion correspondiente.
 *

 * \param confederaciones Array de estructuras del tipo eConfederacion.
 * \param tamConfe - Tamaño del array de estructuras mencionado.
 * \param idAutomatico  - id predefinido para asignar al campo id de la estructura confederacion, usado en la opcion alta.
 * \param contador - Este contador aumentara en 1 o disminuira 1 unidad, si se da de alta o de baja, respectivamente.
 */

int abmConfederacion(eConfederacion confederaciones[], int tamConfe, int* idAutomatico, int*contador){
	int retorno = 0;
	if(confederaciones != NULL && tamConfe > 0){
		retorno = 1;
		int opcion;
		do{
			printf("\nLISTA DE OPCIONES:");
			printf("\n1- ALTA confederacion.\n2- BAJA Confederacion.\n3- MODIFICAR Confederacion.\n4- SALIR.");
			utn_getNumero(&opcion, "\nIngresar opcion: ", "\nError, ingresar en rango [1-4]: ", 1, 4);
			switch(opcion){
			case 1:
				if(*contador < 6){
					if(altaConfederacion(confederaciones, tamConfe, *idAutomatico) == 1){
						*contador = *contador + 1;
						*idAutomatico = *idAutomatico + 1;
					}
				}
				break;
			case 2:
				if(*contador > 0){
					mostrarConfederaciones(confederaciones,tamConfe);
					if(bajaConfederacion(confederaciones, tamConfe) == 1){
						*contador = *contador - 1;
					}
				}
				break;
			case 3:
				if(*contador > 0){
					modificarConfederacion(confederaciones, tamConfe);
				}
				break;
			case 4:
				break;
			}
		}while(opcion != 4);
	}
	return retorno;
}

/**
 * \fn int elegirConfederacion(char[], char[], char[], int, int, int*)
 * \brief Funcion encargada de pedirle al usuario los valores correspondiente para los campos de la estructura confederacion
 * y asignarselos.
 *
 * \param mensaje - cadena de texto que se va a imprimir en pantalla, orientando al usuario sobre lo que debe ingresar.
 * \param cadenaNombre - campo nombre de confederacion de la estructura eConfederacion.
 * \param cadenaRegion - campo region de confederacion de la estructura eConfederacion.
 * \param tamNombre - cantidad de caracteres aceptados en el campo nombre.
 * \param tamRegion - cantidad de caracteres aceptados en el campo region.
 * \param anio - campo anio de creacion de la estructura eConfederacion.
 */

int elegirConfederacion (char mensaje[], char cadenaNombre[], char cadenaRegion[], int tamNombre, int tamRegion, int* anio){
	int retorno = 0;
	int opcionPosicion;

	if(cadenaNombre != NULL && cadenaRegion != NULL && tamNombre > 0 && tamRegion > 0){
		retorno = 1;
		printf("\n---------------------------");
		printf("\nLista de Confederaciones: ");
		printf("\n1- CONMEBOL\n2- UEFA\n3- AFC\n4- CAF\n5- CONCACAF \n6- OFC\n7- OTRA");
		printf("\n---------------------------");
		utn_getNumero(&opcionPosicion, mensaje, "\nError, elegir numero en rango [1-7]: ", 1, 7);

		switch(opcionPosicion){
		case 1:
			strcpy(cadenaNombre, "CONMEBOL");
			strcpy(cadenaRegion, "SUDAMERICA");
			*anio = 1916;
			break;
		case 2:
			strcpy(cadenaNombre, "UEFA");
			strcpy(cadenaRegion, "EUROPA");
			*anio = 1954;
			break;
		case 3:
			strcpy(cadenaNombre, "AFC");
			strcpy(cadenaRegion, "ASIA");
			*anio = 1954;
			break;
		case 4:
			strcpy(cadenaNombre, "CAF");
			strcpy(cadenaRegion, "AFRICA");
			*anio = 1957;
			break;
		case 5:
			strcpy(cadenaNombre, "CONCACAF");
			strcpy(cadenaRegion, "NORTE/CENTRO AMERICA");
			*anio = 1961;
			break;
		case 6:
			strcpy(cadenaNombre, "OFC");
			strcpy(cadenaRegion, "OCEANIA");
			*anio = 1966;
			break;
		case 7:
			getCadena("\nIngresar nombre de la confederacion: ", cadenaNombre, tamNombre);
			getCadena("\ningresar region de la Confederacion: ", cadenaRegion, tamRegion);
			utn_getNumero(anio, "\nIngresar año de creacion: ", "\nError, ingresar en rango [1 - 2022]: ", 1, 2022);
			break;
		}
	}
	return retorno;
}

/**
 * \fn int altaConfederacion(eConfederacion[], int, int)
 * \brief Funcion encargada de cargar un nuevo elemento confederacion dentro del array de estructuras eConfederacion.
 *
 * \param confederaciones - array de estructuras del tipo eConfederacion.
 * \param tamConfe - tam del array de estructuras del tipo eConfederacion.
 * \param idAutomatico - este id predefinido se le asignara automaticamente al campo ID dentro de la estructura,
 * sin que el usuario lo ingrese con sus propias manos.
 */

int altaConfederacion(eConfederacion confederaciones[], int tamConfe, int idAutomatico){
	int retorno = 0;
	if (confederaciones != NULL && tamConfe > 0) {
		for (int i = 0; i < tamConfe; i++) {
			if (confederaciones[i].isEmpty == VACIO) {
				confederaciones[i].id = idAutomatico;
				elegirConfederacion("\nElegir confederacion: ", confederaciones[i].nombre, confederaciones[i].region, 50, 50, &confederaciones[i].anioCreacion);
				confederaciones[i].isEmpty = LLENO;
				retorno = 1;
				break;
			}
		}

	}
	return retorno;
}

/**
 * \fn int bajaConfederacion(eConfederacion[], int)
 * \brief Funcion encargada de cambiar el estado de una estructura del array de estructuras
 * del tipo eConfederacion, con el fin de liberar el espacio.
 *
 * \param confederacion - array de estructuras del tipo eConfederaciones.
 * \param tamConfe - tamaño del array de estructuras del tipo eConfederaciones.

 */

int bajaConfederacion(eConfederacion confederacion[], int tamConfe){
	int retorno = 0;
	int idAux;
	char confirmar;

	if(confederacion != NULL && tamConfe > 0){
		utn_getNumero(&idAux, "\ningresar ID de confederacion a dar de baja: ", "\nError, ingresar en rango [1-6]: ", 1, 6);
		for(int i = 0; i < tamConfe; i++){
			if(confederacion[i].isEmpty == LLENO && confederacion[i].id == idAux){
				 confirmacion("\n¿Seguro que desea darlo de baja? [s/n]: ", &confirmar);
				 fflush(stdin);
				 if(confirmar == 'S'){
					 confederacion[i].isEmpty = VACIO;
					retorno = 1;
					 printf("\n--------- Se borro exitosamente ---------");
				 } else {
					 printf("\n--------- Se cancelo la baja ---------");

				 }
			}
		}
	}
	if(retorno == 0){
		printf("\nEl ID ingresado no existe.");
	}
	return retorno;
}

/**
 * \fn int modificarConfederacion(eConfederacion[], int)
 * \brief Funcion encargada de modificar los campos de la estructura eConfederacion. Haciendo elegir al usuario
 * la opcion a modificar, es decir cual campo.
 *
 * \param confederaciones - array de estructuras del tipo eConfederacion.
 * \param tamConfe - tamaño array de estructuras del tipo eConfederacion.

 */

int modificarConfederacion(eConfederacion confederaciones[], int tamConfe){
	int retorno = 0;
	int idAux;
	int opcion;

	if(confederaciones != NULL && tamConfe > 0){
		mostrarConfederaciones(confederaciones, tamConfe);
		utn_getNumero(&idAux, "\nIngresar ID a modificar: ", "\nError, ingresar ID en rango [1-6]", 1, 6);
		for(int i = 0; i < tamConfe; i++){
			if(confederaciones[i].isEmpty == LLENO && confederaciones[i].id == idAux){
				printf("\nQUE DESEA MODIFICAR: ");
				printf("\n1-NOMBRE\n2-REGION\n3-AÑO CREACION");
				utn_getNumero(&opcion, "\nIngresar opcion: ", "\nError ingresar en rango [1-3]", 1, 3);
				switch(opcion){
				case 1:
					modificarNombreConfederacion(confederaciones, tamConfe, idAux);
					break;
				case 2:
					modificarRegionConfederacion(confederaciones, tamConfe, idAux);
					break;
				case 3:
					modificarAnioCreacion(confederaciones, tamConfe, idAux);
					break;
				}
			}
		}
	}
	return retorno;
}

/**
 * \fn int modificarNombreConfederacion(eConfederacion[], int, int)
 * \brief Funcion encargada de modificar el campo nombre de la estructura eConfederacion.
 *
 * \param confederaciones - array de estructuras del tipo eConfederacion.
 * \param tamConfederaciones - tamaño array de estructuras del tipo eConfederacion.
 * \param idElegido - este es el id elegido por el usuario, para definir cual es la confederacion a modificar
 */

int modificarNombreConfederacion(eConfederacion confederaciones[], int tamConfederaciones, int idElegido){
	int retorno = 0;
	char cadenaNombreAux[50];
	char confirmar;
	if(confederaciones != NULL && tamConfederaciones > 0){
		for(int i = 0; i < tamConfederaciones; i++){
			if(confederaciones[i].id == idElegido){
				printf("\nEl nombre actual es: %s", confederaciones[i].nombre);
				getCadena("\nIngresar nuevo nombre de confederacion: ", cadenaNombreAux, 50);
				confirmacion("\n¿Seguro desea modificarlo? [s/n]: ", &confirmar);
				fflush(stdin);
				if(confirmar == 'S'){
					strcpy(confederaciones[i].nombre, cadenaNombreAux);
					retorno = 1;
				}
			}
		}
	}
	return retorno;
}

/**
 * \fn int modificarRegionConfederacion(eConfederacion confederaciones[], int tamConfederaciones, int idElegido)
 * \brief Funcion encargada de modificar el campo region de la estructura eConfederacion.
 *
 * \param confederaciones - array de estructuras del tipo eConfederacion.
 * \param tamConfederaciones - tamaño array de estructuras del tipo eConfederacion.
 * \param idElegido - este es el id elegido por el usuario, para definir cual es la confederacion a modificar
 */

int modificarRegionConfederacion(eConfederacion confederaciones[], int tamConfederaciones, int idElegido){
	int retorno = 0;
	char cadenaRegionAux[50];
	char confirmar;
	if(confederaciones != NULL && tamConfederaciones > 0){
		for (int i = 0; i < tamConfederaciones; i++) {
			if (confederaciones[i].id == idElegido) {
				printf("\nLa regiona actual es: %s", confederaciones[i].region);
				getCadena("\nIngresar nueva region para confederacion: ", cadenaRegionAux, 50);
				confirmacion("\n¿Seguro desea modificarlo? [s/n]: ", &confirmar);
				fflush(stdin);
				if (confirmar == 'S') {
					strcpy(confederaciones[i].region, cadenaRegionAux);
					retorno = 1;
				}
			}
		}
	}
	return retorno;
}

/**
 * \fn int modificarAnioCreacion(eConfederacion confederaciones[], int tamConfederaciones, int idElegido)
 * \brief Funcion encargada de modificar el campo anio de creacion de la estructura eConfederacion.
 *
 * \param confederaciones - array de estructuras del tipo eConfederacion.
 * \param tamConfederaciones - tamaño array de estructuras del tipo eConfederacion.
 * \param idElegido - este es el id elegido por el usuario, para definir cual es la confederacion a modificar
 */

int modificarAnioCreacion(eConfederacion confederaciones[], int tamConfederaciones, int idElegido){
	int retorno = 0;
	int anioAux;
	char confirmar;
	if (confederaciones != NULL && tamConfederaciones > 0) {
		for (int i = 0; i < tamConfederaciones; i++) {
			if (confederaciones[i].id == idElegido) {
				printf("\nEl año de creacion actual es: %i", confederaciones[i].anioCreacion);
				utn_getNumero(&anioAux, "\nIngresar nuevo año de creacion: ",
						"\nError, ingresar en rango [1-2022]: ",1, 2022);
				confirmacion("\n¿Seguro desea modificarlo? [s/n]: ", &confirmar);
				fflush(stdin);
				if (confirmar == 'S') {
					confederaciones[i].anioCreacion = anioAux;
					retorno = 1;
				}
			}
		}
	}
	return retorno;
}



