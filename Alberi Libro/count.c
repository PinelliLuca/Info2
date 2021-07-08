#include"tree.h"
static void TreeCountNodesRec(const Node* t, int* i, int* e) {
	if (TreeIsEmpty(t))
		return;
	if (TreeIsLeaf(t)) {//nodo esterno
		(*e)++;
		return;
	}
	(*i)++; //nodo interno
	TreeCountNodesRec(TreeLeft(t), i, e);
	TreeCountNodesRec(TreeLeft(t), i, e);
}
void TreeCountNodes(const Node* t, int* internal, int* external) {
	(*internal) = 0;
	(*external) = 0;
	TreeCountNodesRec(t, internal, external);
}