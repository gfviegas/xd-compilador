/**
 * Define funções auxiliares no código .l
 * @author Gustavo Viegas (3026)
 *
 **/

#ifndef handler_h
#define handler_h

#include "tokens.h"
#include "scope.h"
#include "yacc.h"

// typedef union YYSTYPE {
// 	int value;
// 	char *lexeme;
// 	MetaValue meta;
// } YYSTYPE;


// extern YYSTYPE yylval;
// extern YYSTYPE yylval;
extern int yylineno, yychar, yydebug;//, yylval;
extern char* yytext;

int hasError = 0;
int hasSemanticError = 0;
ScopePointer CurrentScope;

int isFunctionBeingEvaluated = 0;
Lexeme CurrentIdentifier;
const Lexeme EMPTY_LEXEME = "";

/**
 * Script principal
 **/
int run(void);

void handleError(const char *str);

Token handleIdentifier(Lexeme lexeme, int lineNumber, Token token, int value, MetaKind kind);

void handleFunctionOpen(YYSTYPE identifier);
void handleFunctionClose();

void handleNewScope(void);
void handleFinishScope(void);
void handleStatement(YYSTYPE type, YYSTYPE identifier);

void checkIdentifierExists(YYSTYPE identifier);
void checkIdentifierNotExists(YYSTYPE identifier);
void checkTypesMatch(YYSTYPE identifier, YYSTYPE target);
void checkFunctionReturnType(YYSTYPE value);

// Coisas do Lex/Yacc
void yyerror(const char *str);
int yylex(void);
int yyparse(void);

#endif
