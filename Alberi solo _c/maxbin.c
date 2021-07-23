#include"tree.h"
Node* CreateMaxBinTreeRec(ElemType* v, size_t v_size, size_t first, size_t last) {

	if (v == NULL || v_size == 0) {
		return NULL;
	}

	ElemType max = 0;
	size_t pos_max = first;
	for (size_t t = first; t <= last; ++t) {
		if (v[t] > max) {
			max = v[t];
			pos_max = t;
		}
	}

	return TreeCreateRoot(v + pos_max, CreateMaxBinTreeRec(v, pos_max - first, first, pos_max - 1), CreateMaxBinTreeRec(v, last - pos_max, pos_max + 1, last));
}
Node* CreateMaxBinTree(const ElemType* v, size_t v_size) {
	if (v == NULL) {
		return NULL;
	}

	return CreateMaxBinTreeRec(v, v_size, 0, v_size - 1);

}