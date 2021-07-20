#include <iostream>
#include <queue>
using namespace std;
pair<int, int> ans, point;
int n;
void bfs()
{
    queue<pair<int, int>> q;
    bool chess[300][300] = {false};
    int x[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int y[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int cnt = 0, num1 = 1, num2 = 0;
    q.push(point);
    chess[point.first][point.second] = true;
    while (1)
    {
        point = q.front();
        q.pop();
        num1--;
        if (point == ans)
        {
            break;
        }
        for (int i = 0; i < 8; i++)
        {
            if (((point.first + x[i] >= 0) && (point.first + x[i] < n)) && ((point.second + y[i] >= 0) && (point.second + y[i] < n)) && (!chess[point.first + x[i]][point.second + y[i]]))
            {
                q.push({point.first + x[i], point.second + y[i]});
                chess[point.first + x[i]][point.second + y[i]] = true;
                num2++;
            }
        }
        if (!num1)
        {
            num1 = num2;
            num2 = 0;
            cnt++;
        }
    }
    cout << cnt << "\n";
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cin >> point.first >> point.second;
        cin >> ans.first >> ans.second;
        bfs();
    }
    return 0;
}