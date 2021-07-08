#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
/*La funziona accetta come parametri due numeri interi positivi n,k e deve stampare su stdout
tutti i sottoinsiemi di cardinalità k dell'insieme contenente i primi n numeri
naturali a partire da 0. */
void SubsetKRec(int n, int k, bool* vcurr, int i, int* nsol, int cnt) { //nsol passato per indirizzo! cnt è il numero di elementi taken
	if (i == n) {//caso base per terminare la ricorsione

		if (cnt == k) { //controllo se il numero di taken è corretto
			(*nsol)++; //se il numero di taken è corretto allora ho una soluzione e incremento il numero di sol totali 
		//nsol passato come puntatore, per incrementarlo devi prima deferenziarlo
			printf("{ ");
			for (int j = 0; j < i; ++j) { //!! metto j<i in modo da non stamapare cevvhi valori presenti in vcurr dato che mi sono fermato prima nella ricerca
				if (vcurr[j]) {
					printf("%d ", j); //stampo 
				}
			}
			printf("}, ");
		}
		return; //HAI TERMINATO LA RICORSIONE, RITORNA!
	}
	vcurr[i] = 0; //not taken
	SubsetKRec(n, k, vcurr, i + 1, nsol, cnt); //avanzo nei livelli i-esimi
	vcurr[i] = 1; //taken
	SubsetKRec(n, k, vcurr, i + 1, nsol, cnt + 1); //avanzo e incremento cnt
}

int SubsetK(int n, int k) {
	//vado ad allocare e creare le strutture dati che mi saranno necessarie per risolvere l'esercizio

	bool* vcurr = calloc(n, sizeof(bool)); //vettore dove mi dice se l'i-esimo elemento è stato preso oppure no
	int nsol = 0;
	SubsetKRec(n, k, vcurr, 0, &nsol, 0);
	printf("\nNumero di soluzioni: %d\n", nsol);
	free(vcurr);
	return nsol; //voglio il numero di soluzioni totali
}
/* 
altra visione del programma: aggiungo caso base di cnt==k invece che metterlo come controllo->so che una volta raggiunto il numero massimo di soluzioni amissibili
* i livelli di sottoalbero accettabili saranno solamente quelli con not taken, quindi posso già interrompere. RICORDA IL RETURN!
void SubsetKRec(int n, int k, bool* vcurr, int i, int* nsol, int cnt) { 

if (cnt == k) { //controllo se il numero di taken è corretto
			(*nsol)++; 
			printf("{ ");
			for (int j = 0; j < n; ++j) {
				if (vcurr[j]) {
					printf("%d ", j); //stampo
				}
			}
			printf("}, ");

	if (i == n) { //caso base NECESSARIO perchè se sorro l'albero da sinistra (ad es 0,0,0,0) devo fermarmi anche se cnt<k 
	//perchè comunque ho terminato i livelli dell'albero
		return; 
	}
	vcurr[i] = 0; //not taken
	SubsetKRec(n, k, vcurr, i + 1, nsol, cnt); 

	vcurr[i] = 1; //taken
	SubsetKRec(n, k, vcurr, i + 1, nsol, cnt + 1); 
}
*/

int main() {
	SubsetK(4, 2);
	return 0;
}