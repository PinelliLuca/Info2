int fiborec(int n)
{
	if (n == 1)
		return 1;
	if (n == 0)
		return 0;
	return fiborec(n - 1) + fiborec(n - 2);
}


int Fibonacci(int n) {
	if (n < 0)
		return -1;
	return fiborec(n);
}