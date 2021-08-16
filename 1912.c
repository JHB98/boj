#include <stdio.h>
int main()
{
    int num[100000], n, max = -__INT_MAX__, save = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
        if (max < num[i])
        {
            max = num[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        save += num[i];
        if (save < 0)
        {
            save = 0;
        }
        if (save && (save > max))
        {
            max = save;
        }
    }
    printf("%d\n", max);
    return 0;
}