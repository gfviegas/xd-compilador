#include "scope.h"

void initScope(ScopePointer *scope, ScopePointer father) {
	*scope = (ScopePointer) malloc(sizeof(Scope));
	if (!(*scope)) return;

	(*scope)->father = father;
	(*scope)->table = createSymbolTable();
}

void createScope(ScopePointer *currentScope) {
	ScopePointer scope = (ScopePointer) malloc(sizeof(Scope));
	if (!scope) return;

	scope->father = *currentScope;
	scope->table = createSymbolTable();

	// initSymbolTable(&(scope->table));

	*currentScope = scope;
}

SymbolPointer searchIdentifier(ScopePointer firstScope, Lexeme lexeme) {
	ScopePointer currentScope = firstScope;
	if (currentScope == NULL) return NULL;

	do {
		// Busca no escopo atual a célula com o lexema
		SymbolPointer resource = getSymbol(currentScope->table, lexeme);

		if (resource != NULL)
			return resource;

		currentScope = currentScope->father;
	} while (currentScope != NULL);

	return NULL;
}

SymbolPointer searchIdentifierCurrentScope(ScopePointer currentScope, Lexeme lexeme) {
	if (currentScope == NULL) return NULL;

	// Busca no escopo atual a célula com o lexema
	return getSymbol(currentScope->table, lexeme);
}

void finishScope(ScopePointer *currentScope) {
	ScopePointer toRemove = *currentScope;

	*currentScope = (*currentScope)->father;

	// TODO: Desalocar memoria do esopo, da tabela e suas celulas
	// free(toRemove->table);
	// free(toRemove);
}
