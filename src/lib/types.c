#include "types.h"

// Imprime a saída informando o tipo encontrado e o seu lexema.
void printPattern(Pattern pattern, Lexeme lexeme) {
	printLine();
	cprintf(YELLOW, "Tipo: ");

	switch (pattern) {
	case IDENTIFIER:
		cprintf(GREEN, "%28s", "Identificador");
		break;
	case INT:
		cprintf(GREEN, "%28s", "Inteiro");
		break;
	case FLOAT:
		cprintf(GREEN, "%28s", "Float");
		break;
	case STRING:
		cprintf(GREEN, "%28s", "String");
		break;
	case ATOM:
		cprintf(GREEN, "%28s", "Átomo");
		break;
	case NIL:
		cprintf(GREEN, "%28s", "Nulo");
		break;
	case TRUE:
		cprintf(GREEN, "%28s", "Verdadeiro");
		break;
	case FALSE:
		cprintf(GREEN, "%28s", "Falso");
		break;
	case ASSIGN:
		cprintf(GREEN, "%28s", "Igual Designação");
		break;
	case AND:
		cprintf(GREEN, "%28s", "E lógico");
		break;
	case OR:
		cprintf(GREEN, "%28s", "Ou lógico");
		break;
	case NOT:
		cprintf(GREEN, "%28s", "Não lógico");
		break;
	case GT:
		cprintf(GREEN, "%28s", "Maior que");
		break;
	case LT:
		cprintf(GREEN, "%28s", "Menor que");
		break;
	case MOD:
		cprintf(GREEN, "%28s", "Módulo");
		break;
	case EQUAL:
		cprintf(GREEN, "%28s", "Igual comparativo");
		break;
	case NOT_EQUAL:
		cprintf(GREEN, "%28s", "Diferente");
		break;
	case SUM:
		cprintf(GREEN, "%28s", "Soma");
		break;
	case SUB:
		cprintf(GREEN, "%28s", "Subtração");
		break;
	case MUL:
		cprintf(GREEN, "%28s", "Multiplicação");
		break;
	case DIV:
		cprintf(GREEN, "%28s", "Divisão");
		break;
	case POW:
		cprintf(GREEN, "%28s", "Potência");
		break;
	case FUNC_START:
		cprintf(GREEN, "%28s", "Inicio Função");
		break;
	case FUNC_END:
		cprintf(GREEN, "%28s", "Fim Função");
		break;
	case MODULE_START:
		cprintf(GREEN, "%28s", "Início Módulo");
		break;
	case MODULE_END:
		cprintf(GREEN, "%28s", "Fim Módulo");
		break;
	case PARAN_OPEN:
		cprintf(GREEN, "%28s", "Abre Parenteses");
		break;
	case PARAN_CLOSE:
		cprintf(GREEN, "%28s", "Fecha Parenteses");
		break;
	case BRACK_OPEN:
		cprintf(GREEN, "%28s", "Abre Colchete");
		break;
	case BRACK_CLOSE:
		cprintf(GREEN, "%28s", "Fecha Colchete");
		break;
	case COMMA:
		cprintf(GREEN, "%28s", "Vírgula");
		break;
	case PRINT:
		cprintf(GREEN, "%28s", "Print");
		break;
	case IF:
		cprintf(GREEN, "%28s", "Se condicional");
		break;
	case THEN:
		cprintf(GREEN, "%28s", "Inicio bloco");
		break;
	case ELSE:
		cprintf(GREEN, "%28s", "Se não condicional");
		break;
	case END:
		cprintf(GREEN, "%28s", "Fim bloco");
		break;
	case CONST:
		cprintf(GREEN, "%28s", "Constante");
		break;
	case DELIMITER:
		cprintf(GREEN, "%28s", "Delimitador (;)");
		break;
	case RETURN:
		cprintf(GREEN, "%28s", "Retorno");
		break;
	case STATIC_TYPE:
		cprintf(GREEN, "%28s", "Tipo de Dado");
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
