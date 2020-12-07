/**
 * Define funções auxiliares no código .l
 * @author Gustavo Viegas (3026)
 *
 **/

#ifndef handler_h
#define handler_h

#include "stack.h"
#include "tokens.h"
#include "scope.h"
#include "codegen.h"
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

StackPointer NodeStack;
int currentNodeParent;

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

// Geracao de árvore sintática
void handleBeginST();
void handlePopST();
void handleGenericST(char *label);
void handleVariableDeclarationST(YYSTYPE identifier, YYSTYPE type);
void handleParameterDeclarationST(YYSTYPE identifier, YYSTYPE type);
void handleFunctionBeginST(YYSTYPE identifier, YYSTYPE type);
void handleIfBeginST();
void handleIfStmtBeginST();
void handleMathOpST(YYSTYPE arg1, YYSTYPE mathop, YYSTYPE arg2);
void handleRelOpST(YYSTYPE arg1, YYSTYPE relop, YYSTYPE arg2);
void handleValueST(YYSTYPE value);
void handleReturnST(YYSTYPE identifier);
void handleFunctionBodyBeginST();
void handleCallFuncBeginST(YYSTYPE identifier);

// Coisas do Lex/Yacc
void yyerror(const char *str);
int yylex(void);
int yyparse(void);

#endif
