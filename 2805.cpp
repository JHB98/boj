#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, m, tree[1000000] = {0}, low = 0, high = 0, answer, mid;
    long long sum;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tree[i]);
        if (tree[i] > high)
        {
            high = tree[i];
        }
    }
    while (low <= high)
    {
        sum = 0;
        mid = (low + high) / 2;
        for (int i = 0; i < n; i++)
        {
            if (tree[i] - mid > 0)
            {
                sum += tree[i] - mid;
            }
        }
        if (sum >= m)
        {
            low = mid + 1;
            answer = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    printf("%d\n", answer);
    return 0;
}