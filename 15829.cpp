#include <stdio.h>
int main()
{
    int L, r = 31, M = 1234567891;
    long long sum = 0, pow_r = 1;
    char ch[100] = {0};
    scanf("%d\n", &L);
    for (int i = 0; i < L; i++)
    {
        scanf("%c", &ch[i]);
    }
    for (int i = 0; i < L; i++)
    {
        sum = (sum + (ch[i] - 'a' + 1) * pow_r) % M;
        pow_r = (pow_r * r) % M;
    }
    printf("%llu\n", sum);
    return 0;
}