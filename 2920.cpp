#include <stdio.h>
#pragma warning(disable: 4996)

int main()
{
	int num[8];

	for (int i = 0; i < 8; i++)
	{
		scanf("%d", &num[i]);
	}


	if (num[0] == 1)
	{
		for (int i = 1; i < 8; i++)
		{
			if (num[i] != (i + 1))
			{
				printf("mixed");
				return 0;
			}
		}

		printf("ascending");
	}

	
	else if (num[0] == 8)
	{
		for (int i = 1; i < 8; i++)
		{
			if (num[i] != (8 - i))
			{
				printf("mixed");
				return 0;
			}
		}

		printf("descending");
	}

	else
	{
		printf("mixed");
	}


	return 0;
}