#include"tree.h"
#include<math.h>

static int Max(int a, int b) {
	return a > b ? a : b;
}
static int TreeHeight(const Node* t) {
	if (TreeIsEmpty(t)) {
		return -1;
	}
	return 1 + Max(TreeHeight(TreeLeft(t)), TreeHeight(TreeRight(t)));
}
int GetBalanceCoeff(const Node* n) {
	if (TreeIsEmpty(n)) 
		return 0;
	return TreeHeight(TreeLeft(n)) - TreeHeight(TreeRight(n));
}
bool TreeIsBalanced(const Node* t) {
	if (TreeIsEmpty(t))
		return true;
	int h_l = TreeHeight(TreeLeft(t));
	int h_r = TreeHeight(TreeRight(t));
	if (TreeIsBalanced(TreeLeft(t)) && TreeIsBalanced(TreeRight(t)) && abs(h_l - h_r) <= 1) {
		return true;
	}
		return false;
}
