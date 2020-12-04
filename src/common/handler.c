#include "handler.h"

int run(void) {
	// searchIdentifier(CurrentScope, "");
	initScope(&CurrentScope, NULL);

	if (CurrentScope == NULL) {
		cprintf(ERROR2, "Escopo inicial retornou NULL");
		printf("\n\n");
		return -1;
	}

	printf("Escopo Atual: %p\n", CurrentScope);

	cprintLine(BLUE);
	cprintf(TITLE2, "\t Código Fonte:");
	printf("\n\n");

	yyparse();

	// cprintLine(MAGENTA);
	// cprintf(TITLE1, "\t Tabela de Tokens:");
	// printf("\n\n");
	// displaySymbolTable(STable);

	printf("\n");
	cprintLine(YELLOW);
	cprintf(TITLE3, "\t Resultado da compilação:");
	printf("\n\n");

	if (!hasError) {
		cprintf(GREEN, "Trem de compilar rodô demais da conta!\nPrograma sintaticamente correto\n");
		return 0;
	}

	cprintf(RED, "Trem de compilar deu ruim!\nPrograma sintaticamente incorreto!\n");
	return 0;
}

Token handleLex(Lexeme lexeme, int lineNumber, Token token, int value) {
	printSourceCode(lexeme, lineNumber);

	if (value <= -1) {
		yylval.lexeme = lexeme;
	} else {
		yylval.value = value;
	}
	// addToSymbolTable(STable, token, lexeme, op);

	return token;
}

void handleError(const char *str) {
	printf("\n");
	cprintf(ERROR, "Uai sô... deu um pobrema: %s na linha %d", str, yylineno);
	printf("\n\n");
	cprintf(ERROR, "Cê quiria digitarr");
	cprintf(ERROR2, " '%s' ", yytext);
	cprintf(ERROR, "memo??");
	printf("\n\n");
	printf("Token problemático: ");
	printResetColor();
	printToken(yychar);
	printResetColor();
	printf("\n");
	hasError = 1;
}

void handleNewScope(void) {
	printf("Criando escopo... \n");
	createScope(&CurrentScope);
	printf("Escopo Atual: %p\n", CurrentScope);
}

void handleFinishScope(void) {
	printf("Finalizando escopo... \n");
	finishScope(&CurrentScope);
	printf("Escopo Atual: %p\n", CurrentScope);
}

void handleStatement(YYSTYPE type, YYSTYPE identifier) {
	printf("\n Tipo: %d == %s \n", type.value, translateIDType(type.value));
	printf("\n Identificador: %s \n", identifier.lexeme);

	addToSymbolTable(CurrentScope->table, identifier.lexeme, type.value);
	displaySymbolTable(CurrentScope->table);

	printf("Testando teste: %p\n", searchIdentifier(CurrentScope, "teste"));
	printf("Testando bussanga: %p\n", searchIdentifier(CurrentScope, "bussanga"));
	// printf("\n\nTYPE: %s, IDENTIFIER: %s \n\n", type.lexeme, identifier.lexeme);
	// printf("Avaliando tipos e etc... \n");
}
