#include "tokens.h"

void printToken(Token token) {
	switch (token) {
		case MODULE_START:
			return cprintf(YELLOW, "MODULE_START");
		case MODULE_END:
			return cprintf(YELLOW, "MODULE_END");
		case ASSIGN:
			return cprintf(YELLOW, "ASSIGN");
		case DELIMITER:
			return cprintf(YELLOW, "DELIMITER");
		case CONST:
			return cprintf(YELLOW, "CONST");
		case TYPE:
			return cprintf(YELLOW, "TYPE");
		case IDENTIFIER:
			return cprintf(YELLOW, "IDENTIFIER");
		case RELOP:
			return cprintf(YELLOW, "RELOP");
		case MATHOP:
			return cprintf(YELLOW, "MATHOP");
		case NUMBER:
			return cprintf(YELLOW, "NUMBER");
		case BOOLEAN:
			return cprintf(YELLOW, "BOOLEAN");
		case RETURN:
			return cprintf(YELLOW, "RETURN");
		case STRING:
			return cprintf(YELLOW, "STRING");
		case NIL:
			return cprintf(YELLOW, "NIL");
		case ATOM:
			return cprintf(YELLOW, "ATOM");
		case IF:
			return cprintf(YELLOW, "IF");
		case ELSE:
			return cprintf(YELLOW, "ELSE");
		case IF_END:
			return cprintf(YELLOW, "IF_END");
		case FUNC_START:
			return cprintf(YELLOW, "FUNC_START");
		case FUNC_END:
			return cprintf(YELLOW, "FUNC_END");
		case THEN:
			return cprintf(YELLOW, "THEN");
		case PARAN_OPEN:
			return cprintf(YELLOW, "PARAN_OPEN");
		case PARAN_CLOSE:
			return cprintf(YELLOW, "PARAN_CLOSE");
		case BRACK_OPEN:
			return cprintf(YELLOW, "BRACK_OPEN");
		case BRACK_CLOSE:
			return cprintf(YELLOW, "BRACK_CLOSE");
		case COMMA:
			return cprintf(YELLOW, "COMMA");
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

void printTable(void) {
	Token tokenList[26] = {
		MODULE_START,
		MODULE_END,
		ASSIGN,
		DELIMITER,
		CONST,
		TYPE,
		IDENTIFIER,
		RELOP,
		MATHOP,
		NUMBER,
		BOOLEAN,
		RETURN,
		STRING,
		NIL,
		ATOM,
		IF,
		ELSE,
		IF_END,
		FUNC_START,
		FUNC_END,
		THEN,
		PARAN_OPEN,
		PARAN_CLOSE,
		BRACK_OPEN,
		BRACK_CLOSE,
		COMMA,
	};

	for (int i = 0; i < 26; i++) {
		cprintf(MAGENTA, "%d", tokenList[i]);
		printf(" -> ");
		printToken(tokenList[i]);
		printf("\n");
	}
}
