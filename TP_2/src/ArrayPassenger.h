/*
 * ArrayPassenger.h
 *
 *  Created on: 7 may. 2022
 *      Author: tobic
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "utn.h"

#define MAX_PRECIO 1000000

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

#define ACTIVO 0
#define CANCELADO 1

#define ECONOMICA 0
#define PRIMERA 1
#define VIP 2

typedef struct {

	int id;
	char name[51];
	char lastname[51];
	float price;
	char flycode[10];
	int typePasenger;
	int statusFlight;
	int isEmpty;

} Passenger;


int initPassengers(Passenger aPassenger[], int len);
int addPassengers(Passenger aPassenger[], int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[], int statusFlight);
int getFreeIndex(Passenger aPassenger[], int len);
int findPassengerById(Passenger aPassenger[], int len, int id);
int removePassenger(Passenger aPassenger[], int len, int id);
int sortPassenger(Passenger aPassenger[], int len, int order);
int sortPassengerByCode(Passenger aPassenger[], int len, int order);
int loadPassenger(Passenger aPassenger[], int len);
int loadPassengerAuto(Passenger aPassenger[], int len);
int modifyPassenger(Passenger aPassengers[], int len);
int removeOnePassenger (Passenger aPassenger[], int len);
int printAllPassengers(Passenger aPassengers[], int len);
void printPassenger(Passenger passenger);
int sumAllPrices(Passenger aPassengers[], int len, float *sum, float* avg, int* counterPassenger);

#endif /* ARRAYPASSENGER_H_ */
