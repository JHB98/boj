#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
bool map[1000][1000];
bool check[1000];
int n;
void dfs(int v)
{
    check[v] = true;
    cout << v + 1 << " ";
    for (int i = 0; i < n; i++)
    {
        if ((map[v][i]) && (!check[i]))
        {
            dfs(i);
        }
    }
}
void bfs(int v)
{
    int ref;
    queue<int> q;
    check[v] = true;
    q.push(v);
    while (!q.empty())
    {
        ref = q.front();
        cout << ref + 1 << " ";
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if ((map[ref][i]) && (!check[i]))
            {
                check[i] = true;
                q.push(i);
            }
        }
    }
}
int main()
{
    int v, s, e, m;
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;
        map[s - 1][e - 1] = map[e - 1][s - 1] = true;
    }
    dfs(v - 1);
    memset(check, false, sizeof(check));
    cout << "\n";
    bfs(v - 1);
    return 0;
}