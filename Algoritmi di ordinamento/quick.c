#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
void SwapQuick(int *a, int* b) {
	int tmp = *a;
	*a= *b;
	*b = tmp;
}
void Quick(int* v, int first, int last) {
	int i, j;
	i = first;
	j = last;
	if (first < last) {
		int pivot = v[(first + last) / 2];
		while (v[i] <= v[j]) {
			while (v[i] < pivot)
				i++;
			while (v[j] > pivot)
				j--;
			if (v[i] <= v[j]) {
				SwapQuick(&v[i], &v[j]);
				i++;
				j--;
			}
		}
	}
	Quick(v, first, j-1);
	Quick(v, i+1, last);
}