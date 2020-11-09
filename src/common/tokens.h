/**
 * Define tipos de padrão que o programa reconhece e como imprmi-los.
 * @author Gustavo Viegas (3026)
 *
 **/

#ifndef tokens_h
#define tokens_h

#include <stdlib.h>
#include "logger.h"

/**
 * Token da linguagem
 **/
typedef enum Token
{
	MODULE_START = 258,
	MODULE_END = 259,
	ASSIGN = 260,
	DELIMITER = 261,
	CONST = 262,
	TYPE = 263,
	IDENTIFIER = 264,
	RELOP = 265,
	MATHOP = 266,
	NUMBER = 267,
	BOOLEAN = 268,
	RETURN = 269,
	STRING = 270,
	NIL = 271,
	ATOM = 272,
	IF = 273,
	ELSE = 274,
	IF_END = 275,
	FUNC_START = 276,
	FUNC_END = 277,
	THEN = 278,

	PARAN_OPEN = 279,
	PARAN_CLOSE = 280,
	BRACK_OPEN = 281,
	BRACK_CLOSE = 282,
	COMMA = 283
} Token;

/**
 * Imprime a saída informando o token encontrado.
 *  @arg Token token
 */
void printToken(Token token);

#endif
