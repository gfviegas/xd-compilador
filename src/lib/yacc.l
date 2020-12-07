%{
	#include "tokens.h"
%}

%start begin
%union {
	char *lexeme;
	MetaValue meta;
}
%token MODULE_START MODULE_END ASSIGN DELIMITER CONST
%token <meta> TYPE
%token <meta> IDENTIFIER
%token <meta> RELOP
%token <meta> MATHOP
%token <meta> NUMBER
%token <meta> BOOLEAN
%token RETURN
%token <meta> STRING
%token <meta> CHAR
%token <meta> NIL
%token <meta> ATOM
%token IF ELSE IF_END FUNC_START FUNC_END THEN PARAN_OPEN PARAN_CLOSE BRACK_OPEN BRACK_CLOSE COMMA

%type <meta> value
%type <meta> callFunction
%type <meta> operation
%%

begin                 :   MODULE_START { handleBeginST(); } stmt MODULE_END
                      ;
stmt                  :   /* épsilon */
                      |   declarationVariable DELIMITER stmt
                      |   declarationFunction stmt
                      |   callFunction DELIMITER stmt
                      |   conditional stmt
                      |   returnOperation DELIMITER stmt
                      ;
declarationVariable   :   CONST TYPE IDENTIFIER { checkIdentifierNotExists($3); handleVariableDeclarationST($3, $2); } ASSIGN operation { checkTypesMatch($6, $2); handleStatement($2, $3); handlePopST(); }
                    //   |   CONST TYPE IDENTIFIER { checkIdentifierNotExists($3); } ASSIGN operation { checkTypesMatch($6, $2); handleStatement($2, $3); }
                      |   CONST TYPE IDENTIFIER { checkIdentifierNotExists($3); handleVariableDeclarationST($3, $2); handleStatement($2, $3); handlePopST(); }
                      ;
declarationFunction   :   FUNC_START TYPE IDENTIFIER { checkIdentifierNotExists($3); handleStatement($2, $3); handleNewScope(); handleFunctionOpen($3); handleFunctionBeginST($3, $2); } PARAN_OPEN parameterDeclaration PARAN_CLOSE THEN { handleFunctionBodyBeginST(); } stmt FUNC_END { handleFinishScope(); handleFunctionClose(); handlePopST();handlePopST(); }
                      ;
conditional           :   IF PARAN_OPEN { handleIfBeginST(); } operation PARAN_CLOSE THEN { handleNewScope(); handleIfStmtBeginST(); } stmt IF_END { handleFinishScope(); handlePopST(); handlePopST(); }
                      |   IF PARAN_OPEN { handleIfBeginST(); } operation PARAN_CLOSE THEN { handleNewScope(); handleIfStmtBeginST(); } stmt ELSE stmt IF_END { handleFinishScope(); handlePopST(); handlePopST(); }
                      ;
operation             :   callFunction MATHOP callFunction { handleMathOpST($1, $2, $3); }
                      |   callFunction MATHOP NUMBER { handleMathOpST($1, $2, $3); }
                      |   NUMBER MATHOP callFunction { handleMathOpST($1, $2, $3); }
                      |   value MATHOP value { handleMathOpST($1, $2, $3); }
                      |   value RELOP value { handleRelOpST($1, $2, $3); }
                      |   value { handleValueST($1); }
                      ;
callFunction          :   IDENTIFIER { checkIdentifierExists($1); } PARAN_OPEN parameter PARAN_CLOSE
                      |   IDENTIFIER { checkIdentifierExists($1); }
                      ;
value                 :   CHAR
                      |   STRING
                      |   ATOM
                      |   NUMBER
                      |   BOOLEAN
                      |   IDENTIFIER { checkIdentifierExists($1); }
					  |	  NIL
                      |   callFunction
                      ;
parameterDeclaration  :   /* épsilon */
                      |   TYPE IDENTIFIER { checkIdentifierNotExists($2); handleStatement($1, $2); handleParameterDeclarationST($2, $1); } COMMA parameterDeclaration
                      |   TYPE IDENTIFIER { checkIdentifierNotExists($2); handleStatement($1, $2); handleParameterDeclarationST($2, $1); }
                      ;
parameter             :   /* épsilon */
                      |   value COMMA parameter
                      |   value
                      ;
returnOperation       :   RETURN value { checkFunctionReturnType($2); handleReturnST($2); }
                      ;

%%
