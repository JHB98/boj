#include <stdio.h>
#include <math.h>
#pragma warning(disable: 4996)
int main()
{
	double num1, num2, num3, max = 0, ref1, ref2;

	while (1)
	{
		scanf("%lf %lf %lf", &num1, &num2, &num3);

		if ((num1 == 0) && (num2 == 0) && (num3 == 0))
		{
			break;
		}
		
		if (num1 > max)
		{
			max = num1;
			ref1 = num2;
			ref2 = num3;
		}
		if (num2 > max)
		{
			max = num2;
			ref1 = num1;
			ref2 = num3;
		}
		if (num3 > max)
		{
			max = num3;
			ref1 = num1;
			ref2 = num2;
		}

		if ((pow(ref1, 2) + pow(ref2, 2)) == pow(max, 2))
		{
			printf("right\n");
		}
		else
		{
			printf("wrong\n");
		}
		max = ref1 = ref2 = 0;

	}

	return 0;
}