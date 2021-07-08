#include <assert.h>
#include <float.h>
#include <stdlib.h>

#include "sciatori.h"

int main(void) {
    Sciatore* coppie = Accoppia(NULL, NULL, 0);
    free(coppie); // Inutile in questo caso
    {
        double a[] = { 81.5, 34.2, 100, 96.8 };
        double l[] = { 100.2, 200.1, 30.10, 150.12 };
        assert(sizeof(a) == sizeof(l));
        Sciatore* coppie = Accoppia(a, l, sizeof(a) / sizeof(double));
        free(coppie);
    }
    {
        double a[] = { 22.0, 199.1, 110, 32.8 };
        double l[] = { 100.2, 20.1, 30.10, 150.12 };
        assert(sizeof(a) == sizeof(l));
        Sciatore* coppie = Accoppia(a, l, sizeof(a) / sizeof(double));
        free(coppie);
    }
    {
        double a[] = { 22.0, 199.1 };
        double l[] = { 100.2, 20.1 };
        assert(sizeof(a) == sizeof(l));
        Sciatore* coppie = Accoppia(a, l, sizeof(a) / sizeof(double));
        free(coppie);
    }
    {
        double a[] = { 22.0, 199.1, 110, 32.8, 22.0, 199.1, 110, 32.8 };
        double l[] = { 100.4, 20.1, 30.10, 150.12, 30.10, 150.12, 30.10, 150.12 };
        assert(sizeof(a) == sizeof(l));
        Sciatore* coppie = Accoppia(a, l, sizeof(a) / sizeof(double));
        free(coppie);
    }

    return 0;
}
