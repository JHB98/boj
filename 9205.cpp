#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;
vector<pair<int, int>> v;
pair<int, int> ans;
bool check[100];
int n;
bool bfs(pair<int, int> s)
{
    queue<pair<int, int>> q;
    pair<int, int> ref;
    q.push(s);
    while (!q.empty())
    {
        ref = q.front();
        q.pop();
        if (abs(ans.first - ref.first) + abs(ans.second - ref.second) <= 1000)
        {
            return true;
        }
        for (int i = 0; i < v.size(); i++)
        {
            if ((!check[i]) && (abs(v[i].first - ref.first) + abs(v[i].second - ref.second) <= 1000))
            {
                check[i] = true;
                q.push(v[i]);
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    pair<int, int> s;
    int t, x, y;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cin >> s.first >> s.second;
        for (int j = 0; j < n; j++)
        {
            cin >> x >> y;
            v.push_back({x, y});
        }
        cin >> ans.first >> ans.second;
        if (bfs(s))
        {
            cout << "happy\n";
        }
        else
        {
            cout << "sad\n";
        }
        v.clear();
        memset(check, false, sizeof(check));
    }
    return 0;
}