#include <stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)

int main()
{
	int N, min = 0, max = 0;
	int* number;
	scanf("%d", &N);
	number = (int*)calloc(N, sizeof(int));

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &number[i]);
	}

	min = number[0];
	max = number[0];

	for (int j = 1; j < N; j++)
	{
		if (min > number[j])
		{
			min = number[j];
		}

		else if (max < number[j])
		{
			max = number[j];
		}
	}
	printf("%d %d", min, max);
	
	free(number);
	return 0;
}