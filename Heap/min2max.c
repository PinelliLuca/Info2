#include"minheap.h"
#include<math.h>
#include<stdlib.h>
#include<string.h>
static void HeapMaxMoveDown(Heap* h, int i) {
	int l = HeapLeft(i);
	int r = HeapRight(i);
	int largest = i;
	if ((l < h->size) && ElemCompare(HeapGetNodeValue(h, l), HeapGetNodeValue(h, largest)) > 0) {
		largest = l;
	}
	if ((r < h->size) && ElemCompare(HeapGetNodeValue(h, r), HeapGetNodeValue(h, largest)) > 0) {
		largest = r;
	}
	if (largest != i) {
		ElemSwap(HeapGetNodeValue(h, i),HeapGetNodeValue(h, largest));
		HeapMaxMoveDown(h, largest);
	}
}
void HeapMin2Max(Heap* h) {
	if (!h || HeapIsEmpty(h))
		return;
	for (int i = h->size / 2 - 1; i >= 0; --i) {
		HeapMaxMoveDown(h, i);
	}
}