/*
 ============================================================================
 Name        : c.c
 Author      : Tobias Mesa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

int main(void) {
	setbuf(stdout, NULL);
	float n, n2;
	float ans;
	int opcion;

	do {

		opcion = menuOptions();
		printf("Ingrese el primer numero: ");
		scanf("%f", &n);
		printf("\nIngrese el segundo numero: ");
		scanf("%f", &n2);

		switch(opcion)
		{
			case 1:
				ans = sumFloat(n,n2);
				break;
			case 2:
				ans = subsFloat(n,n2);
				break;
			case 3:
				 ans = multFloat(n,n2);
				break;
			case 4:
				ans = divFloat(n,n2);
				break;
		}

		printf("\n---------");
		printf("\nEl resultado es: %.2f", ans);

	} while (opcion != 0);


}



