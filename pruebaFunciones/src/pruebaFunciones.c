/*
 ============================================================================
 Name        : pruebaFunciones.c
 Author      : Tobias Mesa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "practica.h"
#define CANT_EDADES 5

int main()
{
	setbuf(stdout, NULL);
	int num[CANT_EDADES];

	for (int i = 0; i < CANT_EDADES; i++)
	{
		getInt("Ingresar un numero: \n", 3, "\nError! reingresa el num", &num[i]);
	}
	for (int i = 0; i < CANT_EDADES; i++)
		{
			printf("%d\n", num[i]);
		}


	return EXIT_SUCCESS;
}

