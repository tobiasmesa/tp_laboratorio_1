/*
 * calculator.c
 *
 *  Created on: 5 abr. 2022
 *      Author: tobic
 */

#include "calculator.h"


int getInt(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroIngresado)
{
	int retorno = -1;
	int buffer;
	int retornoScanf;
	if(mensaje != NULL && minimo < maximo && mensajeError != NULL && pNumeroIngresado != NULL && reintentos > 0)
	{
		printf("%s", mensaje);
		retornoScanf = scanf("%d", &buffer);
		do
		{
			if(retornoScanf != 1 || buffer > maximo || buffer < minimo)
			{
				printf("%s", mensajeError);
				retornoScanf = scanf("%d", &buffer);
				reintentos--;
			}
			else
			{
				reintentos = 0;
				*pNumeroIngresado = buffer;
				retorno = 0;
			}

		} while(reintentos > 0);

	}

	return retorno;
}


float sumFloat(float a, float b)
{
	return a + b;
}
float subsFloat(float a, float b)
{
	return a - b;
}
float multFloat(float a, float b)
{
	return a * b;
}
float divFloat(float a, float b)
{
	if (b == 0)
	{
		return 0;
	}
	return a / b;
}



