#include <stdio.h>
int main()
{
    int n, k, dp[10001] = {1}, coin[100];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &coin[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = coin[i]; j <= k; j++)
        {
            dp[j] += dp[j - coin[i]];
        }
    }
    printf("%d\n", dp[k]);
    return 0;
}