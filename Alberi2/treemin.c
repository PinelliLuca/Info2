#include"tree.h"

const ElemType* BstTreeMin(const Node* n) {
	if (TreeIsEmpty(n))
		return NULL;
	const Node* t = n;
	const ElemType *min = TreeGetRootValue(t);
	while (!TreeIsEmpty(t)) {
		min = TreeGetRootValue(t);
		t = t->left;
	}
	return min;
}

void TreeMinRec(Node* n, ElemType** min, int* livello_max, int livello) {
	if (TreeIsEmpty(n)) {
		return NULL;
	}
	if ((ElemCompare(TreeGetRootValue(n), *min) < 0) || (ElemCompare(TreeGetRootValue(n), *min) == 0
		&& livello > *livello_max)) {
		*min = TreeGetRootValue(n);
		*livello_max = livello;
	}
	TreeMinRec(TreeLeft(n), min, livello_max, livello + 1);
	TreeMinRec(TreeRight(n), min, livello_max, livello + 1);
}
const ElemType TreeMin(const Node* n) {
	if (TreeIsEmpty(n)) {
		return NULL;
	}
	ElemType* min = TreeGetRootValue(n);
	int livello_max = 0;
	TreeMinRec(TreeLeft(n), &min, &livello_max, 1);
	TreeMinRec(TreeRight(n), &min, &livello_max, 1);
	return min;
}