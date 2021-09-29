#include <iostream>
#include <vector>
#define max 100001
using namespace std;
bool check[max];
int ans[max];
vector<vector<int>> v(max);
int dfs(int r)
{
    int sum = 1;
    check[r] = true;
    for (int i = 0; i < v[r].size(); i++)
    {
        if (!check[v[r][i]])
        {
            sum += dfs(v[r][i]);
        }
    }
    ans[r] = sum;
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, r, q, i1, i2, quary;
    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> i1 >> i2;
        v[i1].push_back(i2);
        v[i2].push_back(i1);
    }
    dfs(r);
    for (int i = 0; i < q; i++)
    {
        cin >> quary;
        cout << ans[quary] << "\n";
    }
    return 0;
}