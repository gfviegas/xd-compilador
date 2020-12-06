/**
 * Define tipos de padrão que o programa reconhece e como imprmi-los.
 * @author Gustavo Viegas (3026)
 *
 **/

#ifndef tokens_h
#define tokens_h

#include <stdlib.h>
#include <string.h>
#include "logger.h"

/**
 * Token da linguagem
 **/
typedef enum Token {
	UNKNOWN_TOKEN = -1,
	MODULE_START_TOKEN = 258,
	MODULE_END_TOKEN = 259,
	ASSIGN_TOKEN = 260,
	DELIMITER_TOKEN = 261,
	CONST_TOKEN = 262,
	TYPE_TOKEN = 263,
	IDENTIFIER_TOKEN = 264,
	RELOP_TOKEN = 265,
	MATHOP_TOKEN = 266,
	NUMBER_TOKEN = 267,
	BOOLEAN_TOKEN = 268,
	RETURN_TOKEN = 269,
	STRING_TOKEN = 270,
	CHAR_TOKEN = 271,
	NIL_TOKEN = 272,
	ATOM_TOKEN = 273,
	IF_TOKEN = 274,
	ELSE_TOKEN = 275,
	IF_END_TOKEN = 276,
	FUNC_START_TOKEN = 277,
	FUNC_END_TOKEN = 278,
	THEN_TOKEN = 279,
	PARAN_OPEN_TOKEN = 280,
	PARAN_CLOSE_TOKEN = 281,
	BRACK_OPEN_TOKEN = 282,
	BRACK_CLOSE_TOKEN = 283,
	COMMA_TOKEN = 284
} Token;

typedef enum OperatorType {
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
} OperatorType;

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

typedef enum MetaKind {
	UNKNOWN_META_KIND = -1,
	IDTYPE_META_KIND,
	OPERATOR_META_KIND,
} MetaKind;

/**
 * Um lexema... basicamente uma string
 **/
typedef char *Lexeme;


// Representacao de uma celula qualquer para o yyval
typedef struct MetaValue {
	union {
		OperatorType operator;
		IDType type;
		char* identifier;
	};
	Lexeme lexeme;
	Token token;
} MetaValue;

char *tokenToString(Token token);
char *operatorToString(OperatorType operator);
char *idTypeToString(IDType type);
IDType stringToIDType(char* str);

/**
 * Imprime a saída informando o token encontrado.
 *  @arg Token token
 */
void printToken(Token token);

void printLineNumber(int lineNumber);

void printSourceCode(Lexeme lexeme, int lineNumber);

void printTable(void);

#endif
