#include"sciatori.h"
#include <float.h>

Sciatore* Accoppia(double* altezze, double* lunghezze, size_t v_size) {
	if (v_size == 0)
		return NULL;
	Sciatore *out = malloc(v_size * sizeof(Sciatore));
	bool *a_usate = calloc(v_size, sizeof(bool));
	bool* l_usate = calloc(v_size, sizeof(bool));
	double best_diff = DBL_MAX; //imposto best diff al massimo valore rappresentabile in double per essere sicuro di 
	//avere ogni valore possibile confrontabile
	int best_a_idx = -1;
	int best_l_idx = -1;
	for (size_t i = 0; i < v_size; ++i) {
		for (size_t a = 0; a < v_size; ++a) {
			if (!a_usate[a]) {
				for (size_t s = 0; s < v_size; ++s) {
					if (!l_usate[s]) {
						if (fabs(altezze[a] - lunghezze[s]) < best_diff) {
							best_diff = fabs(altezze[a] - lunghezze[s]);
							best_a_idx = a;
							best_l_idx = s;
						}
					}
				}
			}
		}
		//indice coppia che sto costruendo
		out[i].a = altezze[best_a_idx];
		out[i].l = lunghezze[best_l_idx];
		//aggiorno per le successive coppie
		a_usate[best_a_idx] = true;
		l_usate[best_l_idx] = true;
		best_diff = DBL_MAX; //ripristino massimo valore per la successiva differenza
	}
	free(a_usate);
	free(l_usate);
	return out;
}
