#include<stdio.h>
#include<stdlib.h>
/*
Se n èpari allora l'elemento successivo è dato da n/2
Se n è disparei l'elemento successivo è dato da 3*n+1
la sequenza termina al primo 1 incontrato perchè altrimenti infinito */

size_t HailRec(int n) {
	if (n == 1) {
		printf("1");
		return 1;
	}
	printf("%d, ", n);
	if (n % 2 == 0) {
		
		HailRec(n / 2);
	}
	else {
		
		HailRec(3 * n + 1);
	}
}
size_t Hailstone(int n) {
	if (n <= 0) {
		return 0;
	}
	return HailRec(n);
}

int main() {
	int h;
	h = Hailstone(5);
	puts("");
	h = Hailstone(11);
	puts("");
	return 0;
}
//CORRETTO