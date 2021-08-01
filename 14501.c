#include <stdio.h>
int cal[15][2], sum, ans, n;
void back(int k)
{
    int check = 0;
    for (int i = k + 1; i < n; i++)
    {
        if (i + cal[i][0] <= n)
        {
            if (k == -1)
            {
                sum += cal[i][1];
                back(i);
            }
            else if (k + cal[k][0] <= i)
            {
                sum += cal[i][1];
                if (!check)
                {
                    check = 1;
                }
                back(i);
            }
        }
    }
    if (!check)
    {
        if (sum > ans)
        {
            ans = sum;
        }
    }
    sum -= cal[k][1];
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &cal[i][0], &cal[i][1]);
    }
    back(-1);
    printf("%d\n", ans);
    return 0;
}