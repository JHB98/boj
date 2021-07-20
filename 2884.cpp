#include <stdio.h>
#pragma warning(disable: 4996)

int main()
{
	int H, M;
	scanf("%d %d", &H, &M);

	M -= 45;
	if (M >= 0)
	{
		printf("%d %d", H, M);
	}
	
	else
	{
		H -= 1;
		if (H < 0)
		{
			H = 23;
		}
		M = 60 + M;
		printf("%d %d", H, M);
	}

	return 0;
}