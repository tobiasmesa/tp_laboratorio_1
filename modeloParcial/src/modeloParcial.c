/*
 ============================================================================
 Name        : modeloParcial.c
 Author      : Tobias Mesa
 Version     :
 Copyright   : TP1 Laboratorio 1
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#include "Pantallas_Contrataciones.h"

#define CANT_PANTALLAS 100
#define CANT_CONTRATACIONES 1000

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	Pantalla aPantallas[CANT_PANTALLAS];
	Contrataciones aContratacioens[CANT_CONTRATACIONES];
	pa_inicializar(aPantallas, CANT_PANTALLAS);
	Contrataciones_Inicializar(aContratacioens, CANT_CONTRATACIONES);
	do
	{
		printf("\n1.Alta de pantalla\n2.Modificar datos de pantalla\n3.Baja de pantalla\n0.Salir");
		utn_getNumeroRange(&opcion, "\nIngrese la opcion: ", "\nIngrese una opcion valida", 0, 6, 3);
		switch(opcion)
		{
		case 1:
			pa_Alta(aPantallas, CANT_PANTALLAS);
			break;
		case 2:
			pa_Modificacion(aPantallas, CANT_PANTALLAS);
			break;
		case 3:

			break;
		case 4:
			altaContrataciones(aPantallas, CANT_PANTALLAS, aContratacioens,  CANT_CONTRATACIONES);
			break;
		default:
			break;
		}

	}while(opcion != 0);




	return EXIT_SUCCESS;
}


