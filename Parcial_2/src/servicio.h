/*
 * servicio.h
 *
 *  Created on: 17 jun. 2022
 *      Author: nico
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct
{
	int idServicio;
	char descripcion[50];
	int tipo;
	float precioUnitario;
	int cantidad;
	float totalServicio;
}eServicio;
/***************** NUEVO SERVICIO  ***************************/
/**
 * \brief crea un nuevo Servicio
 * @return retorna NULL si no se pudo crear un nuevo servicio, retorna un puntero a servicio si se pudo crear correctamente.
 */
eServicio* newServicio();
/**
 * \brief crea un nuevo servicio con los datos pasados como parametros
 * @param id int, id del servicio
 * @param desc char*, descripcion del servicio
 * @param tipo int, tipo del servicio
 * @param precio float, precio del servicio
 * @param cantidad int, cantidad del servicio
 * @param total float, total del servicio
 * @return retorna el nuevo servicio si todo ok, null si hubo un fallo
 */
eServicio* servicioNewParametros(int id, char* desc, int tipo, float precio, int cantidad, float total);

/***************** TRABAJO CON ESTRUCTURA ***************************/
/**
 * \brief imprime los datos de un servicio
 * @param servicio eServicio*, puntero al servicio a imprimir
 */
void imprimirServicio(eServicio* servicio);
/**
 * \brief imprime todos los elementos de una lista deservicios
 * @param pArrayServicios LinkedList*, puntero a linkedlist
 * @return retorna -1 si hubo un fallo, 0 si todo ok.
 */
int imprimirListaServicios(LinkedList* pArrayServicios);
/**
 * \brief calcula el total de un servicio
 * @param elemento void*, puntero al elemento a calcular
 */
void calcularTotal(void* elemento);
/**
 * \brief validasi el tipo del elemento es minorista
 * @param elemento void*, puntero a elemento a validar
 * @return retorna 0 si no es minorista, 1 si lo es.
 */
int esMinorista(void* elemento);
/**
 * \brief validasi el tipo del elemento es mayorista
 * @param elemento void*, puntero a elemento a validar
 * @return retorna 0 si no es mayorista, 1 si lo es.
 */
int esMayorista(void* elemento);
/**
 * \brief validasi el tipo del elemento es exportacion
 * @param elemento void*, puntero a elemento a validar
 * @return retorna 0 si no es exportacion, 1 si lo es.
 */
int esExportacion(void* elemento);
/**
 * \brief compara la descripcion de dos elementos
 * @param this1 void*, puntero a elemento a comparar
 * @param this2 void*, puntero a elemento a comparar
 * @return retorna 1 si la descripcion del primero es mayor a la del segundo, -1 si no lo es
 */
int compararDescripcion(void* this1,void* this2);

/***************** SETTERS Y GETTERS ***************************/

/**
 * \brief modifica el campo idServicio con el valor pasado como parametro
 * @param this eServicio*, puntero a servicio a modificar
 * @param id int, nuevo id del servicio
 * @return retorna 0 si todo ok, -1 si hubo un fallo.
 */
int servicio_SetId(eServicio* this, int id);
/**
 * \brief obtiene el valor del campo id de un servicio
 * @param this eServicio*, puntero a servicio
 * @param id int*, puntero a variable donde se guardara el id
 * @return retorna 0 si todo ok, -1 si hubo un fallo.
 */
int servicio_GetId(eServicio* this, int* id);

/**
 * \brief modifica el campo descripcion de un servicio
 * @param this eServicio*, puntero a servicio
 * @param descripcion char*, nueva descripcion del servicio
 * @return retorna 0 si todo ok, -1 si hubo un fallo.
 */
int servicio_SetDescripcion(eServicio* this, char* descripcion);
/**
 * \brief obtiene la descripcion de un servicio
 * @param this eServicio*, puntero a servicio
 * @param descripcion char*, variable donde se guardara la descripcion del servicio
 * @return retorna 0 si todo ok, -1 si hubo un fallo.
 */
int servicio_GetDescripcion(eServicio* this, char* descripcion);

/**
 * \brief modifica el campo tipo de un servicio
 * @param this eServicio*, puntero a servicio
 * @param tipo int, nuevo tipo del servicio
 * @return retorna 0 si todo ok, -1 si hubo un fallo.
 */
int servicio_SetTipo(eServicio* this, int tipo);
/**
 * \brief obtiene el tipo de un servicio
 * @param this eServicio*, puntero a servicio
 * @param tipo int*, puntero donde se guardara el valor del tipo.
 * @return retorna 0 si todo ok, -1 si hubo un fallo.
 */
int servicio_GetTipo(eServicio* this, int* tipo);

/**
 *\brief modifica el campo precio de un servicio
 * @param this eServicio*, puntero a servicio
 * @param precio float, nuevo precio del servicio
 * @return retorna 0 si todo ok, -1 si hubo un fallo.
 */
int servicio_SetPrecioUnitario(eServicio* this, float precio);
/**
 *\brief obtiene el precio de un servicio
 * @param this eServicio*, puntero a servicio
 * @param precio float*, puntero a la variable donde se guardara el valor del precio
 * @return retorna 0 si todo ok, -1 si hubo un fallo.
 */
int servicio_GetPrecioUnitario(eServicio* this, float* precio);

/**
 *\brief modifica el campo cantidad de un servicio
 * @param this eServicio*, puntero a servicio
 * @param cantidad int, nueva cantidad del servicio
 * @return retorna 0 si todo ok, -1 si hubo un fallo.
 */
int servicio_SetCantidad(eServicio* this, int cantidad);
/**
 *\brief obtiene la cantidad de un servicio
 * @param this eServicio*, puntero a servicio
 * @param cantidad int, puntero donde se guardara el valor de la cantidad
 * @return retorna 0 si todo ok, -1 si hubo un fallo.
 */
int servicio_GetCantidad(eServicio* this, int* cantidad);

/**
 *\brief modifica el campo total de un servicio
 * @param this eServicio*, puntero a servicio
 * @param total float, nuevo total del servicio.
 * @return retorna 0 si todo ok, -1 si hubo un fallo.
 */
int servicio_SetTotal(eServicio* this, float total);
/**
 *\brief obtiene el total de un servicio
 * @param this eServicio*, puntero a servicio
 * @param total float*, puntero a variable donde se guardara el valor de la cantidad
 * @return retorna 0 si todo ok, -1 si hubo un fallo.
 */
int servicio_GetTotal(eServicio* this, float* total);

#endif /* SERVICIO_H_ */
