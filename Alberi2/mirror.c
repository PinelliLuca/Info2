#include"tree.h"


bool TreeIsMirrorRec(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) {
		return false;
	}
	return ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) == 0
		&& TreeIsMirrorRec(TreeLeft(t1), TreeRight(t2)) //sotto albero sx con dx
		&& TreeIsMirrorRec(TreeRight(t1), TreeLeft(t2)); //sottoalbero dx con albero sx

}

bool TreeIsMirror(const Node* t) {
	return TreeIsMirrorRec(TreeLeft(t), TreeRight(t));
}