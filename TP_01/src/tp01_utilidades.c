/*
 * tp01_utilidades.c
 *
 *  Created on: 9 abr. 2022
 *      Author: tobic
 */

#include "tp01_utilidades.h"
#define BTC 4793339.23

void precioVuelos(float * aerolinea, float* aerolineab)
{
	int opcion;
	getIntRange("Ingrese la aerolinea a la que ingresara su precio: \n 1. Aerolineas.\n 2. Latam.\nOpcion: ", 3, 1, 2, "\nIngrese una opcion valida: \n", &opcion);
	if(opcion == 1)
	{
		getFloatPositive(aerolinea, "\nPrecio vuelo Aerolineas: ", "\nIngrese un precio valido: ", 10);
	} else
	{
		getFloatPositive(aerolineab, "\nPrecio vuelo Latam: ", "\nIngrese un precio valido: ", 10);
	}

}

void calcularCostos(float precio, float km, float *debito, float *credito, float *btc, float *pUnitario)
{
	*debito = subsFloat(precio, multFloat(precio, divFloat(10, 100)));
	*credito = sumFloat(precio,multFloat(precio,divFloat(25, 100)));
	*btc = divFloat(precio, BTC);
	*pUnitario = divFloat(precio, km);
}

void mostrarCostos(char aerolinea[],float precio, float debito, float credito, float btc, float pUnitario)
{
	printf("%s: $%.2f\na) Precio con tarjeta de debito: $%.2f\nb) Precio con tarjeta de credito: $%.2f\nc) Precio pagando con bitcoin : %.8f BTC\nd) Precio unitario: $%.2f\n", aerolinea, precio,debito, credito, btc, pUnitario);
}

void mostrarDiferencia(float aerolineaA, float aerolineaB)
{
	if(aerolineaA > aerolineaB)
	{
		printf("\n\nLa diferencia es: %.2ff\n", subsFloat(aerolineaA, aerolineaB));
	} else if (aerolineaA < aerolineaB){
		printf("\n\nLa diferencia es: %.2f\n", subsFloat(aerolineaB, aerolineaA));
	} else
	{
		printf("\nLa diferencia es: 0");
	}
}
