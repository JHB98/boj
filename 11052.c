#include <stdio.h>
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int n, p[1001] = {0}, ans[1001] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        ans[i] = p[i];
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            ans[i] = max(ans[i], ans[i - j] + p[j]);
        }
    }
    printf("%d\n", ans[n]);
    return 0;
}