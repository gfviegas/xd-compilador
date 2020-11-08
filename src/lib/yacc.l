%start begin
%token MODULE_START MODULE_END ASSIGN DELIMITER CONST TYPE IDENTIFIER RELOP MATHOP NUMBER BOOLEAN RETURN STRING NIL ATOM IF ELSE IF_END FUNC_START FUNC_END THEN
%%

begin                 :   MODULE_START stmt MODULE_END
                      ;
stmt                  :   /* épsilon */
                      |   stmt stmt
                      |   declarationVariable DELIMITER
                      |   declarationFunction
                      |   callFunction
                      |   conditional
                      |   returnOperation DELIMITER
                      ;
declarationVariable   :   CONST TYPE IDENTIFIER ASSIGN value
                      |   CONST TYPE IDENTIFIER
                      ;
declarationFunction   :   FUNC_START TYPE IDENTIFIER '('parameterDeclaration')' THEN stmt FUNC_END
                      ;
conditional           :   IF '('expr')' THEN stmt IF_END
                      |   IF '('expr')' THEN stmt ELSE stmt IF_END
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
callFunction          :   IDENTIFIER'('parameter')'
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
                      |   TYPE IDENTIFIER',' parameterDeclaration
                      |   TYPE IDENTIFIER
                      ;
parameter             :   /* épsilon */
                      |   IDENTIFIER',' parameter
                      |   IDENTIFIER
                      ;
returnOperation       :   RETURN IDENTIFIER DELIMITER
                      |   RETURN operation DELIMITER
                      ;

%%
