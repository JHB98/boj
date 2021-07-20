#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)
int main()
{
	char chess[50][50] = { 0 }, check = 'B';
	int N, M, cnt = 0, min = 50;
	scanf("%d %d", &N, &M);
	getchar();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%c", &chess[i][j]);
		}
		getchar();
	}

	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			check = 'B';
			cnt = 0;
			for (int k = 0; k < 8; k++)
			{
				for (int l = 0; l < 8; l++)
				{
					if (check == chess[i + k][j + l])
					{
						if (check == 'B')
						{
							check = 'W';
						}

						else
						{
							check = 'B';
						}
					}
					else
					{
						cnt++;
						if (check == 'B')
						{
							check = 'W';
						}

						else
						{
							check = 'B';
						}
					}
				}
				if (check == 'B')
				{
					check = 'W';
				}

				else
				{
					check = 'B';
				}
			}

			if (min > cnt)
			{
				min = cnt;
			}

			cnt = 0;
			check = 'W';

			for (int k = 0; k < 8; k++)
			{
				for (int l = 0; l < 8; l++)
				{
					if (check == chess[i + k][j + l])
					{
						if (check == 'B')
						{
							check = 'W';
						}

						else
						{
							check = 'B';
						}
					}
					else
					{
						cnt++;
						if (check == 'B')
						{
							check = 'W';
						}

						else
						{
							check = 'B';
						}
					}
				}
				if (check == 'B')
				{
					check = 'W';
				}

				else
				{
					check = 'B';
				}
			}

			if (min > cnt)
			{
				min = cnt;
			}
		}
	}

	printf("%d", min);

	return 0;
}