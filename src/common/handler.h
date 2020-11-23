/**
 * Define funções auxiliares no código .l
 * @author Gustavo Viegas (3026)
 *
 **/

#ifndef handler_h
#define handler_h

#include "symbol.h"

extern int yylineno, yychar, yydebug, yylval;
extern char* yytext;

int hasError = 0;
SymbolTablePointer STable;

/**
 * Script principal
 **/
int run(void);

void handleError(const char *str);

Token handleLex(Lexeme lexeme, int lineNumber, Token token, Operator op);

#endif