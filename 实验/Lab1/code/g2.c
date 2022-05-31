#include <stdio.h>

long f(long n)
{
	if (n == 1) return 1;
	else if (n == 2) return 1;
	else return (f(n - 1) + f(n - 2));
}

int main()
{
	long n = 100;
	double g;
	g = ((double)f(n)) / ((double)f(n + 1));
	printf("g = %lf\n", g);
}

