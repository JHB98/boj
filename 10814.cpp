#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)
typedef struct
{
	int order;
	int age;
	char name[101];
}Person;

int compare(const void* person1, const void* person2);

int main()
{
	int N;
	Person* person;
	scanf("%d", &N);
	person = (Person*)malloc(sizeof(Person) * N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %s", &person[i].age, person[i].name);
		person[i].order = i + 1;
	}

	qsort(person, N, sizeof(Person), compare);

	for (int i = 0; i < N; i++)
	{
		printf("%d %s\n", person[i].age, person[i].name);
	}

	return 0;
}
int compare(const void* person1, const void* person2)
{
	Person* person3 = (Person*)person1;
	Person* person4 = (Person*)person2;

	if (person3->age < person4->age)
	{
		return -1;
	}

	else if (person3->age > person4->age)
	{
		return 1;
	}

	else
	{
		if (person3->order < person4->order)
		{
			return -1;
		}

		else
		{
			return 1;
		}
	}
}