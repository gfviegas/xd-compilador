/**
 * Define a tabela de simples e funções de acesso, inserção e remoção.
 * @author Gustavo Viegas (3026)
 *
 **/

#ifndef symbol_h
#define symbol_h

#include <stdlib.h>
#include "tokens.h"
#include "logger.h"

typedef struct Symbol* SymbolPointer;
typedef struct Symbol {
	Token token;
	Lexeme lexeme;
	Operator op;
	SymbolPointer next;
} Symbol;

typedef struct SymbolTable* SymbolTablePointer;
typedef struct SymbolTable {
	SymbolPointer next;
	int amount;
} SymbolTable;


SymbolTablePointer initSymbolTable(void);

SymbolPointer createSymbol(Token token, Lexeme lexeme, Operator op);

void addToSymbolTable(SymbolTablePointer table, Token token, Lexeme lexeme, Operator op);

void removeFromSymbolTable(SymbolTablePointer table, int index);

SymbolPointer getSymbol(SymbolTablePointer table, int index);

void displaySymbolTable(SymbolTablePointer table);

#endif
