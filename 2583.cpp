#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool map[100][100];
int n, m, ans, d[4] = {-1, 0, 1, 0}, s;
vector<int> v;
void dfs(pair<int, int> point)
{
    int l, r;
    map[point.first][point.second] = true;
    s++;
    for (int i = 0; i < 4; i++)
    {
        l = point.first + d[i];
        r = point.second + d[3 - i];
        if ((l >= 0) && (l < m) && (r >= 0) && (r < n) && (!map[l][r]))
        {
            dfs({l, r});
        }
    }
}
int main()
{
    int k;
    pair<int, int> a, b;
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> a.second >> a.first >> b.second >> b.first;
        for (int j = a.first; j < b.first; j++)
        {
            for (int k = a.second; k < b.second; k++)
            {
                map[j][k] = true;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!map[i][j])
            {
                dfs({i, j});
                ans++;
                v.push_back(s);
                s = 0;
            }
        }
    }
    sort(v.begin(), v.end());
    cout << ans << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    return 0;
}