#include<stdio.h>

int main(int argc, char** argv) {
	if (argc != 3) {
		fprintf(stderr, "Il numero di parametri non e' corretto. Sintassi del programma \"occorrenze <s> <c>\"");
		return 1;
	}
	char* s = argv[1]; //primo parametro cioè l'indirizzo della stringa
	char c = argv[2][0]; //ricorda che è una stringa: il primo elemento è il carattere mentre il secondo è il terminatore. 
	//Quindi voglio la seconda stringa(seconda lettera) formata da due lettere di cui l'ultima è il terminatore quindi voglio la prima ([0])
	int cnt = 0;
	for (int i = 0; s[i] != 0; ++i) {
		if (s[i] == c) {
			cnt++;
		}
	}
	printf("%i", cnt);
	return 0;
}