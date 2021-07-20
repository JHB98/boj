#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#pragma warning(disable: 4996)
using namespace std;
int compare(const void* num1, const void* num2);
int main()
{
	int N, M, index;
	int* num1, * num2, * num3;
	scanf("%d", &N);
	num1 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num1[i]);
	}

	scanf("%d", &M);
	num2 = (int*)malloc(sizeof(int) * M);
	num3 = (int*)malloc(sizeof(int) * M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &num2[i]);
	}
	
	qsort(num1, N, sizeof(int), compare);

	for (int i = 0; i < M; i++)
	{
		index = lower_bound(num1, num1 + N, num2[i]) - num1;
		if (num2[i] == num1[index])
		{
			num3[i] = (upper_bound(num1, num1 + N, num2[i]) - num1) - (lower_bound(num1, num1 + N, num2[i]) - num1);
		}
		else
		{
			num3[i] = 0;
		}
	}

	for (int i = 0; i < M; i++)
	{
		printf("%d ", num3[i]);
	}

	return 0;
}
int compare(const void* num1, const void* num2)
{
	int* num3, * num4;
	num3 = (int*)num1;
	num4 = (int*)num2;

	if (*num3 < *num4)
	{
		return -1;
	}
	else if (*num3 > *num4)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}