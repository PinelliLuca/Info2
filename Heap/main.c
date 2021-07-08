#include"elemtype.h"
#include"minheap.h"
#include<stdlib.h>
#include<string.h>

extern Heap* HeapMinHeapify(const ElemType* v, size_t v_size);
extern void HeapMinMoveUpRec(Heap* h, int i);
extern void HeapMinMoveDownRec(Heap* h, int i);
extern void HeapMinHeapsort(Heap* h);
int main(void)
{
	{//HEAPIFYMIN
		ElemType h[] = { 4, 6, 1, 2, 12, 23 };
		size_t h_size = sizeof(h) / sizeof(ElemType);
		HeapMinHeapify(h, h_size);
	}
	{
		ElemType h[] = { 23,21,12 , 2, 12, 23 };
		size_t h_size = sizeof(h) / sizeof(ElemType);
		HeapMinHeapify(h, h_size);

	}
	{
		{ //MOVEDOWN
			ElemType arr[7] = { 10, 4, 7, 3, 2, 5, 9 };
			Heap* heap = malloc(sizeof(Heap));
			heap->data = arr;
			heap->size = 7;
			printf("ORIGINALE PER MOVE DOWN\n");
			HeapWriteStdout(heap);
			HeapMinMoveDownRec(heap, 0);
			printf("MOVE DOWN:\n");
			HeapWriteStdout(heap);
		
			
		}
	}
	{
		{ //MOVEUP
			ElemType h[] = { 4, 6, 1, 5, 12, 23 };
			size_t h_size = sizeof(h) / sizeof(ElemType);
			Heap* heap = HeapMinHeapify(h, h_size);
			heap->size++;
			heap->data = realloc(heap->data, sizeof(ElemType) * heap->size);
			heap->data[heap->size - 1] = 2;
			HeapMinMoveUpRec(heap, heap->size - 1);
			printf("MOVE UP\n");
			HeapWriteStdout(heap);
			HeapDelete(heap);
		}
		{
			//POP
			ElemType h[] = { 4, 6, 1, 5, 12, 23 };
			size_t h_size = sizeof(h) / sizeof(ElemType);
			Heap* heap = HeapMinHeapify(h, h_size);
			printf("HEAP POP ORIGINALE: \n");
			HeapWriteStdout(heap);
			ElemType e;
			bool ret = HeapMinPop(heap, &e);
			printf("POP: \n");
			HeapWriteStdout(heap);
			HeapDelete(heap);
		}
		 {//HEAPSORT
			ElemType h[] = { 4, 6, 1, 5, 12, 23 };
			size_t h_size = sizeof(h) / sizeof(ElemType);
			Heap* heap = HeapMinHeapify(h, h_size);
			printf("HEAPSORT ORIGINALE: \n");
			HeapWriteStdout(heap);
			HeapMinHeapsort(heap);
			printf("ORDINATA:\n");
			HeapWriteStdout(heap);
			HeapDelete(heap);
		}
	}
	return EXIT_SUCCESS;
}