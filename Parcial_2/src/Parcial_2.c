#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "servicio.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar archivo.
     2. Imprimir lista.
     3. Asignar totales.
     4. Filtrar por tipo.
     5. Mostrar servicios.
     6. Guardar servicios.
     7. Salir.
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option;
    int banderaCarga = 0;

    LinkedList* listaServicios = ll_newLinkedList();
    do{
    	utn_getNumero(&option, "1. Cargar archivo.\n2. Imprimir lista.\n3. Asignar totales."
    			"\n4. Filtrar por tipo.\n5. Mostrar servicios.\n6. Guardar servicios.\n7. Salir.\nSeleccione una opcion: ",
				"\nRespuesta invalida.\n", 1, 7, 1);
        switch(option)
        {
            case 1:
            	if(banderaCarga != 1)
            	{
            		controller_CargarArchivo("data.csv", listaServicios);
            		banderaCarga = 1;
            	}
                break;
            case 2:
            	if(ll_len(listaServicios) > 0)
            	{
            		controller_ImprimirLista(listaServicios);
            	}
            	break;
            case 3:
            	if(ll_len(listaServicios) > 0)
            	{
            		controller_AsignarDatos(listaServicios);
            	}
            	break;
            case 4:
            	if(ll_len(listaServicios) > 0)
            	{
            		controller_Filtrar(listaServicios);
            	}
            	break;
            case 5:
            	if(ll_len(listaServicios) > 0)
            	{
            		controller_Ordenar(listaServicios);
            	}
				break;
			case 6:
				if(ll_len(listaServicios) > 0)
				{
					controller_GuardarEnArchivo("data.csv", listaServicios);
				}
				break;
			case 7:
				ll_deleteLinkedList(listaServicios);
				break;
        }
    }while(option != 7);
    return 0;
}


