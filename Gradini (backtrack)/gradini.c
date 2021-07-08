#include<stdio.h>
#include <stdlib.h>
void back(int n, int i, int* vcurr, int* nsol) {
	if (n == 0) {
		printf("[");
		for (int j = 0; j < i - 1; ++j) {
			printf("%d, ", vcurr[j]);
		}
		printf("%d]", vcurr[i-1]);
		(*nsol)++;
		return;
	}
	for (int j = 1; j <= 3; ++j) {
		if (n >= j) {
			vcurr[i] = j;
			back(n - j, i + 1, vcurr, nsol); //sottraggo qua il totale per la successiva chiamata ricorsiva
		}
	}
}
int Steps(int n) {
	if (n <= 0)
		return 0;
	int* vcurr = malloc(n * sizeof(int));
	int nsol = 0;
	back(n, 0, vcurr, &nsol);
	return nsol;
}
int main() {
	int s;
	s = Steps(2);
	printf("    SOLUZIONI: %d", s);
	puts("");
	s = Steps(1);
	printf("      SOLUZIONI: %d", s);
	puts("");
}