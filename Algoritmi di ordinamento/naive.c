#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
void SwapNaive(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
size_t TrovaPosMax(int v[], size_t size) {
	int p = 0;
	for (size_t i = 1; i < size; ++i) {
		if (v[i] > v[p]) {
			p = i;
		}
	}
	return p;
}
void Naive(int v[], size_t size) {
	if (v == NULL || size <= 1)
		return;
	while (size > 1) {
		size_t pos = TrovaPosMax(v, size);
		if (pos < size - 1) {
			SwapNaive(&v[pos], &v[size - 1]);
			
		}
		size--;
	}
}