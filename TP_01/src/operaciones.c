#include "operaciones.h"

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

int getFloat(float *pNum, char mensaje[], char mensajeError[], int intentos)
{
	int rtn = -1; // Set el retorno como -1 en caso de que salga mal
	int rtnScanf; // tomamos el valor
	float buffer;
	if(mensaje != NULL && mensajeError != NULL && pNum != NULL && intentos > 0)
	{
		printf("%s", mensaje);
		rtnScanf = scanf("%f", &buffer);
		do
		{
			if(rtnScanf != 1)
			{
				printf("%s", mensajeError);
				rtnScanf = scanf("%f", &buffer);
				intentos--;
			} else
			{
				intentos = 0;
				*pNum= buffer;
				rtn = 0;
			}
		} while(intentos > 0);
	}
	return rtn;
}

int getFloatRange(char mensaje[], int reintentos, float minimo, float maximo, char mensajeError[], float *pNumeroIngresado)
{
		int retorno = -1;
		float buffer;
		int retornoScanf;
		if(mensaje != NULL && minimo < maximo && mensajeError != NULL && pNumeroIngresado != NULL && reintentos > 0)
		{
			printf("%s", mensaje);
			retornoScanf = scanf("%f", &buffer);
			do
			{
				if(retornoScanf != 1 || buffer > maximo || buffer < minimo)
				{
					printf("%s", mensajeError);
					retornoScanf = scanf("%f", &buffer);
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

int getFloatPositive(float *pNum, char mensaje[], char mensajeError[], int intentos)
{
	int rtn = -1;
		int rtnScanf;
		float buffer;
		if(mensaje != NULL && mensajeError != NULL && pNum != NULL && intentos > 0)
		{
			printf("%s", mensaje);
			rtnScanf = scanf("%f", &buffer);
			do
			{
				if(rtnScanf != 1 || buffer < 1)
				{
					printf("%s", mensajeError);
					rtnScanf = scanf("%f", &buffer);
					intentos--;
				} else
				{
					intentos = 0;
					*pNum= buffer;
					rtn = 0;
				}
			} while(intentos > 0);
		}
		return rtn;

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

