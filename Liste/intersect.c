#include"list.h"
#include<stdbool.h>
//date due liste la funzione Intersect ritorna gli elementi comuni delle due liste,in ordine. Lista di ritorno create da zero
//soluzione esercizio con funzione di appoggio
bool controllo(ElemType* e, Item* i2) {
	Item* t = i2;
	while (!ListIsEmpty(t)) {
		if (ElemCompare(e, ListGetHeadValue(t)) == 0) {
			return true;
		}
		t = ListGetTail(t);
	}
	return false;
}

Item* Intersect(const Item* i1, const Item* i2) {
	Item* ris = ListCreateEmpty();
	//soluzione esercizio senza funzione di appoggio(due cicli for annidati)
/*	for (const Item* tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		for (const Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) == 0) {
				ris = ListInsertBack(ris, ListGetHeadValue(tmp1));
				break; //per evitare valori doppi, dopo che ho aggiunto l'elemento esco dal secondo ciclo così vado avanti nei numeri di i1
			}
		}
	}
	*/
	
	while (!ListIsEmpty(i1)) {
		const Item* tmp = i2;
		bool insert = controllo(ListGetHeadValue(i1), tmp);
		if (insert) {
			ris = ListInsertBack(ris, ListGetHeadValue(i1));
		}
		i1 = ListGetTail(i1);
	}

	return ris;
}