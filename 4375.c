#include <stdio.h>
int main()
{
    int n, ans;
    while (scanf("%d", &n) != EOF)
    {
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = ans * 10 + 1;
            ans %= n;
            if (ans == 0)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}