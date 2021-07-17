#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
bool AtoiRec(const char* str, int i, int* res) {
	int c = str[i];
	if (c == 0) {
		//se arrivo qui la conversione è andata a buon fine
		return true;
	}
	if (str[i] > '9' || str[i] < '0')
		return false;
	//moltiplico per 10 la conversione calcolata fino a questo momento
	(*res) = (*res) * 10 + (str[i] - '0'); //str[i]-'0' ottengo la conversione del carattere char in int
	return AtoiRec(str, i + 1, res);
}
int Atoi(const char* str) {
	if (str == NULL)
		return 0;
	int res = 0;
	int sign = str[0] == '-' ? -1 : 1;
	//se il primo carattere è un segno lo dovrò ignorare
	if (str[0] == '-' || str[0] == '+') {
		str = str + 1;
	}
	bool ok = AtoiRec(str, 0, &res);
	if (!ok)
		res = 0;
	return res * sign;
}
int main() {
	int n;
	n = Atoi("42");
	n = Atoi("+42");
	n = Atoi("-2");
	n = Atoi("4-2");
	n = Atoi(NULL);
	return;

}