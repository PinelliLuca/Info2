#include"tree.h"
void TreeMorrisIsInOrder(Node* t) {
	if (t == NULL)
		return;
	Node* curr = t;
	while (curr != NULL) {
		if (curr->left == NULL) {
			printf("%d ", curr->value);
			curr = curr->right;
		}
		else {
			Node* pred = curr->left;
			while (pred->right != NULL && pred->right != curr) {
				pred = pred->right;
			}
			if (pred->right == curr) {
				pred->right = NULL;
				printf("%d ", curr->value);
				curr = curr->right;
			}
			else {
				pred->right = curr;
				curr = curr->left;
			}
		}
	}
}