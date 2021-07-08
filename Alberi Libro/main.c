#include"tree.h"
#include"elemtype.h"
#include<stdbool.h>
extern bool TreeAreIdentical(const Node* t1, const Node* t2);
extern int TreeHeight(const Node* t);
extern Node* TreeRead(const char* filename);
int main() {
	ElemType e[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };
	Node* t = TreeCreateRoot(e + 10,
		//LEFT di 15
		TreeCreateRoot(e + 15, TreeCreateRoot(e + 3, NULL, NULL), TreeCreateRoot(e + 12, NULL, NULL)),
		//RIGHT di 15
		TreeCreateRoot(e + 21, TreeCreateRoot(e + 20, NULL, NULL), TreeCreateRoot(e + 22, NULL, NULL)));

	//TreeWriteStdoutInOrder(n);
	/*           15
	*     10          21
		3   12     20    22
	*/
	Node* t2 = TreeCreateRoot(e + 10,
		//LEFT di 15
		TreeCreateRoot(e + 15, TreeCreateRoot(e + 3, NULL, NULL), TreeCreateRoot(e + 12, NULL, NULL)),
		//RIGHT di 15
		TreeCreateRoot(e + 21, TreeCreateRoot(e + 20, NULL, NULL), TreeCreateRoot(e + 22, NULL, NULL)));
	bool c = TreeAreIdentical(t, t2);
	if (c == 1) {
		printf("gli alberi sono uguali? Si\n");
	}
	else {
		printf("gli alberi sono uguali? No\n");
	}
	int h=TreeHeight(t);
	printf("Altezza %d\n", h);

	Node* n;
	n= TreeRead("read.txt");
	
	TreeDelete(n);
	TreeDelete(t);
	TreeDelete(t2);
	return 0;
}