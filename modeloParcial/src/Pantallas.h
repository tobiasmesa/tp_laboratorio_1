/*
 * Pantallas.h
 *
 *  Created on: 3 may. 2022
 *      Author: tobic
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#ifndef PANTALLAS_H_
#define PANTALLAS_H_

#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

#define LCD 1
#define LED 0

typedef struct {
	int tipoPantalla;
	char nombre[51];
	char direccion[101];
	int precio;
	int isEmpty;
	int id;

}Pantalla;


void pa_inicializar(Pantalla array[], int TAM);
int pa_Alta(Pantalla array[], int TAM);
int pa_ObtenerIndexLibre(Pantalla array[], int TAM);
int pa_MostrarTodos(Pantalla array[], int TAM);
void pa_MostrarUno(Pantalla pantalla);
Pantalla pa_CargarDatos(void);
Pantalla pa_ModificarUno(Pantalla pantalla);
int pa_Modificacion(Pantalla array[], int TAM);
int pa_Baja(Pantalla array[], int TAM);
int pa_BuscarPorID(Pantalla array[], int TAM, int ID);




#endif /* PANTALLAS_H_ */
