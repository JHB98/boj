#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int num;
int R, C;
void search(int r, int c, int size);
int main()
{
    int n;
    scanf("%d %d %d", &n, &R, &C);
    search(0, 0, pow(2, n));
    return 0;
}
void search(int r, int c, int size)
{
    if (size == 2)
    {
        if (R - r == 1)
        {
            if (C - c == 1)
            {
                printf("%d\n", num + 3);
            }
            else
            {
                printf("%d\n", num + 2);
            }
        }
        else
        {
            if (C - c == 1)
            {
                printf("%d\n", num + 1);
            }
            else
            {
                printf("%d\n", num);
            }
        }
    }
    else
    {
        if ((r + size / 2 > R) && (c + size / 2 > C))
        {
            search(r, c, size / 2);
        }
        else if ((r + size / 2 > R) && (c + (size / 2) * 2 > C))
        {
            num += pow(size / 2, 2);
            search(r, c + size / 2, size / 2);
        }
        else if ((r + (size / 2) * 2 > R) && (c + size / 2 > C))
        {
            num += pow(size / 2, 2) * 2;
            search(r + size / 2, c, size / 2);
        }
        else
        {
            num += pow(size / 2, 2) * 3;
            search(r + size / 2, c + size / 2, size / 2);
        }
    }
}