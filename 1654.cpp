#include <stdio.h>
int main()
{
    long long k, n, lan[10001] = {0}, low = 1, high = 0, sum, mid, ans;
    scanf("%lld %lld", &k, &n);
    for (int i = 0; i < k; i++)
    {
        scanf("%lld", &lan[i]);
        if (high < lan[i])
        {
            high = lan[i];
        }
    }
    while (low <= high)
    {
        mid = (low + high) / 2;
        sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += (lan[i] / mid);
        }
        if (sum >= n)
        {
            low = mid + 1;
            ans = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}