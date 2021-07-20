#include <stdio.h>
#include <stdlib.h>
#include <cmath>
int compare(const void *num1, const void *num2);
int main()
{
    bool check;
    int N, num[500000] = {0}, mode[8001] = {0}, modeCnt = 0, modeNum;
    double sum = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
        sum += num[i];
        mode[num[i] + 4000]++;
    }
    qsort(num, N, sizeof(int), compare);
    printf("%.0lf\n", round(sum / N));
    printf("%d\n", num[N / 2]);
    for (int i = (num[0] + 4000); i <= (num[N - 1] + 4000); i++)
    {
        if (mode[i] > modeCnt)
        {
            modeCnt = mode[i];
            modeNum = i - 4000;
            check = false;
        }
        else if ((mode[i] == modeCnt) && (check == false))
        {
            modeNum = i - 4000;
            check = true;
        }
    }
    printf("%d\n", modeNum);
    printf("%d\n", num[N - 1] - num[0]);
    return 0;
}
int compare(const void *num1, const void *num2)
{
    if (*(int *)num1 < *(int *)num2)
    {
        return -1;
    }
    else if (*(int *)num1 > *(int *)num2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/*void mode(int *num, int N)
{
    int check, cnt, mode = -1, index, modeNum, modeCnt;
    for (int i = 0; i < N; i++)
    {
        check = num[i];
        cnt = 0;
        index = i + 1;
        while (check == num[index++])
        {
            cnt++;
        }
        if (mode < cnt)
        {
            mode = cnt;
            modeNum = num[i];
            modeCnt = 0;
        }
        else if ((mode == cnt) && (modeCnt == 0))
        {
            modeNum = num[i];
            modeCnt = 1;
        }
        i += cnt;
    }
    printf("%d\n", modeNum);
}*/