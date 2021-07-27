#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
void InsMinore(int* v, size_t lastpos) {
	int x = v[lastpos];
	for (size_t i = lastpos - 1; i >= 0 && x < v[i]; --i) {
		v[i + 1] = v[i];
		v[i] = x;
	}
}
void Insert(int* v, size_t dim) {
	if (!v || dim <= 1)
		return;
	for (size_t i = 1; i < dim; i++) {
		InsMinore(v, i);
	}
}