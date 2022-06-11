/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define TAM 256
#define ATERRIZADO 0
#define EN_HORARIO 1
#define EN_VUELO 2
#define DEMORADO 3

#define FIRST 0
#define EXECUTIVE 1
#define ECONOMY 2

#define MAX_PRICE 100000000


typedef struct
{
	int id;
	char name[50];
	char lastname[50];
	float price;
	int typePassenger;
	char flycode[8];
	int statusFlight;

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nameStr, char* lastnameStr, char* typePassengerStr, char* priceStr, char* flycodeStr, char* statusFlight); // alta forzada - Completar con los parametros
Passenger* Passenger_newParametros(char* idStr,char* nameStr, char* lastnameStr, char* typePassengerStr, char* priceStr, char* flycodeStr, char* statusFlight); // alta forzada - Completar con los parametros


void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setStatusFlight(Passenger* this, int statusFlight);
int Passenger_getStatusFlight(Passenger* this, int* statusFlight);

int Passenger_printOne(Passenger* this);

int Passenger_statusFlightConverterInt(char* statusFlight);
int Passenger_statusPassengerTypeInt(char* typePassenger);

int Passenger_statusFlightConverterChar(int statusFlight, char*);
int Passenger_statusPassengerTypeChar(int typePassenger, char*);


int Passenger_compareId(void* a, void* b);

int Passenger_comparePrice(void* a, void* b);

int Passenger_compareName(void* a, void* b);

int Passenger_compareLastName(void* a, void* b);

int Passenger_compareFlycode(void* a, void* b);

int Passenger_compareStatusFlight(void* a, void* b);

int Passenger_compareTypePassenger(void* a, void* b);


#endif /* PASSENGER_H_ */
