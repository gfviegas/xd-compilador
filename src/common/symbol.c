#include "symbol.h"
#include <string.h>

SymbolTablePointer createSymbolTable(void) {
	SymbolTablePointer table = malloc(sizeof(SymbolTable));

	if (!table) return NULL;

	table->next = NULL;
	table->amount = 0;
	return table;
}

void initSymbolTable(SymbolTablePointer *table) {
	*table = (SymbolTablePointer) malloc(sizeof(SymbolTable));

	if (!(*table)) return;

	(*table)->next = NULL;
	(*table)->amount = 0;
}

SymbolPointer createSymbol(Token token, Lexeme lexeme, Operator op) {
	SymbolPointer symbol = (SymbolPointer) malloc(sizeof(Symbol));

	if (!symbol) return NULL;

	symbol->token = token;
	symbol->lexeme = lexeme;
	symbol->op = op;
	symbol->next = NULL;

	return symbol;
}

void addToSymbolTable(SymbolTablePointer table, Token token, Lexeme lexeme, Operator op) {
	SymbolPointer symbol = createSymbol(token, lexeme, op);

	if (table->amount == 0) {
		table->next = symbol;
		table->amount += 1;
		return;
	}

	SymbolPointer currentSymbol = table->next;
	while (currentSymbol->next != NULL) {
		currentSymbol = currentSymbol->next;
	}

	currentSymbol->next = symbol;
	table->amount += 1;
	return;
}

SymbolPointer getSymbol(SymbolTablePointer table, int index) {
	if (table == NULL) return NULL;

	SymbolPointer currentSymbol = table->next;
	if (currentSymbol == NULL) return NULL;

	for (int i = 0; i < index; i++) {
		if (currentSymbol == NULL) return NULL;
		currentSymbol = currentSymbol->next;
	}

	return currentSymbol;
}

void removeFromSymbolTable(SymbolTablePointer table, int index) {
	int currentIndex = 0;
	if (table == NULL) return;

	SymbolPointer currentSymbol = table->next;
	SymbolPointer previousSymbol = table->next;

	if (currentSymbol == NULL) return;

	while (currentIndex != index) {
		if (currentSymbol == NULL) break;

		if (currentIndex == index) {
			previousSymbol->next = currentSymbol->next;

			if (currentSymbol == table->next) {
				table->next = currentSymbol;
			}

			return free(currentSymbol);
		}

		currentIndex += 1;
		previousSymbol = currentSymbol;
		currentSymbol = currentSymbol->next;
	}
}

void displaySymbolTable(SymbolTablePointer table) {
	int id = 1;
	SymbolPointer currentSymbol = table->next;

	cprintf(MAGENTA, "\t %d entradas\n", table->amount);
	cprintf(MAGENTA, "%3s | %20s | %20s | %30s", "ID", "Token", "Operator", "Lexema");
	cprintLine(MAGENTA);

	while (currentSymbol != NULL) {
		char *tokenStr = translateToken(currentSymbol->token);
		char *opStr = translateOperator(currentSymbol->op);

		cprintf(BLUE, "%3d | %20s | %20s | %30s\n", id, tokenStr, opStr, currentSymbol->lexeme);

		currentSymbol = currentSymbol->next;
		id += 1;
	}
}
