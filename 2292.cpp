#include <stdio.h>
int main()
{
    int N, lower = 2, upper = 7, cnt = 2, i = 1;
    scanf("%d", &N);
    while (1)
    {
        if (N == 1)
        {
            printf("1\n");
            break;
        }
        if ((lower <= N) && (N <= upper))
        {
            printf("%d\n", cnt);
            break;
        }
        lower += 6 * i++;
        upper += 6 * i;
        cnt++;
    }
    return 0;
}