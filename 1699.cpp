#include <stdio.h>
#include <math.h>
int num[100001] = {0, 1, 2, 3};
int dp(int n)
{
    int ans, lower = __INT32_MAX__;
    if (num[n])
    {
        return num[n];
    }
    else
    {
        for (int i = (int)sqrt(n); i > 0; i--)
        {
            ans = dp(n - (i * i)) + 1;
            if (lower > ans)
            {
                num[n] = lower = ans;
            }
        }
        return num[n];
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", dp(n));
    return 0;
}