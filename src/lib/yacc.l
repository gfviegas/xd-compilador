%{
	#include "tokens.h"
%}

%start begin
%union {
	int XESQUE;
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
%%

begin                 :   MODULE_START stmt MODULE_END
                      ;
stmt                  :   /* épsilon */
                      |   declarationVariable DELIMITER stmt
                      |   declarationFunction stmt
                      |   callFunction DELIMITER stmt
                      |   conditional stmt
                      |   returnOperation DELIMITER stmt
                      ;
declarationVariable   :   CONST TYPE IDENTIFIER { checkIdentifierNotExists($3); } ASSIGN value { checkTypesMatch($6, $2); handleStatement($2, $3); }
                      |   CONST TYPE IDENTIFIER { checkIdentifierNotExists($3); handleStatement($2, $3); }
                      ;
declarationFunction   :   FUNC_START TYPE IDENTIFIER { checkIdentifierNotExists($3); handleStatement($2, $3); handleNewScope(); handleFunctionOpen($3); } PARAN_OPEN parameterDeclaration PARAN_CLOSE THEN stmt FUNC_END { handleFinishScope(); handleFunctionClose(); }
                      ;
conditional           :   IF PARAN_OPEN operation PARAN_CLOSE THEN { handleNewScope(); } stmt IF_END { handleFinishScope(); }
                      |   IF PARAN_OPEN operation PARAN_CLOSE THEN { handleNewScope(); } stmt ELSE stmt IF_END { handleFinishScope(); }
                      ;
operation             :   callFunction MATHOP callFunction
                      |   callFunction MATHOP NUMBER
                      |   NUMBER MATHOP callFunction
                      |   value RELOP value
                      |   value
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
                      |   TYPE IDENTIFIER { checkIdentifierNotExists($2); handleStatement($1, $2); } COMMA parameterDeclaration
                      |   TYPE IDENTIFIER { checkIdentifierNotExists($2); handleStatement($1, $2); }
                      ;
parameter             :   /* épsilon */
                      |   value COMMA parameter
                      |   value
                      ;
returnOperation       :   RETURN value { checkFunctionReturnType($2); }
                      ;

%%
