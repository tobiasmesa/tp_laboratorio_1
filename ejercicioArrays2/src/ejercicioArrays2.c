/******************************************************************************


1)Hacer un programa en donde el usuario ingrese un array de 5 numeros enteros,
  luego generar un menu en donde el usuario pueda elegir entre las siguientes funciones:

    a)Buscar el MAXIMO y mostrarlo (mostrar la cantidad de ocurrencias)
	b)Buscar el MINIMO y mostrarlo (mostrar la cantidad de ocurrencias)
	c)Calcular el PROMEDIO y mostrarlo
 	d)Ingresar un numero y mostrar si se encontro, cuantas veces y las posiciones del array

2)Hacer un programa que el usuario ingrese un array de 10 caracteres y mostrarlo con PRINTF(%C)

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void cargaArray(int array[], int tam);
void imprimirArray(int array[], int tam);
int maximoArray(int array[],int tam, int *maximo);

int main(void) {

	setbuf(stdout, NULL);

	int arrayIngresado[TAM];
	int maximo;
	int ocurrencias;
	char letra;

	cargaArray(arrayIngresado, TAM);
	printf("a)Buscar el MAXIMO y mostrarlo (mostrar la cantidad de ocurrencias)\nb)Buscar el MINIMO y mostrarlo (mostrar la cantidad de ocurrencias)\nc)Calcular el PROMEDIO y mostrarlo \nd)Ingresar un numero y mostrar si se encontro, cuantas veces y las posiciones del array\n");
	fflush(stdin);
	scanf("%c",&letra);

	switch(letra)
	{
	case 'a':
		ocurrencias = maximoArray(arrayIngresado, TAM, &maximo);
		printf("El maximo es: %d y las ocurrencias son: %d\n",maximo,ocurrencias);
		break;
	case 'b':
		break;
	case 'c':
		break;
	case 'd':
		break;
	default:
		break;

	}





	return EXIT_SUCCESS;
}


void cargaArray(int array[], int tam)
{
	int i;

	for(i = 0;i<tam;i++)
	{
		printf("%d - Ingrese el número",i+1);
		scanf("%d",&array[i]);
	}
}
void imprimirArray(int array[], int tam)
{
	int i;
	for(i = 0;i<tam;i++)
	{
		printf("%d\n",array[i]);
	}
}
int maximoArray(int array[],int tam, int *maximo)
{
	int i;
	int maximoIngresado;
	int contadorOcurrencias;

	contadorOcurrencias = 0;

	for(i = 0;i<tam;i++)
	{
		if(array[i]>maximoIngresado || i == 0)
		{
			maximoIngresado = array[i];
		}
	}
	for(i = 0;i<tam;i++)
	{
		if(array[i]==maximoIngresado)
		{
			contadorOcurrencias++;
		}
	}
	*maximo = maximoIngresado;

	return contadorOcurrencias;
}





