#include "tokens.h"

char* translateToken(Token token) {
	switch (token) {
		case MODULE_START:
			return "MODULE_START";
		case MODULE_END:
			return "MODULE_END";
		case ASSIGN:
			return "ASSIGN";
		case DELIMITER:
			return "DELIMITER";
		case CONST:
			return "CONST";
		case TYPE:
			return "TYPE";
		case IDENTIFIER:
			return "IDENTIFIER";
		case RELOP:
			return "RELOP";
		case MATHOP:
			return "MATHOP";
		case NUMBER:
			return "NUMBER";
		case BOOLEAN:
			return "BOOLEAN";
		case RETURN:
			return "RETURN";
		case STRING:
			return "STRING";
		case NIL:
			return "NIL";
		case ATOM:
			return "ATOM";
		case IF:
			return "IF";
		case ELSE:
			return "ELSE";
		case IF_END:
			return "IF_END";
		case FUNC_START:
			return "FUNC_START";
		case FUNC_END:
			return "FUNC_END";
		case THEN:
			return "THEN";
		case PARAN_OPEN:
			return "PARAN_OPEN";
		case PARAN_CLOSE:
			return "PARAN_CLOSE";
		case BRACK_OPEN:
			return "BRACK_OPEN";
		case BRACK_CLOSE:
			return "BRACK_CLOSE";
		case COMMA:
			return "COMMA";
		default:
			return "?????";
	}
}

char* translateOperator(Operator operator) {
	switch (operator) {
		case RELOP_EQ:
			return "Igualdade";
		case RELOP_NE:
			return "Não-Igual";
		case RELOP_GT:
			return "Maior que";
		case RELOP_LT:
			return "Menor que";
		case RELOP_OR:
			return "Ou lógico";
		case RELOP_AND:
			return "E lógico";
		case MAHTOP_PLUS:
			return "Soma";
		case MAHTOP_MINUS:
			return "Subtração";
		case MAHTOP_MUL:
			return "Multiplicação";
		case MAHTOP_DIV:
			return "Divisão";
		case MAHTOP_MOD:
			return "Módulo";
		case MAHTOP_POW:
			return "Potência";
		default:
			return "?????";
	}
}

void printToken(Token token) {
	char* tokenStr = translateToken(token);
	return cprintf(YELLOW, tokenStr);
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
