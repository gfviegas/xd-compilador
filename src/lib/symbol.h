/**
 * Define a tabela de símbolos e funções de acesso, inserção e remoção.
 * @author Gustavo Viegas (3026)
 *
 **/

#ifndef symbol_h
#define symbol_h

#include <stdlib.h>
#include "tokens.h"

typedef struct Symbol* SymbolPointer;
typedef struct Symbol {
	Lexeme lexeme;
	IDType type;
	SymbolPointer next;
	Lexeme parentIdentifier;
} Symbol;

typedef struct SymbolTable* SymbolTablePointer;
typedef struct SymbolTable {
	SymbolPointer next;
	int amount;
} SymbolTable;


SymbolTablePointer createSymbolTable(void);

void initSymbolTable(SymbolTablePointer *table);

SymbolPointer createSymbol(Lexeme lexeme, IDType type);

void addToSymbolTable(SymbolTablePointer table, Lexeme lexeme, IDType type, Lexeme parentIdentifier);

// void removeFromSymbolTable(SymbolTablePointer table, int index);

SymbolPointer getSymbol(SymbolTablePointer table, Lexeme lexeme);

void displaySymbolTable(SymbolTablePointer table);

#endif
