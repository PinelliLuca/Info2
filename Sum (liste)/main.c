#include"elemtype.h"
#include"list.h"
extern Item* Sum(const Item* i1, const Item* i2);
int main() {
	ElemType e1[] = { 1,2,3 };
	Item* list_a = ListCreateEmpty();
	size_t e1_size = sizeof(e1) / sizeof(ElemType);
	for (size_t i = 0; i < e1_size; ++i) {
		list_a = ListInsertBack(list_a, e1 + i);
	}
	ElemType e2[] = { 1,2,7,10 };
		Item* list_b = ListCreateEmpty();
		size_t e2_size = sizeof(e2) / sizeof(ElemType);
		for (size_t i = 0; i < e2_size; ++i) {
			list_b = ListInsertBack(list_b, e2 + i);
		}
		ListWriteStdout(list_a);
		ListWriteStdout(list_b);
		Item* s = Sum(list_a, list_b);
		ListWriteStdout(s);

		ListDelete(s);
		ListDelete(list_b);
		ListDelete(list_a);
}