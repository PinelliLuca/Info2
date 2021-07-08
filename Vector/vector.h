#pragma once
#include<stdlib.h>
#include<stdio.h>

typedef struct {
	size_t capacity;
	size_t size;
	int* data;
}Vector;