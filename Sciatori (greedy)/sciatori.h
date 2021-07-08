#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <stdint.h>
#include<math.h>
typedef struct {
	double a;
	double l;
}Sciatore;		
extern Sciatore* Accoppia(double* altezze, double* lunghezze, size_t v_size);
