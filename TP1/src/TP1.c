
/*
 ============================================================================
 Name        : TP_01.c
 Author      : Tobias Mesa
 Version     :
 Copyright   : Your copyright notice
 Description : TP-01
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
		printf("--------------------------------\n1. Ingresar Kilometros (KM = %.0f KM)\n2. Ingresar Precio de Vuelos: (Aerolineas= $%.2f, Latam= $%.2f)\n3. Calcular todos los costos\n4. Informar Resultados\n5. Carga forzada de datos\n6. Salir\n--------------------------------\n", kmIngresados, precioAerolineas, precioLatam);
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
				system("cls");
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
					printf("\nKM ingresados: %.2f KM\n",kmIngresados);
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
				kmIngresados = 7090;
				precioAerolineas = 162965;
				precioLatam = 159339;
				calcularCostos(precioAerolineas, kmIngresados, &debitoAero, &creditoAero, &btcAero, &pUnitarioAero);
				calcularCostos(precioLatam, kmIngresados, &debitoLatam, &creditoLatam, &btcLatam, &pUnitarioLatam);
				system("cls");
				printf("\nKM ingresados: %.2f KM\n",kmIngresados);
				mostrarCostos("\nAerolineas", precioAerolineas, debitoAero, creditoAero, btcAero, pUnitarioAero);
				mostrarCostos("\nLatam", precioLatam, debitoLatam, creditoLatam, btcLatam, pUnitarioLatam);
				mostrarDiferencia(precioAerolineas, precioLatam);
				system("pause");
				break;
			default:
				return 0;
		}

	} while(opcion != 6);

	return 0;
}
