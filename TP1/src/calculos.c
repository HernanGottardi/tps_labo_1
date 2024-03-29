/*
 * misFunciones.c
 *
 *  Created on: 15 sept 2022
 *      Author: herni
 */

#include "calculos.h"

// ------------------------------------------------------------------------------------------------------

void elegirCondeferacion(int *pContAFC, int *pContCAF, int *pContCONCACAF, int *pContCONMEBOL, int *pContUEFA, int *pContOFC){

	int opcion;
	printf("\nLista de confederaciones: ");

	printf("\n1 - AFC");
	printf("\n2 - CAF");
	printf("\n3 - CONCACAF");
	printf("\n4 - CONMEBOL");
	printf("\n5 - UEFA");
	printf("\n6 - OFC");

	utn_getNumero(&opcion, "\nIngresar CONFEDERACION del jugador: ",
			"\nError, la opcion no esta en el rango [1-6]", 1, 6, 3);

	switch (opcion) {
	case 1:
		*pContAFC = *pContAFC + 1;
		break;
	case 2:
		*pContCAF = *pContCAF + 1;
		break;
	case 3:
		*pContCONCACAF = *pContCONCACAF + 1;
		break;
	case 4:
		*pContCONMEBOL = *pContCONMEBOL + 1;
		break;
	case 5:
		*pContUEFA = *pContUEFA + 1;
		break;
	case 6:
		*pContOFC = *pContOFC + 1;
		break;
	}
}

//-------------------------------------------------------------------------------------

float calcularPromedio(int *pContadorConfe, int* pContadorTotalConfe) {
	float bufferPorcen;
	bufferPorcen =  (float)*pContadorConfe / *pContadorTotalConfe;
	return bufferPorcen;
}

//---------------------------------------------------------------------------------------

int verificarExistenGastos(int *pTransporte, int* pHospedaje, int* pComida) {
	int retorno = 1;
	if(*pTransporte == 0  || *pHospedaje == 0 || *pComida == 0){
		retorno = 0;
	}
	return retorno;
}



