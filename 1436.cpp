#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)
int main()
{
	int N, cnt = 0, num = 666;
	char str[1000] = { 0 };
	scanf("%d", &N);
	while (cnt != N)
	{
		sprintf(str, "%d", num++);
		if (strstr(str, "666"))
		{
			cnt++;
		}
	}
	printf("%s", str);
	return 0;
}