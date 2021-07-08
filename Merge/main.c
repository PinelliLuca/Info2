#include"elemtype.h"
#include"minheap.h"
#include<stdio.h>
#include<stdlib.h>
extern Heap* MergeHeap(const Heap* h1, const Heap* h2);
int main() {
	
		ElemType v[] = { 1,2,4,6 };
		Heap* h = malloc(sizeof(Heap));
		size_t size = (sizeof(v) / sizeof(ElemType));
		h->data = v;
		h->size = size;
		printf("HEAP 1:\n");
		HeapWriteStdout(h);

		ElemType v2[] = { 0,3,5,7 };
		Heap* h2 = malloc(sizeof(Heap));
		size_t size2 = (sizeof(v2) / sizeof(ElemType));
		h2->data = v2;
		h2->size = size2;
		printf("HEAP 2:\n");
		HeapWriteStdout(h2);

		Heap* merge = MergeHeap(h, h2);
		HeapWriteStdout(merge);

	
	
	return 0;
}