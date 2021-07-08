#include"tree.h"
#include"elemtype.h"


Node* Vector2bst(const ElemType* v, size_t v_size) {
	Node* t = TreeCreateEmpty();
	if (v_size == 0)
		return t;
	t = TreeCreateRoot(&v[0], NULL, NULL);
	for (size_t i = 1; i < v_size; ++i) {
		Node* tmp = t;
		while (1) {
			if (ElemCompare(TreeGetRootValue(tmp), &v[i]) > 0) {
				//nuovo nodo nel sottoalbero sx
				if (TreeIsEmpty(TreeLeft(tmp))) {
					tmp->left = TreeCreateRoot(&v[i], NULL, NULL);
					break;
				}
				else { //mi muovo fino ad arrivare ad una foglia
					tmp = TreeLeft(tmp);
				}
			}
			else if (ElemCompare(TreeGetRootValue(tmp), &v[i]) < 0) {
				//il nuovo nodo va inserito a dx
				if (TreeIsEmpty(TreeRight(tmp))) {
					tmp->right = TreeCreateRoot(&v[i], NULL, NULL);
					break;
				}
				else {
					tmp = TreeRight(tmp);
				}
			}
			else {
				//il nodo è già presente
				break;
			}
		}
	}
	return t;
}
