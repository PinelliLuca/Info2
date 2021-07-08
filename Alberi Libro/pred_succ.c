#include"tree.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
static void Tree2VectorRec(const Node* t, const ElemType* e, const Node*** v, size_t* v_size, size_t* i) {
	if (TreeIsEmpty(t))
		return;
	Tree2VectorRec(TreeLeft(t),e,v,v_size,i);
	*v = realloc((void*)*v, ++(*v_size) * sizeof(Node*));
	(*v)[*v_size - 1] = t;
	if (ElemCompare(TreeGetRootValue(t), e) == 0) {
		*i = *v_size - 1;
	}
	Tree2VectorRec(TreeRight(t), e, v, v_size, i);
}
const Node* Predecessore(const Node* t, const ElemType* e) {
	Node** v = NULL;
	size_t v_size = 0;
	size_t i = 0;
	Tree2VectorRec(t, e, &v, &v_size, &i);
	return i == 0 ? NULL : v[i - 1];
}
const Node* Successore(const Node* t, const ElemType* e) {
	Node** v = NULL;
	size_t v_size = 0;
		size_t i = -1;
		Tree2VectorRec(t, e, &v, &v_size, &i);
		return i == v_size - 1 ? NULL : v[i + 1]; 
}