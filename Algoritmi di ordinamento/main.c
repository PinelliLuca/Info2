#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
extern void Naive(int v[], size_t size);
extern void Bubble(int v[], size_t dim);
extern void Insert(int* v, size_t dim);
extern void Quick(int* v, int first, int last);

int main() {
	{
		int s[] = { 4,2,6,5,7,1,9,3,8 };
		size_t size = sizeof(s) / sizeof(int);
		printf("NAIVE SORT: \n");
		for (int i = 0; i < size; ++i) {
			printf("%d ", s[i]);
		}
		puts("");
		Naive(s, size);
		for (int i = 0; i < size; ++i) {
			printf("%d ", s[i]);
		}
		printf("\n\n");
	}
	{
		int s[] = { 4,2,6,5,7,1,9,3,8 };
		size_t size = sizeof(s) / sizeof(int);
		printf("BUBBLE SORT: \n");
		for (int i = 0; i < size; ++i) {
			printf("%d ", s[i]);
		}
		puts("");
		Bubble(s, size);
		for (int i = 0; i < size; ++i) {
			printf("%d ", s[i]);
		}
		printf("\n\n");
	}
	{
		int s[] = { 4,2,6,5,7,1,9,3,8 };
		size_t size = sizeof(s) / sizeof(int);
		printf("INSERT SORT: \n");
		for (int i = 0; i < size; ++i) {
			printf("%d ", s[i]);
		}
		puts("");
		Insert(s, size);
		for (int i = 0; i < size; ++i) {
			printf("%d ", s[i]);
		}
		printf("\n\n");
	}

	{ 
			int s[] = { 4,2,6,5,7,1,9,3,8 };
			size_t size = sizeof(s) / sizeof(int);
			printf("QUICK SORT: \n");
			for (int i = 0; i < size; ++i) {
				printf("%d ", s[i]);
			}
			puts("");
			Quick(s,0, size-1);
			for (int i = 0; i < size; ++i) {
				printf("%d ", s[i]);
			}
			printf("\n\n");
		}
}