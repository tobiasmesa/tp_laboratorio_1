/*
 * Producto.h
 *
 *  Created on: 26 abr. 2022
 *      Author: tobic
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1


typedef struct {
	int dia;
	int mes;
	int ano;
} Fecha;


typedef struct {
	int id;
	char nombre[31];
	char descripcion[201];
	int precio;
	int isEmpty;
	Fecha fechaVencimiento;
} Producto;




int pr_imprimirArrayProductos (Producto arrayProductos[], int tam);
int pr_imprimirProducto(Producto produc);

int pr_iniciarArrayProducto(Producto arrayProductos[], int tam);
int pr_cargarIsEmpty(Producto* produc);

int pr_alta(Producto arrayProductos[],int indice);

/**
 * @fn int pr_buscarProductoLibre(Producto[], int)
 * @brief Retorna la primer posicion que encuentra LIBRE en el array

 * @param arrayProductos
 * @param tam
 * @return Retorna la primer posicion que encuentra LIBRE en el array
 */
int pr_buscarProductoLibre(Producto arrayProductos[],int tam);
Producto pr_CargarUnProducto(void);



int pr_baja(Producto arrayProductos[], int indice);
#endif /* PRODUCTO_H_ */
