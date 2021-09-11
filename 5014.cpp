#include <iostream>
#include <queue>
using namespace std;
int f, s, g, d[2];
bool check[1000001];
void bfs()
{
    int ans = -1, ref, ref2, cnt1 = 1, cnt2 = 0, save = 0;
    queue<int> q;
    check[s] = true;
    q.push(s);
    while (!q.empty())
    {
        ref = q.front();
        q.pop();
        cnt1--;
        if (ref == g)
        {
            ans = save;
            break;
        }
        for (int i = 0; i < 2; i++)
        {
            ref2 = ref + d[i];
            if ((ref2 >= 1) && (ref2 <= f) && (!check[ref2]))
            {
                check[ref2] = true;
                q.push(ref2);
                cnt2++;
            }
        }
        if (!cnt1)
        {
            cnt1 = cnt2;
            cnt2 = 0;
            save++;
        }
    }
    if (ans != -1)
    {
        cout << ans << "\n";
    }
    else
    {
        cout << "use the stairs\n";
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> f >> s >> g >> d[0] >> d[1];
    d[1] *= -1;
    bfs();
    return 0;
}