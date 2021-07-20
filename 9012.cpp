#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)
int main()
{
	int T, cnt;
	char P;
	scanf("%d", &T);
	getchar();

	for (int i = 0; i < T; i++)
	{
		cnt = 0;
		while (1)
		{
			if (cnt < 0)
			{
				break;
			}

			P = getchar();

			if (P == '\n')
			{
				break;
			}

			else if (P == '(')
			{
				cnt++;
			}

			else
			{
				cnt--;
			}
		}

		if (cnt == 0)
		{
			printf("YES\n");
		}

		else if (cnt < 0)
		{
			while (1)
			{
				if (getchar() == '\n')
				{
					break;
				}
			}
			printf("NO\n");
		}

		else
		{
			printf("NO\n");
		}
	}

	return 0;
}