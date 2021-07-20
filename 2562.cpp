#include <stdio.h>
#pragma warning(disable: 4996)
int main()
{
	int num[9], max, number = 1;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &num[i]);
	}

	max = num[0];

	for (int k = 1; k < 9; k++)
	{
		if (max < num[k])
		{
			max = num[k];
			number = k + 1;
		}

	}
	printf("%d\n%d", max, number);
	return 0;
}