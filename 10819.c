#include <stdio.h>
#include <stdbool.h>
int a[8], s[8], ans, max, n;
bool check[8];
void back(int e)
{
    int ref;
    if (e == n)
    {
        for (int i = 1; i < n; i++)
        {
            ref = s[i - 1] - s[i];
            if (ref < 0)
            {
                ref *= -1;
            }
            ans += ref;
        }
        if (ans > max)
        {
            max = ans;
        }
        ans = 0;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!check[i])
        {
            s[e] = a[i];
            check[i] = true;
            back(e + 1);
            s[e] = 0;
            check[i] = false;
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    back(0);
    printf("%d\n", max);
    return 0;
}