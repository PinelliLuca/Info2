#include"newton.h"
//polinomio p di cui calcolare uno zero
//polinomio d cioè derivata di p
//valore inizziale xn da cui partire
//tolleranza t
//max_iter numero massimo di iterazioni, utilizzabile solo se max_iter>0
static double F(const Polinomio* p, double xn) {
	double fxn = 0;
	for (size_t i = 0; i < p->size; ++i) {
		/*Per ogni monomio della funzione polinomiale viene calcolato il prodotto tra:
		-coefficiente p->coef[i]
		- il valore xn elevato al grado del monomio i, ovvero pow(xn,i)
		e accumulato il risultato in fxn*/
		fxn += pow(xn, i) * p->coeff[i];	
	}
	return fxn;
}

double Newton(const Polinomio* p, const Polinomio* d, double xn, double t, int max_iter) {
	double p_xn = F(p, xn);
	double d_xn = F(d, xn);
	double xn_1 = xn - p_xn / d_xn;
	//caso base1
	if (fabs(xn_1 - xn) <= t) {
		return xn_1;
	}
	//caso base 2, secondario rispetto a caso base 1, quindi lo metto dopo
	if (max_iter == 1) { //se <1 non mi interessa perchè continuerà ad essere diminuito senza mai essere utilizzato
		return xn_1;
	}
	return Newton(p, d, xn_1, t, max_iter - 1);
}
