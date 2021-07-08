#include<stdio.h>
long long FattRec(int n) {
	//base case
	if (n == 1)
		return 1;
	return FattRec(n - 1) * n;
}

unsigned long long Fattoriale(int n) {
	if (n < 0)
		return -1;
	return FattRec(n);
}