#include<stdlib.h>
#include<stdio.h>
int MCDRec(int m, int n) {
	if (m == 0) {
		return n;
	}
	if (n == 0) {
		return m;
	}
	if (m >= n) {
		return MCDRec(n, m - n);
	}
	else {
		return MCDRec(n - m, m);
	}
}
int MCD(int m, int n) {
	if (m == 0 && n != 0)
		return n;
	if (n == 0 && m != 0)
		return m;
	int d = MCDRec(m, n);
	return d;
}
int main() {
	int ris;
	ris = MCD(12, 3);
	printf("%d\n", ris);
	ris = MCD(0, 4);
	printf("%d\n", ris);
	ris = MCD(42, 28);
	printf("%d\n", ris);
	return 0;
} //CORRETTO