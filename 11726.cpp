#include <stdio.h>
int num[1001];
int fibo(int n)
{
    if (!num[n])
    {
        num[n] = (fibo(n - 1) + fibo(n - 2)) % 10007;
    }
    return num[n];
}
int main()
{
    int n;
    scanf("%d", &n);
    num[0] = num[1] = 1;
    fibo(n);
    printf("%d\n", num[n]);
    return 0;
}