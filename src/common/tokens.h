/**
 * Define tipos de padrão que o programa reconhece e como imprmi-los.
 * @author Gustavo Viegas (3026)
 *
 **/

#ifndef tokens_h
#define tokens_h

#include <stdlib.h>

/**
 * Token da linguagem
 **/
typedef enum Token
{
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
	FUNC_END
} Token;

#endif
