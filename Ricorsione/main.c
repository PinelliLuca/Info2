#include<stdio.h>
#include<stdlib.h>
//to avoid warning
extern int SommaFinoA(int n); 
extern long long Fattoriale(int n);
extern int Minimo(const int* v, int v_size);
extern int Fibonacci(int n);
int main() {
	//inizializzatore n
	int n = 5;
	//somma fino a n
	int s = SommaFinoA(n);
		printf("somma fino a %d = %d\n",n, s);
		//fattoriale di n
		n = 6;
			long long f = Fattoriale(n);
				printf("fattoriale di %d = %lld\n", n, f);
			//minimo
				int v[] = { 3,5,9,2 };
				int size = sizeof(v) / sizeof(int);
				int min = Minimo(v, size);
				printf("minimo=%d\n", min);

				//Fibonacci
				int fib = Fibonacci(n);
				printf("Fibonacci di %d vale: %d\n", n, fib);
			return 0;
}