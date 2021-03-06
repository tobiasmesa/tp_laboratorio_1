/*
 * aPassengerPassenger.c
 *
 *  Created on: 7 may. 2022
 *      Author: tobic
 */

#include "ArrayPassenger.h"
static int getId(void);
static int getId(void) {
	static int incrementalId = 0;
	return incrementalId++;
}


/**
 * @fn int initPassengers(Passenger[], int)
 * @brief
 * Recibe un aPassenger de Pasajeros y el lena?o del mismo para inicializarlo.
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
float price, int typePassenger, char flycode[], int statusFlight)
{
	int rtn = -1;
	Passenger aux;
	int index = getFreeIndex(aPassenger,len);

	if(index != -1) {
		if(aPassenger != NULL && len > 0 && id >= 0 && name != NULL && lastName != NULL
				&& price > 0 && typePassenger >= 0 && flycode != NULL && (statusFlight == 0 || statusFlight == 1))
			{
				aux.id = id;
				strcpy(aux.name, name);
				strcpy(aux.lastname, lastName);
				aux.price = price;
				aux.typePasenger = typePassenger;
				strcpy(aux.flycode ,flycode);
				aux.isEmpty = OCUPADO;
				aux.statusFlight = statusFlight;

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

int removeOnePassenger (Passenger aPassenger[], int len)
{
	int rtn = -1;

	int id;
	if(aPassenger != NULL && len > 0)
	{
		if(printAllPassengers(aPassenger, len) == 0)
		{
			utn_getNumeroRange(&id, "\nIngrese el ID a eliminar: ", "\nError! Reingrese!", 0, 10000, 3);
			if(findPassengerById(aPassenger, len, id) == -1)
			{
				utn_getNumeroRange(&id, "\nIngrese el ID a eliminar nuevamente: ", "\nError! Reingrese!", 0, 10000, 3);
			}
			else {
				removePassenger(aPassenger, len, id);
				rtn = 0;
			}


		}
	}
	return rtn;
}

int removePassenger(Passenger aPassenger[], int len, int id){
	int rtn = -1;

	if(aPassenger != NULL && len > 0 && id > -1)
	{
		for(int i = 0; i < len; i++)
		{
			if(aPassenger[i].id == id)
			{
				aPassenger[i].isEmpty = BAJA;
				rtn = 0;
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

								if (aPassenger[i].lastname[0] > aPassenger[j].lastname[0]) {
									//INTERCAMBIO POSICIONES EN aPassenger
									aux = aPassenger[i];
									aPassenger[i] = aPassenger[j];
									aPassenger[j] = aux;
								}
								if(aPassenger[i].lastname[0] == aPassenger[j].lastname[0])
								{
									if(aPassenger[i].typePasenger < aPassenger[j].typePasenger)
									{
										aux = aPassenger[i];
										aPassenger[i] = aPassenger[j];
										aPassenger[j] = aux;
									}
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
								if (aPassenger[i].lastname[0] < aPassenger[j].lastname[0]) {
									//INTERCAMBIO POSICIONES EN aPassenger
									aux = aPassenger[i];
									aPassenger[i] = aPassenger[j];
									aPassenger[j] = aux;
								}
								if(aPassenger[i].lastname[0] == aPassenger[j].lastname[0])
								{
									if(aPassenger[i].typePasenger < aPassenger[j].typePasenger)
									{
										aux = aPassenger[i];
										aPassenger[i] = aPassenger[j];
										aPassenger[j] = aux;
									}
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


										if (aPassenger[i].flycode[0] > aPassenger[j].flycode[0]) {
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
										if (aPassenger[i].flycode[0] < aPassenger[j].flycode[0]) {
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

int loadPassenger(Passenger aPassenger[], int len)

{
	int rtn = -1;
	Passenger aux;

	if(utn_getString(aux.name, sizeof(aux.name), "\nIngrese el nombre del pasajero: ", "\nIngrese el nombre correctamente: ", 3) == 0
			&& utn_getString(aux.lastname, sizeof(aux.lastname), "\nIngrese el apellido del pasajero: ", "\nIngrese el apellido nuevamente: ", 3) == 0
			&& utn_getNumeroFlotante(&aux.price, "\nIngrese el precio del vuelo: " , "Ingrese el precio nuevamente: ", 0, MAX_PRECIO, 3) == 0
			&& utn_getAlfaNum(aux.flycode, sizeof(aux.flycode), "\nIngrese el codigo del vuelo: ", "\nIngrese el codigo correctamente: ", 3) == 0
			&& utn_getNumeroRange(&aux.typePasenger, "\nIngrese el tipo de pasajero [CLASE ECONOMICA (0) / PRIMERA CLASE (1) / VIP (2)]: ", "\nReingrese el tipo de pasajero [CLASE ECONOMICA (0) / PRIMERA CLASE (1) / VIP (2)]: ", 0, 2, 3) == 0
			&& utn_getNumeroRange(&aux.statusFlight, "\nIngrese el estado del vuelo [ACTIVO (0) / CANCELADO (1)]: ", "Ingresar estado de vuelo correctamente [ACTIVO (0) / CANCELADO (1)]: ", 0, 1, 3) == 0)
	{
//////////SEGUIR DESDE ACA - ESTADOS DE VUELO Y CREAR STRUCTURA AP?RTE PARA LOS VUELOS!!!
		addPassengers(aPassenger, len, getId(), aux.name, aux.lastname, aux.price, aux.typePasenger, aux.flycode, aux.statusFlight);
		rtn = 0;
	}

	return rtn;
}

int loadPassengerAuto(Passenger aPassenger[], int len)
{
	int rtn = -1;
	if(aPassenger != NULL && len > 0)
	{
		addPassengers(aPassenger, len, getId(), "Juan", "Bravo", 10.6, VIP, "NB123", 1);
		addPassengers(aPassenger, len, getId(), "Matias", "Alvarez", 10.6, PRIMERA, "CB123", 0);
		addPassengers(aPassenger, len, getId(), "Bautista", "Rodriguez", 10.6, ECONOMICA, "ZB3", 1);
		addPassengers(aPassenger, len, getId(), "Eugenio", "Alvarez", 20.0, PRIMERA, "AB123", 0);
		addPassengers(aPassenger, len, getId(), "Ignacio", "Gudar", 10.6, VIP, "AB123", 1);
		addPassengers(aPassenger, len, getId(), "Genaro", "Soria", 10, ECONOMICA, "AB123", 0);
		addPassengers(aPassenger, len, getId(), "Tobias", "Mesa", 60.99, VIP, "AB123", 0);
		rtn = 0;
	}
	return rtn;
}

void printPassenger(Passenger p) {
	char typePassenger[20];
	char statusFlight[20];

	switch(p.typePasenger)
	{
		case 0:
			strcpy(typePassenger,"ECONOMICA");
			break;
		case 1:
			strcpy(typePassenger,"PRIMERA");
			break;
		case 2:
			strcpy(typePassenger,"VIP");
			break;
		default:
			break;
	}
	switch(p.statusFlight)
	{
		case 0:
			strcpy(statusFlight,"ACTIVO");
			break;
		case 1:
			strcpy(statusFlight,"CANCELADO");
			break;
		default:
			break;
	}
	printf("| %-3d | %-20s | %-20s | %-20s | %-20s | %20f | %20s |\n", p.id, p.name, p.lastname, typePassenger, p.flycode, p.price, statusFlight);
}

int printAllPassengers(Passenger aPassengers[], int len)
{
	int i;
	int rtn = 1;
	int cant = 0;

	printf("| %-3s | %-20s | %-20s | %-20s | %-20s | %20s | %20s |\n\n","id", "name", "lastname", "typePassenger", "p.flycode", "p.price", "p.isEmpty");
	if (aPassengers != NULL && len > 0)
	{
		for (i = 0; i < len; i++) {
			if(aPassengers[i].isEmpty == OCUPADO)
			{
				printPassenger(aPassengers[i]);
			}
				cant++;
		}
	}

	if (cant > 0) {
		rtn = 0;
	}

	return rtn;
}

int printActiveFlights(Passenger aPassengers[], int len)
{
	int i;
	int rtn = 1;
	int cant = 0;

	printf("| %-3s | %-20s | %-20s | %-20s | %-20s | %20s | %20s |\n\n","id", "Nombre", "Apellido", "Clase de pasajero", "Flycode", "Precio", "Flight Status");
	if (aPassengers != NULL && len > 0)
	{
		for (i = 0; i < len; i++) {
			if(aPassengers[i].isEmpty == OCUPADO && aPassengers[i].statusFlight == ACTIVO)
			{
				printPassenger(aPassengers[i]);
			}
				cant++;
		}
	}

	if (cant > 0) {
		rtn = 0;
	}

	return rtn;
}
int modifyPassenger(Passenger aPassengers[], int len)
{
	int rtn = -1;
	int id;
	int index;
	int option;
	Passenger aux;
	if(aPassengers != NULL && len > 0)
	{
		if(printAllPassengers(aPassengers, len) == 0)
		{
			if(utn_getNumeroRange(&id, "Ingrese la ID del pasajero a modificar: ", "Ingrese nuevamente el ID", 0, 1000, 3) == 0)
			{
				index = findPassengerById(aPassengers, len, id);
					if(index != -1)
					{
						aux = aPassengers[index];
						do{
							utn_getNumeroRange(&option,"\n1. Nombre\n2. Apellido\n3. Precio\n4. Tipo de pasajero\n5. Codigo de Vuelo\n0. Salir\nQue quiere modificar? ", "\nIngrese una opcion correcta! ", 0, 5, 3);
							switch(option)
							{
							case 1:
								utn_getString(aux.name, sizeof(aux.name), "\nIngrese el nombre a modificar: ", "\nError. Reingrese: ", 3);
								break;
							case 2:
								utn_getString(aux.lastname, sizeof(aux.lastname), "\nIngrese el apellido a modificar: ", "\nError. Reingrese: ", 3);
								break;
							case 3:
								utn_getNumeroFlotante(&aux.price, "\nIngrese el precio nuevo a modificar: ", "\nError. Reingrese: ", 0, 10, 3);
								break;
							case 4:
								utn_getNumeroRange(&aux.typePasenger, "\nIngrese el tipo de pasajero a modficar: ", "\nError. Reingrese: ", 0, 2, 3);
								break;
							case 5:
								utn_getAlfaNum(aux.flycode, sizeof(aux.flycode), "\nIngrese el codigo del vuelo a modificar: ", "\nError. Reingrese: ", 3);

								break;
							default:
								break;
							}

						} while(option != 0);
						 aPassengers[index] = aux;

					}
				}
			}


		}


	return rtn;
}

int sumAllPrices(Passenger aPassengers[], int len, float *sum, float* avg, int* counterPassenger)
{
	int rtn = -1;
	float tot = 0;
	int counter = 0;
	int counterP = 0;

	if(aPassengers != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(aPassengers[i].isEmpty == OCUPADO)
			{
				tot += aPassengers[i].price;
				counter++;
			}
		}
	}

	*avg = divFloat(tot, counter);

	for(int i = 0; i < len; i++)
	{
		if(aPassengers[i].isEmpty == OCUPADO && aPassengers[i].price > *avg)
		{
			counterP++;
		}
	}

	*sum = tot;
	*counterPassenger = counterP;

	return rtn;
}

int checkPassengers(Passenger aPassengers[], int len)
{
	int rtn = 1;
	if(aPassengers != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(aPassengers[i].isEmpty == OCUPADO)
			{
				rtn = 0;
				return rtn;
			}
		}
	}
	return rtn;
}
