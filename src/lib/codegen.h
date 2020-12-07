/**
 * Geração de código intermediário
 * @author Gustavo Viegas (3026)
 *
 **/

#ifndef codegen_h
#define codegen_h

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

FILE *graphOutput;

/**
 * Abre o arquivo de output do grafo e aponta o ponteiro graphOutput para sua referência
 **/
void initCodeGen();

/**
 * Insere um vértice ao grafo
 *
 * @param   char*  label      Texto descritivo do vértice
 * @param   char*  extraInfo  Informações secundárias do vértice
 *
 * @return  int              Identificador do vértice no grafo
 */
int insertNodeGraph(char *label, char *extraInfo);

/**
 * Insere uma aresta ao grafo
 *
 * @param   int   node1  Identificador do primeiro vértice da aresta
 * @param   int   node2  Identificador do segundo vértice da aresta
 *
 * @return  void
 */
void insertConnection(int node1, int node2);

/**
 * Fecha o arquivo aberto
 *
 * @return  void
 */
void finishCodeGen(void);

#endif
