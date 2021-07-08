#include"tree.h"
Node* TreePrune(Node* t, const ElemType* cut_value) {
	if (TreeIsEmpty(t))
		return t;
	if (ElemCompare(TreeGetRootValue(t), cut_value) == 0) {
		TreeDelete(t);
		return TreeCreateEmpty();
	}
	t->left = TreePrune(TreeLeft(t),cut_value);
	t->right = TreePrune(TreeRight(t),cut_value);
	return t;
}