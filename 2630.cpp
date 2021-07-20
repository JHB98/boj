#include <stdio.h>
int b_cnt = 0;
int w_cnt = 0;
void count(int (*paper)[128], int s, int e, int n);
int main()
{
    int n, paper[128][128] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &paper[i][j]);
        }
    }
    count(paper, 0, 0, n);
    printf("%d\n%d\n", w_cnt, b_cnt);
    return 0;
}
void count(int (*paper)[128], int s, int e, int n)
{
    int check = 1;
    for (int i = s; i < s + n; i++)
    {
        for (int j = e; j < e + n; j++)
        {
            if (paper[s][e] != paper[i][j])
            {
                check = 0;
                break;
            }
        }
    }
    if (check == 1)
    {
        if (paper[s][e] == 1)
        {
            b_cnt++;
        }
        else
        {
            w_cnt++;
        }
    }
    else
    {
        count(paper, s, e, n / 2);
        count(paper, s, e + n / 2, n / 2);
        count(paper, s + n / 2, e, n / 2);
        count(paper, s + n / 2, e + n / 2, n / 2);
    }
}