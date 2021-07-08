#include"minheap.h"
#include<string.h>
Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {
	Heap* h = HeapCreateEmpty();
	h->size = v_size;
	h->data = malloc(sizeof(ElemType) * v_size);
	memcpy(h->data, v, sizeof(ElemType) * v_size);
	//MoveDown sposta un nodo in basso finchè non è rispettata la condizione di heap
	//devo prima analizzare l'albero. Parto dai nodi subito sopra alle foglie, per poi salire fino alla prima radice
	for (int i = h->size / 2 - 1; i >= 0; --i) {
		//parto da h->size/2 perchè salto le foglie le quali saranno sicuramente piu della metà del vettore
		//andrebbe bene anche size-1 con un sacco di cicli in piu inutili
		HeapMinMoveDown(h, i);
	}
	return h;
}