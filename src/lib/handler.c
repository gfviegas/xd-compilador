#include "handler.h"

int run(void) {
	// searchIdentifier(CurrentScope, "");
	initScope(&CurrentScope, NULL);
	CurrentIdentifier = EMPTY_LEXEME;

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

Token handleLex(Lexeme lexeme, int lineNumber, Token token, int value, MetaKind kind) {
	// printToken(token);
	printSourceCode(lexeme, lineNumber);

	MetaValue metaValue;
	metaValue.token = token;
	metaValue.lexeme = lexeme;

	switch (kind) {
		case IDTYPE_META_KIND:
			metaValue.type = value;
			break;
		case OPERATOR_META_KIND:
			metaValue.type = value;
			break;
		default:
			metaValue.identifier = lexeme;
			break;
	}

	yylval.meta = metaValue;
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
	addToSymbolTable(CurrentScope->table, identifier.meta.identifier, type.meta.type);
	return;
}

void checkIdentifierExists(YYSTYPE identifier) {
	SymbolPointer idPointer = searchIdentifier(CurrentScope, identifier.meta.identifier);
	char message[200];

	if (idPointer == NULL) {
		sprintf(message, "erro semântico: o identificador %s não foi declarado", identifier.meta.lexeme);
		hasSemanticError = 1;
		yyerror(message);
		// YYABORT;
	}
}

void checkIdentifierNotExists(YYSTYPE identifier) {
	char message[200];
	SymbolPointer idPointer = searchIdentifierCurrentScope(CurrentScope, identifier.meta.identifier);

	if (idPointer != NULL) {
		sprintf(message, "erro semântico - o identificador %s já foi declarado no escopo atual", identifier.meta.lexeme);
		hasSemanticError = 1;
		yyerror(message);
		// YYABORT;
	}
}

void checkTypesMatch(YYSTYPE identifier, YYSTYPE target) {
	char message[200];

	SymbolPointer idPointer = searchIdentifier(CurrentScope, identifier.meta.lexeme);
	IDType targetType = target.meta.type;
	IDType identifierType = identifier.meta.type;

	// Se o identificador que chegar for uma primitiva.. Ex: trem Palavra x ingual "Batata" uai
	// Batata é uma primitiva do tipo string e ja possui seu tipo retornado em IDType.
	if (idPointer == NULL && identifierType != UNKNOWN_ID_TYPE) {
		if (identifierType != targetType) {
			sprintf(message, "erro semântico - tipo %s esperado para o identificador %s ", idTypeToString(targetType), identifier.meta.lexeme);
			hasSemanticError = 1;
			yyerror(message);
			return;
		}

		return;
	}

	// Se o identificador que chegar for um identifier... Ex: trem Palavra x ingual y uai
	// y é uma constante do tipo string e possui seu tipo armazenado na tabela de simbolos
	if (idPointer != NULL && idPointer->type != targetType) {
		sprintf(message, "erro semântico - tipo %s esperado para o identificador %s ", idTypeToString(targetType), idPointer->lexeme);
		hasSemanticError = 1;
		yyerror(message);
		return;
	}
}

void handleFunctionOpen(YYSTYPE identifier) {
	CurrentIdentifier = identifier.lexeme;
}

void handleFunctionClose() {
	CurrentIdentifier = EMPTY_LEXEME;
}

void checkFunctionReturnType(YYSTYPE value) {
	char message[200];
	SymbolPointer functionPointer = searchIdentifier(CurrentScope, CurrentIdentifier);

	if (functionPointer == NULL) {
		sprintf(message, "erro fatal ao avaliar o paramêtro %s, a função não existe", value.meta.lexeme);
		hasSemanticError = 1;
		yyerror(message);
		return;
	}

	IDType valueType = value.meta.type;
	IDType functionType = functionPointer->type;

	if (functionType != valueType) {
		sprintf(message, "erro semântico - tipo %s esperado para o retorno da função %s ", idTypeToString(functionType), functionPointer->lexeme);
		hasSemanticError = 1;
		yyerror(message);
		return;
	}
}
