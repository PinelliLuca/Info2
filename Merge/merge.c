#include"elemtype.h"
#include"minheap.h"
#include<string.h>
Heap* MergeHeap(const Heap* h1, const Heap* h2) {
	Heap* h = HeapCreateEmpty();
	if (h1) {
		for (size_t i = 0; i < h1->size; ++i) {
			HeapMinInsertNode(h, h1->data + i);
		}
	}
	if (h2) {
		for (size_t i = 0; i < h2->size; ++i) {
			HeapMinInsertNode(h, h2->data + i);
		}
	}
	return h;
}