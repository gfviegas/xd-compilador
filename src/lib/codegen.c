#include "codegen.h"

// ID do Código atual
int codeGenCurrentNode = 0;

// Abre o arquivo de output do grafo e aponta o ponteiro graphOutput para sua referência
void initCodeGen() {
	graphOutput = fopen("./build/graph.dot", "w+");

	if (graphOutput == NULL) {
		printf("Erro ao abrir arquivo de saída de grafo\n");
		exit(1);
	}

	fprintf(graphOutput, "graph G {\n");
}

// Insere um vértice ao grafo
int insertNodeGraph(char* label, char* extraInfo) {
	if (strlen(extraInfo) > 0) {
		fprintf(graphOutput, "\n\t%d[label=<%s<BR/><FONT POINT-SIZE=\"8\">%s</FONT>>]\n", codeGenCurrentNode, label, extraInfo);
	} else {
		fprintf(graphOutput, "\n\t%d[label=<%s>]\n", codeGenCurrentNode, label);
	}

	return codeGenCurrentNode++;
}

// Insere uma aresta ao grafo
void insertConnection(int node1, int node2) {
	fprintf(graphOutput, "\t%d -- %d\n", node1, node2);
}

// Fecha o arquivo aberto
void finishCodeGen(void) {
	fprintf(graphOutput, "\n}\n");
	fclose(graphOutput);
}
