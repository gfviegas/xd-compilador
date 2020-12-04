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
atom						\:{downcaseLetter}+
string                 		["'].*["']
comment      				#.*$
identifier             		{letter}+({upcaseLetter}{downcaseLetter}*)*
staticType					(Numero|NumeroQuebrado|Letra|Palavra|ZeriUm|ÉOuNumÉ|Bolota|Lista|Vetorr|Marpa|Parr|Pia|Fila|Documento)
ws		       				[ \t\r]+
eol	       					\n

/* Fim da primeira parte */
/* Segunda parte: Pattern match! */
%%
{ws}    			{}
{eol}    			{ printLineNumber(++yylineno); }
{comment}    		{}

"Nada"				{ return handleLex(strdup(yytext), yylineno, NIL, UNKNOWN_OPERATOR); }
"Vera"				{ return handleLex(strdup(yytext), yylineno, BOOLEAN, UNKNOWN_OPERATOR); }
"Bobagi"			{ return handleLex(strdup(yytext), yylineno, BOOLEAN, UNKNOWN_OPERATOR); }
"ingual"			{ return handleLex(strdup(yytext), yylineno, ASSIGN, UNKNOWN_OPERATOR); }

"ingualzin"			{ return handleLex(strdup(yytext), yylineno, RELOP, RELOP_EQ); }
"nadavê com"		{ return handleLex(strdup(yytext), yylineno, RELOP, RELOP_NE); }
"maió que"			{ return handleLex(strdup(yytext), yylineno, RELOP, RELOP_GT); }
"menó que"			{ return handleLex(strdup(yytext), yylineno, RELOP, RELOP_LT); }
"ou"				{ return handleLex(strdup(yytext), yylineno, RELOP, RELOP_OR); }
"i"					{ return handleLex(strdup(yytext), yylineno, RELOP, RELOP_AND); }

"mais"				{ return handleLex(strdup(yytext), yylineno, MATHOP, MAHTOP_PLUS); }
"menus"				{ return handleLex(strdup(yytext), yylineno, MATHOP, MAHTOP_MINUS); }
"veiz"				{ return handleLex(strdup(yytext), yylineno, MATHOP, MAHTOP_MUL); }
"divididu"			{ return handleLex(strdup(yytext), yylineno, MATHOP, MAHTOP_DIV); }
"resto"				{ return handleLex(strdup(yytext), yylineno, MATHOP, MAHTOP_MOD); }
"elevado a"			{ return handleLex(strdup(yytext), yylineno, MATHOP, MAHTOP_POW); }

"intao"				{ return handleLex(strdup(yytext), yylineno, THEN, UNKNOWN_OPERATOR); }
"intaotabao"		{ return handleLex(strdup(yytext), yylineno, IF_END, UNKNOWN_OPERATOR); }
"cêsabese"			{ return handleLex(strdup(yytext), yylineno, IF, UNKNOWN_OPERATOR); }
"sinao"				{ return handleLex(strdup(yytext), yylineno, ELSE, UNKNOWN_OPERATOR); }
"negocio"			{ return handleLex(strdup(yytext), yylineno, FUNC_START, UNKNOWN_OPERATOR); }
"tendeu"			{ return handleLex(strdup(yytext), yylineno, FUNC_END, UNKNOWN_OPERATOR); }
"assim"				{ return handleLex(strdup(yytext), yylineno, MODULE_START, UNKNOWN_OPERATOR); }
"cabô"				{ return handleLex(strdup(yytext), yylineno, MODULE_END, UNKNOWN_OPERATOR); }
"trem"				{ return handleLex(strdup(yytext), yylineno, CONST, UNKNOWN_OPERATOR); }
"desembucha"		{ return handleLex(strdup(yytext), yylineno, IDENTIFIER, UNKNOWN_OPERATOR); }
"devorve"			{ return handleLex(strdup(yytext), yylineno, RETURN, UNKNOWN_OPERATOR); }

"("					{ return handleLex(strdup(yytext), yylineno, PARAN_OPEN, UNKNOWN_OPERATOR); }
")"					{ return handleLex(strdup(yytext), yylineno, PARAN_CLOSE, UNKNOWN_OPERATOR); }
"["					{ return handleLex(strdup(yytext), yylineno, BRACK_OPEN, UNKNOWN_OPERATOR); }
"]"					{ return handleLex(strdup(yytext), yylineno, BRACK_CLOSE, UNKNOWN_OPERATOR); }
","					{ return handleLex(strdup(yytext), yylineno, COMMA, UNKNOWN_OPERATOR); }

"Numero"			{ return handleLex(strdup(yytext), yylineno, TYPE, INT_ID_TYPE); }
"NumeroQuebrado"	{ return handleLex(strdup(yytext), yylineno, TYPE, FLOAT_ID_TYPE); }
"Letra"				{ return handleLex(strdup(yytext), yylineno, TYPE, CHAR_ID_TYPE); }
"Palavra"			{ return handleLex(strdup(yytext), yylineno, TYPE, STRING_ID_TYPE); }
"ZeriUm"			{ return handleLex(strdup(yytext), yylineno, TYPE, BINARY_ID_TYPE); }
"ÉOuNumÉ"			{ return handleLex(strdup(yytext), yylineno, TYPE, BOOLEAN_ID_TYPE); }
"Bolota"			{ return handleLex(strdup(yytext), yylineno, TYPE, ATOM_ID_TYPE); }
"Lista"				{ return handleLex(strdup(yytext), yylineno, TYPE, ARRAY_ID_TYPE); }
"Vetorr"			{ return handleLex(strdup(yytext), yylineno, TYPE, LIST_ID_TYPE); }
"Marpa"				{ return handleLex(strdup(yytext), yylineno, TYPE, QUEUE_ID_TYPE); }
"Parr"				{ return handleLex(strdup(yytext), yylineno, TYPE, STACK_ID_TYPE); }
"Pia"				{ return handleLex(strdup(yytext), yylineno, TYPE, MAP_ID_TYPE); }
"Fila"				{ return handleLex(strdup(yytext), yylineno, TYPE, TUPLE_ID_TYPE); }
"Documento"			{ return handleLex(strdup(yytext), yylineno, TYPE, DOCUMENT_ID_TYPE); }


{integer}         	{ return handleLex(strdup(yytext), yylineno, NUMBER, UNKNOWN_OPERATOR); }
{float}         	{ return handleLex(strdup(yytext), yylineno, NUMBER, UNKNOWN_OPERATOR); }
"vazio"				{ return handleLex(strdup(yytext), yylineno, NIL, UNKNOWN_OPERATOR); }
{atom}         		{ return handleLex(strdup(yytext), yylineno, ATOM, UNKNOWN_OPERATOR); }
{string}         	{ return handleLex(strdup(yytext), yylineno, STRING, UNKNOWN_OPERATOR); }

"uai"				{ return handleLex(strdup(yytext), yylineno, DELIMITER, UNKNOWN_OPERATOR); }
{identifier}      	{ return handleLex(strdup(yytext), yylineno, IDENTIFIER, UNKNOWN_OPERATOR); }


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
