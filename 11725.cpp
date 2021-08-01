#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> v;
int *ans;
bool *check;
void dfs(int j)
{
    check[j] = true;
    for (int i = 0; i < v[j].size(); i++)
    {
        if (!check[v[j][i]])
        {
            ans[v[j][i]] = j + 1;
            dfs(v[j][i]);
        }
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int a, b, n;
    cin >> n;
    check = new bool[n]();
    ans = new int[n]();
    for (int i = 0; i < n; i++)
    {
        v.push_back(vector<int>());
    }
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
    }
    dfs(0);
    for (int i = 1; i < n; i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}