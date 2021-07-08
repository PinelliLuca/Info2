#include<stdlib.h>
#include<stdio.h>

int* Monete(int* tagli, size_t tagli_size, int budget) {
	if (budget <= 0)
		return NULL;

	int* res = calloc(tagli_size, sizeof(int));

	for (size_t i = 0; i < tagli_size; ++i) {
		res[i] = budget / tagli[i];
		budget = budget % tagli[i];
	}
	return res;
}

void main() {

	int tagli[] = { 50,20,10,5,2,1 };
	int* res = Monete(tagli, sizeof(tagli) / sizeof(int), 126);
	free(res);

}