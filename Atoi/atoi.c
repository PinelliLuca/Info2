#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int AtoiRec(const char* str, int i) {
	if (i == 0)
		return *str - '0';
	return 10 * AtoiRec(str, i - 1)+(str[i]-'0');
}
int Atoi(const char* str) {
	if (str == NULL)
		return NULL;
	return AtoiRec(str, strlen(str) - 1);
}
int main() {
	int num = Atoi("42");
	printf("%d", num);
}