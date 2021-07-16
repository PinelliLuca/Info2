#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
bool palindromo(char *str, int start, int end) {
	if (end < 0)
		return true;
	if (str[start] != str[end])
		return false;
	palindromo(str, start + 1, end - 1);
}

int main(int argc, char** argv) {
	if (argc != 2) {
		printf("Ricontrolla il numero delle stringhe passate");
		return 1;
	}
	
	int end = strlen(argv[1]) - 1;
	int start = 0;
	bool ris =	palindromo(argv[1],start,end);
	if (ris == false) {
		printf("%s Palindromo? NO", argv[1]);
	}
	else {
		printf("%s Palindromo? SI", argv[1]);
	}
	return 0;
}