#include<stdio.h>
#include<stdlib.h>
size_t Hailstone(int n) {
	if (n == 1) {
		printf("1\n");
		return 1;
	}
	printf("%d, ", n);
	if (n % 2 == 0) {
		Hailstone(n / 2);
	}
	else {
		Hailstone(3 * n + 1);
	}
}
int main(int argc, char* argv[]) {
	int n = atoi(argv[1]);
	if (n <= 0 || argc != 2) {
		return 1;
	}
	int ris = Hailstone(n);
	printf("ris:%d", ris);
	return 0;
}