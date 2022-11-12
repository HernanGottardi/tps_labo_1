#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "parser.h"
#include "inputs.h"
#include "LinkedList.h"
#include "Seleccion.h"
#include "outputs.h"


/**
 * \fn int controller_cargarJugadoresDesdeTexto(char*, LinkedList*)
 * \brief Funcion encargada de abrir el nombre de archivo pasado como primer parametro en modo lectura,
 * extrayendo toda la informacion y guardandola en la linkedList pasada como segundo parametro.
 *
 * \param path - cadena de caracteres, nombre de archivo.
 * \param pArrayListJugador - LinkedList, guarda estructuras Jugadores.
 * \return
 */

int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 0;

	FILE * pArchivoJugadores;
	pArchivoJugadores = fopen(path, "r");

	if(pArchivoJugadores != NULL){
		printf("\nCargando jugadores desde archivo de txt...\n");
		parser_JugadorFromText(pArchivoJugadores, pArrayListJugador);
		fclose(pArchivoJugadores);
		retorno = 1;
	} else {
		printf("\nEl archivo de texto no pudo ser abierto.");
	}

    return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 0;
	FILE* pFile = fopen(path, "rb");
	if(pFile != NULL){
		printf("\nCargando desde archivo binario ...");
		parser_JugadorFromBinary(pFile, pArrayListJugador);
		fclose(pFile);
		retorno = 1;
	} else {
		printf("\nError, no se pudo abrir el archivo binario.");
	}
    return retorno;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int retorno = 0;
	if (pArrayListJugador != NULL) {
		// pedimos lugar en memoria dinamica para un jugador.
		Jugador *nuevoJugador = jug_new();
		// pedimos datos y lo cargamos en el nuevo jugador.
		pedirDatosJugador(nuevoJugador);
		// agregamos la estructura en memoria dinamica a la linked list
		ll_add(pArrayListJugador, nuevoJugador);
		retorno = 1;
	}
    return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int retorno = 0;
	int idElegido;
	if (pArrayListJugador != NULL) {
		retorno = 1;
		// Primero muestro a los jugadores llamando a la funcion listar jugadores en el main.
		utn_getNumero(&idElegido, "\nIngresar ID de jugador a modificar: "
				, "\nError, ingresar ID en rango [1 - 1500]", 1, 1500);
		switch (menuEditar()) {
		case 1:
			modificarNombre(pArrayListJugador, idElegido);
			break;
		case 2:
			modificarEdad(pArrayListJugador, idElegido);
			break;
		case 3:
			modificarPosicion(pArrayListJugador, idElegido);
			break;
		case 4:
			modificarNacionalidad(pArrayListJugador, idElegido);
			break;
		}
	}
	return retorno;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 0;

	Jugador * jugadorAux;
	int idSeleccion;
	int indexJug = pedirIndexBaja(pArrayListJugador, pArrayListSeleccion);

	Seleccion * selecAux;
	int indexSelec;
	int convocados;

	if (indexJug != -1) {
		jugadorAux = (Jugador*) ll_get(pArrayListJugador, indexJug);
		jug_getSIdSeleccion(jugadorAux, &idSeleccion);

		indexSelec = obtenerIndexSeleccionConID(pArrayListSeleccion, idSeleccion);
		selecAux = (Seleccion*) ll_get(pArrayListSeleccion, indexSelec);
		selec_getConvocados(selecAux, &convocados);
		convocados--;
		selec_setConvocados(selecAux, convocados);

		ll_remove(pArrayListJugador, indexJug);
		retorno = 1;
	}
	return retorno;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion) {
	int retorno = 0;
	Jugador *jugAux;
	int cantidadJugadores = ll_len(pArrayListJugador);
	printf("\n------------------------------------------------------------------------------------------------------------------");
	printf("\n%5s %25s %10s %30s %20s %15s", "ID", "NOMBRE COMPLETO", "EDAD", "POSICION", "NACION", "ID SELECCION");
	printf("\n------------------------------------------------------------------------------------------------------------------");
	if (pArrayListJugador != NULL && cantidadJugadores > 0) {
		retorno = 1;
		for (int i = 0; i < cantidadJugadores; i++) {
			jugAux = (Jugador*) ll_get(pArrayListJugador, i);
			mostrar_unJugador(jugAux, pArrayListSeleccion);
		}
	}
	return retorno;
}


/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
	int retorno = 0;
	if(pArrayListJugador != NULL){
		switch(menuOrdenar()){
		case 1:
			ll_sort(pArrayListJugador, compararJugador_Nacionalidad, 1);
			break;
		case 2:
			ll_sort(pArrayListJugador, compararJugador_Edad, 1);
			break;
		case 3:
			ll_sort(pArrayListJugador, compararJugador_Nombre, 1);
			break;
		}

	}
	return retorno;
}



/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 */
int controller_guardarJugadoresModoTexto(char *path, LinkedList *pArrayListJugador) {
	int retorno = 0;
	Jugador *pJugadorAux =  NULL;
	FILE *pArchivo = fopen(path, "w");

	int idAux;
	char nombreAux[30];
	int edadAux;
	char posicionAux[30];
	char nacionAux[30];
	int idSeleccionAux;

	if (pArchivo != NULL) {
		//Encabezado
		fprintf(pArchivo, "id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");
		for (int i = 0; i < ll_len(pArrayListJugador); i++) {
			pJugadorAux = ll_get(pArrayListJugador, i);
			jug_getId(pJugadorAux, &idAux);
			jug_getNombreCompleto(pJugadorAux, nombreAux);
		    jug_getEdad(pJugadorAux, &edadAux);
		    jug_getPosicion(pJugadorAux, posicionAux);
		    jug_getNacionalidad(pJugadorAux, nacionAux);
		    jug_getSIdSeleccion(pJugadorAux, &idSeleccionAux);
			fprintf(pArchivo, "%i,%s,%i,%s,%s,%i\n", idAux, nombreAux, edadAux, posicionAux, nacionAux, idSeleccionAux);
		}
		fclose(pArchivo);
		printf("Escrbiendo en archivo de texto ...\n");
		retorno = 1;
	}
	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 0;
	Jugador* pJugadorAux;
	FILE* pArchivo = fopen(path, "wb");

	if(pArchivo != NULL){
		for(int i = 0; i < ll_len(pArrayListJugador); i++){
			pJugadorAux = ll_get(pArrayListJugador, i);
			fwrite(pJugadorAux, sizeof(Jugador), 1, pArchivo);
		}
		fclose(pArchivo);
		printf("\nEscribiendo en archivo binario ...");
		retorno = 1;
	}
    return retorno;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	FILE* pArchivoSelec;
	pArchivoSelec = fopen(path, "r");
	if(pArchivoSelec != NULL && pArrayListSeleccion != NULL){
		printf("\nCargando datos del archivo de selecciones...\n");
		parser_SeleccionFromText(pArchivoSelec, pArrayListSeleccion);
		fclose(pArchivoSelec);
		retorno = 1;
	} else {
		printf("\nEl archivo no pudo ser abierto");
	}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	int cantidad = ll_len(pArrayListSeleccion);
    Seleccion * seleccionAux;

	printf("\n--------------------------------------------------------------------");
	printf("\n%5s %25s %20s %15s", "ID", "PAIS", "CONFEDERACION", "N° CONVOCADOS");
	printf("\n--------------------------------------------------------------------");

	if (pArrayListSeleccion != NULL && cantidad > 0) {
		retorno = 1;
		for (int i = 0; i < cantidad; i++) {
			seleccionAux = (Seleccion*) ll_get(pArrayListSeleccion, i);
			mostrar_unaSeleccion(seleccionAux);
		}
	}
	return retorno;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = 0;

    Seleccion *pSeleccionAux = NULL;
	FILE *pArchivo = fopen(path, "w");

	int idAux;
	int convocadosAux;
	char paisAux[25];
	char confederacionAux[15];

	if (pArchivo != NULL) {
		//Escribo encabezado
		fprintf(pArchivo,"id,pais,confederacion,convocados\n");
		for (int i = 0; i < ll_len(pArrayListSeleccion); i++) {
			pSeleccionAux = ll_get(pArrayListSeleccion, i);
			selec_getId(pSeleccionAux, &idAux);
			selec_getConvocados(pSeleccionAux, &convocadosAux);
			selec_getPais(pSeleccionAux, paisAux);
			selec_getConfederacion(pSeleccionAux, confederacionAux);
			fprintf(pArchivo, "%i,%s,%s,%i\n", idAux, paisAux, confederacionAux, convocadosAux);
		}
		fclose(pArchivo);
		printf("Escrbiendo en archivo de texto ...\n");
		retorno = 1;
	}
	return retorno;
}


/// ---------------------------------------------------------------------------------------------------------------------
/// --------------------------------------  AGREGO YO  ------------------------------------------------------------------
/// ---------------------------------------------------------------------------------------------------------------------


/**
 * \fn int controller_mostrarJugadoresConvocados(LinkedList*, LinkedList*)
 * \brief Funcion encargada de mostrar solamente a los jugadores convocados.
 *
 * \param pArrayListSeleccion - LinkedList selecciones.
 * \param pArrayListJugador - LinkedList jugadores.
 */

int controller_mostrarJugadoresConvocados(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador){
	int retorno = 0;
	int cantidad = ll_len(pArrayListJugador);
	Jugador *jugAux;
	int idSeleccion;
    printf("\n------------------------------------------------------------------------------------------------------------------");
	printf("\n%5s %25s %10s %30s %20s %15s", "ID", "NOMBRE COMPLETO", "EDAD", "POSICION", "NACION", "ID SELECCION");
	printf("\n------------------------------------------------------------------------------------------------------------------");
	if(pArrayListJugador != NULL && cantidad > 0){
		for (int i = 0; i < cantidad; i++) {
			jugAux = (Jugador*) ll_get(pArrayListJugador, i);
			jug_getSIdSeleccion(jugAux, &idSeleccion);
			if(idSeleccion > 0 && idSeleccion < 33){
				retorno = 1;
				mostrar_unJugador(jugAux, pArrayListSeleccion);
			}
		}
	}
	if(retorno == 0){
		printf("\n\nHasta el momento no hay jugadores convocados.");
	}
	return retorno;
}
/**
 * \fn int controller_convocarjugadores(LinkedList*, LinkedList*)
 * \brief Funcion encargada de convocar a un jugador.
 *
 * \param pArrayListSeleccion - LinkedList selecciones.
 * \param pArrayListJugador - LinkedList jugadores.
 */
int controller_convocarjugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int retorno = 0;
	int idJugadorElegido;

	Jugador*auxJugador;
	int posicionJugador;
	int idSeleccionNueva;
	int idSeleccionActual;

	Seleccion*auxSelecc;
	int posicionSeleccion;
	int cantidadConvocados;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){
		// muestro jugadores
		controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);
		// pido que ingrese ID de jugador
		utn_getNumero(&idJugadorElegido, "\nIngresar ID de jugador a convocar: ", "\nError, ingresar ID en rango [1-1500]: ", 1, 1500);
		// Busco posicion del jugador a convocar.
		posicionJugador = getJugadorIndexById(pArrayListJugador, idJugadorElegido);

		if (posicionJugador != -1) {
			// obtengo el jugador a convocar.
			auxJugador = ll_get(pArrayListJugador, posicionJugador);
			// busco el valor de su idSeleccion.
			jug_getSIdSeleccion(auxJugador, &idSeleccionActual);
			if (idSeleccionActual == 0) {
				// muestro las selecciones
				controller_listarSelecciones(pArrayListSeleccion);
				// pido que ingrese el valor de su ID.
				utn_getNumero(&idSeleccionNueva, "\nIngresar ID de seleccion: ", "\nError, ingresar ID en rango [1-32]: ", 1, 32);
				// Analizo a partir de la posicion de la seleccion, si sus convocados aun no superaron el maximo.
				posicionSeleccion = obtenerIndexSeleccionConID(pArrayListSeleccion, idSeleccionNueva);
				auxSelecc = ll_get(pArrayListSeleccion, posicionSeleccion);
				selec_getConvocados(auxSelecc, &cantidadConvocados);
				if(cantidadConvocados < 23){
					// guardo el valor del ID seleccion dentro de jugadores.
					jug_setIdSeleccion(auxJugador, idSeleccionNueva);
					// sumo a convocados.
					cantidadConvocados++;
					selec_setConvocados(auxSelecc, cantidadConvocados);
				}
			} else {
				printf("\nEste jugador ya fue convocado");
			}
		} else {
			printf("\nEl jugador ingresado no existe.");
		}
	}
	return retorno;
}
/**
 * \fn int controller_quitarConvocado(LinkedList*, LinkedList*)
 * \brief Funcion encargada de marcar a un jugador como no convocado.
 *
 * \param pArrayListSeleccion - LinkedList selecciones.
 * \param pArrayListJugador - LinkedList jugadores.
 */
int controller_quitarConvocado(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion) {
	int retorno = 0;

	Jugador *auxJugador;
	int posicionJugador;
	int idJugadorElegido;

	Seleccion *auxSelecc;
	int posicionSeleccion;
	int idSeleccionActual;
	int cantidadConvocados;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL) {
		// muestro jugadores
		controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);
		// pido que ingrese ID de jugador
		utn_getNumero(&idJugadorElegido,"\nIngresar ID de jugador a quitar seleccion: ", "\nError, ingresar ID en rango [1-1500]: ", 1, 1500);
		// Busco posicion del jugador a quitar.
		posicionJugador = getJugadorIndexById(pArrayListJugador, idJugadorElegido);

		if (posicionJugador != -1) {
			// obtengo el jugador a convocar.
			auxJugador = ll_get(pArrayListJugador, posicionJugador);
			// busco el valor de su idSeleccion.
			jug_getSIdSeleccion(auxJugador, &idSeleccionActual);
			if (idSeleccionActual > 0) {
				jug_setIdSeleccion(auxJugador, 0);
				// disminuyo una unidad a los convocados en esa seleccion;
				posicionSeleccion = obtenerIndexSeleccionConID(pArrayListSeleccion, idSeleccionActual);
				auxSelecc = ll_get(pArrayListSeleccion, posicionSeleccion);
				selec_getConvocados(auxSelecc, &cantidadConvocados);
				cantidadConvocados--;
				selec_setConvocados(auxSelecc, cantidadConvocados);
				printf("\nCantidad de convocados: %i", cantidadConvocados);
				retorno = 1;
			} else {
				printf("\nEste jugador no tiene seleccion");
			}
		} else {
			printf("\nEl jugador ingresado no existe.");
		}
	}
	return retorno;
}
/**
 * \fn int controller_ordenarYListar(LinkedList*, LinkedList*)
 * \brief Funcion encargada de ordenar y mostrar a los jugadores o selecciones, desplegando las opciones
 * para que el usuario elija como quiere ordenar y ver las listas.
 *
 * \param pArrayListSeleccion - LinkedList selecciones.
 * \param pArrayListJugador - LinkedList jugadores.
 */

int controller_ordenarYListar(LinkedList* listaJugadores, LinkedList* listaSelecciones){
	int retorno = 0;
	int opcion;
	printf("\n\n--- MENU ORDENAR ---\n\n");
	printf("\n1- Abrir Menu [ordenar Jugadores].\n2- Ordenar Selecciones por Confederacion.");
	utn_getNumero(&opcion, "\nIngresar opcion: ", "\nError, ingresar 1 o 2: ", 1, 2);
	if (listaJugadores != NULL && listaSelecciones != NULL) {
		retorno = 1;
		if (opcion == 1) {
			controller_ordenarJugadores(listaJugadores);
		} else {
			controller_ordenarSelecciones(listaSelecciones);
		}
	}
	return retorno;
}

/**
 * \fn int controller_GenerarArchivoConvocadosPorConfederacion(LinkedList*, LinkedList*, LinkedList*)
 * \brief Funcion encargada de crear (si es la primera vez) o reescribir (de ya haberse hecho alguna vez) un archivo
 * binario, escribiendo en él a los jugadores que han sido convocados.
 *
 * \param listaJugadores - LinkedList selecciones.
 * \param listaSelecciones - LinkedList jugadores.
 * \param listaAux - LinkedList clonada de jugadores que nos servira para filtrar a los convocados.
 */

int controller_GenerarArchivoConvocadosPorConfederacion(LinkedList* listaJugadores, LinkedList* listaSelecciones,
		LinkedList* listaAux){
	int retorno = 0;
	listaAux = ll_clone(listaJugadores);
	ll_clear(listaAux);

	int opcionConfe = menuConfederacion();

	Jugador* jugadorAux;
	int idSeleccionJugadorAux;
	Seleccion* selecAux;
	int idSeleccionAux;
	char paisSeleccion[30];

	for (int i = 0; i < ll_len(listaJugadores); i++) {
		jugadorAux = (Jugador*) ll_get(listaJugadores, i);
		jug_getSIdSeleccion(jugadorAux, &idSeleccionJugadorAux);

		if (idSeleccionJugadorAux != 0) {
			for (int j = 0; j < ll_len(listaSelecciones); j++) {
				selecAux = (Seleccion*) ll_get(listaSelecciones, j);
				selec_getId(selecAux, &idSeleccionAux);

				if (idSeleccionJugadorAux == idSeleccionAux) {
					selec_getPais(selecAux, paisSeleccion);
					switch (opcionConfe) {
					case 1:
						if (strcmpi(paisSeleccion, "Arabia Saudita") == 0
								|| strcmpi(paisSeleccion, "Australia") == 0
								|| strcmpi(paisSeleccion, "Corea del Sur") == 0
								|| strcmpi(paisSeleccion, "Iran") == 0
								|| strcmpi(paisSeleccion, "Japon") == 0
								|| strcmpi(paisSeleccion, "Qatar") == 0) {
							ll_add(listaAux, jugadorAux);
						}
						break;
					case 2:
						if (strcmpi(paisSeleccion, "Camerun") == 0
								|| strcmpi(paisSeleccion, "Ghana") == 0
								|| strcmpi(paisSeleccion, "Marruecos") == 0
								|| strcmpi(paisSeleccion, "Senegal") == 0
								|| strcmpi(paisSeleccion, "Tunez") == 0) {
							ll_add(listaAux, jugadorAux);
						}
						break;
					case 3:
						if (strcmpi(paisSeleccion, "Canada") == 0
								|| strcmpi(paisSeleccion, "Costa Rica") == 0
								|| strcmpi(paisSeleccion, "Estados Unidos") == 0
								|| strcmpi(paisSeleccion, "Mexico") == 0) {
							ll_add(listaAux, jugadorAux);
						}
						break;
					case 4:
						if (strcmpi(paisSeleccion, "Argentina") == 0
								|| strcmpi(paisSeleccion, "Brasil") == 0
								|| strcmpi(paisSeleccion, "Ecuador") == 0
								|| strcmpi(paisSeleccion, "Uruguay") == 0) {
							ll_add(listaAux, jugadorAux);
						}
						break;
					case 5:
						if (strcmpi(paisSeleccion, "Alemania") == 0
								|| strcmpi(paisSeleccion, "Belgica") == 0
								|| strcmpi(paisSeleccion, "Croacia") == 0
								|| strcmpi(paisSeleccion, "Dinamarca") == 0
								|| strcmpi(paisSeleccion, "Espana") == 0
								|| strcmpi(paisSeleccion, "Gales") == 0
								|| strcmpi(paisSeleccion, "Holanda") == 0
								|| strcmpi(paisSeleccion, "Inglaterra") == 0
								|| strcmpi(paisSeleccion, "Polonia") == 0
								|| strcmpi(paisSeleccion, "Portugal") == 0
								|| strcmpi(paisSeleccion, "Serbia") == 0
								|| strcmpi(paisSeleccion, "Suiza") == 0) {
							ll_add(listaAux, jugadorAux);
						}
						break;
					}

				}
			}

		}
	}
	controller_guardarJugadoresModoBinario("convocadosConfe.bin", listaAux);
	return retorno;
}

/**
 * \fn int controller_imprimirArchivoConvocados(LinkedList*, char*)
 * \brief Funcion encargada de imprimir a los jugadores convocados
 *
 * \param pArrayListJugador - LinkedList de jugadores.
 * \param path - Ruta a el archivo binario de jugadores convocados.
 */
int controller_imprimirArchivoConvocados(LinkedList* pArrayListJugador, char* path){
    int retorno = 0;

    LinkedList* aux = ll_clone(pArrayListJugador);
    ll_clear(aux);

    Jugador* pAuxJugador;

    FILE* pFile = fopen(path, "rb");

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
    			ll_add(aux, pAuxJugador);
    			retorno = 1;
    		}
    	}
    	fclose(pFile);
		FILE *pFile = fopen(path, "rb");
		if (pFile != NULL) {
			recorerArchivo_mostrar_jug(pFile, aux);
			fclose(pFile);
			retorno = 1;
		} else {
			printf("\nError, no se pudo abrir el archivo binario.");
		}
	}
	return retorno;
}

