/* Primeira parte:  */
%{
  #include <stdio.h>
  #include "symbol.c"
  #include "handler.c"

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
char                 		["'].["']
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

"Nada"				{ return handleLex(strdup(yytext), yylineno, NIL_TOKEN, UNKNOWN_OPERATOR, UNKNOWN_META_KIND); }
"Vera"				{ return handleLex(strdup(yytext), yylineno, BOOLEAN_TOKEN, UNKNOWN_OPERATOR, UNKNOWN_META_KIND); }
"Bobagi"			{ return handleLex(strdup(yytext), yylineno, BOOLEAN_TOKEN, UNKNOWN_OPERATOR, UNKNOWN_META_KIND); }
"ingual"			{ return handleLex(strdup(yytext), yylineno, ASSIGN_TOKEN, UNKNOWN_OPERATOR, UNKNOWN_META_KIND); }

"ingualzin"			{ return handleLex(strdup(yytext), yylineno, RELOP_TOKEN, RELOP_EQ, OPERATOR_META_KIND); }
"nadavê com"		{ return handleLex(strdup(yytext), yylineno, RELOP_TOKEN, RELOP_NE, OPERATOR_META_KIND); }
"maió que"			{ return handleLex(strdup(yytext), yylineno, RELOP_TOKEN, RELOP_GT, OPERATOR_META_KIND); }
"menó que"			{ return handleLex(strdup(yytext), yylineno, RELOP_TOKEN, RELOP_LT, OPERATOR_META_KIND); }
"ou"				{ return handleLex(strdup(yytext), yylineno, RELOP_TOKEN, RELOP_OR, OPERATOR_META_KIND); }
"i"					{ return handleLex(strdup(yytext), yylineno, RELOP_TOKEN, RELOP_AND, OPERATOR_META_KIND); }

"mais"				{ return handleLex(strdup(yytext), yylineno, MATHOP_TOKEN, MAHTOP_PLUS, OPERATOR_META_KIND); }
"menus"				{ return handleLex(strdup(yytext), yylineno, MATHOP_TOKEN, MAHTOP_MINUS, OPERATOR_META_KIND); }
"veiz"				{ return handleLex(strdup(yytext), yylineno, MATHOP_TOKEN, MAHTOP_MUL, OPERATOR_META_KIND); }
"divididu"			{ return handleLex(strdup(yytext), yylineno, MATHOP_TOKEN, MAHTOP_DIV, OPERATOR_META_KIND); }
"resto"				{ return handleLex(strdup(yytext), yylineno, MATHOP_TOKEN, MAHTOP_MOD, OPERATOR_META_KIND); }
"elevado a"			{ return handleLex(strdup(yytext), yylineno, MATHOP_TOKEN, MAHTOP_POW, OPERATOR_META_KIND); }

"intao"				{ return handleLex(strdup(yytext), yylineno, THEN_TOKEN, UNKNOWN_OPERATOR, UNKNOWN_META_KIND); }
"intaotabao"		{ return handleLex(strdup(yytext), yylineno, IF_END_TOKEN, UNKNOWN_OPERATOR, UNKNOWN_META_KIND); }
"cêsabese"			{ return handleLex(strdup(yytext), yylineno, IF_TOKEN, UNKNOWN_OPERATOR, UNKNOWN_META_KIND); }
"sinao"				{ return handleLex(strdup(yytext), yylineno, ELSE_TOKEN, UNKNOWN_OPERATOR, UNKNOWN_META_KIND); }
"negocio"			{ return handleLex(strdup(yytext), yylineno, FUNC_START_TOKEN, UNKNOWN_OPERATOR, UNKNOWN_META_KIND); }
"tendeu"			{ return handleLex(strdup(yytext), yylineno, FUNC_END_TOKEN, UNKNOWN_OPERATOR, UNKNOWN_META_KIND); }
"assim"				{ return handleLex(strdup(yytext), yylineno, MODULE_START_TOKEN, UNKNOWN_OPERATOR, UNKNOWN_META_KIND); }
"cabô"				{ return handleLex(strdup(yytext), yylineno, MODULE_END_TOKEN, UNKNOWN_OPERATOR, UNKNOWN_META_KIND); }
"trem"				{ return handleLex(strdup(yytext), yylineno, CONST_TOKEN, UNKNOWN_OPERATOR, UNKNOWN_META_KIND); }
"desembucha"		{ return handleLex(strdup(yytext), yylineno, IDENTIFIER_TOKEN, UNKNOWN_OPERATOR, UNKNOWN_META_KIND); }
"devorve"			{ return handleLex(strdup(yytext), yylineno, RETURN_TOKEN, UNKNOWN_OPERATOR, UNKNOWN_META_KIND); }

"("					{ return handleLex(strdup(yytext), yylineno, PARAN_OPEN_TOKEN, UNKNOWN_OPERATOR, UNKNOWN_META_KIND); }
")"					{ return handleLex(strdup(yytext), yylineno, PARAN_CLOSE_TOKEN, UNKNOWN_OPERATOR, UNKNOWN_META_KIND); }
"["					{ return handleLex(strdup(yytext), yylineno, BRACK_OPEN_TOKEN, UNKNOWN_OPERATOR, UNKNOWN_META_KIND); }
"]"					{ return handleLex(strdup(yytext), yylineno, BRACK_CLOSE_TOKEN, UNKNOWN_OPERATOR, UNKNOWN_META_KIND); }
","					{ return handleLex(strdup(yytext), yylineno, COMMA_TOKEN, UNKNOWN_OPERATOR, UNKNOWN_META_KIND); }

"Numero"			{ return handleLex(strdup(yytext), yylineno, TYPE_TOKEN, INT_ID_TYPE, IDTYPE_META_KIND); }
"NumeroQuebrado"	{ return handleLex(strdup(yytext), yylineno, TYPE_TOKEN, FLOAT_ID_TYPE, IDTYPE_META_KIND); }
"Letra"				{ return handleLex(strdup(yytext), yylineno, TYPE_TOKEN, CHAR_ID_TYPE, IDTYPE_META_KIND); }
"Palavra"			{ return handleLex(strdup(yytext), yylineno, TYPE_TOKEN, STRING_ID_TYPE, IDTYPE_META_KIND); }
"ZeriUm"			{ return handleLex(strdup(yytext), yylineno, TYPE_TOKEN, BINARY_ID_TYPE, IDTYPE_META_KIND); }
"ÉOuNumÉ"			{ return handleLex(strdup(yytext), yylineno, TYPE_TOKEN, BOOLEAN_ID_TYPE, IDTYPE_META_KIND); }
"Bolota"			{ return handleLex(strdup(yytext), yylineno, TYPE_TOKEN, ATOM_ID_TYPE, IDTYPE_META_KIND); }
"Lista"				{ return handleLex(strdup(yytext), yylineno, TYPE_TOKEN, ARRAY_ID_TYPE, IDTYPE_META_KIND); }
"Vetorr"			{ return handleLex(strdup(yytext), yylineno, TYPE_TOKEN, LIST_ID_TYPE, IDTYPE_META_KIND); }
"Marpa"				{ return handleLex(strdup(yytext), yylineno, TYPE_TOKEN, QUEUE_ID_TYPE, IDTYPE_META_KIND); }
"Parr"				{ return handleLex(strdup(yytext), yylineno, TYPE_TOKEN, STACK_ID_TYPE, IDTYPE_META_KIND); }
"Pia"				{ return handleLex(strdup(yytext), yylineno, TYPE_TOKEN, MAP_ID_TYPE, IDTYPE_META_KIND); }
"Fila"				{ return handleLex(strdup(yytext), yylineno, TYPE_TOKEN, TUPLE_ID_TYPE, IDTYPE_META_KIND); }
"Documento"			{ return handleLex(strdup(yytext), yylineno, TYPE_TOKEN, DOCUMENT_ID_TYPE, IDTYPE_META_KIND); }


{integer}         	{ return handleLex(strdup(yytext), yylineno, NUMBER_TOKEN, INT_ID_TYPE, IDTYPE_META_KIND); }
{float}         	{ return handleLex(strdup(yytext), yylineno, NUMBER_TOKEN, FLOAT_ID_TYPE, IDTYPE_META_KIND); }
"vazio"				{ return handleLex(strdup(yytext), yylineno, NIL_TOKEN, UNKNOWN_OPERATOR, IDTYPE_META_KIND); }
{atom}         		{ return handleLex(strdup(yytext), yylineno, ATOM_TOKEN, ATOM_ID_TYPE, IDTYPE_META_KIND); }
{char}         		{ return handleLex(strdup(yytext), yylineno, CHAR_TOKEN, CHAR_ID_TYPE, IDTYPE_META_KIND); }
{string}         	{ return handleLex(strdup(yytext), yylineno, STRING_TOKEN, STRING_ID_TYPE, IDTYPE_META_KIND); }

"uai"				{ return handleLex(strdup(yytext), yylineno, DELIMITER_TOKEN, UNKNOWN_OPERATOR, UNKNOWN_META_KIND); }
{identifier}      	{ return handleLex(strdup(yytext), yylineno, IDENTIFIER_TOKEN, UNKNOWN_OPERATOR, UNKNOWN_META_KIND); }


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
