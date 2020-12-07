#include "handler.h"
#include "stack.c"

int run(void) {
	// Inicializa dados dinamicos
	initStack(&NodeStack);
	initScope(&CurrentScope, NULL);
	CurrentIdentifier = EMPTY_LEXEME;
	initCodeGen();

	if (CurrentScope == NULL) {
		cprintf(ERROR2, "Escopo inicial retornou NULL");
		printf("\n\n");
		finishCodeGen();
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
		finishCodeGen();
		return 0;
	}

	cprintf(RED, "Trem de compilar deu ruim!\nPrograma incorreto!\n");
	finishCodeGen();
	return 0;
}

Token handleLex(Lexeme lexeme, int lineNumber, Token token, int value, MetaKind kind) {
	printToken(token);
	printSourceCode(lexeme, lineNumber);

	MetaValue metaValue;
	metaValue.token = token;
	metaValue.lexeme = lexeme;

	switch (kind) {
		case IDTYPE_META_KIND:
			metaValue.type = value;
			break;
		case OPERATOR_META_KIND:
			metaValue.operator = value;
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
	SymbolPointer valuePointer = searchIdentifier(CurrentScope, value.meta.lexeme);
	IDType valueType = value.meta.type;
	IDType functionType = functionPointer->type;

	if (functionPointer == NULL) {
		sprintf(message, "erro ao avaliar o paramêtro %s, identificador não encontrado", value.meta.lexeme);
		hasSemanticError = 1;
		yyerror(message);
		return;
	}

	if (valuePointer == NULL && valueType != functionType) {
		sprintf(message, "erro semântico - tipo %s esperado para o retorno da função %s ", idTypeToString(functionType), functionPointer->lexeme);
		hasSemanticError = 1;
		yyerror(message);
		return;
	}

	if (valuePointer != NULL && valuePointer->type != functionType) {
		sprintf(message, "erro semântico - tipo %s esperado para o retorno da função %s ", idTypeToString(functionType), functionPointer->lexeme);
		hasSemanticError = 1;
		yyerror(message);
		return;
	}
}

void handleBeginST() {
	int newNode = insertNodeGraph("START", EMPTY_LEXEME);
	currentNodeParent = newNode;
	push(NodeStack, newNode);
}

void handlePopST() {
	pop(NodeStack);
}

void handleGenericST(char *label) {
	int newNode = insertNodeGraph(label, EMPTY_LEXEME);
	insertConnection(currentNodeParent, newNode);

	push(NodeStack, newNode);
}

void handleVariableDeclarationST(YYSTYPE identifier, YYSTYPE type) {
	int assignNode = insertNodeGraph("ASSIGN", "constant");

	int idNode = insertNodeGraph(identifier.meta.lexeme, type.meta.lexeme);
	insertConnection(getTop(NodeStack), assignNode);
	insertConnection(assignNode, idNode);

	push(NodeStack, idNode);
}

void handleParameterDeclarationST(YYSTYPE identifier, YYSTYPE type) {
	int assignNode = insertNodeGraph("ASSIGN", "parameter");

	int idNode = insertNodeGraph(identifier.meta.lexeme, type.meta.lexeme);
	insertConnection(getTop(NodeStack), assignNode);
	insertConnection(assignNode, idNode);
}

void handleIfBeginST() {
	int idNode = insertNodeGraph("IF", EMPTY_LEXEME);
	insertConnection(getTop(NodeStack), idNode);

	push(NodeStack, idNode);

	int condNode = insertNodeGraph("COND", EMPTY_LEXEME);
	insertConnection(idNode, condNode);

	push(NodeStack, condNode);
}

void handleIfStmtBeginST() {
	pop(NodeStack);

	int blockNode = insertNodeGraph("THEN", EMPTY_LEXEME);
	insertConnection(getTop(NodeStack), blockNode);

	push(NodeStack, blockNode);
}

void handleFunctionBeginST(YYSTYPE identifier, YYSTYPE type) {
	int assignNode = insertNodeGraph("ASSIGN", "function");

	int idNode = insertNodeGraph(identifier.meta.lexeme, type.meta.lexeme);
	insertConnection(getTop(NodeStack), assignNode);
	insertConnection(assignNode, idNode);

	push(NodeStack, idNode);

	int paramNode = insertNodeGraph("PARAMS", EMPTY_LEXEME);
	insertConnection(idNode, paramNode);

	push(NodeStack, paramNode);
}

void handleFunctionBodyBeginST() {
	pop(NodeStack);

	int blockNode = insertNodeGraph("THEN", EMPTY_LEXEME);
	insertConnection(getTop(NodeStack), blockNode);

	push(NodeStack, blockNode);
}

void handleMathOpST(YYSTYPE arg1, YYSTYPE mathop, YYSTYPE arg2) {
	int operationNode = insertNodeGraph("OPERATION", "mathop");

	int mathopNode = insertNodeGraph("MATHOP", mathop.meta.lexeme);
	insertConnection(getTop(NodeStack), operationNode);
	insertConnection(operationNode, mathopNode);
	insertConnection(mathopNode, insertNodeGraph(arg1.meta.lexeme, EMPTY_LEXEME));
	insertConnection(mathopNode, insertNodeGraph(arg2.meta.lexeme, EMPTY_LEXEME));
}

void handleRelOpST(YYSTYPE arg1, YYSTYPE relop, YYSTYPE arg2) {
	int operationNode = insertNodeGraph("OPERATION", "relop");

	int relopNode = insertNodeGraph("RELOP", relop.meta.lexeme);
	insertConnection(getTop(NodeStack), operationNode);
	insertConnection(operationNode, relopNode);
	insertConnection(relopNode, insertNodeGraph(arg1.meta.lexeme, EMPTY_LEXEME));
	insertConnection(relopNode, insertNodeGraph(arg2.meta.lexeme, EMPTY_LEXEME));
}

void handleValueST(YYSTYPE value) {
	int valueNode = insertNodeGraph("VALUE", EMPTY_LEXEME);

	int idNode = insertNodeGraph(value.meta.lexeme, EMPTY_LEXEME);
	insertConnection(getTop(NodeStack), valueNode);
	insertConnection(valueNode, idNode);
}

void handleReturnST(YYSTYPE identifier) {
	int valueNode = insertNodeGraph("RETURN", EMPTY_LEXEME);

	int idNode = insertNodeGraph(identifier.meta.lexeme, EMPTY_LEXEME);
	insertConnection(getTop(NodeStack), valueNode);
	insertConnection(valueNode, idNode);
}
