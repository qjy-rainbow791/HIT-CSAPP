#include <stdio.h>

long double f(long double n)
{
	long double f1 = 1;
	long double f2 = 1;
	long double i, temp;
	for (i = 2; i < n + 1; i++)
	{
		f1 = f1 + f2;
		temp = f1;
		f1 = f2;
		f2 = temp;
	}
	return (f1 / f2);
}

int main()
{
	long double n = 100;
	long double g;
	g = f(n);
	printf("g = %Lf\n", g);
}

