/**
 * Define a tabela de símbolos e funções de acesso, inserção e remoção.
 * @author Gustavo Viegas (3026)
 *
 **/

#ifndef scope_h
#define scope_h

#include <stdlib.h>
#include "symbol.h"

typedef struct Scope* ScopePointer;
typedef struct Scope {
	ScopePointer father;
	SymbolTablePointer table;
} Scope;


void initScope(ScopePointer *scope, ScopePointer father);

void createScope(ScopePointer *currentScope);

SymbolPointer searchIdentifier(ScopePointer firstScope, Lexeme lexeme);

void finishScope(ScopePointer *currentScope);

// ScopePointer currentScope;
// Scope{
// 	father : null,
// 	table : SymbolTablePointer(CRIA A TABELA, INSERE O Q TIVER Q INSERIR...)
// }

// Leu um token que cria um novo escopo (ex: intao)
// -> Cria um novo scope
// 	NovoScope = Aloca memoria
// 	= Scope{
// 		father: currentScope,
// 		table: SymbolTablePointer(CRIA A TABELA)
// 	}
// 	CurrentScope = NovoScope

// 	-> Leu um token, tem que inserir na tabela, vai inserir em currentScope.table
// 	-> Leu um token, precisa fazer analise semantica? Procura em currentScope.table. Não achou? Procura em currentScope.father.table. Não achou? .... Até currentScope.father = NULL

// Leu um token que acaba um novo escopo (ex: tendeu)
// 	-> currentScope = currentScope.father

#endif
