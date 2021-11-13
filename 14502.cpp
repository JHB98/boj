#include <iostream>
#include <string.h>
using namespace std;
bool check[64], mapCheck[8][8];
int n, m, map[8][8], saveMap[8][8], cnt, ans, saveCnt;
pair<int, int> p[64], save[3];
void dfs(pair<int, int> ref)
{
    int d[4] = {-1, 0, 1, 0}, ref1, ref2;
    mapCheck[ref.first][ref.second] = true;
    for (int i = 0; i < 4; i++)
    {
        ref1 = ref.first + d[i];
        ref2 = ref.second + d[3 - i];
        if ((ref1 >= 0) && (ref1 < n) && (ref2 >= 0) && (ref2 < m) && (!mapCheck[ref1][ref2]) && (!saveMap[ref1][ref2]))
        {
            saveMap[ref1][ref2] = 2;
            saveCnt--;
            dfs({ref1, ref2});
        }
    }
}
void find(int num)
{
    if (num == 3)
    {
        memset(mapCheck, false, sizeof(mapCheck));
        saveCnt = cnt - 3;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                saveMap[i][j] = map[i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            saveMap[save[i].first][save[i].second] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((saveMap[i][j] == 2) && (!mapCheck[i][j]))
                {
                    dfs({i, j});
                }
            }
        }
        ans = max(saveCnt, ans);
    }
    else
    {
        for (int i = 0; i < cnt; i++)
        {
            if (!check[i])
            {
                check[i] = true;
                save[num] = p[i];
                find(num + 1);
                check[i] = false;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (!map[i][j])
            {
                p[cnt++] = {i, j};
            }
        }
    }
    find(0);
    cout << ans << "\n";
    return 0;
}