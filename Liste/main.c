#include"list.h"
#include<stdlib.h>
extern Item* ListLoad(const char* filename);
extern Item* Intersect(const Item* i1, const Item* i2);
extern Item* Diff(const Item* i1, const Item* i2);

int main() {
	ElemType e1[] = { 3, 4, 2, 0, 45, 1, 3 };
	Item* list_a = ListCreateEmpty();
	size_t e1_size = sizeof(e1) / sizeof(ElemType);
	for (size_t i = 0; i < e1_size; ++i) {
		list_a = ListInsertBack(list_a, e1 + i);
	}

	ElemType e2[] = { 8, 5, 2, 3, 45, 7 };
	Item* list_b = ListCreateEmpty();
	size_t e2_size = sizeof(e2) / sizeof(ElemType);
	for (size_t i = 0; i < e2_size; ++i) {
		list_b = ListInsertBack(list_b, e2 + i);
	}
	Item* load = ListLoad("lista1.txt");
	printf("LoadList: ");
	ListWriteStdout(load);
	
	Item* pari = ListLoad("lista_pari.txt");
	printf("LoadList pari: ");
	ListWriteStdout(pari);
	
	Item* dispari = ListLoad("lista_dispari.txt");
	printf("LoadList dispari: ");
	ListWriteStdout(dispari);
	puts("");
	Item* differenza = Diff(load, pari);
	printf("Differenza pari: ");
	ListWriteStdout(differenza);
	ListDelete(differenza);
	puts("");
	Item* ris = Intersect(list_a, list_b);
	printf("prima lista a: ");
	ListWriteStdout(list_a);
	printf("prima lista b: ");
	ListWriteStdout(list_b);
	printf("funzione Intersect: ");
	ListWriteStdout(ris);
	ListDelete(ris);
	puts("");

	Item* d = Diff(list_a, list_b);
	printf("prima lista a: ");
	ListWriteStdout(list_a);
	printf("prima lista b: ");
	ListWriteStdout(list_b);
	printf("funzione Differenza: ");
	ListWriteStdout(d);
	ListDelete(d);
	puts("");


	ListDelete(pari);
	ListDelete(dispari);
	ListDelete(load);
	ListDelete(list_a);
	ListDelete(list_b);
}