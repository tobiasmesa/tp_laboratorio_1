/*
 * Tracking.c
 *
 *  Created on: 14 may. 2022
 *      Author: tobic
 */


#include "Tracking.h"


long int time_Current()
{
	return time(NULL);
}

long int time_Add(double secondsAdd)
{
	return time_Current() + secondsAdd;
}

void Tracking_Inicializar(Tracking array[], int TAM) {
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			array[i].isEmpty = LIBRE;
			array[i].estado = NO_ENVIADO;
		}
	}
}

int Tracking_ObtenerIndexLibre(Tracking array[], int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int Tracking_BuscarPorID(Tracking array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idTracking == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void Tracking_MostrarUno(Tracking tracking) {
	//PRINTF DE UN SOLO tracking
	char estadoCompra[10];
	switch(tracking.estado)
	{
		case 0:
			strcpy(estadoCompra, "NO ENVIADO");
			break;
		case 1:
			strcpy(estadoCompra, "EN VIAJE");
			break;
		case 2:
			strcpy(estadoCompra, "ENTREGADO");
			break;
		case 3:
			strcpy(estadoCompra, "CANCELADO");
			break;
		default:
			break;
	}
	printf("----------------------------\n");
	printf("%5d -> ID TRAKING \n", tracking.idTracking);
	printf("%5d -> ID COMPRADOR \n", tracking.idComprador);
	printf("%5d -> ID VENDEDOR \n", tracking.idVendedor);
	printf("%5d -> ID PRODUCTO \n", tracking.idProducto);
	printf("%5s -> ESTADO DEL ENVIO KMS\n", estadoCompra);
	printf("----------------------------\n");
}

int Tracking_MostrarTodos(Tracking array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\tLISTADO trackings");
	 //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO tracking
				Tracking_MostrarUno(array[i]);
				//CONTADOR DE tracking
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO tracking PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}
	return rtn;
}

int Tracking_Sort(Tracking array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	Tracking aux;

	/** EJEMPLO DE SORT CON ID DE tracking
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)
	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idTracking > array[j].idTracking) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idTracking < array[j].idTracking) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}

void Tracking_refrescarEnvios(Tracking array[], int TAM)
{
	long int timeNow;
	for(int i = 0; i < TAM; i++)
	{
		if(array[i].isEmpty == OCUPADO)
		{
			timeNow = time_Current();
			if((array[i].horaLlegada - timeNow) <= 0)
			{
				array[i].estado = ENTREGADO;
			} else
			{
				array[i].estado = EN_VIAJE;
			}
		}
	}

}


