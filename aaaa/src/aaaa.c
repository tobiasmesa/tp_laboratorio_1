/*
 ============================================================================
 Name        : aaaa.c
 Author      : Tobias Mesa
 Version     :
 Copyright   : TP1 Laboratorio 1
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {
	setbuf(stdout, NULL);
	char a[200];
	utn_getAlfaNum(a, sizeof(a) ,"\nIngrese el numero flotante", "\nMal. reingrese", 3);
	printf("El numero es: %s", a);
	return EXIT_SUCCESS;
}
