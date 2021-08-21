#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
int main()
{
    int n, ans = 0;
    bool num[1000001];
    memset(num, true, sizeof(num));
    for (int i = 2; i <= 1000; i++)
    {
        if (num[i])
        {
            for (int j = i * 2; j <= 1000000; j += i)
            {
                num[j] = false;
            }
        }
    }
    while (1)
    {
        scanf("%d", &n);
        if (!n)
        {
            break;
        }
        for (int i = 3; i < 1000000; i += 2)
        {
            if (num[i])
            {
                if (num[n - i])
                {
                    ans = n - i;
                    break;
                }
            }
        }
        if (!ans)
        {
            printf("Goldbach's conjecture is wrong.\n");
        }
        else
        {
            printf("%d = %d + %d\n", n, n - ans, ans);
        }
    }
    return 0;
}