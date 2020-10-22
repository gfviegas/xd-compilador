/* Primeira parte:  */
%{
  #include "logger.h"
  #include "types.h"
%}

/* Como não precisamos de usar esse código em outra etapa, essa flag é adicionada */
%option noyywrap

/* Definições regulares */
digit             [0-9]
upcaseLetter      [A-Z]
downcaseLetter    [a-z]
letter            [a-zA-Z]
word              {letter}+
delimiter         [ \t\n]
whitespace        {delimiter}+
licensePlate      {upcaseLetter}{3}\-{digit}{4}
phone             {digit}{4}\-{digit}{4}
float             (\-|\+)?{digit}+\.{digit}+
negInt            \-{digit}+
posInt            \+?{digit}+
name              ({word}\ ){2}{word}(\ {word})?
anything          [^{whitespace}^{word}]
/* Extras! */
phoneNine         {digit}{5}\-{digit}{4}
phoneFull		  \(({digit}{2})\)\ {digit}?{digit}{4}\-{digit}{4}
email			  .+@.+\.{word}+(\.{word}+)?
cep			  	  {digit}{5}\-{digit}{3}

/* Fim da primeira parte */
/* Segunda parte: Pattern match! */
%%

{licensePlate}  { printPattern(LICENSE_PLATE, yytext); }
{phone}         { printPattern(PHONE, yytext); }
{phoneNine}     { printPattern(PHONE_NINE_DIGITS, yytext); }
{phoneFull}     { printPattern(PHONE_FULL, yytext); }
{cep}     		{ printPattern(CEP, yytext); }
{float}         { printPattern(FLOAT, yytext); }
{negInt}        { printPattern(NEG_INT, yytext); }
{posInt}        { printPattern(POS_INT, yytext); }
{email}     	{ printPattern(EMAIL, yytext); }
{name}          { printPattern(NAME, yytext); }
{word}          { printPattern(WORD, yytext); }
{whitespace}    {}
{anything}      {printPattern(UNKNOWN, yytext);}

%%
/* Fim da segunda parte */
/* Terceira parte: Código C */
int main(void) {
  	yylex();
	printf("\n");
  	return 0;
}

/* Fim da terceira parte */
