#include<stdio.h>
#include<stdlib.h>
void Backtrack(int n, int k, int i, char* vcurr,int *nsol) {
	//caso base
	if (k == i) {
		printf("{ ");
		for(int j=0;j<k;++j){
			printf("%c ", vcurr[j]);
		}
		printf("}, ");
		(*nsol)++;
		return;
	}

	for (char c = 'a'; c < 'a' + n; ++c) {
		vcurr[i] = c;
		Backtrack(n, k, i + 1, vcurr,nsol);
	}
}
void BacktrackStrMod(int n, int k) {
	if (n <= 0 || k <= 0 || k > 26)
		return;
	int nsol = 0;
	char* vcurr = malloc(k);
	Backtrack(n, k, 0, vcurr,&nsol);
	printf("\nNUMERO LETTERE %d, LUNGHEZZA STRINGA %d\nNUMERO SOLUZIONI %d", k, n, nsol);
	free(vcurr);
}

int main() {
	BacktrackStrMod(3, 2);
	puts("");
	BacktrackStrMod(0, 2);
	puts("");
	BacktrackStrMod(5, 2);
	puts("");
	puts("");
	BacktrackStrMod(3, 5);
	puts("");
	return 0;
}