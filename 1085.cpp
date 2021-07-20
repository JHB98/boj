#include <stdio.h>
#pragma warning(disable: 4996)
int min(int num1, int num2);
int main()
{
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	printf("%d", min(min(x, y), min(w - x, h - y)));
	return 0;
}
int min(int num1, int num2)
{
	if (num1 < num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}