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

SymbolPointer createSymbol(Lexeme lexeme, IDType type) {
	SymbolPointer symbol = (SymbolPointer) malloc(sizeof(Symbol));

	if (!symbol) return NULL;

	symbol->lexeme = lexeme;
	symbol->type = type;
	symbol->next = NULL;

	return symbol;
}

void addToSymbolTable(SymbolTablePointer table, Lexeme lexeme, IDType type) {
	SymbolPointer symbol = createSymbol(lexeme, type);

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

SymbolPointer getSymbol(SymbolTablePointer table, Lexeme lexeme) {
	if (table == NULL) return NULL;

	SymbolPointer currentSymbol = table->next;

	while (currentSymbol != NULL) {
		if (strcmp(currentSymbol->lexeme, lexeme) == 0) return currentSymbol;

		currentSymbol = currentSymbol->next;
	}

	return NULL;
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

void printSymbolCell(SymbolPointer symbol, int id) {
	char *typeStr = idTypeToString(symbol->type);
	cprintf(BLUE, "%3d | %20s | %30s\n", id, typeStr, symbol->lexeme);
}

void printSymbolTableHeader(SymbolTablePointer table) {
	cprintf(MAGENTA, "\t %d entradas\n", table->amount);
	cprintf(MAGENTA, "%3s | %20s | %30s", "ID", "Tipo", "Lexema");
	cprintLine(MAGENTA);
}

void displaySymbolTable(SymbolTablePointer table) {
	int id = 1;
	SymbolPointer currentSymbol = table->next;

	printSymbolTableHeader(table);

	while (currentSymbol != NULL) {
		printSymbolCell(currentSymbol, id);

		currentSymbol = currentSymbol->next;
		id += 1;
	}
}
