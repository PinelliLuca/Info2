#include"minheap.h"
#include<stdbool.h>
#include<stdlib.h>
bool HeapMinPop(Heap* h, ElemType* e) {
	if (!h || !e || h->size == 0) {
		return false;
	}
	*e = HeapGetNodeValue(h, 0);
	ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, h->size - 1));
	h->size -= 1;
	h->data = realloc(h->data, h->size*sizeof(ElemType));
	HeapMinMoveDown(h, 0);
	return true;
}