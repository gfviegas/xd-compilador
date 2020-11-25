/* Primeira parte:  */
%{
  #include <stdio.h>
  #include "../common/symbol.c"
  #include "../common/handler.c"

  int yylex(void);
%}

/* Definições regulares */
upcaseLetter      			[A-Z]
downcaseLetter    			[a-z]
letter						[a-zA-Z]
digit                  		[0-9]
/*boolean              		(Vera|Bobagi)*/
decimal         			[0-9]+
hexadecimal     			0X({digit}|[A-Fa-f])*
integer                		{hexadecimal}|{decimal}
float                 		[0-9]+(([Ee][+]([0-9]+))*|[.][0-9]+|[.][0-9]*[Ee][+][0-9]+)
atom						:{downcaseLetter}+
string                 		["'].*["']
comment      				#.*$
identifier             		{letter}+({upcaseLetter}{downcaseLetter}*)*
staticType					(Numero|NumeroQuebrado|Letra|Palavra|ZeriUm|ÉOuNumÉ|Bolota|Lista|Vetorr|Marpa|Parr|Pia|Fila|Documento)
ws		       				[ \t]+
eol	       					\n

/* Fim da primeira parte */
/* Segunda parte: Pattern match! */
%%
{ws}    			{}
{eol}    			{ printLineNumber(++yylineno); }
{comment}    		{}

"Nada"				{ handleLex(strdup(yytext), yylineno, NIL, UNKNOWN_OPERATOR); }
"Vera"				{ handleLex(strdup(yytext), yylineno, BOOLEAN, UNKNOWN_OPERATOR); }
"Bobagi"			{ handleLex(strdup(yytext), yylineno, BOOLEAN, UNKNOWN_OPERATOR); }
"ingual"			{ handleLex(strdup(yytext), yylineno, ASSIGN, UNKNOWN_OPERATOR); }

"ingualzin"			{ handleLex(strdup(yytext), yylineno, RELOP, RELOP_EQ); }
"nadavê com"		{ handleLex(strdup(yytext), yylineno, RELOP, RELOP_NE); }
"maió que"			{ handleLex(strdup(yytext), yylineno, RELOP, RELOP_GT); }
"menó que"			{ handleLex(strdup(yytext), yylineno, RELOP, RELOP_LT); }
"ou"				{ handleLex(strdup(yytext), yylineno, RELOP, RELOP_OR); }
"i"					{ handleLex(strdup(yytext), yylineno, RELOP, RELOP_AND); }

"mais"				{ handleLex(strdup(yytext), yylineno, MATHOP, MAHTOP_PLUS); }
"menus"				{ handleLex(strdup(yytext), yylineno, MATHOP, MAHTOP_MINUS); }
"veiz"				{ handleLex(strdup(yytext), yylineno, MATHOP, MAHTOP_MUL); }
"divididu"			{ handleLex(strdup(yytext), yylineno, MATHOP, MAHTOP_DIV); }
"resto"				{ handleLex(strdup(yytext), yylineno, MATHOP, MAHTOP_MOD); }
"elevado a"			{ handleLex(strdup(yytext), yylineno, MATHOP, MAHTOP_POW); }

"intao"				{ handleLex(strdup(yytext), yylineno, THEN, UNKNOWN_OPERATOR); }
"intaotabao"		{ handleLex(strdup(yytext), yylineno, IF_END, UNKNOWN_OPERATOR); }
"cêsabese"			{ handleLex(strdup(yytext), yylineno, IF, UNKNOWN_OPERATOR); }
"sinao"				{ handleLex(strdup(yytext), yylineno, ELSE, UNKNOWN_OPERATOR); }
"negocio"			{ handleLex(strdup(yytext), yylineno, FUNC_START, UNKNOWN_OPERATOR); }
"tendeu"			{ handleLex(strdup(yytext), yylineno, FUNC_END, UNKNOWN_OPERATOR); }
"assim"				{ handleLex(strdup(yytext), yylineno, MODULE_START, UNKNOWN_OPERATOR); }
"cabô"				{ handleLex(strdup(yytext), yylineno, MODULE_END, UNKNOWN_OPERATOR); }
"trem"				{ handleLex(strdup(yytext), yylineno, CONST, UNKNOWN_OPERATOR); }
"desembucha"		{ handleLex(strdup(yytext), yylineno, IDENTIFIER, UNKNOWN_OPERATOR); }
"devorve"			{ handleLex(strdup(yytext), yylineno, RETURN, UNKNOWN_OPERATOR); }

"("					{ handleLex(strdup(yytext), yylineno, PARAN_OPEN, UNKNOWN_OPERATOR); }
")"					{ handleLex(strdup(yytext), yylineno, PARAN_CLOSE, UNKNOWN_OPERATOR); }
"["					{ handleLex(strdup(yytext), yylineno, BRACK_OPEN, UNKNOWN_OPERATOR); }
"]"					{ handleLex(strdup(yytext), yylineno, BRACK_CLOSE, UNKNOWN_OPERATOR); }
","					{ handleLex(strdup(yytext), yylineno, COMMA, UNKNOWN_OPERATOR); }

{staticType}		{ handleLex(strdup(yytext), yylineno, TYPE, UNKNOWN_OPERATOR); }
{integer}         	{ handleLex(strdup(yytext), yylineno, NUMBER, UNKNOWN_OPERATOR); }
{float}         	{ handleLex(strdup(yytext), yylineno, NUMBER, UNKNOWN_OPERATOR); }
"vazio"				{ handleLex(strdup(yytext), yylineno, NIL, UNKNOWN_OPERATOR); }
{atom}         		{ handleLex(strdup(yytext), yylineno, ATOM, UNKNOWN_OPERATOR); }
{string}         	{ handleLex(strdup(yytext), yylineno, STRING, UNKNOWN_OPERATOR); }

"uai"				{ handleLex(strdup(yytext), yylineno, DELIMITER, UNKNOWN_OPERATOR); }
{identifier}      	{ handleLex(strdup(yytext), yylineno, IDENTIFIER, UNKNOWN_OPERATOR); }


%%
/* Fim da segunda parte */
/* Terceira parte: Código C */
int main(void) {
	return run();
}

void yyerror(const char *str) {
	handleError(str);
}

int yywrap() {
	return 1;
}

/* Fim da terceira parte */
