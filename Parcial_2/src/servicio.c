/*
 * servicio.c
 *
 *  Created on: 17 jun. 2022
 *      Author: nico
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "servicio.h"
#include <string.h>

/***************** NUEVO SERVICIO  ***************************/

eServicio* newServicio()
{
	eServicio *newServicio = NULL;

	newServicio = (eServicio*)malloc(sizeof(eServicio));
	if(newServicio != NULL)
	{
		strcpy(newServicio->descripcion,"");
		newServicio->idServicio = -1;
		newServicio->precioUnitario = -1;
		newServicio->cantidad = -1;
		newServicio->tipo = -1;
		newServicio->totalServicio = -1;
	}

	return newServicio;
}
eServicio* servicioNewParametros(int id, char* desc, int tipo, float precio, int cantidad, float total)
{
	eServicio *nuevoServicio = NULL;
	if(id > 0 && desc != NULL && tipo > 0 && tipo < 4 && precio > 0 && precio < 10000 && cantidad > 0 && total >= 0)
	{
		nuevoServicio = newServicio();

		if(nuevoServicio != NULL)
		{
			if(servicio_SetId(nuevoServicio, id) != 0 || servicio_SetDescripcion(nuevoServicio, desc) != 0
					|| servicio_SetTipo(nuevoServicio, tipo) != 0 || servicio_SetCantidad(nuevoServicio, cantidad) != 0
					|| servicio_SetPrecioUnitario(nuevoServicio, precio) != 0 || servicio_SetTotal(nuevoServicio, total) != 0)
			{
				printf("\nError al cargar servicio.\n");
				free(nuevoServicio);
				nuevoServicio = NULL;
			}
		}
	}
	return nuevoServicio;
}

/***************** TRABAJO CON ESTRUCTURA ***************************/

void imprimirServicio(eServicio* servicio)
{
	int id;
	char descripcion[50];
	int tipo;
	float precio;
	int cantidad;
	float total;
	servicio_GetId(servicio, &id);
	servicio_GetTipo(servicio, &tipo);
	servicio_GetPrecioUnitario(servicio, &precio);
	servicio_GetCantidad(servicio, &cantidad);
	servicio_GetTotal(servicio, &total);
	servicio_GetDescripcion(servicio, descripcion);
	printf("\n%-10d %-25s %-10d %-10.2f %-10d %-10.2f\n",id,descripcion,tipo,precio,cantidad,total);
}

int imprimirListaServicios(LinkedList* pArrayServicios)
{
	int ret = -1;
	int i;

	if(pArrayServicios != NULL)
	{
		printf("\n********************************************************************************************************");
		printf("\n%-10s %-25s %-10s %-10s %-10s %-10s\n","ID", "DESCRIPCION","TIPO", "PRECIO", "CANTIDAD", "TOTAL");
		for(i = 0; i < ll_len(pArrayServicios); i++)
		{
			imprimirServicio(ll_get(pArrayServicios, i));
		}
		printf("\n********************************************************************************************************\n");
		ret = 0;
	}
	return ret;
}

void calcularTotal(void* elemento)
{
	int cantidad;
	float precio;
	float total;
	eServicio* servicio = NULL;
	if(elemento != NULL)
	{
		servicio = elemento;
		if(servicio_GetCantidad(servicio, &cantidad) == 0 && servicio_GetPrecioUnitario(servicio, &precio) == 0)
		{
			total = precio * (float)cantidad;
			servicio_SetTotal(servicio, total);
		}
	}
}

int esMinorista(void* elemento)
{
	int ret = 0;
	int num;
	eServicio* servicio = NULL;
	if(elemento != NULL)
	{
		servicio = elemento;
		servicio_GetTipo(servicio, &num);
		if(num == 1)
		{
			ret = 1;
		}
	}
	return ret;
}

int esMayorista(void* elemento)
{
	int ret = 0;
	int num;
	eServicio* servicio = NULL;
	if(elemento != NULL)
	{
		servicio = elemento;
		servicio_GetTipo(servicio, &num);
		if(num == 2)
		{
			ret = 1;
		}
	}
	return ret;
}

int esExportacion(void* elemento)
{
	int ret = 0;
	int num;
	eServicio* servicio = NULL;
	if(elemento != NULL)
	{
		servicio = elemento;
		servicio_GetTipo(servicio, &num);
		if(num == 3)
		{
			ret = 1;
		}
	}
	return ret;
}

int compararDescripcion(void* this1,void* this2)
{
	int ret = -1;
	eServicio* servicio1 = NULL;
	eServicio* servicio2 = NULL;
	char desc1[50];
	char desc2[50];
	if(this1 != NULL && this2 != NULL)
	{
		servicio1 = this1;
		servicio2 = this2;
		servicio_GetDescripcion(servicio1, desc1);
		servicio_GetDescripcion(servicio2, desc2);
		if(strcmp(desc1,desc2) > 0)
		{
			ret = 1;
		}
	}
	return ret;
}

/***************** SETTERS Y GETTERS ***************************/

int servicio_SetId(eServicio* this, int id)
{
	int ret = -1;

	if(this != NULL && id > 0)
	{
		this->idServicio = id;
		ret = 0;
	}
	return ret;
}
int servicio_GetId(eServicio* this, int* id)
{
	int ret = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->idServicio;
		ret = 0;
	}
	return ret;
}

int servicio_SetDescripcion(eServicio* this, char* descripcion)
{
	int ret = -1;
	if(this != NULL && descripcion != NULL && esNombre(descripcion) != 0 && strlen(descripcion) < 50)
	{
		strncpy(this->descripcion,descripcion,sizeof(this->descripcion));
		ret = 0;
	}
	return ret;
}
int servicio_GetDescripcion(eServicio* this, char* descripcion)
{
	int ret = -1;

	if(this != NULL && descripcion != NULL)
	{
		strcpy(descripcion,this->descripcion);
	}
	return ret;
}

int servicio_SetTipo(eServicio* this, int tipo)
{
	int ret = -1;

	if(this != NULL && tipo > 0 && tipo < 4)
	{
		this->tipo = tipo;
		ret = 0;
	}
	return ret;
}
int servicio_GetTipo(eServicio* this, int* tipo)
{
	int ret = -1;

	if(this != NULL && tipo != NULL)
	{
		*tipo = this->tipo;
		ret = 0;
	}
	return ret;
}

int servicio_SetPrecioUnitario(eServicio* this, float precio)
{
	int ret = -1;

	if(this != NULL && precio > 0)
	{
		this->precioUnitario = precio;
		ret = 0;
	}

	return ret;
}
int servicio_GetPrecioUnitario(eServicio* this, float* precio)
{
	int ret = -1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precioUnitario;
		ret = 0;
	}
	return ret;
}

int servicio_SetCantidad(eServicio* this, int cantidad)
{
	int ret = -1;

	if(this != NULL && cantidad > 0)
	{
		this->cantidad = cantidad;
		ret = 0;
	}
	return ret;
}
int servicio_GetCantidad(eServicio* this, int* cantidad)
{
	int ret = -1;

	if(this != NULL && cantidad != NULL)
	{
		*cantidad = this->cantidad;
		ret = 0;
	}
	return ret;
}

int servicio_SetTotal(eServicio* this, float total)
{
	int ret = -1;

	if(this != NULL && total >= 0)
	{
		this->totalServicio = total;
		ret = 0;
	}

	return ret;
}
int servicio_GetTotal(eServicio* this, float* total)
{
	int ret = -1;

	if(this != NULL && total != NULL)
	{
		*total = this->totalServicio;
		ret = 0;
	}
	return ret;
}
