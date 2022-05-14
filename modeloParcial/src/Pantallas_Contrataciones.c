/*
 * Pantallas_Contrataciones.c
 *
 *  Created on: 3 may. 2022
 *      Author: tobic
 */

#include "Pantallas_Contrataciones.h"

int altaContrataciones(Pantalla arrayP[], int TAM_P, Contrataciones arrayC[], int TAM_C)
{
	int rtn = 0;
	int idBuscar;
	int indexPantalla;
	int indexContratacionesLibre;
	Contrataciones aux;

	if(arrayP != NULL && arrayC != NULL && TAM_C > 0 && TAM_P > 0)
	{
		//Se listaran todas las pantallas y se le pedira al usuario la pantalla a contratar con su ID
		pa_MostrarTodos(arrayP, TAM_P);
		utn_getNumeroRange(&idBuscar, "\nIngrese el ID de la pantalla a contratar: ", "\nIngresar nuevamente: ", 0, 1000, 3);
		indexPantalla = pa_BuscarPorID(arrayP, TAM_P, idBuscar);
		if(indexPantalla != -1)
		{
			puts("ENTRE");
		}
	}


	return rtn;
}

