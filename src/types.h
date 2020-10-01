/**
 * Define tipos de padrão que o programa reconhece e como imprmi-los.
 * @author Gustavo Viegas (3026)
 *
 **/

#ifndef types_h
#define types_h

/**
 * Tipos de Padrão que o programa reconhece
 **/
typedef enum Pattern {
  UNKNOWN,
  POS_INT,
  NEG_INT,
  FLOAT,
  NEG_FLOAT,
  LICENSE_PLATE,
  WORD,
  PHONE,
  NAME
} Pattern;

/**
 * Um lexema... basicamente uma string
 **/
typedef char* Lexeme;

/**
 * Imprime a saída informando o tipo encontrado e o seu lexema.
 *
 */
void printPattern(Pattern pattern, Lexeme lexeme);

#endif
