#include"list.h"
#include "elemtype.h"
#include<stdbool.h>
bool verifica(ElemType* e, Item* i) {
	Item* l = i;
	while (!ListIsEmpty(l)) {
		if (ElemCompare(e, ListGetHeadValue(l)) == 0) {
			return false;
		}
		l = ListGetTail(l);
	}
	return true;
}
Item* Diff(const Item* i1, const Item* i2) {
	Item* out = NULL;
	while (!ListIsEmpty(i1)) {
		const Item* tmp = i2;
		bool c = verifica(ListGetHeadValue(i1), tmp);
		if (c) {
			out = ListInsertBack(out, ListGetHeadValue(i1));
		}
		i1 = ListGetTail(i1);
	}
	return out;
}