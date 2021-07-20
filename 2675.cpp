#include <stdio.h>
#pragma warning(disable: 4996)

int main()
{
	int T, R;
	char S[1000], P[1000] = { 0 };
	int k = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int l = 0;
		scanf("%d", &R);
		scanf("%s", S);
		while (1)
		{
			if (S[l] == '\0')
			{
				P[k++] = '\n';
				break;
			}

			for (int j = 0; j < R; j++)
			{
				P[k] = S[l];
				k++;
			}
			l++;
		}
	}
	printf("%s", P);


	return 0;
}