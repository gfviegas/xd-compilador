/**
 * Define a tabela de símbolos e funções de acesso, inserção e remoção.
 * @author Gustavo Viegas (3026)
 *
 **/

#ifndef scope_h
#define scope_h

#include <stdlib.h>
#include "symbol.h"

// Ponteiro para um escopo
typedef struct Scope* ScopePointer;

// Representação de um escopo do compilador
typedef struct Scope {
	// Quem é o escopo pai. Quando é o escopo raiz, este valor é NULL
	ScopePointer father;
	// A tabela de símbolos deste escopo
	SymbolTablePointer table;
} Scope;


void initScope(ScopePointer *scope, ScopePointer father);
void createScope(ScopePointer *currentScope);

SymbolPointer searchIdentifier(ScopePointer firstScope, Lexeme lexeme);
SymbolPointer searchIdentifierCurrentScope(ScopePointer currentScope, Lexeme lexeme);

void finishScope(ScopePointer *currentScope);

#endif
