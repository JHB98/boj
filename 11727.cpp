#include <stdio.h>
int num[1001] = {0, 1, 3};
int fibo(int n)
{
    if (num[n])
    {
        return num[n];
    }
    else
    {
        num[n] = (fibo(n - 1) + fibo(n - 2) * 2) % 10007;
        return num[n];
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    fibo(n);
    printf("%d\n", num[n]);
    return 0;
}