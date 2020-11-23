#include "symbol.h"

SymbolTablePointer initSymbolTable(void) {
	SymbolTablePointer table = malloc(sizeof(SymbolTable));

	if (!table) return NULL;

	table->next = NULL;
	table->amount = 0;
	return table;
}

SymbolPointer createSymbol(Token token, Lexeme lexeme, Operator op) {
	SymbolPointer symbol = malloc(sizeof(Symbol));

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

	cprintLine(BLUE);
	cprintf(BLUE, "\t Imprimindo Tabela de Símbolos (%d entradas)", table->amount);
	cprintf(BLUE, "%3s | %20s | %20s | %30s", "ID", "Token", "Operator", "Lexema");
	cprintLine(BLUE);

	while (currentSymbol->next != NULL) {
		char* tokenStr = translateToken(currentSymbol->token);
		char *opStr = translateOperator(currentSymbol->op);

		cprintf(CYAN, "%3s | %20s | %20s | %30s", id, tokenStr, opStr, currentSymbol->lexeme);

		currentSymbol = currentSymbol->next;
		id += 1;
	}

	cprintLine(BLUE);
}
