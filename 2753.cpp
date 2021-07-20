#include <stdio.h>
#pragma warning(disable: 4996)

int main()
{
	int year;
	scanf("%d", &year);
	if(!(year%4))
	{ 
		if ((year % 100) || (!(year % 400)))
		{
			printf("1");

		}
		else
		{
			printf("0");
		}
	
	}
	else
	{
		printf("0");
	}

	return 0;
}