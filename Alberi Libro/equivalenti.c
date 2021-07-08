#include"tree.h"
bool Equivalenti(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
		return true;
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2))
		return false;
	if (TreeIsLeaf(t1) && TreeIsLeaf(t2)) {
		if (t1->value % t2->value != 0 && t2->value % t1->value != 0)
			return false;
	}
	else {
		if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) != 0)
			return false;
	}
	return Equivalenti(TreeLeft(t1), TreeRight(t2)) && Equivalenti(TreeRight(t1), TreeRight(t2));
}