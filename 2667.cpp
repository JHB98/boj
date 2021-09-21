#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, ans, cnt;
vector<int> v;
bool map[25][25], check[25][25];
void dfs(int i, int j)
{
    int d[4] = {-1, 0, 1, 0}, ref1, ref2;
    check[i][j] = true;
    cnt++;
    for (int k = 0; k < 4; k++)
    {
        ref1 = i + d[k];
        ref2 = j + d[3 - k];
        if ((ref1 >= 0) && (ref1 < n) && (ref2 >= 0) && (ref2 < n) && (map[ref1][ref2]) && (!check[ref1][ref2]))
        {
            dfs(ref1, ref2);
        }
    }
}
int main()
{
    cin.tie(NULL);
    int ref;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%1d", &ref);
            if (ref)
            {
                map[i][j] = true;
                continue;
            }
            map[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] && !check[i][j])
            {
                dfs(i, j);
                v.push_back(cnt);
                ans++;
                cnt = 0;
            }
        }
    }
    sort(v.begin(), v.end());
    cout << ans << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }
    return 0;
}