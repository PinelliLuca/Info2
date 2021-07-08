#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void inverti(int* arr, int size, int i) {
	if (i >= size / 2) { 
		//metto size/2 perchè scambio contemporaneamente l'ultimo col primo fino ad arrivare al centro del vettore
		//superato questo centro e continuando a scambiare il l'inizio con la fine del vettore vorrebbe dire in pratica riordinarlo dall'inizio
		return;
	}
	int tmp = arr[i];
	arr[i] = arr[size - 1 - i];
	arr[size - 1 - i] = tmp;
	inverti(arr, size, i + 1);
}


void InvertiArray(int* arr, size_t size) {
	if (size == 0 || arr == NULL)
		return;

	inverti(arr, size, 0);
}
int main() {
	{
		int k[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		int lun = sizeof(k) / sizeof(int);
		for (int i = 0; i < lun; ++i) {
			printf("%d ", k[i]);
		}
		puts("");
		InvertiArray(k, lun);
		for (int i = 0; i < lun; ++i) {
			printf("%d ", k[i]);
		}
		puts("");
	}
	{
		int k[] = { 9,8,7,6,5,4,3,2,1 };
		int lun = sizeof(k) / sizeof(int);
		for (int i = 0; i < lun; ++i) {
			printf("%d ", k[i]);
		}
		puts("");
		InvertiArray(k, lun);
		for (int i = 0; i < lun; ++i) {
			printf("%d ", k[i]);
		}
		puts(""); 
	}
	{
		
		
		puts("");
		InvertiArray(0, NULL);
		puts("");
	}
	return 0;
}
//ESERCIZIO CORRETTO