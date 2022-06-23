/*
 * parser.h
 *
 *  Created on: 17 jun. 2022
 *      Author:
 */

#ifndef PARSER_H_
#define PARSER_H_
/**
 * \brief lee un archivo en modo texto, obtiene los datos de un servicio y los carga en una estructura
 * @param pArchivo FILE*, archivo a leer.
 * @param pArrayServicios linkedlist* puntero a lista de elementos
 * @return retorna 0 si todo ok, -1 si hubo un error
 */
int parser_ServicioTxt(FILE* pArchivo, LinkedList* pArrayServicios);
/**
 * \brief escribe en un archivo en modo texto las estructuras guardadas en una lista
 * @param pArchivo FILE*, archivo a escribir.
 * @param pArrayServicios linkedlist* puntero a lista de elementos
 * @return retorna 0 si todo ok, -1 si hubo un error
 */
int parser_GuardarTxt(FILE* pArchivo, LinkedList* pArrayServicios);

#endif /* PARSER_H_ */
