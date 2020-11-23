#include "handler.h"

int run(void) {
	initSymbolTable(&STable);
	if (STable == NULL) {
		cprintf(ERROR2, "Tabela de Símbolos retornou NULL");
		printf("\n\n");
		return -1;
	}

	printf("Tabela: %p\n", STable);
	// printFlag();

	cprintLine(MAGENTA);
	cprintf(TITLE1, "\t Tabela de Tokens:");
	printf("\n\n");
	displaySymbolTable(STable);

	cprintLine(BLUE);
	cprintf(TITLE2, "\t Código Fonte:");
	printf("\n\n");

	yyparse();

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

Token handleLex(Lexeme lexeme, int lineNumber, Token token, Operator op) {
	printSourceCode(lexeme, lineNumber);
	yylval = op;

	addToSymbolTable(STable, token, lexeme, op);

	return token;
}

void handleError(const char *str) {
	printf("\n");
	cprintf(ERROR, "Uai sô... deu um pobrema: %s na linha %d", str, yylineno);
	printf("\n\n");
	cprintf(ERROR, "Cê quiria digitarr");
	cprintf(ERROR2, " %s ", yytext);
	cprintf(ERROR, "memo??");
	printf("\n\n");
	printf("Token problemático: ");
	printResetColor();
	printToken(yychar);
	printResetColor();
	printf("\n");
	hasError = 1;
}
