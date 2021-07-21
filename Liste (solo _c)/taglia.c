#include"list.h"

Item* Taglia(Item* i, int n) {
	if (ListIsEmpty(i) || n < 0)
		return i;
	if (n == 0) {
		ListDelete(i);
		return ListCreateEmpty();
	}
	Item *tmp = i;
	int j = 0;
	while (!ListIsEmpty(ListGetTail(tmp))) {
		if (j + 1 == n) {
			ListDelete(ListGetTail(tmp));
			tmp->next = NULL;
			break;
		}
		tmp = ListGetTail(tmp);
		j++;
	}
	return i;
}