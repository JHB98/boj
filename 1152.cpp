#include <stdio.h>
#include <stdbool.h>
#pragma warning(disable: 4996)

int main()
{
	char word, preword = ' ';
	int num = 0;
	bool check = false;
	while (1)
	{
		word = getchar();
		if (word == '\n')
		{
			if (preword == ' ')
			{
				break;
			}
			num++;
			break;
		}
		else if (word == ' ')
		{
			if (check == true)
			{
				num++;
				preword = word;
			}
		}
		else
		{
			preword = word;
			check = true;
		}
	}
	printf("%d", num);

	return 0;
}
