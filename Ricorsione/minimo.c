#include<stdio.h>
int MinRec(const int* v,  int v_size, int index) {
	//caso base: ho controllato fino all'ultima posizione perciò per forza il minimo è l'ultimo elemento
	if (v_size - 1 == index)
		return v[index];
	//chiamo la ricorsione dove vado a ricercare il valore minimo tra due elementi
	int min = MinRec(v, v_size, index + 1);
	//in base al minimo tra min e v[index] ritorno il minimo e proseguo con la chiamata a ricorsione
	if (v[index] < min)
		return v[index];
	else
		return min;

}
int Minimo(const int* v, int v_size) {
	return MinRec(v, v_size, 0);
}