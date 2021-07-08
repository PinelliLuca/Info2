#include"tree.h"
#include"elemtype.h"
#include<stdbool.h>

extern Node* BstInsertRec(const ElemType* e, Node* n);
	

extern Node* BstFromVector(ElemType* v, size_t v_size);

extern Node* DeleteBstNode(Node* n, const ElemType* key);

extern bool TreeIsMirror(const Node* t);
extern const ElemType* BstTreeMin(const Node* n);
extern const ElemType TreeMin(const Node* n);

int main(void) {

	// Test DeleteBstNode
	{
		ElemType key = 12;
		Node* t = TreeCreateEmpty();
		t = DeleteBstNode(t, &key);
		TreeDelete(t);
	}
	{
		ElemType key = 12;
		ElemType e[] = { 12, 4, 5 };
		size_t e_size = sizeof(e) / sizeof(ElemType);
		Node* t = BstFromVector(e, e_size);
		TreeWriteStdoutPreOrder(t);
		puts("");
		ElemType m = TreeMin(t);
		ElemType bst_min = BstTreeMin(t);
		ElemWriteStdout(m);
		puts("");
		ElemWriteStdout(bst_min);
		puts("");
		t = DeleteBstNode(t, &key);
		TreeDelete(t);
	}
	{
		ElemType key = 12;
		ElemType e[] = { 12, 4, 21, 0, 2, 5, 18, 77, 8, 9 };
		size_t e_size = sizeof(e) / sizeof(ElemType);
		Node* t = BstFromVector(e, e_size);
		TreeWriteStdoutPreOrder(t);
		puts("");
		ElemType m = TreeMin(t);
		ElemType bst_min = BstTreeMin(t);
		ElemWriteStdout(m);
		puts("");
		ElemWriteStdout(bst_min);
		puts("");
		t = DeleteBstNode(t, &key);
		TreeDelete(t);
	}
	{
		ElemType key = 21;
		ElemType e[] = { 12, 4, 21, 0, 2, 5, 18, 77, 8, 9 };
		size_t e_size = sizeof(e) / sizeof(ElemType);
		Node* t = BstFromVector(e, e_size);
		TreeWriteStdoutPreOrder(t);
		puts("");
		ElemType m = TreeMin(t);
		ElemType bst_min = BstTreeMin(t);
		ElemWriteStdout(m);
		puts("");
		ElemWriteStdout(bst_min);
		puts("");
		t = DeleteBstNode(t, &key);
		TreeDelete(t);
	}
	{
		ElemType key = 77;
		ElemType e[] = { 12, 4, 21, 0, 2, 5, 18, 77, 8, 9 };
		size_t e_size = sizeof(e) / sizeof(ElemType);
		Node* t = BstFromVector(e, e_size);
		t = DeleteBstNode(t, &key);
		TreeDelete(t);
	}
	{
		ElemType key = 0;
		ElemType e[] = { 12, 4, 21, 0, 2, 5, 18, 77, 8, 9 };
		size_t e_size = sizeof(e) / sizeof(ElemType);
		Node* t = BstFromVector(e, e_size);
		t = DeleteBstNode(t, &key);
		TreeDelete(t);
	}

	// Test Mirror
	bool ret = TreeIsMirror(TreeCreateEmpty());
	{
		ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
		Node* t = TreeCreateRoot(&e[0],
			TreeCreateRoot(&e[1],
				TreeCreateRoot(&e[4], NULL, NULL),
				TreeCreateRoot(&e[2], NULL, NULL)),
			TreeCreateRoot(&e[1],
				TreeCreateRoot(&e[2], NULL, NULL),
				TreeCreateRoot(&e[4], NULL, NULL)));
		ret = TreeIsMirror(t);
		TreeDelete(t);
	}
	{
		ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
		Node* t = TreeCreateRoot(&e[0],
			TreeCreateRoot(&e[1],
				TreeCreateRoot(&e[4], NULL, NULL),
				TreeCreateRoot(&e[2], NULL, NULL)),
			TreeCreateRoot(&e[1],
				TreeCreateRoot(&e[4], NULL, NULL),
				TreeCreateRoot(&e[2], NULL, NULL)));
		ret = TreeIsMirror(t);
		TreeDelete(t);
	}
	{
		ElemType v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
		Node* t = TreeCreateRoot(&v[3],
			TreeCreateRoot(&v[2], NULL, NULL),
			TreeCreateRoot(&v[2], NULL, NULL));
		ret = TreeIsMirror(t);
		TreeDelete(t);
	}
	{
		ElemType v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
		Node* t = TreeCreateRoot(&v[4],
			TreeCreateRoot(&v[5],
				TreeCreateRoot(&v[1], NULL, NULL),
				NULL),
			TreeCreateRoot(&v[5], NULL, NULL));
		ret = TreeIsMirror(t);
		TreeDelete(t);
	}
	{
		ElemType v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
		Node* t = TreeCreateRoot(&v[4],
			TreeCreateRoot(&v[2],
				TreeCreateRoot(&v[1], NULL, NULL),
				TreeCreateRoot(&v[3], NULL, NULL)),
			TreeCreateRoot(&v[2],
				TreeCreateRoot(&v[1], NULL, NULL),
				TreeCreateRoot(&v[4], NULL, NULL)));
		ret = TreeIsMirror(t);
		TreeDelete(t);
	}
	{
		ElemType v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
		Node* t = TreeCreateRoot(&v[7],
			TreeCreateRoot(&v[4],
				TreeCreateRoot(&v[2],
					TreeCreateRoot(&v[1], NULL, NULL),
					NULL),
				TreeCreateRoot(&v[5], NULL, NULL)),
			TreeCreateRoot(&v[4], NULL, NULL));
		ret = TreeIsMirror(t);
		TreeDelete(t);
	}
	{
		ElemType v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
		Node* t = TreeCreateRoot(&v[0],
			TreeCreateRoot(&v[1],
				TreeCreateRoot(&v[3],
					TreeCreateRoot(&v[5], NULL, NULL),
					TreeCreateRoot(&v[6],
						TreeCreateRoot(&v[9], NULL, NULL),
						NULL)),
				TreeCreateRoot(&v[4],
					TreeCreateRoot(&v[7], NULL, NULL),
					TreeCreateRoot(&v[8],
						NULL,
						NULL))),
			TreeCreateRoot(&v[1], TreeCreateRoot(&v[4],
				TreeCreateRoot(&v[8], NULL, NULL),
				TreeCreateRoot(&v[7],
					NULL,
					NULL)),
				TreeCreateRoot(&v[3],
					TreeCreateRoot(&v[6], NULL, TreeCreateRoot(&v[9], NULL, NULL)),
					TreeCreateRoot(&v[5],
						NULL,
						NULL))));
		ret = TreeIsMirror(t);
		TreeDelete(t);
	}
}