#include <stdio.h>
char map[50][50], ref;
int sum, ans, n, d[4] = {0, 1, 0, -1};
void check(int x, int y, int k)
{
    if ((0 <= y + d[3 - k]) && (0 <= x + d[k]) && (n > y + d[3 - k]) && (n > x + d[k]))
    {
        if (map[y][x] == map[y + d[3 - k]][x + d[k]])
        {
            sum++;
            check(x + d[k], y + d[3 - k], k);
        }
    }
}
void change(int i, int j, int k)
{
    ref = map[i + d[3 - k]][j + d[k]];
    map[i + d[3 - k]][j + d[k]] = map[i][j];
    map[i][j] = ref;
}
void solve(int i, int j, int l)
{
    sum = 1;
    check(j, i, l);
    check(j, i, l + 2);
    if (sum > ans)
    {
        ans = sum;
    }
}
int main()
{
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%c", &map[i][j]);
        }
        getchar();
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int l = 0; l < 2; l++)
            {
                solve(i, j, l);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if ((0 <= i + d[3 - k]) && (0 <= j + d[k]) && (n > i + d[3 - k]) && (n > j + d[k]))
                {
                    if (map[i][j] != map[i + d[3 - k]][j + d[k]])
                    {
                        change(i, j, k);
                        for (int l = 0; l < 2; l++)
                        {
                            solve(i, j, l);
                        }
                        change(i, j, k);
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}