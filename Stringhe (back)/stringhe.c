#include<stdio.h>
#include<stdlib.h>
void Backtrack(int n, int i, char* vcurr,int *nsol) {
	//caso base
	if (n == i) {
		printf("{ ");
		for (int j = 0; j < n; ++j) {
			printf("%c ", vcurr[j]);
		}
		printf(" }, ");
		(*nsol)++; //se non passo un puntatore mi azzera il valore nel return finale
		return;
	}
	for (char j = 'a'; j < 'a' + n; ++j) {
		vcurr[i] = j; //ATTENZIONE: è vcurr di i non di j, all'i-esimo posto inserisco un carattere che scorro con j

		Backtrack(n, i + 1, vcurr,nsol);
	}
}
void BacktrackStr(int n) {
	if (n <= 0 || n > 26)
		return;
	int nsol = 0;
	char* vcurr = malloc(n * sizeof(char));
	Backtrack(n, 0, vcurr,&nsol); //hli passo l'area di memoria di nsol così che possa modificare il suo valore interno
	printf("\nSOLUZIONI con %d: %d\n", n, nsol); //errore stupido: se metto &nsol mi stampa l'area di memoria, se metto nsol mi stampa il valore in memoria
	free(vcurr);
}
int main() {
	BacktrackStr(-1);
	puts(""); //è un "a capo" come printf("\n")
	BacktrackStr(0);
	puts("");
	BacktrackStr(1);
	puts("");
	BacktrackStr(2);
	puts("");
	BacktrackStr(3);
	puts("");
	BacktrackStr(4);
	puts("");
	BacktrackStr(5);
	puts("");
	return 0;
}
