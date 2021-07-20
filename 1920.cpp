#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#pragma warning(disable: 4996)
using namespace std;
int compare(const void* num1, const void* num2);
int main()
{
	int N, M, * num, ref;
	scanf("%d", &N);
	num = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}

	qsort(num, N, sizeof(int), compare);

	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &ref);
		if (binary_search(num, num + N, ref))
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
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