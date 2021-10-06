#include <iostream>
#include <queue>
using namespace std;
int n, m, h, t[100][100][100];
int bfs()
{
    queue<pair<int, pair<int, int>>> q;
    pair<int, pair<int, int>> ref;
    int qsize, ans = -1, d[4] = {-1, 0, 1, 0}, sh, sl, sr;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (t[i][j][k] == 1)
                {
                    q.push({i, {j, k}});
                }
            }
        }
    }
    while (!q.empty())
    {
        qsize = q.size();
        for (int i = 0; i < qsize; i++)
        {
            ref = q.front();
            q.pop();
            for (int i = 0; i < 4; i += 2)
            {
                sh = ref.first + d[i];
                if ((sh >= 0) && (sh < h) && !t[sh][ref.second.first][ref.second.second])
                {
                    t[sh][ref.second.first][ref.second.second] = 1;
                    q.push({sh, {ref.second.first, ref.second.second}});
                }
            }
            for (int j = 0; j < 4; j++)
            {
                sl = ref.second.first + d[j];
                sr = ref.second.second + d[3 - j];
                if ((sl >= 0) && (sl < n) && (sr >= 0) && (sr < m) && (!t[ref.first][sl][sr]))
                {
                    t[ref.first][sl][sr] = 1;
                    q.push({ref.first, {sl, sr}});
                }
            }
        }
        ans++;
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (!t[i][j][k])
                {
                    return -1;
                }
            }
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n >> h;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> t[i][j][k];
            }
        }
    }
    cout << bfs() << "\n";
    return 0;
}