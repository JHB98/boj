#include <stdio.h>
#pragma warning(disable: 4996)

int main()
{
	int num[10], cnt = 0;

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &num[i]);
		num[i] = num[i] % 42;
	}

	for (int j = 0; j < 10; j++)
	{
		if (num[j] == -1)
		{

		}
		else
		{
			for (int k = j + 1; k < 10; k++)
			{
				if (num[k] == -1)
				{

				}
				else if (num[j] == num[k])
				{
					num[k] = -1;
				}
			}
		}
	}

	for (int l = 0; l < 10; l++)
	{
		if (num[l] != -1)
		{
			cnt++;
		}
	}
	printf("%d", cnt);


	return 0;
}