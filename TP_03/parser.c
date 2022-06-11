#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int rtn = 1;
	int countData;
	Passenger* aux;
	char id[TAM];
	char name[TAM];
	char lastname[TAM];
	char price[TAM];
	char flycode[TAM];
	char typePassenger[TAM];
	char statusFlight[TAM];

	if(pFile != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,name,lastname,price,flycode,typePassenger,statusFlight); // LEE LA PRIMERA LINEA
		do{
			countData = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,name,lastname,price,flycode,typePassenger,statusFlight);
			if(countData == 7)
			{
				aux = Passenger_newParametros(id, name, lastname, typePassenger, price, flycode, statusFlight);
				if(aux != NULL)
				{
					ll_add(pArrayListPassenger, aux);
				} else
				{
					free(aux);
					rtn = -1;
				}
			}else
			{
				free(aux);
				rtn = -1;
			}
			//Cuando valido el countdata cargar el pasajero y pasarlo a linked list
		}while(feof(pFile) == 0);
	}

    return rtn;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int rtn = 0;
	int cant = 0;
	int dataRead = 0;
	Passenger* aux;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		do {
			aux = Passenger_new();
			cant = fread(aux, sizeof(Passenger), 1, pFile);

			if (cant == 1 && aux != NULL) {
				ll_add(pArrayListPassenger, aux);
				dataRead++;
			}
		} while (!feof(pFile));

		if(dataRead != 0)
		{
			rtn = 1;
		}

	}

    return rtn;
}
