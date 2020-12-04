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
typedef enum Token {
	UNKNOWN_TOKEN = -1,
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

typedef enum Operator {
	UNKNOWN_OPERATOR = -1,
	RELOP_EQ,
	RELOP_NE,
	RELOP_GT,
	RELOP_LT,
	RELOP_OR,
	RELOP_AND,

	MAHTOP_PLUS,
	MAHTOP_MINUS,
	MAHTOP_MUL,
	MAHTOP_DIV,
	MAHTOP_MOD,
	MAHTOP_POW
} Operator;

typedef enum IDType {
	UNKNOWN_ID_TYPE = -1,
	INT_ID_TYPE,
	FLOAT_ID_TYPE,
	CHAR_ID_TYPE,
	STRING_ID_TYPE,
	BINARY_ID_TYPE,
	BOOLEAN_ID_TYPE,
	ATOM_ID_TYPE,
	ARRAY_ID_TYPE,
	LIST_ID_TYPE,
	QUEUE_ID_TYPE,
	STACK_ID_TYPE,
	MAP_ID_TYPE,
	TUPLE_ID_TYPE,
	DOCUMENT_ID_TYPE
} IDType;

/**
 * Um lexema... basicamente uma string
 **/
typedef char *Lexeme;

char *translateToken(Token token);
char *translateOperator(Operator operator);
char *translateIDType(IDType type);

	/**
 * Imprime a saída informando o token encontrado.
 *  @arg Token token
 */
	void printToken(Token token);

void printLineNumber(int lineNumber);

void printSourceCode(Lexeme lexeme, int lineNumber);

void printTable(void);

#endif
