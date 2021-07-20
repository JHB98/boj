#include <stdio.h>
#include <stdbool.h>
bool graph[1000][1000];
bool check[1000];
void dfs(int com);
int n;
int main()
{
    int m, com1, com2, cnt = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &com1, &com2);
        graph[com1 - 1][com2 - 1] = true;
        graph[com2 - 1][com1 - 1] = true;
    }

    for (int j = 0; j < n; j++)
    {
        if (!check[j])
        {
            dfs(j);
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
void dfs(int com)
{
    for (int i = 0; i < n; i++)
    {
        if ((graph[com][i]) && (!check[i]))
        {
            check[i] = true;
            dfs(i);
        }
    }
}