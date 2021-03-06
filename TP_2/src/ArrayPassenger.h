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

/**
* 	\brief To indicate that all position in the array are empty,
* 	this function put the flag (isEmpty) in TRUE in all
* 	position of the array
* 	\param list Passenger* Pointer to array of passenger
* 	\param len int Array length
* 	\return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initPassengers(Passenger aPassenger[], int len);
/**
 * \fn int addPassengers(Passenger[], int, int, char[], char[], float, int, char[], int)
 * \brief
 * add in a existing list of passengers the values received as parameters
 * in the first empty position
 * \param aPassenger
 * \param len
 * \param id
 * \param name
 * \param lastName
 * \param price
 * \param typePassenger
 * \param flycode
 * \param statusFlight
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addPassengers(Passenger aPassenger[], int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[], int statusFlight);
/**
 * \fn int getFreeIndex(Passenger[], int)
 * \brief
 * Look for a free space in the struct array
 * \param aPassenger
 * \param len
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int getFreeIndex(Passenger aPassenger[], int len);
/**
 * \fn int findPassengerById(Passenger[], int, int)
 * \brief
 * Search the id in parameter in the struct array and returns the index
 * \param aPassenger
 * \param len
 * \param id
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - int X for the index
 */
int findPassengerById(Passenger aPassenger[], int len, int id);
/**
 * \fn int removePassenger(Passenger[], int, int)
 * \brief
 * Change the state in isEmpty to remove the passenger from the list
 * \param aPassenger
 * \param len
 * \param id
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int removePassenger(Passenger aPassenger[], int len, int id);
/**
 * \fn int sortPassenger(Passenger[], int, int)
 * \brief
 * Sort passenger by lastname and passenger by type
 * \param aPassenger
 * \param len
 * \param order
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int sortPassenger(Passenger aPassenger[], int len, int order);
/**
 * \fn int sortPassengerByCode(Passenger[], int, int)
 * \brief
 * Sort by code and status flight on 1
 * \param aPassenger
 * \param len
 * \param order
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int sortPassengerByCode(Passenger aPassenger[], int len, int order);
/**
 * \fn int loadPassenger(Passenger[], int)
 * \brief
 * Load one passenger
 * \param aPassenger
 * \param len
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int loadPassenger(Passenger aPassenger[], int len);
/**
 * \fn int loadPassengerAuto(Passenger[], int)
 * \brief
 * Load 5 passengers automatically
 * \param aPassenger
 * \param len
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int loadPassengerAuto(Passenger aPassenger[], int len);
/**
 * \fn int modifyPassenger(Passenger[], int)
 * \brief
 * Modify data from a passenger
 * \param aPassengers
 * \param len
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int modifyPassenger(Passenger aPassengers[], int len);
/**
 * \fn int removeOnePassenger(Passenger[], int)
 * \brief
 * Remove one passenger from array struct
 * \param aPassenger
 * \param len
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int removeOnePassenger(Passenger aPassenger[], int len);
/**
 * \fn int printAllPassengers(Passenger[], int)
 * \brief
 *
 * \param aPassengers
 * \param len
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int printAllPassengers(Passenger aPassengers[], int len);
/**
 * \fn void printPassenger(Passenger)
 * \brief
 * Print one passenger
 * \param passenger
 */
void printPassenger(Passenger passenger);
/**
 * \fn int sumAllPrices(Passenger[], int, float*, float*, int*)
 * \brief
 * Sum all prices and return on a float the sum, average and counter of over avg passengers
 * \param aPassengers
 * \param len
 * \param sum
 * \param avg
 * \param counterPassenger
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int sumAllPrices(Passenger aPassengers[], int len, float *sum, float* avg, int* counterPassenger);
/**
 * \fn int printActiveFlights(Passenger[], int)
 * \brief
 * Print passengers with active flight
 * \param aPassengers
 * \param len
 * \return
 */
int printActiveFlights(Passenger aPassengers[], int len);
/**
 * \fn int checkPassengers(Passenger[], int)
 * \brief
 * Check that are passengers on the array passengers
 * \param aPassengers
 * \param len
 * \return
 */
int checkPassengers(Passenger aPassengers[], int len);
#endif /* ARRAYPASSENGER_H_ */
