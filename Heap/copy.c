#include"minheap.h"
#include<stdlib.h>

Heap* HeapCopy(const Heap* h) {
	if (!h)
		return NULL;
	Heap* new_h = malloc(sizeof(Heap));
	new_h->data = h->size > 0 ? malloc(sizeof(ElemType)) : NULL;
	new_h->size = h->size;
	for (size_t i = 0; i < h->size; ++i) {
		new_h->data[i] = ElemCopy(h->data + 1);
	}
	return new_h;
}