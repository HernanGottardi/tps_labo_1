/*
 * inputs.c
 *
 *  Created on: 17 oct. 2022
 *      Author: herni
 */

#include "inputs.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * \fn int confirmacion(char[], char*)
 * \brief Funcion encargada de validar que la respuesta del tipo char sea S o N. Con el fin de usarla
 * para que el usuario decida si quiere realizar una maniobra o no.
 *
 * \param comentario - este parametro sera una cadena de texto, con el proposito de orientar al usuario en la eleccion.
 * \param confirmacion - puntero donde se guardara la decision tomada por el usario.
 */

int confirmacion(char comentario[], char* confirmacion) {
	int retorno = 0;
	char auxConfirmacion;
	do {
		printf(comentario);
		fflush(stdin);
		scanf("%c", &auxConfirmacion);
		auxConfirmacion = toupper(auxConfirmacion);
	} while (auxConfirmacion != 'S' && auxConfirmacion != 'N');

	if(auxConfirmacion == 'S' || auxConfirmacion == 'N'){
		retorno = 1;
		*confirmacion = auxConfirmacion;
	}
	return retorno;
}

// ------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------

/**
 * \fn int utn_getCaracter(char*, char*, char*, char, char)
 * \brief Funcion encargada de pedir, validar y guardar un caracter en el puntero pasado como parametro.
 *
 * \param pResultado - Puntero a variable de tipo char.
 * \param mensaje - Cadena de caracteres que se imprimira en pantalla para ayudar al usuario a saber que ingresar.
 * \param mensajeError - Cadena de caracteres que se imprimira en pantalla para notificar al usuario
 *  que hubo un error con la informacion que ingreso, pidiendole que vuelva a intentar.
 * \param minimo - valor minimo permitido a ingresar por el usario.
 * \param maximo - valor maximo permitido a ingresar por el usario.
 */

int utn_getCaracter(char *pResultado, char *mensaje, char *mensajeError,
char minimo, char maximo) {

	int retorno = 0;
	char buffer;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo) {
		do {
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &buffer);

			if (buffer >= minimo && buffer <= maximo) {
				*pResultado = buffer;
				retorno = 1;
				break;
			}
			printf("%s", mensajeError);
		} while (retorno != 0);

	}
	return retorno;
}

// ------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------

/**
 * \fn int esNumerica(char*)
 * \brief funcion encargada de validar que los caracteres ingresados por el usario esten en el rango 0 y 9 del codigo ascci.
 *
 * \param cadena - cadena de caracteres ingresada por el usuario.
 */

int esNumerica(char *cadena) {
	int retorno = 1;
	int i = 0;

	if (cadena != NULL && strlen(cadena) > 0) {
		while(cadena[i] < '0' || cadena[i] > '9'){
			retorno = 0;
			break;
		}
		i++;
	}
	return retorno;
}
//----------------------------------------------------------------
/**
 * \fn int myGets(char*, int)
 * \brief Funcion encargada de pedirle al usuario una cadena de caracteres numerica, cambiando
 * el valor de la ultima posicion por \0.
 *
 * \param cadena - puntero a cadena de caracteres que se vera sometida a esta modificacion.
 * \param longitud - cantidad de caracteres de la cadena de caracteres.

 */
int myGets(char *cadena, int longitud) {

	if(cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena){
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n'){
			cadena[strlen(cadena)-1] = '\0';
		}
		return 1;
	}
	return 0;
}
//----------------------------------------------------------------
/**
 * \fn int getInt(int*)
 * \brief Funcion encargada de pedir al usuario una cadena de caracteres y validar que sea numerica,
 * para posteriormente parsearla a tipo entera.
 *
 * \param pResultado - puntero a variable del tipo entera, donde se alojara este numero entero.
 */
int getInt(int *pResultado) {
	int retorno = 0;
	char buffer[64];

	if(pResultado != NULL){
		if (myGets(buffer, sizeof(buffer)) && esNumerica(buffer)) {
			*pResultado = atoi(buffer);
			retorno = 1;
		}
	}
	return retorno;
}
// ---------------------------------------------------------------
/**
 * \fn int utn_getNumero(int*, char*, char*, int, int)
 * \brief funcion encargada de solicitar al usuario un numero entero y validarlo.
 *
 * \param pResultado - puntero a variable del tipo int, donde se guardara el numero ingresado por el usuario.
 * \param mensaje - Cadena de texto que se encargara de imprimir en pantalla detallando lo que debe ingresar el usuario.
 * \param mensajeError - Cadena de texto que se encargara de notificarle al usuario que se equivoco y que debe volverlo a intentar.
 * \param minimo - Valor minimo permitido a ingresar por el usuario.
 * \param maximo - Valor maximo permitido a ingresar por el usuario.
 */

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo) {
	int retorno = 0;
	int buffer;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo) {
		do {
			printf("%s", mensaje);
			if (getInt(&buffer) == 1 && buffer <= maximo && buffer >= minimo) {
				*pResultado = buffer;
				retorno = 1;
				break;
			}
			printf("%s", mensajeError);

		} while (retorno != 1);

	}
	return retorno;
}
// ------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------
/**
 * \fn int esFlotante(char*)
 * \brief Funcion encargada de verificar que la cadena de caracteres ingresada pertenezca al rango nuemerico,
 * permitiendo el ingreso de puntos.
 *
 * \param cadena - cadena de caracteres ingresada por el usuario.
 */

int esFlotante(char *cadena) {
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {

		for (int i = 0; i < strlen(cadena); i++) {
			if (cadena[i] < '0' || cadena[i] > '9') {
				if (cadena[i] != '.') {
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}
// ---------------------------------------------------------------
/**
 * \fn int getFloat(float*)
 * \brief Funcion encargada de obtener una cadena de caracteres por parte del usuario y validar que sea del tipo numerica flotante,
 * para posteriormente convertir esa cadena de caracteres a tipo flotante.
 *
 * \param pResultado

 */
int getFloat(float *pResultado) {
	int retorno = 0;
	char buffer[64];

	if(pResultado != NULL){
		if (myGets(buffer, sizeof(buffer)) == 1 && esFlotante(buffer) == 1) {
			*pResultado = atof(buffer);
			retorno = 1;
		}
	}
	return retorno;
}

// ---------------------------------------------------------------
/**
 * \fn int utn_getFloat(float*, char*, char*, int, int)
 * \brief Funcion encargada de pedirle al usuario que ingrese un numero flotante. Validando que sea correcto.
 *
 * \param pResultado - puntero a variable del tipo flotante.
 * \param mensaje - Cadena de texto que se encargara de imprimir en pantalla detallando lo que debe ingresar el usuario.
 * \param mensajeError - Cadena de texto que se le notifica al usuario que se equivoco y que debe volver a intentarlo.
 * \param minimo - minimo valor del tipo flotante aceptado.
 * \param maximo - maximo valor del tipo flotante aceptado.

 */
 int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo) {
	int retorno = 0;
	float bufferFloat;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo) {
		do {
			printf("%s", mensaje);
			if (getFloat(&bufferFloat) == 1) {
				if (bufferFloat <= maximo && bufferFloat >= minimo) {
					*pResultado = bufferFloat;
					retorno = 1;
					break;

				}
			}
			printf("%s", mensajeError);

		} while (retorno != 1);
	}
	return retorno;
}



// ------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------

 /**
   * \fn int getCadena(char[], char[], int)
  * \brief Funcion encargada de pedirle al usuario una cadena de caracteres. Convirtiendo las iniciales en mayusculas.
  * permitiendo solamente letras y espacios.
  *
  * \param mensaje - Cadena de texto que se encargara de imprimir en pantalla detallando lo que debe ingresar el usuario.
  * \param cadena - Cadena de caracteres donde guardara la cadena de caracteres ingresada por el usuario.
  * \param tamCadena - cantidad de caracteres conformados en la cadena ingresada como parametro.
  */
int getCadena(char mensaje[], char cadena[], int tamCadena){
	int retorno = 0;
	char buffer[1024];
	if (tamCadena > 0 && cadena != NULL) {
		do{
			printf(mensaje);
			fflush(stdin);
			scanf("%[^\n]", buffer);
			if (strlen(buffer) < tamCadena) {
				if (sonLetrasEspacios(buffer, strlen(buffer)) == 1) {
					if (cantCaracteresDistintosAEspacio(buffer, strlen(buffer))!= 0) {
						retorno = 1;
						convertirInicialesEnMayusculas(buffer, tamCadena);
						strcpy(cadena, buffer);
						break;
					} else{
						printf("\nERROR, no se ingresaron caracteres.\n");
					}
				} else {
					printf("\nERROR, no se aceptan caracteres especiales o numericos.\n");
				}
			} else {
				printf("\nERROR, El texto ingresado supera la cantidad maxima de caracteres.\n");
			}
		} while (retorno != 1);
	}
	return retorno;
}
//--------------------------------------------------------------------
/**
 * \fn int sonLetrasEspacios(char[], int)
 * \brief Funcion encargada de validar que la cadena ingresada por parametro este conformada solamente
 * por espacios o letras.
 *
 * \param cadena - cadena de caracteres sometida a validacion.
 * \param tamCadena - cantidad de caracteres que tiene dicha cadena de caracteres.

 */
int sonLetrasEspacios(char cadena[], int tamCadena){
	int retorno = 1;
	if(cadena != NULL && tamCadena > 0){
		strlwr(cadena);
		for(int i = 0; i < tamCadena ;i++){
			if(cadena[i] < 'a' || cadena[i] > 'z'){
				retorno = 0;
				if(cadena[i] == ' '){
					retorno = 1;
				}
			}
		}
	}
	return retorno;
}
/**
 * \fn int cantCaracteresDistintosAEspacio(char[], int)
 * \brief Funcion encargada de recibir una cadena de texto por parametro ingresada previamente por el usuario con el fin de
 * comprobar si la cantidad de caracteres aceptados es mayor a 0. Devolviendo la cantidad de los mismos.
 *
 * \param cadena - Cadena de texto.
 * \param tamCadena - Tamano de la cadena de texto.
 */

int cantCaracteresDistintosAEspacio(char cadena[], int tamCadena) {
	int cantidad = 0;
	if (cadena != NULL && tamCadena > 0) {
		strlwr(cadena);
		for (int i = 0; i < tamCadena; i++) {
			if (cadena[i] >= 'a' && cadena[i] <= 'z') {
				cantidad++;
			}
		}
	}
	return cantidad;
}
//--------------------------------------------------------------------
/**
 * \fn int convertirInicialesEnMayusculas(char[], int)
 * \brief Funcion encargada de convertir iniciales en mayusculas, de una cadena de caracteres.
 *
 * \param cadena - cadena de caracteres.
 * \param tamCadena - cantidad de caracteres de dicha cadena de caracteres.
 */
int convertirInicialesEnMayusculas(char cadena[], int tamCadena) {
	int retorno = 0;
	if (cadena != NULL && tamCadena > 0) {
		retorno = 1;
		cadena[0] = toupper(cadena[0]);
		for (int i = 0; i < tamCadena; i++) {
			if (cadena[i] == ' ') {
				cadena[i + 1] = toupper(cadena[i + 1]);
			}
		}

	}
	return retorno;
}

// ------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------
/**
 * \fn int utn_getShort(short*, char*, char*)
 * \brief Funcion encargada de pedir, validar y guardar una variable del tipo short.
 *
 * \param pResultado - puntero a variable del tipo short encargada de guardar el numero short ingresado por usuario.
 * \param mensaje - Cadena de texto que se encargara de imprimir en pantalla detallando lo que debe ingresar el usuario.
 * \param mensajeError - Cadena de texto que le notificara al usuario lo que hizo mal.

 */

int utn_getShort(short *pResultado, char *mensaje, char *mensajeError) {
	int retorno = 0;
	short buffer;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL) {

		do {
			printf("%s", mensaje);
			if (getShort(&buffer) == 1 && buffer > 0) {
				*pResultado = buffer;
				retorno = 1;
				break;
			}
			printf("%s", mensajeError);

		} while (retorno != 1);

	}
	return retorno;
}
//--------------------------------------------------------------------
/**
 * \fn int getShort(short*)
 * \brief Funcion encargada de pedir y validar que el numero ingresado por el usuario sea del tipo numerico.
 * Si esto se cumple lo guarda en la variable pasada como paramtro. Primero convirtiendolo en entero.
 *
 * \param pResultado - puntero a variable del tipo short, que tiene como proposito almacenar el numero short.
 */
int getShort(short *pResultado) {
	int retorno = 0;
	char buffer[64];

	if(pResultado != NULL){
		if (myGets(buffer, sizeof(buffer)) == 1 && esNumerica(buffer)) {
			*pResultado = atoi(buffer);
			retorno = 1;
		}
	}
	return retorno;
}

//--------------------------------------------------------------------

int menuPrincipal(){
	int opcionPrincipal;
	printf("\nLista de opciones:");
	printf("\n1- Dar de ALTA");
	printf("\n2- Dar de BAJA");
	printf("\n3- MODIFICAR");
	printf("\n4- INFORMAR");
	printf("\n5- ABM-Confederacion");
	printf("\n6- SALIR");
	//fflush(stdin);
	utn_getNumero(&opcionPrincipal, "\nIngresar opcion: ", "\nError, ingresar numero en rango [1-6]", 1, 6);
	return opcionPrincipal;
}

int menuModificarJugador() {
	int opcionRetorno;
	printf("\nSe encontro el jugador ingresado.");
	printf("\n¿Que desea modificarle?");
	printf("\n1-NOMBRE\n2-POSICION\n3-NUMERO CAMISETA\n4-ID CONFEDERACION\n5-SALARIO\n6-AÑOS CONTRATO");
	utn_getNumero(&opcionRetorno, "\nIngresar opcion: ","\nError la opcion no existe: ", 1, 6);
	return opcionRetorno;
}

int menuInformes() {
	int opcionRetorno;
	printf("\nLISTA DE COSAS A INFORMAR: ");
	printf("\n1- Lista de jugadores ordenada\n2- Lista de confederaciones y sus jugadores.");
	printf("\n3- Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio.");
	printf("\n4- Informar la confederación con mayor cantidad de años de contratos total.");
	printf("\n5- Informar porcentaje de jugadores por cada confederación.");
	printf("\n6- Informar cual es la región con más jugadores y el listado de los mismos.");
	utn_getNumero(&opcionRetorno, "\nIngresar opcion de informe: ", "\nError, vuelva a intenar en el rango [1-6]", 1, 6);
	return opcionRetorno;
}


