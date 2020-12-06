#include "tokens.h"

char* tokenToString(Token token) {
	switch (token) {
		case MODULE_START_TOKEN:
			return "MODULE_START";
		case MODULE_END_TOKEN:
			return "MODULE_END";
		case ASSIGN_TOKEN:
			return "ASSIGN";
		case DELIMITER_TOKEN:
			return "DELIMITER";
		case CONST_TOKEN:
			return "CONST";
		case TYPE_TOKEN:
			return "TYPE";
		case IDENTIFIER_TOKEN:
			return "IDENTIFIER";
		case RELOP_TOKEN:
			return "RELOP";
		case MATHOP_TOKEN:
			return "MATHOP";
		case NUMBER_TOKEN:
			return "NUMBER";
		case BOOLEAN_TOKEN:
			return "BOOLEAN";
		case RETURN_TOKEN:
			return "RETURN";
		case STRING_TOKEN:
			return "STRING";
		case NIL_TOKEN:
			return "NIL";
		case ATOM_TOKEN:
			return "ATOM";
		case IF_TOKEN:
			return "IF";
		case ELSE_TOKEN:
			return "ELSE";
		case IF_END_TOKEN:
			return "IF_END";
		case FUNC_START_TOKEN:
			return "FUNC_START";
		case FUNC_END_TOKEN:
			return "FUNC_END";
		case THEN_TOKEN:
			return "THEN";
		case PARAN_OPEN_TOKEN:
			return "PARAN_OPEN";
		case PARAN_CLOSE_TOKEN:
			return "PARAN_CLOSE";
		case BRACK_OPEN_TOKEN:
			return "BRACK_OPEN";
		case BRACK_CLOSE_TOKEN:
			return "BRACK_CLOSE";
		case COMMA_TOKEN:
			return "COMMA";
		default:
			return "?????";
	}
}

char* operatorToString(OperatorType operator) {
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
			return "NONE";
	}
}

char* idTypeToString(IDType type) {
	switch (type) {
		case INT_ID_TYPE:
			return "Numero";
		case FLOAT_ID_TYPE:
			return "NumeroQuebrado";
		case CHAR_ID_TYPE:
			return "Letra";
		case STRING_ID_TYPE:
			return "Palavra";
		case BINARY_ID_TYPE:
			return "ZeriUm";
		case BOOLEAN_ID_TYPE:
			return "ÉOuNumÉ";
		case ATOM_ID_TYPE:
			return "Bolota";
		case ARRAY_ID_TYPE:
			return "Lista";
		case LIST_ID_TYPE:
			return "Vetorr";
		case QUEUE_ID_TYPE:
			return "Marpa";
		case STACK_ID_TYPE:
			return "Parr";
		case MAP_ID_TYPE:
			return "Pia";
		case TUPLE_ID_TYPE:
			return "Fila";
		case DOCUMENT_ID_TYPE:
			return "Documento";
		default:
			return "NONE";
	}
}

IDType stringToIDType(char* str) {
	if (strcmp(str, "Numero") == 0) {
		return INT_ID_TYPE;
	} else if (strcmp(str, "NumeroQuebrado") == 0) {
		return FLOAT_ID_TYPE;
	} else if (strcmp(str, "Letra") == 0) {
		return CHAR_ID_TYPE;
	} else if (strcmp(str, "Palavra") == 0) {
		return STRING_ID_TYPE;
	} else if (strcmp(str, "ZeriUm") == 0) {
		return BINARY_ID_TYPE;
	} else if (strcmp(str, "ÉOuNumÉ") == 0) {
		return BOOLEAN_ID_TYPE;
	} else if (strcmp(str, "Bolota") == 0) {
		return ATOM_ID_TYPE;
	} else if (strcmp(str, "Lista") == 0) {
		return ARRAY_ID_TYPE;
	} else if (strcmp(str, "Vetorr") == 0) {
		return LIST_ID_TYPE;
	} else if (strcmp(str, "Marpa") == 0) {
		return QUEUE_ID_TYPE;
	} else if (strcmp(str, "Parr") == 0) {
		return STACK_ID_TYPE;
	} else if (strcmp(str, "Pia") == 0) {
		return MAP_ID_TYPE;
	} else if (strcmp(str, "Fila") == 0) {
		return TUPLE_ID_TYPE;
	} else if (strcmp(str, "Documento") == 0) {
		return DOCUMENT_ID_TYPE;
	}

	return UNKNOWN_ID_TYPE;
}

void printToken(Token token) {
	char* tokenStr = tokenToString(token);
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
		MODULE_START_TOKEN,
		MODULE_END_TOKEN,
		ASSIGN_TOKEN,
		DELIMITER_TOKEN,
		CONST_TOKEN,
		TYPE_TOKEN,
		IDENTIFIER_TOKEN,
		RELOP_TOKEN,
		MATHOP_TOKEN,
		NUMBER_TOKEN,
		BOOLEAN_TOKEN,
		RETURN_TOKEN,
		STRING_TOKEN,
		NIL_TOKEN,
		ATOM_TOKEN,
		IF_TOKEN,
		ELSE_TOKEN,
		IF_END_TOKEN,
		FUNC_START_TOKEN,
		FUNC_END_TOKEN,
		THEN_TOKEN,
		PARAN_OPEN_TOKEN,
		PARAN_CLOSE_TOKEN,
		BRACK_OPEN_TOKEN,
		BRACK_CLOSE_TOKEN,
		COMMA_TOKEN
	};

	for (int i = 0; i < 26; i++) {
		cprintf(MAGENTA, "%d", tokenList[i]);
		printf(" -> ");
		printToken(tokenList[i]);
		printf("\n");
	}
}
