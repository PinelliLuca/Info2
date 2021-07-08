#include"minheap.h"
#include<stdbool.h>
void IsHeapRec(Heap* h, bool *ris, int i) {
	if (*ris == false) {
		return;
	}
	if (i > h->size) {
		return;
	}
	int sx = HeapLeft(i);
	int dx = HeapRight(i);
	if (sx < h->size) {
		*ris = (ElemCompare(h->data + i, h->data + sx) < 0);
	}
	if (dx < h->size) {
		*ris = (ElemCompare(h->data + i, h->data + dx) < 0);
	}
	IsHeapRec(h, ris, sx);
	IsHeapRec(h, ris, dx);

}
bool IsHeap(const Heap* h) {
	if (!h || h->size == 0)
		return false;
	bool ris = true;
	IsHeapRec(h, &ris, 0);
	return ris;
}