#include <iostream>
#include <cstring>
using namespace std;
int map[100][100], n, d[4] = {-1, 0, 1, 0};
bool check[100][100];
void dfs(pair<int, int> p, int h)
{
    int l, r;
    check[p.first][p.second] = true;
    for (int i = 0; i < 4; i++)
    {
        l = p.first + d[i];
        r = p.second + d[3 - i];
        if ((l >= 0) && (l < n) && (r >= 0) && (r < n) && (map[l][r] > h) && (!check[l][r]))
        {
            dfs({l, r}, h);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int min = 101, max = 0, ans = 1, cnt;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] > max)
            {
                max = map[i][j];
            }
            if (map[i][j] < min)
            {
                min = map[i][j];
            }
        }
    }
    for (int i = min; i < max; i++)
    {
        cnt = 0;
        memset(check, false, sizeof(check));
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if ((map[j][k] > i) && (!check[j][k]))
                {
                    dfs({j, k}, i);
                    cnt++;
                }
            }
        }
        if (cnt > ans)
        {
            ans = cnt;
        }
    }
    cout << ans << "\n";
    return 0;
}