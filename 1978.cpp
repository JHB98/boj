#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)
int main()
{
	int N, cnt = 0, * num;
	scanf("%d", &N);
	num = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < N; i++)
	{
		if (num[i] == 1)
		{
			continue;
		}

		if ((num[i] == 2) || (num[i] == 3))
		{
			cnt++;
			continue;
		}

		for (int j = 2; j <= (num[i] / 2); j++)
		{
			if (num[i] % j == 0)
			{
				break;
			}

			if (j == (num[i] / 2))
			{
				cnt++;
			}
		}
	}

	printf("%d", cnt);

	return 0;
}