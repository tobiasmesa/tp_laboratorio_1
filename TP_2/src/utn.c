/*
 * utn.c
 *
 *  Created on: 21 abr. 2022
 *      Author: tobic
 */

#include "utn.h"



static int getFloat(float* pResultado);
static int esFlotante(char* cadena, int limite);
/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un m?ximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tama?o de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
int myGets(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096]; // ****************Modificar con memoria dinamica************

	if(cadena != NULL && longitud > 0)
	{
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}

/**
 * \brief Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[50];
    if(pResultado != NULL && myGets(bufferString,sizeof(bufferString)) == 0 && esNumerica(bufferString,sizeof(bufferString)))
	{
		retorno=0;
		*pResultado = atoi(bufferString) ;

	}
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
int esNumerica(char* cadena, int limite)
{
	int retorno = 1; // VERDADERO
	int i;
	for(i=0;i<limite && cadena[i] != '\0';i++)
	{
		if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
		{
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
		}
		//CONTINUE
	}
	//BREAK
	return retorno;
}


/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumeroRange(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		if(	getInt(&bufferInt) == 0 &&bufferInt >= minimo && bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}



static int esFlotante(char* cadena, int limite)
{
	int retorno = 0; //VERDADERO
	int i;
	int contadorPuntos = 0; // PARA QUE NO HAYA MAS DE 1 PUNTO EN EL NUMERO
	for(i = 0 ; i < limite && cadena[i] != '\0' ; i++)
	{
		if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
		{
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			if(cadena[i] == '.' && contadorPuntos == 0)
			{
				contadorPuntos++;
			}
			else
			{
				retorno = 1;
				break;
			}
		}
		//CONTINUE
	}
//BREAK
	return retorno;
}

static int getFloat(float* pResultado)
{
	int retorno = 1;
	char bufferString[50];
	if(pResultado != NULL)
	{
		if( myGets(bufferString,sizeof(bufferString)) == 0 &&
				esFlotante(bufferString, sizeof(bufferString)) == 0)
		 	{
				*pResultado = atof(bufferString);
				retorno = 0;
			}
		}
	return retorno;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = 1;
	float bufferFloat;
	do
	{
		printf("%s", mensaje);
		if(getFloat(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo)
		{
			*pResultado= bufferFloat;
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
		reintentos -- ;
	}while(reintentos >= 0);
	return retorno;
}





int getString(char* cadena, int longitud){
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0){
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL){
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n'){
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud){
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

static int getNombre(char* pResultado, int longitud){
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL){
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esTexto(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud){
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

int esTexto(char* cadena,int longitud){
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0){
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++){
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) &&
					(cadena[i] < 'a' || cadena[i] > 'z' )){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un string al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el array y -1 si no
 *
 */
int utn_getString(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos){
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0){
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 &&
				strnlen(bufferString,sizeof(bufferString)) < longitud ){
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}







int esAlfanumerica(char* cadena,int longitud){
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0){
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++){
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) &&
					(cadena[i] < 'a' || cadena[i] > 'z' ) &&
					(cadena[i] > '9' || cadena[i] < '0')){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}



static int getNombreAlfanumerico(char* pResultado, int longitud){
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL){
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esAlfanumerica(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud){
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}



int utn_getAlfaNum(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
		int retorno = -1;
		while(reintentos>=0){
			reintentos--;
			printf("%s",mensaje);
			if(getNombreAlfanumerico(bufferString,sizeof(bufferString)) == 0 &&
					strnlen(bufferString,sizeof(bufferString)) < longitud ){
				strncpy(pResultado,bufferString,longitud);
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
		}
		return retorno;
}









/**
 * @fn float sumFloat(float, float)
 * @brief
 * Suma dos variables tipo float y retorna el resultado
 * @pre
 * @post
 * @param a
 * @param b
 * @return
 */
float sumFloat(float a, float b)
{
	return a + b;
}
/**
 * @fn float subsFloat(float, float)
 * @brief
 * Resta dos variables tipo float y devuelve el resultado
 * @pre
 * @post
 * @param a
 * @param b
 * @return
 */
float subsFloat(float a, float b)
{
	return a - b;
}
/**
 * @fn float multFloat(float, float)
 * @brief
 * Multiplica dos variables tipo float y retorna el resultado
 * @pre
 * @post
 * @param a
 * @param b
 * @return
 */
float multFloat(float a, float b)
{
	return a * b;
}
/**
 * @fn float divFloat(float, float)
 * @brief
 * Divide dos variables tipo float y retorna el resultado. Si el divisor es 0 retorna 0
 * @pre
 * @post
 * @param a
 * @param b
 * @return
 */
float divFloat(float a, float b)
{
	if (b == 0)
	{
		return 0;
	}
	return a / b;
}
