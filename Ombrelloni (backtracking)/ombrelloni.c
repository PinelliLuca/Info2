#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void OmbrelloniRec(int k, int n, int i, bool* vcurr, int cnt, int* nsol) {
	if (i == n) {
		if (cnt == k) {
			for (int k = 0; k < n - 1; ++k) {
				if (vcurr[k] == 1 && vcurr[k + 1] == 1)
					return;
			}
			(*nsol)++;
			for (int j = 0; j < i; ++j) {
				printf(" %d ", vcurr[j]);
			}
			printf("\n");
			return;
		}
		return;
	}
	vcurr[i] = 0;
	OmbrelloniRec(k, n, i + 1, vcurr, cnt, nsol);

	vcurr[i] = 1;
	OmbrelloniRec(k, n, i + 1, vcurr, cnt + 1, nsol);
}


int Ombrelloni(int k, int n) {
	if (n == 0)
		return -1;
	bool* vcurr = calloc(n, sizeof(int));
	int nsol = 0, cnt = 0;
	OmbrelloniRec(k, n, 0, vcurr, cnt, &nsol);
	free(vcurr);
	return nsol;
}
int main() {
	int k = 2, n = 4;
	int nsol = Ombrelloni(k, n);
	printf("\nNumero soluzioni= %d", nsol);
	return 0;
}