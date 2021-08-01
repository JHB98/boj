#include <stdio.h>
#include <stdbool.h>
int n, m, cnt, num[8];
bool check[9];
void back(int k)
{
    check[k] = true;
    num[cnt++] = k;
    for (int i = 1; i <= n; i++)
    {
        if ((!check[i]) && (cnt < m))
        {
            back(i);
        }
    }
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            printf("%d ", num[i]);
        }
        printf("\n");
    }
    check[k] = false;
    num[--cnt] = 0;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        back(i);
    }
    return 0;
}