/* Primeira parte:  */
%{
  #include "../common/logger.h"
  #include "../common/types.h"
%}

/* Como não precisamos de usar esse código em outra etapa, essa flag é adicionada */
%option noyywrap

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
{eol}    			{}
{comment}    		{}

"Nada"				{ printPattern(NIL, yytext); }
"Vera"				{ printPattern(TRUE, yytext); }
"Bobagi"			{ printPattern(FALSE, yytext); }
"ingual"			{ printPattern(ASSIGN, yytext); }

"ingualzin"			{ printPattern(EQUAL, yytext); }
"nadavê com"		{ printPattern(NOT_EQUAL, yytext); }
"maió que"			{ printPattern(GT, yytext); }
"menó que"			{ printPattern(LT, yytext); }
"ou"				{ printPattern(OR, yytext); }
"i"					{ printPattern(AND, yytext); }

"mais"				{ printPattern(SUM, yytext); }
"menus"				{ printPattern(SUB, yytext); }
"veiz"				{ printPattern(MUL, yytext); }
"divididu"			{ printPattern(DIV, yytext); }
"resto"				{ printPattern(MOD, yytext); }
"elevado a"			{ printPattern(POW, yytext); }

"intao"				{ printPattern(THEN, yytext); }
"intaotabao"		{ printPattern(END, yytext); }
"cêsabese"			{ printPattern(IF, yytext); }
"sinao"				{ printPattern(ELSE, yytext); }
"negocio"			{ printPattern(FUNC_START, yytext); }
"tendeu"			{ printPattern(FUNC_END, yytext); }
"assim"				{ printPattern(MODULE_START, yytext); }
"cabô"				{ printPattern(MODULE_END, yytext); }
"trem"				{ printPattern(CONST, yytext); }
"desembucha"		{ printPattern(PRINT, yytext); }
"devorve"			{ printPattern(RETURN, yytext); }

{staticType}		{ printPattern(STATIC_TYPE, yytext); }
{integer}         	{ printPattern(INT, yytext); }
{float}         	{ printPattern(FLOAT, yytext); }
"vazio"				{ printPattern(NIL, yytext); }
{atom}         		{ printPattern(ATOM, yytext); }
{string}         	{ printPattern(STRING, yytext); }

"("					{ printPattern(PARAN_OPEN, yytext); }
")"					{ printPattern(PARAN_CLOSE, yytext); }
"["					{ printPattern(BRACK_OPEN, yytext); }
"]"					{ printPattern(BRACK_CLOSE, yytext); }
","					{ printPattern(COMMA, yytext); }

"uai"				{ printPattern(DELIMITER, yytext); }
{identifier}      	{ printPattern(IDENTIFIER, yytext); }

%%
/* Fim da segunda parte */
/* Terceira parte: Código C */
int main(void) {
  	yylex();
	printf("\n");
  	return 0;
}

/* Fim da terceira parte */
