#include<stdio.h>
#include<stdlib.h>
#include"newton.h"
extern double Newton(const Polinomio* p, const Polinomio* d, double xn, double t, int max_iter);

static Polinomio* D(const Polinomio* p) {
	Polinomio* d = malloc(sizeof(Polinomio));
	d->size = p->size - 1;
	d->coeff = malloc(sizeof(int) * d->size);

	for (unsigned i = 1; i < p->size; ++i) {
		d->coeff[i - 1] = p->coeff[i] * i;
	}
	return d;
}

int main() {
	double n;
	Polinomio p;
	Polinomio* d;
	p.coeff = malloc(4 * sizeof(int));
	p.size = 4;
	p.coeff[0] = 0;
	p.coeff[1] = -2;
	p.coeff[2] = 0;
	p.coeff[3] = 1;
	d = D(&p);
	n = Newton(&p, d, 1, 0.00001, -1);
	printf("%lf\n", n);
	n = Newton(&p, d, 1, 0.00001, 4);
	printf("%lf\n", n);

	free(p.coeff);
	free(d->coeff);
	free(d);
	return 0;
}
//ESERCIZIO CORRETTO
