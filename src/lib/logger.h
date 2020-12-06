/**
 * Auxilia no output do programa com funções auxiliares para colorir o terminal
 *
 * @author Gustavo Viegas (3026)
 * OBS: Esse módulo foi extraído dos TPs de PAA
 */

#ifndef logger_h
#define logger_h

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

// Código ANSI das cores para colorir o terminal
#define ANSI_COLOR_RED "\x1b[49;31m"
#define ANSI_COLOR_GREEN "\x1b[49;32m"
#define ANSI_COLOR_YELLOW "\x1b[49;33m"
#define ANSI_COLOR_BLUE "\x1b[49;34m"
#define ANSI_COLOR_MAGENTA "\x1b[49;35m"
#define ANSI_COLOR_CYAN "\x1b[49;36m"
#define ANSI_COLOR_ORANGE "\x1b[49;36m"
#define ANSI_COLOR_RESET "\x1b[49;0m"
#define ANSI_COLOR_ERROR "\033[37;41m"
#define ANSI_COLOR_ERROR2 "\033[93;41m"
#define ANSI_COLOR_TITLE1 "\033[33;45m"
#define ANSI_COLOR_TITLE2 "\033[47;44m"
#define ANSI_COLOR_TITLE3 "\033[30;43m"

// Tamanho da linha a ser impressa diversas vezes
#define LINE_SIZE 100

// Tamanho máximo de uma string a ser impressa com a funcao cprintf
#define CPRINTF_BUFFER_LENGTH 4096

/**
 * Cores disponíveis para ser impressas
 */
typedef enum AvailableColors
{
	RED,	 // Vermelho
	GREEN,	 // Verde
	YELLOW,	 // Amarelo
	BLUE,	 // Azul
	MAGENTA, // Magenta
	CYAN,	 // Ciano
	ERROR,	 // Erro
	ERROR2,	 // Erro 2
	TITLE1,	 // Titulo 1
	TITLE2,	 // Titulo 2
	TITLE3	 // Titulo 3
} AvailableColors;

/**
 * Limpa o terminal. Abstraída para não ter que importar a stdlib em toda biblioteca
 */
void clearOutput(void);

/**
 * Colored-Printf. Imprime uma mensagem no stdout, como no printf, mas colorido
 * @param color   Cor da mensagem a ser impressa
 * @param fmt     String de formato como do printf
 * @param VARARGS Argumentos adicionais a ser misturados no fmt
 */
void cprintf(AvailableColors color, const char *fmt, ...);

/**
 * Imprime uma linha de tamanho LINE_SIZE, em cor Ciano
 */
void printLine(void);

/**
 * Imprime uma linha de tamanho LINE_SIZE, em cor determinada
 */
void cprintLine(AvailableColors color);


void printResetColor();


void printFlag();

#endif /* logger_h */
