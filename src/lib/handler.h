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

// Variáveis do YACC/LEX
extern int yylineno, yychar, yydebug;
extern char* yytext;

// Variáveis centrais de estado
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
 *
 * @return  int         Retorno padrão de funções main em C
 */
int run(void);

/**
 * Callback quando um erro acontece
 *
 * @param   char*  str  Mensagem a ser impressa sobre o erro
 *
 * @return  void
 */
void handleError(const char *str);

/**
 * Retorna o token para um lexema fornecido, imprime o código fonte e define o valor semântico
 *
 * @param   Lexeme  	lexeme  Lexema lido
 * @param   int  		lineNumber  Linha na qual o lexema foi lido
 * @param   Token  		token  Qual token está atrelado a este lexema
 * @param   int  		value  Metavalor atrelado a este lexema
 * @param   MetaKind	kind   Qual tipo de metavalor esta atrelado a este lexema
 *
 * @return  Token         Token atrelado a este lexema
 */
Token handleLex(Lexeme lexeme, int lineNumber, Token token, int value, MetaKind kind);

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
