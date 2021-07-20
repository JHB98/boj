#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)
int main()
{
	int N, M, * num, sum = 0;
	scanf("%d %d", &N, &M);
	num = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				if ((sum < (num[i] + num[j] + num[k])) && (M >= (num[i] + num[j] + num[k])))
				{
					sum = num[i] + num[j] + num[k];
				}
			}
		}
	}

	printf("%d", sum);

	return 0;
}