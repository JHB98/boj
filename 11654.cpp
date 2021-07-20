#include <stdio.h>
#pragma warning(disable: 4996)

int main()
{
	char input;
	scanf("%c", &input);
	if ( (('a' <= input) && (input <= 'z')) || (('A' <= input) && (input <= 'Z')) || (('0' <= input) && (input <= '9')))
	{
		printf("%d",input);
	}

	return 0;
}