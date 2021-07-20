#include <stdio.h>
#pragma warning(disable: 4996)
int main()
{
	int T, k, n;
	int room[15][15] = { 0 };

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (i == 0)
			{
				room[i][j] = j;
				continue;
			}
			for (int k = 0; k <= j; k++)
			{
				room[i][j] += room[i - 1][k];
			}
		}
	}
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d\n%d", &k, &n);
		printf("%d\n", room[k][n]);
	}
	return 0;
}