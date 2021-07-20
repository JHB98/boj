#include <stdio.h>
#pragma warning(disable: 4996)

int main()
{
	int num, sum[1000] = { 0 };
	char ox[1000] = { 0 };
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int j = 0, score = 1;
		scanf("%s", ox);
		while (1)
		{
			if (ox[j] == '\0')
			{
				break;
			}

			if (ox[j] == 'O')
			{
				sum[i] += score;
				j++;
				score++;
			}

			else
			{
				j++;
				score = 1;
			}
		}
	}
	for (int k = 0; k < num; k++)
	{
		printf("%d\n", sum[k]);
	}


	return 0;
}