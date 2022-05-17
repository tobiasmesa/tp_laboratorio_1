/*
 * RelacionesComprasVentasTracking.h
 *
 *  Created on: 14 may. 2022
 *      Author: tobic
 */

#ifndef RELACIONESCOMPRASVENTASTRACKING_H_
#define RELACIONESCOMPRASVENTASTRACKING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include "Tracking.h"
#include "Usuario.h"
#include "Producto.h"

#define USUARIO 0 //TIPO USUARIOS
#define ADMIN 1

#define TECNOLOGIA 1 // CATEGORIAS PRODUCTOS
#define VESTIMENTA 2
#define ELECTRODOMESTICOS 3
#define MAX_STOCK 9999

#define NO_ENVIADO 0 // ESTADO DE LOS TRACKING
#define EN_VIAJE 1
#define ENTREGADO 2
#define CANCELADO 3



/**
 * \fn int Tracking_Alta(Tracking[], int, int, int, int, int, int)
 * \brief
 * Crea un alta de TRACKING
 * \param array
 * \param TAM
 * \param idVendedor
 * \param idComprador
 * \param idProducto
 * \param cantidadProductos
 * \param codPostal
 * \return -1 si salio mal y 0 si salio bien
 */
int Tracking_Alta(Tracking array[], int TAM, int idVendedor, int idComprador, int idProducto, int cantidadProductos,  int codPostal);
/**
 * \fn int Producto_Venta(Producto[], int, int*, int*, int*)
 * \brief
 * Da alta de una venta y genera un alta de producto, dandole a elegir al vendedor la id del producto y la cantidad
 * \param array
 * \param TAM
 * \param idVendedor
 * \param idProducto
 * \param cantProductos
 * \return -1 si falla y 0 si salio todo OK
 */
int Producto_Venta(Producto array[], int TAM, int* idVendedor, int* idProducto, int* cantProductos);
/**
 * \fn int Tracking_Baja(Tracking[], int, int)
 * \brief
 * Genera una baja de Tracking dandole de naja al producto que se encuentra en la venta.
 * \param array
 * \param TAM
 * \param idTracking
 * \return -1 si falla y 0 si salio todo OK
 */
int Tracking_Baja(Tracking array[], int TAM, int idTracking);
/**
 * \fn int Tracking_ListarComprasFinalizadas(Tracking[], int, int)
 * \brief
 * Lista las ventas finalizadas del vendedor
 * \param array
 * \param TAM
 * \param idVendedor
 * \return -1 si falla y 0 si salio todo OK
 */
int Tracking_ListarComprasFinalizadas(Tracking array[], int TAM, int idVendedor);

/**
 * \fn void Tracking_MostrarCompra(Tracking, Producto[], int)
 * \brief
 * Muestra una compra y el estado de esta
 * \param tracking
 * \param aProducto
 * \param TAM_P
 */
void Tracking_MostrarCompra(Tracking tracking, Producto aProducto[], int TAM_P);
/**
 * \fn int Tracking_MostrarTodasCompras(Tracking[], int, Producto[], int, int)
 * \brief
 * Muestra todas las compras de un comprador en particular
 * \param array
 * \param TAM
 * \param arrayP
 * \param TAM_P
 * \param idComprador
 * \return -1 si falla y 0 si salio todo OK
 */
int Tracking_MostrarTodasCompras(Tracking array[], int TAM, Producto arrayP[], int TAM_P ,int idComprador);
/**
 * \fn int Tracking_HayTracking(Tracking[], int, int)
 * \brief
 * Chequea que haya trackings disponibles
 * \param array
 * \param TAM
 * \param idComprador
 * \return 1 verdadero 0 falso
 */
int Tracking_HayTracking(Tracking array[], int TAM, int idComprador);
/**
 * \fn int Producto_Baja(Producto[], int, int, Tracking[], int)
 * \brief
 * Da la baja de un producto y un tracking
 * \param array
 * \param TAM
 * \param idProducto
 * \param arrayT
 * \param TAM_T
 * \return -1 si falla y 0 si salio todo OK
 */
int Producto_Baja(Producto array[], int TAM, int idProducto, Tracking arrayT[], int TAM_T);
/**
 * \fn int Producto_Alta(Producto[], int, short int, short int)
 * \brief
 * Da de alta un producto en el array productos
 * \param array
 * \param TAM
 * \param idVendedor
 * \param categoria
 * \return -1 si falla y 0 si salio todo OK
 */
int Producto_Alta(Producto array[], int TAM, short int idVendedor, short int categoria);
/**
 * \fn int Producto_listarStock(Producto[], int, short int)
 * \brief
 * Lista el stock que posee el vendedor
 * \param array
 * \param TAM
 * \param idVendedor
 * \return -1 si falla y 0 si salio todo OK
 */
int Producto_listarStock(Producto array[], int TAM, short int idVendedor);
/**
 * \fn void Productos_CargaForzada(Producto[], int, int, char*, float, int)
 * \brief
 * Funcion para probar y cargar datos forzadamente
 * \param array
 * \param TAM
 * \param categoria
 * \param nombre
 * \param precio
 * \param stock
 */
void Productos_CargaForzada(Producto array[], int TAM, int categoria, char* nombre, float precio, int stock);

/**
 * \fn int Usuario_Baja(Usuario[], int, int, Tracking[], int, Producto[], int)
 * \brief
 * Da de baja un usuario, sus respectivos productos a la venta y trackings generados por el
 * \param array
 * \param TAM
 * \param idUsuario
 * \param aTracking
 * \param TAM_T
 * \param aProductos
 * \param TAM_P
 * \return
 */
int Usuario_Baja(Usuario array[], int TAM, int idUsuario, Tracking aTracking[], int TAM_T, Producto aProductos[], int TAM_P);
#endif /* RELACIONESCOMPRASVENTASTRACKING_H_ */
