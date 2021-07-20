#include <stdio.h>
int num[1000001];
int dp(int n)
{
    int ref;
    if (num[n] == 0)
    {
        num[n] = dp(n - 1) + 1;
        if (n % 3 == 0)
        {
            ref = dp(n / 3) + 1;
            if (num[n] > ref)
            {
                num[n] = ref;
            }
        }
        if (n % 2 == 0)
        {
            ref = dp(n / 2) + 1;
            if (num[n] > ref)
            {
                num[n] = ref;
            }
        }
    }
    return num[n];
}
int main()
{
    int n, ans;
    scanf("%d", &n);
    if (n == 1)
    {
        printf("0\n");
        return 0;
    }
    num[2] = num[3] = 1;
    printf("%d\n", dp(n));
    return 0;
}