/*
 * controller.h
 *
 *  Created on: 17 jun. 2022
 *      Author: nico
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/**
 * \brief lee un archivo en modo texto.
 * @param archivo char*, nombre del archivo a leer.
 * @param pArrayServicios linkedlist* puntero a lista de elementos
 * @return retorna 0 si todo ok, -1 si hubo un error
 */
int controller_CargarArchivo(char* archivo, LinkedList* pArrayServicios);
/**
 *\brief imprime los elementos dentro de una lista de elementos
 * @param pArrayServicios linkedlist* puntero a lista de elementos
 * @return retorna 0 si todo ok, -1 si hubo un error
 */
int controller_ImprimirLista(LinkedList* pArrayServicios);
/**
 *\brief calcula y modifica el valor del campo total de un servicio
 * @param pArrayServicios linkedlist* puntero a lista de elementos
 * @return retorna 0 si todo ok, -1 si hubo un error
 */
int controller_AsignarDatos(LinkedList* pArrayServicios);
/**
 *\brief crea una nueva lista con los elementos filtrados de otra
 * @param pArrayServicios linkedlist* puntero a lista de elementos
 * @return retorna 0 si todo ok, -1 si hubo un error
 */
int controller_Filtrar(LinkedList* pArrayServicios);
/**
 *\brief ordena una lista de elementos por descripcion en modo ascendente
 * @param pArrayServicios linkedlist* puntero a lista de elementos
 * @return retorna 0 si todo ok, -1 si hubo un error
 */
int controller_Ordenar(LinkedList* pArrayServicios);
/**
 *\brief escribe los datos de una lista de elementos en un archivo en modo texto
 * @param archivo char*, nombre del archivo a escribir.
 * @param pArrayServicios linkedlist* puntero a lista de elementos
 * @return retorna 0 si todo ok, -1 si hubo un error
 */
int controller_GuardarEnArchivo(char* archivo, LinkedList* pArrayServicios);
#endif /* CONTROLLER_H_ */
