/*
 * controller.c
 *
 *  Created on: 17 jun. 2022
 *      Author: nico
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "servicio.h"
#include "parser.h"


int controller_CargarArchivo(char* archivo, LinkedList* pArrayServicios)
{
	int ret = -1;
    FILE *pArchivo;
    if(archivo != NULL && pArrayServicios != NULL)
    {
    	pArchivo = fopen(archivo,"r");
    	if(pArchivo == NULL)
    	{
    		printf("\nError al abrir el archivo.\n");
    	}
    	else
    	{
    		if(parser_ServicioTxt(pArchivo, pArrayServicios) == 0)
    		{
    			ret = 0;
    		}
    		fclose(pArchivo);
    	}
    }
    return ret;
}

int controller_ImprimirLista(LinkedList* pArrayServicios)
{
	int ret = -1;
	if(pArrayServicios != NULL)
	{
		if(imprimirListaServicios(pArrayServicios) == 0)
		{
			ret = 0;
		}
	}
	return ret;
}

int controller_AsignarDatos(LinkedList* pArrayServicios)
{
	int ret = -1;
	void (*pFuncion)(void*) = NULL;
	if(pArrayServicios != NULL)
	{
		pFuncion = calcularTotal;
		ll_map(pArrayServicios, pFuncion);
		ret = 0;
	}
	return ret;
}

int controller_Filtrar(LinkedList* pArrayServicios)
{
	int ret = -1;
	int (*pFuncion)(void*) = NULL;
	LinkedList* listaFiltrada = NULL;
	if(pArrayServicios != NULL)
	{
		if(utn_getNumero(&ret,"\nFILTRAR POR TIPO:\n1- Minorista.\n2- Mayorista.\n3- Exportar. ", "\nError.\n", 1, 3, 5) == 0)
		{
			switch(ret)
			{
			case 1:
				pFuncion = esMinorista;
				break;
			case 2:
				pFuncion = esMayorista;
				break;
			case 3:
				pFuncion = esExportacion;
				break;
			}
			listaFiltrada = ll_filter(pArrayServicios, pFuncion);
			if(listaFiltrada != NULL)
			{
				ret = 0;
			}
			free(listaFiltrada);
		}
	}
	return ret;
}

int controller_Ordenar(LinkedList* pArrayServicios)
{
	int ret = -1;
	int (*pFuncion)(void*, void*) = NULL;
	if(pArrayServicios != NULL)
	{
		pFuncion = compararDescripcion;
		ll_sort(pArrayServicios, pFuncion, 1);
		imprimirListaServicios(pArrayServicios);
		ret = 0;
	}
	return ret;
}

int controller_GuardarEnArchivo(char* archivo, LinkedList* pArrayServicios)
{
	int ret = -1;
	FILE *pArchivo;
	if(archivo != NULL && pArrayServicios != NULL)
	{
		pArchivo = fopen(archivo,"w");
		if(pArchivo == NULL)
		{
			printf("\nError al abrir el archivo.\n");
		}
		else
		{
			if(parser_GuardarTxt(pArchivo, pArrayServicios) == 0)
			{
				ret = 0;
			}
			fclose(pArchivo);
		}
	}
	return ret;

}

