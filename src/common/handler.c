#include "handler.h"

int run(void) {
	// searchIdentifier(CurrentScope, "");
	initScope(&CurrentScope, NULL);

	if (CurrentScope == NULL) {
		cprintf(ERROR2, "Escopo inicial retornou NULL");
		printf("\n\n");
		return -1;
	}

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
		cprintf(GREEN, "Trem de compilar rodô demais da conta!\nPrograma correto\n");
		return 0;
	}

	cprintf(RED, "Trem de compilar deu ruim!\nPrograma incorreto!\n");
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

	if (hasSemanticError <= 0) {
		cprintf(ERROR, "Cê quiria digitarr");
		cprintf(ERROR2, " '%s' ", yytext);
		cprintf(ERROR, "memo??");
		printf("\n\n");
		printf("Token problemático: ");
		printResetColor();
		printToken(yychar);
		printResetColor();
		printf("\n");
	}

	hasError = 1;
}

void handleNewScope(void) {
	createScope(&CurrentScope);
}

void handleFinishScope(void) {
	finishScope(&CurrentScope);
}

void handleStatement(YYSTYPE type, YYSTYPE identifier) {
	addToSymbolTable(CurrentScope->table, identifier.lexeme, type.value);
}

void checkIdentifierExists(YYSTYPE identifier) {
	SymbolPointer idPointer = searchIdentifier(CurrentScope, identifier.lexeme);
	char message[200];

	if (idPointer == NULL) {
		sprintf(message, "erro semântico: o identificador %s não foi declarado", identifier.lexeme);
		hasSemanticError = 1;
		yyerror(message);
		// YYABORT;
	}
}

void checkIdentifierNotExists(YYSTYPE identifier) {
	char message[200];
	SymbolPointer idPointer = searchIdentifierCurrentScope(CurrentScope, identifier.lexeme);

	if (idPointer != NULL) {
		sprintf(message, "erro semântico - o identificador %s já foi declarado no escopo atual", identifier.lexeme);
		hasSemanticError = 1;
		yyerror(message);
		// YYABORT;
	}
}
