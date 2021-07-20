#include <iostream>
#include <queue>
using namespace std;
int n, m, cnt;
bool check[1000][1000];
int box[1000][1000];
void search()
{
    queue<pair<int, int>> q;
    int loc[4] = {-1, 1, 0, 0}, cnt1 = 0, cnt2 = 0, num1, num2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((box[i][j] == 1) && (!check[i][j]))
            {
                check[i][j] = true;
                q.push({i, j});
                cnt1++;
            }
        }
    }
    while (1)
    {
        for (int i = 0; i < cnt1; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                num1 = q.front().first + loc[j];
                num2 = q.front().second + loc[3 - j];
                if ((num1 >= 0) && (num1 <= n - 1) && (num2 >= 0) && (num2 <= m - 1))
                {
                    if ((box[num1][num2] == 0) && (!check[num1][num2]))
                    {
                        check[num1][num2] = true;
                        q.push({num1, num2});
                        cnt2++;
                    }
                }
            }
            q.pop();
        }
        if (q.empty())
        {
            break;
        }
        cnt1 = cnt2;
        cnt2 = 0;
        cnt++;
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> box[i][j];
        }
    }
    search();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((box[i][j] == 0) && (!check[i][j]))
            {
                cnt = -1;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
