#include <iostream>
#include <queue>
using namespace std;
bool map[101][101];
bool check[101];
int num2, ans = -1, n;
void bfs(int num1)
{
    int ref, cnt1 = 1, cnt2 = 0, cnt3 = 0;
    queue<int> q;
    check[num1] = true;
    q.push(num1);
    while (!q.empty())
    {
        ref = q.front();
        if (ref == num2)
        {
            ans = cnt3;
            break;
        }
        q.pop();
        cnt1--;
        for (int i = 1; i <= n; i++)
        {
            if (map[ref][i] && !check[i])
            {
                check[i] = true;
                q.push(i);
                cnt2++;
            }
        }
        if (!cnt1)
        {
            cnt1 = cnt2;
            cnt2 = 0;
            cnt3++;
        }
    }
}
int main()
{
    int num1, m, x, y;
    cin >> n >> num1 >> num2 >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        map[x][y] = map[y][x] = true;
    }
    bfs(num1);
    cout << ans << "\n";
    return 0;
}