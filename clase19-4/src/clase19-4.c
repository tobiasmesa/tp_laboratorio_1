/*
 ============================================================================
 Name        : clase19-4.c
 Author      : Tobias Mesa
 Version     :
 Copyright   : TP1 Laboratorio 1
 Description :

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
//#include "Cliente.h"
#include "Producto.h"
#define TAM 200


int main(void) {
	setbuf(stdout, NULL);

	Producto aProductos[TAM];
	pr_iniciarArrayProducto(aProductos, TAM);
	pr_alta(aProductos, pr_buscarProductoLibre(aProductos, TAM));
	pr_alta(aProductos,  pr_buscarProductoLibre(aProductos, TAM));
	pr_imprimirArrayProductos(aProductos, TAM);


	return 0;
}









