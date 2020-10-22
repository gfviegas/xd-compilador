#include "types.h"

void printPretty(Pattern pattern, Lexeme lexeme) {
	printLine();
	cprintf(YELLOW, "Tipo: ");

	switch (pattern) {
		case POS_INT:
			cprintf(GREEN, "%28s", "Inteiro Positivo");
			break;
		case NEG_INT:
			cprintf(GREEN, "%28s", "Inteiro Negativo");
			break;
		case FLOAT:
			cprintf(GREEN, "%28s", "Decimal");
			break;
		case LICENSE_PLATE:
			cprintf(GREEN, "%28s", "Placa de Carro");
			break;
		case WORD:
			cprintf(GREEN, "%28s", "Palavra");
			break;
		case PHONE:
			cprintf(GREEN, "%28s", "Telefone");
			break;
		case NAME:
			cprintf(GREEN, "%28s", "Nome Proprio");
			break;
		case PHONE_NINE_DIGITS:
			cprintf(GREEN, "%28s", "Telefone com Nove Digitos");
			break;
		case PHONE_FULL:
			cprintf(GREEN, "%28s", "Telefone com DDD");
			break;
		case EMAIL:
			cprintf(GREEN, "%28s", "Endereco de email");
			break;
		case CEP:
			cprintf(GREEN, "%28s", "CEP");
			break;

		default:
			cprintf(RED, "%28s", "DESCONHECIDO");
			break;
	}

	cprintf(CYAN, "   ||   ");
	cprintf(YELLOW, " Lexema: ");
	cprintf(GREEN, "%s", lexeme);
	printf("%s", ANSI_COLOR_RESET);
}

void printUgly(Pattern pattern, Lexeme lexeme) {
	switch (pattern) {
		case POS_INT:
			printf("Foi encontrado um numero inteiro positivo. LEXEMA: %s\n", lexeme);
			break;
		case NEG_INT:
			printf("Foi encontrado um numero inteiro negativo. LEXEMA: %s\n", lexeme);
			break;
		case FLOAT:
			printf("Foi encontrado um numero com parte decimal. LEXEMA: %s\n", lexeme);
			break;
		case LICENSE_PLATE:
			printf("Foi encontrado uma placa. LEXEMA: %s\n", lexeme);
			break;
		case WORD:
			printf("Foi encontrado uma palavra. LEXEMA: %s\n", lexeme);
			break;
		case PHONE:
			printf("Foi encontrado um telefone. LEXEMA: %s\n", lexeme);
			break;
		case NAME:
			printf("Foi encontrado um nome proprio. LEXEMA: %s\n", lexeme);
			break;
		case PHONE_NINE_DIGITS:
			printf("Foi encontrado um telefone com nove digitos. LEXEMA: %s\n", lexeme);
			break;
		case PHONE_FULL:
			printf("Foi encontrado um telefone com DDD. LEXEMA: %s\n", lexeme);
			break;
		case EMAIL:
			printf("Foi encontrado um endereço de email. LEXEMA: %s\n", lexeme);
			break;
		case CEP:
			printf("Foi encontrado um CEP. LEXEMA: %s\n", lexeme);
			break;

		default:
			printf("DESCONHECIDO. LEXEMA: %s\n", lexeme);
			break;
	}
}

// Imprime a saída informando o tipo encontrado e o seu lexema.
void printPattern(Pattern pattern, Lexeme lexeme) {
	const char *prettyEnv = getenv("PRETTY");

	if (prettyEnv != NULL) {
		return printPretty(pattern, lexeme);
	}

	return printUgly(pattern, lexeme);
}
