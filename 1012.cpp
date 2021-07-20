#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool map[50][50];
bool check[50][50];
int cnt, n, m;
void dfs(int x, int y)
{
    check[x][y] = true;
    if ((x - 1 >= 0) && (map[x - 1][y]) && (!check[x - 1][y]))
    {
        dfs(x - 1, y);
    }
    if ((x + 1 < n) && (map[x + 1][y]) && (!check[x + 1][y]))
    {
        dfs(x + 1, y);
    }
    if ((y - 1 >= 0) && (map[x][y - 1]) && (!check[x][y - 1]))
    {
        dfs(x, y - 1);
    }
    if ((y + 1 < m) && (map[x][y + 1]) && (!check[x][y + 1]))
    {
        dfs(x, y + 1);
    }
}
int main()
{
    int t, k, x, y;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d %d", &m, &n, &k);
        for (int i = 0; i < k; i++)
        {
            scanf("%d %d", &y, &x);
            map[x][y] = true;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((!check[i][j]) && (map[i][j]))
                {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        printf("%d\n", cnt);
        cnt = 0;
        memset(map, false, sizeof(map));
        memset(check, false, sizeof(check));
    }
    return 0;
}