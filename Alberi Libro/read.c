#define _CRT_SECURE_NO_WARNINGS
#include"tree.h"
#include <stdlib.h>
#include<stdio.h>
Node* TreeReadRec(FILE *f) {
	ElemType c;
	int read = fscanf(f, " %c", &c);
	//caso base: non ci sono più dati
	if (read != 1) {
		return TreeCreateEmpty();
	}
	//caso base2: ho letto un punto, quindi leggo una foglia
	if (c == '.') {
		fscanf(f, " %c", &c);
		return TreeCreateRoot(&c, TreeCreateEmpty(), TreeCreateEmpty());
	}
	Node* l = TreeReadRec(f);
	Node* r = TreeReadRec(f);
	//creo e ritorno l'albero avete come radice 'c' e come figli gli alberi l ed r letti ricorsivamente da file
	return TreeCreateRoot(&c, l, r);
}

Node* TreeRead(const char* filename) {
	FILE* f = fopen(filename, "r");
	if (!f)
		return TreeCreateEmpty();
	Node* t = TreeReadRec(f);
	fclose(f);
	return t;
}