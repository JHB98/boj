#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)

int main()
{
	char num[6], reversenum[6], ref;
	int answer[10000] = { 0 }, cnt = 0;
	while (1)
	{
		scanf("%s", num);
		if (!strcmp(num, "0"))
		{
			break;
		}
		strcpy(reversenum, num);
		for (int i = 0; i < (strlen(num) / 2); i++)
		{
			ref = reversenum[i];
			reversenum[i] = reversenum[strlen(num) - i - 1];
			reversenum[strlen(num) - i - 1] = ref;
		}
		if (!strcmp(num, reversenum))
		{
			answer[cnt++] = 1;
		}
		else
		{
			answer[cnt++] = -1;
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		if (answer[i] == 1)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}

	}


	return 0;
}