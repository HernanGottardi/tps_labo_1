

#include "jugador.h"
#include "inputs.h"
#include "LinkedList.h"
#include "ID.h"
#include "outputs.h"
#include "controller.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \fn Jugador jug_new*()
 * \brief Funcion encargada de reservar espacio en memoria dinamica para estructura del tipo Jugado,
 * e inicializarla con valores por defecto.
 *
 * \return variable que apunta a la direccion de memoria reservada o null en caso de no haberse efectuado.
 */

Jugador* jug_new()
{
	Jugador* pJugador;
	pJugador = (Jugador*) malloc(sizeof(Jugador));
	if(pJugador != NULL){
		inicializarJugador(pJugador);
	}
	return pJugador;
}

/**
 * \fn Jugador jug_newParametros*(char*, char*, char*, char*, char*, char*)
 * \brief Funcion encargada de reservar espacio en memoria dinamica para estructura del tipo Jugador y asignarle
 * a sus campos, valores recibidos como parametros.
 *
 * \param idStr - valor reicibido que se le asignara al campo id dentro de la estructura Jugador.
 * \param nombreCompletoStr - valor reicibido que se le asignara al campo nombreCompleto dentro de la estructura Jugador.
 * \param edadStr - valor reicibido que se le asignara al campo edad dentro de la estructura Jugador.
 * \param posicionStr - valor reicibido que se le asignara al campo posicion dentro de la estructura Jugador.
 * \param nacionalidadStr - valor reicibido que se le asignara al campo nacionalidad dentro de la estructura Jugador.
 * \param idSelccionStr - valor reicibido que se le asignara al campo idSeleccion dentro de la estructura Jugador.
 * \return si la reserva de memoria dinamica sale exitosamente la funcion devuelve el puntero a la estructura jugador.
 * Si no devuelve NULL.
 */

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* pJugador;
	pJugador = jug_new();

	if(pJugador != NULL){
		jug_setId(pJugador, atoi(idStr));
		jug_setNombreCompleto(pJugador, nombreCompletoStr);
		jug_setEdad(pJugador, atoi(edadStr));
		jug_setPosicion(pJugador, posicionStr);
		jug_setNacionalidad(pJugador, nacionalidadStr);
		jug_setIdSeleccion(pJugador, atoi(idSelccionStr));
	}
	return pJugador;
}

/**
 * \fn void jug_delete(Jugador*)
 * \brief Funcion encargada de liberar el espacio de memoria de una estructura del tipo Jugador pasada como parametro.
 *
 * \param this - puntero a la estructura Jugador.
 */

void jug_delete(Jugador* this){
	if(this != NULL){
		free(this);
	}
}

/**
 * \fn int jug_setId(Jugador*, int)
 * \brief Funcion encargada de asignarle un valor al campo id de la estructura Jugador pasada como parametro,
 * el valor asignado sera el que recibimos como segundo parametro.

 * \param this - puntero a la estructura Jugador que se le asginara el valor.
 * \param id - valor del tipo int que se guardara dentro de la estructura Jugador.
 * \return retorna 1 si salio bien y 0 si algo salio mal.
 */

int jug_setId(Jugador* this, int id){
	int retorno = 0;
	if(this != NULL && id > 0){
		this->id = id;
		retorno = 1;
	}
	return retorno;
}

/**
 * \fn int jug_getId(Jugador*, int*)
 * \brief Funcion encargada de extraer el valor que tiene guardado el campo id dentro de la estructura Jugador.
 *
 * \param this - estructura Jugador a la que se le extraera el valor que guarda su campo id.
 * \param id - En esta variable del tipo int se guardara el valor del campo id dentro de la estructura Jugador.
 */
int jug_getId(Jugador* this, int* id){
	int retorno = 0;
	if(this != NULL && id != NULL){
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}
//-------------------------------------------------------------

/**
 * \fn int jug_setNombreCompleto(Jugador*, char*)
 * \brief Funcion encargada de asignarle un valor al campo nombreCompleto de la estructura Jugador pasada como parametro,
 * el valor asignado sera el que recibimos como segundo parametro.
 *
 * \param this - puntero a la estructura Jugador que se le asginara el valor.
 * \param nombreCompleto - valor del tipo cadena de carac. que se guardara dentro de la estructura Jugador.
 */

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto){
	int retorno = 0;
	if(this != NULL && nombreCompleto != NULL){
		strcpy(this->nombreCompleto, nombreCompleto);
		retorno = 1;
	}
	return retorno;
}

/**
 * \fn int jug_getNombreCompleto(Jugador*, char*)
 * \brief Funcion encargada de extraer el valor que tiene guardado el campo nombreCompleto dentro de la estructura Jugador.
 *
 * \param this - estructura Jugador a la que se le extraera el valor que guarda su campo nombreCompleto.
 * \param nombreCompleto - En esta variable del tipo cadena de caract. se guardara el valor del campo nombreCompleto de la estructura Jugador.
 * \return
 */

int jug_getNombreCompleto(Jugador* this,char* nombreCompleto){
	int retorno = 0;
	if(this != NULL && nombreCompleto != NULL){
		strcpy(nombreCompleto, this->nombreCompleto);
		retorno = 1;
	}
	return retorno;
}
//-------------------------------------------------------------

/**
 * \fn int jug_setPosicion(Jugador*, char*)
 * \brief Funcion encargada de asignarle un valor al campo posicion de la estructura Jugador pasada como parametro,
 * el valor asignado sera el que recibimos como segundo parametro.
 *
 * \param this - puntero a la estructura Jugador que se le asginara el valor.
 * \param posicion - valor del tipo cadena de carac. que se guardara dentro de la estructura Jugador.
 * \return
 */

int jug_setPosicion(Jugador* this,char* posicion){
	int retorno = 0;
	if(this != NULL && posicion != NULL){
		strcpy(this->posicion, posicion);
		retorno = 1;
	}
	return retorno;
}

/**
 * \fn int jug_getPosicion(Jugador*, char*)
 * \brief Funcion encargada de extraer el valor que tiene guardado el campo posicion dentro de la estructura Jugador.
 *

 * \param this - estructura Jugador a la que se le extraera el valor que guarda su campo posicion.
 * \param posicion - En esta variable del tipo cadena de caract. se guardara el valor del campo posicion de la estructura Jugador.
 * \return
 */
int jug_getPosicion(Jugador *this, char *posicion) {
	int retorno = 0;
	if (this != NULL && posicion != NULL) {
		strcpy(posicion, this->posicion);
		retorno = 1;
	}
	return retorno;
}

//--------------------------------------------------------------

/**
 * \fn int jug_setNacionalidad(Jugador*, char*)
 * \brief Funcion encargada de asignarle un valor al campo nacionalidad de la estructura Jugador pasada como parametro,
 * el valor asignado sera el que recibimos como segundo parametro.
 *
 * \param this - puntero a la estructura Jugador que se le asginara el valor.
 * \param nacionalidad - valor del tipo cadena de carac. que se guardara dentro de la estructura Jugador.
 */

int jug_setNacionalidad(Jugador* this,char* nacionalidad){
	int retorno = 0;
	if(this != NULL && nacionalidad != NULL){
		strcpy(this->nacionalidad, nacionalidad);
		retorno = 1;
	}
	return retorno;
}

/**
 * \fn int jug_getNacionalidad(Jugador*, char*)
 * \brief Funcion encargada de extraer el valor que tiene guardado el campo nacionalidad dentro de la estructura Jugador.
 *
 * \param this - estructura Jugador a la que se le extraera el valor que guarda su campo posicion.
 * \param nacionalidad - En esta variable del tipo cadena de caract. se guardara el valor del campo nacionalidad de la estructura Jugador.
 */

int jug_getNacionalidad(Jugador* this,char* nacionalidad){
	int retorno = 0;
	if(this != NULL && nacionalidad != NULL){
		strcpy(nacionalidad, this->nacionalidad);
		retorno = 1;
	}
	return retorno;
}
//--------------------------------------------------------------

/**
 * \fn int jug_setEdad(Jugador*, int)
 * \brief Funcion encargada de asignarle un valor al campo edad de la estructura Jugador pasada como parametro,
 * el valor asignado sera el que recibimos como segundo parametro.
 *
 * \param this - puntero a la estructura Jugador que se le asginara el valor.
 * \param edad - valor del tipo int que se guardara dentro de la estructura Jugador.
 */
int jug_setEdad(Jugador* this, int edad){
	int retorno = 0;
	if(this != NULL	&& edad > -1){
		this->edad = edad;
		retorno = 1;
	}
	return retorno;
}

/**
 * \fn int jug_getEdad(Jugador*, int*)
 * \brief Funcion encargada de extraer el valor que tiene guardado el campo edad dentro de la estructura Jugador.
 *

 * \param this - estructura Jugador a la que se le extraera el valor que guarda su campo posicion.
 * \param edad - En esta variable del tipo int se guardara el valor del campo edad de la estructura Jugador.
 */

int jug_getEdad(Jugador* this, int* edad){
	int retorno = 0;
	if(this != NULL && edad != NULL){
		*edad = this->edad;
		retorno = 1;
	}
	return retorno;
}

//--------------------------------------------------------------

/**
 * \fn int jug_setIdSeleccion(Jugador*, int)
 * \brief Funcion encargada de asignarle un valor al campo idSeleccion de la estructura Jugador pasada como parametro,
 * el valor asignado sera el que recibimos como segundo parametro.
 *
 * \param this - puntero a la estructura Jugador que se le asginara el valor.
 * \param idSeleccion - valor del tipo int que se guardara dentro de la estructura Jugador.

 */

int jug_setIdSeleccion(Jugador* this, int idSeleccion){
	int retorno = 0;
	if(this != NULL && idSeleccion > -1){
		this->idSeleccion = idSeleccion;
		retorno = 1;
	}
	return retorno;
}
/**
 * \fn int jug_getSIdSeleccion(Jugador*, int*)
 * \brief Funcion encargada de extraer el valor que tiene guardado el campo idSeleccion dentro de la estructura Jugador.
 *
 * \param this - estructura Jugador a la que se le extraera el valor que guarda su campo posicion.
 * \param idSeleccion - En esta variable del tipo int se guardara el valor del campo idSeleccion de la estructura Jugador.
 */

int jug_getSIdSeleccion(Jugador* this, int* idSeleccion){
	int retorno = 0;
	if(this != NULL && idSeleccion != NULL){
		*idSeleccion = this->idSeleccion;
		retorno = 1;
	}
	return retorno;
}

//--------------------------------------------------------------

/**
 * \fn int inicializarJugador(Jugador*)
 * \brief Funcion encargada de asignarle valores inciciales a cada campo de la estructura Jugador.
 *
 * \param unJugadorcito - puntero a la estructura Jugador.

 */

int inicializarJugador(Jugador * unJugadorcito){
	int retorno = 0;
	if(unJugadorcito != NULL){
		retorno = 1;
		jug_setId(unJugadorcito, 0);
		jug_setEdad(unJugadorcito, 0);
		jug_setNombreCompleto(unJugadorcito, "0");
		jug_setIdSeleccion(unJugadorcito, 0);
		jug_setNacionalidad(unJugadorcito, "0");
		jug_setPosicion(unJugadorcito, "0");
	}
	return retorno;
}

//----------------------------------------------------------------

/**
 * \fn int pedirDatosJugador(Jugador*)
 * \brief Funcion encargada de pedirle al usuario que ingrese los datos pertenecientes a cada campo de la estructura Juagdor.
 *
 * \param jugador - Puntero a la estructura Jugador.
 */

int pedirDatosJugador(Jugador* jugador){
	int retorno = 0;

	Jugador auxJugador;
	char idAuxStr[1000];
	int idAuxNum;
	char nombreAux[30];
	int edadAux;
	char posicionAux[30];
	char nacionAux[30];
	int idSeleccionAux = 0;

	if(jugador != NULL){

		//id automatico
		leer_incrementar_ArchivoId(idAuxStr);
		idAuxNum = atoi(idAuxStr);
		jug_setId(&auxJugador, idAuxNum);
		//ingreso de nombre
		getCadena("\nIngresar nombre del jugador: ", nombreAux, 30);
		jug_setNombreCompleto(&auxJugador, nombreAux);
		//ingreso de edad
		utn_getNumero(&edadAux, "\nIngresar edad del jugador: ", "\nError, ingresar en rango[18-20]", 18, 40);
		jug_setEdad(&auxJugador, edadAux);
		//ingreso de posicion
		getCadena("\nIngresar posicion del jugador: ", posicionAux, 30);
		jug_setPosicion(&auxJugador, posicionAux);
		//ingreso de nacionalidad
		getCadena("\nIngresar nacionalidad del jugador: ", nacionAux, 30);
		jug_setNacionalidad(&auxJugador, nacionAux);
		//id seleccion automatico
		jug_setIdSeleccion(&auxJugador, idSeleccionAux);

		*jugador = auxJugador;
		retorno = 1;
	}


	return retorno;
}

/**
 * \fn int checkValidId(LinkedList*, int)
 * \brief Funcion encargada de recorrer todas las estructuras de la linkedList y comprobar si el
 * id pasado como parametro existe en alguno de los campos id de las estructuras Jugador.
 *
 * \param listaJugadores - linkedList que aloja las estructuras Jugador.
 * \param id - id a buscar.
 */
int validarId(LinkedList* listaJugadores, int id){
	int retorno = 0;
	int idAux;
	Jugador* auxJugador;

	for(int i = 0; i < ll_len(listaJugadores); i++){
		auxJugador = ll_get(listaJugadores, i);
		jug_getId(auxJugador, &idAux);
		if(idAux == id){
			retorno = 1;
			break;
		}
	}
	return retorno;
}

/**
 * \fn int getJugadorIndexById(LinkedList*, int)
 * \brief Funcion encargada de obtener uan estructura Jugador a traves del id pasado como segundo parametro.
 *
 * \param listaJugadores - LinkedList que aloja a las estructuras Jugador.
 * \param id - id de jugador que deseamos saber su posicion.
 */
int getJugadorIndexById(LinkedList* listaJugadores, int id)
{
	int index = -1;
	Jugador* auxJug;
	int idAux;

	for(int i=0; i<ll_len(listaJugadores); i++)
	{
		auxJug = ll_get(listaJugadores, i);
		jug_getId(auxJug, &idAux);
		if(idAux == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

/**
 * \fn int pedirIndexBaja(LinkedList*, LinkedList*)
 * \brief Funcion encargada de pedirle al usuario un jugador y devolver la posicion del mismo en la lista.
 *
 * \param listaJugadores - LinkedList que aloja a las estructuras Jugadores.
 * \param listaSelecciones - LinkedList que aloja a las estructuras selecciones.
 */

int pedirIndexBaja(LinkedList *listaJugadores, LinkedList *listaSelecciones) {
	int index = -1;
	int idEliminar;
	char confirmar;

	controller_listarJugadores(listaJugadores, listaSelecciones);
	printf("\nIngresar ID del jugador a eliminar: ");
	if (scanf("%i", &idEliminar) == 0) {
		fflush(stdin);
		printf("\nError, Valor no numerico.");
	}
	while (validarId(listaJugadores, idEliminar) == 0) {
		printf("\nError, el ID no existe. Vuelva a intentarlo: ");
		if(scanf("%i", &idEliminar) == 0){
			fflush(stdin);
			printf("\nError. Valor no numerico.");
		}
	}

	printf("\nUst. ingreso el ID: %i.", idEliminar);
	confirmacion("¿Seguro que desea eliminarlo? [S/N]: ", &confirmar);
	fflush(stdin);
	if(confirmar == 'S'){
		index = getJugadorIndexById(listaJugadores, idEliminar);
	} else {
		printf("\nLa baja fue cancelada.");
	}
   return index;
}

/**
 * \fn int modificarNombre(LinkedList*, int)
 * \brief Funcion encargada de pedirle al usuario un nuevo valor para el campo nombreCompleto de la estructura Jugador.
 *
 * \param listaJugadores - LinkedList en donde se aloja la estructura solicitada.
 * \param id - id de la estructura que se desea modificar.
 */
int modificarNombre(LinkedList* listaJugadores, int id){
	int retorno = 0;
	Jugador* jugadorAux;
	int indexJugador = getJugadorIndexById(listaJugadores, id);
	char nombreActual[25];
	char nuevoNombre[25];
	char confirmar;

	if(indexJugador != -1){
		retorno = 1;
		jugadorAux = (Jugador*)ll_get(listaJugadores, indexJugador);
		jug_getNombreCompleto(jugadorAux, nombreActual);
		printf("\nEl nombre actual es: %s", nombreActual);
		getCadena("\nIngresar nuevo nombre: ", nuevoNombre, 25);
		confirmacion("\nSeguro desea guardar los cambios? [S/N]: ", &confirmar);
		if(confirmar == 'S'){
			jug_setNombreCompleto(jugadorAux, nuevoNombre);
		}
	} else {
		printf("\n\nEl ID ingresado no existe.");
	}
	return retorno;
}
/**
 * \fn int modificarEdad(LinkedList*, int)
 * \brief Funcion encargada de pedirle al usuario un nuevo valor para el campo edad de la estructura Jugador.
 *
 * \param listaJugadores - LinkedList en donde se aloja la estructura solicitada.
 * \param id - id de la estructura que se desea modificar.
 */
int modificarEdad(LinkedList* listaJugadores, int id){
	int retorno = 0;
	Jugador* jugadorAux;
	int indexJugador = getJugadorIndexById(listaJugadores, id);
	int edadActual;
	int nuevaEdad;
	char confirmar;

	if(indexJugador != -1){
		retorno = 1;
		jugadorAux = (Jugador*)ll_get(listaJugadores, indexJugador);
		jug_getEdad(jugadorAux, &edadActual);
		printf("\nLa edad actual es: %i", edadActual);
		utn_getNumero(&nuevaEdad, "\nIngresar nueva edad: ", "Error, ingresar en rango [18-40]", 1, 40);
		confirmacion("\nSeguro desea guardar los cambios? [S/N]: ", &confirmar);
		if(confirmar == 'S'){
			jug_setEdad(jugadorAux, nuevaEdad);
		}
	} else {
		printf("\n\nEl ID ingresado no existe.");
	}
	return retorno;
}
/**
 * \fn int modificarPosicion(LinkedList*, int)
 * \brief Funcion encargada de pedirle al usuario un nuevo valor para el campo Posicion de la estructura Jugador.
 *
 * \param listaJugadores -  LinkedList en donde se aloja la estructura solicitada.
 * \param id - id de la estructura que se desea modificar.
 */
int modificarPosicion(LinkedList* listaJugadores, int id){
	int retorno = 0;
	Jugador* jugadorAux;
	int indexJugador = getJugadorIndexById(listaJugadores, id);
	char posActual[25];
	char nuevaPos[25];
	char confirmar;

	if(indexJugador != -1){
		retorno = 1;
		jugadorAux = (Jugador*)ll_get(listaJugadores, indexJugador);
		jug_getPosicion(jugadorAux, posActual);
		printf("\nLa posicion actual es: %s", posActual);
		getCadena("\nIngresar nueva posicion: ", nuevaPos, 25);
		confirmacion("\nSeguro desea guardar los cambios? [S/N]: ", &confirmar);
		if(confirmar == 'S'){
			jug_setPosicion(jugadorAux, nuevaPos);
		}
	} else {
		printf("\n\nEl ID ingresado no existe.");
	}
	return retorno;
}

/**
 * \fn int modificarNacionalidad(LinkedList*, int)
 * \brief Funcion encargada de pedirle al usuario un nuevo valor para el campo nacionalidad de la estructura Jugador.
 *
 * \param listaJugadores - LinkedList en donde se aloja la estructura solicitada.
 * \param id - id de la estructura que se desea modificar.
 */

int modificarNacionalidad(LinkedList* listaJugadores, int id){
	int retorno = 0;
	Jugador* jugadorAux;
	int indexJugador = getJugadorIndexById(listaJugadores, id);
	char nacionActual[25];
	char nuevaNacion[25];
	char confirmar;

	if(indexJugador != -1){
		retorno = 1;
		jugadorAux = (Jugador*)ll_get(listaJugadores, indexJugador);
		jug_getNacionalidad(jugadorAux, nacionActual);
		printf("\nLa nacionalidad actual es: %s", nacionActual);
		getCadena("\nIngresar nueva nacionalidad: ", nuevaNacion, 25);
		confirmacion("\nSeguro desea guardar los cambios? [S/N]: ", &confirmar);
		if(confirmar == 'S'){
			jug_setNacionalidad(jugadorAux, nuevaNacion);
		}
	} else {
		printf("\n\nEl ID ingresado no existe.");
	}
	return retorno;
}

/**
 * \fn int compararJugador_Nacionalidad(void*, void*)
 * \brief Funcion encargada de comparar dos campos nacionalidad de dos estructuras Jugador.
 *
 * \param primerJugador - estructura Jugador
 * \param segundoJugador - estructura Jugador
 */

int compararJugador_Nacionalidad(void* primerJugador, void* segundoJugador){
	int resCompara;

	Jugador* jugUno;
	jugUno = (Jugador*) primerJugador;
	Jugador* jugDos;
	jugDos = (Jugador*) segundoJugador;


	char primerNacionAux[25];
	jug_getNacionalidad(jugUno, primerNacionAux);
	char segundaNacionAux[25];
	jug_getNacionalidad(jugDos, segundaNacionAux);
	resCompara = strcmpi(primerNacionAux, segundaNacionAux);
	return resCompara;
}
/**
 * \fn int compararJugador_Nombre(void*, void*)
 * \brief Funcion encargada de comparar dos campos nombre de dos estructuras Jugador.
 *
 * \param primerJugador - estructura Jugador
 * \param segundoJugador - estructura Jugador

 */
int compararJugador_Nombre(void* primerJugador, void* segundoJugador){
	int resCompara;

	Jugador* jugUno;
	jugUno = (Jugador*) primerJugador;
	Jugador* jugDos;
	jugDos = (Jugador*) segundoJugador;

	char primerNombreAux[25];
	jug_getNombreCompleto(jugUno, primerNombreAux);
	char segundaNombreAux[25];
	jug_getNombreCompleto(jugDos, segundaNombreAux);
	resCompara = strcmpi(primerNombreAux, segundaNombreAux);
	return resCompara;
}

/**
 * \fn int compararJugador_Edad(void*, void*)
 * \brief Funcion encargada de comparar dos campos edad de dos estructuras Jugador.
 *
 * \param primerJugador - estructura Jugador
 * \param segundoJugador - estructura Jugador
 */

int compararJugador_Edad(void* primerJugador, void* segundoJugador){
	int resCompara;

	Jugador* jugUno;
	jugUno = (Jugador*) primerJugador;
	Jugador* jugDos;
	jugDos = (Jugador*) segundoJugador;

	int primerEdadAux;
	jug_getEdad(jugUno, &primerEdadAux);
	int segundaEdadAux;
	jug_getEdad(jugDos, &segundaEdadAux);
	if(primerEdadAux > segundaEdadAux){
		resCompara = 1;
	} else {
		resCompara = 0;
	}
	return resCompara;
}

/**
 * \fn int recorerArchivo_mostrar_jug(FILE*, LinkedList*)
 * \brief Funcion encargada de recorrer la LinkedList que almacena a las estructuras Jugador
 * y mostrarlas por pantalla.
 *
 * \param pFile - puntero a archivo.
 * \param pArrayListJugador - LinkedList de jugadores.
 */

int recorerArchivo_mostrar_jug(FILE* pFile , LinkedList* pArrayListJugador)
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
    			mostrar_unJugador(pAuxJugador, pArrayListJugador);
    			retorno = 1;
    		}
    	}
    }
    return retorno;
}

