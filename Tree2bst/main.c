#include"tree.h"
#include"elemtype.h"

extern Node* Vector2bst(const ElemType* v, size_t size);
extern Node* Tree2Bst(Node* t);
int main() {
	{
		Node* t = Vector2bst(NULL, 0);
	}
	{
		ElemType v[] = { 8,2,4,5,2,1,9 };
		size_t v_size = sizeof(v) / sizeof(ElemType);
		Node* t = Vector2bst(v, v_size);
		TreeDelete(t);
	} 
	{
		ElemType e[] = { 0,1,2,3,4,5,6,7,8,9 };
		Node* t = TreeCreateRoot(&e[6],
			TreeCreateRoot(&e[2],
				TreeCreateRoot(&e[3], NULL, NULL),
				TreeCreateRoot(&e[8],
					NULL,
					TreeCreateRoot(&e[5], NULL, NULL))),
			TreeCreateRoot(&e[9],
				NULL,
				TreeCreateRoot(&e[3], NULL, NULL)));

		Node* bst = Tree2Bst(t);

		TreeDelete(t);
		TreeDelete(bst);
	}
}