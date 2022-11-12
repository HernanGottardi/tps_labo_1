#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */

int parser_JugadorFromText(FILE *pFile, LinkedList *pArrayListJugador) {

	int retorno = 0;
	Jugador *pJugadorcitoAux;
	int retornolectura;

	char id[5];
	char nombreCompleto[40];
	char edad[10];
	char posicion[30];
	char nacionalidad[30];
	char idSeleccion[5];

	char cabecera[1000];

	if (pFile != NULL && pArrayListJugador != NULL) {
		// lectura fantasma
		fgets(cabecera, 1000, pFile);
		while (!feof(pFile)) {
			retornolectura = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,
					nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
			if (retornolectura == 6) {
				pJugadorcitoAux = jug_newParametros(id, nombreCompleto, edad,
						posicion, nacionalidad, idSeleccion);
				ll_add(pArrayListJugador, pJugadorcitoAux);
				retorno = 1;
			}
		}
	}
	return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */


int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
    int retorno = 0;
    Jugador* pAuxJugador;

    if(pArrayListJugador != NULL){
    	while(!feof(pFile)){
    		// reservo memoria dinamica para el jugador.
    		pAuxJugador = jug_new();
    		if(pAuxJugador != NULL){
    			// leo un jugador del archivo binario y se lo asigno a pAuxJugador.
    			fread(pAuxJugador, sizeof(Jugador), 1, pFile);
    			if(feof(pFile))
    			{
    				break;
    			}
    			// Guardo en el auxiliarJugador a la LinkedList.
    			ll_add(pArrayListJugador, pAuxJugador);
    			retorno = 1;
    		}
    	}
    }
    return retorno;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */

int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	Seleccion* pAuxSeleccion;
	int retorno = 0;
	int cantidadLeida;

	char cabecera[1000];
	char id[5];
	char pais[25];
	char confederacion[15];
	char convocados[2];
	if(pFile != NULL && pArrayListSeleccion != NULL){
		fgets(cabecera, 1000, pFile);
		while(!feof(pFile)){
			cantidadLeida = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, pais, confederacion, convocados);
			if(cantidadLeida == 4){
				pAuxSeleccion = selec_newParametros(id, pais, confederacion, convocados);
			    ll_add(pArrayListSeleccion, pAuxSeleccion);
			    retorno = 1;
			}
		}
	}
    return retorno;
}

