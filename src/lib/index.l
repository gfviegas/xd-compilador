/* Primeira parte:  */
%{
  #include <stdio.h>
  #include "../common/tokens.h"
//   #include "y.tab.h"
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

"Nada"				{ printSourceCode(yytext, yylineno); return NIL; }
"Vera"				{ printSourceCode(yytext, yylineno); return BOOLEAN; }
"Bobagi"			{ printSourceCode(yytext, yylineno); return BOOLEAN; }
"ingual"			{ printSourceCode(yytext, yylineno); return ASSIGN; }

"ingualzin"			{ printSourceCode(yytext, yylineno); return RELOP; }
"nadavê com"		{ printSourceCode(yytext, yylineno); return RELOP; }
"maió que"			{ printSourceCode(yytext, yylineno); return RELOP; }
"menó que"			{ printSourceCode(yytext, yylineno); return RELOP; }
"ou"				{ printSourceCode(yytext, yylineno); return RELOP; }
"i"					{ printSourceCode(yytext, yylineno); return RELOP; }

"mais"				{ printSourceCode(yytext, yylineno); return MATHOP; }
"menus"				{ printSourceCode(yytext, yylineno); return MATHOP; }
"veiz"				{ printSourceCode(yytext, yylineno); return MATHOP; }
"divididu"			{ printSourceCode(yytext, yylineno); return MATHOP; }
"resto"				{ printSourceCode(yytext, yylineno); return MATHOP; }
"elevado a"			{ printSourceCode(yytext, yylineno); return MATHOP; }

"intao"				{ printSourceCode(yytext, yylineno); return THEN; }
"intaotabao"		{ printSourceCode(yytext, yylineno); return IF_END; }
"cêsabese"			{ printSourceCode(yytext, yylineno); return IF; }
"sinao"				{ printSourceCode(yytext, yylineno); return ELSE; }
"negocio"			{ printSourceCode(yytext, yylineno); return FUNC_START; }
"tendeu"			{ printSourceCode(yytext, yylineno); return FUNC_END; }
"assim"				{ printSourceCode(yytext, yylineno); return MODULE_START; }
"cabô"				{ printSourceCode(yytext, yylineno); return MODULE_END; }
"trem"				{ printSourceCode(yytext, yylineno); return CONST; }
"desembucha"		{ printSourceCode(yytext, yylineno); return IDENTIFIER; }
"devorve"			{ printSourceCode(yytext, yylineno); return RETURN; }

"("					{ printSourceCode(yytext, yylineno); return PARAN_OPEN; }
")"					{ printSourceCode(yytext, yylineno); return PARAN_CLOSE; }
"["					{ printSourceCode(yytext, yylineno); return BRACK_OPEN; }
"]"					{ printSourceCode(yytext, yylineno); return BRACK_CLOSE; }
","					{ printSourceCode(yytext, yylineno); return COMMA; }

{staticType}		{ printSourceCode(yytext, yylineno); return TYPE; }
{integer}         	{ printSourceCode(yytext, yylineno); return NUMBER; }
{float}         	{ printSourceCode(yytext, yylineno); return NUMBER; }
"vazio"				{ printSourceCode(yytext, yylineno); return NIL; }
{atom}         		{ printSourceCode(yytext, yylineno); return ATOM; }
{string}         	{ printSourceCode(yytext, yylineno); return STRING; }

"uai"				{ printSourceCode(yytext, yylineno); return DELIMITER; }
{identifier}      	{ printSourceCode(yytext, yylineno); return IDENTIFIER; }


%%
/* Fim da segunda parte */
/* Terceira parte: Código C */
extern int yylineno, yychar, yydebug;
int hasError = 0;

int main(void) {
	printf("\n%d\n", yytoken_kind_t.YYEMPTY);


	cprintLine(BLUE);
	cprintf(CYAN, "\t Código Fonte: \n");
  	yyparse();

	printf("\n");
	cprintLine(YELLOW);
	if (!hasError) {
		cprintf(GREEN, "Trem de compilar rodô demais da conta!\nPrograma sintaticamente correto\n");
		return 0;
	}

	cprintf(RED, "Trem de compilar deu ruim!\nPrograma sintaticamente incorreto!\n");
  	return 0;
}

void yyerror(const char *str) {
	cprintf(ERROR, " Uai sô... deu um pobrema: %s na linha %d \n", str, yylineno);
	printf("Token problemático: ");
	printResetColor();
	printToken(yychar);
	printResetColor();
	hasError = 1;
}

int yywrap() {
	return 1;
}

/* Fim da terceira parte */
