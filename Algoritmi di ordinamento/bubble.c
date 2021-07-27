#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
void SwapBubble(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void Bubble(int v[], size_t dim) {
	bool ordinato = false;
	while (dim > 1 && !ordinato) {
		ordinato = true;
		for (size_t i = 0; i < dim - 1; ++i) {
			if (v[i] > v[i + 1]) {
				SwapBubble(&v[i], &v[i + 1]);
				ordinato = false;
			}
		}
		dim--;
	}
}