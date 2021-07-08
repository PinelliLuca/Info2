#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void SubsetBack(int n, int s, int i, bool* vcurr, int tot, int* trovati) {
//caso base 1: il totale è uguale al valore dato (s)
	if (tot == s) {
		printf("{ ");
		for (int j = 1; j <= n; ++j) {
			if (vcurr[j]) {
				printf("%d ", j);
			}
		}
		printf("}, ");
		(*trovati)++;
		return;
	}
	//caso base 2: i è maggiore dei numeri utilizzabili quindi ho sbagliato e ricomincio
	//NON USARLO COME CASO BASE 1 ALTRIMENTI TI TROVA SOLO LA PRIMA SOLUZIONE
	if (i > n) {
		return;
	}
	if (tot + i <= s) {
		vcurr[i] = true;
		SubsetBack(n, s, i + 1, vcurr, tot + i, trovati);
		vcurr[i] = false; //ripristino lo stato di vcurr per le successive chiamate
			SubsetBack(n, s, i + 1, vcurr, tot, trovati);
	}

}

int SubsetEqual(int n, int s) {
	if (n <= 0 || s <= 0)
		return 0;
	int trovati = 0;
	bool* vcurr = calloc(n + 1, sizeof(bool));
	SubsetBack(n, s, 1, vcurr, 0, &trovati);
	free(vcurr);
	return trovati;
}
int main() {
	int sub;
	sub = SubsetEqual(4, 6);
	printf("\n%d", sub);
	puts("");
	return 0;
}