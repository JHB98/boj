#include <iostream>
#include <queue>
using namespace std;
int n, m;
bool map[100][100];
void bfs()
{
    queue<pair<int, int>> q;
    int size, ans = 1, d[4] = {-1, 0, 1, 0}, s1, s2;
    pair<int, int> ref;
    q.push({0, 0});
    map[0][0] = false;
    while (!q.empty())
    {
        size = q.size();
        for (int i = 0; i < size; i++)
        {
            ref = q.front();
            if ((ref.first == n - 1) && (ref.second == m - 1))
            {
                cout << ans << "\n";
                return;
            }
            q.pop();
            for (int j = 0; j < 4; j++)
            {
                s1 = ref.first + d[j];
                s2 = ref.second + d[3 - j];
                if ((s1 >= 0) && (s1 < n) && (s2 >= 0) && (s2 < m) && (map[s1][s2]))
                {
                    map[s1][s2] = false;
                    q.push({s1, s2});
                }
            }
        }
        ans++;
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    char ref;
    cin >> n >> m;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ref = cin.get();
            if (ref == '1')
            {
                map[i][j] = true;
            }
        }
        cin.get();
    }
    bfs();
    return 0;
}