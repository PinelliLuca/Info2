#include<stdio.h>

int FibonacciRec(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	//vale anche:
	// if(n==0||n==1) 
	//return n;
	return FibonacciRec(n - 1) + FibonacciRec(n - 2);
}
int Fibonacci(int n) {
	if (n < 0)
		return -1;
	return FibonacciRec(n);
}
int main() {
	int f,n;
	n = 5;
	f = Fibonacci(n);
	printf("Fibonacci di %d = %d\n", n, f);
	n = 4;
	f = Fibonacci(n);
	printf("Fibonacci di %d = %d\n", n, f);
	n = 12;
	f = Fibonacci(n);
	printf("Fibonacci di %d = %d\n", n, f);
	n = 0;
	f = Fibonacci(n);
	printf("Fibonacci di %d = %d\n", n, f);
} //CORRETTO