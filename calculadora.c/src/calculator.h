/*
 * calculator.h
 *
 *  Created on: 5 abr. 2022
 *      Author: tobic
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_
#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"
int getInt(char mensaje, int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroIngresado);
float sumFloat(float a, float b);
float subsFloat(float a, float b);
float multFloat(float a, float b);
float divFloat(float a, float b);
int menuOptions();



#endif /* CALCULATOR_H_ */
