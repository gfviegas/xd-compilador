%{
/*codigo colocado aqui aparece no arquivo gerado pelo flex*/
%}

/* This tells flex to read only one input file */
%option noyywrap

/* definicoes regulares */

delim [ \t\n]
ws		{delim}+

%%
{ws}		{/*nenhuma acao e nenhum retorno*/}
%%

/*codigo em C. Foi criado o main, mas podem ser criadas outras funcoes aqui.*/
int main(void) {
  /* Call the lexer, then quit. */
  yylex();
  return 0;
}
