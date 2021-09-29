#include <stdio.h>
int dp[100][10];
int main()
{
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i < 10; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (!j)
            {
                dp[i][j] = dp[i - 1][j + 1] % 1000000000;
            }
            else if (j < 9)
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] % 1000000000;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        ans += dp[n - 1][i];
        ans %= 1000000000;
    }
    printf("%d\n", ans);
    return 0;
}