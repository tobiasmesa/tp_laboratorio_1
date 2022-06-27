#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Controller.h"


static int getId(void);

static int getId(void) {
	static int incrementalId = 1001;
	return incrementalId++;
}

static int selectOrder(void);
static int selectOrder(void)
	{
		int order = -1;
utn_getNumeroRange(&order, "\n[0]Mayor a menor\n[1]Menor a mayor\nSeleccione el orden:", "Error. Reingrese: ", 0, 1, 3);

		return order;
	}
/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int rtn = 1; // verdadero
	if(path != NULL && pArrayListPassenger != NULL)
	{
		FILE *pArchivo = fopen(path, "r");
		if (pArchivo == NULL || parser_PassengerFromText(pArchivo, pArrayListPassenger) == 0) {
			rtn = -1;
		}
		fclose(pArchivo);

	}

    return rtn;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
		int rtn = 1; // verdadero

		if(path != NULL && pArrayListPassenger != NULL)
		{
				FILE *pArchivo = fopen(path, "rb");
				if (pArchivo != NULL && parser_PassengerFromBinary(pArchivo, pArrayListPassenger) != 0)
				{
					fclose(pArchivo);
				}
				else
				{
					rtn = -1;
				}
		}

	return rtn;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */



int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	// setters
	Passenger* aux = Passenger_new();

	int rtn = -1;
	char name[TAM];
	char lastname[TAM];
	float price;
	int typeP;
	int statusFlight;
	char flycode[TAM];
	int id;



	if(utn_getString(name, TAM, "\nIngrese el nombre del pasajero: ", "\nError. Reingrese: ", 3))
	{
		if(utn_getString(lastname, TAM, "\nIngrese el apellido del pasajero: ","\nError. Reingrese: ", 3))
		{
			if(utn_getNumeroFlotante(&price,"\nIngrese el precio del vuelo: ", "\nError. Reingrese: ", 0, MAX_PRICE, 3))
			{
				if(utn_getAlfaNum(flycode, TAM, "\nIngrese el codigo de vuelo: ", "\nError. Reingrese", 3))
				{
					if(utn_getNumeroRange(&statusFlight,"\n[0] ATERRIZADO"
							"\n[1] EN HORARIO"
							"\n[2] EN VUELO"
							"\n[3] DEMORADO\nIngrese el estado de vuelo ", "\nError. Reingrese: ", 0, 3, 3)){
							if(utn_getNumeroRange(&typeP,"\n[0] FIRST CLASS"
									"\n[1] EXECUTIVE CLASS"
									"\n[2] ECONOMY CLASS\nIngrese la clase del pasajero: ", "\nError. Reingrese: ", 0, 2, 3))
							{
								id = getId();
								if(id >= 1)
								{
									if(Passenger_setNombre(aux,name))
									{
										if(Passenger_setApellido(aux, lastname))
										{
											if(Passenger_setPrecio(aux, price))
											{
												if(Passenger_setCodigoVuelo(aux, flycode))
												{
													if(Passenger_setTipoPasajero(aux, typeP))
													{
														if(Passenger_setStatusFlight(aux, statusFlight))
														{
															if(Passenger_setId(aux, id))
															{

																	ll_add(pArrayListPassenger, aux);
																	rtn = 1;
															}
														}
													}
												}
											}
										}
									}
								}
						}
					}
				}
			}
		}
	}

    return rtn;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	//usar los gets
	int id;
	int opt;
	char name[TAM];
	char lastname[TAM];
	float price;
	int typeP;
	int statusFlight;
	char flycode[TAM];
	int index;
	Passenger* aux;

	if(pArrayListPassenger != NULL)
	{
		if(utn_getNumeroRange(&id, "Ingrese el ID a modificar: ", "Error. Reingrese", 1, 3000, 3))
		{
			index = controller_getIndexbyId(pArrayListPassenger, id);

			if( index != -1)
			{
			aux = ll_get(pArrayListPassenger, index); // COMO OBTENER EL INDEX CON EL ID

			if(aux != NULL)
			{
				if(utn_getNumeroRange(&opt, "\n1. Nombre\n2. Apellido\n3. Precio de vuelo\n4. Clase del pasajero\n5. Codigo de vuelo\n6. Estado de vuelo. \n\nIngrese la opcion: ", "Error. Reingrese: ", 1, 6, 3))
				{
					switch (opt) {
						case 1:
							if(utn_getString(name, TAM, "\nIngrese el nombre del pasajero: ", "\nError. Reingrese: ", 3)){
								Passenger_setNombre(aux, name);
							}
							break;
						case 2:
							if(utn_getString(lastname, TAM, "\nIngrese el apellido del pasajero: ","\nError. Reingrese: ", 3))
							{
								Passenger_setApellido(aux, lastname);
							}
							break;
						case 3:
							if(utn_getNumeroFlotante(&price,"\nIngrese el precio del vuelo: ", "\nError. Reingrese: ", 0, MAX_PRICE, 3))
							{
								Passenger_setPrecio(aux, price);
							}
							break;
						case 4:
							if(utn_getNumeroRange(&typeP,"\n[0] FIRST CLASS"
											"\n[1] EXECUTIVE CLASS"
											"\n[2] ECONOMY CLASS\nIngrese la clase del pasajero: ", "\nError. Reingrese: ", 0, 2, 3))
							{
								Passenger_setTipoPasajero(aux, typeP);
							}
							break;
						case 5:
							if(utn_getAlfaNum(flycode, TAM, "\nIngrese el codigo de vuelo: ", "\nError. Reingrese", 3))
							{
								Passenger_setCodigoVuelo(aux, flycode);
							}
							break;
						case 6:
							if(utn_getNumeroRange(&statusFlight,"\n[0] ATERRIZADO"
									"\n[1] EN HORARIO"
									"\n[2] EN VUELO"
									"\n[3] DEMORADO\nIngrese el estado de vuelo ", "\nError. Reingrese: ", 0, 3, 3))
							{
								Passenger_setStatusFlight(aux, statusFlight);
							}
							break;
						default:
							break;
					}
				}

			}
		}
	}
	}
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	int id;
	int index;

	if(pArrayListPassenger != NULL)
	{
		if(utn_getNumeroRange(&id, "Ingrese el ID a borrar: ", "Error. Reingrese", 1, 3000, 3))
		{
			index = controller_getIndexbyId(pArrayListPassenger, id);
			if(index != -1)
			{
			if(ll_remove(pArrayListPassenger, index))	// COMO OBTENER EL INDEX CON EL ID //Recorrer toda la lista con con llget comparando id y dsp con indexof
			{
				rtn = 1;
			}
			}
		}
	}
    return rtn;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	if(pArrayListPassenger != NULL)
	{
		printf("%4s %12s %12s %5s %10s %10s %10s\n","id","name","lastname","price","typePassenger","statusFlight","flycode");
		for(int i = 0; i < ll_len(pArrayListPassenger); i++){
              Passenger_printOne((Passenger*)ll_get(pArrayListPassenger, i));
    }
		return 1;
	}
    return 0;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	int opt;
	if(pArrayListPassenger != NULL)
	{
		if(utn_getNumeroRange(&opt, "\n[0] Por ID\n[1] Por nombre\n[2] Por Apellido\n[3] Por Precio\n[4] Por Clase\n[5] Por Codigo de vuelo\n[6] Por Estado de vuelo\nIngrese una opcion: ",
				"\nError. Reingrese: ", 0, 5, 3))
		{
			switch(opt)
			{
			case 0:
				ll_sort(pArrayListPassenger, Passenger_compareId, selectOrder());
			break;
			case 1:
				ll_sort(pArrayListPassenger, Passenger_compareName, selectOrder());
				break;
			case 2:
				ll_sort(pArrayListPassenger, Passenger_compareLastName, selectOrder());
				break;
			case 3:
				ll_sort(pArrayListPassenger, Passenger_comparePrice, selectOrder());
				break;
			case 4:
				ll_sort(pArrayListPassenger, Passenger_compareTypePassenger, selectOrder());
				break;
			case 5:
				ll_sort(pArrayListPassenger, Passenger_compareFlycode, selectOrder());
				break;
			case 6:
				ll_sort(pArrayListPassenger, Passenger_compareStatusFlight, selectOrder());
				break;
			default:
				break;
			}
		}

	}
    return rtn;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	FILE* pFile = NULL;
	Passenger* aux;
	int id;
	char name[TAM];
	char lastname[TAM];
	float price;
	char statusFlightChar[TAM];
	char flycode[TAM];
	char typePassengerChar[TAM];
	int typePassenger;
	int statusFlight;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			fprintf(pFile,"id,name,lastname,price,statusFlight,typePassenger,flycode\n");
				for(int i = 0; i < ll_len(pArrayListPassenger); i++)
				{
					aux = ll_get(pArrayListPassenger, i);
					if(Passenger_getId(aux, &id) && Passenger_getNombre(aux, name) && Passenger_getApellido(aux, lastname) &&
							Passenger_getPrecio(aux, &price) && Passenger_getStatusFlight(aux, &statusFlight) && Passenger_getTipoPasajero(aux, &typePassenger)
							&& Passenger_getCodigoVuelo(aux, flycode))
					{
						if(Passenger_statusPassengerTypeChar(typePassenger, typePassengerChar) && Passenger_statusFlightConverterChar(statusFlight, statusFlightChar))
						{
							fprintf(pFile,"%d,%s,%s,%f,%s,%s,%s\n", id, name, lastname, price, typePassengerChar, statusFlightChar, flycode);
						}
					}

				}
				rtn = 1;
		}
	}
	fclose(pFile);
    return rtn;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	FILE* pArchivo;
	Passenger* aux;
	int size = ll_len(pArrayListPassenger);


	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path, "wb");
		if(pArchivo != NULL)
		{
			for(int i = 0; i < size ; i++)
			{
				aux = ll_get(pArrayListPassenger, i);
				fwrite(aux, sizeof(Passenger),1,pArchivo);

			}
			rtn = 1;
		}
	}

    return rtn;
}

int controller_getIndexbyId(LinkedList* pArrayListPassenger, int id)
{
	int rtn = -1;
	int indexFounded;
	Passenger* aux;

	for(int i = 0; i < ll_len(pArrayListPassenger); i++)
	{
		aux = (Passenger*) ll_get(pArrayListPassenger, i);

		if(Passenger_getId(aux, &indexFounded))
		{
			if(indexFounded == id)
			{
				rtn = ll_indexOf(pArrayListPassenger, aux);
				break;
			}
		}
	}

	return rtn;
}
