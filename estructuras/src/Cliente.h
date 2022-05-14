/*
 * Cliente.h
 *
 *  Created on: 28 abr. 2022
 *      Author: tobic
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <stdlib.h>
#include <stdio.h>
#include "utn.h"


typedef struct{
	int dia;
	int mes;
	int ano;
} Fecha;


typedef struct {
	int id;
	int isEmpty;
	Fecha fechaNac;
} Cliente;



//

#endif /* CLIENTE_H_ */
