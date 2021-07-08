#include"minheap.h"
#include"elemtype.h"
void HeapMinHeapsort(Heap* h) {
	if (h==NULL || h->size == 0) {
		return;
	}
	size_t original_size = h->size;
	while (h->size > 1) {
		ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, h->size - 1));
		h->size--;
		HeapMinMoveDown(h, 0);
	}
	h->size = original_size;
}