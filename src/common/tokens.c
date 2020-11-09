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
		default:
			return cprintf(RED, "?????");
	}
}
