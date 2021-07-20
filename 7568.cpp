#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)
typedef struct
{
	int weight;
	int height;
}Person;
int main()
{
	int N, rankN = 1;
	scanf("%d", &N);
	Person* person;
	person = (Person*)malloc(sizeof(Person) * N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &person[i].weight, &person[i].height);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (((person[i].weight) < (person[j].weight)) && ((person[i].height) < (person[j].height)))
			{
				rankN++;
			}
		}
		printf("%d ", rankN);
		rankN = 1;
	}

	return 0;
}