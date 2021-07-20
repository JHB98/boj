#include <stdio.h>
int main()
{
    int N, cnt = 0, ref = 1, cnt5 = 0, Sn, Scnt;
    scanf("%d", &N);
    while (N > 0)
    {
        N -= 5;
        cnt++;
        cnt5++;
    }
    if (N < 0)
    {
        Sn = N;
        Scnt = cnt;
        while (1)
        {
            N = Sn;
            cnt = Scnt;
            N += (5 * ref);
            cnt -= ref;
            while (N > 0)
            {
                N -= 3;
                cnt++;
            }
            if ((N == 0) || (ref == cnt5))
            {
                break;
            }
            else
            {
                ref++;
            }
        }
    }
    if (N < 0)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", cnt);
    }
    return 0;
}