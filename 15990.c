#include <stdio.h>
#include <memory.h>
int main()
{
    int t, n;
    long long m[100000][3];
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        memset(m, 0, sizeof(m));
        m[0][0] = m[1][1] = m[2][0] = m[2][1] = m[2][2] = 1;
        for (int j = 3; j < n; j++)
        {
            m[j][0] = (m[j - 1][1] + m[j - 1][2]) % 1000000009;
            m[j][1] = (m[j - 2][0] + m[j - 2][2]) % 1000000009;
            m[j][2] = (m[j - 3][0] + m[j - 3][1]) % 1000000009;
        }
        printf("%lld\n", (m[n - 1][0] + m[n - 1][1] + m[n - 1][2]) % 1000000009);
    }
    return 0;
}