#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int M, N, *num;
    scanf("%d %d", &M, &N);
    num = (int *)malloc(sizeof(int) * N);
    for (int i = 1; i <= N; i++)
    {
        num[i - 1] = i;
    }
    for (int i = 2; i <= sqrt(N); i++)
    {
        if (num[i - 1] == 0)
        {
            continue;
        }
        for (int j = i * 2; j <= N; j += i)
        {
            num[j - 1] = 0;
        }
    }
    for (int i = M; i <= N; i++)
    {
        if ((num[i - 1] == 0) || (i == 1))
        {
            continue;
        }
        printf("%d\n", num[i - 1]);
    }
    return 0;
}