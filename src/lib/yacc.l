%start begin
%token MODULE_START MODULE_END ASSIGN DELIMITER CONST TYPE IDENTIFIER RELOP MATHOP NUMBER BOOLEAN RETURN STRING NIL ATOM IF ELSE IF_END FUNC_START FUNC_END THEN PARAN_OPEN PARAN_CLOSE BRACK_OPEN BRACK_CLOSE COMMA
%%

begin                 :   MODULE_START stmt MODULE_END
                      ;
stmt                  :   /* épsilon */
                      |   declarationVariable DELIMITER stmt
                      |   declarationFunction stmt
                      |   callFunction stmt
                      |   conditional stmt
                      |   returnOperation DELIMITER stmt
                      ;
declarationVariable   :   CONST TYPE IDENTIFIER ASSIGN value
                      |   CONST TYPE IDENTIFIER
                      ;
declarationFunction   :   FUNC_START TYPE IDENTIFIER PARAN_OPEN parameterDeclaration PARAN_CLOSE THEN stmt FUNC_END
                      ;
conditional           :   IF PARAN_OPEN expr PARAN_CLOSE THEN stmt IF_END
                      |   IF PARAN_OPEN expr PARAN_CLOSE THEN stmt ELSE stmt IF_END
                      ;
operation             :   IDENTIFIER MATHOP IDENTIFIER
                      |   operation MATHOP operation
                      |   operation MATHOP IDENTIFIER
                      |   IDENTIFIER MATHOP operation
                      |   NUMBER MATHOP IDENTIFIER
                      |   IDENTIFIER MATHOP NUMBER
                      |   callFunction
                      ;
expr                  :   term RELOP term
                      |   term
                      |   callFunction
                      ;
callFunction          :   IDENTIFIER PARAN_OPEN parameter PARAN_CLOSE
                      |   IDENTIFIER
                      ;
term                  :   IDENTIFIER
                      |   NUMBER
                      ;
value                 :   STRING
                      |   NUMBER
                      |   BOOLEAN
                      |   IDENTIFIER
                      |   callFunction
                      ;
parameterDeclaration  :   /* épsilon */
                      |   TYPE IDENTIFIER COMMA parameterDeclaration
                      |   TYPE IDENTIFIER
                      ;
parameter             :   /* épsilon */
                      |   IDENTIFIER COMMA parameter
                      |   IDENTIFIER
                      ;
returnOperation       :   RETURN IDENTIFIER
                      |   RETURN operation
                      ;

%%
