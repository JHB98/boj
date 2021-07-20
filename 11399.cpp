#include <stdio.h>
#include <stdlib.h>
int compare(const void *time1, const void *time2);
int main()
{
    int n, time[1000] = {0}, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &time[i]);
    }
    qsort(time, n, sizeof(int), compare);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            sum += time[j];
        }
    }
    printf("%d\n", sum);
    return 0;
}
int compare(const void *time1, const void *time2)
{
    if (*(int *)time1 < *(int *)time2)
    {
        return -1;
    }
    else if (*(int *)time1 > *(int *)time2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}