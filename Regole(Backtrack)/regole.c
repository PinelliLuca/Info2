#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Back(int n, const char* r, int i, int* vcurr, bool* usati) {
	//i si muove all'interno di r, scorre quindi le lettere
	//faccio un ciclo for con j che scorra invece i numeri, impostando i dovuti controlli con costrutti di if

	//caso base: l'albero di ricerca sarà di n+1 
	if (i == n + 1) {
		for (int j = 0; j < n + 1; ++j) {
			printf("%d ", vcurr[j]);
		}
		printf("\n");
		return;
	}
	//ciclo for: il controllo sarà contemporaneamente sia sulle lettere che sui numeri.
	//di questi dovrò controllare con j se sono già stati usati e se il precedente è < o >

	for (int j = 1; j <= n + 1; ++j) {
		//ricorda che il primo numero da prendere è 1 quindi per controllare il vettore usati che invece parto da zero l'elemento corrente sarà sempre j-1

		if (!usati[j - 1]) {
			//se nel vettore trovo 'i' E il numero precedente è minore dell'attuale numero j-esimo che sto controllando 
			//allora ho trovato il numero
			bool controllo_incremento = ((r[i - 1] == 'i' || r[i - 1] == 'I') && vcurr[j - 1] < j);

			//se trovo 'd' E il numero precedente a j è maggiore di j allora posso prendere j
			bool controllo_decremento=((r[i - 1] == 'd' || r[i - 1] == 'D') && vcurr[j - 1] > j);
			//se sono al primo numero della sequenza
			bool controllo_prima_lettera = i == 0;
			if (controllo_incremento || controllo_decremento || controllo_prima_lettera) {
				//se uno dei bool è vero allora prendo j
				vcurr[i] = j;
				usati[j - 1] = true;
				Back(n, r, i + 1, vcurr, usati);
			}
		
			//ricorda sempre di "cancellare" la scelta attuale in modo. In questo modo controllerò le sequenze successive di j
			usati[j - 1] = false;
		}
	}
}
void Regole(const char* r) {
	/*if (strlen(r) == 0) {
		printf("1\n");
		return;
	} inutile
	*/
	int n = strlen(r);
	bool* usati = calloc(n + 1, sizeof(bool));
	int* vcurr = malloc((n + 1) * sizeof(int));

	Back(n, r, 0, vcurr, usati);
	free(vcurr); 
	free(usati);
	
}
int main() {
	Regole("I");
	puts("");
	Regole("D");
	puts("");
	Regole("DI");
	puts("");
	Regole("Id");
	puts("");
	Regole("");
	puts("");
	return 0;
}