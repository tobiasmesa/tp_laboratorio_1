/*
 * operaciones.h
 *
 *  Created on: 9 abr. 2022
 *      Author: tobic
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * @fn int getIntRange(char[], int, int, int, char[], int*)
 * @brief
 * Esta funcion solicita un numero entero en un rango especifico.
 * @param mensaje Muestra el mensaje que pide el ingreso del numero
 * @param reintentos reintentos para que se ingrese el INT de manera correcta
 * @param minimo Minimo del rango
 * @param maximo Maximo del rango
 * @param mensajeError
 * @param pNumeroIngresado Devuelve el numero entero por parametro
 * @return Devuelve 0 si esta bien -1 si algo fallo
 */
int getIntRange(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroIngresado);
/**
 * @fn int getInt(char[], int, char[], int*)
 * @brief
 *
 * @pre
 * @post
 * @param mensaje
 * @param reintentos
 * @param mensajeError
 * @param pNumeroIngresado
 * @return
 */
int getInt(char mensaje[], int reintentos, char mensajeError[], int *pNumeroIngresado);
/** */
int getFloat(float *pNum, char mensaje[], char mensajeError[], int intentos);
/** */
int getFloatPositive(float *pNum, char mensaje[], char mensajeError[], int intentos);
/** */
float sumFloat(float a, float b);
/** */
float subsFloat(float a, float b);
/** */
float multFloat(float a, float b);
/** */
float divFloat(float a, float b);

#endif /* OPERACIONES_H_ */
