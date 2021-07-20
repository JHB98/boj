#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int compare(const void *word1, const void *word2);
int main()
{
	int N;
	scanf("%d", &N);
	char **word;
	word = (char **)malloc(sizeof(char *) * N);

	for (int i = 0; i < N; i++)
	{
		word[i] = (char *)malloc(sizeof(char) * 51);
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%s", word[i]);
	}

	qsort(word, N, sizeof(word[0]), compare);

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (!strcmp(word[i], word[j]))
			{
				strcpy(word[j], "\0");
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (strcmp(word[i], "\0"))
		{
			printf("%s\n", word[i]);
		}
	}

	return 0;
}

int compare(const void *word1, const void *word2)
{
	if (strlen(*(char **)word1) < strlen(*(char **)word2))
	{
		return -1;
	}
	else if (strlen(*(char **)word1) > strlen(*(char **)word2))
	{
		return 1;
	}
	else
	{
		return strcmp(*(char **)word1, *(char **)word2);
	}
}