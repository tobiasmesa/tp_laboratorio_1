/*
 * RelacionesComprasVentasTracking.c
 *
 *  Created on: 14 may. 2022
 *      Author: tobic
 */

#include "RelacionesComprasVentasTracking.h"


static int Tracking_ObtenerID(void);
static int Tracking_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION Tracking_ObtenerID();
	static int tracking_idIncremental = 1;
	return tracking_idIncremental++;
}


int Tracking_Alta(Tracking array[], int TAM, int idVendedor, int idComprador, int idProducto, int cantidadProductos, int codPostal) {
	int rtn = 0;
	Tracking auxtracking;

	//BUSCO ESPACIO EN ARRAY
	int index = Tracking_ObtenerIndexLibre(array, TAM);
	int distancia;
	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {

		auxtracking.idComprador = idComprador;
		auxtracking.idVendedor = idVendedor;
		auxtracking.idProducto = idProducto;
		auxtracking.cantidad = cantidadProductos;
		auxtracking.estado = EN_VIAJE;

		if(codPostal < 1000 && codPostal >= 1)
		{
			distancia = 20;
		} else if(codPostal < 3000 && codPostal >= 1001)
		{
			distancia = 30;
		} else if(codPostal < 5000 && codPostal >= 3001)
		{
			distancia = 50;
		} else if (codPostal < 8000 && codPostal >= 5001)
		{
			distancia = 80;
		} else if (codPostal < 9999 && codPostal >= 150)
		{
			distancia = 150;
		} else
		{
			distancia = 0;
		}

		auxtracking.distanciaKM = distancia;
		auxtracking.horaLlegada = time_Add((distancia/10)*20);
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxtracking.idTracking = Tracking_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxtracking.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxtracking;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}




int Tracking_ListarComprasFinalizadas(Tracking array[], int TAM, int idVendedor)
{
	int rtn = -1;
	if(array != NULL && TAM > 0 && idVendedor > -1)
	{
		for(int i = 0; i < TAM; i++)
		{
			if(array[i].idVendedor == idVendedor && (array[i].estado == CANCELADO || array[i].estado == ENTREGADO))
			{
				Tracking_MostrarUno(array[i]);
				rtn = 0;
			}
		}
	}
	return rtn;
}

/******** PRODUCTOS ********/


static int Producto_ObtenerID(void);

static int Producto_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION Producto_ObtenerID();
	static int producto_idIncremental = 1;
	return producto_idIncremental++;
}

int Producto_Alta(Producto array[], int TAM, short int idVendedor, short int categoria) {
	int rtn = 0;
	Producto auxproducto;

	//BUSCO ESPACIO EN ARRAY
	int index = Producto_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO producto AUXILIAR
		auxproducto = Producto_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxproducto.idProducto = Producto_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxproducto.idVendedor = idVendedor;
		auxproducto.isEmpty = OCUPADO;
		auxproducto.categoria = categoria;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxproducto;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

int Producto_listarStock(Producto array[], int TAM, short int idVendedor)
{
	int rtn = -1;
	char categoria[20];
	printf("| %-20s | %-20s | %-20s | %-20s | %-20s |\n", "NOMBRE","PRECIO ($)","STOCK","ID VENDEDOR", "CATEGORIA");
	printf("| %-20s | %-20s | %-20s | %-20s | %-20s |\n", "------","------","-----","-----------", "---------");
	//Llamar funcion mostrar de PRODUCTOS
	if(array != NULL && TAM > 0 && idVendedor > -1)
	{
		for(int i = 0; i < TAM; i++)
		{
			if(array[i].idVendedor == idVendedor && array[i].isEmpty == OCUPADO)
			{
				if(array[i].stock > 0)
				{
					switch(array[i].categoria)
					{
						case 1:
							strcpy(categoria,"TECNOLOGIA");
							break;
						case 2:
							strcpy(categoria,"VESTIMENTA");
							break;
						case 3:
							strcpy(categoria,"ELECTRODOMESTICO");
							break;
						default:
							break;
					}
					printf("| %-20s | %-20f | %-20d | %-20d | %-20s |\n", array[i].nombreProducto, array[i].precio, array[i].stock, array[i].idVendedor, categoria);
				rtn = 0;
				}
			}

		}
	}
	system("pause");
	return rtn;
}

void Productos_CargaForzada(Producto array[], int TAM, int categoria, char* nombre, float precio, int stock)
{

		Producto auxproducto;

		//BUSCO ESPACIO EN ARRAY
		int index = Producto_ObtenerIndexLibre(array, TAM);

		//SI INDEX == -1 ARRAY LLENO
		//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
		if (index != -1) {
			//PIDO DATOS - CARGO producto AUXILIAR
			strcpy(auxproducto.nombreProducto,nombre);
			auxproducto.precio = precio;
			auxproducto.stock = stock;
			//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
			auxproducto.idProducto = Producto_ObtenerID();

			//CAMBIO SU ESTADO A "OCUPADO"
			auxproducto.idVendedor = 2;
			auxproducto.isEmpty = OCUPADO;
			auxproducto.categoria = categoria;
			//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
			array[index] = auxproducto;

			//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		}

}

int Producto_Venta(Producto array[], int TAM, int* idVendedor, int* idProducto, int* cant)
{
	int rtn = 0;
	int idProductoSeleccionado;
	int indexProductoSeleccionado;
	int cantProductos;
	float total = 0;
	int respuesta;

	Producto_MostrarTodos(array, TAM);
	utn_getNumeroRange(&idProductoSeleccionado, "\nSELECCIONE ID DEL PRODUCTO A COMPRAR: ", "\nERROR. REINGRESE: ", 0, TAM, 3); //CALCULAR SI ES POSIBLE COMPRAR ESA CANTIDAD DEL PRODUCTO
	indexProductoSeleccionado = Producto_BuscarPorID(array, TAM, idProductoSeleccionado);
	if (indexProductoSeleccionado != -1 && array[indexProductoSeleccionado].stock > 0) {
		utn_getNumeroRange(&cantProductos,
				"\nSELECCIONE CANTIDAD DEL PRODUCTO A COMPRAR ([0] PARA SALIR): ",
				"\nERROR. REINGRESE: ", 0, MAX_STOCK, 3);
		if(cantProductos == 0)
		{
			return 0;
		}
		system("cls");
		total = array[indexProductoSeleccionado].precio * cantProductos;
		printf("EL TOTAL DE LA COMPRA ES: $%.2f", total);
		utn_getNumeroRange(&respuesta, "\nCONFIRMA LA COMPRA? [SI (1) / NO (0)]: ", "\nINGRESE UNA RESPUESTA VALIDA: ", 0, 1, 3);
		if ((array[indexProductoSeleccionado].stock - cantProductos) >= 0 && respuesta == 1) {
			array[indexProductoSeleccionado].stock =  array[indexProductoSeleccionado].stock - cantProductos;
			*idVendedor = array[indexProductoSeleccionado].idVendedor;
			*idProducto = array[indexProductoSeleccionado].idProducto;
			*cant = cantProductos;
			rtn = 0;
		} else {
			puts("SELECCIONE UNA CANTIDAD VALIDA !");
			rtn = -1;
		}
	}



	return rtn;
}


void Tracking_MostrarCompra(Tracking tracking, Producto aProducto[], int TAM_P)
{
	char estadoCompra[10];
	switch(tracking.estado)
	{
		case 0:
			strcpy(estadoCompra, "NO ENVIADO");
			break;
		case 1:
			strcpy(estadoCompra, "EN VIAJE");
			break;
		case 2:
			strcpy(estadoCompra, "ENTREGADO");
			break;
		case 3:
			strcpy(estadoCompra, "CANCELADO");
			break;
		default:
			break;
	}

	printf("\n| %-20d | %-20d | %-20s | %-20f | %-20s | %-20s ", tracking.idTracking, tracking.idProducto, aProducto[Producto_BuscarPorID(aProducto, TAM_P , tracking.idProducto)].nombreProducto, aProducto[Producto_BuscarPorID(aProducto, TAM_P , tracking.idProducto)].precio,ctime(&tracking.horaLlegada), estadoCompra);
	printf("----------------------------\n");
}



int Tracking_MostrarTodasCompras(Tracking array[], int TAM, Producto arrayP[],int TAM_P ,int idComprador)
{
	int rtn = -1;
	if(array != NULL && TAM > 0 && idComprador > -1)
	{
		puts("\n\t******* COMPRAS **********\n"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)
		printf("\n| %-20s | %-20s | %-20s | %-20s | %-20s| %-20s", "ID TRACKING", "ID PRODUCTO","NOMBRE PRODUCTO","PRECIO ($)", "HORA DE LLEGADA", "ESTADO");

		//
		for(int i = 0; i < TAM; i++)
		{
			if(array[i].idComprador == idComprador && (array[i].isEmpty == OCUPADO || array[i].isEmpty == BAJA))
			{
				Tracking_MostrarCompra(array[i], arrayP, TAM_P);
			}
		}
	}
	return rtn;
}

int Tracking_HayTracking(Tracking array[], int TAM, int idComprador)
{
	int rtn = 0;
	for(int i = 0; i < TAM; i++)
	{
		if((array[i].isEmpty == OCUPADO  || array[i].isEmpty == BAJA) && array[i].idComprador == idComprador)
		{
			rtn = 1; // SI TIENE TRACKINGS SALE 1
			break;
		}
	}
	return rtn;
}


int Producto_Baja(Producto array[], int TAM, int idProducto, Tracking arrayT[], int TAM_T) {
	int rtn = 0;
	int index;
	int idTracking;

	if(array != NULL && TAM > 0 && idProducto > 0)
	{
		index = Producto_BuscarPorID(array, TAM, idProducto);
			if(index != -1)
			{
				array[index].isEmpty = BAJA;
				array[index].stock = 0;

				for(int i = 0; i < TAM_T; i++)
				{
					if(array[index].idProducto == arrayT[i].idProducto)
					{
						idTracking = arrayT[i].idTracking;
					}
				}

				Tracking_Baja(arrayT, TAM_T, idTracking);
				rtn = 0;
			}
	}

	return rtn;
}



int Tracking_Baja(Tracking array[], int TAM, int idTracking) // SE ELIGE LA ID DEL TRACKING PORQUE MUCHAS COMPRAS PUEDEN TENER EL MISMO ID DE PRODUCTO
{
	int rtn = -1;
	int index = Tracking_BuscarPorID(array, TAM , idTracking);
	if(index != -1)
	{
		array[index].isEmpty = BAJA;
		array[index].estado = CANCELADO;
		rtn = 0;
	}

	return rtn;
}

int Usuario_Baja(Usuario array[], int TAM, int idUsuario, Tracking aTracking[], int TAM_T, Producto aProductos[], int TAM_P) {
	int rtn = -1;
	int index;
	int idTracking;
	int idProducto;
	index = Usuario_BuscarPorID(array, TAM_P, idUsuario);
	if(index != -1)
	{
		array[index].isEmpty = BAJA;
		for(int i = 0; i < TAM_T; i++)
		{
			if(idUsuario == aTracking[i].idComprador || idUsuario == aTracking[i].idVendedor)
			{
				idTracking = aTracking[i].idTracking;
				Tracking_Baja(aTracking, TAM_T, idTracking);

			}
		for(int i = 0; i < TAM_P; i++)
		{
			if(idUsuario == aProductos[i].idVendedor)
			{
				idProducto = aProductos[i].idProducto;
				Producto_Baja(aProductos, TAM_P, idProducto, aTracking, TAM_T);
			}
		}
		}
	}


	return rtn;
}
