#include <stdio.h>
#pragma warning(disable: 4996)

int main()
{
	int num1, num2, num3, num4 = 100000000, result;
	int check[10] = { 0 };
	scanf("%d %d %d", &num1, &num2, &num3);
	result = num1 * num2 * num3;

	while (1)
	{

		if (num4 == 0)
		{
			break;
		}
		if (result == 0)
		{
			check[0]++;
			break;
		}
		if (num4 > result)
		{
			num4 /= 10;
		}

		else
		{
			check[result / num4]++;
			result = result % num4;
			num4 /= 10;

			if (num4 > result)
			{
				while (1)
				{
					if (num4 <= result)
					{
						break;
					}
					check[0]++;
					num4 /= 10;
				}
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", check[i]);
	}
	return 0;
}