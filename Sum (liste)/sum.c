#include"list.h"

Item* Sum(const Item* i1, const Item* i2) {
	
	if (ListIsEmpty(i1) && !ListIsEmpty(i2))
		return i2;
	if (ListIsEmpty(i2) && !ListIsEmpty(i1))
		return i1;
	Item* list = ListCreateEmpty();
	if (ListIsEmpty(i1) && ListIsEmpty(i2))
		return list;
	ElemType riporto = 0;
	while (1) {
		ElemType e1 = ElemCopy(ListGetHeadValue(i1));
		ElemType e2 = ElemCopy(ListGetHeadValue(i2));
		ElemType ins = e1 + e2 + riporto;
		riporto = 0;
		if (ins >= 10) {
			riporto = 1;
			ins -= 10;
		}
		list = ListInsertBack(list, &ins);
		i1 = ListGetTail(i1);
		i2 = ListGetTail(i2);
		if (ListIsEmpty(i1) && !ListIsEmpty(i2)) {
			while (!ListIsEmpty(i2)) {
				e2 = ElemCopy(ListGetHeadValue(i2));
				if (riporto == 1) {
					e2 = e2 + 1;
					riporto = 0;
					if (e2 >= 10) {
						e2 = e2 / 10;
						riporto = 1;
					}
					else {
						riporto = 0;
					}
				}
				list = ListInsertBack(list, &e2);
				i2 = ListGetTail(i2);
			}
		}
		if (ListIsEmpty(i2) && !ListIsEmpty(i1)) {
			while (!ListIsEmpty(i1)) {
				e1 = ElemCopy(ListGetHeadValue(i1));
				if (riporto == 1) {
					e1 = e1 + 1;
					riporto = 0;
					if (e1 >= 10) {
						e1 = e1 / 10;
						riporto = 1;
					}
					else {
						riporto = 0;
					}
				}
				list = ListInsertBack(list, &e1);
				i1 = ListGetTail(i1);
			}
		}
		if (ListIsEmpty(i1) && ListIsEmpty(i2)) {
			if (riporto == 1) { //in teoria inutile, nell'esercizio le liste iniziali presentano solo numeri di una solo unità
				//nel caso in cui si passassero numeri con anche la decina allora impongo questo controllo
				ElemType e = 1; 
				list = ListInsertBack(list, &e);
			}
			break;
		}
	}
	return list;
} //ESERCIZIO CORRETTO SU VS
//SU OLJ ERRORE: <MEMORY_ERROR> Free of pointer not previously allocated using malloc/realloc/calloc.