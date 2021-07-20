#include <stdio.h>
#pragma warning(disable: 4996)

int main()
{
	double a, b;
	scanf("%lf %lf", &a, &b);
	printf("%.9lf", a / b);

	return 0;
}