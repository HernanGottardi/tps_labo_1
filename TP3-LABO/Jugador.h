#include "LinkedList.h"
#include <stdio.h>

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

void jug_delete(Jugador* this);

int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);


int inicializarJugador(Jugador * unJugadorcito);
int pedirDatosJugador(Jugador* jugador);
int getJugadorIndexById(LinkedList* listaJugadores, int id);
int pedirIndexBaja(LinkedList *listaJugadores, LinkedList *listaSelecciones);

int modificarNombre(LinkedList* listaJugadores, int id);
int modificarEdad(LinkedList* listaJugadores, int id);
int modificarPosicion(LinkedList* listaJugadores, int id);
int modificarNacionalidad(LinkedList* listaJugadores, int id);

int compararJugador_Nacionalidad(void* primerJugador, void* segundoJugador);
int compararJugador_Nombre(void* primerJugador, void* segundoJugador);
int compararJugador_Edad(void* primerJugador, void* segundoJugador);

int validarId(LinkedList* listaJugadores, int id);
int generar_listaConvocados(LinkedList* listaJugadores, LinkedList* listaSelecciones, LinkedList* listaAux);
int mostrar_listaConvocados(char* path, LinkedList *listaAux);
int mostrar_jug(FILE* pFile , LinkedList* pArrayListJugador);
int recorerArchivo_mostrar_jug(FILE* pFile , LinkedList* pArrayListJugador);

#endif // jug_H_INCLUDED
