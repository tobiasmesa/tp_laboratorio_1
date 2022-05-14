/*
 * practica.h
 *
 *  Created on: 5 abr. 2022
 *      Author: tobic
 */

#ifndef PRACTICA_H_
#define PRACTICA_H_

#include <stdio.h>
#include <stdlib.h>

int getIntRange(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroIngresado);
int getInt(char mensaje[], int reintentos, char mensajeError[], int *pNumeroIngresado);
int getIntArray(char mensaje[], char mensajeError[], int *arr[], int cantElementos);

#endif /* PRACTICA_H_ */
