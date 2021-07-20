#include <stdio.h>
long long num[1000001] = {1, 1, 2};
long long dp(int n)
{
    if (num[n])
    {
        return num[n];
    }
    else
    {
        num[n] = (dp(n - 1) + dp(n - 2) + dp(n - 3)) % 1000000009;
        return num[n];
    }
}
int main()
{
    int t, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        printf("%lld\n", dp(n));
    }
    return 0;
}