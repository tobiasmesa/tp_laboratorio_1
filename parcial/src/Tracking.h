/*
 * Tracking.h
 *
 *  Created on: 14 may. 2022
 *      Author: tobic
 */

#ifndef TRACKING_H_
#define TRACKING_H_

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#include "utn.h"

#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

#define NO_ENVIADO 0 // ESTADO DE LOS TRACKING
#define EN_VIAJE 1
#define ENTREGADO 2
#define CANCELADO 3


typedef struct {
	int idTracking;

	short int isEmpty;
	int cantidad;
	int distanciaKM;
	long int horaLlegada;

	short int estado;
	//Relaciones
	int idProducto;
	int idVendedor; //FK_USUARIO VENDEDOR
	int idComprador; // FK_USUARIO COMPRADOR

}Tracking;

long int time_Current(void);
long int time_Add(double secondsAdd);

void Tracking_Inicializar(Tracking array[], int TAM);
int Tracking_ObtenerIndexLibre(Tracking array[], int TAM);
int Tracking_BuscarPorID(Tracking array[], int TAM, int ID);
void Tracking_MostrarUno(Tracking tracking);
int Tracking_MostrarTodos(Tracking array[], int TAM);


//ABM

int Tracking_Baja(Tracking array[], int TAM, int idTracking);
void Tracking_refrescarEnvios(Tracking array[], int TAM);
#endif /* TRACKING_H_ */
