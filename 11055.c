#include <stdio.h>
int dp[1000], a[1000];
int main()
{
    int n, max, ans;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        dp[i] = a[i];
    }
    ans = dp[0];
    for (int i = 1; i < n; i++)
    {
        max = 0;
        for (int j = 0; j < i; j++)
        {
            if ((a[i] > a[j]) && (max < dp[j]))
            {
                max = dp[j];
            }
        }
        dp[i] = max + a[i];
        if (ans < dp[i])
        {
            ans = dp[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}