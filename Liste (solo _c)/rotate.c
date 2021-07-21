#include"list.h"
Item *Rotate(Item* i, int n) {
	//Per HP: lista non vuota e numero di elementi>n
	if (n == 0) {
		return i;
	}
	Item* tmp=i;
	Item* last =i;
	Item* ris = i;
	while (!ListIsEmpty(ListGetTail(last))) {
		last = ListGetTail(last);
	}
	int j = 0;
	if (n == 1) {
		ris = ListGetTail(tmp);
		tmp->next = NULL;
		last->next = i;
		return ris;
	}
	while(!ListIsEmpty(ListGetTail(tmp))) {
		if (j + 1 == n) {
			tmp->next = NULL;
			last->next = i;
			break;
		}
		j++;
		tmp = ListGetTail(tmp);
		ris = ListGetTail(tmp);
	}
	return ris;
} //corretto