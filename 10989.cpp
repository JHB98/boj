#include <stdio.h>
int main()
{
    int n, num[10001] = {0}, index;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &index);
        num[index]++;
    }
    for (int i = 0; i < 10001; i++)
    {
        if (num[i] != 0)
        {
            for (int j = 0; j < num[i]; j++)
            {
                printf("%d\n", i);
            }
        }
    }
    return 0;
}