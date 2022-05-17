/*
 * Producto.h
 *
 *  Created on: 14 may. 2022
 *      Author: tobic
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "utn.h"

#define MAX_CHARS_CADENAS 30
#define MAX_PRECIO 10000000000
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
#define TECNOLOGIA 1 // CATEGORIAS PRODUCTOS
#define VESTIMENTA 2
#define ELECTRODOMESTICOS 3


typedef struct {
	int idProducto;
	short int isEmpty;
	char nombreProducto[25];
	float precio;
	short int categoria;
	int stock;
	//Relaciones
	int idVendedor; // FK_VENDEDOR Cuando damos de alta un producto necesitamos el vendedor

}Producto;

void Producto_Inicializar(Producto array[], int TAM);
int Producto_ObtenerIndexLibre(Producto array[], int TAM);
int Producto_BuscarPorID(Producto array[], int TAM, int ID);
void Producto_MostrarUno(Producto producto);
int Producto_MostrarTodos(Producto array[], int TAM);
int Producto_MostrarDadosDeBaja(Producto array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int Producto_Sort(Producto array[], int TAM, int criterio);
int Producto_MostrarTodosOrdenados(Producto array[], int TAM);
//ABM
Producto Producto_CargarDatos(void);
Producto Producto_ModificarUno(Producto producto);


int Producto_Modificacion(Producto array[], int TAM);


int Producto_GetCategoria(void);


/** FIN CABECERAS DE FUNCION*/
#endif /* PRODUCTO_H_ */
