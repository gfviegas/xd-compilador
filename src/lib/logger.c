/**
 * Auxilia no output do programa com funções auxiliares para colorir o terminal
 *
 * @author Gustavo Viegas
 * OBS: Esse módulo foi extraído dos TPs de PAA
 */

#include "logger.h"

// Limpa o terminal. Abstraída para não ter que importar a stdlib em toda biblioteca
void clearOutput(void) {
	system("clear");
}

// Colored-Printf. Imprime uma mensagem no stdout, como no printf, mas colorido
void cprintf(AvailableColors color, const char *fmt, ...) {
	static const char *colors[] = {
		ANSI_COLOR_RED,
		ANSI_COLOR_GREEN,
		ANSI_COLOR_YELLOW,
		ANSI_COLOR_BLUE,
		ANSI_COLOR_MAGENTA,
		ANSI_COLOR_CYAN,
		ANSI_COLOR_ERROR,
		ANSI_COLOR_ERROR2,
		ANSI_COLOR_TITLE1,
		ANSI_COLOR_TITLE2,
		ANSI_COLOR_TITLE3
	};

	char buffer[CPRINTF_BUFFER_LENGTH];
	va_list args;
	va_start(args, fmt);
	vsnprintf(buffer, sizeof(buffer), fmt, args);
	va_end(args);

	printf("%s%s%s", colors[color], buffer, ANSI_COLOR_RESET);
}

// Imprime uma linha de tamanho LINE_SIZE, em cor Ciano
void printLine(void) {
	printf("\n");

	for (int i = 0; i < LINE_SIZE; i++)
		printf("%s=", ANSI_COLOR_CYAN);

	printf("\n%s", ANSI_COLOR_RESET);
}

void cprintLine(AvailableColors color) {
	static const char *colors[] = {
		ANSI_COLOR_RED,
		ANSI_COLOR_GREEN,
		ANSI_COLOR_YELLOW,
		ANSI_COLOR_BLUE,
		ANSI_COLOR_MAGENTA,
		ANSI_COLOR_CYAN,
		ANSI_COLOR_ERROR,
		ANSI_COLOR_ERROR2
		ANSI_COLOR_TITLE1,
		ANSI_COLOR_TITLE2,
		ANSI_COLOR_TITLE3
	};
	printf("\n");

	for (int i = 0; i < LINE_SIZE; i++)
		printf("%s=", colors[color]);

	printf("\n%s", ANSI_COLOR_RESET);
}

void printResetColor() {
	printf("%s %s", ANSI_COLOR_RESET, ANSI_COLOR_RESET);
}

void printFlag() {


cprintf(RED, "\n                                                                                ");
cprintf(RED, "\n                                       ###    @@                                 ");
cprintf(RED, "\n                                 .@   ##### @.@                                 ");
cprintf(RED, "\n                                %/*  #######    @                               ");
cprintf(RED, "\n                               @   ###########  @&*                             ");
cprintf(RED, "\n                            & &%  #############                                 ");
cprintf(RED, "\n                           /    ################/ #                             ");
cprintf(RED, "\n                         . @#  ################### * @                          ");
cprintf(RED, "\n                         (,  *#####################  *. @                       ");
cprintf(RED, "\n                        .(/ ######################### &@,@                      ");
cprintf(RED, "\n                           ###########################                          ");
cprintf(RED, "\n                         ###############################                        ");
cprintf(RED, "\n                                                                                ");
cprintf(RED, "\n                                    #%  (%.  . #                                                                                                                ");

}
