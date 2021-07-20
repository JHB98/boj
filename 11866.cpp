#include <stdio.h>
#pragma warning(disable: 4996)
int check(int person);
int reject[1000] = { 0 }, N = 0;
int main()
{
	int K, cnt = 0, person = 1;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		while (1)
		{
			if (!check(person))
			{
				cnt++;
			}
			else
			{
				person++;
				if (person > N)
				{
					person = 1;
				}
				continue;
			}
			if (cnt == K)
			{
				break;
			}
			person++;
			if (person > N)
			{
				person = 1;
			}
		}
		reject[i] = person;
		cnt = 0;
	}
	printf("<");
	for (int k = 0; k < N-1; k++)
	{
		printf("%d, ", reject[k]);
	}
	printf("%d>", reject[N-1]);

	return 0;
}

int check(int person)
{
	for (int i = 0; i < N; i++)
	{
		if (reject[i] == person)
		{
			return 1;
		}
		if (reject[i] == 0)
		{
			return 0;
		}
	}
	return 0;
}