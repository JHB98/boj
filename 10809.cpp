#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)

int main()
{
	char alp;
	int num = 0, alphabet[26];
	memset(alphabet, -1, sizeof(alphabet));
	while (1)
	{
		scanf("%c", &alp);
		if (alp == '\n')
		{
			break;
		}
		if (alphabet[alp - 'a'] == -1)
		{
			alphabet[alp - 'a'] = num;
		}
		num++;

	}

	for (int i = 0; i < 26; i++)
	{
		printf("%d ", alphabet[i]);
	}

	return 0;
}
