#include <stdio.h>
#pragma warning(disable: 4996)

int main()
{
	int num1, num2, num3 = 2, num4 = 1;
	scanf("%d %d", &num1, &num2);

	while (1)
	{
		if ((num3 > num1) || (num3 > num2))
		{
			break;
		}
		if ((num1 % num3) == 0)
		{
			if ((num2 % num3) == 0)
			{
				num4 *= num3;
				num1 /= num3;
				num2 /= num3;
				num3 = 2;
			}
			else
			{
				num3++;
			}
		}
		else
		{
			num3++;
		}
	}
	printf("%d\n%d", num4, num1 * num2 * num4);


	return 0;
}