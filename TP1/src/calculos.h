/*
 * misFunciones.h
 *
 *  Created on: 15 sept 2022
 *      Author: herni
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "inputs.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------
/**
 * \fn void ElegirCondeferacion(int*, int*, int*, int*, int*, int*)
 * \brief Le permite al usuario elegir la confederacion del jugador. Incrementando en 1 la variable contadora correspondiente a su eleccion.
 *
 * \param contAFC Puntero a variable contadora que se va a incrementar en 1 si el usuario selecciona la opcion confederacion AFC
 * \param contCAF Puntero a variable contadora que se va a incrementar en 1 si el usuario selecciona la opcion confederacion CAF
 * \param contCONCACAF Puntero a variable contadora que se va a incrementar en 1 si el usuario selecciona la opcion confederacion CONCACAF
 * \param contCONMEBOL Puntero a variable contadora que se va a incrementar en 1 si el usuario selecciona la opcion confederacion CONMEBOL
 * \param contUEFA Puntero a variable contadora que se va a incrementar en 1 si el usuario selecciona la opcion confederacion UEFA
 * \param contOFC Puntero a variable contadora que se va a incrementar en 1 si el usuario selecciona la opcion confederacion OFC
 * \return no retorna nada, simplemente imprime en pantalla las opciones de confederacion a elegir.
 */



void elegirCondeferacion(int *pContAFC, int *pContCAF, int *pContCONCACAF, int *pContCONMEBOL, int *pContUEFA, int *pContOFC);
//--------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * \fn float CalcularPromedio(int*, int*)
 * \brief Calcula el promedio a partir de dos punteros a variables ingresadas.
 *
 * \param Puntero a variable contadora (por tipo de confederacion), que hace de dividendo en el promedio.
 * \param contadorTotal Puntero a variable contadora (cantidad de confederaciones ingresadas), que hace de divisor en el promedio.
 * \return Retorna la variable local creada en la funcion, encargada de llevar el valor del calculo promedio.
 */

float calcularPromedio(int *pContadorConfe, int* pContadorTotalConfe);
//--------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * \fn int VerificarExistenGastos(int*, int*, int*)
 * \brief Se encarga de comprobar a traves de una condicion, si los gastos de cada tipo(hospedaje, transporte, comida) son mayor a cero.
 *
 *
 * \param transporte Puntero a variable acumuladora de gastos.
 * \param hospedaje Puntero a variable acumuladora de gastos.
 * \param comida Puntero a variable acumuladora de gastos.
 * \return Retorna 1 si la condicion se cumple (que los tres parametros ingresados sean distintos a cero) o devuelve 0 si no se cumple.
 */

int verificarExistenGastos(int *pTransporte, int* pHospedaje, int* pComida);


#endif /* CALCULOS_H_ */
