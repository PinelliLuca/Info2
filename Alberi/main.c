#include"tree.h"
#include"elemtype.h"
extern* BstInsertRec(const ElemType* e, Node* n);
extern const ElemType* TreeMax(const Node* n);
int main() {
	ElemType e[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };
	Node* t = TreeCreateRoot(e + 15,
		TreeCreateRoot(e + 10,
			TreeCreateRoot(e + 3, NULL, NULL),
			TreeCreateRoot(e + 12, NULL, NULL)),
		TreeCreateRoot(e + 21, NULL, NULL));

	t = BstInsertRec(e + 23, t);
	const ElemType *max = TreeMax(t);
	TreeDelete(t);
	return 0;
}