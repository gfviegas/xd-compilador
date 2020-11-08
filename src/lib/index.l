/* Primeira parte:  */
%{
  #include "../common/logger.h"
  #include "../common/tokens.h"
  #include "y.tab.h"
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
{eol}    			{}
{comment}    		{}

"Nada"				{ return NIL; }
"Vera"				{ return BOOLEAN; }
"Bobagi"			{ return BOOLEAN; }
"ingual"			{ return ASSIGN; }

"ingualzin"			{ return RELOP; }
"nadavê com"		{ return RELOP; }
"maió que"			{ return RELOP; }
"menó que"			{ return RELOP; }
"ou"				{ return RELOP; }
"i"					{ return RELOP; }

"mais"				{ return MATHOP; }
"menus"				{ return MATHOP; }
"veiz"				{ return MATHOP; }
"divididu"			{ return MATHOP; }
"resto"				{ return MATHOP; }
"elevado a"			{ return MATHOP; }

"intao"				{ return THEN; }
"intaotabao"		{ return IF_END; }
"cêsabese"			{ return IF; }
"sinao"				{ return ELSE; }
"negocio"			{ return FUNC_START; }
"tendeu"			{ return FUNC_END; }
"assim"				{ return MODULE_START; }
"cabô"				{ return MODULE_END; }
"trem"				{ return CONST; }
"desembucha"		{ return PRINT; }
"devorve"			{ return RETURN; }

{staticType}		{ return TYPE; }
{integer}         	{ return NUMBER; }
{float}         	{ return NUMBER; }
"vazio"				{ return NIL; }
{atom}         		{ return ATOM; }
{string}         	{ return STRING; }

"uai"				{ return DELIMITER; }
{identifier}      	{ return IDENTIFIER; }

%%
/* Fim da segunda parte */
/* Terceira parte: Código C */
int main(void) {
  	yylex();
	printf("\n");
  	return 0;
}

/* Fim da terceira parte */
