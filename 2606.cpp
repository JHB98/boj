#include <stdio.h>
#include <stdbool.h>
bool computer[100][100];
bool check[100];
void dfs(int com);
int cnt;
int main()
{
    int n, com1, com2;
    scanf("%d %d", &n, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &com1, &com2);
        computer[com1 - 1][com2 - 1] = true;
        computer[com2 - 1][com1 - 1] = true;
    }
    check[0] = true;
    dfs(0);
    printf("%d\n", cnt);
    return 0;
}
void dfs(int com)
{
    for (int i = 0; i < 100; i++)
    {
        if ((computer[com][i]) && (!check[i]))
        {
            check[i] = true;
            cnt++;
            dfs(i);
        }
    }
}