/**
 * Define funções auxiliares no código .l
 * @author Gustavo Viegas (3026)
 *
 **/

#ifndef handler_h
#define handler_h

#include "scope.h"

typedef union YYSTYPE {
	int value;
	char *lexeme;
} YYSTYPE;

extern YYSTYPE yylval;
// extern YYSTYPE yylval;
extern int yylineno, yychar, yydebug;//, yylval;
extern char* yytext;

int hasError = 0;
ScopePointer CurrentScope;

/**
 * Script principal
 **/
int run(void);

void handleError(const char *str);

Token handleIdentifier(Lexeme lexeme, int lineNumber, Token token, Operator op);

void handleNewScope(void);
void handleFinishScope(void);
void handleStatement(YYSTYPE type, YYSTYPE identifier);

// Coisas do Lex/Yacc
void yyerror(const char *str);
int yylex(void);
int yyparse(void);

#endif
