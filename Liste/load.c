#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"list.h"

Item* ListLoad(const char* filename) {
	FILE* f = fopen(filename, "r");
	Item* out = ListCreateEmpty();
	if (!f)
		return out;
	while (1) {
		ElemType tmp;
		if (1 != ElemRead(f, &tmp)) {
			break;
		}
		out = ListInsertBack(out,ListGetHeadValue(&tmp));
	}
	fclose(f);
	return out;
}