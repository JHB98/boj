#include <stdio.h>
#pragma warning(disable: 4996)

int main()
{
	int num, max = 0;
	double score[1000] = { 0 }, sum = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%lf", &score[i]);
		if (max < score[i])
		{
			max = score[i];
		}
	}
	for (int j = 0; j < num; j++)
	{
		score[j] = score[j] / max * 100;
		sum += score[j];
	}
	printf("%.2lf", sum / num);


	return 0;
}