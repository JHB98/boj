#include <iostream>
#include <queue>
using namespace std;
typedef struct
{
    int l;
    int r;
    int like;
    int space;
} seat;
struct compare
{
    bool operator()(seat a, seat b)
    {
        if (a.like != b.like)
        {
            return a.like < b.like;
        }
        else
        {
            if (a.space != b.space)
            {
                return a.space < b.space;
            }
            else
            {
                if (a.l != b.l)
                {
                    return a.l > b.l;
                }
                else
                {
                    return a.r > b.r;
                }
            }
        }
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int student[401][4] = {0}, n, index, cls[21][21] = {0}, d[4] = {-1, 0, 1, 0}, sum = 0, save;
    priority_queue<seat, vector<seat>, compare> pq;
    queue<int> q;
    cin >> n;
    for (int i = 0; i < n * n; i++)
    {
        cin >> index;
        q.push(index);
        for (int j = 0; j < 4; j++)
        {
            cin >> student[index][j];
        }
    }
    while (!q.empty())
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                seat dat = {i, j, 0, 0};
                if (!cls[i][j])
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int rl = i + d[k];
                        int rr = j + d[3 - k];
                        if ((rl >= 1) && (rl <= n) && (rr >= 1) && (rr <= n))
                        {
                            if (!cls[rl][rr])
                            {
                                dat.space++;
                            }
                            else
                            {
                                for (int l = 0; l < 4; l++)
                                {
                                    if (cls[rl][rr] == student[q.front()][l])
                                    {
                                        dat.like++;
                                    }
                                }
                            }
                        }
                    }
                    pq.push(dat);
                }
            }
        }
        cls[pq.top().l][pq.top().r] = q.front();
        q.pop();
        while (!pq.empty())
        {
            pq.pop();
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            save = 0;
            for (int k = 0; k < 4; k++)
            {
                int rl = i + d[k];
                int rr = j + d[3 - k];
                if ((rl >= 1) && (rl <= n) && (rr >= 1) && (rr <= n))
                {
                    for (int l = 0; l < 4; l++)
                    {
                        if (cls[rl][rr] == student[cls[i][j]][l])
                        {
                            save++;
                        }
                    }
                }
            }
            switch (save)
            {
            case 1:
                sum += 1;
                break;
            case 2:
                sum += 10;
                break;
            case 3:
                sum += 100;
                break;
            case 4:
                sum += 1000;
                break;
            }
        }
    }
    cout << sum << "\n";
    return 0;
}