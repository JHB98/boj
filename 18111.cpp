#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int N, M, B, ground[500][500] = {0}, ground_height = 0, time, result[2], save_B;
    scanf("%d %d %d", &N, &M, &B);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &ground[i][j]);
        }
    }
    save_B = B;
    result[0] = 999999999;
    while (1)
    {
        B = save_B;
        time = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (ground[i][j] > ground_height)
                {
                    B += ground[i][j] - ground_height;
                    time += (ground[i][j] - ground_height) * 2;
                }
                else if (ground[i][j] < ground_height)
                {
                    B -= ground_height - ground[i][j];
                    time += ground_height - ground[i][j];
                }
            }
        }
        if (B >= 0)
        {
            if (result[0] > time)
            {
                result[0] = time;
                result[1] = ground_height;
            }
            else if (result[0] == time)
            {
                result[1] = ground_height;
            }
        }
        if ((++ground_height) > 256)
        {
            break;
        }
    }
    printf("%d %d\n", result[0], result[1]);

    return 0;
}