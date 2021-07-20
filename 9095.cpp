#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t, n, array[12] = {1, 1, 2};
    scanf("%d", &t);
    for (int i = 3; i < 12; i++)
    {
        array[i] = array[i - 1] + array[i - 2] + array[i - 3];
    }
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        printf("%d\n", array[n]);
    }
    return 0;
}