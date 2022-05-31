#include <stdio.h>

double f(long n)
{
	long f1 = 1;
	long  f2 = 1;
	long i, temp;
	for (i = 2; i < n + 1; i++)
	{
		f1 = f1 + f2;
		temp = f1;
		f1 = f2;
		f2 = temp;
	}
	return ((double)f1 / (double)f2);
}

int main()
{
	long n = 100;
	double g;
	g = f(n);
	printf("g = %lf\n", g);
}

