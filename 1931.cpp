#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, s, e, cnt = 1, check;
    vector<pair<int, int>> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> e;
        v.push_back({e, s});
    }
    sort(v.begin(), v.end());
    check = v[0].first;
    for (int i = 1; i < v.size(); i++)
    {
        if (check <= v[i].second)
        {
            check = v[i].first;
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}