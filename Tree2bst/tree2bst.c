#include"tree.h"
#include"elemtype.h"

void InsertBSTRec(Node** tree, const ElemType* e)
{
	if (*tree == NULL)
	{
		Node* tmp = TreeCreateRoot(e, NULL, NULL);
		*tree = tmp;
		return;
	}
	if (ElemCompare(e, TreeGetRootValue((const Node*)(*tree))) <= 0) { 
		InsertBSTRec((&(*tree)->left), e); 
	}
	else { 
		InsertBSTRec((&(*tree)->right), e); 
	}
}
void Tree2BstRec(const Node* t, Node** ris)
{
	if (t == NULL) { 
		return;
	}
	Tree2BstRec(t->left, ris);
	InsertBSTRec(ris, TreeGetRootValue(t));
	Tree2BstRec(t->right, ris);
}
Node* Tree2Bst(const Node* t)
{
	if (t == NULL) {
		return NULL; 
	}
	Node* ris = NULL;
	Tree2BstRec(t, &ris);
	return ris;
}
/*
static Node* InsertBstInOrd(const ElemType* e, Node* bst) {
	if (TreeIsEmpty(bst)) {
		return TreeCreateRoot(e, NULL, NULL);
	}
	Node* t = bst;
	while (1) {
		if (ElemCompare(e, TreeGetRootValue(t)) < 0) {
			if (TreeIsEmpty(TreeLeft(t))) {
				t->left = TreeCreateRoot(e, NULL, NULL);
				break;
			}
			else {
				bst = TreeLeft(t);
			}
		}
		else if (ElemCompare(e, TreeGetRootValue(t)) > 0) {
			if (TreeIsEmpty(TreeRight(t))) {
				t->right = TreeCreateRoot(e, NULL, NULL);
				break;
			}
			else {
				t = TreeRight(t);
			}
		}
		else {
			break;
		}
		
	}
	return bst;
}
static void Tree2BstRec(Node* t, Node** bst) {
	if (TreeIsEmpty(t)) {
		return;
	}
	Tree2BstRec(TreeLeft(t), bst);
	(*bst) = InsertBstInOrd(TreeGetRootValue(t), *bst);
	Tree2BstRec(TreeRight(t), bst);
}
Node* Tree2Bst(Node* t) {
	Node* bst = TreeCreateEmpty();
	Tree2BstRec(t, &bst);
	return bst;
}
*/