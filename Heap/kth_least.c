#include"minheap.h"
#include<stdlib.h>
#include<string.h>

ElemType* KthLeast(const Heap* h, int k) {
	Heap* tmp = malloc(sizeof(Heap));
	tmp->data = malloc(sizeof(ElemType) * h->size);
	tmp->size = h->size;
	for (size_t i = 0; i < h->size; ++i) {
		tmp->data[i] = ElemCopy(&h->data[i]);
	}
	while (--k > 0) {
		ElemSwap(&tmp->data[0], &tmp->data[h->size - 1]);
		tmp->size--;
		HeapMinMoveDown(tmp, 0);
	}
	ElemType res = ElemCopy(&tmp->data[0]);
	tmp->size = h->size;//per deallocare correttamente la memoria
	HeapDelete(tmp);
	return res;
}