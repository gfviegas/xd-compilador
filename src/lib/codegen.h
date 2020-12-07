/**
 * Codigo Intermediario
 * @author Gustavo Viegas (3026)
 *
 **/

#ifndef codegen_h
#define codegen_h

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef enum Boolean {
	FALSE = 0,
	TRUE = 1
} Boolean;

FILE *graphOutput;

void initCodeGen();
int insertNodeGraph(char *label, char *extraInfo);
void insertConnection(int node1, int node2);
void finishCodeGen();

// enum SyntaxTreeCode {
// 	SUM,
// };

// typedef enum SyntaxTreeBinaryOperation {
// 	RELOP_STOPER,
// 	RELOP,
// } SyntaxTreeBinaryOperation;

// typedef struct SyntaxNode *SyntaxNodePointer;
// typedef struct SyntaxTreeBinary {
// 	SyntaxTreeBinaryOperation code;

// 	SyntaxNodePointer left;
// 	SyntaxNodePointer right;
// } SyntaxTreeBinary;

// typedef struct SyntaxTreeLeaf {
// 	union {
// 		char charValue;
// 		char *stringValue;
// 		int intValue;
// 		float floatValue;
// 		Boolean booleanValue;
// 	};
// } SyntaxTreeLeaf;

// typedef struct SyntaxTree {


// } SyntaxTree;



#endif
