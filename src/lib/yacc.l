%start begin
%union {
	int value;
	char *lexeme;
}
%token MODULE_START MODULE_END ASSIGN DELIMITER CONST
%token <value>TYPE
%token <lexeme> IDENTIFIER
%token <value>RELOP <value>MATHOP
%token NUMBER BOOLEAN RETURN STRING NIL ATOM IF ELSE IF_END FUNC_START FUNC_END THEN PARAN_OPEN PARAN_CLOSE BRACK_OPEN BRACK_CLOSE COMMA
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
declarationVariable   :   CONST TYPE IDENTIFIER { checkIdentifierNotExists($3); } ASSIGN value { handleStatement($2, $3); }
                      |   CONST TYPE IDENTIFIER { checkIdentifierNotExists($3); } { handleStatement($2, $3); }
                      ;
declarationFunction   :   FUNC_START TYPE IDENTIFIER { checkIdentifierNotExists($3); } PARAN_OPEN parameterDeclaration PARAN_CLOSE THEN { handleNewScope(); } stmt FUNC_END { handleFinishScope(); }
                      ;
conditional           :   IF PARAN_OPEN expr PARAN_CLOSE THEN { handleNewScope(); } stmt IF_END { handleFinishScope(); }
                      |   IF PARAN_OPEN expr PARAN_CLOSE THEN { handleNewScope(); } stmt ELSE stmt IF_END { handleFinishScope(); }
                      ;
operation             :   IDENTIFIER { checkIdentifierExists($1); } MATHOP IDENTIFIER { checkIdentifierExists($3); }
                      |   operation MATHOP operation
                      |   operation MATHOP IDENTIFIER { checkIdentifierExists($3); }
                      |   IDENTIFIER { checkIdentifierExists($1); } MATHOP operation
                      |   NUMBER MATHOP IDENTIFIER { checkIdentifierExists($3); }
                      |   IDENTIFIER { checkIdentifierExists($1); } MATHOP NUMBER
                      |   callFunction
                      ;
expr                  :   value RELOP value
                      |   value
                      |   callFunction
                      ;
callFunction          :   IDENTIFIER { checkIdentifierExists($1); } PARAN_OPEN parameter PARAN_CLOSE
                      |   IDENTIFIER { checkIdentifierExists($1); }
                      ;
value                 :   STRING
                      |   NUMBER
                      |   BOOLEAN
                      |   IDENTIFIER { checkIdentifierExists($1); }
					  |	  NIL
                      |   callFunction
                      ;
parameterDeclaration  :   /* épsilon */
                      |   TYPE IDENTIFIER { checkIdentifierNotExists($2); } COMMA parameterDeclaration
                      |   TYPE IDENTIFIER { checkIdentifierNotExists($2); }
                      ;
parameter             :   /* épsilon */
                      |   value COMMA parameter
                      |   value
                      ;
returnOperation       :   RETURN value
                      |   RETURN operation
                      ;

%%
