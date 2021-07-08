#include<stdio.h>
#include<stdlib.h>
#include <string.h>

void Printbin(int n) {
	if (n == 0) {
		return;
	}
	int b = n % 2;
	Printbin(n / 2);
	printf("%i", b); //se lo metti doo quando reimposta i valori te li stampa al contrario: come deve fare
}
int main(int argc, char** argv) {
	char* n = argv[1];
	int  b = atoi(n);
	if (argc != 2 || b < 0) {
		return 1;
	}
	Printbin(b);
	return 0;
} //Quasi CORRETTO