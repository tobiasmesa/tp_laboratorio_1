/*
 * Producto.c
 *
 *  Created on: 14 may. 2022
 *      Author: tobic
 */


#include "Producto.h"


void Producto_Inicializar(Producto array[], int TAM) {
	int i;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			array[i].isEmpty = LIBRE;
		}
	}
}

int Producto_ObtenerIndexLibre(Producto array[], int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int Producto_BuscarPorID(Producto array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idProducto == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void Producto_MostrarUno(Producto producto) {
	//PRINTF DE UN SOLO producto
	printf("| %-20d | %-20s | %-20f | %-20d |\n", producto.idProducto, producto.nombreProducto, producto.precio, producto.stock);
}

int Producto_MostrarTodos(Producto array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t******* LISTADO PRODUCTOS **********");
	printf("%5s\n\n", "******TECNOLOGIA******"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)
	printf("| %-20s | %-20s | %-20s | %-20s \n", "ID", "NOMBRE","PRECIO ($)","STOCK");
	printf("| %-20s | %-20s | %-20s | %-20s \n", "------","------","------","-----");
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO && array[i].categoria == TECNOLOGIA && array[i].stock > 0) {
				//MUESTRO UN SOLO producto
				Producto_MostrarUno(array[i]);
				//CONTADOR DE producto
				cantidad++;
			}
		}
		printf("%5s\n\n", "******VESTIMENTA******"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)
		printf("| %-20s | %-20s | %-20s | %-20s \n", "ID", "NOMBRE","PRECIO ($)","STOCK");
		printf("| %-20s | %-20s | %-20s | %-20s \n", "------","------","------","-----");
		for (i = 0; i < TAM; i++) {
					//PREGUNTO POR SU ESTADO "OCUPADO"
					if (array[i].isEmpty == OCUPADO && array[i].categoria == VESTIMENTA && array[i].stock > 0) {
						//MUESTRO UN SOLO producto
						Producto_MostrarUno(array[i]);
						//CONTADOR DE producto
						cantidad++;
					}
				}
			printf("%5s\n\n", "******ELECTRODOMESTICOS******"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)
				printf("| %-20s | %-20s | %-20s | %-20s \n", "ID", "NOMBRE","PRECIO ($)","STOCK");
				printf("| %-20s | %-20s | %-20s | %-20s \n", "------","------","------","-----");
				for (i = 0; i < TAM; i++) {
							//PREGUNTO POR SU ESTADO "OCUPADO"
							if (array[i].isEmpty == OCUPADO && array[i].categoria == ELECTRODOMESTICOS && array[i].stock > 0) {
								//MUESTRO UN SOLO producto
								Producto_MostrarUno(array[i]);
								//CONTADOR DE producto
								cantidad++;
							}
						}
	}

	//SI CANTIDAD == 0 - NO HUBO producto PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int Producto_MostrarDadosDeBaja(Producto array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> producto\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO producto
				Producto_MostrarUno(array[i]);
				//CONTADOR DE producto
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO producto PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

Producto Producto_CargarDatos(void) {
	Producto auxiliar;

	utn_getString(auxiliar.nombreProducto, 25, "\nINGRESE EL NOMBRE DEL PRODUCTO: ", "\nERROR. REINGRESE: ", 3);
	utn_getNumeroFlotante(&auxiliar.precio, "\nINGRESE EL PRECIO DEL PRODUCTO: ", "\nERROR. REINGRESE: ", 0, MAX_PRECIO, 3);
	utn_getNumeroRange(&auxiliar.stock, "\nINGRESE LA CANTIDAD QUE HAY EN STOCK: ", "\nERROR. REINGRESE: ", 0, 9999, 3);

	return auxiliar;
}


Producto Producto_ModificarUno(Producto producto) {
	Producto auxiliar = producto;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}


int Producto_Modificacion(Producto array[], int TAM) {
	int rtn = 0;
	int idProducto;
	int index;
	int flag = 0;
	Producto auxiliar;

	//LISTO TODOS LOS producto
	if (Producto_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY producto DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY producto PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idProducto);

		//BUSCO INDEX POR ID EN ARRAY
		while (Producto_BuscarPorID(array, TAM, idProducto) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idProducto);
		}

		//OBTENGO INDEX DEL ARRAY DE producto A MODIFICAR
		index = Producto_BuscarPorID(array, TAM, idProducto);

		//LLAMO A FUNCION QUE MODIFICA producto
		auxiliar = Producto_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int Producto_Sort(Producto array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	Producto aux;

	/** EJEMPLO DE SORT CON ID DE producto
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)
	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].nombreProducto[0] > array[j].nombreProducto[0]) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].nombreProducto[0] < array[j].nombreProducto[0]) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}



int Producto_GetCategoria(void)
{
	system("cls");
	int rtn = -1;
	int aux;
	if(utn_getNumeroRange(&aux,
			"********************\n"
			"**** CATEGORIAS ****\n"
			"********************\n\n"
			"1. TECNOLOGIA"
			"\n2. VESTIMENTA"
			"\n3. ELECTRODOMESTICOS"
			"\n\nINGRESE UNA CATEGORIA: ", "\nINGRESE UNA CATEGORIA VALIDA: ", 1, 3, 3) == 0)
	{
		rtn = aux;
	}

	return rtn;
}

int Producto_MostrarTodosOrdenados(Producto array[], int TAM)
{
	int i;
	int rtn = 0;
	int cantidad = 0;
	Producto_Sort(array, TAM, -1);
	//CABECERA
	puts("\n\t******* LISTADO PRODUCTOS **********");
	printf("%5s\n\n", "******TECNOLOGIA******"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)
	printf("| %-20s | %-20s | %-20s | %-20s \n", "ID", "NOMBRE","PRECIO ($)","STOCK");
	printf("| %-20s | %-20s | %-20s | %-20s \n", "------","------","------","-----");
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO && array[i].categoria == TECNOLOGIA && array[i].stock > 0) {
				//MUESTRO UN SOLO producto
				Producto_MostrarUno(array[i]);
				//CONTADOR DE producto
				cantidad++;
			}
		}
		printf("%5s\n\n", "******VESTIMENTA******"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)
		printf("| %-20s | %-20s | %-20s | %-20s \n", "ID", "NOMBRE","PRECIO ($)","STOCK");
		printf("| %-20s | %-20s | %-20s | %-20s \n", "------","------","------","-----");
		for (i = 0; i < TAM; i++) {
					//PREGUNTO POR SU ESTADO "OCUPADO"
					if (array[i].isEmpty == OCUPADO && array[i].categoria == VESTIMENTA && array[i].stock > 0) {
						//MUESTRO UN SOLO producto
						Producto_MostrarUno(array[i]);
						//CONTADOR DE producto
						cantidad++;
					}
				}
			printf("%5s\n\n", "******ELECTRODOMESTICOS******"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)
				printf("| %-20s | %-20s | %-20s | %-20s \n", "ID", "NOMBRE","PRECIO ($)","STOCK");
				printf("| %-20s | %-20s | %-20s | %-20s \n", "------","------","------","-----");
				for (i = 0; i < TAM; i++) {
							//PREGUNTO POR SU ESTADO "OCUPADO"
							if (array[i].isEmpty == OCUPADO && array[i].categoria == ELECTRODOMESTICOS && array[i].stock > 0) {



								Producto_MostrarUno(array[i]);
								//CONTADOR DE producto
								cantidad++;
							}
						}
	}

	//SI CANTIDAD == 0 - NO HUBO producto PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}
	system("pause");

	return rtn;
}
