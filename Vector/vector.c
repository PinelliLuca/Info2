#include"vector.h"
//Ordina vettore



void PushBack(Vector* v, int e) {
	//controllo che io abbia ancora posto per inserire elementi, altrimenti riallargo la memoria
	if (v->size == v->capacity) {
		//raddoppio la capacità tutte le volte in modo da non fare troppe realloc, le quali sono costose in termini
		//di prestazioni. Raddoppiando devo riallocare meno volte e senza esagerare con l'allocazione in termini di dimensioni di memoria
		v->capacity *= 2;
		v->data = realloc(v->data, sizeof(int) * v->capacity);
	}
	v->data[v->size] = e; //in fondo al vettore metto l'elemento
	(v->size)++; //ridimensiono la size
}







int main() {
	Vector v = { .capacity = 1,.size = 0,.data = malloc(sizeof(int) * 1) };
	srand(0);
	for (int i = 0; i < 20; ++i) {
		PushBack(&v, rand());
	}
	return 0;
}