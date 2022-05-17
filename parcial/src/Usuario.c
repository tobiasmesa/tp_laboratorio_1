/*
 * Usuario.c
 *
 *  Created on: 14 may. 2022
 *      Author: tobic
 */

#include "Usuario.h"


static int Usuario_ObtenerID(void);
static int Usuario_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION Usuario_ObtenerID();
	static int usuario_idIncremental = 0;
	return usuario_idIncremental++;
}

void Usuario_Inicializar(Usuario array[], int TAM) {
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

int Usuario_ObtenerIndexLibre(Usuario array[], int TAM) {
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

int Usuario_BuscarPorID(Usuario array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idUsuario == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void Usuario_MostrarUno(Usuario usuario) {

	char state[20];
	switch(usuario.isEmpty)
	{
	case 0:
		strcpy(state,"LIBRE");
		break;
	case 1:
		strcpy(state,"OCUPADO");
		break;
	case -1:
		strcpy(state,"BAJA");
		break;
	default:
		break;
	}
	printf("| %-20d | %-20s | %-20s\n", usuario.idUsuario, usuario.correo, state);

}

int Usuario_MostrarTodos(Usuario array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t USUARIOS");
	printf("| %-20s | %-20s | %-20s \n", "ID", "MAIL","ESTADO");//AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO || array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO usuario
				Usuario_MostrarUno(array[i]);
				//CONTADOR DE usuario
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO usuario PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}
	return rtn;
}

int Usuario_MostrarDadosDeBaja(Usuario array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> usuario\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO usuario
				Usuario_MostrarUno(array[i]);
				//CONTADOR DE usuario
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO usuario PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

Usuario Usuario_CargarDatos(void) {
	Usuario auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	auxiliar.tipo = USUARIO;
	utn_getEmail(auxiliar.correo, sizeof(auxiliar.correo), "\nIngrese correo a registrar: ", "\nIngrese un correo valido: ", 3);
	utn_getAlfaNum(auxiliar.password, sizeof(auxiliar.password), "\nIngrese contrasena a registrar: ", "\nIngrese una contrasena valida: ", 3);
	utn_getAlfaNum(auxiliar.direccion, sizeof(auxiliar.direccion), "\nIngrese su direccion: ", "\nIngrese una direccion valida", 3);
	utn_getNumeroRange(&auxiliar.codPostal, "Ingrese su codigo postal: ", "Ingrese un codigo postal valido: ", 0, 9999, 3);



	return auxiliar;
}

Usuario Usuario_ModificarUno(Usuario usuario) {
	Usuario auxiliar = usuario;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int Usuario_Alta(Usuario array[], int TAM) {
	int rtn = 0;
	Usuario auxUsuario;

	//BUSCO ESPACIO EN ARRAY
	int index = Usuario_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO usuario AUXILIAR
		auxUsuario = Usuario_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxUsuario.idUsuario = Usuario_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxUsuario.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxUsuario;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}



int Usuario_Modificacion(Usuario array[], int TAM) {
	int rtn = 0;
	int idUsuario;
	int index;
	int flag = 0;
	Usuario auxiliar;

	//LISTO TODOS LOS usuario
	if (Usuario_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY usuario DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY usuario PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idUsuario);

		//BUSCO INDEX POR ID EN ARRAY
		while (Usuario_BuscarPorID(array, TAM, idUsuario) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idUsuario);
		}

		//OBTENGO INDEX DEL ARRAY DE usuario A MODIFICAR
		index = Usuario_BuscarPorID(array, TAM, idUsuario);

		//LLAMO A FUNCION QUE MODIFICA usuario
		auxiliar = Usuario_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int Usuario_Sort(Usuario array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	Usuario aux;

	/** EJEMPLO DE SORT CON ID DE usuario
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
						if (array[i].idUsuario > array[j].idUsuario) {
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
						if (array[i].idUsuario < array[j].idUsuario) {
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

void crearUsuario(Usuario array[], int TAM, int tipo, char* correo, char* contrasena, int codigoPostal)
{
	Usuario auxUsuario;
	//BUSCO ESPACIO EN ARRAY
	int index = Usuario_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO usuario AUXILIAR
		strcpy(auxUsuario.correo,correo);
		strcpy(auxUsuario.password,contrasena);
		strcpy(auxUsuario.direccion,"Lomass");
		auxUsuario.codPostal = codigoPostal;

		auxUsuario.tipo = tipo;
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxUsuario.idUsuario = Usuario_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxUsuario.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxUsuario;
		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
	}

}

int validarMail(Usuario array[], int TAM, char* correo, char* password, short int* id)
{
	int rtn = -1;
		for(int i = 0; i < TAM; i++)
		{
			if(strcmp(array[i].correo, correo) == 0)
			{
				if(strcmp(array[i].password, password) == 0)
				{
					*id = array[i].idUsuario;

					if(array[i].isEmpty == -1)
					{
						return rtn;
					}

					if(array[i].tipo == ADMIN)
					{
						rtn = 0; //RETORNA 0 SI ES LOGIN CORRECTO Y ADMIN
					} else
					{
						rtn = 1; //RETORNA 1 SI ES LOGIN CORRECTO Y USER
					}

				}
			}
		}

	return rtn;
}

int Usuario_getCodigoPostal(Usuario array[], int TAM, int id)
{
	int rtn = -1;
	int index;
	if(array != NULL && TAM > 0 && id > -1)
	{
		index = Usuario_BuscarPorID(array, TAM, id);
		if(index != -1)
		{
			rtn = array[index].codPostal;
		}
	}

	return rtn;
}
