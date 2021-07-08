#include"minheap.h"
#include <limits.h>

/*
#include <limits.h>
void HeapMinMoveDownRec(Heap* h, int i)
{
	const ElemType null_value = INT_MAX;
	const ElemType* parent = (const ElemType*)h->data + i;
	const ElemType* left = (const ElemType*)((HeapLeft(i) < (int)h->size) ? h->data + HeapLeft(i) : &null_value);
	const ElemType* right = (const ElemType*)((HeapRight(i) < (int)h->size) ? h->data + HeapRight(i) : &null_value);
	if (*left == INT_MAX && *right == INT_MAX)
	{
		return;
	}
	const ElemType* min = (ElemCompare(left, right) < 0) ? left : right;
	int min_index = (ElemCompare(left, right) < 0) ? HeapLeft(i) : HeapRight(i);
	if (ElemCompare(parent, min) > 0)
	{
		ElemSwap((ElemType*)parent, (ElemType*)min);
		HeapMinMoveDownRec(h, min_index);
	}
}
*/

void HeapMinMoveDownRec(Heap* h, int i) {

	ElemType* parent = h->data + i;
	ElemType* val_max = INT_MAX; //valore massimo rappresentabile
	ElemType* left = (HeapLeft(i) < h->size) ? h->data + HeapLeft(i) : &val_max; //o esiste o è sempre maggiore
	ElemType* right = (HeapRight(i) < h->size) ? h->data + HeapRight(i) : &val_max;
	if (*left == INT_MAX && *right == INT_MAX) {
		return;//se entrambi non esistono ho finito il vettore
	}
	const ElemType *minimo = ElemCompare(left, right) < 0 ? left : right; 
	int min_index = (ElemCompare(left, right) < 0) ? HeapLeft(i) : HeapRight(i); //int perchè è un indice! elementoi-esimo
	if (ElemCompare(minimo, parent) < 0) {
		ElemSwap(parent, minimo);
		HeapMinMoveDownRec(h, min_index);
	}
}
