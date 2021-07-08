#include<stdio.h>
int SommaFinoARecursive(int n) {
	
	if (n == 1)
		return 1;

	return SommaFinoARecursive(n - 1) + n;
}
int SommaFinoA(int n) {
	if (n <= 0)
		return -1;
	return SommaFinoARecursive(n);
}
