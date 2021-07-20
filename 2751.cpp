#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)
int compare(const void* num1, const void* num2);
int main()
{
	int N, * num;
	scanf("%d", &N);
	num = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}
	qsort(num, N, sizeof(int), compare);

	for (int i = 0; i < N; i++)
	{
		printf("%d\n", num[i]);
	}
	return 0;
}
int compare(const void* num1, const void* num2)
{
	if (*(int*)num1 < *(int*)num2)
	{
		return -1;
	}

	else if (*(int*)num1 > *(int*)num2)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}