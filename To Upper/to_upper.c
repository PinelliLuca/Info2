#include<stdio.h>
#include<stdlib.h>

void ToUpper(char* str) {
	if (str == NULL) {
		return;
	}
	printf("Stringa iniziale: %s\n", str);
	//for(int i=0;str[i]!=0;++i)
	for (int i = 0; *(str + i) != 0; ++i) {
		if (*(str + i) >= 'a' && *(str + i) <= 'z') {
			*(str + i) = *(str + i) - ('a' - 'A'); //a-A mi dice la distanza tra i due caratteri in ASCII
		}
	}
	printf("Stringa finale: %s", str);
}
void main() {
	char s[] = "Ciao";
	ToUpper(s);
}