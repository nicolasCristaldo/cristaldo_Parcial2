/*
 * parser.c
 *
 *  Created on: 17 jun. 2022
 *      Author: nico
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "servicio.h"

int parser_ServicioTxt(FILE* pArchivo, LinkedList* pArrayServicios)
{
	int ret = -1;
	int r;
	eServicio *newServicio = NULL;
	char idStr[2000],descripcionStr[2000],tipoStr[2000],precioStr[2000],totalStr[2000],cantidadStr[2000];
	int id,tipo,cantidad;
	float precio,total;
	if(pArchivo != NULL && pArrayServicios != NULL)
	{
		fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,descripcionStr,tipoStr,precioStr,cantidadStr,totalStr);
		do
		{
			r = fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,descripcionStr,tipoStr,precioStr,cantidadStr,totalStr);
			if(r == 6)
			{
				id = atoi(idStr);
				tipo = atoi(tipoStr);
				cantidad = atoi(cantidadStr);
				precio = atof(precioStr);
				total = atof(totalStr);

				newServicio = servicioNewParametros(id, descripcionStr, tipo, precio, cantidad, total);
				if(newServicio != NULL)
				{
					ret = 0;
					if(ll_add(pArrayServicios, newServicio) == 0)
					{
						printf("\n%d %s %d %f %d %f\n",newServicio->idServicio,newServicio->descripcion,newServicio->tipo,
								newServicio->precioUnitario,newServicio->cantidad,newServicio->totalServicio);
					}
				}
				else
				{
					printf("No se cargó el servicio.\n");
				}
			}
		}while(feof(pArchivo) == 0);
	}
	return ret;
}

int parser_GuardarTxt(FILE* pArchivo, LinkedList* pArrayServicios)
{
	int ret = -1;
	int i = 0;
	eServicio* pServicio;
	int id;
	char descripcion[50];
	int tipo;
	float precio;
	int cantidad;
	float total;
	if(pArchivo != NULL && pArrayServicios != NULL)
	{
		fprintf(pArchivo,"id_servicio,descripcion,tipo,precioUnitario,cantidad,totalServicio\n");
		do
		{
			pServicio = ll_get(pArrayServicios,i);

			servicio_GetId(pServicio, &id);
			servicio_GetTipo(pServicio, &tipo);
			servicio_GetPrecioUnitario(pServicio, &precio);
			servicio_GetCantidad(pServicio, &cantidad);
			servicio_GetTotal(pServicio, &total);
			servicio_GetDescripcion(pServicio, descripcion);

			fprintf(pArchivo,"%d,%s,%d,%.0f,%d,%.1f\n",id,descripcion,tipo,precio,cantidad,total);
			i++;
		}while(i < ll_len(pArrayServicios) && feof(pArchivo) == 0);
		ret = 0;
	}
	return ret;
}
