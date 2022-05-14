/*
 * tp01_utilidades.h
 *
 *  Created on: 9 abr. 2022
 *      Author: tobic
 */

#ifndef TP01_UTILIDADES_H_
#define TP01_UTILIDADES_H_


#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

void precioVuelos(float * aerolinea, float* aerolineab);
void calcularCostos(float precio, float km,float *debito, float *credito, float *btc, float *pUnitario);
void mostrarCostos(char aerolinea[],float precio, float debito, float credito, float btc, float pUnitario);
void mostrarDiferencia(float aerolineaA, float aerolineaB);
#endif /* TP01_UTILIDADES_H_ */
