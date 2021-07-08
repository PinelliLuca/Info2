#include"tree.h"

bool PrintLevelRec(const Node* t, int level) {
	if (TreeIsEmpty(t))
		return false;
	if (level == 0) {
		ElemWriteStdout(TreeGetRootValue(t));
		putchar(' ');
		return true;
	}
	bool l = PrintLevelRec(TreeLeft(t), level - 1);
	bool r = PrintLevelRec(TreeRight(t), level - 1);
	return r || l;
}
void LevelOrder(const Node* t) {
	int height = 0;
	while (PrintLevelRec(t, height)) {
		height++;
	}
}