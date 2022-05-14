/*
 * Pantallas.c
 *
 *  Created on: 3 may. 2022
 *      Author: tobic
 */

#include "Pantallas.h"

static int pa_ObtenerID(void);
static int pa_ObtenerID(void) {
	static int pa_idIncremental = 0;
	return pa_idIncremental++;
}

void pa_inicializar(Pantalla array[], int TAM)
{
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

int pa_ObtenerIndexLibre(Pantalla array[], int TAM) {
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

int pa_Alta(Pantalla array[], int TAM) {
	int rtn = 0;
	Pantalla aux;

	//BUSCO ESPACIO EN ARRAY
	int index = pa_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Gen AUXILIAR
		aux = pa_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		aux.id = pa_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		aux.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = aux;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

Pantalla pa_CargarDatos(void) {
	Pantalla auxiliar;
	utn_getString(auxiliar.nombre, sizeof(auxiliar.nombre), "\nIngrese el nombre de la pantalla: ", "\nIngrese el nombre correctamente!", 3);
	utn_getString(auxiliar.direccion, sizeof(auxiliar.direccion), "\nIngrese la direccion de la pantalla: ", "\nIngrese la direccion correctamente: ", 3);
	utn_getNumeroRange(&auxiliar.tipoPantalla, "\nIngrese el tipo de pantalla (LED [0] / LCD [1]): ", "\nIngrese otra vez el tipo(LED [0] / LCD [1]: ", 0, 1, 3);
	utn_getNumeroRange(&auxiliar.precio, "\nIngrese el precio de la pantalla: ", "\nIngrese el precio correctamente: ", 0, 1000000, 3);
	return auxiliar;
}

void pa_MostrarUno(Pantalla pantalla) {
	//PRINTF DE UN SOLO Gen
	printf("%5d      %s         %d\n", pantalla.id, pantalla.nombre, pantalla.precio);
}

int pa_MostrarTodos(Pantalla array[], int TAM)
{
	int i;
		int rtn = 0;
		int cantidad = 0;

		//CABECERA
		puts("\n\t> LISTADO PANTALLAS");
		printf("   ID      NOMBRE      PRECIO\n\n"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

		//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
		if (array != NULL && TAM > 0) {
			//RECORRO TODO EL ARRAY
			for (i = 0; i < TAM; i++) {
				//PREGUNTO POR SU ESTADO "OCUPADO"
				if (array[i].isEmpty == OCUPADO) {
					//MUESTRO UN SOLO Gen
					pa_MostrarUno(array[i]);
					//CONTADOR DE Gen
					cantidad++;
				}
			}
		}

		//SI CANTIDAD == 0 - NO HUBO Gen PARA MOSTRAR (ARRAY SIN ALTAS)
		if (cantidad > 0) {
			rtn = 1;
		}

		return rtn;
}

Pantalla pa_ModificarUno(Pantalla pantalla) {
	Pantalla auxiliar = pantalla;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	auxiliar = pa_CargarDatos();
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int pa_Modificacion(Pantalla array[], int TAM) {
	int rtn = 0;
	int id;
	int index;
	int flag = 0;
	Pantalla auxiliar;

	//LISTO TODOS LAS PANTALLAS
	if (pa_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY PANTALLAS DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/

		utn_getNumeroRange(&id, "\nIngrese la id: ", "\nReingrese el id: ", 0, 100, 3);

		//BUSCO INDEX POR ID EN ARRAY
		while (pa_BuscarPorID(array, TAM, id) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			utn_getNumeroRange(&id, "\nIngrese la id a dar de baja: ", "\nReingrese el id: ", 0, 100, 3);
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A MODIFICAR
		index = pa_BuscarPorID(array, TAM, id);

		//LLAMO A FUNCION QUE MODIFICA Gen
		auxiliar = pa_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}


int pa_BuscarPorID(Pantalla array[], int TAM, int ID)
{
	int rtn = -1;
		int i;

		//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
		if (array != NULL && TAM > 0) {
			//RECORRO TODO EL ARRAY
			for (i = 0; i < TAM; i++) {
				//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
				if (array[i].id == ID && array[i].isEmpty == OCUPADO) {
					//SI ENCONTRE EL ID
					//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
					rtn = i;
					break;
				}
			}
		}

		return rtn;
}



int pa_Baja(Pantalla array[], int TAM) {
	int rtn = 0;
	int id;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Gen
	if (pa_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		utn_getNumeroRange(&id, "\nIngrese la id a dar de baja: ", "\nReingrese el id: ", 0, 100, 3);


		//BUSCO INDEX POR ID EN ARRAY
		while (pa_BuscarPorID(array, TAM, id) == -1)
		{
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			utn_getNumeroRange(&id, "\nIngrese la id a dar de baja: ", "\nReingrese el id: ", 0, 100, 3);

		}

		//OBTENGO INDEX DEL ARRAY DE Gen A DAR DE BAJA
		index = pa_BuscarPorID(array, TAM, id);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}
