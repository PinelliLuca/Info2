#define _CRT_SECURE_NO_WARNINGS
#include"tree.h"
static void TreeWriteRec(const Node* t, FILE* f, int d) {
	if (t->left == NULL && t->right == NULL) {
		fprintf(f, "%*s", 4 * d, "");
		fprintf(f, ".%c\n", t->value);
		return;
	}
	fprintf(f, "%*s", 4 * d, "");
	fprintf(f, "%c\n", t->value);
	TreeWriteRec(t->left, f, d + 1);
	TreeWriteRec(t->right, f, d + 1);
	return;
}
bool TreeWrite(const Node* t, const char* filename) {
	FILE* f = fopen(filename, "w");
	if (!f)
		return false;
	if (t != NULL) {
		TreeWriteRec(t, f, 0);
	}
	else {
		//non faccio nulla
	}
	fclose(f);
	return true;
}