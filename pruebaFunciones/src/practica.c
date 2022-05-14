/*
 * practica.c
 *
 *  Created on: 5 abr. 2022
 *      Author: tobic
 */


#include "practica.h"

int getIntRange(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroIngresado)
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

int getInt(char mensaje[], int reintentos, char mensajeError[], int *pNumeroIngresado)
{
			int retorno = -1;
			int buffer;
			int retornoScanf;
			if(mensaje != NULL  && mensajeError != NULL && pNumeroIngresado != NULL && reintentos > 0)
			{
				printf("%s", mensaje);
				retornoScanf = scanf("%d", &buffer);
				do
				{
					if(retornoScanf != 1)
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

int getIntArray(char mensaje[], char mensajeError[], int *arr[], int cantElementos)
{
	int rtn = -1;
	if(mensaje != NULL && mensajeError != NULL && arr != NULL && cantElementos > 0)
	{
		int buffer[cantElementos];
		printf("%s", mensaje);

	}


	return rtn;
}








/*int getFloat(int *pNum, char mensaje[], char mensajeError[], int intentos)
{
	int rtn = -1;
	int rtnScanf;
	int buffer;
	if(mensaje != NULL && mensajeError != NULL && pNum != NULL && intentos > 0)
	{
		printf("%s", mensaje);
		rtnScanf = scanf("%d", &buffer);
		do
		{
			if(rtnScanf != 1)
			{
				printf("%s", mensajeError);
				rtnScanf = scanf("%d", &buffer);
				intentos--;
			}
		} while();
	}
	return rtn;
}



*/
