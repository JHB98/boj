#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)
int main()
{
	int T, H, W, N, ** hotel, cnt;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d %d", &H, &W, &N);
		hotel = (int**)malloc(sizeof(int*) * H);
		cnt = 0;

		for (int j = 0; j < H; j++)
		{
			hotel[j] = (int*)malloc(sizeof(int) * W);
		}

		for (int k = 0; k < W; k++)
		{
			for (int l = 0; l < H; l++)
			{
				cnt++;
				if (cnt == N)
				{
					if (k < 9)
					{
						printf("%d0%d\n", l + 1, k + 1);
					}
					else
					{
						printf("%d%d\n", l + 1, k + 1);
					}
				}
			}
		}
		
	}
	return 0;
}