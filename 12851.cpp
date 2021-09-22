#include <iostream>
#include <queue>
using namespace std;
int n, k, ans, cnt;
bool check[100001];
void bfs(int num)
{
    queue<int> q;
    int ref;
    bool find = false;
    check[num] = true;
    q.push(num);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            ref = q.front();
            if (ref == k)
            {
                cnt++;
                find = true;
            }
            q.pop();
            check[ref] = true;
            if ((ref + 1 < 100001) && !check[ref + 1])
            {
                q.push(ref + 1);
            }
            if ((ref - 1 >= 0) && !check[ref - 1])
            {
                q.push(ref - 1);
            }
            if ((ref * 2 < 100001) && !check[ref * 2])
            {
                q.push(ref * 2);
            }
        }
        if (find)
        {
            break;
        }
        ans++;
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    bfs(n);
    cout << ans << "\n"
         << cnt << "\n";
    return 0;
}