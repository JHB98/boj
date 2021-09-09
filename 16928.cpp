#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
bool check[100];
unordered_map<int, int> s;
int bfs()
{
    queue<int> q;
    int ans = 0, ref, cnt1 = 1, cnt2 = 0;
    check[0] = true;
    q.push(0);
    while (!q.empty())
    {
        ref = q.front();
        q.pop();
        cnt1--;
        if (ref == 99)
        {
            break;
        }
        for (int i = 1; i <= 6; i++)
        {
            if ((ref + i < 100) && !check[ref + i])
            {
                check[ref + i] = true;
                if (s.count(ref + i))
                {
                    check[s.find(ref + i)->second] = true;
                    q.push(s.find(ref + i)->second);
                }
                else
                {
                    q.push(ref + i);
                }
                cnt2++;
            }
        }
        if (!cnt1)
        {
            cnt1 = cnt2;
            cnt2 = 0;
            ans++;
        }
    }
    return ans;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m, k, v;
    cin >> n >> m;
    for (int i = 0; i < n + m; i++)
    {
        cin >> k >> v;
        s.insert({k - 1, v - 1});
    }
    cout << bfs() << "\n";
    return 0;
}