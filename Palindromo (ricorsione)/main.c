#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

bool PalRec(const char* str, size_t start, int end) {
	if (end<0) 
		return true;
	if (str[start] != str[end])
		return false;
	PalRec(str, start + 1, end - 1);
}

bool IsPalindromo(const char* str) {
	size_t size = strlen(str);
	if (str == NULL) {
		return false;
	}
	if (size == 0)
		return true;
	size_t start = 0;
	int end = size - 1; //togli il terminatore. Ricorda che solo un int può essere negativo, non un size_t
	return PalRec(str, start, end);
}
int main(void) {
	{
		int b;
		char s[] = { "osso" };
		b = IsPalindromo(s);
		printf("%s palindromo? ", s);
		if (b == 1) {
			printf("Si");
		}
		else
			printf("No");
		puts(""); 
	}
	{
		int b;
		char s[] = { "" };
		b = IsPalindromo(s);
		printf("%s palindromo? ", s);
		if (b == 1) {
			printf("Si");
		}
		else
			printf("No");
		puts(""); }
	{
		int b;
		char s[] = { "abs" };
		b = IsPalindromo(s);
		printf("%s palindromo? ", s);
		if (b == 1) {
			printf("Si");
		}
		else
			printf("No");
		puts(""); 
	}
	{
		int b;
		char s[] = { "ossesso" };
		b = IsPalindromo(s);
		printf("%s palindromo? ", s);
		if (b == 1) {
			printf("Si");
		}
		else
			printf("No");
		puts("");
	}
	return 0;
} //ESERCIZIO CORRETTO