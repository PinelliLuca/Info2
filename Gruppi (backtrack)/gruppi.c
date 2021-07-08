#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct studente {
	char nome[21];
};
bool Verifica(struct studente* vcurr, int len, struct studente* to_check) {
	for (int j = 0; j < len; ++j) {
		bool prima_lettera = (vcurr[j].nome[0] == to_check->nome[0]);
			bool iniziali_consecutive = (vcurr[j].nome[0] == to_check->nome[0] + 1) || (vcurr[j].nome[0] == to_check->nome[0] - 1);
			if (prima_lettera || iniziali_consecutive) {
				return false;
			}
	}
	return true;
}
void GruppiRec(struct studente* stud, int k, struct studente* vcurr, int i, int n, int* nsol) {
	if (i == n) {
		printf("{ %s,", vcurr[0].nome);
		for (int j = 1; j < n; ++j) {
			printf("%s ", vcurr[j].nome);

		}
		(*nsol)++;
		return;
	}
	for (int j = 0; j < k; j++) {
		if (Verifica(vcurr, i, stud + j)) {
			strcpy(vcurr[i].nome, stud[j].nome);
			GruppiRec(stud, k, vcurr, i + 1,n, nsol);

		}
	}
}
int Gruppi(const char* filename, int n) { //n: numero studenti in ogni gruppo
	FILE* f = fopen(filename, "r");
	if (!f)
		return 0;
	struct studente* stud = NULL;
	int k = 0; //elementi vettore studenti
	while (1) {
		stud = realloc(stud, sizeof(struct studente) * (k + 1)); //rialloco aggiungendo (+1) l'ultimo elemento
		if (fscanf(f, "%20s", stud[k].nome) != 1) {
			//se non ci sono più nomi l'ultima realloc ha allocato uno spazio in piu
			stud = realloc(stud, sizeof(struct studente) * k); //facendo per k ho gli esatti oggetti presenti dato che mi ha fatto da contatore
			break;
		}
		k++;
	}
	fclose(f);
	if (n < 1 || n < k) {
		free(stud);
		return 0;
	}
	int nsol = 0;
	struct studente* vcurr = malloc(sizeof(struct studente) * n);
	GruppiRec(stud, k, vcurr, 0, n, &nsol);
	free(stud);
	free(vcurr);
	return nsol;
}
int main() {
	int s;
	s = Gruppi("test1.txt", 1);
	printf("\nSOLUZIONI: %d", s);
	puts("");
	s = Gruppi("test1.txt", 2);
	printf("\nSOLUZIONI: %d", s);
	puts("");
	s = Gruppi("test1.txt", 5);
	printf("\nSOLUZIONI: %d", s);
	puts("");
	return 0;
} //NON CORRETTO
//non mi apre i nomi da file