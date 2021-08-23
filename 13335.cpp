#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    queue<int> q;
    int n, w, l, ref, cnt = 1, sum = 0;
    vector<pair<int, int>> v;
    cin >> n >> w >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> ref;
        q.push(ref);
    }
    while (1)
    {
        if (q.empty() && v.empty())
        {
            break;
        }
        if (!q.empty() && sum + q.front() <= l)
        {
            v.push_back({q.front(), 0});
            sum += q.front();
            q.pop();
        }
        for (int i = 0; i < v.size(); i++)
        {
            v[i].second++;
        }
        cnt++;
        if (v[0].second == w)
        {
            sum -= v[0].first;
            v.erase(v.begin());
        }
    }
    cout << cnt << "\n";
    return 0;
}