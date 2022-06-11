/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include "Passenger.h"

Passenger* Passenger_new()
{
	Passenger* aux = NULL;
	aux = (Passenger*)malloc(sizeof(Passenger));
	return aux;
}

Passenger* Passenger_newParametros(char* idStr,char* nameStr, char* lastnameStr, char* typePassengerStr, char* priceStr, char* flycodeStr, char* statusFlightStr) // alta forzada - Completar con los parametro
{
	Passenger* aux = Passenger_new();
	int statusFlightInt = Passenger_statusFlightConverterInt(statusFlightStr);
	int typePassenger = Passenger_statusPassengerTypeInt(typePassengerStr);

	if(aux != NULL)
	{
		if(esNumerica(idStr, TAM) && esFlotante(priceStr, TAM) && esAlfanumerica(flycodeStr, TAM) && statusFlightInt != -1 && typePassenger != -1)
		{   //Usar los setters, cargar en la lista y hacer la view //Crear SETTER PARA TIPOS CHAR
			if(Passenger_setId(aux, atoi(idStr)) &&
					Passenger_setPrecio(aux, atof(priceStr)) &&
					Passenger_setNombre(aux, nameStr) &&
					Passenger_setApellido(aux, lastnameStr) &&
					Passenger_setCodigoVuelo(aux,flycodeStr) &&
					Passenger_setTipoPasajero(aux, typePassenger) &&
					Passenger_setStatusFlight(aux, statusFlightInt))
			{
				return aux;
			}
		} else {
			free(aux); // Que retorna si los valores no son correctos?
		}
	}
	return aux;
}


int Passenger_setId(Passenger* this, int id)
{
	int rtn = 0;
	if(this != NULL && id > 0)
	{
		this->id = id;
		rtn = 1;
	}
	return rtn;
}


int Passenger_setNombre(Passenger* this, char* nombre)
{
	int rtn = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->name,nombre);
		rtn = 1;
	}
	return rtn;
}



int Passenger_setApellido(Passenger* this, char* apellido)
{
	int rtn = 0;
	if(this != NULL && apellido != NULL)
	{
		strcpy(this->lastname,apellido);
		rtn = 1;
	}
	return rtn;
}


int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int rtn = 0 ;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->flycode,codigoVuelo);
		rtn = 1;
	}
	return rtn;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int rtn = 0;
	if(this != NULL && tipoPasajero != -1)
	{
		this->typePassenger = tipoPasajero;
		rtn = 1;
	}
	return rtn;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int rtn = 0;
	if(this != NULL && precio > -1)
	{
		this->price=precio;
		rtn = 1;
	}
	return rtn;
}

int Passenger_setStatusFlight(Passenger* this, int statusFlight)
{
	int rtn = 0;
	if(this != NULL && statusFlight != -1)
	{
		this->statusFlight=statusFlight;
		rtn = 1;
	}
	return rtn;
}

void Passenger_delete(Passenger* this)
{
	free(this);
}

int Passenger_printOne(Passenger* this)
{
	int rtn = -1;
	int id;
	float price;
	char name[TAM];
	char lastname[TAM];
	int typePassenger;
	int statusFlight;
	char flycode[TAM];
	char typePassengerChar[TAM];
	char statusFlightChar[TAM];

	if(Passenger_getId(this, &id))
	{
		if(Passenger_getNombre(this, name))
		{
			if(Passenger_getApellido(this, lastname))
			{
				if(Passenger_getStatusFlight(this, &statusFlight))
				{
					if(Passenger_getTipoPasajero(this, &typePassenger))
					{
						if(Passenger_getPrecio(this, &price))
						{
							if(Passenger_getCodigoVuelo(this, flycode))
							{
								if(Passenger_statusPassengerTypeChar(typePassenger, typePassengerChar))
								{
									if(Passenger_statusFlightConverterChar(statusFlight, statusFlightChar))
									{
										printf("%4d %12s %12s $%5.1f %10s %10s %10s\n",id,name,lastname,price,typePassengerChar,statusFlightChar,flycode);
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
	//VALIDAR LOS GETTERS Y NO MUESTRA NADA !!
	return rtn;
}

int Passenger_getId(Passenger* this, int* id)
{
	int rtn = 0; //RETORNA FALSO
	if(this != NULL && id != NULL)
	{
		rtn = 1;
		*id = this->id;
	}

	return rtn;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int rtn = 0; //RETORNA FALSO
	if(this != NULL && nombre != NULL)
	{
		rtn = 1;
		strcpy(nombre,this->name);
	}
	return rtn;

}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int rtn = 0; //RETORNA FALSO
	if(this != NULL && apellido != NULL)
	{
		rtn = 1;
		strcpy(apellido,this->lastname);
	}

	return rtn;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int rtn = 0; //RETORNA FALSO
	if(this != NULL && codigoVuelo != NULL)
	{
		rtn = 1;
		strcpy(codigoVuelo,this->flycode);
	}
	return rtn;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int rtn = 0; //RETORNA FALSO
	if(this != NULL && tipoPasajero != NULL)
	{
		rtn = 1;
		*tipoPasajero = this->typePassenger;
	}
	return rtn;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int rtn = 0; //RETORNA FALSO
	if(this != NULL && precio != NULL)
	{
		rtn = 1;
		 *precio = this->price;
	}
	return rtn;
}

int Passenger_getStatusFlight(Passenger* this, int* statusFlight)
{
	int rtn = 0; //RETORNA FALSO
	if(this != NULL && statusFlight != NULL)
	{
		rtn = 1;
		 *statusFlight = this->statusFlight;
	}
	return rtn;
}

int Passenger_statusPassengerTypeInt(char* passengerType)

{
	int rtn = -1;
	if(passengerType != NULL)
	{
		if(strcmp(passengerType,"EconomyClass") == 0)
		{
			return ECONOMY;
		}
		if(strcmp(passengerType,"FirstClass") == 0)
		{
			return FIRST;
		}
		if(strcmp(passengerType, "ExecutiveClass") == 0)
		{
			return EXECUTIVE;
		}
	}
	return rtn;
}

int Passenger_statusPassengerTypeChar(int typePassenger, char* typeChar)
{
		int rtn = -1;
		if(typePassenger > -1)
		{
			if(typePassenger == ECONOMY)
			{
				strcpy(typeChar, "EconomyClass");
				rtn = 1;
			}
			if(typePassenger == FIRST)
			{
				strcpy(typeChar, "FirstClass");
				rtn = 1;
			}
			if(typePassenger == EXECUTIVE)
			{
				strcpy(typeChar, "ExecutiveClass");
				rtn = 1;
			}
		}
		return rtn;
}

int Passenger_statusFlightConverterInt(char* statusFlight) //Retorna el estado de vuelo
{
	int rtn = -1;
	if(statusFlight != NULL)
	{
		if(strcmp(statusFlight,"Aterrizado") == 0)
		{
			return ATERRIZADO;
		}
		if(strcmp(statusFlight,"En Horario") == 0)
		{
			return EN_HORARIO;
		}
		if(strcmp(statusFlight, "Demorado") == 0 )
		{
			return DEMORADO;
		}
		if(strcmp(statusFlight, "En Vuelo") == 0)
		{
			return EN_VUELO;
		}
	}
	return rtn;
}

int Passenger_statusFlightConverterChar(int statusFlight, char* statusChar)
{
		int rtn = -1;
		if(statusFlight > -1 && statusChar != NULL)
		{
			if(statusFlight == ATERRIZADO)
			{
				strcpy(statusChar, "Aterrizado");
				rtn = 1;
			}
			if(statusFlight == EN_HORARIO)
			{
				strcpy(statusChar, "En Horario");
				rtn = 1;
			}
			if(statusFlight == DEMORADO )
			{
				strcpy(statusChar, "Demorado");
				rtn = 1;
			}
			if( statusFlight == EN_VUELO)
			{
				strcpy(statusChar, "En Vuelo");
				rtn = 1;
			}
		}
		return rtn;

}

int Passenger_compareId(void* a, void* b)
{
	int rtn = 0;
	int idA;
	int idB;
	Passenger* aux1 = (Passenger*) a;
	Passenger* aux2 = (Passenger*) b;
	if(a != NULL)
	{
		if(b  != NULL)
		{
			if(Passenger_getId(aux1, &idA))
			{
				if(Passenger_getId(aux2, &idB))
				{
					if(idA > idB)
					{
						rtn = 1;

					} else
					{
						rtn = -1;
					}
				}
			}
		}
	}

	return rtn;
}

int Passenger_comparePrice(void* a, void* b)
{
	int rtn = 0;
	float priceA;
	float priceB;
	Passenger* aux1 = (Passenger*) a;
	Passenger* aux2 = (Passenger*) b;
	if(a != NULL)
	{
		if(b  != NULL)
		{
			if(Passenger_getPrecio(aux1, &priceA))
			{
				if(Passenger_getPrecio(aux2, &priceB))
				{
					if(priceA > priceB)
					{
						rtn = 1;
					} else
					{
						rtn = -1;
					}
				}
			}
		}
	}

	return rtn;
}

int Passenger_compareName(void* a, void* b)
{
	int rtn = 0;

	char name[TAM];
	char name2[TAM];

	Passenger* aux1 = (Passenger*) a;
	Passenger* aux2 = (Passenger*) b;

	if(a != NULL)
	{
		if(b  != NULL)
		{
			if(Passenger_getNombre(aux1, name))
			{
				if(Passenger_getNombre(aux2, name2))
				{
					if(strncmp(name,name2,TAM) > 0)
					{
						rtn = 1;
					}
					else
					{
						rtn = -1;
					}
				}
			}
		}
	}

	return rtn;
}

int Passenger_compareLastName(void* a, void* b)
{
	int rtn = 0;

	char lastname[TAM];
	char lastname2[TAM];

	Passenger* aux1 = (Passenger*) a;
	Passenger* aux2 = (Passenger*) b;

	if(a != NULL)
	{
		if(b  != NULL)
		{
			if(Passenger_getApellido(aux1, lastname))
			{
				if(Passenger_getApellido(aux2, lastname2))
				{
					if(strncmp(lastname,lastname2,TAM) > 0)
					{
						rtn = 1;
					}
					else
					{
						rtn = -1;
					}
				}
			}
		}
	}

	return rtn;
}

int Passenger_compareFlycode(void* a, void* b)
{
	int rtn = 0;

	char flycode[TAM];
	char flycode2[TAM];

	Passenger* aux1 = (Passenger*) a;
	Passenger* aux2 = (Passenger*) b;

	if(a != NULL)
	{
		if(b  != NULL)
		{
			if(Passenger_getCodigoVuelo(aux1, flycode))
			{
				if(Passenger_getCodigoVuelo(aux2, flycode2))
				{
					if(strncmp(flycode, flycode2, TAM) > 0)
					{
						rtn = 1;
					}
					else
					{
						rtn = -1;
					}
				}
			}
		}
	}

	return rtn;
}

int Passenger_compareStatusFlight(void* a, void* b)
{
	int rtn = 0;

	int statusFlight;
	int statusFlight2;

	Passenger* aux1 = (Passenger*) a;
	Passenger* aux2 = (Passenger*) b;

	if(a != NULL)
	{
		if(b  != NULL)
		{
			if(Passenger_getStatusFlight(aux1, &statusFlight))
			{
				if(Passenger_getStatusFlight(aux2, &statusFlight2))
				{
					if(statusFlight > statusFlight2)
					{
						rtn = 1;
					} else
					{
						rtn = -1;
					}
				}
			}
		}
	}

	return rtn;
}

int Passenger_compareTypePassenger(void* a, void* b)
{
	int rtn = 0;

	int typePassenger;
	int typePassenger2;

	Passenger* aux1 = (Passenger*) a;
	Passenger* aux2 = (Passenger*) b;

	if(a != NULL)
	{
		if(b  != NULL)
		{
			if(Passenger_getStatusFlight(aux1, &typePassenger))
			{
				if(Passenger_getStatusFlight(aux2, &typePassenger2))
				{
					if(typePassenger > typePassenger2)
					{
						rtn = 1;
					} else
					{
						rtn = -1;
					}
				}
			}
		}
	}

	return rtn;
}

