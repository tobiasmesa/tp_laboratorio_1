/*
 ============================================================================
 Name        : parcial.c
 Author      : Tobias Mesa
 Version     : 1.0
 Copyright   : Parcial 1 - DIV K
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "RelacionesComprasVentasTracking.h"
#include "utn.h"

#define C_PRODUCTOS 100
#define C_USUARIOS 100
#define C_TRACKINGS 500

int main(void) {

	setbuf(stdout, NULL);

	Producto aProductos[C_PRODUCTOS];
	Tracking aTrackings[C_TRACKINGS];
	Usuario aUsuarios[C_USUARIOS];

	Producto_Inicializar(aProductos, C_PRODUCTOS);
	Tracking_Inicializar(aTrackings, C_TRACKINGS);
	Usuario_Inicializar(aUsuarios, C_USUARIOS);

	int option;
	int suboption;
	char mail[30];
	char contrasena[20];
	int validacion;

	int categoria;
	short int idSesion;
	int rtn;
	int subopcion2;
	char opcion[2];


	crearUsuario(aUsuarios, C_USUARIOS, 1, "admin", "admin", 1002);
	crearUsuario(aUsuarios, C_USUARIOS, 0, "user@mail.com", "user", 1232);
	crearUsuario(aUsuarios, C_USUARIOS, 0, "user2@mail.com", "user2", 90);

	Productos_CargaForzada(aProductos, C_PRODUCTOS, TECNOLOGIA, "JOYSTICK_PS5", 12300.59, 2);
	Productos_CargaForzada(aProductos, C_PRODUCTOS, VESTIMENTA, "REMERAS_TAL", 11300, 20);
	Productos_CargaForzada(aProductos, C_PRODUCTOS, ELECTRODOMESTICOS, "PARLANTES_SONY", 3000, 6);
	Productos_CargaForzada(aProductos, C_PRODUCTOS, TECNOLOGIA, "Playstation5", 8000.59, 2);
	Productos_CargaForzada(aProductos, C_PRODUCTOS, VESTIMENTA, "AIR_FORCE1", 18000, 20);
	Productos_CargaForzada(aProductos, C_PRODUCTOS, ELECTRODOMESTICOS, "SMART_TV", 60000, 6);

	do {
		utn_getNumeroRange(&option,
				"\n****************************"
				"\n** 1er EXAMEN LAB I - 1H ***"
				"\n****************************\n\n"
				"1) INGRESAR\n"
				"2) REGISTRARSE\n\n"
				"0) SALIR\n\n"
				"INGRESE UNA OPCION: ", "\nINGRESE UNA OPCION VALIDA: ", 0, 2,
				3);

		system("cls");

		if (option == 1) {
			if (utn_getEmail(mail, sizeof(mail), "\nINGRESE EL CORREO: ",
					"\nINGRESE UN CORREO VALIDO: ", 3) == 0) {
				if (utn_getAlfaNum(contrasena, sizeof(contrasena),
						"\nINGRESE SU CONTRASENA: ",
						"\nINGRESE UNA CONTRASENA VALIDA: ", 3) == 0) {
					validacion = validarMail(aUsuarios, C_USUARIOS, mail,
							contrasena, &idSesion);
					if (validacion == 1) {
						do {
							system("cls");
							utn_getNumeroRange(&suboption,
									"****************************"
											"\n** 1er EXAMEN LAB I - 1H ***"
											"\n********* USUARIO **********"
											"\n****************************\n\n"
											"1) COMPRAR\n"
											"2) VENDER\n"
											"3) ESTADO DE COMPRAS\n"
											"4) ESTADO DE VENTAS\n\n"
											"0) SALIR\n\n"
											"INGRESE UNA OPCION: ",
									"\nERROR INGRESE UNA OPCION VALIDA: ", 0, 4,
									3);


							switch (suboption) {
							case 1: //Alta a un tracking PASAR ID DE COMPRADOR Y VENDEDOR
								do {

										int idProducto;
										int idVendedor;
										int cantidadProductos;
										int codigoPostal = Usuario_getCodigoPostal(aUsuarios, C_USUARIOS, idSesion); // GET CODIGO POSTAL

										rtn = Producto_Venta(aProductos, C_PRODUCTOS, &idVendedor, &idProducto, &cantidadProductos);
										Tracking_Alta(aTrackings, C_TRACKINGS, idVendedor, idSesion, idProducto, cantidadProductos, codigoPostal);

									}	while(rtn != 0);

									Tracking_refrescarEnvios(aTrackings, C_TRACKINGS);

								break;
							case 2: //DAR DE ALTA UN PRODUCTO Y SELECCIONAR A QUE CATEGORIA PERTENECE (GUARDAR ID_VENDEDOR)
								categoria = Producto_GetCategoria();
								if (categoria != -1) {
									Producto_Alta(aProductos, C_PRODUCTOS, idSesion,
											categoria);
								}
								break;
							case 3:
								Tracking_refrescarEnvios(aTrackings, C_TRACKINGS);
								if(Tracking_HayTracking(aTrackings, C_TRACKINGS, idSesion) != 1){
									puts("NO TIENE COMPRAS !");
									system("pause");
								}else{
									Tracking_MostrarTodasCompras(aTrackings,
											C_TRACKINGS, aProductos,
											C_PRODUCTOS, idSesion);
									//DAR DE BAJA UN TRACKING QUE SE ENCUENTRA EN VIAJE y OPCION SALIR
									utn_getNumeroRange(&subopcion2,
											"\nINGRESE UN ID DEL TRACKING PARA CANCELARLO / SALIR [0]: ",
											"\nERROR: REINGRESE ", 0,
											C_PRODUCTOS, 3);
									switch (subopcion2) {
									case 0:
										break;
									default:
											rtn = Tracking_Baja(aTrackings,
													C_TRACKINGS, subopcion2);
											if (rtn == -1) {
												puts("INGRESE UNA ID VALIDA!!");
											}
										//DAR DE BAJA AL TRACKING
										break;
									}
								}


								break;
							case 4:
								rtn = utn_getNumeroRange(&subopcion2, "\n1. LISTADO DE VENTAS FINALIZADAS."
										"\n2. VER PRODUCTOS.\nINGRESE LA OPCION: ", "\nERROR: REINGRESE: ", 1, 2, 3);
								switch(subopcion2)
								{
								case 1:
									Tracking_refrescarEnvios(aTrackings, C_TRACKINGS);
									if(Tracking_ListarComprasFinalizadas(aTrackings, C_TRACKINGS, idSesion) == -1)
									{
										puts("NO HAY PRODUCTOS PARA MOSTRAR");
									}
									break;
								case 2:
									 //VER PRODUCTOS MIENTRAS QUE HAYA ALGUNO CON STOCK
									if (Producto_listarStock(aProductos,
									C_PRODUCTOS, idSesion) == -1) {
										puts("NO HAY PRODUCTOS PARA MOSTRAR");
									}
									 break;
								default:
									break;
								}

								break;
							case 0:
								break;
							default:
								break;
							}
						} while (suboption != 0);

					} else if (validacion == 0)
					{
						do {
							system("cls");
							utn_getAlfaNum(opcion, sizeof(opcion),
									"****************************"
									"\n** 1er EXAMEN LAB I - 1H ***"
									"\n********* ADMIN **********"
									"\n****************************\n\n"
									"A) LISTAR EL ESTADO DE TODOS LOS USUARIOS. \n"
									"B) LISTAR TODOS LOS PRODUCTOS POR CATEGORIA. \n"
									"C) BAJA DE UN PRODUCTO\n"
									"D) BAJA DE UN USUARIO\n"
									"E) VER TRACKING GLOBAL\n\n"
									"0) SALIR\n\n"
									"INGRESE UNA OPCION: ",
									"\nERROR INGRESE UNA OPCION VALIDA: ", 3);

							switch(opcion[0])
							{
							case 'a':
							case 'A':
								//Listar usuarios y sus estados.
								Usuario_MostrarTodos(aUsuarios, C_USUARIOS);
								system("pause");
								break;
							case 'b':
							case 'B':
								Producto_MostrarTodosOrdenados(aProductos, C_PRODUCTOS);
								break;
							case 'c':
							case 'C':
								// DAR DE BAJA UN PRODUCTO
								Producto_MostrarTodos(aProductos, C_PRODUCTOS);
								utn_getNumeroRange(&subopcion2, "\nINGRESE LA ID A DAR DE BAJA:", "\nERROR. REINGRESE: ", 0, C_PRODUCTOS, 3);
								Producto_Baja(aProductos, C_PRODUCTOS, subopcion2, aTrackings, C_TRACKINGS);
								break;
							case 'd':
							case 'D':
								Usuario_MostrarTodos(aUsuarios, C_USUARIOS);
								utn_getNumeroRange(&subopcion2, "\nINGRESE ID DE USUARIO A DAR DE BAJA: ", "\nERROR. REINGRESE: ", 0, C_USUARIOS, 3);
								Usuario_Baja(aUsuarios, C_USUARIOS, subopcion2, aTrackings, C_TRACKINGS, aProductos, C_PRODUCTOS);
								break;
							case 'e':
							case 'E':
								Tracking_MostrarTodos(aTrackings, C_TRACKINGS);
								system("pause");
								break;
							default:
								break;
							}


						} while(strcmp(opcion,"0") != 0);

					}
				}
			}
		} else if (option == 2) {
			system("cls");
			if (Usuario_Alta(aUsuarios, C_USUARIOS)) {
				system("cls");
				puts("\nUsuario creado exitosamente!");
				Sleep(2);
			} else {

				puts("No se ha creado el usuario! ");
				Sleep(2);
			}
		} else {
			return 0;
		}

	} while (option != 0);

	return EXIT_SUCCESS;
}
