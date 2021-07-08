#define _USE_MATH_DEFINES
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include <cfloat>

double SenoRec(double x, int i,int n) {
	if (n > i)
		return 0;
	//tgamma(n)=(n-1)!
	//tgamma(n+1)=n!
	double cur = (pow(-1, n) / tgamma(2 * n + 1 + 1)) * pow(x, 2 * n + 1);
	return cur + SenoRec(x, i, n + 1);

}
double Seno(double x, int i) {
	if (i < 0)
		return DBL_MIN;
	return SenoRec(x, i,0);
}
int main() {
	double s;
	s = Seno(M_PI / 2, 2);
	printf("%lf", s);
}