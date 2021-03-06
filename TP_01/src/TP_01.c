/*
 ============================================================================
 Name        : TP_01.c
 Author      : Tobias Mesa
 Version     :
 Copyright   : Your copyright notice
 Description : TP-01 Cambiar las variables VOID -
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "tp01_utilidades.h"


int main(){
	setbuf(stdout, NULL);
	int opcion;
	float kmIngresados = 0;
	/**
		 Variables de aerolineas*/
	float precioAerolineas = 0;
	float btcAero = 0;
	float pUnitarioAero = 0;
	float creditoAero = 0;
	/**
		 Variables de latam*/
	float precioLatam = 0;
	float debitoAero = 0;
	float debitoLatam = 0;
	float btcLatam = 0;
	float pUnitarioLatam = 0;
	float creditoLatam = 0;

	int rtn;

	do
	{
		printf("--------------------------------\n");
		printf("1. Ingresar Kilometros. (KM = %.0f KM)\n", kmIngresados);
		printf("2. Ingresar Precio de Vuelos: (Aerolineas= $%.2f, Latam= $%.2f)\n", precioAerolineas, precioLatam);
		printf("3. Calcular todos los costos\n");
		printf("4. Informar Resultados\n");
		printf("5. Carga forzada de datos\n");
		printf("6. Salir\n");
		printf("--------------------------------\n");
		getIntRange("\nIngrese una opcion: ", 3, 1, 6, "\nIngrese una opcion valida: ", &opcion);
		system("cls");

		switch(opcion)
		{
			case 1:
				do {
				rtn = getFloatPositive(&kmIngresados, "\nIngresar Kilometros: ", "\nIngrese una cantidad valida: ", 3);
				} while (rtn != 0);
				break;
			case 2:
				precioVuelos(&precioAerolineas, &precioLatam);
				break;
			case 3:
				if(precioAerolineas != 0 && precioLatam != 0)
				{
					calcularCostos(precioAerolineas, kmIngresados, &debitoAero, &creditoAero, &btcAero, &pUnitarioAero);
					calcularCostos(precioLatam, kmIngresados, &debitoLatam, &creditoLatam, &btcLatam, &pUnitarioLatam);


				} else if(kmIngresados == 0)
				{

					printf("\nLe falta cargar los km!\n");
					system("pause");

				} else
				{
					printf("\nLe falta cargar los precios de las aerolineas!!\n");
					system("pause");
				}
				break;
			case 4:
				if(debitoAero != 0 && debitoLatam != 0)
				{
					system("cls");
					printf("\nKM ingresados: %.2f\n",kmIngresados);
					mostrarCostos("\nAerolineas", precioAerolineas, debitoAero, creditoAero, btcAero, pUnitarioAero);
					mostrarCostos("\nLatam", precioLatam, debitoLatam, creditoLatam, btcLatam, pUnitarioLatam);
					mostrarDiferencia(precioAerolineas, precioLatam);
					system("pause");
				} else
				{
					printf("\nDebe calcular los costos en el paso 3!\n");
				}

				break;
			case 5:

				break;
			default:
				return 0;
		}

	} while(opcion != 6);


	return 0;
}


