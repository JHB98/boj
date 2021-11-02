#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
char grid[100][100];
bool check[100][100];
int n;
void bfs(int i, int j, char c)
{
    queue<pair<int, int>> q;
    int d[4] = {-1, 0, 1, 0}, y, x;
    pair<int, int> ref;
    check[i][j] = true;
    q.push({i, j});
    while (!q.empty())
    {
        ref = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            y = ref.first + d[k];
            x = ref.second + d[3 - k];
            if ((y >= 0) && (y < n) && (x >= 0) && (x < n) && (!check[y][x]) && (grid[y][x] == c))
            {
                check[y][x] = true;
                q.push({y, x});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int ans1 = 0, ans2 = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!check[i][j])
                {
                    bfs(i, j, grid[i][j]);
                    if (!k)
                    {
                        ans1++;
                    }
                    else
                    {
                        ans2++;
                    }
                }
            }
        }
        if (k)
        {
            break;
        }
        memset(check, false, sizeof(check));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 'G')
                {
                    grid[i][j] = 'R';
                }
            }
        }
    }
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}