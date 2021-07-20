#include <stdio.h>
#pragma warning(disable: 4996)
int main()
{
	int N, num, ref, sum = 0;
	scanf("%d", &N);
	for (int i = 1; i < N; i++)
	{
		num = i;
		sum += i;
		while (num > 0)
		{
			ref = num % 10;
			num /= 10;
			sum += ref;
		}
		if (sum == N)
		{
			printf("%d", i);
			return 0;
		}
		sum = 0;
	}
	printf("0");
	return 0;
}