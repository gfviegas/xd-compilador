/**
 * Define tipos de padrão que o programa reconhece e como imprmi-los.
 * @author Gustavo Viegas (3026)
 *
 **/

#ifndef types_h
#define types_h

#include <stdlib.h>
#include "logger.h"

/**
 * Tipos de Padrão que o programa reconhece
 **/
typedef enum Pattern
{
	UNKNOWN,
	IDENTIFIER,
	INT,
	FLOAT,
	// BINARY,
	STRING,
	ATOM,
	NIL,
	TRUE,
	FALSE,
	ASSIGN,
	AND,
	OR,
	NOT,
	GT,
	LT,
	MOD,
	EQUAL,
	NOT_EQUAL,
	SUM,
	SUB,
	MUL,
	DIV,
	POW,
	FUNC_START,
	FUNC_END,
	MODULE_START,
	MODULE_END,
	PARAN_OPEN,
	PARAN_CLOSE,
	BRACK_OPEN,
	BRACK_CLOSE,
	COMMA,
	PRINT,
	IF,
	THEN,
	ELSE,
	END,
	CONST,
	DELIMITER,
	RETURN,
	STATIC_TYPE
} Pattern;

/**
 * Um lexema... basicamente uma string
 **/
typedef char *Lexeme;

/**
 * Imprime a saída informando o tipo encontrado e o seu lexema.
 *  @arg Pattern
 */
void printPattern(Pattern pattern, Lexeme lexeme);

#endif
