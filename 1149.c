#include <stdio.h>
int price[1000][3], dp[1000][3];
int min(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    return a;
}
int main()
{
    int n, ans;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &price[i][j]);
            dp[i][j] = price[i][j];
        }
    }
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = min(dp[i - 1][1] + price[i][0], dp[i - 1][2] + price[i][0]);
        dp[i][1] = min(dp[i - 1][0] + price[i][1], dp[i - 1][2] + price[i][1]);
        dp[i][2] = min(dp[i - 1][0] + price[i][2], dp[i - 1][1] + price[i][2]);
    }
    ans = min(dp[n - 1][0], dp[n - 1][1]);
    ans = min(ans, dp[n - 1][2]);
    printf("%d\n", ans);
    return 0;
}