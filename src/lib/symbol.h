/**
 * Define a tabela de símbolos e funções de acesso, inserção e remoção.
 * @author Gustavo Viegas (3026)
 *
 **/

#ifndef symbol_h
#define symbol_h

#include <stdlib.h>
#include "tokens.h"

// Ponteiro para um símbolo
typedef struct Symbol* SymbolPointer;
typedef struct Symbol {
	// Lexema do símbolo
	Lexeme lexeme;
	// Tipo do símbolo
	IDType type;
	// Ponteiro para o próximo símbolo da lista
	SymbolPointer next;
} Symbol;

// Ponteiro para a tabela de símbolos
typedef struct SymbolTable* SymbolTablePointer;
typedef struct SymbolTable {
	// Ponteiro para a célula cabeça
	SymbolPointer next;
	// Quantidade de símbolos na tabela
	int amount;
} SymbolTable;


SymbolTablePointer createSymbolTable(void);

void initSymbolTable(SymbolTablePointer *table);

SymbolPointer createSymbol(Lexeme lexeme, IDType type);

void addToSymbolTable(SymbolTablePointer table, Lexeme lexeme, IDType type);

// void removeFromSymbolTable(SymbolTablePointer table, int index);

SymbolPointer getSymbol(SymbolTablePointer table, Lexeme lexeme);

void printSymbolCell(SymbolPointer symbol, int id);

void printSymbolTableHeader(SymbolTablePointer table);

void displaySymbolTable(SymbolTablePointer table);

#endif
