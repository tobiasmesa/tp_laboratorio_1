#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"

/****************************************************
    Menu:\n
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n
     3. Alta de pasajero\n
     4. Modificar datos de pasajero\n
     5. Baja de pasajero\n
     6. Listar pasajeros\n
     7. Ordenar pasajeros\n
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n
    10. Salir\n
*****************************************************/



int main()
{
	setbuf(stdout,  NULL);
    int option = 0;
    int flagOption1 = 0;
    int flagOption2 = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	utn_getNumeroRange(&option, "Menu:\n"
    			"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
    			"2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n"
    			"3. Alta de pasajero\n"
    			"4. Modificar datos de pasajero\n"
    			"5. Baja de pasajero\n"
    			"6. Listar pasajeros\n"
    			"7. Ordenar pasajeros\n"
    			"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
    			"9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).\n"
    			"10. Salir\n"
    			"Ingrese una opcion: ", "Error. Reintente", 1, 10, 3);
        switch(option)
        {
            case 1:
            	if(!flagOption1 && !flagOption2)
            	{
            		 if(controller_loadFromText("data.csv", listaPasajeros) == 1)
            		 {
            			 puts("\nYA SE HAN CARGADO LOS PASAJEROS DESDE EL .CSV!");
            			 flagOption1 = 1;
            		 } else
            		 {
            			 puts("\nNO SE HAN CARGADO LOS PASAJEROS!");
            		 }


            	} else
            	{
            		puts("\nERROR. YA SE HAN CARGADO LOS PASAJEROS!");
            	}
                break;
            case 2:
            	if(!flagOption2 && !flagOption1)
            	{
            		if(controller_loadFromBinary("data.bin", listaPasajeros) == 1)
            		{
            			puts("\nYA SE HAN CARGADO LOS PASAJEROS DESDE EL .BIN!");
            		} else
            		{
            			puts("\nNO SE HAN CARGADO LOS PASAJEROS!");
            		}

            	} else
            	{
            		puts("\nERROR. YA SE HAN CARGADO LOS PASAJEROS!");
            	}

            	break;
            case 3:
            	if(controller_addPassenger(listaPasajeros))
            	{
            		puts("\nPASAJERO AGREGADO!");
            	} else
            	{
            		puts("\nEL PASAJERO NO SE HA AGREGADO! ");
            	}
            	break;
            case 4:
            	controller_editPassenger(listaPasajeros);
            	break;
            case 5:
            	if(controller_removePassenger(listaPasajeros))
            	{
            		puts("\nPASAJERO ELIMINADO!");
            	} else
            	{
            		puts("\nID INCORRECTO!");
            	}
            	break;
            case 6:
            	if(!controller_ListPassenger(listaPasajeros))
            	{
            		puts("\nNO HAY PASAJEROS CARGADOS!");
            	}
            	break;
            case 7:
            	if(controller_sortPassenger(listaPasajeros))
            	{
            		puts("\nSE HAN ORDENADO LOS PASAJEROS!");
            	}

            	break;
            case 8:
            	if(controller_saveAsText("data.csv", listaPasajeros))
            	{
            		puts("\nPASEJEROS GUARDADOS!");
            	}

            	break;
            case 9:
            	if(controller_saveAsBinary("data.bin", listaPasajeros))
            	{
            		puts("\nPASEJEROS GUARDADOS!");
            	}
            	break;
            default:
            	break;
        }

    }while(option != 10);
    return 0;
}

