/*
 * aPassengerPassenger.c
 *
 *  Created on: 7 may. 2022
 *      Author: tobic
 */

#include "ArrayPassenger.h"

/**
 * @fn int initPassengers(Passenger[], int)
 * @brief
 * Recibe un aPassenger de Pasajeros y el lena�o del mismo para inicializarlo.
 * @param aPassenger
 * @param len
 * @return Retorna -1 si fallo la y 0 si esta todo OK
 */
int initPassengers(Passenger aPassenger[], int len)
{
	int rtn = -1;
	if(aPassenger != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			aPassenger[i].isEmpty = LIBRE;
		}
		rtn = 0;
	}

	return rtn;
}

int addPassengers(Passenger aPassenger[], int len, int id, char name[], char lastName[],
float price, int typePassenger, char flycode[])
{
	int rtn = -1;
	Passenger aux;
	int index = getFreeIndex(aPassenger,len);

	if(index != -1) {
		if(aPassenger != NULL && len > 0 && id >= 0 && name != NULL && lastName != NULL
				&& price > 0 && typePassenger >= 0 && flycode != NULL)
			{
				aux.id = id;
				strcpy(aux.name, name);
				strcpy(aux.lastname, lastName);
				aux.price = price;
				aux.typePasenger = typePassenger;
				strcpy(aux.flycode ,flycode);
				aux.isEmpty = OCUPADO;

				aPassenger[index] = aux;

				rtn = 0;
			}
	}

	return rtn;
}

int getFreeIndex(Passenger aPassenger[], int len) //Retorna el INDEX o -1 si algo salio mal
{
	int rtn = -1;
	if(aPassenger != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(aPassenger[i].isEmpty == LIBRE)
			{
				rtn = i;
				return rtn;
			}
		}
	}

	return rtn;
}

int findPassengerById(Passenger aPassenger[], int len, int id)
{
	int rtn = -1;
	if(aPassenger != NULL && len > 0 && id > -1)
	{
		for(int i = 0; i < len; i++)
		{
			if(aPassenger[i].id == id)
			{
				rtn = i;
				return rtn;
			}
		}
	}

	return rtn;
}

int removePassenger(Passenger aPassenger[], int len, int id)
{
	int rtn = -1;
	if(aPassenger != NULL && len > 0 && id > -1)
	{
		for(int i = 0; i < len; i++)
		{
			if(aPassenger[i].id == id)
			{
				aPassenger[i].isEmpty = BAJA;
			}
		}
	}
	return rtn;
}

int sortPassenger(Passenger aPassenger[], int len, int order)
{
	int rtn = -1;
	Passenger aux;
	int i, j;

	if(aPassenger != NULL && len > 0 && ( order == 0 || order == 1))
	{
		switch (order) {
				case 0:
					for (i = 0; i < len - 1; i++) {
						for (j = i + 1; j < len; j++) {
							//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
							if (aPassenger[i].isEmpty == OCUPADO
									&& aPassenger[j].isEmpty == OCUPADO) {
								//order DE ORDENAMIENTO
								if (aPassenger[i].id > aPassenger[j].id) {
									//INTERCAMBIO POSICIONES EN aPassenger
									aux = aPassenger[i];
									aPassenger[i] = aPassenger[j];
									aPassenger[j] = aux;
								}
							}
						}
					}
					rtn = 0;
					break;
				case 1:
					for (i = 0; i < len - 1; i++) {
						for (j = i + 1; j < len; j++) {
							//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
							if (aPassenger[i].isEmpty == OCUPADO
									&& aPassenger[j].isEmpty == OCUPADO) {
								//order DE ORDENAMIENTO
								if (aPassenger[i].id < aPassenger[j].id) {
									//INTERCAMBIO POSICIONES EN aPassenger
									aux = aPassenger[i];
									aPassenger[i] = aPassenger[j];
									aPassenger[j] = aux;
								}
							}
						}
					}
					rtn = 0;
					break;
				default:
					rtn = -1;
					break;
				}
	}

	return rtn;
}

int sortPassengerByCode(Passenger aPassenger[], int len, int order)
{
	int rtn = -1;
	Passenger aux;

	if(aPassenger != NULL && len > 0 && (order == 0 || order == 1 ))
	{
		switch (order) {
						case 0:
							for (int i = 0; i < len - 1; i++) {
								for (int j = i + 1; j < len; j++) {
									//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
									if (aPassenger[i].isEmpty == OCUPADO
											&& aPassenger[j].isEmpty == OCUPADO) {
										//order DE ORDENAMIENTO
										if (aPassenger[i].flycode > aPassenger[j].flycode) {
											//INTERCAMBIO POSICIONES EN aPassenger
											aux = aPassenger[i];
											aPassenger[i] = aPassenger[j];
											aPassenger[j] = aux;
										}
									}
								}
							}
							rtn = 0;
							break;
						case 1:
							for (int i = 0; i < len - 1; i++) {
								for (int j = i + 1; j < len; j++) {
									//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
									if (aPassenger[i].isEmpty == OCUPADO
											&& aPassenger[j].isEmpty == OCUPADO) {
										//order DE ORDENAMIENTO
										if (aPassenger[i].flycode < aPassenger[j].flycode) {
											//INTERCAMBIO POSICIONES EN aPassenger
											aux = aPassenger[i];
											aPassenger[i] = aPassenger[j];
											aPassenger[j] = aux;
										}
									}
								}
							}
							rtn = 0;
							break;
						default:
							rtn = -1;
							break;
						}
	}

	return rtn;
}


int loadPassenger(void)
{
	int rtn = -1;
	Passenger aux;

	if(utn_getString(aux.name, sizeof(aux.name), "\nIngrese el nombre del pasajero: ", "\nIngrese el nombre correctamente: ", 3) == 0
			&& utn_getString(aux.lastname, sizeof(aux.lastname), "\nIngrese el apellido del pasajero: ", "\nIngrese el apellido nuevamente: ", 3) == 0
			&& utn_getNumeroFlotante(&aux.price, "\nIngrese el precio del vuelo: " , "Ingrese el precio nuevamente: ", 0, MAX_PRECIO, 3) == 0
			&& utn_getAlfaNum(aux.flycode, sizeof(aux.flycode), "\nIngrese el codigo del vuelo: ", "\nIngrese el codigo correctamente: ", 3)
			&& utn_getNumeroRange(&aux.statusFlight, "\nIngrese el estado del vuelo", "Ingresar estado de vuelo correctamente", 0, 5, 3) == 0)
	{
//////////SEGUIR DESDE ACA - ESTADOS DE VUELO Y CREAR STRUCTURA AP�RTE PARA LOS VUELOS!!!
	}

	return rtn;
}



void printPassenger(Passenger p) {
	printf("%5d\n", p.isEmpty);
}

int printAllPassengers(Passenger aPassengers[], int len)
{
	int i;
	int rtn = 0;
	int cant = 0;


	puts("\n\t> LISTADO");
	printf("%5s\n\n", "IS EMPTY");

	if (aPassengers != NULL && len > 0)
	{
		for (i = 0; i < len; i++) {

				printPassenger(aPassengers[i]);
				cant++;
		}
	}

	if (cant > 0) {
		rtn = 1;
	}

	return rtn;
}
