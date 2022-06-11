/*
 * utn.h
 *
 *  Created on: 21 abr. 2022
 *      Author: tobic
 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int utn_getNumeroRange(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int myGets(char* cadena, int longitud);
int esNumerica(char* cadena, int limite);
int getInt(int* pResultado);

int utn_getString(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int esTexto(char* cadena,int longitud);
int getString(char* cadena, int longitud);
int utn_getAlfaNum(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int esAlfanumerica(char* cadena,int longitud);
int esFlotante(char* cadena, int limite);

float sumFloat(float a, float b);
float subsFloat(float a, float b);
float multFloat(float a, float b);
float divFloat(float a, float b);

#endif /* UTN_H_ */
