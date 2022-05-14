/*
 * Contrataciones.h
 *
 *  Created on: 3 may. 2022
 *      Author: tobic
 */

#ifndef CONTRATACIONES_H_
#define CONTRATACIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

//*** Contrataciones
typedef struct {
	int id;
	int isEmpty;
	int FK_idPantalla;
	int cuit;
	int cantidadDias;
	char nombreArchivoVideo[MAX_CHARS_CADENAS];
} Contrataciones;
//***

/** INICIO CABECERAS DE FUNCION*/
void Contrataciones_Inicializar(Contrataciones array[], int TAM);
int Contrataciones_ObtenerIndexLibre(Contrataciones array[], int TAM);
int Contrataciones_BuscarPorID(Contrataciones array[], int TAM, int ID);
void Contrataciones_MostrarUno(Contrataciones Gen);
int Contrataciones_MostrarTodos(Contrataciones array[], int TAM);
int Contrataciones_MostrarDadosDeBaja(Contrataciones array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int Contrataciones_Sort(Contrataciones array[], int TAM, int criterio);

//ABM
Contrataciones Contrataciones_CargarDatos(void);
Contrataciones Contrataciones_ModificarUno(Contrataciones Gen);
int Contrataciones_Alta(Contrataciones array[], int TAM);
int Contrataciones_Baja(Contrataciones array[], int TAM);
int Contrataciones_Modificacion(Contrataciones array[], int TAM);

#endif /* CONTRATACIONES_H_ */
