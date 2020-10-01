#include "logger.h"
#include "types.h"

void printPattern(Pattern pattern, Lexeme lexeme) {
	printLine();
	cprintf(YELLOW, "\tLexema: ");
	cprintf(GREEN, "%s\n\t", lexeme);
	cprintf(YELLOW, "Tipo: ");

	switch (pattern) {
	case POS_INT:
		cprintf(GREEN, "Inteiro Positivo.");
		break;
	case NEG_INT:
		cprintf(GREEN, "Inteiro Negativo.");
		break;
	case FLOAT:
		cprintf(GREEN, "Decimal.");
		break;
	case LICENSE_PLATE:
		cprintf(GREEN, "Placa de Carro.");
		break;
	case WORD:
		cprintf(GREEN, "Palavra.");
		break;
	case PHONE:
		cprintf(GREEN, "Telefone.");
		break;
	case NAME:
		cprintf(GREEN, "Nome Próprio.");
		break;

	default:
		cprintf(RED, "DESCONHECIDO.");
		break;
	}
}
