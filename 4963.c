#include <stdio.h>
#include <memory.h>
#include <stdbool.h>
bool map[50][50];
bool check[50][50];
int cnt, w, h;
void dfs(int i, int j)
{
    int l[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int c[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    for (int k = 0; k < 8; k++)
    {
        if (((i + l[k] >= 0) && (i + l[k] < h)) && ((j + c[k] >= 0) && (j + c[k] < w)))
        {
            if (map[i + l[k]][j + c[k]] && !check[i + l[k]][j + c[k]])
            {
                check[i + l[k]][j + c[k]] = true;
                dfs(i + l[k], j + c[k]);
            }
        }
    }
}
int main()
{
    int ref;
    while (1)
    {
        scanf("%d %d", &w, &h);
        if ((!w) && (!h))
        {
            break;
        }
        cnt = 0;
        memset(map, false, sizeof(map));
        memset(check, false, sizeof(check));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                scanf("%d", &ref);
                if (ref)
                {
                    map[i][j] = true;
                }
            }
        }
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (map[i][j] && !check[i][j])
                {
                    check[i][j] = true;
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}