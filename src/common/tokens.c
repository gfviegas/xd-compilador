#include "tokens.h"

void printToken(Token token) {
	switch (token) {
		case TOK_MODULE_START:
			return cprintf(YELLOW, "MODULE_START");
		case TOK_MODULE_END:
			return cprintf(YELLOW, "MODULE_END");
		case TOK_ASSIGN:
			return cprintf(YELLOW, "ASSIGN");
		case TOK_DELIMITER:
			return cprintf(YELLOW, "DELIMITER");
		case TOK_CONST:
			return cprintf(YELLOW, "CONST");
		case TOK_TYPE:
			return cprintf(YELLOW, "TYPE");
		case TOK_IDENTIFIER:
			return cprintf(YELLOW, "IDENTIFIER");
		case TOK_RELOP:
			return cprintf(YELLOW, "RELOP");
		case TOK_MATHOP:
			return cprintf(YELLOW, "MATHOP");
		case TOK_NUMBER:
			return cprintf(YELLOW, "NUMBER");
		case TOK_BOOLEAN:
			return cprintf(YELLOW, "BOOLEAN");
		case TOK_RETURN:
			return cprintf(YELLOW, "RETURN");
		case TOK_STRING:
			return cprintf(YELLOW, "STRING");
		case TOK_NIL:
			return cprintf(YELLOW, "NIL");
		case TOK_ATOM:
			return cprintf(YELLOW, "ATOM");
		case TOK_IF:
			return cprintf(YELLOW, "IF");
		case TOK_ELSE:
			return cprintf(YELLOW, "ELSE");
		case TOK_IF_END:
			return cprintf(YELLOW, "IF_END");
		case TOK_FUNC_START:
			return cprintf(YELLOW, "FUNC_START");
		case TOK_FUNC_END:
			return cprintf(YELLOW, "FUNC_END");
		case TOK_THEN:
			return cprintf(YELLOW, "THEN");
		default:
			return cprintf(RED, "?????");
	}
}

void printLineNumber(int lineNumber) {
	cprintf(BLUE, "\n%d) ", lineNumber);
}

void printSourceCode(Lexeme lexeme, int lineNumber) {
	if (lineNumber == 1) {
		printLineNumber(lineNumber);
	}

	cprintf(CYAN, "%s ", lexeme);
}

// void printTable(int startIndex) {
// 	int lastSuccessful = 0;
// 	int index = startIndex;

// 	while (lastSuccessful < 5) {
// 		char *symbolName = yysymbol_name(index);

// 		if (symbolName == NULL) {
// 			lastSuccessful++;
// 			continue;
// 		}

// 		printf("%s \n", symbolName);
// 		lastSuccessful = 0;
// 	}
// }
