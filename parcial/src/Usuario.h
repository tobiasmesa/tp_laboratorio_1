/*
 * Usuario.h
 *
 *  Created on: 14 may. 2022
 *      Author: tobic
 */

#ifndef USUARIO_H_
#define USUARIO_H_

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#include "utn.h"

#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

#define USUARIO 0
#define ADMIN 1


//*** Usuario
typedef struct {
	int idUsuario;
	short int isEmpty;
	short int tipo;
	char correo[25];
	char password[10];
	char direccion[50];
	int codPostal;
	//Relaciones

} Usuario;
//***

/** INICIO CABECERAS DE FUNCION*/
void Usuario_Inicializar(Usuario array[], int TAM);
int Usuario_ObtenerIndexLibre(Usuario array[], int TAM);
int Usuario_BuscarPorID(Usuario array[], int TAM, int ID);
void Usuario_MostrarUno(Usuario usuario);
int Usuario_MostrarTodos(Usuario array[], int TAM);
int Usuario_MostrarDadosDeBaja(Usuario array[], int TAM);

int Usuario_getCodigoPostal(Usuario array[], int TAM, int id);


void crearUsuario(Usuario array[], int TAM, int tipo, char* correo, char* contrasena, int codigoPostal);
int validarMail(Usuario array[], int TAM, char* correo, char* password, short int* id);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int Usuario_Sort(Usuario array[], int TAM, int criterio);

//ABM
Usuario Usuario_CargarDatos(void);
Usuario Usuario_ModificarUno(Usuario usuario);
int Usuario_Alta(Usuario array[], int TAM);

int Usuario_Modificacion(Usuario array[], int TAM);
/** FIN CABECERAS DE FUNCION*/


#endif /* USUARIO_H_ */
