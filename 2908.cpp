#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

int main()
{
	char a[4], b[4], temp;
	int num1, num2;
	
	for (int i = 0; i < 3; i++)
	{
		scanf("%c", &a[i]);
	}
	a[3] = '\0';
	getchar();
	for (int j = 0; j < 3; j++)
	{
		scanf("%c", &b[j]);
	}
	b[3] = '\0';

	temp = a[0];
	a[0] = a[2];
	a[2] = temp;

	temp = b[0];
	b[0] = b[2];
	b[2] = temp;

	num1 = atoi(a);
	num2 = atoi(b);


	if (num1 > num2)
	{
		printf("%d", num1);
	}

	else
	{
		printf("%d", num2);
	}
	


	return 0;
}