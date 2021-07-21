#include<stdio.h>
#include<stdlib.h>

void controllo(int n, int d) {
	if (d == n) {
		printf("true");
		return;
	}
	int div = n % d;
	if (div == 0) {
		printf("false");
		return;
	}
	controllo(n, d + 1);
}
int main(int argc, char** argv) {
	int n = atoi(argv[1]);
	if (atoi(argv[1]) < 0 || argc != 2) {
		return 1;
	}
	if (n == 1) {
		printf("false");
		return 0;
	}
	int d = 2;
	controllo(n, d);
	return 0;
}