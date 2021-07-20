#include <stdio.h>
#include <stdbool.h>
#pragma warning(disable: 4996)

int main()
{
	int alphabet[26] = { 0 }, max = 0, maxnumber = 0;
	char alp;
	bool check = false;
	while (1)
	{
		alp = getchar();
		if (alp == '\n')
		{
			break;
		}
		
		if ((alp >= 'a') && (alp <= 'z'))
		{
			alphabet[alp - 'a']++;
		}
		else
		{
			alphabet[alp - 'A']++;
		}

	}
	for (int i = 0; i < 26; i++)
	{
		if (max < alphabet[i])
		{
			max = alphabet[i];
			maxnumber = i;
			check = false;
		}
		else if (max == alphabet[i])
		{
			check = true;
		}
	}
	if (check)
	{
		printf("?");
	}
	else
	{
		printf("%c", 'A' + maxnumber);
	}



	return 0;
}