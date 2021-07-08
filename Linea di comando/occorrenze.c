#include<stdio.h>

int main(int argc, char** argv) {
	if (argc != 3) {
		fprintf(stderr, "Il numero di parametri non e' corretto. Sintassi del programma \"occorrenze <s> <c>\"");
		return 1;
	}
	char* s = argv[1]; //primo parametro cio� l'indirizzo della stringa
	char c = argv[2][0]; //ricorda che � una stringa: il primo elemento � il carattere mentre il secondo � il terminatore. 
	//Quindi voglio la seconda stringa(seconda lettera) formata da due lettere di cui l'ultima � il terminatore quindi voglio la prima ([0])
	int cnt = 0;
	for (int i = 0; s[i] != 0; ++i) {
		if (s[i] == c) {
			cnt++;
		}
	}
	printf("%i", cnt);
	return 0;
}