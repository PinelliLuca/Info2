#include<stdlib.h>
#include <stdio.h>

void flip(int* v, size_t i) {
	for (int j = i; j >= 0; j--) {
		int tmp = v[0];
		v[0] = v[j];
		v[j] = tmp;
	}

}
void PancakeSort(int* v, size_t v_size) {
	if (v_size <= 1)
		return;
	size_t curr_size = v_size;
	size_t m = 0;
	while (1) {
		if (v[curr_size] > v[m]) {
			m = curr_size;
		}
		curr_size--;
		if (curr_size == 0)
			break;
	}
	flip(v, m);
	curr_size = v_size - 1;
	while (1) {
		flip(v, curr_size);
		curr_size--;
		if (curr_size == 1)
			break;
	}
}

int main() {
	int vector[] = { 4,3,5,1,2 };
	PancakeSort(vector, 5);
	for (int i = 0; i < 5; i++) {
		printf(" %d,", vector[i]);
	}
}
//Non completamente corretto, da riguardare
