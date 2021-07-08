#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct {
	unsigned p; //peso
	unsigned a; //altezza
	unsigned l; //limite
} Cartone;
typedef struct {
	unsigned a; //altezza torre
	int* c_ids; //vettore di cartoni (id)-->0,2,1 significa che la torre è costruita con i cartoni in posizione 0,2 e 1
	int c_size; //dimensione di c_ids
	unsigned peso; //peso della torre(somma dei pesi dei cartoni caricati attualmente
} Torre;


void TorreCartoniRec(int n, const Cartone* c, int i, Torre* vcurr, Torre* vbest, bool *usati) {
	if (i == n) {
		if (vcurr->a > vbest->a) {
			vbest->a = vcurr->a;
			vbest->peso = vcurr->peso;
			vbest->c_size = vcurr->c_size;
			memcpy(vbest->c_ids, vcurr->c_ids, sizeof(int) * vcurr->c_size);
		}
		return;
	}
	bool rami_validi = false;
	for (int j = 0; j < n; ++j) {
		if (!usati[j] && c[j].l >= vcurr->peso) { //stai costruendo dall'alto! devi verificare che la somma dei pacchi superiori non superino il limite di quello che stai controlando perchè andrà in basso
			rami_validi = true; //sono entrato, quindi il ramo è valido e non entro nella ricorsione finale di if(!rami_validi)
			vcurr->a += c[j].a;
			vcurr->peso += c[j].p;
			vcurr->c_ids[vcurr->c_size] = j;
			vcurr->c_size++;

			usati[j] = 1;
			TorreCartoniRec(n, c, i + 1, vcurr, vbest, usati);
			//torno ad aggiornare le informazioni per il calcolo del successivo ramo dove prenderò il pacco,
			//altrimenti mi porterei dietro le informazioni calcolate precedentemente nel successivo pacco caricato, 
			//ricorda che stai aggiornando i dati nell variabili della chiamata e poi chiami con quei dati procedendo l'esplorazione
					vcurr->a -= c[j].a;
					vcurr->peso -= c[j].p;
					vcurr->c_size--;

					usati[j] = 0;
		}
	}

	if (!rami_validi) { //durante l'esplorazione degll'albero mi ritroverò ad un certo punto ad un nodo che presenta figli non ammissibili,
		//prima di ritornare la chiamata forzo una ricorsione per aggiornare vbest nel caso in cui io abbia trovato una torre migliore e per farlo impongo i==n,
		//in questo modo alla chiamata successiva entrerò nell'if(i==n) caso base per verificare vbest e nel caso aggiornarlo.
		//Tutto questo mi permette di evitare le successive chiamate ricorsive per i figli di quel nodo.
		TorreCartoniRec(n, c, n, vcurr, vbest, usati);
	}
}

void TorreCartoni(const Cartone* c, size_t n) {
	bool* usati = calloc(n, sizeof(bool));
	Torre vcurr = { .a = 0,.c_ids = malloc(n * sizeof(int)),.c_size = 0,.peso = 0 };
	Torre vbest = { .a = 0,.c_ids = malloc(n * sizeof(int)),.c_size = 0,.peso = 0 };
	TorreCartoniRec((int)n, c, 0, &vcurr, &vbest, usati);

	for (int j = 0; j < vbest.c_size; ++j) {
		printf("%d\n", vbest.c_ids[j]);
	}
	printf("\nAltezza %d", vbest.a);
	free(vbest.c_ids);
	free(vcurr.c_ids);
	free(usati);
}

int main() {
	{
		Cartone c[] = { {.p = 10,.a = 10,.l = 8},{.p = 10,.a = 20,.l = 40},{.p = 9,.a = 3,.l = 5} };
		TorreCartoni(c, sizeof(c) / sizeof(Cartone));
		puts("");
	}
	{
		Cartone c[] = { {.p = 25,.a = 20,.l = 40},{.p = 10,.a = 10,.l = 12},{.p = 9,.a = 3,.l = 5} };
		TorreCartoni(c, sizeof(c) / sizeof(Cartone));
		puts("");
	}
	return 0;
}