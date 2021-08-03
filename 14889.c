#include <stdio.h>
#include <stdbool.h>
int s[20][20], n, sum, ans = __INT_MAX__, cnt;
bool p[20];
void back(int i)
{
    p[i] = true;
    cnt++;
    if (cnt < n / 2)
    {
        for (int j = i + 1; j < n; j++)
        {
            back(j);
        }
    }
    else
    {
        for (int j = 0; j < n; j++)
        {
            if (p[j])
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (p[k])
                    {
                        sum += s[j][k] + s[k][j];
                    }
                }
            }
            else
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (!p[k])
                    {
                        sum -= s[j][k] + s[k][j];
                    }
                }
            }
        }
        if (sum < 0)
        {
            sum *= -1;
        }
        if (sum < ans)
        {
            ans = sum;
        }
        sum = 0;
    }
    p[i] = false;
    cnt--;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &s[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        back(i);
    }
    printf("%d\n", ans);
    return 0;
}