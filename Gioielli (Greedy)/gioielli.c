#define _CRT_SECURE_NO_WARNINGS
#include "gioielli.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int CompareGioielli(const void* a, const void* b) {
    const Gioiello* pa = a;
    const Gioiello* pb = b;
    float a_value = pa->peso / pa->prezzo;
    float b_value = pb->peso / pb->prezzo;

    return (a_value < b_value) - (a_value > b_value);
}

int LeggiDati(FILE* f, Gioiello** g) {
    Gioiello* letti = NULL;
    Gioiello tmp;

    int i = 0;
    while (1) {
        if (fscanf(f, "%i %f %f", &tmp.codice, &tmp.peso, &tmp.prezzo) != 3) {
            break;
        }
        letti = realloc(letti, (++i) * sizeof(Gioiello));
        letti[i - 1] = tmp;
    }

    *g = letti;

    fclose(f);
    return i;
}

Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size) {
    int n;       // Numero di gioielli disponibili
    Gioiello* g; // Gioielli disponibili
    Gioiello* a; // Gioielli acquistati

    FILE* f;

    f = fopen(filename, "r");
    if (f == NULL) {
        return NULL;
    }

    n = LeggiDati(f, &g);
    a = malloc(n * sizeof(Gioiello));

    // Ordino i gioielli in senso decrescente rispetto all'appetibilità
    qsort(g, n, sizeof(Gioiello), CompareGioielli);

    float soldi_rimasti = budget;
    size_t a_size = 0;
    int i = 0; // Indice gioiello corrente nel vettore g

    while (soldi_rimasti > 0 && i < n) {
        if (g[i].prezzo <= soldi_rimasti) {
            a[a_size++] = g[i];
            soldi_rimasti -= g[i].prezzo;
        }
        i++;
    }

    *ret_size = a_size;
    free(g);
    a = realloc(a, sizeof(Gioiello) * a_size); // Si potrebbe omettere!
    return a;
}



int main(void) {

    size_t ret_size;
    Gioiello* g;
    g = CompraGioielli("gioielli_1.txt", 121, &ret_size);
    free(g);

    g = CompraGioielli("gioielli_1.txt", 130, &ret_size);
    free(g);

    g = CompraGioielli("gioielli_2.txt", 121, &ret_size);
    free(g);

    g = CompraGioielli("gioielli_2.txt", 200, &ret_size);
    free(g);

    g = CompraGioielli("gioielli_3.txt", 121, &ret_size);
    free(g);

    g = CompraGioielli("gioielli_3.txt", 200, &ret_size);
    free(g);

    return 0;
}

