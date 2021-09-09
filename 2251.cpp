#include <iostream>
#include <queue>
using namespace std;
bool check[201][201], ans[201];
queue<pair<pair<int, int>, int>> q;
int a, b, c;
void push(int f, int s, int l)
{
    if (!check[f][s])
    {
        check[f][s] = true;
        q.push({{f, s}, l});
    }
}
void bfs()
{
    check[0][0] = true;
    q.push({{0, 0}, c});
    while (!q.empty())
    {
        int ar = q.front().first.first;
        int br = q.front().first.second;
        int cr = q.front().second;
        q.pop();
        if (!ar)
        {
            ans[cr] = true;
        }
        if (ar + br <= b)
        {
            push(0, ar + br, cr);
        }
        else
        {
            push(ar - (b - br), b, cr);
        }
        if (ar + cr <= c)
        {
            push(0, br, ar + cr);
        }
        else
        {
            push(ar - (c - cr), br, c);
        }
        if (br + ar <= a)
        {
            push(br + ar, 0, cr);
        }
        else
        {
            push(a, br - (a - ar), cr);
        }
        if (br + cr <= c)
        {
            push(ar, 0, br + cr);
        }
        else
        {
            push(ar, br - (c - cr), c);
        }
        if (cr + ar <= a)
        {
            push(cr + ar, br, 0);
        }
        else
        {
            push(a, br, cr - (a - ar));
        }
        if (cr + br <= b)
        {
            push(ar, cr + br, 0);
        }
        else
        {
            push(ar, b, cr - (b - br));
        }
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    bfs();
    for (int i = 0; i <= c; i++)
    {
        if (ans[i])
        {
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}