#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int k;
char sign[9], save[11], min[11] = "9999999999", max[11] = "0";
bool check[10];
void back(int n)
{
    if (n == k + 1)
    {
        save[n] = '\n';
        if (strcmp(max, save) < 0)
        {
            strcpy(max, save);
        }
        if (strcmp(save, min) < 0)
        {
            strcpy(min, save);
        }
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        if (!n)
        {
            check[i] = true;
            save[n] = '0' + i;
            back(n + 1);
            check[i] = false;
        }
        else if (!check[i])
        {
            if (sign[n - 1] == '<')
            {
                if (save[n - 1] < '0' + i)
                {
                    check[i] = true;
                    save[n] = '0' + i;
                    back(n + 1);
                    check[i] = false;
                }
            }
            else
            {
                if (save[n - 1] > '0' + i)
                {
                    check[i] = true;
                    save[n] = '0' + i;
                    back(n + 1);
                    check[i] = false;
                }
            }
        }
    }
}
int main()
{
    char ref;
    scanf("%d", &k);
    getchar();
    for (int i = 0; i < k; i++)
    {
        scanf("%c", &sign[i]);
        getchar();
    }
    back(0);
    printf("%s%s", max, min);
    return 0;
}