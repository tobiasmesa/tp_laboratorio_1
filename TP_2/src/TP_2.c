/*
 ============================================================================
 Name        : TP_2.c
 Author      : Tobias Mesa
 Version     :
 Copyright   : TP2 Laboratorio 1
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayPassenger.h"

#define Q_PASSENGERS 2000 // Quantity PASSENGERS



int main(void) {
	setbuf(stdout, NULL);
	puts("TP2"); /* prints TO2 */
	Passenger arrayPassengers[Q_PASSENGERS];
	initPassengers(arrayPassengers, Q_PASSENGERS);
	int option;
	float sum = 0;
	float avg = 0;
	int option2;
	int counterPassengerOverAvg = 0;
	do
	{
		utn_getNumeroRange(&option, ""
				"\n 1. ALTA"
				"\n 2. MODIFICAR"
				"\n 3. BAJA"
				"\n 4. INFORMAR"
				"\n 5. CARGA FORZADA"
				"\n 0. SALIR"
				"\nIngrese una opcion: ", "\nIngrese una opcion valida: ", 0, 6, 3);
		switch(option)
		{
		case 1:
			loadPassenger(arrayPassengers, Q_PASSENGERS);
			break;
		case 2:
			if(checkPassengers(arrayPassengers, Q_PASSENGERS) == 0)
			{
				modifyPassenger(arrayPassengers, Q_PASSENGERS);
			} else
			{
				puts("Ingrese un pasajero!");
			}
			break;
		case 3:
			if(checkPassengers(arrayPassengers, Q_PASSENGERS) == 0)
			{
				removeOnePassenger(arrayPassengers, Q_PASSENGERS);
			} else
			{
				puts("Ingrese un pasajero!");
			}

			break;
		case 4:
			if(checkPassengers(arrayPassengers, Q_PASSENGERS) == 0)
			{
				utn_getNumeroRange(&option2, "\n1. Listado de pasajeros ordenado alfabeticamente por apellido y tipo.\n"
									"2.Total y promedio.\n"
									"3.Listado de los pajeros por Codigo y estados de vuelo.\n"
									"4.Salir.\nIngrese la opcion: ", "Error. Reingrese", 1, 4, 3);
							switch(option2)
							{
							case 1:
								sortPassenger(arrayPassengers, Q_PASSENGERS, 0);
								printAllPassengers(arrayPassengers, Q_PASSENGERS);
								break;
							case 2:
								sumAllPrices(arrayPassengers, Q_PASSENGERS, &sum, &avg, &counterPassengerOverAvg);
								printf("\nLa suma total de los precios de los vuelos es: $%.2f\n"
										"\nEl promedio del total de los vuelos es: $%.2f\n\n"
										"La cantidad de pasajeros sobre el promedio es: %d\n\n\n", sum, avg, counterPassengerOverAvg);
								break;
							case 3:
								sortPassengerByCode( arrayPassengers, Q_PASSENGERS, 0);
								printActiveFlights(arrayPassengers, Q_PASSENGERS);
								break;
							default:
								break;
							}
							} else
			{
				puts("Ingrese un pasajero!");
			}


			break;
		case 5:
			loadPassengerAuto(arrayPassengers, Q_PASSENGERS);
			break;
		case 6:
			printAllPassengers(arrayPassengers, Q_PASSENGERS);
			break;

		case 0:
			return 0;
			break;
		default:
			printf("Ingrese una opcion valida!");
			break;
		}

	} while(option != 0);




	return EXIT_SUCCESS;
}
