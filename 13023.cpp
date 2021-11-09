#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
vector<vector<int>> v(2000);
bool check[2000], f;
int n, m, d;
void dfs(int num)
{
    check[num] = true;
    d++;
    if (d >= 5)
    {
        f = true;
        return;
    }
    for (int i = 0; i < v[num].size(); i++)
    {
        if (!check[v[num][i]])
        {
            dfs(v[num][i]);
        }
    }
    check[num] = false;
    d--;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int l, r;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        v[l].push_back(r);
        v[r].push_back(l);
    }
    for (int i = 0; i < n; i++)
    {
        dfs(i);
        if (f)
        {
            cout << 1 << "\n";
            return 0;
        }
        memset(check, false, sizeof(check));
    }
    cout << 0 << "\n";
    return 0;
}