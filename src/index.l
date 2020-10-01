/* Primeira parte:  */

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
name              (({word}\ ){3})({word})?
anything          [^{whitespace}^{word}]

%{
  #include "logger.h"
  #include "types.h"
%}

/* Como não precisamos de usar esse código em outra etapa, essa flag é adicionada */
%option noyywrap

/* Fim da primeira parte */
/* Segunda parte: Pattern match! */
%%

{licensePlate}  { printPattern(LICENSE_PLATE, yytext); }
{phone}         { printPattern(PHONE, yytext); }
{float}         { printPattern(FLOAT, yytext); }
{negInt}        { printPattern(NEG_INT, yytext); }
{posInt}        { printPattern(POS_INT, yytext); }
{name}          { printPattern(NAME, yytext); }
{word}          { printPattern(WORD, yytext); }
{whitespace}    {}
{anything}      {printPattern(UNKNOWN, yytext);}

%%
/* Fim da segunda parte */
/* Terceira parte: Código C */
int main(void) {
  yylex();
  printLine();
  return 0;
}

/* Fim da terceira parte */
