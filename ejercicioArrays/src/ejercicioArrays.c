/*
 ============================================================================
 Name        : ejercicioArrays.c
 Author      : Tobias Mesa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "practica.h"

#define CANT_NUM 5


void cargarArray(int array[], int tam);
void imprimirArray(int array[], int tam);
int buscarMaxArray(int num);

int main(void) {
	char letra;
	setbuf(stdout, NULL);
	int numeros[CANT_NUM];

	cargarArray(numeros, CANT_NUM);
	printf("\na)Buscar el MAXIMO y mostrarlo mostrar la cantidad de ocurrencias\nb)Buscar el MINIMO y mostrarlo mostrar la cantidad de ocurrencias\nc)Calcular el PROMEDIO y mostrarlo\nd)Ingresar un numero y mostrar si se encontro, cuantas veces y las posiciones del array");
	fflush(stdin);
	scanf("%c", letra);
	switch(letra)
	{
		case 'a':
			printf("%d",buscarMaxArray(numeros));
			break;
		case 'b':
				break;
		case 'c':
				break;
		case 'd':
				break;
		default:
	}
	return EXIT_SUCCESS;
}


void cargarArray(int array[], int tam) {
	for (int i = 0; i < tam; i++){
		 getInt("Ingrese un numero: \n", 3,"ERROR! Reingrese un numero: \n", &array[i]);
	}
}

void imprimirArray(int array[], int tam) {
	for (int i = 0; i < tam; i++) {
		printf("%d\n", array[i]);
	}
}
