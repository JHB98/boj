#include <iostream>
#include <vector>
#include <set>
using namespace std;
bool chess[1000][1000];
int n, m;
set<pair<int, int>> s;
void queen(pair<int, int> q, int l, int r)
{
    chess[q.first][q.second] = true;
    if (((q.first + l) >= 0) && ((q.first + l) < n) && ((q.second + r) >= 0) && ((q.second + r) < m) && (s.find({q.first + l, q.second + r}) == s.end()))
    {
        queen({q.first + l, q.second + r}, l, r);
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    vector<pair<int, int>> qv;
    int q, k, p, ref1, ref2, cnt = 0;
    int d1[8] = {-1, -2, -2, -1, 1, 2, 2, 1}, d2[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, d3[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, d4[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    cin >> n >> m;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> ref1 >> ref2;
        ref1--;
        ref2--;
        s.insert({ref1, ref2});
        qv.push_back({ref1, ref2});
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> ref1 >> ref2;
        ref1--;
        ref2--;
        s.insert({ref1, ref2});
        chess[ref1][ref2] = true;
        for (int j = 0; j < 8; j++)
        {
            if (((ref1 + d1[j]) >= 0) && ((ref1 + d1[j]) < n) && ((ref2 + d2[j]) >= 0) && ((ref2 + d2[j]) < m))
            {
                chess[ref1 + d1[j]][ref2 + d2[j]] = true;
            }
        }
    }
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        cin >> ref1 >> ref2;
        ref1--;
        ref2--;
        s.insert({ref1, ref2});
        chess[ref1][ref2] = true;
    }
    for (int i = 0; i < qv.size(); i++)
    {
        for (int j = 0; j < 8; j++)
        {
            queen(qv[i], d3[j], d4[j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!chess[i][j])
            {
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}