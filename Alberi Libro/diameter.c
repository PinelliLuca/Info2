#include"tree.h"
extern int TreeHeight(const Node* t);
#define MAX(a,b) (((a)>(b))?(a):(b))
int Diameter(const Node* t) {
	if (TreeIsEmpty(t))
		return 0;
	int d_l = Diameter(TreeLeft(t));
	int d_r = Diameter(TreeRight(t));
	int h_l = TreeHeight(TreeLeft(t));
	int h_r = TreeHeight(TreeRight(t));
	return MAX(MAX(d_l, d_r), h_l + 1 + h_r);
}