/* Primeira parte:  */
%{
  #include <stdio.h>
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

"Nada"				{ handleLex(yytext, yylineno, NIL, UNKNOWN_OPERATOR); }
"Vera"				{ handleLex(yytext, yylineno, BOOLEAN, UNKNOWN_OPERATOR); }
"Bobagi"			{ handleLex(yytext, yylineno, BOOLEAN, UNKNOWN_OPERATOR); }
"ingual"			{ handleLex(yytext, yylineno, ASSIGN, UNKNOWN_OPERATOR); }

"ingualzin"			{ handleLex(yytext, yylineno, RELOP, RELOP_EQ); }
"nadavê com"		{ handleLex(yytext, yylineno, RELOP, RELOP_NE); }
"maió que"			{ handleLex(yytext, yylineno, RELOP, RELOP_GT); }
"menó que"			{ handleLex(yytext, yylineno, RELOP, RELOP_LT); }
"ou"				{ handleLex(yytext, yylineno, RELOP, RELOP_OR); }
"i"					{ handleLex(yytext, yylineno, RELOP, RELOP_AND); }

"mais"				{ handleLex(yytext, yylineno, MATHOP, MAHTOP_PLUS); }
"menus"				{ handleLex(yytext, yylineno, MATHOP, MAHTOP_MINUS); }
"veiz"				{ handleLex(yytext, yylineno, MATHOP, MAHTOP_MUL); }
"divididu"			{ handleLex(yytext, yylineno, MATHOP, MAHTOP_DIV); }
"resto"				{ handleLex(yytext, yylineno, MATHOP, MAHTOP_MOD); }
"elevado a"			{ handleLex(yytext, yylineno, MATHOP, MAHTOP_POW); }

"intao"				{ handleLex(yytext, yylineno, THEN, UNKNOWN_OPERATOR); }
"intaotabao"		{ handleLex(yytext, yylineno, IF_END, UNKNOWN_OPERATOR); }
"cêsabese"			{ handleLex(yytext, yylineno, IF, UNKNOWN_OPERATOR); }
"sinao"				{ handleLex(yytext, yylineno, ELSE, UNKNOWN_OPERATOR); }
"negocio"			{ handleLex(yytext, yylineno, FUNC_START, UNKNOWN_OPERATOR); }
"tendeu"			{ handleLex(yytext, yylineno, FUNC_END, UNKNOWN_OPERATOR); }
"assim"				{ handleLex(yytext, yylineno, MODULE_START, UNKNOWN_OPERATOR); }
"cabô"				{ handleLex(yytext, yylineno, MODULE_END, UNKNOWN_OPERATOR); }
"trem"				{ handleLex(yytext, yylineno, CONST, UNKNOWN_OPERATOR); }
"desembucha"		{ handleLex(yytext, yylineno, IDENTIFIER, UNKNOWN_OPERATOR); }
"devorve"			{ handleLex(yytext, yylineno, RETURN, UNKNOWN_OPERATOR); }

"("					{ handleLex(yytext, yylineno, PARAN_OPEN, UNKNOWN_OPERATOR); }
")"					{ handleLex(yytext, yylineno, PARAN_CLOSE, UNKNOWN_OPERATOR); }
"["					{ handleLex(yytext, yylineno, BRACK_OPEN, UNKNOWN_OPERATOR); }
"]"					{ handleLex(yytext, yylineno, BRACK_CLOSE, UNKNOWN_OPERATOR); }
","					{ handleLex(yytext, yylineno, COMMA, UNKNOWN_OPERATOR); }

{staticType}		{ handleLex(yytext, yylineno, TYPE, UNKNOWN_OPERATOR); }
{integer}         	{ handleLex(yytext, yylineno, NUMBER, UNKNOWN_OPERATOR); }
{float}         	{ handleLex(yytext, yylineno, NUMBER, UNKNOWN_OPERATOR); }
"vazio"				{ handleLex(yytext, yylineno, NIL, UNKNOWN_OPERATOR); }
{atom}         		{ handleLex(yytext, yylineno, ATOM, UNKNOWN_OPERATOR); }
{string}         	{ handleLex(yytext, yylineno, STRING, UNKNOWN_OPERATOR); }

"uai"				{ handleLex(yytext, yylineno, DELIMITER, UNKNOWN_OPERATOR); }
{identifier}      	{ handleLex(yytext, yylineno, IDENTIFIER, UNKNOWN_OPERATOR); }


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
